/// AppLog Cross-Platform SDK By Rust.
/// Help doc: https://bytedance.feishu.cn/wiki/BhsUwADEcilH8hkrZT4c3q0lndf

#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
namespace applog {
#endif // __cplusplus

/**
 * c header，will create applogrs.hpp
 *
 * C端定义的客户端响应体
 */
typedef struct HttpClientResponse {
  uint64_t code;
  const char *data;
} HttpClientResponse;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * # Safety
 * Set custom domain, example: "log.xx.com", default is log.snssdk.com
 */
void AppLog_setCustomDomain(const char *host);

/**
 * # Safety
 * Set custom domains for custom host and abtest host
 */
void AppLog_setCustomAndAbTestDomain(const char *custom_host, const char *abtest_host);

/**
 * # Safety
 * Set if auto start to run workers
 */
void AppLog_setAutoStart(unsigned int enabled);

/**
 * # Safety
 * Initialize inner applog sdk with app_id and channel
 */
void AppLog_init(const char *appid, const char *channel);

/**
 * # Safety
 * Initialize rangers applog sdk with app_id and channel
 */
void AppLog_init_rangers(const char *appid, const char *channel);

/**
 * # Safety
 * start applog by manual
 */
void AppLog_start(void);

/**
 * # Safety
 * Set top common params to header, same level with aid
 */
void AppLog_setHeader(const char *key, const char *value);

/**
 * # Safety
 * Set did and disable auto register
 */
void AppLog_setDeviceId(unsigned long long did);

/**
 * # Safety
 * Query current bd did
 */
const char *AppLog_getBdDid(void);

/**
 * # Safety
 * Query current ssid
 */
const char *AppLog_getSsid(void);

/**
 * # Safety
 * Set user_unique_id
 */
void AppLog_setUserUniqueId(const char *uuid);

/**
 * # Safety
 * Set user_unique_id and user_type
 */
void AppLog_setUserUniqueIdAndType(const char *uuid, const char *user_type);

/**
 * # Safety
 * Set if auto register when change user_unique_id
 */
void AppLog_setAutoRegisterWhenUuidChanged(unsigned int enabled);

/**
 * # Safety
 * Set user_id
 */
void AppLog_setUserId(unsigned long long uuid);

/**
 * # Safety
 * Set user_type
 */
void AppLog_setUserType(unsigned char t);

/**
 * # Safety
 * Disable auto request device register to get did
 */
void AppLog_setAutoRegisterEnabled(unsigned int enabled);

/**
 * # Safety
 * Disable auto request active check
 */
void AppLog_setAutoActiveEnabled(unsigned int enabled);

/**
 * # Safety
 * Set if sdk can print log
 */
void AppLog_setLogEnabled(unsigned int enabled);

/**
 * # Safety
 * Set log printer
 */
void AppLog_setLogger(void (*observer)(const char*));

/**
 * # Safety
 * Set data storage directory on disk
 */
void AppLog_setDbDir(const char *dir);

/**
 * # Safety
 * http proxy, example: https://127.0.0.2:8888
 */
void AppLog_setHttpProxy(const char *url);

/**
 * # Safety
 * enable et verify report
 */
void AppLog_setEventVerifyEnabled(unsigned int enabled);

/**
 * # Safety
 * launch
 */
void AppLog_launch(void);

/**
 * # Safety
 * terminate
 */
void AppLog_terminate(void);

/**
 * # Safety
 * Add a device_id listener
 */
void AppLog_registerDidObserver(void (*observer)(uint64_t));

/**
 * # Safety
 * Add a install_id listener
 */
void AppLog_registerIidObserver(void (*observer)(uint64_t));

/**
 * # Safety
 * Add a bd_did listener
 */
void AppLog_registerBdDidObserver(void (*observer)(char*));

/**
 * # Safety
 * Add a ssid listener
 */
void AppLog_registerSsidObserver(void (*observer)(char*));

/**
 * # Safety
 * Set applog http client
 */
void AppLog_setHttpClient(const struct HttpClientResponse *(*post)(const char*,
                                                                   const uint8_t*,
                                                                   uint64_t,
                                                                   const char*));

/**
 * # Safety
 * set encrypt is enable
 */
void AppLog_setEncryptEnabled(unsigned int enabled);

/**
 * # Safety
 * set compress is enable
 */
void AppLog_setCompressEnabled(unsigned int enabled);

/**
 * # Safety
 * set uid enable is enable（to fix event user_id）
 */
void AppLog_setEventUidEnabled(unsigned int enabled);

/**
 * # Safety
 * set pack by size, default max size is 100kb
 */
void AppLog_setMaxPackSize(unsigned long long size);

/**
 * # Safety
 * set track event is enabled
 */
void AppLog_setTrackEventEnabled(unsigned int enabled);

/**
 * # Safety
 * set events upload enabled
 */
void AppLog_setReportEventEnabled(unsigned int enabled);

/**
 * # Safety
 * set if enable inner monitor, default open
 */
void AppLog_setMonitorEnabled(unsigned int enabled);

/**
 * # Safety
 * Query time sync，will copy to input array[server_time,local_time] and out len
 */
void AppLog_getTimeSync(uint64_t *out_ptr, size_t *out_len);

/**
 * # Safety
 * set if enable abtest, default false
 */
void AppLog_setAbTestEnabled(unsigned int enabled);

/**
 * # Safety
 * Query abtest config value or defaultValue
 */
const char *AppLog_getAbTestConfig(const char *key, const char *default_value);

/**
 * # Safety
 * Query all abtest config
 */
const char *AppLog_getAllAbTestConfigs(void);

/**
 * # Safety
 * set http request header with key and value
 */
void AppLog_setHttpHeader(const char *key, const char *value);

/**
 * # Safety
 * Collect a event
 */
void AppLog_onEvent(const char *event, const char *params);

/**
 * # Safety
 * Collect a impression
 */
void AppLog_onImpression(const char *data);

/**
 * # Safety
 * Add new custom common params
 */
void AppLog_addCustomHeader(const char *key, const char *value);

/**
 * # Safety
 * Remove custom common params
 */
void AppLog_removeCustomHeader(const char *key);

/**
 * # Safety
 * Query current did
 */
uint64_t AppLog_getDeviceId(void);

/**
 * # Safety
 * Query current session id
 */
const char *AppLog_getSessionId(void);

/**
 * # Safety
 * flush events to report, only once flush work in 10s period
 */
void AppLog_flush(void);

/**
 * # Safety
 * destroy sdk inner thread and release mem
 */
void AppLog_destroy(void (*callback)(void));

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#ifdef __cplusplus
} // namespace applog
#endif // __cplusplus
