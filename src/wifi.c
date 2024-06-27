#include "wifi.h"
#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_event.h>
#include <zephyr/logging/log.h>
#include <zephyr/net/sntp.h>
#include <arpa/inet.h>

#include "memory.h"

#define DNS_TIMEOUT (5 * MSEC_PER_SEC)

#define NTP_SERVER "ntp.shoa.cl"
#define SNTP_PORT 123

LOG_MODULE_REGISTER(wifi);
K_SEM_DEFINE(dns_result_sem, 0, 1);

bool got_ip = false;
static struct sockaddr_in ntp_server_addr;
static uint16_t dns_id;

// Definir una variable global para almacenar el valor de la característica
char wifi_ssid[WIFI_MAX_CHAR_CREDS];
bool wifi_ssid_set = false;

char wifi_pass[WIFI_MAX_CHAR_CREDS];
bool wifi_pass_set = false;


static struct net_mgmt_event_callback wifi_cb;
static struct net_mgmt_event_callback ipv4_cb;

static void wifi_dns_resolve();

static void handle_wifi_connect_result(struct net_mgmt_event_callback *cb)
{
  const struct wifi_status *status = (const struct wifi_status *)cb->info;

  if (status->status)
  {
    printk("Connection request failed (%d)\n", status->status);
  }
  else
  {
    printk("Connected\n");
  }
}

static void handle_wifi_disconnect_result(struct net_mgmt_event_callback *cb)
{
  const struct wifi_status *status = (const struct wifi_status *)cb->info;

  if (status->status)
  {
    printk("Disconnection request (%d)\n", status->status);
  }
  else
  {
    printk("Disconnected\n");
  }
}

static void handle_ipv4_result(struct net_if *iface)
{
  int i = 0;

  for (i = 0; i < NET_IF_MAX_IPV4_ADDR; i++) {

    char buf[NET_IPV4_ADDR_LEN];

    if (iface->config.ip.ipv4->unicast[i].addr_type != NET_ADDR_DHCP) {
      continue;
    }

    printk("IPv4 address: %s\n",
            net_addr_ntop(AF_INET,
                            &iface->config.ip.ipv4->unicast[i].address.in_addr,
                            buf, sizeof(buf)));
    printk("Subnet: %s\n",
            net_addr_ntop(AF_INET,
                            &iface->config.ip.ipv4->netmask,
                            buf, sizeof(buf)));
    printk("Router: %s\n",
            net_addr_ntop(AF_INET,
                            &iface->config.ip.ipv4->gw,
                            buf, sizeof(buf)));
  }

  got_ip = true;

}

static void wifi_mgmt_event_handler(struct net_mgmt_event_callback *cb, uint32_t mgmt_event, struct net_if *iface)
{
  switch (mgmt_event)
  {

    case NET_EVENT_WIFI_CONNECT_RESULT:
        handle_wifi_connect_result(cb);
        break;

    case NET_EVENT_WIFI_DISCONNECT_RESULT:
        handle_wifi_disconnect_result(cb);
        break;

    case NET_EVENT_IPV4_ADDR_ADD:
        handle_ipv4_result(iface);
        break;

    default:
        break;
  }
}

bool wifi_connect(uint8_t* ssid, ssize_t len_ssid, uint8_t* pass, ssize_t len_pass)
{
  struct net_if *iface = net_if_get_default();

  struct wifi_connect_req_params wifi_params = {0};

  wifi_params.ssid = ssid;
  wifi_params.psk = pass;
  wifi_params.ssid_length = len_ssid;
  wifi_params.psk_length = len_pass;
  wifi_params.channel = WIFI_CHANNEL_ANY;
  wifi_params.security = WIFI_SECURITY_TYPE_PSK;
  wifi_params.band = WIFI_FREQ_BAND_2_4_GHZ; 
  wifi_params.mfp = WIFI_MFP_OPTIONAL;

  printk("Connecting to SSID: %s\n", wifi_params.ssid);

  if (net_mgmt(NET_REQUEST_WIFI_CONNECT, iface, &wifi_params, sizeof(struct wifi_connect_req_params)))
  {
    printk("WiFi Connection Request Failed\n");
    return false;
  }
  return true;
}

void wifi_status(void)
{
  struct net_if *iface = net_if_get_default();
  
  struct wifi_iface_status status = {0};

  if (net_mgmt(NET_REQUEST_WIFI_IFACE_STATUS, iface, &status,  sizeof(struct wifi_iface_status)))
  {
    printk("WiFi Status Request Failed\n");
  }

  printk("\n");

  if (status.state >= WIFI_STATE_ASSOCIATED) {
    printk("SSID: %-32s\n", status.ssid);
    printk("Band: %s\n", wifi_band_txt(status.band));
    printk("Channel: %d\n", status.channel);
    printk("Security: %s\n", wifi_security_txt(status.security));
    printk("RSSI: %d\n", status.rssi);
  }
}

void wifi_disconnect(void)
{
  struct net_if *iface = net_if_get_default();

  if (net_mgmt(NET_REQUEST_WIFI_DISCONNECT, iface, NULL, 0))
  {
    printk("WiFi Disconnection Request Failed\n");
  }
}

void wifi_init(){
  memset(wifi_ssid, 0, WIFI_MAX_CHAR_CREDS);
  memset(wifi_pass, 0, WIFI_MAX_CHAR_CREDS);

  net_mgmt_init_event_callback(&wifi_cb, wifi_mgmt_event_handler,
                                NET_EVENT_WIFI_CONNECT_RESULT | NET_EVENT_WIFI_DISCONNECT_RESULT);

  net_mgmt_init_event_callback(&ipv4_cb, wifi_mgmt_event_handler, NET_EVENT_IPV4_ADDR_ADD);

  net_mgmt_add_event_callback(&wifi_cb);
  net_mgmt_add_event_callback(&ipv4_cb);

  char* temp_ssid;
  char* temp_pass;

  temp_ssid = memory_check_wifi_ssid();
  if(temp_ssid != NULL){
    memcpy(wifi_ssid, temp_ssid, strlen(temp_ssid));
    LOG_INF("copiando %s len: %d", temp_ssid, strlen(temp_ssid));
    wifi_ssid_set = true;
  }

  temp_pass = memory_check_wifi_pass();
  if(temp_pass != NULL){
    memcpy(wifi_pass, temp_pass, strlen(temp_pass));
    LOG_INF("copiando %s len: %d", temp_pass, strlen(temp_pass));
    wifi_pass_set = true;
  }
}


int wifi_get_ntp(void)
{
  struct sntp_ctx ctx;
  struct sntp_time sntp_time;
  int rv;

  wifi_dns_resolve();

  ntp_server_addr.sin_family = AF_INET;
  ntp_server_addr.sin_port = htons(SNTP_PORT);

  rv = sntp_init(&ctx, (struct sockaddr *)&ntp_server_addr, sizeof(struct sockaddr_in));
  if (rv < 0) {
    LOG_ERR("Failed to init SNTP IPv4 ctx: %d", rv);
    return rv;
  }

  LOG_INF("Sending SNTP IPv4 request...");
  rv = sntp_query(&ctx, 4 * MSEC_PER_SEC, &sntp_time);
  if (rv < 0) {
    LOG_ERR("SNTP IPv4 request failed: %d", rv);
    sntp_close(&ctx);
    return rv;
  }

  LOG_INF("Status: %d", rv);
  LOG_INF("Time since Epoch: high word: %u, low word: %u",
      (uint32_t)(sntp_time.seconds >> 32), (uint32_t)sntp_time.seconds);

  sntp_close(&ctx);
  return 0;
}


void dns_result_cb(enum dns_resolve_status status, struct dns_addrinfo *info, void *user_data) {
  char hr_addr[NET_IPV4_ADDR_LEN];
  void *addr;

  if (status == DNS_EAI_INPROGRESS && info) {
    if (info->ai_family == AF_INET) {
      addr = &net_sin(&info->ai_addr)->sin_addr;
      memcpy(&ntp_server_addr.sin_addr, addr, sizeof(struct in_addr));

      net_addr_ntop(info->ai_family, addr, hr_addr, sizeof(hr_addr));
      LOG_INF("Resolved IP address: %s", hr_addr);

      /* We take the first address and cancel the query */
      dns_cancel_addr_info(dns_id);
      k_sem_give(&dns_result_sem); // Signal that DNS resolution is complete
    }
  } else if (status != DNS_EAI_CANCELED) {
    LOG_ERR("DNS resolving failed (%d)", status);
  }
}


void wifi_dns_resolve(){

  static const char *query = NTP_SERVER;
  int ret;

  ret = dns_get_addr_info(query,
        DNS_QUERY_TYPE_A,
        &dns_id,
        dns_result_cb,
        (void *)query,
        DNS_TIMEOUT);
  if (ret < 0) {
    LOG_ERR("Cannot resolve IPv4 address (%d)", ret);
    return;
  }

  k_sem_take(&dns_result_sem, K_FOREVER); // Wait for DNS resolution to complete
}

bool wifi_is_connected(){
  return got_ip;
}