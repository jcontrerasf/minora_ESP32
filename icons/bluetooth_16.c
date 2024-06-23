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

#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_16
#define LV_ATTRIBUTE_IMG_BLUETOOTH_16
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BLUETOOTH_16 uint8_t bluetooth_16_map[] = {
  0x06, 0x00, 0x07, 0x00, 0x05, 0x80, 0xc4, 0xc0, 0xe4, 0x40, 0x74, 0xc0, 0x3d, 0x80, 0x0f, 0x00, 
  0x0f, 0x00, 0x3d, 0x80, 0x74, 0xc0, 0xe4, 0x40, 0xc4, 0xc0, 0x05, 0x80, 0x07, 0x00, 0x06, 0x00 
};

const lv_img_dsc_t bluetooth_16 = {
  .header.cf = LV_IMG_CF_ALPHA_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 10,
  .header.h = 16,
  .data_size = 32,
  .data = bluetooth_16_map,
};
