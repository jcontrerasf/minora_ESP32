#pragma once

#include "forecast_json_defs.h"

int forecast_get(const char *server, const char *url);

struct weather_data *forecast_get_parsed_data();

void forecast_update_data(bool conn, time_t t_now, const char *server, const char *url);