#include "forecast.h"
#include <zephyr/kernel.h>
#include <zephyr/net/socket.h>
#include <zephyr/data/json.h>
#include <zephyr/logging/log.h>

#include <zephyr/net/net_ip.h>
#include <zephyr/net/tls_credentials.h>
#include <zephyr/net/http/client.h>


LOG_MODULE_REGISTER(forecast);

#define MAX_RECV_BUF_LEN 512
#define HTTP_PORT "80"

static uint8_t recv_buf[MAX_RECV_BUF_LEN];

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

  LOG_INF("Response to %s", (const char *)user_data);
  LOG_INF("Response status %s", rsp->http_status);
  printk("Response: %.*s\n", rsp->data_len, (char *)rsp->recv_buf);
}


int forecast_get(const char *url, const char *server)
{
  struct sockaddr_in addr;
  int sock = -1;
  int32_t timeout = 3 * MSEC_PER_SEC;
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

  ret = http_client_req(sock, &req, timeout, "IPv4 GET");

  zsock_close(sock);

  return ret;
}

/*

curl 'https://api.open-meteo.com/v1/forecast?latitude=-33.4569&longitude=-70.6483&daily=temperature_2m_max,temperature_2m_min,weather_code&timezone=auto&forecast_days=2&hourly=temperature_2m'
curl 'https://api.open-meteo.com/v1/forecast?latitude=-33.4569&longitude=-70.6483&daily=temperature_2m_max,temperature_2m_min,weather_code&timezone=auto&forecast_days=2'


{
  "latitude": -33.5,
  "longitude": -70.625,
  "generationtime_ms": 0.04303455352783203,
  "utc_offset_seconds": -14400,
  "timezone": "America/Santiago",
  "timezone_abbreviation": "-04",
  "elevation": 549.0,
  "hourly_units": {
    "time": "iso8601",
    "temperature_2m": "°C"
  },
  "hourly": {
    "time": [
      "2024-06-27T00:00",
      "2024-06-27T01:00",
      "2024-06-27T02:00",
      "2024-06-27T03:00",
      "2024-06-27T04:00",
      "2024-06-27T05:00",
      "2024-06-27T06:00",
      "2024-06-27T07:00",
      "2024-06-27T08:00",
      "2024-06-27T09:00",
      "2024-06-27T10:00",
      "2024-06-27T11:00",
      "2024-06-27T12:00",
      "2024-06-27T13:00",
      "2024-06-27T14:00",
      "2024-06-27T15:00",
      "2024-06-27T16:00",
      "2024-06-27T17:00",
      "2024-06-27T18:00",
      "2024-06-27T19:00",
      "2024-06-27T20:00",
      "2024-06-27T21:00",
      "2024-06-27T22:00",
      "2024-06-27T23:00",
      "2024-06-28T00:00",
      "2024-06-28T01:00",
      "2024-06-28T02:00",
      "2024-06-28T03:00",
      "2024-06-28T04:00",
      "2024-06-28T05:00",
      "2024-06-28T06:00",
      "2024-06-28T07:00",
      "2024-06-28T08:00",
      "2024-06-28T09:00",
      "2024-06-28T10:00",
      "2024-06-28T11:00",
      "2024-06-28T12:00",
      "2024-06-28T13:00",
      "2024-06-28T14:00",
      "2024-06-28T15:00",
      "2024-06-28T16:00",
      "2024-06-28T17:00",
      "2024-06-28T18:00",
      "2024-06-28T19:00",
      "2024-06-28T20:00",
      "2024-06-28T21:00",
      "2024-06-28T22:00",
      "2024-06-28T23:00"
    ],
    "temperature_2m": [
      8.0,
      8.2,
      7.3,
      6.8,
      6.9,
      7.4,
      8.0,
      7.4,
      7.1,
      8.1,
      10.5,
      12.7,
      13.9,
      14.5,
      16.3,
      16.7,
      15.6,
      14.2,
      12.7,
      11.4,
      10.7,
      10.2,
      9.9,
      8.8,
      7.8,
      8.1,
      7.5,
      7.7,
      7.7,
      6.8,
      6.5,
      6.4,
      6.7,
      7.5,
      9.3,
      10.7,
      12.2,
      14.2,
      15.5,
      15.9,
      15.9,
      15.2,
      13.8,
      12.4,
      11.6,
      10.8,
      9.1,
      8.0
    ]
  },
  "daily_units": {
    "time": "iso8601",
    "temperature_2m_max": "°C",
    "temperature_2m_min": "°C",
    "weather_code": "wmo code"
  },
  "daily": {
    "time": [
      "2024-06-27",
      "2024-06-28"
    ],
    "temperature_2m_max": [
      16.7,
      15.9
    ],
    "temperature_2m_min": [
      6.8,
      6.4
    ],
    "weather_code": [
      3,
      3
    ]
  }
}

*/