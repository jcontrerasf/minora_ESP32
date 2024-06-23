#pragma once

#include <zephyr/kernel.h>
#include <zephyr/types.h>
#include <stddef.h>

extern char wifi_ssid[50];
extern bool wifi_ssid_set;

extern char wifi_pass[50];
extern bool wifi_pass_set;

bool wifi_connect(uint8_t* ssid, ssize_t len_ssid, uint8_t* pass, ssize_t len_pass);

void wifi_init();