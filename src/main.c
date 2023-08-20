/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>

#include <zephyr/drivers/rtc.h>
#include <time.h>
#include <zephyr/sys/timeutil.h>


#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/bluetooth/services/hrs.h>

#include <zephyr/kernel.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_event.h>

LOG_MODULE_REGISTER(rtc_dev);
static const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));


static K_SEM_DEFINE(wifi_connected, 0, 1);
static K_SEM_DEFINE(ipv4_address_obtained, 0, 1);

static struct net_mgmt_event_callback wifi_cb;
static struct net_mgmt_event_callback ipv4_cb;

static void handle_wifi_connect_result(struct net_mgmt_event_callback *cb)
{
    const struct wifi_status *status = (const struct wifi_status *)cb->info;

    if (status->status)
    {
        printk("Connection request failed (%d)\n", status->status);
    }
    else
    {
        printk("Connected\n");
        k_sem_give(&wifi_connected);
    }
}

static void handle_wifi_disconnect_result(struct net_mgmt_event_callback *cb)
{
    const struct wifi_status *status = (const struct wifi_status *)cb->info;

    if (status->status)
    {
        printk("Disconnection request (%d)\n", status->status);
    }
    else
    {
        printk("Disconnected\n");
        k_sem_take(&wifi_connected, K_NO_WAIT);
    }
}

static void handle_ipv4_result(struct net_if *iface)
{
    int i = 0;

    for (i = 0; i < NET_IF_MAX_IPV4_ADDR; i++) {

        char buf[NET_IPV4_ADDR_LEN];

        if (iface->config.ip.ipv4->unicast[i].addr_type != NET_ADDR_DHCP) {
            continue;
        }

        printk("IPv4 address: %s\n",
                net_addr_ntop(AF_INET,
                                &iface->config.ip.ipv4->unicast[i].address.in_addr,
                                buf, sizeof(buf)));
        printk("Subnet: %s\n",
                net_addr_ntop(AF_INET,
                                &iface->config.ip.ipv4->netmask,
                                buf, sizeof(buf)));
        printk("Router: %s\n",
                net_addr_ntop(AF_INET,
                                &iface->config.ip.ipv4->gw,
                                buf, sizeof(buf)));
        }

        k_sem_give(&ipv4_address_obtained);
}

static void wifi_mgmt_event_handler(struct net_mgmt_event_callback *cb, uint32_t mgmt_event, struct net_if *iface)
{
    switch (mgmt_event)
    {

        case NET_EVENT_WIFI_CONNECT_RESULT:
            handle_wifi_connect_result(cb);
            break;

        case NET_EVENT_WIFI_DISCONNECT_RESULT:
            handle_wifi_disconnect_result(cb);
            break;

        case NET_EVENT_IPV4_ADDR_ADD:
            handle_ipv4_result(iface);
            break;

        default:
            break;
    }
}

bool wifi_connect(uint8_t* ssid, ssize_t len_ssid, uint8_t* pass, ssize_t len_pass)
{
    struct net_if *iface = net_if_get_default();

    struct wifi_connect_req_params wifi_params = {0};

    wifi_params.ssid = ssid;
    wifi_params.psk = pass;
    wifi_params.ssid_length = len_ssid;
    wifi_params.psk_length = len_pass;
    wifi_params.channel = WIFI_CHANNEL_ANY;
    wifi_params.security = WIFI_SECURITY_TYPE_PSK;
    wifi_params.band = WIFI_FREQ_BAND_2_4_GHZ; 
    wifi_params.mfp = WIFI_MFP_OPTIONAL;

    printk("Connecting to SSID: %s\n", wifi_params.ssid);

    if (net_mgmt(NET_REQUEST_WIFI_CONNECT, iface, &wifi_params, sizeof(struct wifi_connect_req_params)))
    {
        printk("WiFi Connection Request Failed\n");
        return false;
    }
    return true;
}

void wifi_status(void)
{
    struct net_if *iface = net_if_get_default();
    
    struct wifi_iface_status status = {0};

    if (net_mgmt(NET_REQUEST_WIFI_IFACE_STATUS, iface, &status,	sizeof(struct wifi_iface_status)))
    {
        printk("WiFi Status Request Failed\n");
    }

    printk("\n");

    if (status.state >= WIFI_STATE_ASSOCIATED) {
        printk("SSID: %-32s\n", status.ssid);
        printk("Band: %s\n", wifi_band_txt(status.band));
        printk("Channel: %d\n", status.channel);
        printk("Security: %s\n", wifi_security_txt(status.security));
        printk("RSSI: %d\n", status.rssi);
    }
}

void wifi_disconnect(void)
{
    struct net_if *iface = net_if_get_default();

    if (net_mgmt(NET_REQUEST_WIFI_DISCONNECT, iface, NULL, 0))
    {
        printk("WiFi Disconnection Request Failed\n");
    }
}

static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL,
		      BT_UUID_16_ENCODE(BT_UUID_HRS_VAL),
		      BT_UUID_16_ENCODE(BT_UUID_BAS_VAL),
		      BT_UUID_16_ENCODE(BT_UUID_DIS_VAL))
};

// Definir una variable global para almacenar el valor de la característica
static char wifi_ssid[50];
static bool wifi_ssid_set = false;

static char wifi_pass[50];
static bool wifi_pass_set = false;

// Función para manejar las solicitudes de escritura en la característica WiFi
static ssize_t write_ssid(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                          const void *buf, uint16_t len, uint16_t offset,
                          uint8_t flags)
{
    if (offset + len > sizeof(wifi_ssid)) {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memset(wifi_ssid, 0, 50);
    memcpy(wifi_ssid + offset, buf, len);
    wifi_ssid_set = true;

    return len;
}

static ssize_t write_pass(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                          const void *buf, uint16_t len, uint16_t offset,
                          uint8_t flags)
{
    if (offset + len > sizeof(wifi_pass)) {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memset(wifi_pass, 0, 50);
    memcpy(wifi_pass + offset, buf, len);
    wifi_pass_set = true;

    return len;
}


#define WIFI_SSID_UUID_CHAR 0xb8, 0x39, 0x34, 0xf8, 0xaf, 0x02, 0x3d, 0xad,\
                            0xda, 0x4c, 0xab, 0x78, 0xc3, 0x64, 0xa9, 0x35
//35a963c3-78ab-4cda-ad3d-02aff83439b8
#define BT_UUID_WIFI_SSID   BT_UUID_DECLARE_128(WIFI_SSID_UUID_CHAR)

#define WIFI_PASS_UUID_CHAR 0xb8, 0x3a, 0x34, 0xf8, 0xaf, 0x02, 0x3d, 0xad,\
                            0xda, 0x4c, 0xab, 0x78, 0xc3, 0x64, 0xa9, 0x35
//35a963c3-78ab-4cda-ad3d-02aff83439b8
#define BT_UUID_WIFI_PASS   BT_UUID_DECLARE_128(WIFI_PASS_UUID_CHAR)

BT_GATT_SERVICE_DEFINE(wifi_svc,
	BT_GATT_PRIMARY_SERVICE(BT_UUID_ESS),

  /* WiFi */
  BT_GATT_CHARACTERISTIC(BT_UUID_WIFI_SSID,
             BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE,
			       NULL, write_ssid, wifi_ssid),

	BT_GATT_CUD("SSID Wi-Fi", BT_GATT_PERM_READ),

  BT_GATT_CHARACTERISTIC(BT_UUID_WIFI_PASS,
             BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE,
			       NULL, write_pass, wifi_pass),

	BT_GATT_CUD("PASS Wi-Fi", BT_GATT_PERM_READ)
);

typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	uint8_t day_of_week;
	uint8_t exact_time_256;
	uint8_t adjust_reason;
} cts_datetime_t;

//cts_datetime_t datetime;

static struct {
	int offset;
	cts_datetime_t datetime;
} m_read_buf;

static struct bt_uuid_16 uuid = BT_UUID_INIT_16(0);
static struct bt_gatt_read_params read_params;

static struct tm hora = { 0 };

uint8_t cts_sync_read(struct bt_conn *conn, uint8_t err,
				    struct bt_gatt_read_params *params,
				    //const void *data, u16_t length)
				    const void *data, uint16_t length)
{

	if (!data || length <= 0) {
		return BT_GATT_ITER_STOP;
	}

	memcpy(&m_read_buf.datetime + m_read_buf.offset, data, length);
	m_read_buf.offset += length;
    printk("%d:%d:%d %02d/%02d/%04d\n", m_read_buf.datetime.hours, m_read_buf.datetime.minutes, m_read_buf.datetime.seconds, m_read_buf.datetime.day, m_read_buf.datetime.month, m_read_buf.datetime.year);

    hora.tm_sec = m_read_buf.datetime.seconds;
    hora.tm_min = m_read_buf.datetime.minutes;
    hora.tm_hour = m_read_buf.datetime.hours;
    hora.tm_mday = m_read_buf.datetime.day;
    hora.tm_mon = m_read_buf.datetime.month - 1;
    hora.tm_year = m_read_buf.datetime.year - 1900;
    hora.tm_wday = m_read_buf.datetime.day_of_week;
    hora.tm_yday = -1;
    hora.tm_isdst = -1;



    time_t epoch = timeutil_timegm(&hora);
    struct timespec tspec;
    tspec.tv_sec = epoch;
    tspec.tv_nsec= 0;
    printk("Epoch: %lld\n", epoch);
    clock_settime(CLOCK_REALTIME, &tspec);

	return BT_GATT_ITER_CONTINUE;
}

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		printk("Connection failed (err 0x%02x)\n", err);
	} else {
		printk("Connected\n");
		memcpy(&uuid, BT_UUID_CTS_CURRENT_TIME, sizeof(uuid));
		memset(&read_params, 0, sizeof(read_params));
		read_params.func = cts_sync_read;
		read_params.by_uuid.uuid = (struct bt_uuid *) &uuid;
		read_params.by_uuid.start_handle = 0x0001;//attr->handle;
		read_params.by_uuid.end_handle = 0xffff;
		m_read_buf.offset = 0;
		bt_gatt_read(conn, &read_params);
	}
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	printk("Disconnected (reason 0x%02x)\n", reason);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = connected,
	.disconnected = disconnected,
};

static void bt_ready(void)
{
	int err;

	printk("Bluetooth initialized\n");

	err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
	if (err) {
		printk("Advertising failed to start (err %d)\n", err);
		return;
	}

	printk("Advertising successfully started\n");
}

static void auth_cancel(struct bt_conn *conn)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing cancelled: %s\n", addr);
}

static struct bt_conn_auth_cb auth_cb_display = {
	.cancel = auth_cancel,
};

static void bas_notify(void)
{
	uint8_t battery_level = bt_bas_get_battery_level();

	battery_level--;

	if (!battery_level) {
		battery_level = 100U;
	}

	bt_bas_set_battery_level(battery_level);
}

static void hrs_notify(void)
{
	static uint8_t heartrate = 90U;

	/* Heartrate measurements simulation */
	heartrate++;
	if (heartrate == 160U) {
		heartrate = 90U;
	}

	bt_hrs_notify(heartrate);
}


int main(void)
{
	int err;

	printk("Iniciando app\n");
    memset(wifi_ssid, 0, 50);

	err = bt_enable(NULL);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return 0;
	}

	bt_ready();

	bt_conn_auth_cb_register(&auth_cb_display);

    if (rtc_dev == NULL) {
        LOG_ERR("RTC device not found\n");
        return 0;
    }
    err = device_is_ready(rtc_dev);
    LOG_INF("RTC dev: %d\n", err);

	net_mgmt_init_event_callback(&wifi_cb, wifi_mgmt_event_handler,
                                 NET_EVENT_WIFI_CONNECT_RESULT | NET_EVENT_WIFI_DISCONNECT_RESULT);

    net_mgmt_init_event_callback(&ipv4_cb, wifi_mgmt_event_handler, NET_EVENT_IPV4_ADDR_ADD);

    net_mgmt_add_event_callback(&wifi_cb);
    net_mgmt_add_event_callback(&ipv4_cb);



	while (1) {
		k_sleep(K_SECONDS(1));
        struct timespec tspec;
        clock_gettime(CLOCK_REALTIME, &tspec);
        struct tm *tiempo;
        tiempo = gmtime(&tspec.tv_sec);
        printk("Hora: %02d:%02d:%02d del %02d/%02d/%04d\n", tiempo->tm_hour, tiempo->tm_min, tiempo->tm_sec, tiempo->tm_mday, tiempo->tm_mon + 1, tiempo->tm_year + 1900);
        // printk("get epoch: %lld\n", tspec.tv_sec);
        if(wifi_ssid_set && wifi_pass_set){
            if(wifi_connect(wifi_ssid, strlen(wifi_ssid), wifi_pass, strlen(wifi_pass))){
                wifi_ssid_set = false;
                wifi_pass_set = false;
            }
        }

		/* Heartrate measurements simulation */
		hrs_notify();

		// /* Battery level simulation */
		bas_notify();
	}
	return 0;
}