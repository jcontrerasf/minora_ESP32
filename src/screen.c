#include "screen.h"
#include <zephyr/drivers/display.h>
#include <zephyr/sys/printk.h>
#include <lvgl.h>
#include <math.h>

#include "forecast.h"

#define BASE_EPOCH 1717203600

// LV_FONT_DECLARE(kode_mono_bold_20);
// LV_FONT_DECLARE(kode_mono_bold_18);
// LV_FONT_DECLARE(kode_mono_bold_24);
LV_FONT_DECLARE(kode_mono_bold_26);

LV_IMG_DECLARE(bluetooth_14);
LV_IMG_DECLARE(bluetooth_16);

LV_IMG_DECLARE(overcast);
LV_IMG_DECLARE(sunny);
LV_IMG_DECLARE(partly_cloudy);
LV_IMG_DECLARE(rainy);

//Agregar soporte para inglés
char* str_days[7]   = {"dom", "lun", "mar", "mie", "jue", "vie", "sab"};
char* str_months[12] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};

const struct device *display;
static lv_obj_t * date_label;
static lv_obj_t * bt_icon;
static lv_obj_t * today_code;
static lv_obj_t * tomorrow_code;
static lv_obj_t * td_max_temp;
static lv_obj_t * td_min_temp;
static lv_obj_t * td_now_temp;
static lv_obj_t * tomorrow_date;
static lv_obj_t * tomorrow_minmax;

void screen_init(){
  
  lv_obj_t *hello_world_label;

  display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

  if(display == NULL){
      printk("Error display\n");
  }

  if(!device_is_ready(display)){
      printk("Error dev display\n");
  }


  lv_disp_t *lv_disp;
  lv_disp = lv_disp_get_default();
  lv_disp_set_rotation(NULL, LV_DISP_ROT_NONE);

  static lv_style_t kode_26;
  lv_style_init(&kode_26);
  lv_style_set_text_font(&kode_26, &kode_mono_bold_26);

  today_code = lv_img_create(lv_scr_act());
  lv_img_set_src(today_code, &sunny);
  lv_obj_align(today_code, LV_ALIGN_BOTTOM_LEFT, 0, 0);

  td_max_temp = lv_label_create(lv_scr_act());
  lv_label_set_text(td_max_temp, "13 C");
  lv_obj_align(td_max_temp, LV_ALIGN_BOTTOM_LEFT, 120, -30);


  td_min_temp = lv_label_create(lv_scr_act());
  lv_label_set_text(td_min_temp, "1 C");
  lv_obj_align(td_min_temp, LV_ALIGN_BOTTOM_LEFT, 120, -10);


  td_now_temp = lv_label_create(lv_scr_act());
  lv_label_set_text(td_now_temp, "10");
  lv_obj_add_style(td_now_temp, &kode_26, LV_PART_MAIN);
  lv_obj_align(td_now_temp, LV_ALIGN_BOTTOM_LEFT, 75, -10);


  lv_obj_t * td_now_text = lv_label_create(lv_scr_act());
  lv_label_set_text(td_now_text, "Ahora");
  lv_obj_align(td_now_text, LV_ALIGN_BOTTOM_LEFT, 65, -40);

  tomorrow_code = lv_img_create(lv_scr_act());
  lv_img_set_src(tomorrow_code, &sunny);
  lv_obj_align(tomorrow_code, LV_ALIGN_BOTTOM_MID, 50, 0);


  tomorrow_date = lv_label_create(lv_scr_act());
  lv_label_set_text(tomorrow_date, "tmw");
  lv_obj_align(tomorrow_date, LV_ALIGN_BOTTOM_RIGHT, -2, -40);

  tomorrow_minmax = lv_label_create(lv_scr_act());
  lv_label_set_text(tomorrow_minmax, "2 / 23");
  lv_obj_align(tomorrow_minmax, LV_ALIGN_BOTTOM_RIGHT, -2, -10);

  
  bt_icon = lv_img_create(lv_scr_act());
  lv_img_set_src(bt_icon, &bluetooth_14);
  lv_obj_align(bt_icon, LV_ALIGN_TOP_RIGHT, 0, 0);
  screen_hide_bt_icon();



  date_label = lv_label_create(lv_scr_act());
  lv_label_set_text(date_label, "dom 09 jun 2024");
  lv_obj_add_style(date_label, &kode_26, LV_PART_MAIN);
  lv_obj_align(date_label, LV_ALIGN_TOP_MID, 0, 2);
}

void screen_set_date(int wday, int mday, int month, int year){
  char date[30];
  // display_blanking_on(display);
  sprintf(date, "%s %02d %s %04d", str_days[wday], mday, str_months[month], year);
  lv_label_set_text(date_label, date);
  // display_blanking_off(display);
  // lv_task_handler();
}

const lv_img_dsc_t *weather_code_to_icon(uint8_t code){
  switch (code){
  case 0:
    return &sunny;
    break;

  case 1:
  case 2:
    return &partly_cloudy;
    break;

  case 3:
    return &overcast;
    break;
  
  default:
    return &rainy;
    break;
  }
}

void screen_set_tomorrow_info(int wday, int mday, float min, float max, int code){
  char str[10];
  sprintf(str, "%s %02d", str_days[wday], mday);
  lv_label_set_text(tomorrow_date, str);

  sprintf(str, "%d\xB0 / %d\xB0", (int)roundf(min), (int)roundf(max));
  lv_label_set_text(tomorrow_minmax, str);

  lv_img_set_src(tomorrow_code, weather_code_to_icon(code));
}

void screen_set_today_info(float now, float min, float max, int code){
  char str[10];
  sprintf(str, "%d", (int)roundf(now));//Agregar \xB0 en font   intentar centrar
  lv_label_set_text(td_now_temp, str);

  sprintf(str, "%d \xB0"  "C", (int)roundf(min));
  lv_label_set_text(td_min_temp, str);

  sprintf(str, "%d \xB0"  "C", (int)roundf(max));
  lv_label_set_text(td_max_temp, str);

  lv_img_set_src(today_code, weather_code_to_icon(code));
}

//fuerza partial update que permite limpiar la pantalla, como complete update pero sin parpadeo molesto
void screen_force_refresh(){
  for(int i = 0; i<5; i++){
    lv_label_set_text(td_max_temp, NULL);
    lv_task_handler();
  }
  display_blanking_off(display);
}

void screen_update_forecast(time_t td){
  static time_t last_update = BASE_EPOCH;
  struct weather_data *wd = forecast_get_parsed_data();


  if(td > BASE_EPOCH && (td - last_update >= 3600) && wd != NULL){

    last_update = td - (td % 3600);

    td += wd->utc_offset_seconds;
    struct tm *now = gmtime(&td);
    screen_set_today_info(wd->hourly.temperature_2m[now->tm_hour], wd->daily.temperature_2m_min[0], wd->daily.temperature_2m_max[0], wd->hourly.weather_code[now->tm_hour]);
    screen_set_date(now->tm_wday, now->tm_mday, now->tm_mon, now->tm_year + 1900);

    time_t tmw = td + (24*3600);
    struct tm *tomorrow = gmtime(&tmw);
    screen_set_tomorrow_info(tomorrow->tm_wday, tomorrow->tm_mday, wd->daily.temperature_2m_min[1], wd->daily.temperature_2m_max[1], wd->daily.weather_code[1]);
    screen_force_refresh();
  }
}

//Esto sí funciona para forzar una actualización completa
    // if(tiempo->tm_sec%10 == 0){
    //     display_blanking_on(display);
    //     lv_label_set_text(date_label, fecha);
    //     display_blanking_off(display);
    //     lv_task_handler();
    // }


void screen_show_bt_icon(){
  lv_obj_clear_flag(bt_icon, LV_OBJ_FLAG_HIDDEN);
}

void screen_hide_bt_icon(){
  lv_obj_add_flag(bt_icon, LV_OBJ_FLAG_HIDDEN);
}

void screen_refresh(){
  lv_task_handler();
}