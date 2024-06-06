/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font KodeMono-VariableFont_wght.ttf --range 32-127 --format lvgl -o kode_mono_14.c
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

#ifndef KODE_MONO_14
#define KODE_MONO_14 1
#endif

#if KODE_MONO_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0x20,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x12, 0x12, 0x22, 0x7f, 0x24, 0x24, 0x24, 0xfe,
    0x4c, 0x48, 0x48,

    /* U+0024 "$" */
    0x10, 0xfa, 0x14, 0x8, 0x10, 0x1f, 0x1, 0x2,
    0x6, 0xf, 0xf1, 0x2, 0x0,

    /* U+0025 "%" */
    0x61, 0x31, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x40,
    0x60, 0x20, 0x21, 0xb0, 0xc0,

    /* U+0026 "&" */
    0x3c, 0x44, 0x4c, 0x28, 0x30, 0x30, 0x5b, 0x8b,
    0x86, 0x86, 0xfa,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x12, 0x6c, 0x88, 0x88, 0x88, 0x8c, 0x63, 0x10,

    /* U+0029 ")" */
    0x84, 0x63, 0x11, 0x11, 0x11, 0x13, 0x6c, 0x80,

    /* U+002A "*" */
    0x21, 0x3e, 0xe5, 0x8,

    /* U+002B "+" */
    0x21, 0x9, 0xf2, 0x10,

    /* U+002C "," */
    0xf5, 0xc0,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0x44, 0x21, 0x10, 0x84, 0x42, 0x11, 0x8,
    0x42, 0x0,

    /* U+0030 "0" */
    0x7a, 0x18, 0x63, 0x9e, 0xda, 0x71, 0x86, 0x17,
    0x80,

    /* U+0031 "1" */
    0x31, 0xcd, 0x4, 0x10, 0x41, 0x4, 0x10, 0x4f,
    0xc0,

    /* U+0032 "2" */
    0x7a, 0x10, 0x41, 0x8, 0x42, 0x18, 0x42, 0xf,
    0xc0,

    /* U+0033 "3" */
    0xfc, 0x10, 0x84, 0x30, 0xe0, 0x81, 0x4, 0x1f,
    0x80,

    /* U+0034 "4" */
    0xc, 0x28, 0xd3, 0x2c, 0x50, 0x9f, 0x82, 0x4,
    0x8, 0x10,

    /* U+0035 "5" */
    0xfe, 0x8, 0x20, 0xf8, 0x30, 0x41, 0x4, 0x1f,
    0x80,

    /* U+0036 "6" */
    0x7a, 0x8, 0x20, 0x82, 0xfc, 0x61, 0x86, 0x17,
    0x80,

    /* U+0037 "7" */
    0xfc, 0x10, 0xc6, 0x30, 0x84, 0x10, 0x41, 0x4,
    0x0,

    /* U+0038 "8" */
    0x39, 0x18, 0x61, 0x8d, 0xe4, 0xa1, 0x86, 0x17,
    0x80,

    /* U+0039 "9" */
    0xfa, 0x28, 0x61, 0x45, 0xf0, 0x41, 0x4, 0x3f,
    0x80,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xfc, 0x0, 0x36, 0x58, 0x0,

    /* U+003C "<" */
    0x0, 0x88, 0x8c, 0x61, 0x86, 0x18,

    /* U+003D "=" */
    0xf8, 0x1, 0xf0,

    /* U+003E ">" */
    0x2, 0x8, 0x20, 0x8c, 0xcc, 0xc0,

    /* U+003F "?" */
    0x7d, 0x8a, 0x8, 0x30, 0xc1, 0x4, 0x8, 0x0,
    0x0, 0x40,

    /* U+0040 "@" */
    0x3c, 0x42, 0x81, 0x9d, 0xa5, 0xa5, 0xa5, 0x9f,
    0x80, 0x40, 0x3c,

    /* U+0041 "A" */
    0x3d, 0x18, 0x61, 0x87, 0xf8, 0x61, 0x86, 0x18,
    0x40,

    /* U+0042 "B" */
    0xfe, 0x18, 0x62, 0x9b, 0xe8, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0043 "C" */
    0x7a, 0x18, 0x20, 0x82, 0x8, 0x20, 0x82, 0x17,
    0x80,

    /* U+0044 "D" */
    0xfa, 0x28, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0x80,

    /* U+0045 "E" */
    0x7e, 0x8, 0x20, 0x83, 0xc8, 0x20, 0x82, 0x7,
    0xc0,

    /* U+0046 "F" */
    0x7e, 0x8, 0x20, 0x83, 0xc8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0047 "G" */
    0x7a, 0x18, 0x20, 0x82, 0x78, 0x61, 0x86, 0x17,
    0xc0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0x87, 0xf8, 0x61, 0x86, 0x18,
    0x40,

    /* U+0049 "I" */
    0xfc, 0x41, 0x4, 0x10, 0x41, 0x4, 0x10, 0x4f,
    0xc0,

    /* U+004A "J" */
    0xf8, 0x42, 0x10, 0x84, 0x21, 0x8, 0x98,

    /* U+004B "K" */
    0x87, 0xa, 0x24, 0x8b, 0x1a, 0x36, 0x44, 0x85,
    0xe, 0x8,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0x17,
    0xc0,

    /* U+004D "M" */
    0x87, 0x3d, 0x6d, 0xb6, 0x18, 0x61, 0x86, 0x18,
    0x40,

    /* U+004E "N" */
    0xc6, 0x9b, 0x65, 0x8e, 0x38, 0x61, 0x86, 0x18,
    0x40,

    /* U+004F "O" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x17,
    0x80,

    /* U+0050 "P" */
    0xfa, 0x18, 0x61, 0x87, 0xe8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0051 "Q" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x27,
    0xc0,

    /* U+0052 "R" */
    0xfa, 0x28, 0x61, 0x87, 0xe8, 0xa1, 0x86, 0x18,
    0x40,

    /* U+0053 "S" */
    0x7a, 0x28, 0x20, 0x81, 0xe0, 0x41, 0x6, 0x1f,
    0xc0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x17,
    0xc0,

    /* U+0056 "V" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x49, 0x42,
    0x0,

    /* U+0057 "W" */
    0x83, 0x6, 0xc, 0x18, 0x32, 0x64, 0xc9, 0x93,
    0x75, 0xb0,

    /* U+0058 "X" */
    0x86, 0x18, 0x61, 0xc9, 0xe4, 0xe1, 0x86, 0x18,
    0x40,

    /* U+0059 "Y" */
    0x83, 0x5, 0xb, 0x22, 0x82, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+005A "Z" */
    0xfc, 0x10, 0x43, 0x8, 0xe2, 0x10, 0x82, 0xf,
    0xc0,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8f,

    /* U+005C "\\" */
    0x84, 0x21, 0x4, 0x21, 0x4, 0x21, 0x4, 0x21,
    0x4, 0x0,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f,

    /* U+005E "^" */
    0x30, 0xc6, 0x92, 0xc6, 0x10,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x8c,

    /* U+0061 "a" */
    0x3e, 0x4, 0x9, 0xf6, 0x38, 0x50, 0xbf,

    /* U+0062 "b" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0x80,

    /* U+0063 "c" */
    0x7a, 0x18, 0x20, 0x82, 0x8, 0x5e,

    /* U+0064 "d" */
    0x4, 0x10, 0x5f, 0x86, 0x18, 0x61, 0x86, 0x17,
    0xc0,

    /* U+0065 "e" */
    0x7a, 0x18, 0xbc, 0x82, 0x8, 0x5e,

    /* U+0066 "f" */
    0x3d, 0x14, 0x10, 0x43, 0xe4, 0x10, 0x41, 0x4,
    0x0,

    /* U+0067 "g" */
    0x7e, 0x18, 0x61, 0xfa, 0x7, 0xe1, 0x86, 0x37,
    0x80,

    /* U+0068 "h" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x40,

    /* U+0069 "i" */
    0x10, 0x0, 0x0, 0x60, 0x41, 0x4, 0x10, 0x41,
    0x3f,

    /* U+006A "j" */
    0x20, 0x7, 0x11, 0x11, 0x11, 0x12, 0xc0,

    /* U+006B "k" */
    0x82, 0x8, 0x22, 0x92, 0x8d, 0x22, 0x8a, 0x18,
    0x40,

    /* U+006C "l" */
    0xe0, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x81,
    0xc0,

    /* U+006D "m" */
    0xed, 0x26, 0x4c, 0x98, 0x30, 0x60, 0xc1,

    /* U+006E "n" */
    0xfa, 0x18, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x5e,

    /* U+0070 "p" */
    0xfa, 0x18, 0x61, 0x86, 0x18, 0x7e, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x7e, 0x18, 0x61, 0x86, 0x18, 0x5f, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xbc, 0x81, 0x2, 0x4, 0x8, 0x10, 0x7c,

    /* U+0073 "s" */
    0xfa, 0x8, 0x1e, 0x4, 0x18, 0x7f,

    /* U+0074 "t" */
    0x42, 0x11, 0xe4, 0x21, 0x8, 0x42, 0x4e,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x5f,

    /* U+0076 "v" */
    0x86, 0x18, 0x61, 0x85, 0x25, 0xc,

    /* U+0077 "w" */
    0x93, 0x26, 0x4c, 0x99, 0x32, 0x5f, 0x36,

    /* U+0078 "x" */
    0x86, 0x18, 0x9e, 0x4e, 0x18, 0x61,

    /* U+0079 "y" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0x5f, 0x4, 0x2f,
    0x0,

    /* U+007A "z" */
    0xfc, 0x10, 0x84, 0x31, 0x8c, 0x3f,

    /* U+007B "{" */
    0x39, 0x8, 0x42, 0x22, 0x10, 0x41, 0x8, 0x42,
    0x1c,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xe1, 0x8, 0x42, 0x8, 0x21, 0x11, 0x8, 0x42,
    0x70,

    /* U+007E "~" */
    0x1, 0xfc, 0x20
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 134, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 134, .box_w = 1, .box_h = 11, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 134, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 5, .adv_w = 134, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 29, .adv_w = 134, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 134, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 134, .box_w = 1, .box_h = 4, .ofs_x = 4, .ofs_y = 7},
    {.bitmap_index = 54, .adv_w = 134, .box_w = 4, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 62, .adv_w = 134, .box_w = 4, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 70, .adv_w = 134, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 74, .adv_w = 134, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 78, .adv_w = 134, .box_w = 2, .box_h = 5, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 80, .adv_w = 134, .box_w = 5, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 81, .adv_w = 134, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 134, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 92, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 134, .box_w = 2, .box_h = 7, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 185, .adv_w = 134, .box_w = 3, .box_h = 11, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 190, .adv_w = 134, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 196, .adv_w = 134, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 199, .adv_w = 134, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 205, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 134, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 226, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 134, .box_w = 5, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 134, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 378, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 134, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 469, .adv_w = 134, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 479, .adv_w = 134, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 486, .adv_w = 134, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 491, .adv_w = 134, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 492, .adv_w = 134, .box_w = 3, .box_h = 2, .ofs_x = 3, .ofs_y = 10},
    {.bitmap_index = 493, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 515, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 548, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 134, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 134, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 573, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 591, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 619, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 628, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 134, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 648, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 682, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 697, .adv_w = 134, .box_w = 1, .box_h = 14, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 699, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 708, .adv_w = 134, .box_w = 7, .box_h = 3, .ofs_x = 1, .ofs_y = 3}
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
const lv_font_t kode_mono_14 = {
#else
lv_font_t kode_mono_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if KODE_MONO_14*/

