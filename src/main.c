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
#include <zephyr/logging/log.h>


#include "screen.h"
#include "wifi.h"
#include "ble.h"


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



int main(void){
  int err;


  printk("Iniciando app\n");
  memset(wifi_ssid, 0, 50);
  memset(wifi_pass, 0, 50);

  // gpio_init();

  ble_init();

  screen_init();

  // display_set_pixel_format(display, PIXEL_FORMAT_MONO01);

  // int ret = cfb_framebuffer_init(display);
  // printk("ret framebuffer=%d\n", ret);

  // cfb_framebuffer_clear(display, true);

  // lv_task_handler();
  // display_blanking_off(display);

  // ret = cfb_print(display, "SALUDOS :D", 5, 5);
  // printk("ret print framebuffer=%d\n", ret);

  // ret = cfb_framebuffer_finalize(display);
  // printk("ret print finalize=%d\n", ret);

  wifi_set_callbacks();

  uint8_t last_day = 0;



  while (1) {
    k_sleep(K_SECONDS(1));
    struct timespec tspec;
    clock_gettime(CLOCK_REALTIME, &tspec);
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

    if(last_day != tiempo->tm_mday){
      last_day = tiempo->tm_mday;
      screen_set_date(tiempo->tm_wday, tiempo->tm_mday, tiempo->tm_mon, tiempo->tm_year + 1900);
    }   
    

  }
  return 0;
}