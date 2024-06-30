#include <zephyr/data/json.h>

/******************IMPORTANT********************
Fue necesario modificar la librería JSON de Zephyr,
específicamente el archivo /zephyrproject/zephyr/lib/os/json.c,
que corresponde a este: https://github.com/zephyrproject-rtos/zephyr/blob/main/lib/utils/json.c

- En la función: static int64_t decode_value(struct json_obj *obj,
			    const struct json_obj_descr *descr,
			    struct json_token *value, void *field, void *val)

  case JSON_TOK_OPAQUE: {
		struct json_obj_token *obj_token = field;

		obj_token->start = value->start;
		obj_token->length = value->end - value->start;
		return 0;
	}
	case JSON_TOK_FLOAT: {
		float *num = field;
		char *endptr;
		*num = strtol(value->start, &endptr, 10);
		if(*endptr == '.' && *(endptr + 1) >= '0' && *(endptr + 1) <= '9'){
			*num += (double)((*(endptr + 1) - '0') / 10.0);
		}else if (endptr != value->end) {
			return -EINVAL;
		}
		return 0;
	}


- En la función: static ptrdiff_t get_elem_size(const struct json_obj_descr *descr)

  case JSON_TOK_FLOAT:
		return sizeof(float);
	case JSON_TOK_OPAQUE:
	case JSON_TOK_OBJ_ARRAY:
		return sizeof(struct json_obj_token);
    
*******************IMPORTANT********************/

struct hourly_units {
  const char *time;
  const char *temperature_2m;
};

struct hourly {
  const char *time[48];
  float temperature_2m[48];
  size_t time_len;
  size_t temperature_2m_len;
};

struct daily_units {
  const char *time;
  const char *temperature_2m_max;
  const char *temperature_2m_min;
  const char *weather_code;
};

struct daily {
  const char *time[2];
  float temperature_2m_max[2];
  float temperature_2m_min[2];
  int weather_code[2];
  size_t time_len;
  size_t temperature_2m_max_len;
  size_t temperature_2m_min_len;
  size_t weather_code_len;
};

struct weather_data {
  float latitude;
  float longitude;
  float generationtime_ms;
  int utc_offset_seconds;
  const char *timezone;
  const char *timezone_abbreviation;
  float elevation;
  struct hourly_units hourly_units;
  struct hourly hourly;
  struct daily_units daily_units;
  struct daily daily;
};


const struct json_obj_descr hourly_units_descr[] = {
  JSON_OBJ_DESCR_PRIM(struct hourly_units, time, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct hourly_units, temperature_2m, JSON_TOK_STRING)
};

const struct json_obj_descr hourly_descr[] = {
  JSON_OBJ_DESCR_ARRAY(struct hourly, time, 48, time_len, JSON_TOK_STRING),
  JSON_OBJ_DESCR_ARRAY(struct hourly, temperature_2m, 48, temperature_2m_len, JSON_TOK_FLOAT),
};

const struct json_obj_descr daily_units_descr[] = {
  JSON_OBJ_DESCR_PRIM(struct daily_units, time, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct daily_units, temperature_2m_max, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct daily_units, temperature_2m_min, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct daily_units, weather_code, JSON_TOK_STRING)
};

const struct json_obj_descr daily_descr[] = {
  JSON_OBJ_DESCR_ARRAY(struct daily, time, 2, time_len, JSON_TOK_STRING),
  JSON_OBJ_DESCR_ARRAY(struct daily, temperature_2m_max, 2, temperature_2m_max_len, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_ARRAY(struct daily, temperature_2m_min, 2, temperature_2m_min_len, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_ARRAY(struct daily, weather_code, 2, weather_code_len, JSON_TOK_NUMBER),
};

const struct json_obj_descr weather_data_descr[] = {
  JSON_OBJ_DESCR_PRIM(struct weather_data, latitude, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_PRIM(struct weather_data, longitude, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_PRIM(struct weather_data, generationtime_ms, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_PRIM(struct weather_data, utc_offset_seconds, JSON_TOK_NUMBER),
  JSON_OBJ_DESCR_PRIM(struct weather_data, timezone, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct weather_data, timezone_abbreviation, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct weather_data, elevation, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_OBJECT(struct weather_data, hourly_units, hourly_units_descr),
  JSON_OBJ_DESCR_OBJECT(struct weather_data, hourly, hourly_descr),
  JSON_OBJ_DESCR_OBJECT(struct weather_data, daily_units, daily_units_descr),
  JSON_OBJ_DESCR_OBJECT(struct weather_data, daily, daily_descr)
};