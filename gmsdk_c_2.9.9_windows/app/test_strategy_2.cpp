#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <iostream>
#include "strategy.h"

using namespace std;

//处理逐笔行情事件
void on_tick(Tick *tick)
{

}


bool oc = true;

//处理分时行情事件
void on_bar(Bar *bar)
{
	if (oc)
	{
		gm_td_open_long(bar->exchange, bar->sec_id, 0, 100);
	}
	else
	{
		gm_td_close_long(bar->exchange, bar->sec_id, 0, 100);
	}

	oc = !oc;
}

void  on_error(int ec, const char *lp)
{
	//printf("on_error code: %d ,msg: %s\n", ec, lp);
}

int main(int argc, char *[])
{
	int ret;

	//初始化策略,根据配置文件
	ret = strategy_init_with_config("test_strategy_2.ini");

	if (ret)
	{
		printf("init got error: %d\n", ret);
		system("pause");
		return ret;
	}

	// 设置事件回调函数
	gm_td_set_error_callback(on_error);

	gm_md_set_tick_callback(on_tick);
	gm_md_set_bar_callback(on_bar);
	gm_md_set_error_callback(on_error);

	printf("开始回测!\n");

	// 执行并等待策略运行结束
	ret = gm_run();

	if (ret)
	{
		cout << "error:" << ret << " msg:" << gm_strerror(ret) <<endl;
		getchar();
	}

	return 0;
}
