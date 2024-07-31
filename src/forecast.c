#include "forecast.h"
#include <zephyr/kernel.h>
#include <zephyr/net/socket.h>
#include <zephyr/data/json.h>
#include <zephyr/logging/log.h>

#include <zephyr/net/net_ip.h>
#include <zephyr/net/tls_credentials.h>
#include <zephyr/net/http/client.h>


LOG_MODULE_REGISTER(forecast);

#define MAX_RECV_BUF_LEN 3000
#define HTTP_PORT "80"
#define API_UPDATE_INTERVAL (3600*6) //seconds

static uint8_t recv_buf[MAX_RECV_BUF_LEN];

K_SEM_DEFINE(api_req_sem, 1, 1);

const struct json_obj_descr hourly_units_descr[] = {
  JSON_OBJ_DESCR_PRIM(struct hourly_units, time, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct hourly_units, temperature_2m, JSON_TOK_STRING),
  JSON_OBJ_DESCR_PRIM(struct daily_units, weather_code, JSON_TOK_STRING)
};

const struct json_obj_descr hourly_descr[] = {
  JSON_OBJ_DESCR_ARRAY(struct hourly, time, 48, time_len, JSON_TOK_STRING),
  JSON_OBJ_DESCR_ARRAY(struct hourly, temperature_2m, 48, temperature_2m_len, JSON_TOK_FLOAT),
  JSON_OBJ_DESCR_ARRAY(struct hourly, weather_code, 48, weather_code_len, JSON_TOK_NUMBER),
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

struct weather_data wd;
bool parse_ok = false;

static bool forecast_parse_JSON(char *json_data);


static int setup_socket(const char *server, const char *port, int *sock)
{
  int ret = 0;

  struct zsock_addrinfo hints, *res;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  ret = zsock_getaddrinfo(server, port, &hints, &res);
  if (ret != 0) {
    LOG_ERR("getaddrinfo() failed: %d", ret);
    return -EINVAL;
  }

  *sock = zsock_socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  if (*sock < 0) {
    LOG_ERR("Failed to create HTTP socket (%d)", -errno);
    zsock_freeaddrinfo(res);
    return -errno;
  }

  ret = zsock_connect(*sock, res->ai_addr, res->ai_addrlen);
  if (ret < 0) {
    LOG_ERR("Cannot connect to remote (%d)", -errno);
    zsock_close(*sock);
    *sock = -1;
    zsock_freeaddrinfo(res);
    return -errno;
  }

  zsock_freeaddrinfo(res);
  return 0;
}

static void response_cb(struct http_response *rsp, enum http_final_call final_data, void *user_data)
{
  if (final_data == HTTP_DATA_MORE) {
    LOG_INF("Partial data received (%zd bytes)", rsp->data_len);
  } else if (final_data == HTTP_DATA_FINAL) {
    LOG_INF("All the data received (%zd bytes)", rsp->data_len);
  }

  LOG_INF("GET response status %s", rsp->http_status);
  // printk(strchr(rsp->recv_buf, '{'));
  parse_ok = forecast_parse_JSON(strchr(rsp->recv_buf, '{'));
}


int forecast_get(const char *server, const char *url){
  
  k_sem_take(&api_req_sem, K_FOREVER);

  struct sockaddr_in addr;
  int sock = -1;
  int32_t timeout = 10 * MSEC_PER_SEC;
  int ret = 0;

  ret = setup_socket(server, HTTP_PORT, &sock);
  if (sock < 0) {
    LOG_ERR("Cannot create HTTP connection.");
    return -ECONNABORTED;
  }

  struct http_request req;
  memset(&req, 0, sizeof(req));

  req.method = HTTP_GET;
  req.url = url;
  req.host = server;
  req.protocol = "HTTP/1.1";
  req.response = response_cb;
  req.recv_buf = recv_buf;
  req.recv_buf_len = sizeof(recv_buf);

  ret = http_client_req(sock, &req, timeout, NULL);

  zsock_close(sock);

  return ret;
}


static bool forecast_parse_JSON(char *json_data){

  int ret = json_obj_parse(json_data, strlen(json_data), weather_data_descr, ARRAY_SIZE(weather_data_descr), &wd);

  k_sem_give(&api_req_sem);

  if (ret < 0) {
    printk("Error parsing JSON: %d\n", ret);
    return false;
  } else {
    // printk("Maximas: %f   %f\n", wd.daily.temperature_2m_max[0], wd.daily.temperature_2m_max[1]);
    // printk("codes: %d %d\n", wd.daily.weather_code[0], wd.daily.weather_code[1]);
    // printk("timezone: %s (%s)\n", wd.timezone, wd.timezone_abbreviation);
    return true;
  }
}

struct weather_data *forecast_get_parsed_data(){
  if(parse_ok && k_sem_count_get(&api_req_sem)){
    return &wd;
  }else{
    return NULL;
  }
}


/********************************************************************************/

struct my_json_data {
  float my_float_number;
};

static const struct json_obj_descr my_json_descr[] = {
  JSON_OBJ_DESCR_PRIM(struct my_json_data, my_float_number, JSON_TOK_FLOAT),
};

void test_float(void)
{
  char *json_str = "{\"my_float_number\": 3.14}sjlf";
  struct my_json_data data;

  int ret = json_obj_parse(json_str, strlen(json_str), my_json_descr, ARRAY_SIZE(my_json_descr), &data);
  if (ret < 0) {
    printk("Failed to parse JSON: %d\n", ret);
  } else {
    printk("Parsed float number: %f\n", data.my_float_number);
  }
}

void forecast_update_data(bool conn, time_t t_now, const char *server, const char *url){
  static time_t last_update = 0;
  static int64_t delay = 0;
  static bool first_time = true;

  if (!conn){
    return;
  }

  if(!parse_ok && k_uptime_get() > delay){
    LOG_INF("Actualizando forecast");
    forecast_get(server, url);
    delay = k_uptime_get() + (1000*15);
    return;
  }

  t_now += wd.utc_offset_seconds;

  if(t_now - last_update >= API_UPDATE_INTERVAL){

    last_update = t_now - (t_now % API_UPDATE_INTERVAL);

    if(first_time){
      LOG_INF("First time, se actualizara a las %lld", last_update + API_UPDATE_INTERVAL);
      first_time = false;
      return;
    }

    LOG_INF("Actualizando forecast");
    forecast_get(server, url);

  }
}