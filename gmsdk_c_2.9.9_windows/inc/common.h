/**
* @file    common.h
* @brief   gmsdk 公共方法和定义
* @version v2.2.0
*
*/

#ifndef GMSDK_COMMON_H
#define GMSDK_COMMON_H

#ifdef WIN32
    #ifdef GMSDK_EXPORTS  
        #define GM_API extern "C" __declspec(dllexport)
    #else
        #define GM_API extern "C" __declspec(dllimport)
    #endif
#else
    #define GM_API extern "C"
#endif


//字符字段长度定义
const unsigned int LEN_ID       = 40;
const unsigned int LEN_SYMBOL   = 32;
const unsigned int LEN_USERNAME = 32;
const unsigned int LEN_PASSWORD = 32;
const unsigned int LEN_INFO     = 64;
const unsigned int LEN_SECID    = 24;
const unsigned int LEN_EXCHANGE = 8;
const unsigned int LEN_ISO_DATATIME = 36;
const unsigned int LEN_SEC_NAME = 64;
const unsigned int LEN_PUB_DATE = 16;
const unsigned int LEN_TRADE_DATE = 16;

/**
* 获取GMSDK版本号
* @return GMSDK版本号
*/
GM_API const char* gm_version();


/**
* 根据错误编码，获取错误文本信息
* @param errorno 错误编码
* @return 错误信息
*/
GM_API const char* gm_strerror(int errorno);

/**
* 初始化GMSDK并登陆
* @param addr       掘金认证服务器地址, 比如 cloud.myquant.cn
* @param username   掘金账号
* @param password   掘金密码
* @return 初始化值
*/
GM_API int gm_login(const char *username, const char *password, const char *addr = NULL);

/**
* 阻塞运行GMSDK，监听实时行情和交易消息，并触发回调。
* @return 退出值
*/
GM_API int gm_run();

/**
* poll 底层消息循环，供上层语言绑定使用。
* @return 退出值
*/
GM_API void gm_poll();

/**
* 登出并停止运行GMSDK，退出监听实时行情和交易消息。调用本函数后，gm_run函数将退出监听。
*/
GM_API void gm_logout();

/**
* bg2312/gbk ->utf8
*/
GM_API char* gm_gbk2utf8(const char* gbk);

/**
* utf8->bg2312/gbk
*/
GM_API char* gm_utf2gbk(const char* utf8);


/**
* 定时回调方法
*
*/
typedef void(*TimerCallback)(int interval);

/**
* 设置定时器时间间隔
* @param interval          定时器触发时间间隔,单位:毫秒
*
*/

GM_API void gm_set_timer(int interval);

/**
* 根据时间间隔取消定时器
* @param interval          定时器时间间隔,单位:毫秒
*
*/

GM_API void gm_unset_timer(int interval);

/**
* 设置定时器回调方法
* @param cb          定时器回调方法
*
*/
GM_API void gm_set_timer_callback(TimerCallback cb);

/**
* 设置同步API的超时时间，系统默认为30秒
* @param seconds         超时时间，单位为秒
*
*/
GM_API void gm_set_timeout_val(int seconds);

/**
* 获取同步API的超时时间
* @return                超时时间，单位为秒
*
*/
GM_API int gm_get_timeout_val();


GM_API void gm_set_language(const char* language);

#endif
