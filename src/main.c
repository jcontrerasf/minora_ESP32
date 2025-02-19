/* main.c - Application main entry point */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>

#include <time.h>
#include <zephyr/sys/timeutil.h>
#include <zephyr/logging/log.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/sensor_data_types.h>
#include <zephyr/rtio/rtio.h>
#include <zephyr/dsp/print_format.h>

#include "screen.h"
#include "wifi.h"
#include "ble.h"
#include "memory.h"
#include "forecast.h"

const int gmt_offset = -4 * MIN_PER_HOUR * SEC_PER_MIN;

#define API_SERVER "api.open-meteo.com"
#define API_URL "/v1/forecast?latitude=-33.4569&longitude=-70.6483&daily=temperature_2m_max,temperature_2m_min,weather_code&timezone=auto&forecast_days=2&hourly=temperature_2m,weather_code"


const struct device *const dev = DEVICE_DT_GET_ANY(bosch_bme680);

SENSOR_DT_READ_IODEV(iodev, DT_COMPAT_GET_ANY_STATUS_OKAY(bosch_bme680),
		{SENSOR_CHAN_AMBIENT_TEMP, 0},
		{SENSOR_CHAN_HUMIDITY, 0},
		{SENSOR_CHAN_PRESS, 0});

RTIO_DEFINE(ctx, 1, 1);

static const struct device *check_bme680_device(void)
{
	if (dev == NULL) {
		/* No such node, or the node does not have status "okay". */
		printk("\nError: no device found.\n");
		return NULL;
	}

	if (!device_is_ready(dev)) {
		printk("\nError: Device \"%s\" is not ready; "
		       "check the driver initialization logs for errors.\n",
		       dev->name);
		return NULL;
	}

	printk("Found device \"%s\", getting sensor data\n", dev->name);
	return dev;
}


int main(void){

  printk("Iniciando app\n");

  const struct device *dev = check_bme680_device();

  memory_init();

  ble_init();

  screen_init();

  wifi_init();
  
  bool once = false;

  while (1) {
    k_sleep(K_SECONDS(1));
    struct timespec tspec;
    clock_gettime(CLOCK_REALTIME, &tspec);
    // tspec.tv_sec += gmt_offset;
    struct tm *tiempo;
    tiempo = gmtime(&tspec.tv_sec);
    printk("Hora: %02d:%02d:%02d del %02d/%02d/%04d\n", tiempo->tm_hour, tiempo->tm_min, tiempo->tm_sec, tiempo->tm_mday, tiempo->tm_mon + 1, tiempo->tm_year + 1900);
    printk("get epoch: %lld\n", tspec.tv_sec);

    if(!once && wifi_is_connected()){
      wifi_get_ntp();
      once = true;
    }

    forecast_update_data(wifi_is_connected(), tspec.tv_sec, API_SERVER, API_URL);

    screen_update_forecast(tspec.tv_sec);
    
    // screen_refresh(); //quitar esto para evitar valores por default al inicio

    struct sensor_value value;
    if (sensor_sample_fetch(dev) == 0){
			float temp;
			float hum;
		  if(sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &value) == 0) {
				temp = value.val1 + (value.val2 * 10E-6);
				printk("Temp %0.2f C\n", temp);
			}
			if(sensor_channel_get(dev, SENSOR_CHAN_HUMIDITY, &value) == 0) {
				hum = value.val1 + (value.val2 * 10E-6);
				printk("Hum %0.2f %%\n", hum);
			}
      screen_set_indoor_sensor(temp, hum);

		}

		k_sleep(K_MSEC(1000));

  }
  return 0;
}