#pragma once

#include "forecast_json_defs.h"

int forecast_get(const char *server, const char *url);

struct weather_data *forecast_get_parsed_data();

void test_float(void);