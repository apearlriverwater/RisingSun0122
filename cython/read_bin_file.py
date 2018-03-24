
#-*- coding: utf-8 -*-
 
import struct


#//必须固定为17字节数据，采用结构体单字节对齐方式
#typedef struct tagL2TICKS {
#	int m_nTime, m_nIndex;       //时间、成交笔序号
#	int m_nPriceMul1000, m_nVols;//价格*1000，成交股数
#	char m_nBS;                  //成交方向：2买  1卖 0 竞价？
#}L2TICKS;    
#nTime,nIndex,nPrice1000,nVol,cBS
def read_ticks(tickfilepath,ticks):
    f = open(tickfilepath,'rb')
    filedata = f.read()
    filesize = f.tell()
    f.close()
    tickCount=filesize/17
    print('ticks count :', tickCount)
    index=0

    while index < filesize:
        tick=struct.unpack_from('4i1c',filedata,index)
        ticks.append(tick)
        index=index+17


