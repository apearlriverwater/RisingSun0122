#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <iostream>

#include "mdapi.h"

using namespace std;


int main(int argc, char *[])
{
	int ret;

	//登录
	ret = gm_login("demo@myquant.cn", "123456");
	if (ret != 0)
	{
		printf("login fail");
		return ret;
	}

    //提起一分钟分时数据(freq=60 seconds)
    Bar *bar; int count;
    ret = gm_md_get_bars("CFFEX.IF1506", 60, "2015-02-04 00:00:00", "2015-02-09 00:00:00", &bar, &count);
    cout << "gm_md_get_bars: " << count <<endl;

    //提取tick数据
    Tick *tick;
    ret = gm_md_get_ticks("CFFEX.IF1506", "2015-02-04 00:00:00", "2015-02-09 00:00:00", &tick, &count);
    cout << "gm_md_get_ticks: " << count <<endl;

    //提取日频数据
    DailyBar *dbar;
    ret = gm_md_get_dailybars("CFFEX.IF1506", "2015-02-04 00:00:00", "2015-02-09 00:00:00", &dbar, &count);
    cout << "gm_md_get_dailybars: " << count <<endl;

    //提取最新N笔tick数据
    ret = gm_md_get_last_n_ticks("CFFEX.IF1506", 10, &tick, &count);
    cout << "gm_md_get_last_n_ticks: " << count <<endl;

    //提取最新N笔bar数据
    ret = gm_md_get_last_n_bars("CFFEX.IF1506", 60, 10, &bar, &count);
    cout << "gm_md_get_last_n_bars: " << count <<endl;

    //提取最新N笔dailybar数据
    ret = gm_md_get_last_n_dailybars("CFFEX.IF1506", 10, &dbar, &count);
    cout << "gm_md_get_last_n_dailybars: " << count <<endl;

    //提取tick, bar, dailybar快照
    ret = gm_md_get_last_ticks("CFFEX.IF1506,SZSE.000010",  &tick, &count);
    cout << "gm_md_get_last_ticks: " << count <<endl;
    ret = gm_md_get_last_bars("CFFEX.IF1506,SZSE.000010", 60, &bar, &count);
    cout << "gm_md_get_last_bars: " << count <<endl;
    ret = gm_md_get_last_dailybars("CFFEX.IF1506,SZSE.000010", &dbar, &count);
    cout << "gm_md_get_last_dailybars: " << count <<endl;

	// waiting...
	getchar();

	return 0;
}
