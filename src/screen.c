#include "screen.h"
#include <zephyr/drivers/display.h>
#include <zephyr/sys/printk.h>
#include <lvgl.h>

LV_FONT_DECLARE(kode_mono_bold_20);
LV_FONT_DECLARE(kode_mono_bold_18);
LV_FONT_DECLARE(kode_mono_bold_24);
LV_FONT_DECLARE(kode_mono_bold_26);

//Agregar soporte para inglés
char* str_days[7]   = {"dom", "lun", "mar", "mie", "jue", "vie", "sab"};
char* str_months[12] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};

const struct device *display;
static lv_obj_t * date_label;

void screen_init(){
  
  lv_obj_t *hello_world_label;

  display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

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

  date_label = lv_label_create(lv_scr_act());
  lv_label_set_text(date_label, "dom 09 jun 2024"); //LV_SYMBOL_BLUETOOTH
  lv_obj_add_style(date_label, &my_style, LV_PART_MAIN);
  lv_obj_align(date_label, LV_ALIGN_CENTER, 0, 30);
}

void screen_set_date(int wday, int mday, int month, int year){
  char date[30];
  // display_blanking_on(display);
  sprintf(date, "%s %02d %s %04d", str_days[wday], mday, str_months[month], year);
  lv_label_set_text(date_label, date);
  display_blanking_off(display);
  lv_task_handler();
}

//Esto sí funciona para forzar una actualización completa
    // if(tiempo->tm_sec%10 == 0){
    //     display_blanking_on(display);
    //     lv_label_set_text(date_label, fecha);
    //     display_blanking_off(display);
    //     lv_task_handler();
    // }
        