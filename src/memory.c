#include "memory.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <string.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/storage/flash_map.h>
#include <zephyr/fs/nvs.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(memory);


static struct nvs_fs fs;

#define NVS_PARTITION    storage_partition
#define NVS_PARTITION_DEVICE  FIXED_PARTITION_DEVICE(NVS_PARTITION)
#define NVS_PARTITION_OFFSET  FIXED_PARTITION_OFFSET(NVS_PARTITION)


#define WIFI_SSID_ID 1
#define WIFI_PASS_ID 2

void memory_init(){
  int rc = 0;
  struct flash_pages_info info;

  fs.flash_device = NVS_PARTITION_DEVICE;
  if (!device_is_ready(fs.flash_device)) {
    printk("Flash device %s is not ready\n", fs.flash_device->name);
    return;
  }
  fs.offset = NVS_PARTITION_OFFSET;
  rc = flash_get_page_info_by_offs(fs.flash_device, fs.offset, &info);
  if (rc) {
    printk("Unable to get page info\n");
    return;
  }
  fs.sector_size = info.size;
  fs.sector_count = 3U;

  rc = nvs_mount(&fs);
  if (rc) {
    printk("Flash Init failed\n");
    return;
  }
}

char* memory_check_wifi_ssid(){
  int rc = 0;
  static char ssid[30];
  memset(ssid, 0, sizeof(ssid));

  rc = nvs_read(&fs, WIFI_SSID_ID, ssid, sizeof(ssid));
  if (rc > 0) {
    LOG_INF("Id: %d, WiFi SSID: %s, len: %d", WIFI_SSID_ID, ssid, rc);
    return ssid;
  } else {
    LOG_INF("No exite wifi ssid");
    return NULL;
  }
}


char* memory_check_wifi_pass(){
  int rc = 0;
  static char pass[30];
  memset(pass, 0, sizeof(pass));

  rc = nvs_read(&fs, WIFI_PASS_ID, pass, sizeof(pass));
  if (rc > 0) {
    LOG_INF("Id: %d, WiFi PASS: %s, len: %d", WIFI_PASS_ID, pass, rc);
    return pass;
  } else {
    LOG_INF("No exite wifi pass");
    return NULL;
  }
}

void memory_set_wifi_ssid(char* ssid, size_t len){
  (void)nvs_write(&fs, WIFI_SSID_ID, ssid, len+1);//strlen(buf)+1
  //chequear valor de retorno
}

void memory_set_wifi_pass(char* pass, size_t len){
  (void)nvs_write(&fs, WIFI_PASS_ID, pass, len+1);//strlen(buf)+1
  //chequear valor de retorno
}

void memory_clear_wifi(){
  (void)nvs_delete(&fs, WIFI_SSID_ID);
  (void)nvs_delete(&fs, WIFI_PASS_ID);
}