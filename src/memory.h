#pragma once
#include <zephyr/types.h>

void memory_init();

char* memory_check_wifi_ssid();

char* memory_check_wifi_pass();

void memory_set_wifi_ssid(char* ssid, size_t len);

void memory_set_wifi_pass(char* pass, size_t len);

void memory_clear_wifi();