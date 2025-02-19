#pragma once

#include <time.h>
#include <zephyr/sys/timeutil.h>

void screen_init();

void screen_set_date(int wday, int mday, int month, int year);

void screen_show_bt_icon();

void screen_hide_bt_icon();

void screen_refresh();

void screen_update_forecast(time_t t);

void screen_set_indoor_sensor(float temp, float hum);