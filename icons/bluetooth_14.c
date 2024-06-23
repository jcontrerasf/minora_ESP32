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

//https://javl.github.io/image2cpp/

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_14
#define LV_ATTRIBUTE_IMG_BLUETOOTH_14
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BLUETOOTH_14 uint8_t bluetooth_14_map[] = {
  0x0e, 0x00, 0x0b, 0x00, 0x89, 0x80, 0xc8, 0x80, 0x69, 0x80, 0x3b, 0x00, 0x1e, 0x00, 0x1e, 0x00, 
  0x3b, 0x00, 0x69, 0x80, 0xc8, 0x80, 0x89, 0x80, 0x0b, 0x00, 0x0e, 0x00
};

const lv_img_dsc_t bluetooth_14 = {
  .header.cf = LV_IMG_CF_ALPHA_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 9,
  .header.h = 14,
  .data_size = 28,
  .data = bluetooth_14_map,
};
