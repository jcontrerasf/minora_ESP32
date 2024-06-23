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


#include "wifi.h"
#include "ble.h"

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

LV_FONT_DECLARE(kode_mono_bold_20);
LV_FONT_DECLARE(kode_mono_bold_18);
LV_FONT_DECLARE(kode_mono_bold_24);
LV_FONT_DECLARE(kode_mono_bold_26);



char* dias[7]   = {"dom", "lun", "mar", "mie", "jue", "vie", "sab"};
char* meses[12] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};


int main(void){
  int err;

  const struct device *display;
  lv_obj_t *hello_world_label;

  display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

  printk("Iniciando app\n");
  memset(wifi_ssid, 0, 50);
  memset(wifi_pass, 0, 50);

  // gpio_init();

  ble_init();


  if(display == NULL){
      printk("Error display\n");
  }

  if(!device_is_ready(display)){
      printk("Error dev display\n");
  }

  // display_set_orientation(display, DISPLAY_ORIENTATION_NORMAL);
  lv_disp_t *lv_disp;
  lv_disp = lv_disp_get_default();
  lv_disp_set_rotation(NULL, LV_DISP_ROT_NONE);
  // display_blanking_on(display);

  hello_world_label = lv_label_create(lv_scr_act());
  lv_label_set_text(hello_world_label, LV_SYMBOL_BLUETOOTH);
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

  LV_IMG_DECLARE(cloudy);
  lv_obj_t * img1 = lv_img_create(lv_scr_act());
  lv_img_set_src(img1, &cloudy);
  lv_obj_align(img1, LV_ALIGN_CENTER, -100, -30);

  LV_IMG_DECLARE(bluetooth_24dp);
  lv_obj_t * ble_img = lv_img_create(lv_scr_act());
  lv_img_set_src(ble_img, &bluetooth_24dp);
  lv_obj_align(ble_img, LV_ALIGN_TOP_RIGHT, 0, 0);


  static lv_style_t my_style;
  lv_style_init(&my_style);
  lv_style_set_text_font(&my_style, &kode_mono_bold_26);

  lv_obj_t * bt_icon = lv_label_create(lv_scr_act());
  lv_label_set_text(bt_icon, "dom 09 jun 2024"); //LV_SYMBOL_BLUETOOTH
  lv_obj_add_style(bt_icon, &my_style, LV_PART_MAIN);
  lv_obj_align(bt_icon, LV_ALIGN_CENTER, 0, 30);

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

  char fecha[30];
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
      // display_blanking_on(display);
      last_day = tiempo->tm_mday;
      sprintf(fecha, "%s %02d %s %04d", dias[tiempo->tm_wday], tiempo->tm_mday, meses[tiempo->tm_mon], tiempo->tm_year + 1900);
      lv_label_set_text(bt_icon, fecha);
      display_blanking_off(display);
      // lv_task_handler();
    }
    lv_task_handler();
    
    //Esto sí funciona para forzar una actualización completa
    // if(tiempo->tm_sec%10 == 0){
    //     display_blanking_on(display);
    //     lv_label_set_text(bt_icon, fecha);
    //     display_blanking_off(display);
    //     lv_task_handler();
    // }
        

  }
  return 0;
}