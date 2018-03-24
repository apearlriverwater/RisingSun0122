#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <iostream>

#include "tdapi.h"
#include "common.h"

using namespace std;


/**
* 处理委托回报事件
*/
void on_execution(ExecRpt *res)
{
	cout << "execrpt type:" << res->exec_type << " " << res->exchange << "." << res->sec_id <<endl;
	switch (res->exec_type)
	{
	case 21:
		cout << "行权成功:" << res->exchange << "." << res->sec_id << " " << res->order_id<< endl;
		break;

	case 22:
		cout << "行权失败:" << res->exchange << "." << res->sec_id << " " << res->ord_rej_reason_detail << endl;
		break;

	case 23:
		cout << "行权撤消:" << res->exchange << "." << res->sec_id << " " << res->order_id << endl;
		break;

	case 24:
		cout << "行权撤消失败:" << res->exchange << "." << res->sec_id << " " << res->ord_rej_reason_detail << endl;
		break;

	case 26:
		cout << "组合保证金申请组合失败:" << res->exchange << "." << res->sec_id << " " << res->ord_rej_reason_detail << endl;
		break;

	case 28:
		cout << "组合保证金申请拆分失败:" << res->exchange << "." << res->sec_id << " " << res->ord_rej_reason_detail << endl;
		break;

	default:


		break;
	}
}

/**
* 委托回报函数类型(回调接口: 订单接受)
*/
void on_order_new(Order *res)
{
    cout << "order_new: " << res->strategy_id << "  " << res->price <<endl;
}

/**
* 委托回报函数类型(回调接口：订单完全成交) 
*/
void on_order_filled(Order *res)
{
    cout << "order_filled: " << res->strategy_id << "  " << res->price <<endl;
}

/**
* 委托回报函数类型(回调接口：订单部分成交)
*/
void on_order_partiall_filled(Order *res)
{
    cout << "order_partiall_filled: " << res->strategy_id << "  " << res->price <<endl;
}

/**
* 委托回报函数类型(回调接口：订单停止)
*/
void on_order_stop_executed(Order *res)
{
    cout << "order_stop_executed: " << res->strategy_id << "  " << res->price <<endl;
}


/**
* 委托回报函数类型(回调接口：订单撤销成功)
*/
void on_order_canceled(Order *res)
{
    cout << "order_canceled: " << res->strategy_id << "  " << res->price <<endl;
}

/**
* 委托回报函数类型(回调接口：撤单失败)
*/
void on_order_cancel_rejected(ExecRpt *res)
{
    cout << "order_cancel_rejected: " << res->strategy_id << "  " << res->price <<endl;
}

/**
* 登录交易服务器成功, 测试下单等
*/
void on_td_login()
{
	cout << "on_td_login" << endl;

	//gm_td_option_inquiry("CZCE", "SR705C6400");

	//ExerciseOrder o;
	//strcpy(o.exchange, "CZCE");
	//strcpy(o.sec_id, "SR705C6200");
	//o.volume = 1;
	//o.position_effect = PositionEffect_Close;
	//o.side = OrderSide_Bid;
	//gm_td_option_exercise(&o);

	//gm_td_cancel_option_exercise("CZCE", "2017030201831376");
	//gm_td_combine_position("SHFE", "ag1706", 0, 5);
	//gm_td_uncombine_position("SHFE", "ag1706", 0, 5);
}

void on_error(int code, const char* msg)
{
	//printf("error c=%d,msg=%s\n", code, msg);
}

void on_option_inquiry(OptionInquiry *option_inquiry)
{
	std::cout << "on_option_inquiry: " << option_inquiry->sec_id << endl;
}

int main(int argc, char *argv[])
{
	int ret;

    // 设置事件回调函数
    gm_td_set_login_callback(on_td_login);
	gm_td_set_execrpt_callback(on_execution);
	gm_td_set_order_cancelled_callback(on_order_canceled);
	gm_td_set_order_cancel_rejected_callback(on_order_cancel_rejected);
	gm_td_set_order_filled_callback(on_order_filled);
	gm_td_set_order_new_callback(on_order_new);
	gm_td_set_order_partially_filled_callback(on_order_partiall_filled);
	gm_td_set_order_stop_executed_callback(on_order_stop_executed);
	gm_td_set_error_callback(on_error);

	gm_td_set_option_inquiry_callback(on_option_inquiry);

	ret = gm_login("13480922739", "a7612006");
	if (ret != 0)
	{
		printf("login fail");
		return ret;
	}

	//连接到挖金子网站
	ret = gm_td_init("915c6faa-f260-11e5-b9d4-28b2bd5054ab");
	
    //连接到掘金终端
	//ret = gm_td_init("strategy_2", "localhost:8001");


    //初始化失败，退出。
	if (ret)
    {
        printf("gm_td_init return: %d(%s)\n", ret, gm_strerror(ret)); 
		system("pause");
        return ret;
	}
	

	
	// waiting...
    gm_run();
	return 0;
}
