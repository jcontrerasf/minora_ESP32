/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --no-compress --font KodeMono-Bold.ttf --range 48-57,97-121 --format lvgl -o kode_mono_bold_18.c
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

#ifndef KODE_MONO_BOLD_18
#define KODE_MONO_BOLD_18 1
#endif

#if KODE_MONO_BOLD_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x7f, 0x7f, 0xb0, 0x78, 0x7c, 0x7e, 0x7f, 0x77,
    0xf3, 0xf1, 0xf0, 0xf0, 0x6f, 0xf7, 0xf0,

    /* U+0031 "1" */
    0x18, 0x1c, 0x1e, 0x1f, 0x5, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x1f, 0xff, 0xf8,

    /* U+0032 "2" */
    0x7f, 0x7f, 0xb0, 0xe0, 0x30, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x1f, 0xff, 0xf8,

    /* U+0033 "3" */
    0xff, 0xff, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0x7c,
    0x7, 0x1, 0x80, 0xc0, 0x7f, 0xff, 0xf0,

    /* U+0034 "4" */
    0x3, 0x80, 0xf0, 0x3e, 0xe, 0xc3, 0x98, 0xe3,
    0x18, 0x63, 0xff, 0x3f, 0xe0, 0x30, 0x6, 0x0,
    0xc0, 0x18,

    /* U+0035 "5" */
    0xff, 0xff, 0xf0, 0x18, 0xf, 0xe3, 0xf8, 0xe,
    0x3, 0x1, 0x80, 0xc0, 0x7f, 0xff, 0xf0,

    /* U+0036 "6" */
    0x7f, 0x7f, 0xb0, 0x18, 0xc, 0x7, 0xfb, 0xff,
    0xc3, 0xc1, 0xe0, 0xf0, 0xef, 0xe7, 0xe0,

    /* U+0037 "7" */
    0xff, 0xff, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60,
    0x70, 0x30, 0x18, 0xc, 0x6, 0x3, 0x0,

    /* U+0038 "8" */
    0x3f, 0x3f, 0xf8, 0x78, 0x3c, 0x3b, 0xf9, 0xfc,
    0xe6, 0xc1, 0xe0, 0xf0, 0xef, 0xe7, 0xe0,

    /* U+0039 "9" */
    0x7e, 0x7f, 0xb0, 0xf8, 0x3e, 0x1b, 0xfc, 0xfe,
    0x3, 0x1, 0x80, 0xc0, 0xef, 0xe7, 0xe0,

    /* U+0061 "a" */
    0x3f, 0x1f, 0xc0, 0x60, 0x31, 0xf9, 0xfd, 0xc7,
    0xc3, 0x7f, 0x9f, 0xc0,

    /* U+0062 "b" */
    0xc0, 0x60, 0x30, 0x18, 0xf, 0xf7, 0xfb, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3f, 0xff, 0xf8,

    /* U+0063 "c" */
    0x7e, 0xff, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc1,
    0x7f, 0x7e,

    /* U+0064 "d" */
    0x1, 0x80, 0xc0, 0x60, 0x37, 0xff, 0xff, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x37, 0xfb, 0xfc,

    /* U+0065 "e" */
    0x7e, 0xff, 0xc3, 0xc7, 0xfe, 0xfc, 0xc0, 0xc0,
    0xff, 0x7e,

    /* U+0066 "f" */
    0x1f, 0x1f, 0xcc, 0x46, 0x3, 0x7, 0xf3, 0xf8,
    0x60, 0x30, 0x18, 0xc, 0x6, 0x3, 0x0,

    /* U+0067 "g" */
    0x7f, 0xff, 0xc3, 0xc3, 0xc7, 0xfe, 0xfc, 0xc0,
    0xfe, 0x7f, 0xc3, 0xc7, 0xfe, 0x7c,

    /* U+0068 "h" */
    0xc0, 0x60, 0x30, 0x18, 0xf, 0xf7, 0xfb, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc,

    /* U+0069 "i" */
    0x18, 0xc, 0x0, 0x0, 0x0, 0x3, 0x81, 0xc0,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x1, 0x87, 0xff,
    0xfe,

    /* U+006A "j" */
    0x18, 0x60, 0x0, 0x0, 0xf3, 0xc3, 0xc, 0x30,
    0xc3, 0xc, 0x31, 0xbe, 0xf0,

    /* U+006B "k" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x76, 0x73, 0x71,
    0xf8, 0xfc, 0x73, 0x31, 0xd8, 0x7c, 0x1e, 0xc,

    /* U+006C "l" */
    0xe0, 0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x1f, 0x1f,

    /* U+006D "m" */
    0xfb, 0xbf, 0xec, 0xcf, 0x33, 0xcc, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x30,

    /* U+006E "n" */
    0xff, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+006F "o" */
    0x7f, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x7f, 0xbf, 0x80,

    /* U+0070 "p" */
    0xff, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xff, 0xff, 0xb0, 0x18, 0xc, 0x6, 0x0,

    /* U+0071 "q" */
    0x7f, 0xff, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x7f, 0xbf, 0xc0, 0x60, 0x30, 0x18, 0xc,

    /* U+0072 "r" */
    0xdf, 0xff, 0xcc, 0x46, 0x3, 0x1, 0x80, 0xc0,
    0x60, 0xfe, 0x7f, 0x0,

    /* U+0073 "s" */
    0x7e, 0xff, 0xc2, 0xc0, 0x7e, 0x7f, 0x3, 0x3,
    0xff, 0xfe,

    /* U+0074 "t" */
    0x30, 0x18, 0xc, 0x6, 0xf, 0xe7, 0xf0, 0xc0,
    0x60, 0x30, 0x18, 0xc, 0x6, 0x21, 0xf0, 0xf0,

    /* U+0075 "u" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x7f, 0xbf, 0xc0,

    /* U+0076 "v" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0x1d, 0x9c,
    0xfc, 0x3c, 0xc, 0x0,

    /* U+0077 "w" */
    0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3e,
    0xcd, 0xff, 0x7f, 0x8f, 0xc0,

    /* U+0078 "x" */
    0xc1, 0xe0, 0xf0, 0xfc, 0xe7, 0xf3, 0xf9, 0xcf,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+0079 "y" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0xc3, 0x7f, 0xbf, 0xc0, 0xe0, 0xef, 0xe7, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 173, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 246, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 173, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 173, .box_w = 6, .box_h = 17, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 292, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 173, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 375, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 391, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 173, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 25, .glyph_id_start = 11,
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
    .cmap_num = 2,
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
const lv_font_t kode_mono_bold_18 = {
#else
lv_font_t kode_mono_bold_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if KODE_MONO_BOLD_18*/

