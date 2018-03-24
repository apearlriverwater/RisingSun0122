/**
* @file    error.h
* @brief   gmsdk 错误码定义
* @version v2.2.0
*
*/

#ifndef GMSDK_ERROR_H
#define GMSDK_ERROR_H

/* 共用的配置或通讯层面的错误 1000～1499 */

#define SUCCESS                             0       // "成功"

#define ERR_CONFIG_FILE_NOT_EXIST           1001    // "策略配置文件不存在"
#define ERR_CONFIG_PARSE                    1002    // "策略配置文件格式错误"
#define ERR_AUTH_CONNECT                    1003    // "无法连接掘金认证服务"
#define ERR_AUTH_LOGIN                      1004    // "无法登录掘金认证服务"
#define ERR_REQUEST_TIMEOUT                 1005    // "请求超时"
#define ERR_INVALID_PARAMETER               1006    // "非法参数"
#define ERR_STRATEGY_INIT                   1007    // "策略未初始化"
#define ERR_INTERNAL_INIT_ERROR             1008    // "SDK内部初始化错误"
#define ERR_API_SERVER_CONNECT              1009    // "无法连接掘金API服务"
#define ERR_QUERY_SERVER_ADDR_ERROR         1010    // "无法获取掘金服务器地址列表"

/* 业务层面错误码 共有部分， 1500～1999*/

#define ERR_INVALID_SYMBOL                  1501    // "非法证券代码"
#define ERR_INVALID_DATE                    1502    // "非法日期格式"
#define ERR_INVALID_STRATEGY_ID             1503    // "非法策略ID"

/* 交易部分 2000 ~ 2999 */ 

#define ERR_TD_CONNECT                      2000    // "交易服务连接失败"
#define ERR_TD_LOGIN                        2001    // "交易服务登录失败"
#define ERR_TD_TIMEOUT                      2002    // "交易命令请求超时" 
#define ERR_TD_NO_RESULT                    2003    // "该条件没查到数据"
#define ERR_TD_INVALID_SESSION              2004    // "交易请求没有登陆"
#define ERR_TD_INVALID_PARAMETER            2005    // "交易请求参数非法" 
#define ERR_TD_STRATEGY_LOCKED              2006    // "策略被禁止交易" 
#define ERR_TD_SERVER_ERROR                 2007    // "交易服务内部错误" 
#define ERR_TD_CORRUPT_DATA                 2008    // "返回数据包错误" 
#define ERR_TD_CONNECT_CLOSE                2009    // "交易服务连接断开"


/* 数据服务部分 3000～3999*/

#define ERR_MD_CONNECT                      3000    // "数据服务连接失败"
#define ERR_MD_LOGIN                        3001    // "数据服务登录失败"
#define ERR_MD_TIMEOUT                      3002    // "数据服务请求超时"
#define ERR_MD_NO_RESULT                    3003    // "该条件没查到数据"
#define ERR_MD_BUFFER_ALLOC                 3005    // "分配缓冲区错误"
#define ERR_MD_INVALID_PARAMETER            3006    // "数据请求参数非法" 
#define ERR_MD_SERVER_ERROR                 3007    // "数据服务内部错误" 
#define ERR_MD_CORRUPT_DATA                 3008    // "返回数据包错误"
#define ERR_MD_CONNECT_CLOSE                3009    // "数据服务连接断开"

/*回测部分 4000~4999*/

#define ERR_BT_INVALID_TIMESPAN             4000    // "回测时间区间错误"
#define ERR_BT_INVALID_INITIAL_CASH         4001    // "回测请求参数非法"
#define ERR_BT_INVALID_TRANSACTION_RATIO    4002    // "回测请求参数非法"
#define ERR_BT_INVALID_COMMISSION_RATIO     4003    // "回测请求参数非法"
#define ERR_BT_INVALID_SLIPPAGE_RATIO       4004    // "回测请求参数非法"
#define ERR_BT_READ_CACHE_ERROR             4005    // "回测读取缓存数据错误"
#define ERR_BT_WRITE_CACHE_ERROR            4006    // "回测写入缓存数据错误"
#define ERR_BT_CONNECT                      4007    // "终端未启动或无法连接到终端"
#define ERR_BT_RESULT                       4008    // "回测绩效生成失败"
#define ERR_BT_NO_ORDER                     4009    // "回测策略没有委托"

/*网络错误 10000~19999*/
#define ERR_NET_ERROR                      10000    //网络错误

#endif
