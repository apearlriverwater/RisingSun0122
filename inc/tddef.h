/**
* @file    tddef.h
* @brief   gmsdk 交易数据结构说明
* @version v2.2.0
*
*/

#ifndef GMSDK_TDDEF_H
#define GMSDK_TDDEF_H


#include "common.h"


enum ExecType {
  ExecType_New = 1,
  ExecType_DoneForDay = 4,
  ExecType_Canceled = 5,
  ExecType_PendingCancel = 6,
  ExecType_Stopped = 7,
  ExecType_Rejected = 8,
  ExecType_Suspended = 9,
  ExecType_PendingNew = 10,
  ExecType_Calculated = 11,
  ExecType_Expired = 12,
  ExecType_Restated = 13,
  ExecType_PendingReplace = 14,
  ExecType_Trade = 15,
  ExecType_TradeCorrect = 16,
  ExecType_TradeCancel = 17,
  ExecType_OrderStatus = 18,
  ExecType_CancelRejected = 19,
  ExecType_OptionInquiry_Failed = 20,
  ExecType_OptionExercise_Ok = 21,
  ExecType_OptionExercise_Failed = 22,
  ExecType_CancelOptionExercise_Ok = 23,
  ExecType_CancelOptionExercise_Failed = 24,
  ExecType_CombinePosition_Ok = 25,
  ExecType_CombinePosition_Failed = 26,
  ExecType_UncombinePosition_Ok = 27,
  ExecType_UncombinePosition_Failed = 28
};


enum OrderStatus {
  OrderStatus_New = 1,
  OrderStatus_PartiallyFilled = 2,
  OrderStatus_Filled = 3,
  OrderStatus_DoneForDay = 4,
  OrderStatus_Canceled = 5,
  OrderStatus_PendingCancel = 6,
  OrderStatus_Stopped = 7,
  OrderStatus_Rejected = 8,
  OrderStatus_Suspended = 9,
  OrderStatus_PendingNew = 10,
  OrderStatus_Calculated = 11,
  OrderStatus_Expired = 12,
  OrderStatus_AcceptedForBidding = 13,
  OrderStatus_PendingReplace = 14
};


enum CancelOrderRejectReason {
  CancelOrderRejectReason_OrderFinalized = 101,
  CancelOrderRejectReason_UnknownOrder = 102,
  CancelOrderRejectReason_BrokerOption = 103,
  CancelOrderRejectReason_AlreadyInPendingCancel = 104
};


enum OrderSide {
  OrderSide_Bid = 1,
  OrderSide_Ask = 2
};


enum OrderType {
    OrderType_LMT = 0,
    OrderType_BOC = 1,
    OrderType_BOP = 2,
    OrderType_B5TC = 3,
    OrderType_B5TL = 4,
    OrderType_IOC = 5,
    OrderType_FOK = 6,
    OrderType_AON = 7,
    OrderType_MTL = 8,
    OrderType_EXE = 9
};


enum PositionEffect {
    PositionEffect_Open = 1,
    PositionEffect_Close = 2,
    PositionEffect_CloseToday = 3,
    PositionEffect_CloseYesterday = 4
};


enum OrderRejectReason {
  OrderRejectReason_UnknownReason = 1,
  OrderRejectReason_RiskRuleCheckFailed = 2,
  OrderRejectReason_NoEnoughCash = 3,
  OrderRejectReason_NoEnoughPosition = 4,
  OrderRejectReason_IllegalStrategyID = 5,
  OrderRejectReason_IllegalSymbol = 6,
  OrderRejectReason_IllegalVolume = 7,
  OrderRejectReason_IllegalPrice = 8,
  OrderRejectReason_NoMatchedTradingChannel = 9,
  OrderRejectReason_AccountForbidTrading = 10,
  OrderRejectReason_TradingChannelNotConnected = 11,
  OrderRejectReason_StrategyForbidTrading = 12,
  OrderRejectReason_NotInTradingSession = 13
};


/**
* @brief 委托数据定义
*
*/
typedef struct Order
{
    char strategy_id[LEN_ID];       ///策略id
    char account_id[LEN_ID];        ///帐号id, 系统自动根据配置补充

    char cl_ord_id[LEN_ID];         ///委托订单的客户方id
    char order_id[LEN_ID];          ///委托订单的柜台生成id
    char ex_ord_id[LEN_ID];         ///委托订单的交易所接受后生成id

    char exchange[LEN_EXCHANGE];    ///交易所代码
    char sec_id[LEN_SECID];         ///交易标的代码，本地代码如IF1502

    int position_effect;            //开平标志，取值参考enum PositionEffect
    int side;                       //买卖方向，取值参考enum OrderSide
    int order_type;                 //委托类型，取值参考enum OrderType
    int order_src;                  //委托来源，取值参考enum OrderSrc
    int status;                     //委托状态，取值参考enum OrderStatus
    int ord_rej_reason;             //委托拒绝原因，取值参考enum OrderRejectReason
    char ord_rej_reason_detail[LEN_INFO];   ///委托被拒绝原因描述

    double price;                   //委托价格
    double stop_price;              //止损价
    double volume;                  //委托量
    double filled_volume;           //已成量
    double filled_vwap;             //已成均价
    double filled_amount;           //已成金额

    double sending_time;            //委托发送时间
    double transact_time;           //委托处理时间
}Order;


/**
* @brief 委托回报数据定义
*
*/
typedef struct ExecRpt
{
    char strategy_id[LEN_ID];       ///策略id

    char cl_ord_id[LEN_ID];         ///委托订单的客户方id
    char order_id[LEN_ID];          ///委托订单的柜台生成id
    char exec_id[LEN_ID];           ///委托订单的交易所生成id

    char exchange[LEN_EXCHANGE];    ///交易所代码
    char sec_id[LEN_SECID];         ///交易标的代码，本地代码如IF1502

    int position_effect;            ///开平仓标识
    int side;                       ///买卖方向
    int ord_rej_reason;             ///委托被拒绝原因类型
    char ord_rej_reason_detail[LEN_INFO];  ///委托被拒绝原因描述
    int exec_type; 

    double price;                   ///成交价格
    double volume;                  ///成交数量
    double amount;                  ///成交金额

    double transact_time;           ///成交时间
}ExecRpt;


/**
* @brief 资金帐户的数据定义
*
*/
typedef struct Cash
{
    char strategy_id[LEN_ID];       ///策略id
	char account_id[LEN_ID];        ///账户id
    int currency;                   ///货币类别

    double nav;                     ///帐户净值
    double fpnl;                    ///浮动赢亏
    double pnl;                     ///总赢亏
    double profit_ratio;            ///收益率
    double frozen;                  ///持仓冻结金额
    double order_frozen;            ///挂单冻结金额
    double available;               ///可用资金

    double cum_inout;               ///累计出入金总额
    double cum_trade;               ///累计交易额
    double cum_pnl;                 ///累计赢亏
    double cum_commission;          ///累计交易费

    double last_trade;              ///上次交易金额
    double last_pnl;                ///上次总赢亏
    double last_commission;         ///上次交易费
    double last_inout;              ///上次出入金
    int change_reason;              ///帐户变动类别

    double transact_time;           ///帐户变动时间戳
}Cash; 


/**
* @brief 持仓数据定义
*
*/
typedef struct Position
{
    char strategy_id[LEN_ID];           ///策略id
	char account_id[LEN_ID];            ///账户id
    char exchange[LEN_EXCHANGE];        ///交易所代码
    char sec_id[LEN_SECID];             ///交易标的代码，本地代码如IF1502
    int  side;                          ///买卖方向
    double volume;                      ///持仓数量
    double volume_today;                ///今仓量
    double amount;                      ///持仓市值
    double vwap;                        ///持仓成本

    double price;                       ///当前价格
    double fpnl;                        ///浮动赢动
    double cost;                        ///持仓成本
    double order_frozen;                ///挂单冻结仓位量
    double order_frozen_today;          ///挂单冻结今仓仓位
    double available;                   ///可平仓位量
    double available_today;             ///可平今仓位(volume_today-order_frozen_today)
	double available_yesterday;         ///可平昨仓位(available - available_today)

    double last_price;                  ///上一次成交价
    double last_volume;                 ///上一次成交量

    double init_time;                   ///建仓时间
    double transact_time;               ///仓位变更时间
}Position;

/**
* @brief 绩效指标定义
*
*/
typedef struct Indicator
{
    char  strategy_id[LEN_ID];                   //策略ID                                             
    char  account_id[LEN_ID];                    //账号ID                                             

    double nav;                                  //净值(cum_inout + cum_pnl + fpnl - cum_commission)  
    double pnl;                                  //净收益(nav-cum_inout)                              
    double profit_ratio;                         //收益率(pnl/cum_inout)   
	double profit_ratio_bench;                   //基准收益率

    double sharp_ratio;                          //夏普比率                                           
    double risk_ratio;                           //风险比率     
	int open_count;                              //开仓次数
    int trade_count;                             //交易次数                                           
    int win_count;                               //盈利次数                                           
    int lose_count;                              //亏损次数                                           
    double win_ratio;                            //胜率                                               
    double max_profit;                           //最大收益                                           
    double min_profit;                           //最小收益                                           
    double max_single_trade_profit;              //最大单次交易收益                                   
    double min_single_trade_profit;              //最小单次交易收益                                   
    double daily_max_single_trade_profit;        //今日最大单次交易收益                               
    double daily_min_single_trade_profit;        //今日最小单次交易收益                               
    double max_position_value;                   //最大持仓市值或权益                                 
    double min_position_value;                   //最小持仓市值或权益                                 
    double max_drawdown;                         //最大回撤                                           
    double daily_pnl;                            //今日收益                                           
    double daily_return;                         //今日收益率                                         
    double annual_return;                        //年化收益率       

	double cum_inout;							 //累计出入金
	double cum_trade;                            //累计交易额
	double cum_pnl;                              //累计平仓收益(没扣除手续费)
	double cum_commission;                       //累计手续费

    double transact_time;                        //指标计算时间         
}Indicator;

/**
* @brief 柜台账号信息
*
*/
typedef struct BrokerAccount
{
	char account_id[LEN_ID];                      //账号ID
	char username[LEN_USERNAME];                  //用户名
	bool permissible;                             //账号是否允许交易
	int  status;                                  //账户状态
}BrokerAccount;

/**
* @brief 作市商询价接收
*
*/
typedef struct OptionInquiry
{
	char exchange[LEN_EXCHANGE];                  //交易所代码
	char sec_id[LEN_SECID];                       //合约代码
	char inquiry_id[LEN_ID];                      //询价id
	double sending_time;                            //询价时间

}OptionInquiry;

/**
* @brief 行权申请
*
*/
typedef struct ExerciseOrder
{
	char    cl_ord_id[LEN_ID];          //客户方id
	char    exchange[LEN_EXCHANGE];     //交易所代码
	char    sec_id[LEN_SECID];          //行权代码
	double  volume;                     //行权数量
	int     position_effect;            //开平标志，取值参考enum PositionEffect
	int     side;                       //行权后头寸的持仓方向
}ExerciseOrder;

#endif
