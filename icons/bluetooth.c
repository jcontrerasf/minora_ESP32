#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_24DP
#define LV_ATTRIBUTE_IMG_BLUETOOTH_24DP
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BLUETOOTH_24DP uint8_t bluetooth_24dp_map[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xe0, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xf0, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xf8, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xfc, 0x00, 0x0f, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0xfe, 0x00, 0x0f, 0xf3, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xff, 0x00, 0x0f, 0xf1, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xff, 0x80, 0x0f, 0xf0, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xff, 0xc0, 0x0f, 0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xe0, 0x0f, 0xf0, 0x3f, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7f, 0xf0, 0x0f, 0xf0, 0x1f, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xf8, 0x0f, 0xf0, 0x1f, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xfc, 0x0f, 0xf0, 0x3f, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0f, 0xfe, 0x0f, 0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xff, 0x0f, 0xf0, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xff, 0x8f, 0xf1, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0xff, 0xcf, 0xf3, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xef, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xef, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0xff, 0xcf, 0xf3, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xff, 0x8f, 0xf1, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xff, 0x0f, 0xf0, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0f, 0xfe, 0x0f, 0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xfc, 0x0f, 0xf0, 0x3f, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xf8, 0x0f, 0xf0, 0x1f, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7f, 0xf0, 0x0f, 0xf0, 0x1f, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xe0, 0x0f, 0xf0, 0x3f, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xff, 0xc0, 0x0f, 0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xff, 0x80, 0x0f, 0xf0, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xff, 0x00, 0x0f, 0xf1, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0xfe, 0x00, 0x0f, 0xf3, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xfc, 0x00, 0x0f, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xf8, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xf0, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xe0, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t bluetooth_24dp = {
  .header.cf = LV_IMG_CF_ALPHA_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 96,
  .header.h = 96,
  .data_size = 1152,
  .data = bluetooth_24dp_map,
};