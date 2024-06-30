/* main.c - Application main entry point */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>

#include <time.h>
#include <zephyr/sys/timeutil.h>
#include <zephyr/logging/log.h>

#include "screen.h"
#include "wifi.h"
#include "ble.h"
#include "memory.h"
#include "forecast.h"

const int gmt_offset = -4 * MIN_PER_HOUR * SEC_PER_MIN;

int main(void){

  printk("Iniciando app\n");

  memory_init();

  ble_init();

  screen_init();

  wifi_init();

  uint8_t last_day = 0;
  
  bool once = false;

  while (1) {
    k_sleep(K_SECONDS(1));
    struct timespec tspec;
    clock_gettime(CLOCK_REALTIME, &tspec);
    tspec.tv_sec += gmt_offset;
    struct tm *tiempo;
    tiempo = gmtime(&tspec.tv_sec);
    printk("Hora: %02d:%02d:%02d del %02d/%02d/%04d\n", tiempo->tm_hour, tiempo->tm_min, tiempo->tm_sec, tiempo->tm_mday, tiempo->tm_mon + 1, tiempo->tm_year + 1900);
    printk("get epoch: %lld\n", tspec.tv_sec);
    if(wifi_ssid_set && wifi_pass_set){
      if(wifi_connect(wifi_ssid, strlen(wifi_ssid), wifi_pass, strlen(wifi_pass))){
        wifi_ssid_set = false;
        wifi_pass_set = false;
      }
    }

    if(!once && wifi_is_connected()){
      test_float();
      wifi_get_ntp();
      forecast_get("api.open-meteo.com", "/v1/forecast?latitude=-33.4569&longitude=-70.6483&daily=temperature_2m_max,temperature_2m_min,weather_code&timezone=auto&forecast_days=2");//&hourly=temperature_2m
      once = true;
    }

    if(last_day != tiempo->tm_mday){
      last_day = tiempo->tm_mday;
      screen_set_date(tiempo->tm_wday, tiempo->tm_mday, tiempo->tm_mon, tiempo->tm_year + 1900);
    }   
    
    screen_update();

  }
  return 0;
}