/**
* @file    mdapi.h
* @brief   gmsdk 行情函数说明
* @version v2.2.0
*
*/

#ifndef GMSDK_MDAPI_H
#define GMSDK_MDAPI_H

#include <stddef.h>
#include "common.h"
#include "mddef.h"

// GMSDK 行情数据服务接口
// =============================================================================================
///////////////////////////////////////////////////////////////////
//  掘金数据服务，包括：实时行情，仿真行情以及回放行情的订阅接口；历史行情及基本面数据的查询接口
///////////////////////////////////////////////////////////////////


typedef enum MDMode {
    MD_MODE_NULL       = 1,  // 不接收行情流
    MD_MODE_LIVE       = 2,  // 接收实时行情
    MD_MODE_SIMULATED  = 3,  // 接收模拟行情
    MD_MODE_PLAYBACK   = 4   // 接收回放行情
}MDMode;


/**
* 初始化行情数据服务: 连接并登陆数据服务
* @param mode       订阅哪一类行情：mode=MD_LIVE/MD_SIMULATED/MD_PLAYBACK
* @param start_time 回放行情的开始时间，仅用于MD_PLAYBACK模式，格式：yyyy-mm-dd HH:MM:SS
* @param end_time   回放行情的结束时间，仅用于MD_PLAYBACK模式，格式：yyyy-mm-dd HH:MM:SS
* @return 0：       成功,其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_md_init(int mode = MD_MODE_NULL, const char *subscribe_symbol_list = NULL, const char *start_time = NULL, const char *end_time = NULL);

/**
* 初始化行情数据服务: 连接并登陆数据服务
* @param mode       订阅哪一类行情：mode=MD_LIVE/MD_SIMULATED/MD_PLAYBACK
* @param start_time 回放行情的开始时间，仅用于MD_PLAYBACK模式，格式：yyyy-mm-dd HH:MM:SS
* @param end_time   回放行情的结束时间，仅用于MD_PLAYBACK模式，格式：yyyy-mm-dd HH:MM:SS
* @param rest_addr  可选参数，用户指定数据提取服务地址 如cloud.myquant.cn:8000
* @param live_addr  可选参数, 用户指定实时行情或模拟行情服务地址, 如cloud.myquant.cn:8000
* @return 0：       成功,其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_md_init_ex(int mode = MD_MODE_NULL, const char *subscribe_symbol_list = NULL, const char *start_time = NULL, const char *end_time = NULL, const char *rest_addr = NULL, const char *live_addr = NULL);

/**
* 重连到行情数据服务: 如果接收实时/模拟行情中途断开了连接，可调用此函数重连。
* @return 0：成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_md_reconnect();

/**
* 订阅行情
* @param symbol_list 订阅代码表,参考订阅规则
* @return 0:success 
*
* @note symbol_list 订阅规则和算法说明:
*
* 交易所exchange: SHSE-上交所 SZSE-深交所 CFFEX-中金所 SHFE-上期所 DCE-大商所 CZCE-郑商所
*
* 订阅串有三节或四节组成, 分别对应 交易所exchange.代码code.数据类型data_type.周期类型bar_type
* 只有订阅bar数据时, 才用到第四节, 周期类型才有作用
* 支持6种格式的订阅,使用如下:
* SZSE.000010.tick      : 深交所,000010, tick数据 
* CFFEX.IF1403.*        : 中金所,IF1403,所有数据
* CFFEX.IF1403.tick     : 中金所,IF1403, tick数据
* CFFEX.IF1403.bar.60   : 中金所,IF1403, 1分钟(60秒)bar数据
* 
* CFFEX.IF1403.*,CFFEX.IF1312.*    : 中金所,IF1403和IF1312所有数据(订阅多个代码)
*
* 退定规则同订阅的格式
*
*/
GM_API int gm_md_subscribe(const char *symbol_list);


/**
* 取消订阅
* @param symbol_list 取消订阅代码表,参考订阅规则
* @return 0:success
*
*/
GM_API int gm_md_unsubscribe(const char *symbol_list);

/**
* 重置订阅
* @param symbol_list 订阅代码表,参考订阅规则
* @return 0:success
*
*/
GM_API int gm_md_resubscribe(const char *symbol_list);

/**
* Login回调方法
*
*/
typedef void (*MDLoginCallback)();

/**
* Event行情回调方法
* @param event          事件对象
*
*/
typedef void (*MDEventCallback)(MDEvent *event);

/**
* Tick行情回调方法
* @param tick          逐笔行情
*
*/
typedef void (*MDTickCallback)(Tick *tick);

/**
* Bar行情回调方法
* @param bar          分时行情
*
*/
typedef void (*MDBarCallback)(Bar *bar);

/**
* 行情Error回调方法
* @param error_code    错误编号
* @param error_msg     错误描述
*
*/
typedef void (*MDErrorCallback)(int error_code, const char *error_msg);

/**
* 设置登录回调方法
* @param cb          登录回调方法
*
*/
GM_API void gm_md_set_login_callback(MDLoginCallback cb);

/**
* 设置行情Event回调方法
* @param cb          行情Event回调方法
*
*/
GM_API void gm_md_set_event_callback(MDEventCallback cb);

/**
* 设置Tick行情回调方法
* @param cb          Tick行情回调方法
*
*/
GM_API void gm_md_set_tick_callback(MDTickCallback cb);

/**
* 设置Bar行情回调方法
* @param cb          Bar行情回调方法
*
*/
GM_API void gm_md_set_bar_callback(MDBarCallback cb);


/**
* 设置行情error回调方法
* @param cb          Error回调方法
*
*/
GM_API void gm_md_set_error_callback(MDErrorCallback cb);



///////////////////////////////////////////////////////////////////
//  数据提取接口
///////////////////////////////////////////////////////////////////

/**
* 按时间周期提取Tick,按时间升序排列
* @param symbol_list   多个品种代码列表, 如CFFEX.IF1308
* @param t_begin       开始时间, 如2013-8-14 00:00:00
* @param t_end         结束时间, 如2013-8-15 00:00:00
* @param tick          返回的数据缓冲区, 内容Tick 格式的结构数组
* @param count         返回结构的数量,即多少个Tick 
* @return              0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_ticks(const char *symbol_list, const char *t_begin, const char *t_end, Tick **tick, int *count);


/**
* 提取快照, 即最新的Tick，支持一次性提取多个代码的快照
* @param symbol_list 多个品种代码列表, 如CFFEX.IF1308,CFFEX.1401,SHFE.AG1311
* @param tick        返回的数据缓冲区, 内容Tick 格式的结构数组
* @param count       返回结构的数量,即多少个Tick 
* @return            0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_last_ticks(const char *symbol_list, Tick **tick, int *count);


/**
* 提取最近n条Tick
* @param symbol   代码, 如CFFEX.IF1308
* @param n        数据个数
* @param tick     返回的数据缓冲区, 内容Tick 格式的结构数组
* @param count    返回结构的数量,即多少个Tick 
* @return         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_last_n_ticks(const char *symbol, int n, Tick **tick, int *count);

/**
* 提取指定时间最近n条Tick
* @param symbol   代码, 如CFFEX.IF1308
* @param n        数据个数
* @param end_time 指定截止时间
* @param tick     返回的数据缓冲区, 内容Tick 格式的结构数组
* @param count    返回结构的数量,即多少个Tick
* @return         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_n_ticks_by_time(const char *symbol, int n, const char *end_time, Tick **tick, int *count);


/**
* 按时间周期提取bar
* @param symbol_list 多个品种代码列表, 如CFFEX.IF1308
* @param bar_type    bar周期类型,以秒计算, 1分钟bar用60 
* @param t_begin     开始时间, 如2013-8-14 00:00:00
* @param t_end       结束时间, 如2013-8-15 00:00:00
* @param bar         返回的数据缓冲区, 内容Bar 格式的结构数组
* @param count       返回结构的数量,即多少个Bar
* @return            0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_bars(const char *symbol_list, int bar_type, const char *t_begin, const char *t_end, Bar **bar, int *count);


/**
* 提取最新的Bar, 支持多个代码同时提取
* @param symbol_list 多个品种代码列表, 如CFFEX.IF1308,CFFEX.1401,SHFE.AG1311
* @param bar_type    bar周期类型,以秒计算, 1分钟bar用60 
* @param bar         返回的数据缓冲区, 内容Bar 格式的结构数组
* @param count       返回结构的数量,即多少个Bar 
* @return            0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)  
*
*/
GM_API int gm_md_get_last_bars(const char *symbol_list, int bar_type, Bar **bar, int *count);


/**
* 提取最近n条Bar
* @param symbol     代码, 如CFFEX.IF1308
* @param bar_type   bar周期类型,以秒计算, 1分钟bar用60 
* @param n          数据个数
* @param bar        返回的数据缓冲区, 内容Bar 格式的结构数组
* @param count      返回结构的数量,即多少个Bar 
* @return           0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)  
*
*/
GM_API int gm_md_get_last_n_bars(const char *symbol, int bar_type, int n, Bar **bar, int *count);

/**
* 提取指定时间最近n条Bar
* @param symbol     代码, 如CFFEX.IF1308
* @param bar_type   bar周期类型,以秒计算, 1分钟bar用60
* @param n          数据个数
* @param end_time   指定截止时间
* @param bar        返回的数据缓冲区, 内容Bar 格式的结构数组
* @param count      返回结构的数量,即多少个Bar
* @return           0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_n_bars_by_time(const char *symbol, int bar_type, int n, const char *end_time, Bar **bar, int *count);


/**
* 按时间周期提取DailyBar
* @param symbol_list 多个品种代码列表, 如CFFEX.IF1308
* @param t_begin     开始时间, 如2013-8-14 00:00:00
* @param t_end       结束时间, 如2013-8-15 00:00:00
* @param dbar        返回的数据缓冲区, 内容DailyBar 格式的结构数组
* @param count       返回结构的数量,即多少个DailyBar
* @return            0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_dailybars(const char *symbol_list, const char *t_begin, const char *t_end, DailyBar **dbar, int *count);


/**
* 提取最新的DailyBar，支持同时提取多个代码
* @param symbol_list 多个品种代码列表, 如CFFEX.IF1308,CFFEX.1401,SHFE.AG1311
* @param dbar        返回的数据缓冲区, 内容DailyBar 格式的结构数组
* @param count       返回结构的数量,即多少个DailyBar 
* @return            0: success , 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_last_dailybars(const char *symbol_list, DailyBar **dbar, int *count);


/**
* 提取最新n条DailyBar
* @param symbol  品种代码, 如CFFEX.IF1308
* @param n       数据个数
* @param dbar    返回的数据缓冲区, 内容DailyBar 格式的结构数组
* @param count   返回结构的数量,即多少个DailyBar 
* @return        0: success , 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*
*/
GM_API int gm_md_get_last_n_dailybars(const char *symbol, int n, DailyBar **dbar, int *count);

/**
* 提取指定时间最新n条DailyBar
* @param symbol     品种代码, 如CFFEX.IF1308
* @param n          数据个数
* @param end_time   指定截止时间
* @param dbar       返回的数据缓冲区, 内容DailyBar 格式的结构数组
* @param count      返回结构的数量,即多少个DailyBar
* @return           0: success , 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_n_dailybars_by_time(const char *symbol, int n, const char *end_time, DailyBar **dbar, int *count);

/**
* 提取交易代码
* @param exchange                 交易所名字，比如：SHSE,SZSE,CFFEX,DCE,SHFE,CZCE
* @param sec_type                 证券类型，比如：1,2,3,4,5==股票，基金，指数，期货，期权
* @param is_active                当前是否可以交易，1=可交易，0=全部
* @param instrument               返回的数据缓冲区, 内容Instrument格式的结构数组
* @param count                    返回结构的数量,即多少个Instrument
* @return                         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_md_get_instruments(const char *exchange, int sec_type, int is_active, Instrument ** instrument, int *count);

/**
* 根据交易代码名字进行模糊查找，适用场景，比如根据期货品种查询所有合约
* @param name                     交易代码名关键字，比如：300，IF, CF
* @param instrument               返回的数据缓冲区, 内容Instrument格式的结构数组
* @param count                    返回结构的数量,即多少个Instrument
* @return                         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_md_get_instruments_by_name(const char *name, Instrument ** instrument, int *count);

/**
* 提取指数的成分股代码
* @param index_symbol             指数代码, 如SHSE.000300
* @param constituent              返回的数据缓冲区, 内容Constituent格式的结构数组
* @param count                    返回结构的数量,即多少个Constituent
* @return                         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_md_get_constituents(const char *index_symbol, Constituent ** constituent, int *count);


/**
* 按时间周期提取FinancialIndex,按时间升序排列
* @param symbol_list              多个品种代码列表, 如SHSE.600000,SZSE.000001
* @param t_begin                  开始时间, 如2013-8-14 00:00:00
* @param t_end                    结束时间, 如2013-8-15 00:00:00
* @param financial_index          返回的数据缓冲区, 内容FinancialIndex 格式的结构数组
* @param count                    返回结构的数量,即多少个FinancialIndex
* @return                         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_financial_index(const char *symbol_list, const char *t_begin, const char *t_end, FinancialIndex **financial_index, int *count);


/**
* 提取快照, 即最新的FinancialIndex，支持一次性提取多个代码的快照
* @param symbol_list            多个品种代码列表, 如SHSE.600000,SZSE.000001
* @param financial_index        返回的数据缓冲区, 内容FinancialIndex 格式的结构数组
* @param count                  返回结构的数量,即多少个FinancialIndex
* @return                        0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/

GM_API int gm_md_get_last_financial_index(const char *symbol_list, FinancialIndex **financial_index, int *count);

/**
* 提取最近n条FinancialIndex
* @param symbol              代码, 如SHSE.600000
* @param n                   数据个数
* @param financial_index     返回的数据缓冲区, 内容FinancialIndex 格式的结构数组
* @param count               返回结构的数量,即多少个FinancialIndex
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_n_financial_index(const char *symbol, int n, FinancialIndex **financial_index, int *count);


/**
* 按时间周期提取ShareIndex,按时间升序排列
* @param symbol_list              多个品种代码列表, 如SHSE.600000,SZSE.000001
* @param t_begin                  开始时间, 如2013-8-14 00:00:00
* @param t_end                    结束时间, 如2013-8-15 00:00:00
* @param share_index              返回的数据缓冲区, 内容ShareIndex 格式的结构数组
* @param count                    返回结构的数量,即多少个ShareIndex
* @return                         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_share_index(const char *symbol_list, const char *t_begin, const char *t_end, ShareIndex **share_index, int *count);


/**
* 提取快照, 即最新的ShareIndex，支持一次性提取多个代码的快照
* @param symbol_list            多个品种代码列表, 如SHSE.600000,SZSE.000001
* @param share_index            返回的数据缓冲区, 内容ShareIndex 格式的结构数组
* @param count                  返回结构的数量,即多少个ShareIndex
* @return                        0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_share_index(const char *symbol_list, ShareIndex **share_index, int *count);


/**
* 提取最近n条ShareIndex
* @param symbol              代码, 如SHSE.600000
* @param n                   数据个数
* @param share_index         返回的数据缓冲区, 内容ShareIndex 格式的结构数组
* @param count               返回结构的数量,即多少个ShareIndex
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_n_share_index(const char *symbol, int n, ShareIndex **share_index, int *count);


/**
* 按时间周期提取MarketIndex,按时间升序排列
* @param symbol_list            多个品种代码列表, 如SHSE.600000,SZSE.000001
* @param t_begin                  开始时间, 如2013-8-14 00:00:00
* @param t_end                    结束时间, 如2013-8-15 00:00:00
* @param market_index             返回的数据缓冲区, 内容MarketIndex 格式的结构数组
* @param count                    返回结构的数量,即多少个MarketIndex
* @return                         0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_market_index(const char *symbol_list, const char *t_begin, const char *t_end, MarketIndex **market_index, int *count);


/**
* 提取快照, 即最新的MarketIndex，支持一次性提取多个代码的快照
* @param symbol_list            多个品种代码列表, 如SHSE.600000,SZSE.000001
* @param market_index           返回的数据缓冲区, 内容MarketIndex 格式的结构数组
* @param count                  返回结构的数量,即多少个MarketIndex
* @return                       0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_market_index(const char *symbol_list, MarketIndex **market_index, int *count);


/**
* 提取最近n条MarketIndex
* @param symbol              代码, 如SHSE.600000
* @param n                   数据个数
* @param market_index        返回的数据缓冲区, 内容MarketIndex 格式的结构数组
* @param count               返回结构的数量,即多少个MarketIndex
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_last_n_market_index(const char *symbol, int n, MarketIndex **market_index, int *count);

/**
* 提取交易日历
* @param exchange            交易所代码, 如SHSE
* @param start_time          开始时间
* @param end_time            结束时间 
* @trade_date                返回的数据缓冲区, 内容TradeDate 格式的结构数组
* @param count               返回结构的数量,即多少个TradeDate
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_calendar(const char *exchange, const char *start_time, const char *end_time, TradeDate **trade_date, int *count);


/**
* 提取复权因子
* @param symbols             证券代码 如SHSE.600000
* @param start_time          开始时间
* @param end_time            结束时间
* @adj_factor                返回的数据缓冲区, 内容StockAdjustFactor 格式的结构数组
* @param count               返回结构的数量,即多少个StockAdjustFactor
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_stock_adj(const char *symbol, const char *start_time, const char *end_time, StockAdjustFactor **adj_factor, int *count);

/**
* 提取分红送股明细
* @param symbols             证券代码 如SHSE.600000
* @param start_time          开始时间
* @param end_time            结束时间
* @divident                  返回的数据缓冲区, 内容StockDivident 格式的结构数组
* @param count               返回结构的数量,即多少个StockDivident
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_divident(const char *symbol, const char *start_time, const char *end_time, StockDivident **divident, int *count);

/**
* 提取虚拟合约信息
* @param vsymbol             虚拟合约代码，可以是连接合约或主力合约代码，如CFFEX.IF, CFFEX.IF00
* @param start_time          开始时间
* @param end_time            结束时间
* @vcontract                 返回的数据缓冲区, 内容VirtualContract 格式的结构数组
* @param count               返回结构的数量,即多少个VirtualContract
* @return                    0: success, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*
*/
GM_API int gm_md_get_virtual_contract(const char *vsymbol, const char *start_time, const char *end_time, VirtualContract **vcontract, int *count);

#endif
