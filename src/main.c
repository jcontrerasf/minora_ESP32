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

#define API_SERVER "api.open-meteo.com"
#define API_URL "/v1/forecast?latitude=-33.4569&longitude=-70.6483&daily=temperature_2m_max,temperature_2m_min,weather_code&timezone=auto&forecast_days=2&hourly=temperature_2m"

int main(void){

  printk("Iniciando app\n");

  memory_init();

  ble_init();

  screen_init();

  wifi_init();
  
  bool once = false;

  while (1) {
    k_sleep(K_SECONDS(1));
    struct timespec tspec;
    clock_gettime(CLOCK_REALTIME, &tspec);
    // tspec.tv_sec += gmt_offset;
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
      wifi_get_ntp();
      once = true;
    }

    forecast_update_data(wifi_is_connected(), tspec.tv_sec, API_SERVER, API_URL);

    screen_update_forecast(tspec.tv_sec);
    
    // screen_refresh(); //quitar esto para evitar valores por default al inicio

  }
  return 0;
}