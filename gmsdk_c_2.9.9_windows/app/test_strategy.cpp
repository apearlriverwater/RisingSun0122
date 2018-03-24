#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <iostream>
#include "strategy.h"

using namespace std;

int g_count = 0;

//处理逐笔行情事件
void on_tick(Tick *tick)
{
	g_count++;


	int ret;
	if(tick->strtime)
		cout << "symbol: " << tick->sec_id << " price: " << tick->last_price << " time:" << tick->strtime << endl;

	Order o;
	if (g_count % 20 == 0)
	{
		ret = gm_td_open_long(tick->exchange, tick->sec_id, tick->last_price, 1, &o);
		if (ret == 0)
		{
			cout << "开多: " << o.cl_ord_id << endl;
			cout << "strategy: " << o.strategy_id << endl;
			cout << "symbol:" << o.sec_id << endl;
			cout << "price:" << o.price << endl;
			cout << "volume:" << o.volume << endl;
		}
		else
			cout << "error code: " << ret << endl;
	}

	if (g_count % 40 == 0)
	{
		ret = gm_td_open_short(tick->exchange, tick->sec_id, 0, 1, &o);
		if (ret == 0)
		{
			cout << "开空: " << o.cl_ord_id << endl;
			cout << "strategy: " << o.strategy_id << endl;
			cout << "symbol:" << o.sec_id << endl;
			cout << "price:" << o.price << endl;
			cout << "volume:" << o.volume << endl;
		}
		else
			cout << "error code: " << ret << endl;
	}

	if (g_count % 80 == 0)
	{
		ret = gm_td_close_long(tick->exchange, tick->sec_id, tick->last_price, 1, &o);
		if (ret == 0)
		{
			cout << "平多: " << o.cl_ord_id << endl;
			cout << "strategy: " << o.strategy_id << endl;
			cout << "symbol:" << o.sec_id << endl;
			cout << "price:" << o.price << endl;
			cout << "volume:" << o.volume << endl;
		}
		else
			cout << "error code: " << ret << endl;

	}

	if (g_count % 160 == 0)
	{
		ret = gm_td_close_short(tick->exchange, tick->sec_id, 0, 1, &o);
		if (ret == 0)
		{
			cout << "平空: " << o.cl_ord_id << endl;
			cout << "strategy: " << o.strategy_id << endl;
			cout << "symbol:" << o.sec_id << endl;
			cout << "price:" << o.price << endl;
			cout << "volume:" << o.volume << endl;
		}
		else
			cout << "error code: " << ret << endl;

	}

}

//处理分时行情事件
void on_bar(Bar *bar)
{
	cout << "symbol: " << bar->sec_id << " price: " << bar->close << " time:" << bar->strtime << endl;
	//cout << "symbol: " << bar->sec_id << " price: " << bar->close << endl;
}

//处理委托回报事件
void on_execrpt(ExecRpt *res)
{
	cout << "成交回报: " << endl;
	cout << "strategy: " << res->strategy_id << endl;
	cout << "symbol:" << res->sec_id << endl;
	cout << "price:" << res->price << endl;
	cout << "volume:" << res->volume << endl;
}

/**
* 委托回报函数类型(回调接口: 订单接受)
*
*/
void on_order_new(Order *res)
{
	cout << "order_new: " << res->strategy_id << "  " << res->price << endl;
}

/**
* 委托回报函数类型(回调接口：订单完全成交)
*
*/
void on_order_filled(Order *res)
{
	cout << "order_filled: " << res->strategy_id << "  " << res->price << endl;
}

/**
* 委托回报函数类型(回调接口：订单部分成交)
*
*/
void on_order_partiall_filled(Order *res)
{
	cout << "order_partiall_filled: " << res->strategy_id << "  " << res->price << endl;
}

/**
* 委托回报函数类型(回调接口：订单停止)
*
*/
void on_order_stop_executed(Order *res)
{
	cout << "order_stop_executed: " << res->strategy_id << "  " << res->price << endl;
}


/**
* 委托回报函数类型(回调接口：订单撤销成功)
*
*/
void on_order_canceled(Order *res)
{
	cout << "order_canceled: " << res->strategy_id << "  " << res->price << endl;
}

/**
* 委托回报函数类型(回调接口：撤单失败)
*
*/
void on_order_cancel_rejected(ExecRpt *res)
{
	cout << "order_cancel_rejected: " << res->strategy_id << "  " << res->price << endl;
}

void  on_error(int ec, const char *lp)
{
	printf("on_error code: %d ,msg: %s\n", ec, lp);
}

int main(int argc, char *[])
{
	int ret;

	//初始化策略,根据配置文件
	ret = strategy_init_with_config("test_strategy.ini");

	if (ret)
	{
		printf("init got error: %d\n", ret);
		system("pause");
		return ret;
	}

	// 设置事件回调函数
	gm_td_set_execrpt_callback(on_execrpt);
	gm_td_set_order_cancelled_callback(on_order_canceled);
	gm_td_set_order_cancel_rejected_callback(on_order_cancel_rejected);
	gm_td_set_order_filled_callback(on_order_filled);
	gm_td_set_order_new_callback(on_order_new);
	gm_td_set_order_partially_filled_callback(on_order_partiall_filled);
	gm_td_set_order_stop_executed_callback(on_order_stop_executed);
	gm_td_set_error_callback(on_error);

	gm_md_set_tick_callback(on_tick);
	gm_md_set_bar_callback(on_bar);
	gm_md_set_error_callback(on_error);

	printf("策略起动成功! %s\n", gm_strerror(ret));

	// 执行并等待策略运行结束
	ret = gm_run();

	if (ret)
	{
		cout << "error:" << ret << " msg:" << gm_strerror(ret) << endl;
		getchar();
	}

	return 0;
}
