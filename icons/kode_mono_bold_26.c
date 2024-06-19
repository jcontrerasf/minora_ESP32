/*******************************************************************************
 * Size: 26 px
 * Bpp: 1
 * Opts: --bpp 1 --size 26 --no-compress --font KodeMono-Bold.ttf --range 32-127 --format lvgl -o kode_mono_bold_26.c
 ******************************************************************************/

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

#ifndef KODE_MONO_BOLD_26
#define KODE_MONO_BOLD_26 1
#endif

#if KODE_MONO_BOLD_26

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xe0, 0x0,
    0xf, 0xff,

    /* U+0022 "\"" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7,

    /* U+0023 "#" */
    0x7, 0x38, 0xe, 0x70, 0x18, 0xe0, 0x71, 0xc3,
    0xff, 0xe7, 0xff, 0xcf, 0xff, 0x87, 0x38, 0xc,
    0x70, 0x38, 0xe0, 0x71, 0x80, 0xe7, 0xf, 0xff,
    0x9f, 0xff, 0x3f, 0xfe, 0x1c, 0x70, 0x38, 0xc0,
    0x73, 0x80, 0xe7, 0x0,

    /* U+0024 "$" */
    0x7, 0x0, 0x38, 0xf, 0xf8, 0xff, 0xef, 0xff,
    0x70, 0x3b, 0x80, 0x9c, 0x0, 0xe0, 0x7, 0x80,
    0x1f, 0xf8, 0xff, 0xe3, 0xff, 0x80, 0x1c, 0x0,
    0xe0, 0x7, 0x40, 0x3f, 0xff, 0xff, 0xfc, 0xff,
    0xc0, 0x70, 0x3, 0x80, 0x1c, 0x0, 0xe0,

    /* U+0025 "%" */
    0x38, 0x8, 0xf8, 0x3d, 0xf0, 0x7b, 0xe1, 0xe3,
    0x87, 0x80, 0x1e, 0x0, 0x38, 0x0, 0xf0, 0x3,
    0xc0, 0xf, 0x0, 0x1c, 0x0, 0x78, 0x1, 0xe0,
    0x7, 0x87, 0x1e, 0x1f, 0x3c, 0x3e, 0xf0, 0x7c,
    0xc0, 0x70,

    /* U+0026 "&" */
    0xf, 0xe0, 0x1f, 0xf0, 0x3f, 0xf0, 0x38, 0x70,
    0x3c, 0xf0, 0x1f, 0xe0, 0xf, 0xc0, 0xf, 0x80,
    0xf, 0x80, 0x1f, 0xcf, 0x3f, 0xcf, 0x79, 0xef,
    0xf0, 0xff, 0xe0, 0x7e, 0xe0, 0x7c, 0xe0, 0x78,
    0xff, 0xfc, 0x7f, 0xfe, 0x7f, 0xce,

    /* U+0027 "'" */
    0xff, 0xff, 0xff,

    /* U+0028 "(" */
    0x0, 0x1, 0x81, 0xe1, 0xf1, 0xf1, 0xf1, 0xf1,
    0xf0, 0xf0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x3,
    0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xf, 0x3,
    0xc0, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xe0, 0x60,

    /* U+0029 ")" */
    0x0, 0x30, 0x3c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c,
    0x1f, 0x7, 0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c,
    0xe, 0x7, 0x3, 0x81, 0xc0, 0xe0, 0x70, 0x78,
    0x78, 0x78, 0x7c, 0x7c, 0x7c, 0x3c, 0xc, 0x0,

    /* U+002A "*" */
    0xe, 0x1, 0xc0, 0x38, 0x7f, 0xff, 0xfe, 0xff,
    0x87, 0xc1, 0xfc, 0x7b, 0xc6, 0x30, 0x44, 0x0,

    /* U+002B "+" */
    0xe, 0x1, 0xc0, 0x38, 0x7, 0xf, 0xff, 0xff,
    0xff, 0xf8, 0x70, 0xe, 0x1, 0xc0, 0x38, 0x0,

    /* U+002C "," */
    0xff, 0xff, 0xf3, 0x9d, 0xef, 0x71, 0x0,

    /* U+002D "-" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+002E "." */
    0xff, 0xff, 0xff, 0x80,

    /* U+002F "/" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0xe0, 0x1c, 0x3,
    0x80, 0xe0, 0x1c, 0x3, 0x80, 0xe0, 0x1c, 0x3,
    0x80, 0xe0, 0x1c, 0x3, 0x80, 0xe0, 0x1c, 0x7,
    0x80, 0xe0, 0x1c, 0x7, 0x80, 0xe0, 0x1c, 0x7,
    0x0, 0x60, 0x0,

    /* U+0030 "0" */
    0x3f, 0xc7, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x7e,
    0xf, 0xe1, 0xfe, 0x3f, 0xe7, 0x7e, 0xe7, 0xfc,
    0x7f, 0x87, 0xf0, 0x7e, 0x7, 0xe0, 0x77, 0xff,
    0x7f, 0xe3, 0xfc,

    /* U+0031 "1" */
    0x7, 0x0, 0x78, 0x7, 0xc0, 0x7e, 0x7, 0xf0,
    0x7b, 0x81, 0x9c, 0x0, 0xe0, 0x7, 0x0, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80, 0x1c,
    0x0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+0032 "2" */
    0x3f, 0xe3, 0xff, 0xbf, 0xfd, 0xc0, 0xf4, 0x3,
    0x80, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+0033 "3" */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xe0, 0x1e,
    0x1, 0xe0, 0x1e, 0x1, 0xfc, 0xf, 0xe0, 0x7f,
    0x80, 0x1e, 0x0, 0x70, 0x3, 0x80, 0x1c, 0x0,
    0xff, 0xff, 0xff, 0xf7, 0xff, 0x0,

    /* U+0034 "4" */
    0x0, 0x78, 0x1, 0xf0, 0x7, 0xe0, 0x1f, 0xc0,
    0x7b, 0x81, 0xe7, 0x7, 0x8e, 0x1e, 0x1c, 0x78,
    0x38, 0xe0, 0x70, 0xff, 0xf9, 0xff, 0xf1, 0xff,
    0xe0, 0x7, 0x0, 0xe, 0x0, 0x1c, 0x0, 0x38,
    0x0, 0x70, 0x0, 0xe0,

    /* U+0035 "5" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xe, 0x0,
    0x7f, 0xe1, 0xff, 0x8f, 0xfe, 0x0, 0x70, 0x3,
    0xc0, 0xe, 0x0, 0x70, 0x3, 0x80, 0x1c, 0x0,
    0xff, 0xff, 0xff, 0xf7, 0xff, 0x0,

    /* U+0036 "6" */
    0x3f, 0xc7, 0xfc, 0xff, 0xce, 0x0, 0xe0, 0xe,
    0x0, 0xe0, 0xe, 0xfe, 0xff, 0xff, 0xff, 0xf8,
    0x7f, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0xf7, 0xfe,
    0x7f, 0xc3, 0xf8,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0xf0, 0xf,
    0x80, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0, 0xf0,
    0xf, 0x0, 0x70, 0x3, 0x80, 0x1c, 0x0, 0xe0,
    0x7, 0x0, 0x38, 0x1, 0xc0, 0x0,

    /* U+0038 "8" */
    0xf, 0xc1, 0xfe, 0x3f, 0xf7, 0x87, 0xf0, 0x7e,
    0x7, 0xe0, 0xf7, 0xfe, 0x7f, 0xc3, 0xfc, 0x78,
    0xef, 0xf, 0xe0, 0x7e, 0x7, 0xe0, 0xf7, 0xfe,
    0x7f, 0xc3, 0xf8,

    /* U+0039 "9" */
    0x7f, 0x8f, 0xfc, 0xff, 0xee, 0xe, 0xe0, 0x7e,
    0x7, 0x70, 0x77, 0xff, 0x3f, 0xf1, 0xff, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0xe7, 0xfe,
    0x7f, 0xc7, 0xf8,

    /* U+003A ":" */
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xfc,

    /* U+003B ";" */
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x1, 0xff,
    0xff, 0xe7, 0x3b, 0xde, 0xe2, 0x0,

    /* U+003C "<" */
    0x0, 0x80, 0xf0, 0x7c, 0x3e, 0x1f, 0xf, 0x7,
    0x83, 0xc0, 0xf0, 0x3e, 0x7, 0xc0, 0x78, 0xf,
    0x1, 0xe0, 0x3c, 0x6, 0x0, 0x0,

    /* U+003D "=" */
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xf0,

    /* U+003E ">" */
    0x0, 0x1c, 0xf, 0x81, 0xf0, 0x3e, 0x3, 0xc0,
    0x78, 0xf, 0x3, 0xc1, 0xf0, 0xf8, 0x78, 0x3c,
    0x1e, 0xf, 0x1, 0x80, 0x0, 0x0,

    /* U+003F "?" */
    0xf, 0xf0, 0x1f, 0xf8, 0x3f, 0xfc, 0x78, 0x1c,
    0x70, 0x1e, 0x60, 0x1f, 0x0, 0x3c, 0x0, 0x78,
    0x0, 0xf0, 0x1, 0xe0, 0x3, 0xc0, 0x3, 0x80,
    0x3, 0x80, 0x3, 0x80, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0,

    /* U+0040 "@" */
    0x7, 0xf0, 0x1f, 0xf8, 0x3f, 0xfc, 0x78, 0x1e,
    0xf0, 0x7, 0xe1, 0xc7, 0xe3, 0xe7, 0xe7, 0xf7,
    0xee, 0x77, 0xee, 0x77, 0xee, 0x77, 0xee, 0x77,
    0xee, 0x77, 0xe7, 0xff, 0xe3, 0xfe, 0xf0, 0x0,
    0x78, 0x0, 0x3f, 0xf0, 0x1f, 0xf0, 0xf, 0xf0,

    /* U+0041 "A" */
    0xf, 0xe3, 0xfc, 0xff, 0xbc, 0x7f, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1c,

    /* U+0042 "B" */
    0xff, 0xef, 0xfe, 0xff, 0xfe, 0x7, 0xe0, 0x7e,
    0xf, 0xe1, 0xee, 0x3c, 0xff, 0xcf, 0xfc, 0xff,
    0xee, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7f, 0xff,
    0xff, 0xff, 0xfc,

    /* U+0043 "C" */
    0x3f, 0xc7, 0xfe, 0xff, 0xfe, 0x7, 0xe0, 0x2e,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xe0,
    0xe, 0x0, 0xe0, 0xe, 0x2, 0xe0, 0x67, 0xff,
    0x7f, 0xe3, 0xfc,

    /* U+0044 "D" */
    0xff, 0xc7, 0xfe, 0x3f, 0xf9, 0xc1, 0xee, 0x7,
    0x70, 0x3f, 0x80, 0xfc, 0x7, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1f, 0x80,
    0xff, 0xff, 0xff, 0xf7, 0xff, 0x0,

    /* U+0045 "E" */
    0x3f, 0xfb, 0xff, 0xff, 0xff, 0xc0, 0xe, 0x0,
    0x70, 0x3, 0x80, 0x1c, 0x0, 0xff, 0x87, 0xfc,
    0x3f, 0xe1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80,
    0xf, 0xff, 0x7f, 0xf9, 0xff, 0xc0,

    /* U+0046 "F" */
    0x3f, 0xf7, 0xff, 0xff, 0xfe, 0x0, 0xe0, 0xe,
    0x0, 0xe0, 0xe, 0x0, 0xff, 0x8f, 0xf8, 0xff,
    0x8e, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0,
    0xe0, 0xe, 0x0,

    /* U+0047 "G" */
    0x3f, 0xc7, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x6e,
    0x0, 0xe0, 0xe, 0x7e, 0xe7, 0xfe, 0x7f, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x77, 0xff,
    0x7f, 0xf3, 0xff,

    /* U+0048 "H" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0x80, 0xfd, 0xf7, 0xff, 0xff, 0xff,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1f, 0x80,
    0xfc, 0x7, 0xe0, 0x3f, 0x1, 0xc0,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xe, 0x0, 0x70,
    0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x0, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80, 0x1c,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0xff, 0xff, 0xff, 0xff, 0x80, 0x70, 0xe, 0x1,
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80,
    0x70, 0xe, 0x1, 0xc0, 0x38, 0xf, 0x3, 0xc7,
    0xf0, 0xfc, 0x1f, 0x0,

    /* U+004B "K" */
    0xe0, 0x7b, 0x83, 0xce, 0x1e, 0x38, 0xf0, 0xe7,
    0x83, 0xbc, 0xf, 0xe0, 0x3f, 0x80, 0xff, 0x3,
    0xdc, 0xe, 0x78, 0x38, 0xf0, 0xe1, 0xc3, 0x87,
    0x8e, 0xf, 0x38, 0x1c, 0xe0, 0x7b, 0x80, 0xf0,

    /* U+004C "L" */
    0xe0, 0x7, 0x0, 0x38, 0x1, 0xc0, 0xe, 0x0,
    0x70, 0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x0,
    0x38, 0x1, 0xc0, 0xe, 0x0, 0x70, 0x1f, 0xc0,
    0xef, 0xff, 0x7f, 0xf9, 0xff, 0xc0,

    /* U+004D "M" */
    0xe0, 0x7f, 0xf, 0xf9, 0xff, 0x9f, 0xff, 0xff,
    0xf7, 0xef, 0x7e, 0x77, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7,
    0xe0, 0x7e, 0x7,

    /* U+004E "N" */
    0xf8, 0x7f, 0xc7, 0xfc, 0x7f, 0xe7, 0xee, 0x7e,
    0x77, 0xe7, 0xfe, 0x3f, 0xe3, 0xfe, 0x1f, 0xe0,
    0xfe, 0xf, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7,
    0xe0, 0x7e, 0x7,

    /* U+004F "O" */
    0x3f, 0xc7, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x77, 0xff,
    0x7f, 0xe3, 0xfc,

    /* U+0050 "P" */
    0xff, 0xe7, 0xff, 0xbf, 0xfd, 0xc0, 0xfe, 0x3,
    0xf0, 0x1f, 0x80, 0xfc, 0x7, 0xef, 0xff, 0xff,
    0xbf, 0xf9, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80,
    0x1c, 0x0, 0xe0, 0x7, 0x0, 0x0,

    /* U+0051 "Q" */
    0x3f, 0xc7, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x6e, 0x6, 0xe0, 0xce, 0x38, 0xe3, 0xc7, 0xfc,
    0x7f, 0xe3, 0xff, 0x0, 0x60,

    /* U+0052 "R" */
    0xff, 0xc7, 0xff, 0x3f, 0xfd, 0xc0, 0xee, 0x7,
    0xf0, 0x1f, 0x80, 0xfc, 0xf, 0xff, 0xf7, 0xff,
    0xbb, 0xf9, 0xc1, 0xee, 0x7, 0x70, 0x3f, 0x80,
    0xfc, 0x7, 0xe0, 0x3f, 0x1, 0xc0,

    /* U+0053 "S" */
    0x3f, 0xe3, 0xff, 0xbf, 0xfd, 0xc0, 0xee, 0x2,
    0x70, 0x3, 0x80, 0x1e, 0x0, 0x7f, 0xe3, 0xff,
    0x8f, 0xfe, 0x0, 0x70, 0x3, 0x80, 0x1d, 0x0,
    0xff, 0xff, 0xff, 0xf3, 0xff, 0x0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x80, 0x7,
    0x0, 0x1c, 0x0, 0x70, 0x1, 0xc0, 0x7, 0x0,
    0x1c, 0x0, 0x70, 0x1, 0xc0, 0x7, 0x0, 0x1c,
    0x0, 0x70, 0x1, 0xc0, 0x7, 0x0, 0x1c, 0x0,

    /* U+0055 "U" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0x80, 0xfc, 0x7, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1f, 0x80,
    0xef, 0xff, 0x7f, 0xf9, 0xfd, 0xc0,

    /* U+0056 "V" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0xf, 0x70, 0xe7, 0x9c, 0x3b, 0xc3, 0xf8,
    0x1f, 0x0, 0xe0,

    /* U+0057 "W" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0x80, 0xfc, 0xe7, 0xe7, 0x3f, 0x39,
    0xf9, 0xcf, 0xce, 0x7e, 0x73, 0xfb, 0x9d, 0xff,
    0xef, 0xfe, 0x3f, 0xe0, 0xee, 0x0,

    /* U+0058 "X" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc3,
    0xfc, 0xf3, 0xfc, 0x3f, 0x87, 0xf8, 0xe7, 0x3c,
    0x7f, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1c,

    /* U+0059 "Y" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xe0, 0x77, 0x87,
    0x9c, 0x78, 0xf7, 0x83, 0xf8, 0xf, 0x80, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80, 0x1c,
    0x0, 0xe0, 0x7, 0x0, 0x38, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x70, 0x3,
    0x80, 0x3c, 0x7, 0x83, 0xfc, 0x1f, 0xe0, 0xff,
    0x7, 0xc0, 0x7c, 0x7, 0x80, 0x78, 0x3, 0x80,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+005B "[" */
    0xff, 0xff, 0xff, 0xfc, 0xe, 0x7, 0x3, 0x81,
    0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x3,
    0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7,
    0x3, 0x81, 0xff, 0xff, 0xff, 0xc0,

    /* U+005C "\\" */
    0xe0, 0x1e, 0x1, 0xc0, 0x38, 0x3, 0x80, 0x70,
    0xe, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x38, 0x7,
    0x0, 0xe0, 0xe, 0x1, 0xc0, 0x38, 0x3, 0x80,
    0x70, 0xe, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x38,
    0x7, 0x0, 0xe0,

    /* U+005D "]" */
    0xff, 0xff, 0xff, 0x7, 0x7, 0x7, 0x7, 0x7,
    0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
    0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xff,
    0xff, 0xff,

    /* U+005E "^" */
    0x7, 0x80, 0x3f, 0x1, 0xfc, 0x7, 0x78, 0x3c,
    0xe0, 0xe3, 0xc7, 0x87, 0xbc, 0xe, 0xe0, 0x3c,
    0x80, 0x40,

    /* U+005F "_" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+0060 "`" */
    0x60, 0xf1, 0xf0, 0xf0, 0x60,

    /* U+0061 "a" */
    0x1f, 0xf0, 0xff, 0x87, 0xfe, 0x0, 0x70, 0x3,
    0x87, 0xfc, 0x7f, 0xe7, 0xff, 0x78, 0x3f, 0x81,
    0xfc, 0xe, 0xff, 0xf3, 0xff, 0x8f, 0xdc,

    /* U+0062 "b" */
    0xe0, 0x7, 0x0, 0x38, 0x1, 0xc0, 0xe, 0x0,
    0x77, 0xf3, 0xff, 0xdf, 0xfe, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1f, 0x80,
    0xfc, 0x7, 0xff, 0xff, 0xff, 0xbb, 0xf8,

    /* U+0063 "c" */
    0x3f, 0xc7, 0xfe, 0xff, 0xfe, 0x7, 0xe0, 0x2e,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x2, 0xe0,
    0x67, 0xff, 0x7f, 0xe3, 0xfc,

    /* U+0064 "d" */
    0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x73,
    0xf7, 0x7f, 0xff, 0xff, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7,
    0x7f, 0xf7, 0xff, 0x3f, 0x70,

    /* U+0065 "e" */
    0x3f, 0xc7, 0xfe, 0xff, 0xfe, 0xf, 0xe1, 0xef,
    0xfc, 0xff, 0x8f, 0xf0, 0xe0, 0xe, 0x0, 0xe0,
    0x67, 0xff, 0x7f, 0xe3, 0xfc,

    /* U+0066 "f" */
    0xf, 0xe1, 0xff, 0x3f, 0xf3, 0x86, 0x38, 0x3,
    0x80, 0x38, 0xf, 0xf8, 0xff, 0x8f, 0xf8, 0x38,
    0x3, 0x80, 0x38, 0x3, 0x80, 0x38, 0x3, 0x80,
    0x38, 0x3, 0x80,

    /* U+0067 "g" */
    0x1f, 0xb9, 0xff, 0xdf, 0xfe, 0xe0, 0x77, 0x3,
    0xb8, 0x3d, 0xff, 0xcf, 0xfc, 0x7f, 0x83, 0x80,
    0x1f, 0xfc, 0x7f, 0xe3, 0xff, 0xb8, 0x1d, 0xc0,
    0xee, 0xf, 0x7f, 0xf1, 0xff, 0x7, 0xf0,

    /* U+0068 "h" */
    0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe,
    0xfc, 0xff, 0xef, 0xfe, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7,
    0xe0, 0x7e, 0x7, 0xe0, 0x70,

    /* U+0069 "i" */
    0x7, 0x0, 0x38, 0x1, 0xc0, 0xe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0x80, 0x7e, 0x3, 0xf0,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80, 0x1c,
    0x0, 0xe0, 0x7, 0x0, 0x38, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0x80,

    /* U+006A "j" */
    0xe, 0x7, 0x3, 0x80, 0x0, 0x0, 0x0, 0xfe,
    0x7f, 0x3f, 0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c,
    0xe, 0x7, 0x3, 0x81, 0xc1, 0xe1, 0xef, 0xe7,
    0xe3, 0xe0,

    /* U+006B "k" */
    0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xe1, 0xee,
    0x3c, 0xe7, 0x8e, 0xf0, 0xfe, 0xf, 0xf0, 0xff,
    0xf, 0x38, 0xe3, 0xce, 0x1c, 0xe0, 0xee, 0xf,
    0xe0, 0x7e, 0x7, 0xe0, 0x70,

    /* U+006C "l" */
    0xf0, 0xf, 0xc0, 0xfc, 0x1, 0xc0, 0x1c, 0x1,
    0xc0, 0x1c, 0x1, 0xc0, 0x1c, 0x1, 0xc0, 0x1c,
    0x1, 0xc0, 0x1c, 0x1, 0xc0, 0x1c, 0x1, 0xc0,
    0xf, 0xf0, 0xff, 0x7, 0xf0,

    /* U+006D "m" */
    0xec, 0x67, 0xff, 0xbf, 0xfd, 0xce, 0x7e, 0x73,
    0xf3, 0x9f, 0x9c, 0xfc, 0x7, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1c,

    /* U+006E "n" */
    0xef, 0xcf, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7,

    /* U+006F "o" */
    0x3f, 0xc7, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x77, 0xff, 0x7f, 0xe3, 0xfc,

    /* U+0070 "p" */
    0xef, 0xcf, 0xfe, 0xff, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7f, 0xff, 0xff, 0xee, 0xfc, 0xe0, 0xe, 0x0,
    0xe0, 0xe, 0x0, 0xe0, 0x0,

    /* U+0071 "q" */
    0x3f, 0x77, 0xff, 0xff, 0xfe, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x77, 0xff, 0x7f, 0xf3, 0xf7, 0x0, 0x70, 0x7,
    0x0, 0x70, 0x7, 0x0, 0x70,

    /* U+0072 "r" */
    0xe7, 0xe7, 0xff, 0xbf, 0xfc, 0x38, 0x41, 0xc0,
    0xe, 0x0, 0x70, 0x3, 0x80, 0x1c, 0x0, 0xe0,
    0x7, 0x1, 0xff, 0xf, 0xf8, 0x7f, 0xc0,

    /* U+0073 "s" */
    0x3f, 0xc7, 0xfe, 0xff, 0xfe, 0x6, 0xe0, 0x7,
    0xfc, 0x7f, 0xe3, 0xff, 0x0, 0x70, 0x7, 0x40,
    0x7f, 0xff, 0xff, 0xe7, 0xfc,

    /* U+0074 "t" */
    0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x81, 0xff,
    0x3f, 0xe7, 0xfc, 0x38, 0x7, 0x0, 0xe0, 0x1c,
    0x3, 0x80, 0x70, 0xe, 0x11, 0xc6, 0x1f, 0xe3,
    0xf8, 0x3e, 0x0,

    /* U+0075 "u" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x77, 0xff, 0x7f, 0xf3, 0xf7,

    /* U+0076 "v" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xf0, 0xf7, 0x9e, 0x3b,
    0xc3, 0xf8, 0x1f, 0x0, 0xe0,

    /* U+0077 "w" */
    0xe3, 0x8f, 0xc7, 0x1f, 0x8e, 0x3f, 0x1c, 0x7e,
    0x38, 0xfc, 0x71, 0xf8, 0xe3, 0xf1, 0xc7, 0xe3,
    0x8e, 0xe7, 0x3d, 0xff, 0xf9, 0xff, 0xe1, 0xff,
    0x83, 0xde, 0x0,

    /* U+0078 "x" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0xff, 0x1f,
    0x3f, 0xf0, 0xff, 0x87, 0xfe, 0x7c, 0x7f, 0x81,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1c,

    /* U+0079 "y" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xf0,
    0x77, 0xff, 0x3f, 0xf3, 0xff, 0x0, 0xf0, 0x1e,
    0xff, 0xcf, 0xf8, 0xff, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xff, 0xff, 0xf0, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70,
    0xf, 0xff, 0xff, 0xff, 0xff,

    /* U+007B "{" */
    0x3, 0xf0, 0x7f, 0x7, 0xf0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0xf0, 0x1e,
    0x3, 0xc0, 0x78, 0x7, 0x80, 0x3c, 0x1, 0xe0,
    0xf, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x7f, 0x7, 0xf0, 0x3f,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8,

    /* U+007D "}" */
    0xfc, 0xf, 0xe0, 0xfe, 0x0, 0xe0, 0xe, 0x0,
    0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xf0, 0x7,
    0x80, 0x3c, 0x1, 0xe0, 0x1e, 0x3, 0xc0, 0x78,
    0xf, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0,
    0xe0, 0xe, 0xf, 0xe0, 0xfe, 0xf, 0xc0,

    /* U+007E "~" */
    0x8, 0x8, 0xfc, 0xef, 0xff, 0xb8, 0xf8, 0x0,
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 250, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 250, .box_w = 4, .box_h = 20, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 11, .adv_w = 250, .box_w = 9, .box_h = 8, .ofs_x = 3, .ofs_y = 10},
    {.bitmap_index = 20, .adv_w = 250, .box_w = 15, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 250, .box_w = 13, .box_h = 24, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 95, .adv_w = 250, .box_w = 15, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 250, .box_w = 16, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 250, .box_w = 3, .box_h = 8, .ofs_x = 6, .ofs_y = 10},
    {.bitmap_index = 170, .adv_w = 250, .box_w = 9, .box_h = 28, .ofs_x = 3, .ofs_y = -6},
    {.bitmap_index = 202, .adv_w = 250, .box_w = 9, .box_h = 28, .ofs_x = 3, .ofs_y = -6},
    {.bitmap_index = 234, .adv_w = 250, .box_w = 11, .box_h = 11, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 250, .adv_w = 250, .box_w = 11, .box_h = 11, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 266, .adv_w = 250, .box_w = 5, .box_h = 10, .ofs_x = 5, .ofs_y = -6},
    {.bitmap_index = 273, .adv_w = 250, .box_w = 10, .box_h = 3, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 277, .adv_w = 250, .box_w = 5, .box_h = 5, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 250, .box_w = 11, .box_h = 25, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 316, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 250, .box_w = 13, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 250, .box_w = 15, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 250, .box_w = 5, .box_h = 14, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 250, .box_w = 5, .box_h = 21, .ofs_x = 5, .ofs_y = -6},
    {.bitmap_index = 634, .adv_w = 250, .box_w = 10, .box_h = 17, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 656, .adv_w = 250, .box_w = 12, .box_h = 9, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 670, .adv_w = 250, .box_w = 10, .box_h = 17, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 692, .adv_w = 250, .box_w = 16, .box_h = 19, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 730, .adv_w = 250, .box_w = 16, .box_h = 20, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 770, .adv_w = 250, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 795, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 909, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 936, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 963, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 993, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1023, .adv_w = 250, .box_w = 11, .box_h = 20, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1051, .adv_w = 250, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1083, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1113, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1167, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1194, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1224, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1253, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1283, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1313, .adv_w = 250, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1345, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1375, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1402, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1432, .adv_w = 250, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1457, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1487, .adv_w = 250, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1517, .adv_w = 250, .box_w = 9, .box_h = 26, .ofs_x = 4, .ofs_y = -5},
    {.bitmap_index = 1547, .adv_w = 250, .box_w = 11, .box_h = 25, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 1582, .adv_w = 250, .box_w = 8, .box_h = 26, .ofs_x = 4, .ofs_y = -5},
    {.bitmap_index = 1608, .adv_w = 250, .box_w = 14, .box_h = 10, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 1626, .adv_w = 250, .box_w = 14, .box_h = 3, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1632, .adv_w = 250, .box_w = 7, .box_h = 5, .ofs_x = 4, .ofs_y = 15},
    {.bitmap_index = 1637, .adv_w = 250, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1660, .adv_w = 250, .box_w = 13, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1691, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1712, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1741, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1762, .adv_w = 250, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1789, .adv_w = 250, .box_w = 13, .box_h = 19, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1820, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1849, .adv_w = 250, .box_w = 13, .box_h = 21, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1884, .adv_w = 250, .box_w = 9, .box_h = 23, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 1910, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1939, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1968, .adv_w = 250, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1991, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2012, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2033, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 2062, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 2091, .adv_w = 250, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2114, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2135, .adv_w = 250, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2162, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2183, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2204, .adv_w = 250, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2231, .adv_w = 250, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2254, .adv_w = 250, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 2283, .adv_w = 250, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2304, .adv_w = 250, .box_w = 12, .box_h = 26, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 2343, .adv_w = 250, .box_w = 3, .box_h = 23, .ofs_x = 6, .ofs_y = -4},
    {.bitmap_index = 2352, .adv_w = 250, .box_w = 12, .box_h = 26, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 2391, .adv_w = 250, .box_w = 14, .box_h = 5, .ofs_x = 1, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t kode_mono_bold_26 = {
#else
lv_font_t kode_mono_bold_26 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 28,          /*The maximum line height required by the font*/
    .base_line = 6,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if KODE_MONO_BOLD_26*/

