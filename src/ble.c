#include "ble.h"

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <time.h>
#include <zephyr/sys/timeutil.h>

#include "wifi.h"
#include "screen.h"
#include "memory.h"

static ssize_t write_ssid(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                          const void *buf, uint16_t len, uint16_t offset,
                          uint8_t flags);
                      
static ssize_t write_pass(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                          const void *buf, uint16_t len, uint16_t offset,
                          uint8_t flag);

#define BT_UUID_WIFI_SVC         BT_UUID_DECLARE_16(0x1820) //Internet Protocol Support service

#define BT_UUID_WIFI_SSID_CHRC   BT_UUID_DECLARE_16(0x2b37) //Registered User

#define BT_UUID_WIFI_PASS_CHRC   BT_UUID_DECLARE_16(0x2a02) //Peripheral Privacy Flag

//Scan Response data
// static const struct bt_data sd[] = {
//  BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
// };

//Advertisement data
static const struct bt_data ad[] = {
  BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
  BT_DATA_BYTES(BT_DATA_UUID16_ALL,
          BT_UUID_16_ENCODE(BT_UUID_HRS_VAL),
          BT_UUID_16_ENCODE(BT_UUID_BAS_VAL),
          BT_UUID_16_ENCODE(BT_UUID_DIS_VAL))
};

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

  memory_set_wifi_ssid(wifi_ssid, strlen(wifi_ssid));
  printk("SSID seteado desde BT: %s\n", wifi_ssid);

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

  memory_set_wifi_pass(wifi_pass, strlen(wifi_pass));
  printk("PASS seteado desde BT: %s\n", wifi_pass);

  return len;
}


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
    return;
  }

  printk("Connected\n");
  memcpy(&uuid, BT_UUID_CTS_CURRENT_TIME, sizeof(uuid));
  memset(&read_params, 0, sizeof(read_params));
  read_params.func = cts_sync_read;
  read_params.by_uuid.uuid = (struct bt_uuid *) &uuid;
  read_params.by_uuid.start_handle = 0x0001;//attr->handle;
  read_params.by_uuid.end_handle = 0xffff;
  m_read_buf.offset = 0;
  bt_gatt_read(conn, &read_params);

  screen_show_bt_icon();
  
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
  printk("Disconnected (reason 0x%02x)\n", reason);
  screen_hide_bt_icon();
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

void ble_init(){

  bt_addr_le_t addr = {0};
  size_t count = 1;

  int err = bt_enable(NULL);
  if (err) {
    printk("Bluetooth init failed (err %d)\n", err);
    return;
  }

  bt_ready();

  bt_conn_auth_cb_register(&auth_cb_display);
  

  bt_id_get(&addr, &count);
  printk("%02x%02x\n", addr.a.val[1], addr.a.val[0]);
  char ble_name[30];
  sprintf(ble_name, "%s %02X%02X", CONFIG_BT_DEVICE_NAME, addr.a.val[1], addr.a.val[0]);

  bt_set_name(ble_name);
  bt_le_adv_update_data(ad, ARRAY_SIZE(ad), NULL, 0);

}