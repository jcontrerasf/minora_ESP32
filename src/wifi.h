#pragma once

#include <zephyr/kernel.h>
#include <zephyr/types.h>
#include <stddef.h>

bool wifi_connect(uint8_t* ssid, ssize_t len_ssid, uint8_t* pass, ssize_t len_pass);

void wifi_set_callbacks();