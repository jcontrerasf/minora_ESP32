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

#include <time.h>
#include <zephyr/sys/timeutil.h>
#include <zephyr/display/cfb.h>
#include <zephyr/drivers/display.h>
#include <zephyr/display/ssd16xx.h>
#include <zephyr/logging/log.h>
#include <lvgl.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#include <zephyr/kernel.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_event.h>

// #include "../EPD/EPAPER.h"

// static const struct device *display = DEVICE_DT_GET(DT_NODELABEL(ssd1675a));

const uint8_t gImage_up_L[64] = { /* 0X01,0X01,0X10,0X00,0X20,0X00, */
0xFC,0x1F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xF0,0x7F,0xFF,0xFF,0xE0,0xFF,0xFF,0xFF,
0xC1,0xFF,0xFF,0xFF,0x83,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,
0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x83,0xFF,0xFF,0xFF,0xC1,0xFF,0xFF,0xFF,
0xE0,0xFF,0xFF,0xFF,0xF0,0x7F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,
};

// static lv_image_dsc_t my_img_dsc = {
//     .header.always_zero = 0,
//     .header.w = 16,
//     .header.h = 32,
//     .data_size = 16 * 32 * LV_COLOR_DEPTH / 8,
//     .header.cf = LV_COLOR_FORMAT_NATIVE,          /*Set the color format*/
//     .data = gImage_up_L,
// };



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

#define BT_UUID_WIFI_SVC         BT_UUID_DECLARE_16(0x1820) //Internet Protocol Support service

#define BT_UUID_WIFI_SSID_CHRC   BT_UUID_DECLARE_16(0x2b37) //Registered User

#define BT_UUID_WIFI_PASS_CHRC   BT_UUID_DECLARE_16(0x2a02) //Peripheral Privacy Flag

BT_GATT_SERVICE_DEFINE(wifi_svc,
	BT_GATT_PRIMARY_SERVICE(BT_UUID_WIFI_SVC),

  /* WiFi */
  BT_GATT_CHARACTERISTIC(BT_UUID_WIFI_SSID_CHRC,
             BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_WRITE,
			       NULL, write_ssid, wifi_ssid),

	BT_GATT_CUD("SSID Wi-Fi", BT_GATT_PERM_READ),

  BT_GATT_CHARACTERISTIC(BT_UUID_WIFI_PASS_CHRC,
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


static struct {
	int offset;
	cts_datetime_t datetime;
} m_read_buf;

static struct bt_uuid_16 uuid = BT_UUID_INIT_16(0);
static struct bt_gatt_read_params read_params;

static struct tm hora = { 0 };

uint8_t cts_sync_read(struct bt_conn *conn, uint8_t err,
				    struct bt_gatt_read_params *params,
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


void gpio_init(){
    // if (!device_is_ready(edp_cs_pin.port) && !device_is_ready(edp_dc_pin.port)) {
	// 	printk("GPIO port initialization error\n");
	// 	return;
	// }
	// int ret;
	// ret = gpio_pin_configure_dt(&edp_cs_pin, GPIO_OUTPUT_ACTIVE);
	// if (ret < 0) {
	// 	return;
	// }
	// ret = gpio_pin_configure_dt(&edp_dc_pin, GPIO_OUTPUT_ACTIVE);
	// if (ret < 0) {
	// 	return;
	// }
	// ret = gpio_pin_configure_dt(&edp_res_pin, GPIO_OUTPUT_ACTIVE);
	// if (ret < 0) {
	// 	return;
	// }
	// ret = gpio_pin_configure_dt(&edp_busy_pin, GPIO_INPUT | GPIO_PULL_UP);
	// if (ret < 0) {
	// 	return;
	// }

	// printk("GPIO pins initialized correctly\n");
    // ret = gpio_pin_set_dt(&edp_res_pin, 0);
    // printk("pin reset low: %d\n", ret);
}

int main(void)
{
	int err;

    const struct device *display;
    lv_obj_t *hello_world_label;

	display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

	printk("Iniciando app\n");
    memset(wifi_ssid, 0, 50);
    memset(wifi_pass, 0, 50);

    // gpio_init();

	err = bt_enable(NULL);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return 0;
	}

	bt_ready();

	bt_conn_auth_cb_register(&auth_cb_display);


    if(display == NULL){
        printk("Error display\n");
    }

    if(!device_is_ready(display)){
        printk("Error dev display\n");
    }

    // display_set_orientation(display, DISPLAY_ORIENTATION_NORMAL);
    lv_disp_t *lv_disp;
    lv_disp = lv_disp_get_default();
    lv_disp_set_rotation(lv_disp, LV_DISP_ROT_NONE);
    // display_blanking_on(display);

    hello_world_label = lv_label_create(lv_scr_act());
    lv_label_set_text(hello_world_label, "Hola desde LVGL");
	lv_obj_align(hello_world_label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Boton");

    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_border_width(&style_btn, 2);
    lv_style_set_border_color(&style_btn, lv_color_black());

    // lv_obj_remove_style_all(btn1);                          /*Remove the style coming from the theme*/
    lv_obj_add_style(btn1, &style_btn, 0);


    // display_set_pixel_format(display, PIXEL_FORMAT_MONO01);

    // int ret = cfb_framebuffer_init(display);
    // printk("ret framebuffer=%d\n", ret);

    // cfb_framebuffer_clear(display, true);

    lv_task_handler();
	// display_blanking_off(display);

    // ret = cfb_print(display, "SALUDOS :D", 5, 5);
    // printk("ret print framebuffer=%d\n", ret);

    // ret = cfb_framebuffer_finalize(display);
    // printk("ret print finalize=%d\n", ret);


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

	}
	return 0;
}