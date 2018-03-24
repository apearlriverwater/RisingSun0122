/**
* @file    strategy.h
* @brief   gmsdk 策略模板
* @version v2.2.0
*
*/

#ifndef GMSDK_STRATEGY_H
#define GMSDK_STRATEGY_H


#include "mdapi.h"
#include "tdapi.h"


/**
* 初始化策略，从参数读取设置
* @param username              掘金账号
* @param password              掘金密码
* @param strategy_id           策略ID
* @param subscribe_symbol_list 行情订阅的代码列表
* @param mode                  行情模式：mode=MD_MODE_LIVE/MD_MODE_SIMULATED/MD_MODE_PLAYBACK
* @return 0：成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int strategy_init(
    const char   *username,
    const char   *password,
    const char   *strategy_id,
    const char   *subscribe_symbol_list,
    int           mode = MD_MODE_LIVE,
    const char   *td_addr = NULL
    );


/**
* 初始化策略，从参数读取设置，内部接口
* @param username              掘金账号
* @param password              掘金密码
* @param strategy_id           策略ID
* @param subscribe_symbol_list 行情订阅的代码列表
* @param mode                  订阅哪一类行情：mode=MD_MODE_LIVE/MD_MODE_SIMULATED/MD_MODE_PLAYBACK
* @param td_addr               可选，交易服务地址, 比如 cloud.myquant.cn:8001
* @param md_rest_addr          可选，数据提取服务地址 如cloud.myquant.cn:8000
* @param md_live_addr          可选, 实时行情或模拟行情服务地址, 如cloud.myquant.cn:8000
* @param gm_addr               掘金认证服务器地址, 比如 cloud.myquant.cn
* @return 0：成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int strategy_init_ex(
    const char   *username,
    const char   *password,
    const char   *strategy_id,
    const char   *subscribe_symbol_list,
    int           mode=MD_MODE_LIVE, 
    const char   *td_addr=NULL,
    const char   *md_rest_addr = NULL,
    const char   *md_live_addr=NULL,
    const char   *gm_addr = NULL
);

/**
* 策略回测参数设置
* @param start_time                      回放行情开始时间，格式：yyyy-mm-dd HH:MM:SS
* @param end_time                        回放行情结束时间，格式：yyyy-mm-dd HH:MM:SS
* @param initial_cash                    回测初始资金，默认1000000
* @param transaction_ratio               委托量成交比率,默认1，按委托量全部成交
* @param commission_ratio                手续费率,默认0，无手续费
* @param slippage_ratio                  滑点比率,默认0，无滑点
* @param price_type                      行情复权方式，0=不复权,1=前复权
* @return 0：成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/

GM_API int strategy_backtest_config(
    const char  *start_time,
    const char  *end_time,
    const double initial_cash = 1000000,
    const double transaction_ratio = 1,
    const double commission_ratio = 0,
    const double slippage_ratio = 0,
    const int    price_type = 1,
	const char  *bench_symbol = NULL,
	int          check_cache = 1
    );
    
/**
* 初始化策略，从配置文件读取策略设置
* @param config_file 策略配置文件名（全路径）
* @return 0：成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int strategy_init_with_config(const char *config_file);

#endif
