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

#ifndef LV_ATTRIBUTE_IMG_FOG
#define LV_ATTRIBUTE_IMG_FOG
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_FOG uint8_t fog_map[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xe0, 0x7f, 0x80, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0x00, 0x0f, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x7e, 0x00, 0x07, 0xe0, 0x00, 
  0x00, 0x00, 0x00, 0xf8, 0x00, 0x01, 0xf0, 0x00, 
  0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x78, 0x00, 
  0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x78, 0x00, 
  0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x3c, 0x00, 
  0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x3c, 0x00, 
  0x00, 0x0f, 0xf0, 0x80, 0x00, 0x00, 0x1c, 0x00, 
  0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x1e, 0x00, 
  0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 
  0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 
  0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 
  0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 
  0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 
  0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
  0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 
  0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 
  0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 
  0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
  0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 
  0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 
  0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
  0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
  0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 
  0x00, 0x03, 0xfe, 0x1f, 0xf8, 0x7f, 0xc0, 0x00, 
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
  0x00, 0x0f, 0x8f, 0xfc, 0x3f, 0xf1, 0xf0, 0x00, 
  0x00, 0x0c, 0x00, 0xc0, 0x03, 0x00, 0x30, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0xfc, 0x07, 0xe0, 0x3f, 0x80, 0x00, 
  0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
  0x00, 0x0e, 0x03, 0xf0, 0x0f, 0xc0, 0x70, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t fog = {
  .header.cf = LV_IMG_CF_ALPHA_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 64,
  .header.h = 64,
  .data_size = 512,
  .data = fog_map,
};
