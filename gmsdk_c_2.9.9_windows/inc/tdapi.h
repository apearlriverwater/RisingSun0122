/**
* @file    tdapi.h
* @brief   gmsdk 交易数据结构说明
* @version v2.2.0
*
*/

#ifndef GMSDK_TDAPI_H
#define GMSDK_TDAPI_H

#include <stddef.h>
#include "common.h"
#include "tddef.h"

// GMSDK 交易接口
// =====================================================================================

/**
* 初始化交易服务: 连接并登陆交易服务
* @param strategy_id 策略ID
* @param addr        交易服务器地址, cloud.myquant.cn:8001
* @return 0：        成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_init(const char *strategy_id, const char *addr=NULL);


/**
* 重连到交易服务: 如果交易服务中途断开了连接，可调用此函数重连。
* @return 0：成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_reconnect();


/**
* 委托请求：开多仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_open_long(const char *exchange, const char *sec_id, double price, double volume, Order *order=NULL);

/**
* 委托请求：开空仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_open_short(const char *exchange, const char *sec_id, double price, double volume, Order *order=NULL);

/**
* 委托请求：平多仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_close_long(const char *exchange, const char *sec_id, double price, double volume, Order *order=NULL);

/**
* 委托请求：平空仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_close_short(const char *exchange, const char *sec_id, double price, double volume, Order *order=NULL);

/**
* 委托请求：平昨多仓(上期)
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_close_long_yesterday(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 委托请求：平昨空仓(上期)
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_close_short_yesterday(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 委托请求, 
* @param o.exchange        交易所代码
* @param o.sec_id          证券代码
* @param o.price           委托价格
* @param o.volume          委托数量
* @param o.position_effect 开/平方向，参见enum PositionEffect
* @param o.side            买卖/多空方向，参见enum OrderSide
* @param o.order_type      委托类型，参见enum OrderType
* @param o.stop_price      止损止盈价
* @return 0:             成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_place_order(Order *o);

/**
* 撤销委托
* @param cl_ord_id 客户端委托ID，委托的唯一识别符（client order id)
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_cancel_order(const char *cl_ord_id);

/**
* 同步委托请求：开多仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_open_long_sync(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 同步委托请求：开空仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_open_short_sync(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 同步委托请求：平多仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_close_long_sync(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 同步委托请求：平空仓
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_close_short_sync(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 同步委托请求：平昨多仓(上期)
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_close_long_yesterday_sync(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 同步委托请求：平昨空仓(上期)
* @param exchange 交易所代码
* @param sec_id 证券代码
* @param price  价格：price==0为市价单，否则为限价单
* @param volume 数量
* @param order  输出参数，返回委托请求的Order对象，Order对象空间由用户分配并传入
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_close_short_yesterday_sync(const char *exchange, const char *sec_id, double price, double volume, Order *order = NULL);

/**
* 同步委托请求,
* @param o.exchange        交易所代码
* @param o.sec_id          证券代码
* @param o.price           委托价格
* @param o.volume          委托数量
* @param o.position_effect 开/平方向，参见enum PositionEffect
* @param o.side            买卖/多空方向，参见enum OrderSide
* @param o.order_type      委托类型，参见enum OrderType
* @param o.stop_price      止损止盈价
* @return 0:             成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/

GM_API int gm_td_place_order_sync(Order *o);

/**
* 同步撤销委托
* @param cl_ord_id 客户端委托ID，委托的唯一识别符（client order id)
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/

GM_API int gm_td_cancel_order_sync(const char *cl_ord_id);

/**
* 查询委托
* @param start_time 查询委托的开始时间,如果为空或NULL, 则查询当天的委托
* @param end_time   查询委托的结束时间,如果为空或NULL, 则查询当天的委托
* @param res 委托查询结果
* @param count 未结委托记录条数
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_get_orders(const char *start_time, const char *end_time, Order **res, int *count);

/**
* 查询委托
* @param cl_ord_id 客户端委托ID，委托的唯一识别符（client order id)
* @param res 委托查询结果
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_get_order(const char *cl_ord_id, Order **res);

/**
* 查询未结委托
* @param res   未结委托查询结果
* @param count 未结委托记录条数
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_get_unfinished_orders(Order **res, int *count);

/**
* 按市场与代码查询委托
* @param exchange   市场代码
* @param sec_id     证券代码或合约代码
* @param start_time 查询委托的开始时间,如果为空或NULL, 则查询当天的委托
* @param end_time   查询委托的结束时间,如果为空或NULL, 则查询当天的委托
* @param res 委托查询结果
* @param count 未结委托记录条数
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_get_orders_by_symbol(const char *exchange, const char *sec_id, const char *start_time, const char *end_time, Order **res, int *count);

/**
* 查询当前策略的资金
* @param res 资金查询结果
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_get_cash(Cash **res);

/**
* 查询当前策略的持仓
* @param symbol 持仓代码
* @param side   持仓方向
* @param res    持仓查询结果
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_get_position(const char *exchange, const char *sec_id, int side, Position **res);


/**
* 查询当前策略的持仓
* @param res   持仓查询结果
* @param count 持仓记录条数
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h) 
*/
GM_API int gm_td_get_positions(Position **res, int *count);

/**
* 查询当前策略的绩效
* @param res 绩效查询结果
* @return 0: 成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_get_indicator(Indicator **res);

/**
* Login回调方法
*
*/
typedef void (*TDLoginCallback)();

/**
* 委托回报函数类型(回调接口)
*
*/
typedef void (*TDExecRptCallback) (ExecRpt *res);

/**
* 订单状态更新函数类型(回调接口: 订单状态)
*
*/
typedef void (*TDOrderStatusCallback) (Order *res);

/**
* 订单状态更新函数类型(回调接口: 订单拒绝)
*
*/
typedef void (*TDOrderRejectedCallback) (Order *res);

/**
* 订单状态更新函数类型(回调接口: 订单接受)
*
*/
typedef void (*TDOrderNewCallback) (Order *res);

/**
* 订单状态更新函数类型(回调接口：订单完全成交) 
*
*/
typedef void (*TDOrderFilledCallback) (Order *res);

/**
* 订单状态更新函数类型(回调接口：订单部分成交)
*
*/
typedef void (*TDOrderPartiallyFilledCallback) (Order *res);

/**
* 订单状态更新函数类型(回调接口：订单停止)
*
*/
typedef void (*TDOrderStopExecutedCallback) (Order *res);


/**
* 订单状态更新函数类型(回调接口：订单撤销成功)
*
*/
typedef void (*TDOrderCancelledCallback) (Order *res);

/**
* 委托回报函数类型(回调接口：撤单失败)
*
*/
typedef void (*TDOrderCancelRejectedCallback) (ExecRpt *res);

/**
* 交易Error回调方法
* @param error_code          错误编号
* @param error_msg          错误描述
*
*/
typedef void(*TDErrorCallback)(int error_code, const char *msg);

/**
* 回测完成回调方法
* @param indicator          回调绩效报告
*
*/
typedef void(*TDBacktestFinishCallback)(Indicator *indicator);

/**
* 作市商接收投资者询价回调方法
* @param instrument          询价合约信息
*
*/
typedef void(*TDOptionInquiryCallback)(OptionInquiry *option_inquiry);

/**
* 设置登录回调方法
* @param cb          登录回调方法
*
*/
GM_API void gm_td_set_login_callback(TDLoginCallback cb);

/**
* 设置委托回报 callback函数 （原始委托回报函数，如果注册，会最先被调用）
* @param cb 委托回报处理函数
*/
GM_API void gm_td_set_execrpt_callback(TDExecRptCallback cb);

/**
* 设置订单状态更新回报 callback函数
* @param cb 委托被拒绝回报处理函数
*/
GM_API void gm_td_set_order_status_callback(TDOrderStatusCallback cb);

/**
* 设置委托拒绝回报 callback函数
* @param cb 委托被拒绝回报处理函数
*/
GM_API void gm_td_set_order_rejected_callback(TDOrderRejectedCallback cb);

/**
* 设置委托接受回报 callback函数
* @param cb 委托下单成功回报处理函数
*/
GM_API void gm_td_set_order_new_callback(TDOrderNewCallback cb);

/**
* 设置委托完全成交回报 callback函数
* @param cb 委托回报处理函数
*/
GM_API void gm_td_set_order_filled_callback(TDOrderFilledCallback cb);

/**
* 设置委托部分成交回报 callback函数
* @param cb 委托回报处理函数
*/
GM_API void gm_td_set_order_partially_filled_callback(TDOrderPartiallyFilledCallback cb);

/**
* 设置委托停止回报 callback函数
* @param cb 委托停止处理函数
*/
GM_API void gm_td_set_order_stop_executed_callback(TDOrderStopExecutedCallback cb);

/**
* 设置委托撤销回报 callback函数
* @param cb 委托撤销处理函数
*/
GM_API void gm_td_set_order_cancelled_callback(TDOrderCancelledCallback cb);

/**
* 设置委托撤销拒绝回报 callback函数
* @param cb 委托撤销失败处理函数
*/
GM_API void gm_td_set_order_cancel_rejected_callback(TDOrderCancelRejectedCallback cb);

/**
* 设置交易error回调方法
* @param cb          Error回调方法
*
*/
GM_API void gm_td_set_error_callback(TDErrorCallback cb);

/**
* 设置回测完成回调方法
* @param cb          回测完成回调方法
*
*/
GM_API void gm_td_set_backtest_finish_callback(TDBacktestFinishCallback cb);

/**
* 获取柜台交易账号列表
* 
*
*/
GM_API int gm_td_get_broker_accounts(BrokerAccount** res, int *count);

/**
* 获取柜台交易账号资金
*
*
*/
GM_API int gm_td_get_broker_cash(Cash **res, int *count);

/**
* 获取柜台交易账号持仓
*
*
*/
GM_API int gm_td_get_broker_positions(Position **res, int *count);

/**
* 设置接收投资者询价回调方法
* @param cb          接收投资者询价回调方法
*
*/
GM_API void gm_td_set_option_inquiry_callback(TDOptionInquiryCallback cb);

/**
* 投资者询价
* @param exchange          交易所代码
* @param sec_id            合约代码
*/
GM_API int gm_td_option_inquiry(const char *exchange, const char *sec_id);

/**
* 行权
* @param o               行权参数
* @return 0:             成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_option_exercise(ExerciseOrder *o);

/**
* 撤销行权
* @param exchange        交易所id
* @param exec_order_id   行权编号
* @return 0:             成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_cancel_option_exercise(const char *exchange, const char *exec_order_id);

/**
* 组合保证金-申请组合
* @param exchange           交易所代码
* @param sec_id             组合合约代码, a&b样式
* @param side               组合合约中的第一腿合约（即合约 a ）的持仓方向填入此字段
* @param volume             申请的组合的数量,如 如 a&b 为 为 1:3 的配比，持仓数量为 a 2 手，b 6 手；当申请 2 手 手 a 持仓与 6 手 手 b 持仓的组合保证金优惠时，此时需填入 2.
* @return 0:                成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_combine_position(const char *exchange, const char* sec_id, int side, int volume);


/**
* 组合保证金-拆分组合
* @param exchange           交易所代码
* @param sec_id             组合合约代码, a&b样式
* @param side               组合合约中的第一腿合约（即合约 a ）的持仓方向填入此字段
* @param volume             申请的组合的数量,如 如 a&b 为 为 1:3 的配比，持仓数量为 a 2 手，b 6 手；当申请 2 手 手 a 持仓与 6 手 手 b 持仓的组合保证金优惠时，此时需填入 2.
* @return 0:                成功, 其他： error code(注：参见SDK错误代码定义文档，或头文件error.h)
*/
GM_API int gm_td_uncombine_position(const char *exchange, const char* sec_id, int side, int volume);

#endif
