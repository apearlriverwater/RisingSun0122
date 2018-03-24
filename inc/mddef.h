/**
* @file    mddef.h
* @brief   gmsdk 行情数据结构说明
* @version v2.2.0
*
*/

#ifndef GMSDK_MDDEF_H
#define GMSDK_MDDEF_H


#include "common.h"

/**
* @brief 事件数据结构
*
*/
typedef struct MDEvent
{
    double    utc_time;      ///<UTC时间戳[带毫秒]
    int       event_type;    ///<事件类型(1:开盘  2:收盘, 3:回放结束)
}MDEvent;


/**
* @brief 分时Bar数据结构
*
*/
typedef struct Bar
{
    char                    exchange[LEN_EXCHANGE];       ///<交易所代码
    char                    sec_id[LEN_SECID];            ///<证券ID
    int                     bar_type;                     ///<分时周期类型(enum BarType)
    double                  utc_time;                     ///bar的开始时间
    char                    strtime[LEN_ISO_DATATIME];    ///bar的开始时间
	double                  utc_endtime;                  ///bar的结束时间
	char                    strendtime[LEN_ISO_DATATIME]; ///bar的结束时间

    float                   open;                         ///<开盘价
    float                   close;                        ///<收盘价
    float                   high;                         ///<最高价
    float                   low;                          ///<最低价
    double                  volume;                       ///<成交量
    double                  amount;                       ///<成交金额
    float                   pre_close;                    ///前收盘价

    long long                position;                    ///<持仓量
    float                   adj_factor;                   //复权因子
    int                     flag;                         //除权出息，停牌等标记
}Bar;

/**
* @brief 日线数据结构,增加了持仓和结算,每日收盘保存
*
*/
typedef struct DailyBar
{

    char                    exchange[LEN_EXCHANGE];     ///<交易所代码
    char                    sec_id[LEN_SECID];          ///<证券ID
    int                     bar_type;                   ///<分时周期类型(enum BarType)
    double                  utc_time;                   ///<UTC时间戳
    char                    strtime[LEN_ISO_DATATIME];  ///交易时间

    float                   open;                       ///<开盘价
    float                   close;                      ///<收盘价
    float                   high;                       ///<最高价
    float                   low;                        ///<最低价
    double                  volume;                     ///<成交量
    double                  amount;                     ///<成交金额

    long long                position;                    ///<持仓量
    float                    settle_price;                 ///<结算价
    float                    upper_limit;                ///<涨停价
    float                    lower_limit;                ///<跌停价
    float                   pre_close;                  ///昨收价

    float                   adj_factor;                 //复权因子
    int                     flag;                       //除权出息，停牌等标记

}DailyBar;


/**
* @brief 逐笔报价Tick数据结构
*
*/
typedef struct Tick
{
    char                   exchange[LEN_EXCHANGE];   ///<交易所代码
    char                   sec_id[LEN_SECID];        ///<证券ID
    double                 utc_time;                 ///<utc时间，精确到毫秒
    char                   strtime[LEN_ISO_DATATIME];  ///交易时间

    //以下为基础字段
    float                  last_price;               ///<最新价
    float                  open;                     ///<开盘价
    float                  high;                     ///<最高价
    float                  low;                      ///<最低价

    float                  bid_p1;                   ///<买价一
    float                  bid_p2;                   ///<买价二
    float                  bid_p3;                   ///<买价三
    float                  bid_p4;                   ///<买价四
    float                  bid_p5;                   ///<买价五
    int                    bid_v1;                   ///<买量一
    int                    bid_v2;                   ///<买量二
    int                    bid_v3;                   ///<买量三
    int                    bid_v4;                   ///<买量四
    int                    bid_v5;                   ///<买量五
    float                  ask_p1;                   ///<卖价一
    float                  ask_p2;                   ///<卖价二
    float                  ask_p3;                   ///<卖价三
    float                  ask_p4;                   ///<卖价四
    float                  ask_p5;                   ///<卖价五
    int                    ask_v1;                   ///<卖量一
    int                    ask_v2;                   ///<卖量二
    int                    ask_v3;                   ///<卖量三
    int                    ask_v4;                   ///<卖量四
    int                    ask_v5;                   ///<卖量五

    double                 cum_volume;               ///<成交总量
    double                 cum_amount;               ///<成交总金额/最新成交额,累计值
    long long              cum_position;             ///<合约持仓量(期),累计值
    double                 last_amount;              ///<瞬时成交额
    int                    last_volume;              ///<瞬时成交量(中金所提供)
    float                  upper_limit;              ///涨停价
    float                  lower_limit;              ///跌停价
    float                  settle_price;             ///今日结算价
    int                    trade_type;               ///(保留)交易类型,对应多开,多平等类型
    float                  pre_close;                ///昨收价
}Tick;

/**
* @brief 交易代码数据结构
*
*/
struct Instrument
{
    char       symbol[LEN_SYMBOL];        //交易代码
    int        sec_type;                  //代码类型
    char       sec_name[LEN_SEC_NAME];    //代码名称
    double     multiplier;                //合约乘数
    double     margin_ratio;              //保证金比率
    double     price_tick;                //价格变更单位 
    double     upper_limit;               //当天涨停板
    double     lower_limit;               //当天跌停板
    int        is_active;                 //当天是否交易
	char       update_time[LEN_ISO_DATATIME]; //更新时间
};

/**
* @brief 成份股数据结构
*
*/
struct Constituent
{
    char       symbol[LEN_SYMBOL];        //交易代码
    double     weight;                    //代码权重
};

/**
* @brief 财务指标
*
*/
struct FinancialIndex
{
    char   symbol[LEN_SYMBOL];            //交易代码
    char   pub_date[LEN_PUB_DATE];        //公告日期
    double eps;                           //每股收益
    double bvps;                          //每股净资产
    double cfps;                          //每股现金流
    double afps;                          //每股公积金
    double total_asset;                   //总资产
    double current_asset;                 //流动资产
    double fixed_asset;                   //固定资产
    double liability;                     //负债合计
    double current_liability;             //流动负债
    double longterm_liability;            //长期负债
    double equity;                        //所有者权益
    double income;                        //主营业务收入
    double operating_profit;              //主营业务利润
    double net_profit;                    //净利润
};

/**
* @brief 股本指标
*
*/
struct ShareIndex
{
    char   symbol[LEN_SYMBOL];            //交易代码
    char   pub_date[LEN_PUB_DATE];        //公告日期
    double total_share;                   //总股本
    double flow_a_share;                  //流通A股
    double nonflow_a_share;               //限售流通A股
};

/**
* @brief 市场指标
*
*/
struct MarketIndex
{
    char   symbol[LEN_SYMBOL];            //交易代码
    char   pub_date[LEN_PUB_DATE];        //公告日期
    double pe_ratio;                      //收益率
    double pb_ratio;                      //市净率
    double ps_ratio;                      //市销率
    double market_value;                  //市值
    double market_value_flow;             //流通市值
};

/**
* @brief 交易日
*
*/
struct TradeDate
{
	double   utc_time;                    //交易日(utc)
	char     strtime[LEN_ISO_DATATIME];   //交易日(string)
};

/**
* @brief 复权因子
*
*/

struct StockAdjustFactor
{
	char       symbol[LEN_SYMBOL];         //股票代码
	char       trade_date[LEN_TRADE_DATE]; //交易日
	double     adj_factor;                 //复权因子
};

/**
* @brief 分红送股事件
*
*/
struct StockDivident
{ 
	char       symbol[LEN_SYMBOL];         //股票代码
	char       div_date[LEN_TRADE_DATE];   //除权除息日
	double     cash_div;                   //每股派现
	double     share_div_ratio;            //每股送股比例
	double     share_trans_ratio;          //每股转增股比例
	double     allotment_ratio;            //每股配股比例
	double     allotment_price;            //配股价
};

/**
* @brief 虚拟合约
*
*/

struct VirtualContract
{
	char     vsymbol[LEN_SYMBOL];        //主力合约或连接合约代码
	char     symbol[LEN_SYMBOL];         //真实symbol
	char     trade_date[LEN_TRADE_DATE]; //交易日
};


#endif
