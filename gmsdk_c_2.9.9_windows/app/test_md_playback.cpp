#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "mdapi.h"
#include "tdapi.h"

using namespace std;


//处理逐笔行情事件
void on_tick(Tick *tick)
{
	cout << "代码:" << tick->exchange << "." << tick->sec_id << ".tick 时间:" << tick->strtime << " 最新价:" << tick->last_price << endl;
}

//处理分时行情事件
void on_bar(Bar *bar)
{
	cout << "代码:" << bar->sec_id << " 时间:" << bar->strtime << " bar类型:" << bar->bar_type << endl;
}

void  on_error(int code, const char *msg)
{
	//printf("error code: %d \n", code);
}


int main(int argc, char *[])
{
	int ret;

	ret = gm_login("username", "password");
	if (ret != 0)
	{
		printf("login fail");
		return ret;
	}

	// 设置事件回调函数
	gm_md_set_tick_callback(on_tick);
	gm_md_set_bar_callback(on_bar);
	gm_md_set_error_callback(on_error);

	ret = gm_md_init(
		MD_MODE_PLAYBACK,
		"SHFE.ag1706.tick",
		"2016-11-16 21:00:00",
		"2016-11-17 15:20:00"
		);


	//初始化失败，退出。
	if (ret)
	{
		printf("gm_md_login return: %d\n", ret);
		return ret;
	}

	gm_run();

	printf("playback end!");
	getchar();
	return 0;
}

