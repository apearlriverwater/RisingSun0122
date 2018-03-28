

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
//资金流信息预处理，可不关注20180102
char __thiscall CDataMgr::PreProcMoneyFlowData(CDataMgr *this, char a2, char a3, int a4, signed int a5, int a6, _DWORD *a7, int a8)
{
  char result; // al
  _DWORD *v9; // ST12EC_4
  LightLogger::CLogger *v10; // eax
  LightLogger::CLogger *v11; // eax
  CDataMgr *v12; // [esp+1A8h] [ebp-974h]
  char v13; // [esp+1C8h] [ebp-954h]
  char v14; // [esp+1ECh] [ebp-930h]
  struct CListCompressIf *v15; // [esp+1F0h] [ebp-92Ch]
  wchar_t v16; // [esp+200h] [ebp-91Ch]
  DWORD v17; // [esp+B08h] [ebp-14h]
  int v18; // [esp+B18h] [ebp-4h]

  v12 = this;
  if ( !a4 )
    return 0;
  LightLogger::CLogger::GetLogger(&v14, L"PushMoneyFlow");
  v18 = 0;
  v9 = (_DWORD *)sub_504F190(&v13, a3);
  sub_4DCE590(&v16, L"start pushstatus:%s IncrementId:%d", *v9);
  mfc80xU_577(&v13);
  v10 = (LightLogger::CLogger *)unknown_libname_96(&v14);
  LightLogger::CLogger::WriteLogLine(v10, &v16, 10000);
  v17 = GetTickCount();
  v15 = CDataMgr::GetListCompressPtr(v12, a2, a3);
  if ( v15 )
  {
    if ( a4 )
      JUMPOUT(a5, 1, &unk_505DC66);
    sub_4DCE590(&v16, L"data addr is null or data len is:%d", a5);
    v11 = (LightLogger::CLogger *)unknown_libname_96(&v14);
    LightLogger::CLogger::WriteLogLine(v11, &v16, 10000);
    v18 = -1;
    sub_4ECC780(&v14);
    result = 0;
  }
  else
  {
    v18 = -1;
    sub_4ECC780(&v14);
    result = 0;
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