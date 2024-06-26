#pragma once

#include <zephyr/kernel.h>
#include <zephyr/types.h>
#include <stddef.h>

#define WIFI_MAX_CHAR_CREDS 30

extern char wifi_ssid[WIFI_MAX_CHAR_CREDS];
extern bool wifi_ssid_set;

extern char wifi_pass[WIFI_MAX_CHAR_CREDS];
extern bool wifi_pass_set;

bool wifi_connect(uint8_t* ssid, ssize_t len_ssid, uint8_t* pass, ssize_t len_pass);

void wifi_init();