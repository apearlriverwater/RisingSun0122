

//当日实时资金流信息预处理  数据格式已清楚
char __thiscall CDataMgr::PreProcMoneyFlowData(CDataMgr *this, char a2, char a3, int a4, signed int a5, int a6, _DWORD *a7, int a8)
{
  char result; // al
  _DWORD *v9; // ST1A4_4
  LightLogger::CLogger *v10; // eax
  LightLogger::CLogger *v11; // eax
  _DWORD *v12; // ST1A0_4
  LightLogger::CLogger *v13; // eax
  float v14; // ST19C_4
  float v15; // ST190_4
  float v16; // ST188_4
  char v17; // al
  double v18; // st7
  int v19; // eax
  float v20; // ST14C_4
  float v21; // ST138_4
  float v22; // ST100_4
  float v23; // STEC_4
  float v24; // ST94_4
  float v25; // ST80_4
  float v26; // ST68_4
  float v27; // ST54_4
  int v28; // esi
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // ST38_4
  int v35; // eax
  LightLogger::CLogger *v36; // eax
  char v37; // [esp+30h] [ebp-AECh]
  int v38; // [esp+3Ch] [ebp-AE0h]
  int v39; // [esp+40h] [ebp-ADCh]
  signed int v40; // [esp+194h] [ebp-988h]
  CDataMgr *v41; // [esp+1A8h] [ebp-974h]
  int v42; // [esp+1B0h] [ebp-96Ch]
  int v43; // [esp+1B8h] [ebp-964h]
  char v44; // [esp+1C0h] [ebp-95Ch]
  char v45; // [esp+1C8h] [ebp-954h]
  int v46; // [esp+1CCh] [ebp-950h]
  int v47; // [esp+1D0h] [ebp-94Ch]
  struct STK_PER *v48; // [esp+1D4h] [ebp-948h]
  int i; // [esp+1D8h] [ebp-944h]
  char v50[4]; // [esp+1DFh] [ebp-93Dh]
  char v51; // [esp+1E8h] [ebp-934h]
  char v52; // [esp+1ECh] [ebp-930h]
  struct CListCompressIf *v53; // [esp+1F0h] [ebp-92Ch]
  char v54; // [esp+1F4h] [ebp-928h]
  int v55; // [esp+1F8h] [ebp-924h]
  char v56; // [esp+1FCh] [ebp-920h]
  wchar_t v57; // [esp+200h] [ebp-91Ch]
  char v58; // [esp+A00h] [ebp-11Ch]
  char Dst; // [esp+A08h] [ebp-114h]
  char v60; // [esp+A18h] [ebp-104h]
  float v61; // [esp+A19h] [ebp-103h]
  float v62; // [esp+A1Dh] [ebp-FFh]
  double v63; // [esp+A21h] [ebp-FBh]
  double v64; // [esp+A29h] [ebp-F3h]
  double v65; // [esp+A31h] [ebp-EBh]
  double v66; // [esp+A39h] [ebp-E3h]
  float v67; // [esp+A41h] [ebp-DBh]
  double v68; // [esp+A45h] [ebp-D7h]
  float v69; // [esp+A4Dh] [ebp-CFh]
  double v70; // [esp+A51h] [ebp-CBh]
  double v71; // [esp+A59h] [ebp-C3h]
  double v72; // [esp+A61h] [ebp-BBh]
  float v73; // [esp+A69h] [ebp-B3h]
  double v74; // [esp+A6Dh] [ebp-AFh]
  float v75; // [esp+A75h] [ebp-A7h]
  double v76; // [esp+A79h] [ebp-A3h]
  double v77; // [esp+A81h] [ebp-9Bh]
  double v78; // [esp+A89h] [ebp-93h]
  float v79; // [esp+A91h] [ebp-8Bh]
  double v80; // [esp+A95h] [ebp-87h]
  float v81; // [esp+A9Dh] [ebp-7Fh]
  double v82; // [esp+AA1h] [ebp-7Bh]
  double v83; // [esp+AA9h] [ebp-73h]
  double v84; // [esp+AB1h] [ebp-6Bh]
  float v85; // [esp+AB9h] [ebp-63h]
  double v86; // [esp+ABDh] [ebp-5Fh]
  float v87; // [esp+AC5h] [ebp-57h]
  char v88; // [esp+AD3h] [ebp-49h]
  int v89; // [esp+AD4h] [ebp-48h]
  char v90; // [esp+AD8h] [ebp-44h]
  char v91; // [esp+AD9h] [ebp-43h]
  __int64 v92; // [esp+ADAh] [ebp-42h]
  char v93; // [esp+AE4h] [ebp-38h]
  char Src; // [esp+AF4h] [ebp-28h]
  char v95[4]; // [esp+AF5h] [ebp-27h]
  int v96; // [esp+AF9h] [ebp-23h]
  int v97; // [esp+AFDh] [ebp-1Fh]
  __int16 v98; // [esp+B01h] [ebp-1Bh]
  char v99; // [esp+B03h] [ebp-19h]
  DWORD v100; // [esp+B08h] [ebp-14h]
  int v101; // [esp+B0Ch] [ebp-10h]  股票总数，可分市场：上海、深圳？
  int v102; // [esp+B18h] [ebp-4h]

  v41 = this;
  if ( !a4 )
    return 0;
  LightLogger::CLogger::GetLogger(&v52, L"PushMoneyFlow");
  v102 = 0;
  v9 = (_DWORD *)sub_73AF190(&v45, a3);
  sub_712E590(&v57, L"start pushstatus:%s IncrementId:%d", *v9);
  mfc80xU_577(&v45);
  v10 = (LightLogger::CLogger *)unknown_libname_96(&v52);
  LightLogger::CLogger::WriteLogLine(v10, &v57, 10000);
  v100 = GetTickCount();
  v53 = CDataMgr::GetListCompressPtr(v41, a2, a3);
  if ( v53 )
  {
    if ( a4 && a5 >= 1 )
    {
      v55 = 0;
      v101 = 0;
      v88 = 0;
      //call  sub_4ED4CA0(char *this, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6)  a4资金流数据指针  截获数据？？
      //&v55资金流数据指针, &v101股票数
      /*  修改下列代码实现跳转，直接获取当前资金流情况数据
      .text:0507DC66 loc_507DC66:                            ; CODE XREF: CDataMgr::PreProcMoneyFlowData(uint,char,char *,int,std::vector<MainCapFlowShowDetailClientPaid,std::allocator<MainCapFlowShowDetailClientPaid>> &,ulong &,int)+119↑j
.text:0507DC66 mov     [ebp+var_924], 0
.text:0507DC70 mov     [ebp+var_10], 0
.text:0507DC77 mov     [ebp+var_49], 0
.text:0507DC7B lea     ecx, [ebp+var_49]
.text:0507DC7E push    ecx
.text:0507DC7F lea     edx, [ebp+var_10]
.text:0507DC82 push    edx
.text:0507DC83 lea     eax, [ebp+var_924]
.text:0507DC89 push    eax
.text:0507DC8A mov     ecx, dword ptr [ebp+arg_C]
.text:0507DC8D push    ecx
.text:0507DC8E mov     edx, [ebp+arg_8]
.text:0507DC91 push    edx                             ; char
.text:0507DC92 mov     eax, [ebp+var_92C]
.text:0507DC98 mov     edx, [eax]
.text:0507DC9A mov     ecx, [ebp+var_92C]
.text:0507DCA0 mov     eax, [edx+38h]
.text:0507DCA3 call    eax*/
      if ( (*(unsigned __int8 (__thiscall **)(struct CListCompressIf *, int, signed int, int *, int *, char *))(*(_DWORD *)v53 + 56))(
             v53,
             a4,
             a5,
             &v55,
             &v101,
             &v88) )
      {
        if ( v55 && v101 >= 1 )
        {
          sub_718F530(&v58);
          v12 = (_DWORD *)sub_718F3D0(&v44, "%H:%M:%S");
          GetTickCount();
          sub_712E590(&v57, L"curtime:%s buffersize:%d stocknum:%d uncompresstime:%d", *v12);
          mfc80xU_577(&v44);
          v13 = (LightLogger::CLogger *)unknown_libname_96(&v52);
          LightLogger::CLogger::WriteLogLine(v13, &v57, 10000);
          sub_7230250(&v93);
          LOBYTE(v102) = 1;
          Src = 0;
          *(_DWORD *)v95 = 0;
          v96 = 0;
          v97 = 0;
          v98 = 0;
          v99 = 0;
          v50[0] = 0;
          v50[1] = 0;
          *(_DWORD *)&v50[2] = 0;
          for ( i = 0; i < v101; ++i )
          {
            v47 = v55 + 92 * i;
            sub_748F6E0(*(_DWORD *)(v55 + 92 * i), &Src, (int)v50);
            v48 = QDataEngine::App_OneStkInfo(&Src, v50[0]);  获取股票数据指针，第一字节起股票名字汉字
            if ( v48 )
            {
              if ( !*(_DWORD *)((char *)v48 + 85) )
              {
                sub_74A7740();
                sub_74A8420(1, (int)v48);
              }
              if ( *(_DWORD *)((char *)v48 + 85) )
              {
                v90 = v50[0];
                v14 = *(float *)(*(_DWORD *)((char *)v48 + 85) + 70) - *(float *)(v47 + 4);
                if ( log(v14) >= 0.001 )
                {
                  v91 = 1;
                  v89 = *(unsigned __int16 *)((char *)v48 + 69);
                  if ( *(float *)(v47 + 4) * 1000.0 <= 0.0 )
                    v40 = (signed int)(*(float *)(v47 + 4) * 1000.0 - 0.5);
                  else
                    v40 = (signed int)(*(float *)(v47 + 4) * 1000.0 + 0.5);
                  v92 = v40;
                  sub_722D2A0(&v89);
                }
                
                *(float *)(*(_DWORD *)((char *)v48 + 85) + 70) = *(float *)(v47 + 4);
                *(float *)(*(_DWORD *)((char *)v48 + 85) + 54) = *(float *)(v47 + 8);
                strcpy_s(&Dst, 0x10u, &Src);  复制股票代码
                v60 = v50[0];
                v61 = *(float *)(v47 + 4);  最新价
                v15 = *(float *)(v47 + 8) - 0.0;
                if ( log(v15) >= 0.001 && (v16 = *(float *)(v47 + 4) - 0.0, log(v16) >= 0.001) )
                {
                  v17 = sub_748FAD0(v50[0], &Src);
                  v18 = v61;
                  sub_748F640(v61, *(float *)(v47 + 8), v17);
                  v62 = v18;   当前涨幅
                  *(float *)(*(_DWORD *)((char *)v48 + 85) + 174) = v62;
                }
                else
                {
                  v62 = 0.0;
                  *(float *)(*(_DWORD *)((char *)v48 + 85) + 174) = 0.0;
                }
                if ( v50[0] == 90 )
                {
                  sub_7239EF0(&v50[1], &v95[1], 5u);
                  v19 = atoi(&v50[1]);
                  v46 = CDataMgr::GetBkStockListById(v41, v19, 0);
                  if ( v46 )
                  {
                    *(float *)(v46 + 117) = *(float *)(v47 + 4);
                    *(float *)(v46 + 133) = *(float *)(v47 + 8);
                    *(float *)(v46 + 177) = *(float *)(*(_DWORD *)((char *)v48 + 85) + 174);
                  }
                }
                v63 = (double)*(unsigned __int64 *)(v47 + 20);  集合竞价成交金额（单位元）
                v64 = (double)*(unsigned __int64 *)(v47 + 28);  小单入 元
                v65 = (double)*(unsigned __int64 *)(v47 + 36);  小单出 元
                v66 = v64 + v65;  小单总额
                v68 = v64 - v65;  小单净入，入为正
                if ( *(_DWORD *)(v47 + 12) || *(_DWORD *)(v47 + 16) )
                {
                  v20 = v66;
                  v67 = v20 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12);  小单占比
                  v21 = v68;
                  v69 = v21 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12);  小单占比
                }
                else
                {
                  v67 = 0.0;
                  v69 = 0.0;
                }
                v70 = (double)*(unsigned __int64 *)(v47 + 44);  中单入 元
                v71 = (double)*(unsigned __int64 *)(v47 + 52);  中单出 元
                v72 = v70 + v71;  中单总额
                v74 = v70 - v71;  中单净入，入为正
                if ( *(_DWORD *)(v47 + 12) || *(_DWORD *)(v47 + 16) )
                {
                  v22 = v72;
                  v73 = v22 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12); 中单占比
                  v23 = v74;
                  v75 = v23 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12);  中单净占比
                }
                else
                {
                  v73 = 0.0;
                  v75 = 0.0;
                }
                
                 v76 = (double)*(unsigned __int64 *)(v47 + 60);大入
                v77 = (double)*(unsigned __int64 *)(v47 + 68);大出
                v78 = v76 + v77;大单总额
                v80 = v76 - v77;大单总额
                if ( *(_DWORD *)(v47 + 12) || *(_DWORD *)(v47 + 16) )
                {
                  v26 = v78;
                  v79 = v26 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12); 大单占比
                  v27 = v80;
                  v81 = v27 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12); 大单净占比
                }
                else
                {
                  v79 = 0.0;
                  v81 = 0.0;
                }
                
               
                v82 = (double)*(unsigned __int64 *)(v47 + 76);超大入
                v83 = (double)*(unsigned __int64 *)(v47 + 84);超大出
                v84 = v82 + v83;   超大单总额
                v86 = v82 - v83;   超大单总额
                if ( *(_DWORD *)(v47 + 12) || *(_DWORD *)(v47 + 16) )
                {
                  v24 = v84;
                  v85 = v24 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12);  超大单占比  ？？大单也是 (v47 + 12)
                  v25 = v86;
                  v87 = v25 * 100.0 / (double)*(unsigned __int64 *)(v47 + 12);  超大单净占比 
                  
                }
                else
                {
                  v85 = 0.0;
                  v87 = 0.0;
                }
                
                sub_722EB80(&Dst);  //应该是结果保存？？
              }
            }
          }//for ( i = 0; i < v101; ++i )
          
          v43 = mfc80xU_762(40);
          LOBYTE(v102) = 2;
          if ( v43 )
            v39 = sub_722EB10(v43);
          else
            v39 = 0;
          LOBYTE(v102) = 1;
          sub_722E5E0(v39);
          LOBYTE(v102) = 3;
          v42 = mfc80xU_762(28);
          if ( v42 )
            v38 = sub_718CDE0(v42);
          else
            v38 = 0;
          sub_722E5E0(v38);
          LOBYTE(v102) = 4;
          CGlobalEnv::GetGlobalEnv(&v54);
          LOBYTE(v102) = 5;
          v28 = sub_714D4E0(&v93);
          v29 = unknown_libname_96(&v51);
          *(_DWORD *)(unknown_libname_89(v29) + 8) = v28;
          v30 = unknown_libname_96(&v51);
          unknown_libname_89(v30);
          sub_722D110(&v93);
          v31 = unknown_libname_96(&v51);
          *(_DWORD *)unknown_libname_89(v31) = a8 / 10000;
          v32 = unknown_libname_96(&v51);
          *(_DWORD *)(unknown_libname_89(v32) + 4) = a8 % 10000;
          v33 = unknown_libname_96(&v56);
          unknown_libname_89(v33);
          sub_7197300(&v51);
          v34 = unknown_libname_96(&v54);
          v35 = unknown_libname_96(&v56);
          *a7 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v34 + 36))(v34, v35);
          sub_712E590(&v57, L"end", v37);
          v36 = (LightLogger::CLogger *)unknown_libname_96(&v52);
          LightLogger::CLogger::WriteLogLine(v36, &v57, 10000);
          LOBYTE(v102) = 4;
          sub_722C780(&v54);
          LOBYTE(v102) = 3;
          sub_722C780(&v56);
          LOBYTE(v102) = 1;
          sub_722C780(&v51);
          LOBYTE(v102) = 0;
          sub_7230280(&v93);
          v102 = -1;
          sub_722C780(&v52);
          result = 1;
        }
        else
        {
          v102 = -1;
          sub_722C780(&v52);
          result = 0;
        }
      }
      else
      {
        v102 = -1;
        sub_722C780(&v52);
        result = 0;
      }
    }
    else
    {
      sub_712E590(&v57, L"data addr is null or data len is:%d", a5);
      v11 = (LightLogger::CLogger *)unknown_libname_96(&v52);
      LightLogger::CLogger::WriteLogLine(v11, &v57, 10000);
      v102 = -1;
      sub_722C780(&v52);
      result = 0;
    }
  }
  else
  {
    v102 = -1;
    sub_722C780(&v52);
    result = 0;
  }
  return result;
}

//a4资金流数据指针  a5股票数
char __thiscall sub_4ED4CA0(char *this, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6)
{
  char *v6; // ebx
  int v7; // eax
  _DWORD *v8; // esi
  char result; // al
  char v10; // [esp+10h] [ebp-8h]

  if ( !a2 )
    return 0;
  if ( a3 <= 0 )
    return 0;
  v6 = this + 904;
  if ( !(unsigned __int8)sub_4ED9ED0(a3, this + 904, a6) )
    return 0;
  v7 = *((_DWORD *)v6 + 1);
  if ( v7 && (*((_DWORD *)v6 + 2) - v7) / 92 )   //计算股票数((_DWORD *)v6 + 2) - v7) / 92
  {
    v8 = sub_4ED6F60((int)v6, &v10);
    if ( !*v8 )
      invalid_parameter_noinfo();
    if ( v8[1] >= *(_DWORD *)(*v8 + 8) )
      invalid_parameter_noinfo();
    *a4 = v8[1];
    *a5 = sub_4ED6F90(v6);  //计算股票数   (*((_DWORD *)v6 + 2) - *((_DWORD *)v6 + 1)) / 92
    result = 1;
  }
  else
  {
    *a4 = 0;
    *a5 = 0;
    result = 1;
  }
  return result;
}

//添加实时资金流信息
int __cdecl QDataEngine::Add_MoneyFlowDetailDataStockPaid(char a1, char *szStockCode, struct MainCapFlowShowDetailClientPaid *a3, int a4)
{
  QDataEngine::GetNameTableRef(szStockCode);
  return (unsigned __int8)sub_747AAB0(a1, szStockCode, (int)a3, a4);
}
//添加实时资金流信息，被QDataEngine::Add_MoneyFlowDetailDataStockPaid调用
char __stdcall sub_747AAB0(char a1, char *szStockCode, int a3, int a4)
{
  char result; // al
  struct STK_PER *v5; // [esp+8h] [ebp-4h]

  v5 = QDataEngine::App_OneStkInfo(szStockCode, a1);
  if ( !v5 )
    return 0;
  switch ( a4 )
  {
    case 1:
      if ( *(_DWORD *)((char *)v5 + 133) || (sub_74A7740(), sub_74A8420(13, v5)) )
      {
        if ( *(_DWORD *)((char *)v5 + 133) )
        { // 实时资金流向汇总表20180102  把所有浮点数打印处理结合显示即可情况个字段的意义  字段长度176字节
        	/*
        	最新0x00=1.292000007629395e1,
					涨幅%0x04=-2.339999914169312,
					集合竞价0x08=6.09269e5,
					
					超大单流入0x88=4.804854e6,
					超大单流出0x90=5.867869e6,
					超大单净额0xa4=-1.063015e6,
					超大单净占比%0xac=-2.472244501113892
					
					大单流入0x60=8.26447e6,
					大单流出0x68=2.0104722e7,
					大单净额0x7c=-1.1840252e7,
					大单净占比%0x84=-2.753676795959473e1,
					
					中单流入56=1.6772989e7,
					中单流出64=8.830513e6,
					中单净额84=7.942476e6,
					中单净占比%92=1.847174644470215e1
					
					小单流入16=1.2546388e7,
					小单流出24=7.585597e6,
					小单净额44=4.960791e6,
					小单净占比%52=1.153726768493652e1,
					
					
					32=2.0131985e7,
					40=4.682077407836914e1,
					72=2.5603502e7,
					80=5.954583740234375e1,
					0x70=2.8369192e7,
					0x78=6.597797393798828e1,
					0x98=1.0672723e7,
					0xa0=2.482145690917969e1,
        	*/
          **(float **)(          (char *)v5 + 133) = *(float *)(a3 + 17);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 4) = *(float *)(a3 + 21);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 8) = *(double *)(a3 + 25);
          
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 16) = *(double *)(a3 + 33);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 24) = *(double *)(a3 + 41);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 32) = *(double *)(a3 + 49);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 40) = *(float *)(a3 + 57);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 44) = *(double *)(a3 + 61);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 52) = *(float *)(a3 + 69);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 56) = *(double *)(a3 + 73);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 64) = *(double *)(a3 + 81);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 72) = *(double *)(a3 + 89);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 80) = *(float *)(a3 + 97);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 84) = *(double *)(a3 + 101);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 92) = *(float *)(a3 + 109);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 96) = *(double *)(a3 + 113);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 104) = *(double *)(a3 + 121);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 112) = *(double *)(a3 + 129);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 120) = *(float *)(a3 + 137);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 124) = *(double *)(a3 + 141);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 132) = *(float *)(a3 + 149);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 136) = *(double *)(a3 + 153);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 144) = *(double *)(a3 + 161);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 152) = *(double *)(a3 + 169);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 160) = *(float *)(a3 + 177);
          *(double *)(*(_DWORD *)((char *)v5 + 133) + 164) = *(double *)(a3 + 181);
          *(float *)(*(_DWORD *)((char *)v5 + 133) + 172) = *(float *)(a3 + 189);
          
          
          goto LABEL_24;
        }
      }
      result = 0;
      break;
    case 3:
      if ( *(_DWORD *)((char *)v5 + 137) || (sub_74A7740(), sub_74A8420(14, v5)) )
      {
        if ( *(_DWORD *)((char *)v5 + 137) )
        {
          **(float **)          ((char *)v5 + 137) = *(float *)(a3 + 17);           最新价
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 4) = *(float *)(a3 + 21);      涨幅%
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 8) = *(double *)(a3 + 25);		集合竞价元
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 16) = *(double *)(a3 + 33);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 24) = *(double *)(a3 + 41);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 32) = *(double *)(a3 + 49);
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 40) = *(float *)(a3 + 57);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 44) = *(double *)(a3 + 61);
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 52) = *(float *)(a3 + 69);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 56) = *(double *)(a3 + 73);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 64) = *(double *)(a3 + 81);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 72) = *(double *)(a3 + 89);
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 80) = *(float *)(a3 + 97);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 84) = *(double *)(a3 + 101);		中单净额
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 92) = *(double *)(a3 + 101);		？？？？  中单净占比%
          
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 96) = *(double *)(a3 + 113);		大单流入
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 104) = *(double *)(a3 + 121);		大单流出
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 112) = *(double *)(a3 + 129);		中单流入
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 120) = *(float *)(a3 + 137);			中单流出
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 124) = *(double *)(a3 + 141);		大单净额
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 132) = *(float *)(a3 + 149);
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 136) = *(double *)(a3 + 153);		超大单流入元
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 144) = *(double *)(a3 + 161);		超大单流出元
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 152) = *(double *)(a3 + 169);   ？？？
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 160) = *(float *)(a3 + 177);     ？？？？
          *(double *)(*(_DWORD *)((char *)v5 + 137) + 164) = *(double *)(a3 + 181);   超大单净额 
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 172) = *(float *)(a3 + 189);
          
          002065,最新0x00=8.420000076293945,涨幅%0x04=-4.699999988079071e-1,
集合竞价0x08=2.54718e6,？？？0x98=1.3822521e7,超大单流入0x88=2.694402e6,
超大单流出0x90=1.1128119e7,0xa0=7.837285995483398,
超大单净额0xa4=-8.433717e6,超大单净占比%0xac=-4.781866550445557
中单流入0x70=9.4172874e7,大单流入0x60=3.4055213e7,
大单流出0x68=6.0117661e7,中单流出0x78=5.339545059204102e1,
大单净额0x7c=-2.6062448e7,大单净占比%0x84=-1.477725028991699e1,
中单净额0x54=1.0730908e7,中单净占比%0x5c=6.084360122680664
          
          
          
          
          *(float *)(*(_DWORD *)((char *)v5 + 137) + 92) = *(float *)(a3 + 109);
          goto LABEL_24;
        }
      }
      result = 0;
      break;
    case 5:
      if ( *(_DWORD *)((char *)v5 + 141) || (sub_74A7740(), sub_74A8420(15, v5)) )
      {
        if ( *(_DWORD *)((char *)v5 + 141) )
        {
          **(float **)((char *)v5 + 141) = *(float *)(a3 + 17);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 4) = *(float *)(a3 + 21);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 8) = *(double *)(a3 + 25);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 152) = *(double *)(a3 + 169);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 136) = *(double *)(a3 + 153);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 144) = *(double *)(a3 + 161);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 160) = *(float *)(a3 + 177);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 164) = *(double *)(a3 + 181);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 172) = *(float *)(a3 + 189);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 112) = *(double *)(a3 + 129);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 96) = *(double *)(a3 + 113);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 104) = *(double *)(a3 + 121);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 120) = *(float *)(a3 + 137);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 124) = *(double *)(a3 + 141);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 132) = *(float *)(a3 + 149);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 32) = *(double *)(a3 + 49);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 16) = *(double *)(a3 + 33);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 24) = *(double *)(a3 + 41);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 40) = *(float *)(a3 + 57);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 44) = *(double *)(a3 + 61);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 52) = *(float *)(a3 + 69);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 72) = *(double *)(a3 + 89);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 56) = *(double *)(a3 + 73);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 64) = *(double *)(a3 + 81);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 80) = *(float *)(a3 + 97);
          *(double *)(*(_DWORD *)((char *)v5 + 141) + 84) = *(double *)(a3 + 101);
          *(float *)(*(_DWORD *)((char *)v5 + 141) + 92) = *(float *)(a3 + 109);
          goto LABEL_24;
        }
      }
      result = 0;
      break;
    case 10:
      if ( *(_DWORD *)((char *)v5 + 145) || (sub_74A7740(), sub_74A8420(16, v5)) )
      {
        if ( *(_DWORD *)((char *)v5 + 145) )
        {
          **(float **)((char *)v5 + 145) = *(float *)(a3 + 17);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 4) = *(float *)(a3 + 21);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 8) = *(double *)(a3 + 25);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 152) = *(double *)(a3 + 169);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 136) = *(double *)(a3 + 153);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 144) = *(double *)(a3 + 161);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 160) = *(float *)(a3 + 177);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 164) = *(double *)(a3 + 181);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 172) = *(float *)(a3 + 189);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 112) = *(double *)(a3 + 129);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 96) = *(double *)(a3 + 113);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 104) = *(double *)(a3 + 121);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 120) = *(float *)(a3 + 137);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 124) = *(double *)(a3 + 141);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 132) = *(float *)(a3 + 149);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 32) = *(double *)(a3 + 49);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 16) = *(double *)(a3 + 33);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 24) = *(double *)(a3 + 41);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 40) = *(float *)(a3 + 57);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 44) = *(double *)(a3 + 61);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 52) = *(float *)(a3 + 69);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 72) = *(double *)(a3 + 89);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 56) = *(double *)(a3 + 73);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 64) = *(double *)(a3 + 81);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 80) = *(float *)(a3 + 97);
          *(double *)(*(_DWORD *)((char *)v5 + 145) + 84) = *(double *)(a3 + 101);
          *(float *)(*(_DWORD *)((char *)v5 + 145) + 92) = *(float *)(a3 + 109);
          goto LABEL_24;
        }
      }
      result = 0;
      break;
    default:
LABEL_24:
      result = 1;
      break;
  }
  return result;
}


//没找到规律，暂时放弃20180101
//确定了近期增仓比列20180102
char __thiscall CDataMgr::ProcT0MoneyFlowData(CDataMgr *this, int a2, int a3)
{
  char result; // al
  LightLogger::CLogger *v4; // eax
  LightLogger::CLogger *v5; // eax
  int v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  float v11; // ST50_4
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  float v18; // ST44_4
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  float v25; // ST38_4
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  float v32; // ST2C_4
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // [esp+58h] [ebp-3E4h]
  CDataMgr *v52; // [esp+5Ch] [ebp-3E0h]
  int v53; // [esp+64h] [ebp-3D8h]
  char v54; // [esp+70h] [ebp-3CCh]
  unsigned __int8 v55[517]; // [esp+77h] [ebp-3C5h]
  struct CListCompressIf *v56; // [esp+27Ch] [ebp-1C0h]
  char v57; // [esp+280h] [ebp-1BCh]
  double v58; // [esp+2A0h] [ebp-19Ch]
  double v59; // [esp+2A8h] [ebp-194h]
  double v60; // [esp+2B0h] [ebp-18Ch]
  double v61; // [esp+2B8h] [ebp-184h]
  double v62; // [esp+2C0h] [ebp-17Ch]
  __int16 v63; // [esp+2C8h] [ebp-174h]
  char v64; // [esp+2CCh] [ebp-170h]
  double v65; // [esp+2ECh] [ebp-150h]
  double v66; // [esp+2F4h] [ebp-148h]
  double v67; // [esp+2FCh] [ebp-140h]
  double v68; // [esp+304h] [ebp-138h]
  double v69; // [esp+30Ch] [ebp-130h]
  __int16 v70; // [esp+314h] [ebp-128h]
  char v71; // [esp+318h] [ebp-124h]
  double v72; // [esp+338h] [ebp-104h]
  double v73; // [esp+340h] [ebp-FCh]
  double v74; // [esp+348h] [ebp-F4h]
  double v75; // [esp+350h] [ebp-ECh]
  double v76; // [esp+358h] [ebp-E4h]
  __int16 v77; // [esp+360h] [ebp-DCh]
  char v78; // [esp+364h] [ebp-D8h]
  double v79; // [esp+384h] [ebp-B8h]
  double v80; // [esp+38Ch] [ebp-B0h]
  double v81; // [esp+394h] [ebp-A8h]
  double v82; // [esp+39Ch] [ebp-A0h]
  double v83; // [esp+3A4h] [ebp-98h]
  __int16 v84; // [esp+3ACh] [ebp-90h]
  double v85; // [esp+3B0h] [ebp-8Ch]
  char v86; // [esp+3B8h] [ebp-84h]
  char v87; // [esp+3D8h] [ebp-64h]
  char v88; // [esp+3F8h] [ebp-44h]
  char v89; // [esp+408h] [ebp-34h]
  char Src; // [esp+418h] [ebp-24h]
  int v91; // [esp+419h] [ebp-23h]
  int v92; // [esp+41Dh] [ebp-1Fh]
  int v93; // [esp+421h] [ebp-1Bh]
  __int16 v94; // [esp+425h] [ebp-17h]
  char v95; // [esp+427h] [ebp-15h]
  char v96; // [esp+42Ch] [ebp-10h]
  int v97; // [esp+438h] [ebp-4h]

  v52 = this;
  if ( !a2 )
    return 0;
  v56 = CDataMgr::GetListCompressPtr(this, *(_DWORD *)(a2 + 17), *(_BYTE *)(a2 + 21));
  if ( !v56 )
    return 0;
  LightLogger::CLogger::GetLogger(&v96, L"ProcT0MoneyFlow");
  v97 = 0;
  if ( a2 == -30 || *(_DWORD *)(a2 + 26) < 1u )
  {
    sub_4D8E590((wchar_t *)&v55[1], L"data addr is null or data len is:%d", *(_DWORD *)(a2 + 26));
    v4 = (LightLogger::CLogger *)unknown_libname_96(&v96);
    LightLogger::CLogger::WriteLogLine(v4, (const wchar_t *)&v55[1], 10000);
  }
  sub_4D8E590((wchar_t *)&v55[1], L"data len is:%d", *(_DWORD *)(a2 + 26));
  v5 = (LightLogger::CLogger *)unknown_libname_96(&v96);
  LightLogger::CLogger::WriteLogLine(v5, (const wchar_t *)&v55[1], 10000);
  sub_4E8C4D0(&v57);
  if ( (*(unsigned __int8 (__thiscall **)(struct CListCompressIf *, int, _DWORD, char *))(*(_DWORD *)v56 + 40))(
         v56,
         a2 + 30,
         *(_DWORD *)(a2 + 26),
         &v57) )
  {
    Src = 0;
    v91 = 0;
    v92 = 0;
    v93 = 0;
    v94 = 0;
    v95 = 0;
    v55[0] = 0;
    sub_50F00A0(*(_DWORD *)(a2 + 22), &Src, (int)v55);
    if ( (signed int)v55[0] >= 0 )
    { //ecx  能看到股票代码
      EnterCriticalSection((LPCRITICAL_SECTION)((char *)v52 + 242));
      if ( sub_4DD2EA0((char *)v52 + 649) )
      {
        v53 = mfc80xU_762(416);
        if ( v53 )
          v51 = sub_4E8EC60(v53);
        else
          v51 = 0;
          
        sub_4E8E5E0(v51);
        v6 = unknown_libname_96(&v54);
        v7 = (_BYTE *)unknown_libname_89(v6);
        *v7 = v55[0];
        v8 = unknown_libname_96(&v54);
        v9 = unknown_libname_89(v8);
        sub_4E11460((char *)(v9 + 1), &Src);
        if ( fabs(v62 - 0.0) >= 0.001 )
        {
          v11 = (v60 + v58 - v61 - v59) * 100.0 / v62;
          v12 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v12) + 17) = v11;//当日增仓比
        }
        else
        {
          v10 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v10) + 17) = 0.0;
        }
        
        v13 = unknown_libname_96(&v54);
        v14 = unknown_libname_89(v13);
        *(_WORD *)(v14 + 21) = v63;  //当日增仓排名
        v15 = unknown_libname_96(&v54);
        v16 = unknown_libname_89(v15);
        memcpy((void *)(v16 + 23), &v57, 0x40u);
        if ( fabs(v69 - 0.0) >= 0.001 )
        {
          v18 = (v67 + v65 - v68 - v66) * 100.0 / v69;
          v19 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v19) + 87) = v18; //3日增仓比
        }
        else
        {
          v17 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v17) + 87) = 0.0;
        }
        v20 = unknown_libname_96(&v54);
        v21 = unknown_libname_89(v20);
        *(_WORD *)(v21 + 91) = v70;  //3日增仓排名
        v22 = unknown_libname_96(&v54);
        v23 = unknown_libname_89(v22);
        memcpy((void *)(v23 + 93), &v64, 0x40u);
        if ( fabs(v76 - 0.0) >= 0.001 )
        {
          v25 = (v74 + v72 - v75 - v73) * 100.0 / v76;
          v26 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v26) + 157) = v25;//5日增仓比
        }
        else
        {
          v24 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v24) + 157) = 0.0;
        }
        v27 = unknown_libname_96(&v54);
        v28 = unknown_libname_89(v27);
        *(_WORD *)(v28 + 161) = v77;    //5日增仓排名
        v29 = unknown_libname_96(&v54);
        v30 = unknown_libname_89(v29);
        memcpy((void *)(v30 + 163), &v71, 0x40u);
        if ( fabs(v83 - 0.0) >= 0.001 )
        {
          v32 = (v81 + v79 - v82 - v80) * 100.0 / v83;
          v33 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v33) + 227) = v32;//10日增仓比
        }
        else
        {
          v31 = unknown_libname_96(&v54);
          *(float *)(unknown_libname_89(v31) + 227) = 0.0;
        }
        v34 = unknown_libname_96(&v54);
        v35 = unknown_libname_89(v34);
        *(_WORD *)(v35 + 231) = v84;//10日增仓排名
        v36 = unknown_libname_96(&v54);
        v37 = unknown_libname_89(v36);
        memcpy((void *)(v37 + 233), &v78, 0x40u);
        v38 = unknown_libname_96(&v54);
        v39 = unknown_libname_89(v38);
        *(double *)(v39 + 297) = v85;   //不明用途？？
        v40 = unknown_libname_96(&v54);
        v41 = unknown_libname_89(v40);
        memcpy((void *)(v41 + 305), &v86, 0x20u);
        v42 = unknown_libname_96(&v54);
        v43 = unknown_libname_89(v42);
        memcpy((void *)(v43 + 337), &v87, 0x20u);
        v44 = unknown_libname_96(&v54);
        v45 = unknown_libname_89(v44);
        memcpy((void *)(v45 + 369), &v88, 0x10u);
        v46 = unknown_libname_96(&v54);
        v47 = unknown_libname_89(v46);
        memcpy((void *)(v47 + 385), &v89, 0x10u);
        v48 = unknown_libname_96((void *)a3);
        *(_DWORD *)(unknown_libname_89(v48) + 4) = 0;
        v49 = unknown_libname_96((void *)a3);
        *(_DWORD *)unknown_libname_89(v49) = 8209;
        v50 = unknown_libname_96((void *)a3);
        unknown_libname_89(v50);
        sub_4DF7300(&v54);
        sub_4E8C780(&v54);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v52 + 242));
      v97 = -1;
      sub_4E8C780(&v96);
      result = 1;
    }
    else
    {
      v97 = -1;
      sub_4E8C780(&v96);
      result = 0;
    }
  }
  else
  {
    v97 = -1;
    sub_4E8C780(&v96);
    result = 0;
  }
  return result;
}


//部分资金流有关的信息存在data\STOCK目录，格式待研究
168 字节资金流信息：分钟结构与各种分钟数结构类似，日线级别也是此结构
      dw  日期   交易日													4bytes     +0
      dw  时间   单位分钟												4bytes     +4 
      double 小单入，中单入，大单入，超大单入   32bytes    +8，10H，18H，20H
      double 小单出，中单出，大单出，超大单出   32bytes    +32H，30H，38H，40H
      
      疑似成交量
      qword 小单入，中单入，大单入，超大单入   32bytes     +48H，50H，58H，60H
      		esi显示偏移量，函数进入时确定的固定值
      		
          60H    var_CC
          64H    var_CC+4  LOW 31BITS,
                 MOST BIT  var_6C+4
                           var_6C    esi
                 RESULT:anonymous_2

          58H    var_BC
          5CH    var_BC+4  LOW 31BITS,
                 MOST BIT  var_7C+4
                           var_7C    esi
                 RESULT:var_4C
                 	
          50H    var_BC
          54H    var_BC+4  LOW 31BITS,
                 MOST BIT  var_F4+4
                           var_F4    esi
                 RESULT:var_B4     
                 	
          48H    var_5C
          4CH    var_5C+4  LOW 31BITS,
                 MOST BIT  var_9C+4
                           var_9C    esi
                 RESULT:var_D4    
                 	   	 	
      qword 小单出，中单出，大单出，超大单出   32bytes     +68H，70H，78H，80H
      		80H    var_EC
          84H    var_EC+4  LOW 31BITS,
                 MOST BIT  var_AC+4
                           var_AC    esi    
                 RESULT:var_44

          78H    var_DC
          7CH    var_DC+4  LOW 31BITS,
                 MOST BIT  var_64+4
                           var_64    esi
                 RESULT:var_54
                 	
          70H    var_74
          74H    var_74+4  LOW 31BITS,
                 MOST BIT  var_84+4
                           var_84    esi
                 RESULT:var_C4     
                 	
          68H    var_94
          6CH    var_94+4  LOW 31BITS,
                 MOST BIT  var_A4+4
                           var_A4    esi
                 RESULT:var_E4
      
      
      
      其余32字节内容不详                                  
          88h-97h  4word内容累加后存入anonymous_0+4转成浮点数，低四字节似乎固定，
                   若累加结果为零与某个双精度数累加dbl_9885608 dq 4.294967296e9，
                   结果：var_FC
          98h-a7h  4word内容累加后存入anonymous_0+4转成浮点数，低四字节似乎固定，
                   若累加结果为零与某个双精度数累加dbl_9885608 dq 4.294967296e9，
                   结果：	anonymous_0
      
      
      
      通过设置数据读写时产生中断从而获得数据被处理的位置。第一次中断后，
   调用msvcr80__VEC_memcpy获得需要的资金流数据。在第二次中断时
   已从服务器获得数据。

; =============== S U B R O U T I N E =======================================
?WriteCapitalFlowKLineData@QDataEngine@@SAJEW4DCYCLE@@ABV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@PAUCAPITALFLOW_DAY_ITEM_DATA@@HAAH@Z
?ReadCapitalFlowKLineData@QDataEngine@@SA_NEABV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@W4DCYCLE@@AAV?$vector@UCAPITALFLOW_DAY_ITEM_DATA@@V?$allocator@UCAPITALFLOW_DAY_ITEM_DATA@@@std@@@3@@Z     call    sub_4DA59C0
.text:04DCA010
.text:04DCA010 ; 168字节资金流信息复制
.text:04DCA010 ; THIS指针似乎包含自定义的公式，待进一步研究
.text:04DCA010 ; ebx+0x12  stock code
.text:04DCA010 ; Attributes: bp-based frame
.text:04DCA010
.text:04DCA010 sub_4DCA010     proc near               ; CODE XREF: sub_4DC59C0+96↑p
.text:04DCA010                                         ; sub_4DC9C20+B3↑p
.text:04DCA010
	/*
.text:04DCA010 var_14          = dword ptr -14h
.text:04DCA010 var_10          = dword ptr -10h
.text:04DCA010 var_C           = dword ptr -0Ch
.text:04DCA010 DstSize         = dword ptr -8
.text:04DCA010 var_4           = dword ptr -4
.text:04DCA010 arg_0           = dword ptr  8
.text:04DCA010 arg_4           = dword ptr  0Ch
.text:04DCA010 arg_8           = dword ptr  10h
.text:04DCA010 arg_C           = dword ptr  14h
.text:04DCA010
.text:04DCA010                 push    ebp
.text:04DCA011                 mov     ebp, esp
.text:04DCA013                 sub     esp, 14h
.text:04DCA016 ; 9:   v9 = this;
.text:04DCA016                 mov     [ebp+var_10], ecx
.text:04DCA019 ; 10:   sub_4FDDAD0(a4);
.text:04DCA019                 mov     ecx, [ebp+arg_8]
.text:04DCA01C                 call    sub_4DBDAD0
.text:04DCA021 ; 11:   if ( ((unsigned __int8)std::operator!=<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(v9 + 15, a3)
.text:04DCA021 ; 12:      || a2 != v9[22])
.text:04DCA021 ; 13:     && !sub_4FED2F0(a3, a2) )
.text:04DCA021                 mov     eax, [ebp+arg_4]
.text:04DCA024                 push    eax
.text:04DCA025                 mov     ecx, [ebp+var_10]
.text:04DCA028                 add     ecx, 3Ch
.text:04DCA02B                 push    ecx
.text:04DCA02C                 call    ds:??$?9_WU?$char_traits@_W@std@@V?$allocator@_W@1@@std@@YA_NABV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@0@0@Z ; std::operator!=<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &)
.text:04DCA032                 add     esp, 8
.text:04DCA035                 movzx   edx, al
.text:04DCA038                 test    edx, edx
.text:04DCA03A                 jnz     short loc_4DCA047
.text:04DCA03C                 mov     eax, [ebp+var_10]
.text:04DCA03F                 mov     ecx, [ebp+arg_0]
.text:04DCA042                 cmp     ecx, [eax+58h]
.text:04DCA045                 jz      short loc_4DCA067
.text:04DCA047
.text:04DCA047 loc_4DCA047:                            ; CODE XREF: sub_4DCA010+2A↑j
.text:04DCA047                 mov     edx, [ebp+arg_0]
.text:04DCA04A                 push    edx
.text:04DCA04B                 mov     eax, [ebp+arg_4]
.text:04DCA04E                 push    eax
.text:04DCA04F                 mov     ecx, [ebp+var_10]
.text:04DCA052                 call    sub_4DCD2F0
.text:04DCA057                 mov     [ebp+var_4], eax
.text:04DCA05A                 cmp     [ebp+var_4], 0
.text:04DCA05E                 jnz     short loc_4DCA067
.text:04DCA060 ; 15:     return 0;
.text:04DCA060                 xor     al, al
.text:04DCA062                 jmp     loc_4DCA11B
.text:04DCA067 ; ---------------------------------------------------------------------------
.text:04DCA067 ; 17:   if ( a5 >= 0 && a5 != v9[28] )
.text:04DCA067
.text:04DCA067 loc_4DCA067:                            ; CODE XREF: sub_4DCA010+35↑j
.text:04DCA067                                         ; sub_4DCA010+4E↑j
.text:04DCA067                 cmp     [ebp+arg_C], 0
.text:04DCA06B                 jl      short loc_4DCA07C
.text:04DCA06D                 mov     ecx, [ebp+var_10]
.text:04DCA070                 mov     edx, [ebp+arg_C]
.text:04DCA073                 cmp     edx, [ecx+70h]
.text:04DCA076                 jnz     loc_4DCA100
.text:04DCA07C ; 25:     if ( v9[30] >= sub_4FDDA90(v9 + 24) )
.text:04DCA07C
.text:04DCA07C loc_4DCA07C:                            ; CODE XREF: sub_4DCA010+5B↑j
.text:04DCA07C                 mov     ecx, [ebp+var_10]
.text:04DCA07F                 add     ecx, 60h
.text:04DCA082                 call    sub_4DBDA90     ; 获取资金流结构体数量
.text:04DCA087                 mov     ecx, [ebp+var_10]
.text:04DCA08A                 cmp     [ecx+78h], eax
.text:04DCA08D                 jge     short loc_4DCA09A
.text:04DCA08F ; 28:       v8 = v9[30];
.text:04DCA08F                 mov     edx, [ebp+var_10]
.text:04DCA092                 mov     eax, [edx+78h]
.text:04DCA095                 mov     [ebp+var_14], eax
.text:04DCA098                 jmp     short loc_4DCA0A8
.text:04DCA09A ; ---------------------------------------------------------------------------
.text:04DCA09A ; 26:       v8 = sub_4FDDA90(v9 + 24);
.text:04DCA09A
.text:04DCA09A loc_4DCA09A:                            ; CODE XREF: sub_4DCA010+7D↑j
.text:04DCA09A                 mov     ecx, [ebp+var_10]
.text:04DCA09D                 add     ecx, 60h
.text:04DCA0A0                 call    sub_4DBDA90     ; 获取资金流结构体数量
.text:04DCA0A5                 mov     [ebp+var_14], eax
.text:04DCA0A8 ; 29:     if ( v8 > 0 )
.text:04DCA0A8
.text:04DCA0A8 loc_4DCA0A8:                            ; CODE XREF: sub_4DCA010+88↑j
.text:04DCA0A8                 mov     ecx, [ebp+var_14]
.text:04DCA0AB                 mov     [ebp+var_C], ecx
.text:04DCA0AE                 cmp     [ebp+var_C], 0
.text:04DCA0B2                 jg      short loc_4DCA0B8
.text:04DCA0B4 ; 41:       result = 0;
.text:04DCA0B4                 xor     al, al
.text:04DCA0B6                 jmp     short loc_4DCA11B
.text:04DCA0B8 ; ---------------------------------------------------------------------------
.text:04DCA0B8 ; 31:       sub_4FE5970((void *)a4, v8);
.text:04DCA0B8
.text:04DCA0B8 loc_4DCA0B8:                            ; CODE XREF: sub_4DCA010+A2↑j
.text:04DCA0B8                 mov     edx, [ebp+var_C]
.text:04DCA0BB                 push    edx
.text:04DCA0BC                 mov     ecx, [ebp+arg_8]
.text:04DCA0BF                 call    sub_4DC5970
.text:04DCA0C4 ; 36:       memcpy_s(v7, 168 * v8, v6, 168 * v8);
.text:04DCA0C4                 mov     eax, [ebp+var_C]
.text:04DCA0C7                 imul    eax, 0A8h
.text:04DCA0CD                 mov     [ebp+DstSize], eax
.text:04DCA0D0                 mov     ecx, [ebp+DstSize]
.text:04DCA0D3                 push    ecx             ; MaxCount
.text:04DCA0D4 ; 32:       v6 = (const void *)sub_4FE11E0(v9 + 24, 0);// get data pointer(168*a2+this[1])
.text:04DCA0D4 ; 33:                                                 // 此时已获得资金流的信息
.text:04DCA0D4 ; 34:
.text:04DCA0D4                 push    0
.text:04DCA0D6                 mov     ecx, [ebp+var_10]
.text:04DCA0D9                 add     ecx, 60h        ; 调用下一个函数后获得资金流信息，缺当前股票代码
.text:04DCA0DC                 call    sub_4DC11E0     ; get data pointer(168*a2+this[1])
.text:04DCA0E1                 push    eax             ; Src
.text:04DCA0E2                 mov     edx, [ebp+DstSize]
.text:04DCA0E5                 push    edx             ; DstSize
.text:04DCA0E6 ; 34:
.text:04DCA0E6                 push    0
.text:04DCA0E8                 mov     ecx, [ebp+arg_8]
.text:04DCA0EB                 call    sub_4DC11E0     ; get data pointer(168*a2+this[1])
.text:04DCA0F0                 push    eax             ; Dst
.text:04DCA0F1                 call    ds:memcpy_s
.text:04DCA0F7 ; 37:       result = 1;
.text:04DCA0F7                 add     esp, 10h
.text:04DCA0FA                 mov     al, 1
.text:04DCA0FC                 jmp     short loc_4DCA11B
.text:04DCA0FC ; ---------------------------------------------------------------------------
.text:04DCA0FE                 db 0EBh
.text:04DCA0FF                 db  19h
.text:04DCA100 ; ---------------------------------------------------------------------------
.text:04DCA100 ; 19:     if ( v9[30] > 0 )
.text:04DCA100
.text:04DCA100 loc_4DCA100:                            ; CODE XREF: sub_4DCA010+66↑j
.text:04DCA100                 mov     eax, [ebp+var_10]
.text:04DCA103                 cmp     dword ptr [eax+78h], 0
.text:04DCA107                 jle     short loc_4DCA119
.text:04DCA109 ; 20:       sub_4FEA130(a2, a3);
.text:04DCA109                 mov     ecx, [ebp+arg_4]
.text:04DCA10C                 push    ecx
.text:04DCA10D                 mov     dl, byte ptr [ebp+arg_0]
.text:04DCA110                 push    edx
.text:04DCA111                 mov     ecx, [ebp+var_10]
.text:04DCA114                 call    sub_4DCA130
.text:04DCA119 ; 21:     result = 0;
.text:04DCA119
.text:04DCA119 loc_4DCA119:                            ; CODE XREF: sub_4DCA010+F7↑j
.text:04DCA119                 xor     al, al
.text:04DCA11B ; 44:   return result;
.text:04DCA11B
.text:04DCA11B loc_4DCA11B:                            ; CODE XREF: sub_4DCA010+52↑j
.text:04DCA11B                                         ; sub_4DCA010+A6↑j ...
.text:04DCA11B                 mov     esp, ebp
.text:04DCA11D                 pop     ebp
.text:04DCA11E                 retn    10h
*/
.text:04DCA11E sub_4DCA010     endp

// 168字节资金流信息复制     缺当前股票代码信息 
//处理实时状态下当日的资金流信息,多日实时资金流暂时未找到20180107
char __thiscall sub_4FE83E0(_DWORD *this, int a2, int a3, void *a4, int a5)
{
  char result; // al
  const void *v6; // ST08_4
  void *v7; // eax
  int v8; // [esp+0h] [ebp-14h]
  _DWORD *v9; // [esp+4h] [ebp-10h]

  v9 = this;
  sub_4FDDAD0(a4);
  if ( ((unsigned __int8)std::operator!=<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(v9 + 15, a3)
     || a2 != v9[22])
    && !sub_4FEC020(a3, a2) )
  {
    return 0;
  }
  if ( a5 >= 0 && a5 != v9[28] )
  {
    if ( v9[30] > 0 )
      sub_4FE8500(a2, a3);
    result = 0;
  }
  else
  {
    if ( v9[30] >= sub_4FDDA90(v9 + 24) )
      v8 = sub_4FDDA90(v9 + 24);
    else
      v8 = v9[30];
    if ( v8 > 0 )
    {
      sub_4FE5970(a4, v8);
      v6 = (const void *)sub_4FE11E0(v9 + 24, 0);
      v7 = (void *)sub_4FE11E0(a4, 0);
      memcpy_s(v7, 168 * v8, v6, 168 * v8);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// 168字节资金流信息复制  缺当前股票代码信息,联合分笔信息和获得股票代码
定时触发调用XXD700时，第一次、二次、三次EBX+0X12 STOCKCODE，
//处理K线状态下的资金流信息
// THIS指针似乎包含自定义的公式，待进一步研究
char __thiscall sub_4FEA010(_DWORD *this, int a2, int a3, int a4, int a5)
{
  char result; // al
  const void *v6; // ST08_4
  void *v7; // eax
  int v8; // [esp+0h] [ebp-14h]
  _DWORD *v9; // [esp+4h] [ebp-10h]

  v9 = this;
  sub_4FDDAD0(a4);
  if ( ((unsigned __int8)std::operator!=<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(v9 + 15, a3)
     || a2 != v9[22])
    && !sub_4FED2F0(a3, a2) )
  {
    return 0;
  }
  if ( a5 >= 0 && a5 != v9[28] )
  {
    if ( v9[30] > 0 )
      sub_4FEA130(a2, a3);
    result = 0;
  }
  else
  {
    if ( v9[30] >= sub_4FDDA90(v9 + 24) )
      v8 = sub_4FDDA90(v9 + 24);
    else
      v8 = v9[30];
    if ( v8 > 0 )
    {
      sub_4FE5970((void *)a4, v8);
      v6 = (const void *)sub_4FE11E0(v9 + 24, 0);// get data pointer(168*a2+this[1])
                                                // 此时已获得资金流的信息  仅适用于K线，实时信息不再此处

      v7 = (void *)sub_4FE11E0((_DWORD *)a4, 0);// get data pointer(168*a2+this[1])
      memcpy_s(v7, 168 * v8, v6, 168 * v8);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}


//k线资金流信息？？？
缺当前股票代码信息
char __cdecl QDataEngine::ReadCapitalFlowKLineData(unsigned __int8 a1, int a2, int a3, int a4)
{
  int v4; // ecx
  char result; // al
  int v6; // ecx
  int v7; // ST14_4
  int v8; // eax
  int *v9; // eax
  int v10; // ST18_4
  int v11; // ST14_4
  _DWORD *v12; // eax
  bool v13; // [esp+4h] [ebp-64h]
  char v14; // [esp+Ch] [ebp-5Ch]
  char v15; // [esp+14h] [ebp-54h]
  char v16; // [esp+1Ch] [ebp-4Ch]
  char v17; // [esp+27h] [ebp-41h]
  int v18; // [esp+2Ch] [ebp-3Ch]
  int v19; // [esp+30h] [ebp-38h]
  int v20; // [esp+38h] [ebp-30h]
  int v21; // [esp+3Ch] [ebp-2Ch]
  bool v22; // [esp+47h] [ebp-21h]
  int v23; // [esp+48h] [ebp-20h]
  char v24; // [esp+4Ch] [ebp-1Ch]
  int v25; // [esp+64h] [ebp-4h]

  v18 = sub_4C6E720();
  v13 = a3 == 10 || a3 == 11 || a3 == 12 || a3 == 13 || a3 == 14;
  v22 = v13;
  if ( v13 )
  {
    sub_4C95920(&v24);
    v25 = 0;
    v6 = *((_DWORD *)QDataEngine::m_pDataCenter + 13);
    if ( (unsigned __int8)sub_4C959C0(a1, 9, a2, &v24) && !(unsigned __int8)sub_4C91280(&v24) )
    {
      v19 = sub_4C8DA90(&v24);
      v7 = sub_4C8DA90(&v24);
      v8 = sub_4C911E0(0);
      v23 = QDataEngine::ConvertCycleCapitalFlowData(a1, a2, a3, v8, v7, 0);资金信息周期变换？？？20180102
      if ( v23 >= 1 && v19 >= v23 )
      {
        sub_4D80EF0(&v20);
        sub_4C95970(v23);
        v9 = (int *)sub_4D80EF0(&v16);
        v10 = v9[1];
        v11 = *v9;
        v12 = (_DWORD *)sub_4C95DA0(&v15, v23);
        sub_4CA2C30(&v14, v20, v21, *v12, v12[1], v11, v10);
        v25 = -1;
        ((void (*)(void))sub_4C95950)();
        result = 1;
      }
      else
      {
        v25 = -1;
        sub_4C95950(&v24);
        result = 0;
      }
    }
    else
    {
      v25 = -1;
      sub_4C95950(&v24);
      result = 0;
    }
  }
  else
  {
    v4 = *((_DWORD *)QDataEngine::m_pDataCenter + 13);
    result = sub_4FA59C0(a1, a3, a2, a4);
    v17 = result;
  }
  return result;
}


text:04FA59C0 sub_4FA59C0 proc near                   ; CODE XREF: QDataEngine::ReadCapitalFlowKLineData(uchar,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &,DCYCLE,std::vector<CAPITALFLOW_DAY_ITEM_DATA,std::allocator<CAPITALFLOW_DAY_ITEM_DATA>> &)+82↓p
	/*
.text:04FA59C0                                         ; QDataEngine::ReadCapitalFlowKLineData(uchar,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &,DCYCLE,std::vector<CAPITALFLOW_DAY_ITEM_DATA,std::allocator<CAPITALFLOW_DAY_ITEM_DATA>> &)+B9↓p
.text:04FA59C0
.text:04FA59C0 var_3C= dword ptr -3Ch
.text:04FA59C0 var_36= byte ptr -36h
.text:04FA59C0 var_35= byte ptr -35h
.text:04FA59C0 var_34= byte ptr -34h
.text:04FA59C0 var_18= dword ptr -18h
.text:04FA59C0 var_14= dword ptr -14h
.text:04FA59C0 var_D= byte ptr -0Dh
.text:04FA59C0 var_C= dword ptr -0Ch
.text:04FA59C0 var_4= dword ptr -4
.text:04FA59C0 arg_0= dword ptr  8
.text:04FA59C0 arg_4= dword ptr  0Ch
.text:04FA59C0 arg_8= dword ptr  10h
.text:04FA59C0 arg_C= dword ptr  14h
.text:04FA59C0
.text:04FA59C0 ; FUNCTION CHUNK AT .text:0532E6D0 SIZE 00000009 BYTES
.text:04FA59C0
.text:04FA59C0 push    ebp
.text:04FA59C1 mov     ebp, esp
.text:04FA59C3 push    0FFFFFFFFh
.text:04FA59C5 push    offset SEH_4EF5AA0
.text:04FA59CA mov     eax, large fs:0
.text:04FA59D0 push    eax
.text:04FA59D1 sub     esp, 30h
.text:04FA59D4 mov     eax, ___security_cookie
.text:04FA59D9 xor     eax, ebp
.text:04FA59DB mov     [ebp+var_18], eax
.text:04FA59DE push    eax
.text:04FA59DF lea     eax, [ebp+var_C]
.text:04FA59E2 mov     large fs:0, eax
.text:04FA59E8 mov     [ebp+var_3C], ecx
.text:04FA59EB lea     ecx, [ebp+var_34]
; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
;    ::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
;分配字符串空间？？
.text:04FA59EE call    ds:??0?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ 
.text:04FA59F4 mov     [ebp+var_4], 0
.text:04FA59FB mov     ecx, [ebp+var_3C]
.text:04FA59FE call    sub_4FAA570              ??????????????????????
.text:04FA5A03 lea     eax, [ebp+var_34]
.text:04FA5A06 push    eax
.text:04FA5A07 mov     ecx, [ebp+arg_8]
.text:04FA5A0A push    ecx
.text:04FA5A0B mov     edx, [ebp+arg_4]
.text:04FA5A0E push    edx
.text:04FA5A0F mov     eax, [ebp+arg_0]
.text:04FA5A12 push    eax
.text:04FA5A13 mov     ecx, [ebp+var_3C]
.text:04FA5A16 call    sub_4FAA4C0           ??????????????????
.text:04FA5A1B mov     [ebp+var_14], eax
.text:04FA5A1E cmp     [ebp+var_14], 0
.text:04FA5A22 jnz     short loc_4FA5A45
.text:04FA5A24 mov     ecx, [ebp+var_3C]
.text:04FA5A27 call    sub_4FA7E80             ; LeaveCriticalSection
.text:04FA5A2C mov     [ebp+var_35], 0
.text:04FA5A30 mov     [ebp+var_4], 0FFFFFFFFh
.text:04FA5A37 lea     ecx, [ebp+var_34]
; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
;    ::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
;分配字符串空间？？
.text:04FA5A3A call    ds:__imp_??1?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ 
.text:04FA5A40 mov     al, [ebp+var_35]
.text:04FA5A43 jmp     short loc_4FA5A7F
.text:04FA5A45 ; ---------------------------------------------------------------------------
.text:04FA5A45
.text:04FA5A45 loc_4FA5A45:                            ; CODE XREF: sub_4FA59C0+62↑j
.text:04FA5A45 push    1
.text:04FA5A47 mov     ecx, [ebp+arg_C]
.text:04FA5A4A push    ecx
.text:04FA5A4B lea     edx, [ebp+var_34]
.text:04FA5A4E push    edx
.text:04FA5A4F mov     eax, [ebp+arg_0]
.text:04FA5A52 push    eax
.text:04FA5A53 mov     ecx, [ebp+var_14]
.text:04FA5A56 call    sub_4FAA010                    处理K线状态下的资金流信息,缺股票代码信息
.text:04FA5A5B mov     [ebp+var_D], al
.text:04FA5A5E mov     ecx, [ebp+var_3C]
.text:04FA5A61 call    sub_4FA7E80                   ; LeaveCriticalSection
.text:04FA5A66 mov     cl, [ebp+var_D]
.text:04FA5A69 mov     [ebp+var_36], cl
.text:04FA5A6C mov     [ebp+var_4], 0FFFFFFFFh
.text:04FA5A73 lea     ecx, [ebp+var_34]
; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
     ::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
;分配字符串空间？？
.text:04FA5A76 call    ds:__imp_??1?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ 
.text:04FA5A7C mov     al, [ebp+var_36]
.text:04FA5A7F
.text:04FA5A7F loc_4FA5A7F:                            ; CODE XREF: sub_4FA59C0+83↑j
.text:04FA5A7F mov     ecx, [ebp+var_C]
.text:04FA5A82 mov     large fs:0, ecx
.text:04FA5A89 pop     ecx
.text:04FA5A8A mov     ecx, [ebp+var_18]
.text:04FA5A8D xor     ecx, ebp
.text:04FA5A8F call    @__security_check_cookie@4      ; __security_check_cookie(x)
.text:04FA5A94 mov     esp, ebp
.text:04FA5A96 pop     ebp
.text:04FA5A97 retn    10h
.text:04FA5A97 sub_4FA59C0 endp
.text:04FA5A97
*/



.text:04FAA4C0 sub_4FAA4C0 proc near                   ; CODE XREF: sub_4FA59C0+56↑p
	/*
.text:04FAA4C0                                         ; sub_4FA5AA0+57↑p ...
.text:04FAA4C0
.text:04FAA4C0 var_3C= dword ptr -3Ch
.text:04FAA4C0 var_38= dword ptr -38h
.text:04FAA4C0 var_34= byte ptr -34h
.text:04FAA4C0 var_2C= byte ptr -2Ch
.text:04FAA4C0 var_10= dword ptr -10h
.text:04FAA4C0 var_C= dword ptr -0Ch
.text:04FAA4C0 var_4= dword ptr -4
.text:04FAA4C0 arg_0= dword ptr  8
.text:04FAA4C0 arg_4= dword ptr  0Ch
.text:04FAA4C0 arg_8= dword ptr  10h
.text:04FAA4C0 arg_C= dword ptr  14h
.text:04FAA4C0
.text:04FAA4C0 ; FUNCTION CHUNK AT .text:0532E670 SIZE 00000008 BYTES
.text:04FAA4C0
.text:04FAA4C0 push    ebp
.text:04FAA4C1 mov     ebp, esp
.text:04FAA4C3 push    0FFFFFFFFh
.text:04FAA4C5 push    offset SEH_4EFA4C0
.text:04FAA4CA mov     eax, large fs:0
.text:04FAA4D0 push    eax
.text:04FAA4D1 sub     esp, 30h
.text:04FAA4D4 mov     eax, ___security_cookie
.text:04FAA4D9 xor     eax, ebp
.text:04FAA4DB mov     [ebp+var_10], eax
.text:04FAA4DE push    eax
.text:04FAA4DF lea     eax, [ebp+var_C]
.text:04FAA4E2 mov     large fs:0, eax
.text:04FAA4E8 mov     [ebp+var_3C], ecx
.text:04FAA4EB cmp     [ebp+arg_0], 0FFFFFFFFh
.text:04FAA4EF jz      short loc_4FAA508
.text:04FAA4F1 mov     ecx, [ebp+arg_8]
; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(void)  create string
.text:04FAA4F4 call    ds:?c_str@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QBEPB_WXZ 
.text:04FAA4FA push    eax                             ; wchar_t *
.text:04FAA4FB call    ds:wcslen
.text:04FAA501 add     esp, 4
.text:04FAA504 test    eax, eax
.text:04FAA506 jnz     short loc_4FAA50C
.text:04FAA508
.text:04FAA508 loc_4FAA508:                            ; CODE XREF: sub_4FAA4C0+2F↑j
.text:04FAA508 xor     eax, eax
.text:04FAA50A jmp     short loc_4FAA555
.text:04FAA50C ; ---------------------------------------------------------------------------
.text:04FAA50C
.text:04FAA50C loc_4FAA50C:                            ; CODE XREF: sub_4FAA4C0+46↑j
.text:04FAA50C mov     eax, [ebp+arg_8]
.text:04FAA50F push    eax
.text:04FAA510 mov     ecx, [ebp+arg_4]
.text:04FAA513 push    ecx
.text:04FAA514 mov     edx, [ebp+arg_0]
.text:04FAA517 push    edx
.text:04FAA518 lea     ecx, [ebp+var_34]
.text:04FAA51B call    sub_4FA2360
.text:04FAA520 mov     [ebp+var_4], 0
.text:04FAA527 lea     eax, [ebp+var_2C]
.text:04FAA52A push    eax
.text:04FAA52B mov     ecx, [ebp+arg_C]
; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
;    ::operator=(std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &)
.text:04FAA52E call    ds:??4?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAEAAV01@ABV01@@Z 
.text:04FAA534 lea     ecx, [ebp+var_34]
.text:04FAA537 push    ecx
.text:04FAA538 mov     ecx, [ebp+var_3C]
.text:04FAA53B call    sub_4FADB80               ??????????????????????
.text:04FAA540 mov     [ebp+var_38], eax
.text:04FAA543 mov     [ebp+var_4], 0FFFFFFFFh
.text:04FAA54A lea     ecx, [ebp+var_34]
.text:04FAA54D call    sub_4F97E10               ??????????????????????
.text:04FAA552 mov     eax, [ebp+var_38]
.text:04FAA555
.text:04FAA555 loc_4FAA555:                            ; CODE XREF: sub_4FAA4C0+4A↑j
.text:04FAA555 mov     ecx, [ebp+var_C]
.text:04FAA558 mov     large fs:0, ecx
.text:04FAA55F pop     ecx
.text:04FAA560 mov     ecx, [ebp+var_10]
.text:04FAA563 xor     ecx, ebp
.text:04FAA565 call    @__security_check_cookie@4      ; __security_check_cookie(x)
.text:04FAA56A mov     esp, ebp
.text:04FAA56C pop     ebp
.text:04FAA56D retn    10h
*/
.text:04FAA56D sub_4FAA4C0 endp


int __userpurge sub_6E462FC8@<eax>(int a1@<ebp>, int a2)
{
  int v2; // ecx
  int v3; // ebx
  bool v4; // zf
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // ecx
  int v11; // ST04_4
  int v12; // ST08_4
  int v13; // ecx
  int v15; // [esp-Ch] [ebp-Ch]
  int v16; // [esp-8h] [ebp-8h]
  int v17; // [esp-4h] [ebp-4h]

  ((void (__stdcall *)(signed int))msvcp80__EH_prolog3_catch)(40);
  v3 = v2;
  *(_DWORD *)(a1 - 20) = v2;
  v17 = v2;
  *(_DWORD *)(a1 - 24) = 0;
  ((void (__thiscall *)(int, int))msvcp80_std::basic_ostream<unsigned short,std::char_traits<unsigned short> >::sentry::sentry)(
    a1 - 40,
    v17);
  v4 = *(_BYTE *)(a1 - 36) == 0;
  *(_DWORD *)(a1 - 4) = 0;
  if ( !v4 )
  {
    v17 = ((int (__thiscall *)(int, int))msvcp80_std::ios_base::getloc)(v3 + *(_DWORD *)(*(_DWORD *)v3 + 4), a1 - 28);
    *(_BYTE *)(a1 - 4) = 1;
    *(_DWORD *)(a1 - 32) = ((int (__cdecl *)(int))msvcp80_std::use_facet<std::num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t> > > >)(v17);
    ((void (__thiscall *)(int))msvcp80_std::locale::~locale)(a1 - 28);
    v5 = *(_DWORD *)(*(_DWORD *)v3 + 4);
    v6 = *(_DWORD *)(*(_DWORD *)v3 + 4);
    v17 = *(_DWORD *)(a1 + 8);
    v7 = v3 + v6;
    v8 = *(unsigned __int16 *)(v7 + 48);
    v9 = *(_DWORD *)(v7 + 40);
    v16 = v8;
    v15 = v3 + v5;
    *(_DWORD *)(a1 - 52) = 0;
    *(_DWORD *)(a1 - 44) = v9;
    v10 = *(_DWORD *)(a1 - 32);
    *(_BYTE *)(a1 - 48) = 0;
    v11 = *(_DWORD *)(a1 - 52);
    v12 = *(_DWORD *)(a1 - 52 + 4);
    *(_BYTE *)(a1 - 4) = 2;
    if ( *(_BYTE *)(((int (__thiscall *)(int, int, int, int, _DWORD, int, int, int))unk_6E4484C1)(
                      v10,
                      a1 - 52,
                      v11,
                      v12,
                      *(_DWORD *)(a1 - 52 + 8),
                      v15,
                      v16,
                      v17)
                  + 4) )
      *(_DWORD *)(a1 - 24) = 4;
    *(_DWORD *)(a1 - 4) = 0;
  }
  v13 = *(_DWORD *)(*(_DWORD *)v3 + 4);
  v17 = 0;
  ((void (__thiscall *)(int, _DWORD, _DWORD))unk_6E4462DA)(v3 + v13, *(_DWORD *)(a1 - 24), 0);
  *(_DWORD *)(a1 - 4) = -1;
  ((void (__thiscall *)(int))msvcp80_std::basic_ostream<unsigned short,std::char_traits<unsigned short> >::sentry::~sentry)(a1 - 40);
  return ((int (*)(void))msvcp80__EH_epilog3)();
}

	
.text:04FA5AA0 sub_4FA5AA0 proc near                   ; CODE XREF: QDataEngine::ClearCapitalFlowKLineData(uchar,DCYCLE,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &)+17↓p
.text:04FA5AA0                                         ; QDataEngine::Del_CapitalFlowHisData(char,char *,uchar)+66↓p
.text:04FA5AA0
.text:04FA5AA0 var_3C= dword ptr -3Ch
.text:04FA5AA0 var_36= byte ptr -36h
.text:04FA5AA0 var_35= byte ptr -35h
.text:04FA5AA0 var_34= byte ptr -34h
.text:04FA5AA0 var_18= dword ptr -18h
.text:04FA5AA0 var_14= dword ptr -14h
.text:04FA5AA0 var_D= byte ptr -0Dh
.text:04FA5AA0 var_C= dword ptr -0Ch
.text:04FA5AA0 var_4= dword ptr -4
.text:04FA5AA0 arg_0= byte ptr  8
.text:04FA5AA0 arg_4= dword ptr  0Ch
.text:04FA5AA0 arg_8= dword ptr  10h
.text:04FA5AA0
.text:04FA5AA0 ; FUNCTION CHUNK AT .text:0532E6D0 SIZE 00000009 BYTES
.text:04FA5AA0
.text:04FA5AA0 push    ebp
.text:04FA5AA1 mov     ebp, esp
.text:04FA5AA3 push    0FFFFFFFFh
.text:04FA5AA5 push    offset SEH_4EF5AA0
.text:04FA5AAA mov     eax, large fs:0
.text:04FA5AB0 push    eax
.text:04FA5AB1 sub     esp, 30h
.text:04FA5AB4 mov     eax, ___security_cookie
.text:04FA5AB9 xor     eax, ebp
.text:04FA5ABB mov     [ebp+var_18], eax
.text:04FA5ABE push    eax
.text:04FA5ABF lea     eax, [ebp+var_C]
.text:04FA5AC2 mov     large fs:0, eax
.text:04FA5AC8 mov     [ebp+var_3C], ecx
.text:04FA5ACB lea     ecx, [ebp+var_34]
.text:04FA5ACE call    ds:??0?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
.text:04FA5AD4 mov     [ebp+var_4], 0
.text:04FA5ADB mov     ecx, [ebp+var_3C]
.text:04FA5ADE call    sub_4FAA570
.text:04FA5AE3 lea     eax, [ebp+var_34]
.text:04FA5AE6 push    eax
.text:04FA5AE7 mov     ecx, [ebp+arg_8]
.text:04FA5AEA push    ecx
.text:04FA5AEB mov     edx, [ebp+arg_4]
.text:04FA5AEE push    edx
.text:04FA5AEF movzx   eax, [ebp+arg_0]
.text:04FA5AF3 push    eax
.text:04FA5AF4 mov     ecx, [ebp+var_3C]
.text:04FA5AF7 call    sub_4FAA4C0
.text:04FA5AFC mov     [ebp+var_14], eax
.text:04FA5AFF cmp     [ebp+var_14], 0
.text:04FA5B03 jnz     short loc_4FA5B26
.text:04FA5B05 mov     ecx, [ebp+var_3C]
.text:04FA5B08 call    sub_4FA7E80
.text:04FA5B0D mov     [ebp+var_35], 0
.text:04FA5B11 mov     [ebp+var_4], 0FFFFFFFFh
.text:04FA5B18 lea     ecx, [ebp+var_34]
.text:04FA5B1B call    ds:__imp_??1?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
.text:04FA5B21 mov     al, [ebp+var_35]
.text:04FA5B24 jmp     short loc_4FA5B5A
.text:04FA5B26 ; ---------------------------------------------------------------------------
.text:04FA5B26
.text:04FA5B26 loc_4FA5B26:                            ; CODE XREF: sub_4FA5AA0+63↑j
.text:04FA5B26 lea     ecx, [ebp+var_34]
.text:04FA5B29 push    ecx
.text:04FA5B2A mov     dl, [ebp+arg_0]
.text:04FA5B2D push    edx
.text:04FA5B2E mov     ecx, [ebp+var_14]
.text:04FA5B31 call    sub_4FAA130
.text:04FA5B36 mov     [ebp+var_D], al
.text:04FA5B39 mov     ecx, [ebp+var_3C]
.text:04FA5B3C call    sub_4FA7E80
.text:04FA5B41 mov     al, [ebp+var_D]
.text:04FA5B44 mov     [ebp+var_36], al
.text:04FA5B47 mov     [ebp+var_4], 0FFFFFFFFh
.text:04FA5B4E lea     ecx, [ebp+var_34]
.text:04FA5B51 call    ds:__imp_??1?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
.text:04FA5B57 mov     al, [ebp+var_36]
.text:04FA5B5A
.text:04FA5B5A loc_4FA5B5A:                            ; CODE XREF: sub_4FA5AA0+84↑j
.text:04FA5B5A mov     ecx, [ebp+var_C]
.text:04FA5B5D mov     large fs:0, ecx
.text:04FA5B64 pop     ecx
.text:04FA5B65 mov     ecx, [ebp+var_18]
.text:04FA5B68 xor     ecx, ebp
.text:04FA5B6A call    @__security_check_cookie@4      ; __security_check_cookie(x)
.text:04FA5B6F mov     esp, ebp
.text:04FA5B71 pop     ebp
.text:04FA5B72 retn    0Ch
.text:04FA5B72 sub_4FA5AA0 endp




//利用STL的有关技术输出信息
int __cdecl QDataEngine::WriteCapitalFlowKLineData(char a1, int a2, int a3, void *a4, int a5, int a6)
{
  int v6; // ecx

  v6 = *((_DWORD *)QDataEngine::m_pDataCenter + 13);
  return sub_4C95B80(a1, a2, a3, a4, a5, a6);
}

; int __stdcall sub_4C95B80(char, int, int, void *, int, int)
.text:04C95B80 sub_4C95B80 proc near                   ; CODE XREF: QDataEngine::WriteCapitalFlowKLineData(uchar,DCYCLE,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &,CAPITALFLOW_DAY_ITEM_DATA *,int,int &)+23↓p
/*
.text:04C95B80
.text:04C95B80 var_40= dword ptr -40h
.text:04C95B80 var_3C= dword ptr -3Ch
.text:04C95B80 var_38= dword ptr -38h
.text:04C95B80 var_34= dword ptr -34h
.text:04C95B80 var_18= dword ptr -18h
.text:04C95B80 var_14= dword ptr -14h
.text:04C95B80 var_10= dword ptr -10h
.text:04C95B80 var_C= dword ptr -0Ch
.text:04C95B80 var_4= dword ptr -4
.text:04C95B80 arg_0= byte ptr  8
.text:04C95B80 arg_4= dword ptr  0Ch
.text:04C95B80 arg_8= dword ptr  10h
.text:04C95B80 arg_C= dword ptr  14h
.text:04C95B80 arg_10= dword ptr  18h
.text:04C95B80 arg_14= dword ptr  1Ch
.text:04C95B80
.text:04C95B80 ; FUNCTION CHUNK AT .text:0501E6A0 SIZE 00000009 BYTES
.text:04C95B80
.text:04C95B80 ; __unwind { // SEH_4EF5B80
.text:04C95B80 push    ebp
.text:04C95B81 mov     ebp, esp
.text:04C95B83 push    0FFFFFFFFh
.text:04C95B85 push    offset SEH_4EF5B80
.text:04C95B8A mov     eax, large fs:0
.text:04C95B90 push    eax
.text:04C95B91 sub     esp, 34h
.text:04C95B94 mov     eax, ___security_cookie
.text:04C95B99 xor     eax, ebp
.text:04C95B9B mov     [ebp+var_18], eax
.text:04C95B9E push    eax
.text:04C95B9F lea     eax, [ebp+var_C]
.text:04C95BA2 mov     large fs:0, eax
.text:04C95BA8 mov     [ebp+var_40], ecx
.text:04C95BAB lea     ecx, [ebp+var_34]
.text:04C95BAE call    ds:??0?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
.text:04C95BB4 ;   try {
.text:04C95BB4 mov     [ebp+var_4], 0
.text:04C95BBB mov     ecx, [ebp+var_40]
.text:04C95BBE call    sub_4C9A570                     ; EnterCriticalSection
.text:04C95BC3 lea     eax, [ebp+var_34]
.text:04C95BC6 push    eax
.text:04C95BC7 mov     ecx, [ebp+arg_8]
.text:04C95BCA push    ecx
.text:04C95BCB mov     edx, [ebp+arg_4]
.text:04C95BCE push    edx
.text:04C95BCF movzx   eax, [ebp+arg_0]
.text:04C95BD3 push    eax
.text:04C95BD4 mov     ecx, [ebp+var_40]
.text:04C95BD7 call    sub_4C9A4C0                      ????????????????????
.text:04C95BDC mov     [ebp+var_14], eax
.text:04C95BDF cmp     [ebp+var_14], 0
.text:04C95BE3 jnz     short loc_4C95C09
.text:04C95BE5 mov     ecx, [ebp+var_40]
.text:04C95BE8 call    sub_4C97E80                  ????????????????????????
.text:04C95BED mov     [ebp+var_38], 0
.text:04C95BED ;   } // starts at 4C95BB4
.text:04C95BF4 mov     [ebp+var_4], 0FFFFFFFFh
.text:04C95BFB lea     ecx, [ebp+var_34]
.text:04C95BFE call    ds:__imp_??1?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
.text:04C95C04 mov     eax, [ebp+var_38]
.text:04C95C07 jmp     short loc_4C95C4A
.text:04C95C09 ; ---------------------------------------------------------------------------
.text:04C95C09
.text:04C95C09 loc_4C95C09:                            ; CODE XREF: sub_4C95B80+63↑j
.text:04C95C09 mov     ecx, [ebp+arg_14]
.text:04C95C0C push    ecx                             ; int
.text:04C95C0D mov     edx, [ebp+arg_10]
.text:04C95C10 push    edx                             ; int
.text:04C95C11 mov     eax, [ebp+arg_C]
.text:04C95C14 push    eax                             ; void *
.text:04C95C15 lea     ecx, [ebp+var_34]
.text:04C95C18 push    ecx                             ; int
.text:04C95C19 movzx   edx, [ebp+arg_0]
.text:04C95C1D push    edx                             ; int
.text:04C95C1E mov     ecx, [ebp+var_14]
.text:04C95C21 call    sub_4C99C20                                 ???????????????????????
.text:04C95C26 mov     [ebp+var_10], eax
.text:04C95C29 mov     ecx, [ebp+var_40]
.text:04C95C2C call    sub_4C97E80                                 ?????????????????????????
.text:04C95C31 mov     eax, [ebp+var_10]
.text:04C95C34 mov     [ebp+var_3C], eax
.text:04C95C37 mov     [ebp+var_4], 0FFFFFFFFh
.text:04C95C3E lea     ecx, [ebp+var_34]
.text:04C95C41 call    ds:__imp_??1?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAE@XZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(void)
.text:04C95C47 mov     eax, [ebp+var_3C]
.text:04C95C4A
.text:04C95C4A loc_4C95C4A:                            ; CODE XREF: sub_4C95B80+87↑j
.text:04C95C4A mov     ecx, [ebp+var_C]
.text:04C95C4D mov     large fs:0, ecx
.text:04C95C54 pop     ecx
.text:04C95C55 mov     ecx, [ebp+var_18]
.text:04C95C58 xor     ecx, ebp
.text:04C95C5A call    @__security_check_cookie@4      ; __security_check_cookie(x)
.text:04C95C5F mov     esp, ebp
.text:04C95C61 pop     ebp
.text:04C95C62 retn    18h
.text:04C95C62 ; } // starts at 4C95B80
*/
.text:04C95C62 sub_4C95B80 endp

 sub_4C9A4C0 proc near                   ; CODE XREF: sub_4C959C0+56↑p
 /*
.text:04C9A4C0                                         ; sub_4C95AA0+57↑p ...
.text:04C9A4C0
.text:04C9A4C0 var_3C= dword ptr -3Ch
.text:04C9A4C0 var_38= dword ptr -38h
.text:04C9A4C0 var_34= byte ptr -34h
.text:04C9A4C0 var_2C= byte ptr -2Ch
.text:04C9A4C0 var_10= dword ptr -10h
.text:04C9A4C0 var_C= dword ptr -0Ch
.text:04C9A4C0 var_4= dword ptr -4
.text:04C9A4C0 arg_0= dword ptr  8
.text:04C9A4C0 arg_4= dword ptr  0Ch
.text:04C9A4C0 arg_8= dword ptr  10h
.text:04C9A4C0 arg_C= dword ptr  14h
.text:04C9A4C0
.text:04C9A4C0 ; FUNCTION CHUNK AT .text:0501E670 SIZE 00000008 BYTES
.text:04C9A4C0
.text:04C9A4C0 ; __unwind { // SEH_4EFA4C0
.text:04C9A4C0 push    ebp
.text:04C9A4C1 mov     ebp, esp
.text:04C9A4C3 push    0FFFFFFFFh
.text:04C9A4C5 push    offset SEH_4EFA4C0
.text:04C9A4CA mov     eax, large fs:0
.text:04C9A4D0 push    eax
.text:04C9A4D1 sub     esp, 30h
.text:04C9A4D4 mov     eax, ___security_cookie
.text:04C9A4D9 xor     eax, ebp
.text:04C9A4DB mov     [ebp+var_10], eax
.text:04C9A4DE push    eax
.text:04C9A4DF lea     eax, [ebp+var_C]
.text:04C9A4E2 mov     large fs:0, eax
.text:04C9A4E8 mov     [ebp+var_3C], ecx
.text:04C9A4EB cmp     [ebp+arg_0], 0FFFFFFFFh
.text:04C9A4EF jz      short loc_4C9A508
.text:04C9A4F1 mov     ecx, [ebp+arg_8]
.text:04C9A4F4 call    ds:?c_str@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QBEPB_WXZ ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(void)
.text:04C9A4FA push    eax                             ; wchar_t *
.text:04C9A4FB call    ds:wcslen
.text:04C9A501 add     esp, 4
.text:04C9A504 test    eax, eax
.text:04C9A506 jnz     short loc_4C9A50C
.text:04C9A508
.text:04C9A508 loc_4C9A508:                            ; CODE XREF: sub_4C9A4C0+2F↑j
.text:04C9A508 xor     eax, eax
.text:04C9A50A jmp     short loc_4C9A555
.text:04C9A50C ; ---------------------------------------------------------------------------
.text:04C9A50C
.text:04C9A50C loc_4C9A50C:                            ; CODE XREF: sub_4C9A4C0+46↑j
.text:04C9A50C mov     eax, [ebp+arg_8]
.text:04C9A50F push    eax
.text:04C9A510 mov     ecx, [ebp+arg_4]
.text:04C9A513 push    ecx
.text:04C9A514 mov     edx, [ebp+arg_0]
.text:04C9A517 push    edx
.text:04C9A518 lea     ecx, [ebp+var_34]
.text:04C9A51B call    sub_4C92360                  ?????????????????  输出信息
.text:04C9A520 ;   try {
.text:04C9A520 mov     [ebp+var_4], 0
.text:04C9A527 lea     eax, [ebp+var_2C]
.text:04C9A52A push    eax
.text:04C9A52B mov     ecx, [ebp+arg_C]
.text:04C9A52E call    ds:??4?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAEAAV01@ABV01@@Z ; std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::operator=(std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &)
.text:04C9A534 lea     ecx, [ebp+var_34]
.text:04C9A537 push    ecx
.text:04C9A538 mov     ecx, [ebp+var_3C]
.text:04C9A53B call    sub_4C9DB80                   ????????????????????
.text:04C9A540 mov     [ebp+var_38], eax
.text:04C9A540 ;   } // starts at 4C9A520
.text:04C9A543 mov     [ebp+var_4], 0FFFFFFFFh
.text:04C9A54A lea     ecx, [ebp+var_34]
.text:04C9A54D call    sub_4C87E10
.text:04C9A552 mov     eax, [ebp+var_38]
.text:04C9A555
.text:04C9A555 loc_4C9A555:                            ; CODE XREF: sub_4C9A4C0+4A↑j
.text:04C9A555 mov     ecx, [ebp+var_C]
.text:04C9A558 mov     large fs:0, ecx
.text:04C9A55F pop     ecx
.text:04C9A560 mov     ecx, [ebp+var_10]
.text:04C9A563 xor     ecx, ebp
.text:04C9A565 call    @__security_check_cookie@4      ; __security_check_cookie(x)
.text:04C9A56A mov     esp, ebp
.text:04C9A56C pop     ebp
.text:04C9A56D retn    10h
*/
sub_4C9A4C0    endp


//用了大量stl模版，作用不明0103
//似乎利用std::basic_ostringstream输出信息
_DWORD *__thiscall sub_4CF2360(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // ST18_4
  int v5; // ST08_4
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char v10; // [esp+10h] [ebp-A8h]
  char v11; // [esp+2Ch] [ebp-8Ch]
  int v12; // [esp+B4h] [ebp-4h]

  v4 = this;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
  	 ::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(this + 2);
  v12 = 0;
  *v4 = a2;
  std::basic_ostringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
  	 ::basic_ostringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v11,
    2,
    1);
  LOBYTE(v12) = 1;
  v5 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(a4);
  v6 = std::basic_ostream<wchar_t,std::char_traits<wchar_t>>::operator<<(&v11, a3);
  v7 = sub_4CEF9A0(v6, &unk_50B4860);
  sub_4CEF9A0(v7, v5);
  v8 = std::basic_ostringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v11, &v10);
  LOBYTE(v12) = 2;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::operator=(v4 + 2, v8);
  LOBYTE(v12) = 1;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>
  	 ::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v10);
  v4[1] = a3;
  LOBYTE(v12) = 0;
  std::basic_ostringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor();
  return v4;
}

//看不出作用0103   似乎输出信息
int __cdecl sub_4CEF9A0(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-70h]
  char v8; // [esp+13h] [ebp-5Dh]
  __int16 v9; // [esp+14h] [ebp-5Ch]
  __int16 v10; // [esp+16h] [ebp-5Ah]
  int v11; // [esp+18h] [ebp-58h]
  __int16 v12; // [esp+1Eh] [ebp-52h]
  int v13; // [esp+20h] [ebp-50h]
  int v14; // [esp+24h] [ebp-4Ch]
  char v15; // [esp+2Bh] [ebp-45h]
  __int16 v16; // [esp+2Ch] [ebp-44h]
  __int16 v17; // [esp+2Eh] [ebp-42h]
  int v18; // [esp+30h] [ebp-40h]
  __int16 v19; // [esp+36h] [ebp-3Ah]
  int v20; // [esp+38h] [ebp-38h]
  int v21; // [esp+3Ch] [ebp-34h]
  int v22; // [esp+40h] [ebp-30h]
  __int16 v23; // [esp+44h] [ebp-2Ch]
  __int16 v24; // [esp+46h] [ebp-2Ah]
  __int16 v25; // [esp+48h] [ebp-28h]
  __int16 v26; // [esp+4Ah] [ebp-26h]
  char v27; // [esp+4Ch] [ebp-24h]
  int v28; // [esp+54h] [ebp-1Ch]
  int v29; // [esp+58h] [ebp-18h]
  int v30; // [esp+5Ch] [ebp-14h]
  int *v31; // [esp+60h] [ebp-10h]
  int v32; // [esp+6Ch] [ebp-4h]

  v31 = &v7;
  v30 = 0;
  v29 = std::char_traits<wchar_t>::length(a2);
  if ( std::ios_base::width((std::ios_base *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1)) <= 0
    || (v2 = std::ios_base::width((std::ios_base *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1)), v2 <= v29) )
  {
    v21 = 0;
  }
  else
  {
    v3 = std::ios_base::width((std::ios_base *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1));
    v21 = v3 - v29;
  }
  v28 = v21;
  sub_4CF1F40(a1);
  v32 = 0;
  if ( (unsigned __int8)unknown_libname_6(&v27) )
  {
    LOBYTE(v32) = 1;
    v20 = std::ios_base::flags((std::ios_base *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1));
    if ( (v20 & 0x1C0) != 64 )
    {
      while ( v28 > 0 )
      {
        v19 = std::basic_ios<wchar_t,std::char_traits<wchar_t>>::fill(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1);
        v4 = std::basic_ios<wchar_t,std::char_traits<wchar_t>>::rdbuf(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1);
        v18 = v4;
        LOWORD(v4) = v19;
        v17 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>>::sputc(v18, v4);
        v26 = v17;
        v16 = std::char_traits<wchar_t>::eof();
        v25 = v16;
        v15 = std::char_traits<wchar_t>::eq_int_type(&v25, &v26);
        if ( v15 )
        {
          v30 |= 4u;
          break;
        }
        --v28;
      }
    }
    if ( !v30 )
    {
      v14 = std::basic_ios<wchar_t,std::char_traits<wchar_t>>::rdbuf(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1);
      v13 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>>::sputn(v14, a2, v29);
      if ( v13 != v29 )
        v30 |= 4u;
    }
    if ( !v30 )
    {
      while ( v28 > 0 )
      {
        v12 = std::basic_ios<wchar_t,std::char_traits<wchar_t>>::fill(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1);
        v5 = std::basic_ios<wchar_t,std::char_traits<wchar_t>>::rdbuf(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1);
        v11 = v5;
        LOWORD(v5) = v12;
        v10 = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>>::sputc(v11, v5);  输出字符
        v24 = v10;
        v9 = std::char_traits<wchar_t>::eof();
        v23 = v9;
        v8 = std::char_traits<wchar_t>::eq_int_type(&v23, &v24);
        if ( v8 )
        {
          v30 |= 4u;
          break;
        }
        --v28;
      }
    }
    std::ios_base::width((std::ios_base *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1), 0);
    v32 = 0;
  }
  else
  {
    v30 |= 4u;
  }
  std::basic_ios<wchar_t,std::char_traits<wchar_t>>::setstate(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1, v30, 0);
  v22 = a1;
  v32 = -1;
  sub_4CF1E80();
  return v22;
}

// 为this指针分配资金流所需的存贮空间，this+0x4：开始地址，this+0x8，+0xc：结束地址。
// 处理资金流有关的信息a4：数据项数，实时状态下最大240
int __thiscall sub_4FED700(_DWORD *this, int a2, int a3, unsigned int a4, const void *a5)
{
  int result; // eax
  int v6; // esi
  int v7; // eax
  unsigned int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // [esp+0h] [ebp-E8h]
  int v12; // [esp+10h] [ebp-D8h]
  int v13; // [esp+14h] [ebp-D4h]
  unsigned int v14; // [esp+18h] [ebp-D0h]
  _DWORD *v15; // [esp+1Ch] [ebp-CCh]
  int v16; // [esp+20h] [ebp-C8h]
  int v17; // [esp+24h] [ebp-C4h]
  int v18; // [esp+28h] [ebp-C0h]
  unsigned int v19; // [esp+2Ch] [ebp-BCh]
  char v20; // [esp+30h] [ebp-B8h]
  int *v21; // [esp+D8h] [ebp-10h]
  int v22; // [esp+E4h] [ebp-4h]
  unsigned int v23; // [esp+F8h] [ebp+10h]

  v21 = &v11;
  v15 = this;                                   // +0x68  股票代码
  qmemcpy(&v20, a5, 0xA8u);                     // 0xa8  168  每分钟的资金流结构体大小？？
                                                // 从a5把数据复制到v21
                                                // 似乎清零
  result = sub_4FEFC60(this);                   // 获取资金流结构体数量
  v19 = result;
  if ( a4 )
  {
    v6 = sub_4FDDA90(v15);                      // 获取资金流结构体数量
    if ( sub_4FEF460() - v6 >= a4 )             // sub_4FEF460()返回有固定的符号数25565281
    {
      v7 = sub_4FDDA90(v15);                    // 获取资金流结构体数量
      if ( v19 >= a4 + v7 )
      {
        if ( (v15[2] - a3) / 168 >= a4 )        // 此分支作用不明
                                                // 似乎是数据确定后定期更新显示
        {
          v16 = v15[2];
          v10 = sub_4FF4240(v16 - -88 * a4, v16, v15[2]);
          v15[2] = v10;
          sub_4FF42A0(a3, v16 - -88 * a4, v16);
          result = sub_4FF4270(a3, a3 - 88 * a4, (int)&v20);
        }
        else
        {
          sub_4FF4240(a3, v15[2], a3 + 168 * a4);
          v22 = 2;
          sub_4FF2660(v15[2], a4 - (v15[2] - a3) / 168, &v20);
          v22 = -1;
          v15[2] += 168 * a4;
          result = sub_4FF4270(a3, *((_BYTE *)v15 + 8) - -88 * a4, (int)&v20);
        }
      }
      else
      {
        v8 = v19 >> 1;                          // ebx+0x12  stockcode
        if ( sub_4FEF460() - v8 >= v19 )        // sub_4FEF460()返回有固定的符号数25565281
          v14 = v19 + (v19 >> 1);
        else
          v14 = 0;
        v19 = v14;
        v9 = sub_4FDDA90(v15);                  // 获取资金流结构体数量
        if ( v19 < a4 + v9 )
          v19 = a4 + sub_4FDDA90(v15);
        v17 = sub_4FEF480(v19);                 // 分配需要的资金流数据内存指针
                                                // v18保存分钟资金流数据
                                                // v18=v20*168+类基址
        v18 = v17;
        v22 = 0;
        v13 = sub_4FF4240(v15[1], a3, v17);
        v18 = v13;
        v12 = sub_4FF2660(v13, a4, &v20);
        v18 = v12;
        sub_4FF4240(a3, v15[2], v12);
        v22 = -1;
        v23 = a4 + sub_4FDDA90(v15);
        if ( v15[1] )
        {
          sub_4FDE930(v15[1], v15[2]);
          sub_4FDBD10(v15[1], (v15[3] - v15[1]) / 168);
        }
        v15[3] = v17 + 168 * v19;
        v15[2] = v17 + 168 * v23;               // setup memory breakpoit  msvcr80_fastcopy_I 会发生中断
        result = v17;
        v15[1] = v17;
      }
    }
    else
    {
      result = sub_50C8C90();
    }
  }
  return result;
}

//128biti  copy ,其中包括每日分钟资金流copy
void __cdecl msvcr80_fastcopy_I(__m128i *a1, const __m128i *a2, unsigned int a3)
{
  const __m128i *v3; // esi
  __m128i *v4; // edi
  unsigned int v5; // ecx
  __m128i v6; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v3 = a2;
  v4 = a1;
  v5 = a3 >> 7;
  do
  {
    v6 = _mm_load_si128(v3 + 1);
    v7 = _mm_load_si128(v3 + 2);
    v8 = _mm_load_si128(v3 + 3);
    _mm_store_si128(v4, _mm_load_si128(v3));
    _mm_store_si128(v4 + 1, v6);
    _mm_store_si128(v4 + 2, v7);
    _mm_store_si128(v4 + 3, v8);
    v9 = _mm_load_si128(v3 + 5);
    v10 = _mm_load_si128(v3 + 6);
    v11 = _mm_load_si128(v3 + 7);
    _mm_store_si128(v4 + 4, _mm_load_si128(v3 + 4));
    _mm_store_si128(v4 + 5, v9);
    _mm_store_si128(v4 + 6, v10);
    _mm_store_si128(v4 + 7, v11);
    v3 += 8;
    v4 += 8;
    --v5;
  }
  while ( v5 );
}

signed int __cdecl msvcr80_memcpy_s(int a1, unsigned int a2, int a3, unsigned int a4)
{
  signed int v5; // esi

  if ( !a4 )
    return 0;
  if ( !a1 )
    goto LABEL_15;
  if ( a3 && a2 >= a4 )
  {
    ((void (__cdecl *)(int, int, unsigned int))msvcr80_memcpy)(a1, a3, a4);
    return 0;
  }
  ((void (__cdecl *)(int, _DWORD, unsigned int))msvcr80_memset)(a1, 0, a2);
  if ( !a3 )
  {
LABEL_15:
    v5 = 22;
    *(_DWORD *)((int (*)(void))msvcr80__errno)() = 22;
LABEL_5:
    ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))msvcr80__invalid_parameter)(0, 0, 0, 0, 0);
    return v5;
  }
  if ( a2 < a4 )
  {
    *(_DWORD *)((int (*)(void))msvcr80__errno)() = 34;
    v5 = 34;
    goto LABEL_5;
  }
  return 22;
}

__m128i *__cdecl msvcr80__VEC_memcpy(__m128i *a1, const __m128i *a2, unsigned int a3)
{
  int v3; // ecx
  __m128i *result; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned int v7; // [esp+4h] [ebp-18h]

  v3 = (signed int)a2 % -16;
  result = a1;
  if ( (signed int)a1 % -16 | (signed int)a2 % -16 )
  {
    if ( v3 == (signed int)a1 % -16 )
    {
      v6 = -v3;
      qmemcpy(a1, a2, v6 + 16);
      msvcr80__VEC_memcpy(&a1[1].m128i_i8[v6], &a2[1].m128i_i8[v6], a3 - (v6 + 16));// 递归调用
    }
    else
    {
      qmemcpy(a1, a2, a3);
    }
    result = a1;
  }
  else
  {
    v5 = a3 & 0x7F;
    v7 = v5;
    if ( a3 != v5 )
    {
      msvcr80_fastcopy_I(a1, a2, a3 - v5);      // 基于ixmm寄存器进行16字节数据搬运
      result = a1;
      v5 = v7;
    }
    if ( v5 )
    {
      qmemcpy((char *)result->m128i_i32 + a3 - v5, (char *)a2->m128i_i32 + a3 - v5, v7);
      result = a1;
    }
  }
  return result;
}