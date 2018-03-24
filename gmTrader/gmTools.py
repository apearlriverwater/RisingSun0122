#-*- coding: utf-8 -*-
 
import struct
import os
from pandas import Series, DataFrame
import pandas as pd
import numpy  as np

RISINGSUN_BUY	=		1  #BUY 
RISINGSUN_SELL	=		2  #SELL

'''
path: 
filename:文件名包含的子字符串，不支持通配符
onlyfile=True  是否仅返回文件名，不返回子目录名

'''
def get_code_in_cap_file(path,filename,minutes,onlyfile=True):
    lists=os.listdir(path)
    files=[]

    if onlyfile==True:
        #only return file lists
        if len(filename)>0:
            files=[file for file in lists if file.find(filename)>-1 and file.find('.dat')>-1 and file.find(minutes)>-1]
            return files

    return lists

#//仅保留有用的信息
#typedef struct tagCAPITALFLOWMINISTRUCK {
#	int32_t	m_nDate, m_nTime;       //date /时间  2*4
#	double	m_dblSmallBuy, m_dblMidBuy, m_dblBigBuy, m_dblHugeBuy;   4*8
#	double	m_dblSmallSell, m_dblMidSell, m_dblBigSell, m_dblHugeSell;  4*8

def read_cap_flow(filepath):
    columns=['Date','Time','SmallBuy','MidBuy','BigBuy','HugeBuy','SmallSell','MidSell','BigSell','HugeSell']

    f = open(filepath,'rb')
    dataSize=72
    filedata = f.read()
    filesize = f.tell()
    f.close()
    
    tickCount=filesize/dataSize

    index=0
    series=[]
    while index < filesize:
        cap=struct.unpack_from('2i8d',filedata,index)
        series.append(cap)
        index=index+dataSize
    caps=pd.DataFrame(series,columns=columns)
    return caps


'''
    主力资金流统计
'''
def CaclMainFlow(CapFlow):
    MainFlow=()
    for flow in CapFlow:
        MainFlow=MainFlow+((MainFlow+flow[4]+flow[5]-flow[8]-flow[9])/10000)
        continue
    return MainFlow  #单位：万元  list

'''
    均线多头向上判断：多头向上时返回true，否则false
        dataList 待计算数据
        maList 周期序列列表，最少三个周期,
        nLastWeeks最少程序周期数
'''
def IsMaUp(data,maList,nLastWeeks):
    bRet=True
    ma=[]
    columns=[]
    CaclCount=sum(maList)+nLastWeeks+2

    if len(maList)>=3 and len(data)>CaclCount:
         # 计算每个周期的主力资金流变化情况
        data['mainflow']=data['BigBuy']+data['HugeBuy']-data['BigSell']-data['HugeSell']

        for week in maList:
            columns.append(str(week))
            tmp=pd.rolling_mean(data['mainflow'][-CaclCount:],week)
            ma.append(tmp[-nLastWeeks-1:])

        #分析资金流变化情况的均线趋势  按列排序并进行比较
        pdMa=pd.DataFrame(ma,index=columns)

        for index in pdMa.columns:
            #按列进行排序，分析各点数据  大到小排序
            tmp=pdMa[index].tolist()
            if tmp!=sorted(tmp,reverse = True):
                bRet=False
                break;
    else:
        bRet=False

    return bRet




#//必须固定为17字节数据，采用结构体单字节对齐方式
#typedef struct tagL2TICKS {
#	int m_nTime, m_nIndex;       //时间、成交笔序号
#	int m_nPriceMul1000, m_nVols;//价格*1000，成交股数
#	char m_nBS;                  //成交方向：2买  1卖 0 竞价？
#}L2TICKS;    
#nTime,nIndex,nPrice1000,nVol,cBS
def read_ticks(tickfilepath):
    columns=['Time','Index','PriceMul1000','Vol','BS']
    f = open(tickfilepath,'rb')
    filedata = f.read()
    filesize = f.tell()
    f.close()
    dataSize=17
    tickCount=filesize/dataSize

    index=0
    series=[]

    while index < filesize:
        tick=struct.unpack_from('4i1c',filedata,index)
        series.append(tick)
        index=index+dataSize

    ticks=pd.DataFrame(series,columns=columns)
    return ticks


'''
利用掘金终端的函数读取需要的K线数据
get_bars 提取指定时间段的历史Bar数据，支持单个代码提取或多个代码组合提取。策略类和行情服务类都提供该接口。
get_bars(symbol_list, bar_type, begin_time, end_time)
        参数名	类型	说明
        symbol_list	string	证券代码, 带交易所代码以确保唯一，如SHSE.600000，同时支持多只代码
        bar_type	int	bar周期，以秒为单位，比如60即1分钟bar
        begin_time	string	开始时间, 如2015-10-30 09:30:00
        end_time	string	结束时间, 如2015-10-30 15:00:00

'''
def read_kline(symbol_list, bar_type, begin_time, end_time):
    return get_bars(symbol_list, bar_type, begin_time, end_time)
    pass
