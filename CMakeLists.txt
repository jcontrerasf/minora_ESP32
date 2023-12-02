# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
set(BOARD "esp32_devkitc_wroom")
set(DTC_OVERLAY_FILE "esp32.overlay")
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(Minora)

target_include_directories(app PRIVATE EPD)

target_sources(app PRIVATE src/main.c)

#target_sources(app PRIVATE EPD/EPAPER.c)
