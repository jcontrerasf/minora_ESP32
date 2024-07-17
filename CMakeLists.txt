# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
set(BOARD "esp32_devkitc_wroom")
set(DTC_OVERLAY_FILE "esp32.overlay")
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(Minora)

target_sources(app PRIVATE src/main.c)

# file(GLOB ICON_SOURCES "icons/*.c")
# target_sources(app PRIVATE ${ICON_SOURCES})
target_sources(app PRIVATE icons/overcast.c)
target_sources(app PRIVATE icons/sunny.c)
target_sources(app PRIVATE icons/partly_cloudy.c)
target_sources(app PRIVATE icons/rainy.c)
target_sources(app PRIVATE icons/fog.c)
target_sources(app PRIVATE icons/bluetooth_14.c)
target_sources(app PRIVATE icons/kode_mono_bold_26.c)

target_sources(app PRIVATE src/wifi.c)
target_sources(app PRIVATE src/ble.c)
target_sources(app PRIVATE src/screen.c)
target_sources(app PRIVATE src/memory.c)
target_sources(app PRIVATE src/forecast.c)