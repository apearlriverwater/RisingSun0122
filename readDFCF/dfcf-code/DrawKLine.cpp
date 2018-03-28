ineFactory:07449B20 loc_7449B20:                            ; CODE XREF: sub_73C5A80+7CC↑p
ElementKlineFactory:07449B20 push    ebp                             ; 处理K线资金流有关的信息
/*
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
*/	
int __stdcall sub_100A9B20(_DWORD *a1, int a2, char a3)
{
  int v3; // ecx
  int result; // eax
  int v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  int v8; // esi
  _DWORD *v9; // eax
  int *v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  const wchar_t *v13; // STEB0_4
  int v14; // STEAC_4
  int v15; // eax
  int v16; // eax
  int v17; // eax
  CDataMgr *v18; // ebx
  int v19; // eax
  unsigned __int8 v20; // cl
  char *v21; // eax
  int v22; // eax
  void *v23; // esp
  unsigned int v24; // edi
  int i; // eax
  unsigned int v26; // ecx
  bool v27; // cf
  bool v28; // zf
  int v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // ecx
  double v42; // st6
  double v43; // st5
  double v44; // st4
  double v45; // st1
  double v46; // st2
  double v47; // st6
  double v48; // st7
  double v49; // st1
  double v50; // rt0
  double v51; // rt2
  double v52; // st2
  double v53; // st6
  double v54; // st3
  double v55; // st7
  int v56; // eax
  int v57; // eax
  CDataMgr *v58; // edi
  int v59; // eax
  _DWORD *v60; // edi
  unsigned int v61; // ebx
  int v62; // eax
  int v63; // [esp+0h] [ebp-164h]
  int v64; // [esp+10h] [ebp-154h]
  int v65; // [esp+14h] [ebp-150h]
  double v66; // [esp+18h] [ebp-14Ch]
  double v67; // [esp+28h] [ebp-13Ch]
  double v68; // [esp+30h] [ebp-134h]
  double v69; // [esp+38h] [ebp-12Ch]
  double v70; // [esp+40h] [ebp-124h]
  double v71; // [esp+48h] [ebp-11Ch]
  double v72; // [esp+50h] [ebp-114h]
  double v73; // [esp+58h] [ebp-10Ch]
  double v74; // [esp+60h] [ebp-104h]
  double v75; // [esp+68h] [ebp-FCh]
  __int64 v76; // [esp+70h] [ebp-F4h]
  __int64 v77; // [esp+78h] [ebp-ECh]
  double v78; // [esp+80h] [ebp-E4h]
  __int64 v79; // [esp+88h] [ebp-DCh]
  double v80; // [esp+90h] [ebp-D4h]
  __int64 v81; // [esp+98h] [ebp-CCh]
  double v82; // [esp+A0h] [ebp-C4h]
  __int64 v83; // [esp+A8h] [ebp-BCh]
  double v84; // [esp+B0h] [ebp-B4h]
  unsigned __int64 v85; // [esp+B8h] [ebp-ACh]
  unsigned __int64 v86; // [esp+C0h] [ebp-A4h]
  unsigned __int64 v87; // [esp+C8h] [ebp-9Ch]
  __int64 v88; // [esp+D0h] [ebp-94h]
  unsigned __int64 v89; // [esp+D8h] [ebp-8Ch]
  unsigned __int64 v90; // [esp+E0h] [ebp-84h]
  unsigned __int64 v91; // [esp+E8h] [ebp-7Ch]
  __int64 v92; // [esp+F0h] [ebp-74h]
  unsigned __int64 v93; // [esp+F8h] [ebp-6Ch]
  unsigned __int64 v94; // [esp+100h] [ebp-64h]
  __int64 v95; // [esp+108h] [ebp-5Ch]
  double v96; // [esp+110h] [ebp-54h]
  double v97; // [esp+118h] [ebp-4Ch]
  double v98; // [esp+120h] [ebp-44h]
  double v99; // [esp+128h] [ebp-3Ch]
  _DWORD *v100; // [esp+134h] [ebp-30h]
  double v101; // [esp+138h] [ebp-2Ch]
  double v102; // [esp+140h] [ebp-24h]
  CDataMgr *v103; // [esp+14Ch] [ebp-18h]
  int v104; // [esp+160h] [ebp-4h]

  v3 = a2;
  result = a1[1];
  if ( !result || !*(_DWORD *)(result + 744) )
    return result;
  v5 = *(_DWORD *)(a2 + 4);//分钟周期，日线时固定为零，分钟K线对应实际分钟数
  if ( v5 )
  {
    v3 = *(_DWORD *)(a2 + 8) - v5;    ？？？？
    v6 = v3 / 168;
  }
  else
  {
    v6 = 0;
  }
  v7 = a1[4];
  v100 = a1 + 3;
  if ( v7 )
  {
    v3 = a1[5] - v7;
    result = v3 / 88;
    if ( v6 < v3 / 88 )
      return result;
  }
  if ( !a3 )
  {
    v8 = sub_100ACAF0(a1 + 3);
    if ( sub_100ACC30(a2) == v8 )
    {
      if ( sub_100ACC30(a2) )
      {
        v103 = (CDataMgr *)sub_100ACC30(a2);
        HIDWORD(v102) = sub_100ACB10();
        v9 = (_DWORD *)sub_100ACC50();
        v3 = HIDWORD(v102);
        if ( *v9 == *(_DWORD *)HIDWORD(v102) )
        {
          HIDWORD(v102) = sub_100ACB10() + 4;
          if ( *(_DWORD *)(sub_100ACC50() + 4) == *(_DWORD *)HIDWORD(v102) )
          {
            HIDWORD(v102) = sub_100ACB10();
            v10 = (int *)sub_100ACC50();
            v3 = *v10;
            if ( *v10 == *(_DWORD *)HIDWORD(v102) )
            {
              HIDWORD(v102) = sub_100ACB10() + 4;
              result = *(_DWORD *)(sub_100ACC50() + 4);
              v3 = HIDWORD(v102);
              if ( result == *(_DWORD *)HIDWORD(v102) )
                return result;
            }
          }
        }
      }
    }
  }
  sub_100ACBF0(v3);
  v11 = a1;
  v12 = a1[1];
  v13 = *(const wchar_t **)(v12 + 368);
  v14 = *(unsigned __int8 *)(v12 + 372);
  v103 = 0;
  if ( IsZhiShu(v14, v13) || *(_BYTE *)(a1[1] + 372) == 90 )
  {
    v103 = (CDataMgr *)1;
    v15 = CGlobalEnv::GetGlobalEnv((char *)&v102 + 4);
    v104 = 0;
    v16 = *(_DWORD *)(*(_DWORD *)v15 + 144);
    v17 = sub_10046BF0();
    v18 = (CDataMgr *)v17;
    HIDWORD(v99) = v17;
    if ( v17 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 4))(v17);
    LOBYTE(v104) = 2;
    if ( HIDWORD(v102) )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)HIDWORD(v102) + 8))(HIDWORD(v102));
    ((void (*)(void))off_1017E0B4)();
    v19 = a1[1];
    v20 = *(_BYTE *)(v19 + 372);
    if ( v20 == 90 )
    {
      if ( *(_DWORD *)(v19 + 368) )
      {
        v22 = lstrlenW(*(LPCWSTR *)(v19 + 368)) + 1;
        if ( v22 <= 0x3FFFFFFF )
        {
          v23 = alloca(2 * v22);
          HIDWORD(v101) = &v63;
          v21 = (char *)sub_10046BC0(2 * v22, 0x3A8u);
          v11 = a1;
        }
        else
        {
          v21 = 0;
        }
      }
      else
      {
        v21 = 0;
      }
      v102 = CDataMgr::GetLTG(v18, *(unsigned __int8 *)(v11[1] + 372), v21);
    }
    else
    {
      v102 = CDataMgr::GetTotalLTG(v18, v20);
    }
    v104 = -1;
    if ( v18 )
      (*(void (__stdcall **)(CDataMgr *))(*(_DWORD *)v18 + 8))(v18);
  }
  v24 = *(_DWORD *)(a2 + 4);
  if ( v24 > *(_DWORD *)(a2 + 8) )
    invalid_parameter_noinfo();
  for ( i = a2; ; i = a2 )
  {
    v26 = *(_DWORD *)(i + 8);
    v27 = *(_DWORD *)(i + 4) < v26;
    v28 = *(_DWORD *)(i + 4) == v26;
    HIDWORD(v101) = *(_DWORD *)(i + 8);
    if ( !v27 && !v28 )
      invalid_parameter_noinfo();
    if ( !a2 )
      invalid_parameter_noinfo();
    if ( v24 == HIDWORD(v101) )
      break;
    if ( !v103 )
    {
      if ( !a2 )
        invalid_parameter_noinfo();
      if ( v24 >= *(_DWORD *)(a2 + 8) )
        invalid_parameter_noinfo();
      v29 = a1[1];
      v102 = sub_10063DA0(*(_DWORD *)v24) * 10000.0;
    }
    if ( !a2 )
      invalid_parameter_noinfo();
    if ( v24 >= *(_DWORD *)(a2 + 8) )
      invalid_parameter_noinfo();
    v30 = *(_DWORD *)(v24 + 100);
    LODWORD(v81) = *(_DWORD *)(v24 + 96);
    v27 = v24 < *(_DWORD *)(a2 + 8);
    HIDWORD(v81) = v30 & 0x7FFFFFFF;
    v93 = __PAIR__(v30 & 0x80000000, 0);
    v101 = (double)__PAIR__(v30, (unsigned int)v81);
    if ( !v27 )
      invalid_parameter_noinfo();
    v31 = *(_DWORD *)(v24 + 92);
    v32 = *(_DWORD *)(v24 + 92) & 0x80000000;
    v27 = v24 < *(_DWORD *)(a2 + 8);
    LODWORD(v83) = *(_DWORD *)(v24 + 88);
    HIDWORD(v83) = v31 & 0x7FFFFFFF;
    v91 = __PAIR__(v32, 0);
    v97 = (double)__PAIR__(v31, (unsigned int)v83);
    if ( !v27 )
      invalid_parameter_noinfo();
    v33 = *(_DWORD *)(v24 + 84);
    LODWORD(v76) = *(_DWORD *)(v24 + 80);
    v27 = v24 < *(_DWORD *)(a2 + 8);
    HIDWORD(v76) = v33 & 0x7FFFFFFF;
    v89 = __PAIR__(v33 & 0x80000000, 0);
    v84 = (double)__PAIR__(v33, (unsigned int)v76);
    if ( !v27 )
      invalid_parameter_noinfo();
    v34 = *(_DWORD *)(v24 + 76);
    v35 = *(_DWORD *)(v24 + 76) & 0x80000000;
    v27 = v24 < *(_DWORD *)(a2 + 8);
    LODWORD(v95) = *(_DWORD *)(v24 + 72);
    HIDWORD(v95) = v34 & 0x7FFFFFFF;
    v87 = __PAIR__(v35, 0);
    v80 = (double)__PAIR__(v34, (unsigned int)v95);
    if ( !v27 )
      invalid_parameter_noinfo();
    v36 = *(_DWORD *)(v24 + 132);
    LODWORD(v77) = *(_DWORD *)(v24 + 128);
    v27 = v24 < *(_DWORD *)(a2 + 8);
    HIDWORD(v77) = v36 & 0x7FFFFFFF;
    v85 = __PAIR__(v36 & 0x80000000, 0);
    v98 = (double)__PAIR__(v36, (unsigned int)v77);
    if ( !v27 )
      invalid_parameter_noinfo();
    v37 = *(_DWORD *)(v24 + 124);
    v38 = *(_DWORD *)(v24 + 124) & 0x80000000;
    v27 = v24 < *(_DWORD *)(a2 + 8);
    LODWORD(v79) = *(_DWORD *)(v24 + 120);
    HIDWORD(v79) = v37 & 0x7FFFFFFF;
    v94 = __PAIR__(v38, 0);
    v96 = (double)__PAIR__(v37, (unsigned int)v79);
    if ( !v27 )
      invalid_parameter_noinfo();
    v39 = *(_DWORD *)(v24 + 116);
    LODWORD(v92) = *(_DWORD *)(v24 + 112);
    v27 = v24 < *(_DWORD *)(a2 + 8);
    HIDWORD(v92) = v39 & 0x7FFFFFFF;
    v90 = __PAIR__(v39 & 0x80000000, 0);
    v82 = (double)__PAIR__(v39, (unsigned int)v92);
    if ( !v27 )
      invalid_parameter_noinfo();
    v40 = *(_DWORD *)(v24 + 108);
    v41 = *(_DWORD *)(v24 + 108) & 0x80000000;
    v27 = v24 < *(_DWORD *)(a2 + 8);
    LODWORD(v88) = *(_DWORD *)(v24 + 104);
    HIDWORD(v88) = v40 & 0x7FFFFFFF;
    v86 = __PAIR__(v41, 0);
    v78 = (double)__PAIR__(v40, (unsigned int)v88);
    if ( !v27 )
    {
      invalid_parameter_noinfo();
      if ( v24 >= *(_DWORD *)(a2 + 8) )
      {
        invalid_parameter_noinfo();
        if ( v24 >= *(_DWORD *)(a2 + 8) )
        {
          invalid_parameter_noinfo();
          if ( v24 >= *(_DWORD *)(a2 + 8) )
            invalid_parameter_noinfo();
        }
      }
    }
    HIDWORD(v99) = *(_DWORD *)(v24 + 136) + *(_DWORD *)(v24 + 140) + *(_DWORD *)(v24 + 144) + *(_DWORD *)(v24 + 148);
    v27 = v24 < *(_DWORD *)(a2 + 8);
    v75 = (double)HIDWORD(v99);
    if ( !v27 )
    {
      invalid_parameter_noinfo();
      if ( v24 >= *(_DWORD *)(a2 + 8) )
      {
        invalid_parameter_noinfo();
        if ( v24 >= *(_DWORD *)(a2 + 8) )
        {
          invalid_parameter_noinfo();
          if ( v24 >= *(_DWORD *)(a2 + 8) )
            invalid_parameter_noinfo();
        }
      }
    }
    HIDWORD(v99) = *(_DWORD *)(v24 + 152) + *(_DWORD *)(v24 + 156) + *(_DWORD *)(v24 + 160) + *(_DWORD *)(v24 + 164);
    v27 = v24 < *(_DWORD *)(a2 + 8);
    v99 = (double)HIDWORD(v99);
    if ( !v27 )
      invalid_parameter_noinfo();
    v27 = v24 < *(_DWORD *)(a2 + 8);
    v64 = *(_DWORD *)v24;
    if ( !v27 )
      invalid_parameter_noinfo();
    v27 = v24 < *(_DWORD *)(a2 + 8);
    v65 = *(_DWORD *)(v24 + 4);
    if ( !v27 )
    {
      invalid_parameter_noinfo();
      if ( v24 >= *(_DWORD *)(a2 + 8) )
      {
        invalid_parameter_noinfo();
        if ( v24 >= *(_DWORD *)(a2 + 8) )
        {
          invalid_parameter_noinfo();
          if ( v24 >= *(_DWORD *)(a2 + 8) )
            invalid_parameter_noinfo();
        }
      }
    }
    v66 = (*(double *)(v24 + 32) + *(double *)(v24 + 24) - *(double *)(v24 + 64) - *(double *)(v24 + 56)) / 10000.0;
    v42 = v102;
    if ( v102 >= 2.220446049250313e-16 )
    {
      v67 = (v97 + v101 - v98 - v96) * 100.0 / v102;
      v44 = 100.0;
      v43 = 0.0;
    }
    else
    {
      v43 = 0.0;
      v67 = 0.0;
      v44 = 100.0;
    }
    v45 = v75;
    v46 = v99 + v75;
    if ( v43 == v99 + v75 )
      goto LABEL_89;
    v47 = v75;
    if ( v102 < 2.220446049250313e-16 )
    {
      v45 = v75;
      v42 = v102;
LABEL_89:
      v50 = v45;
      v68 = v43;
      v49 = 2.220446049250313e-16;
      v48 = v42;
      v47 = v50;
      goto LABEL_90;
    }
    v48 = v102;
    v68 = (v80 + v84 + v82 + v78) * (v99 - v75) / v46 * v44 / v102;
    v49 = 2.220446049250313e-16;
LABEL_90:
    if ( v43 == v47 || v43 == v99 || v49 > v48 )
    {
      v53 = v46;
      v69 = v43;
      v54 = v49;
    }
    else
    {
      v51 = v46;
      v52 = (v97 + v101) / v47;
      v53 = v51;
      v69 = v52 - (v96 + v98) / v99;
      v54 = 2.220446049250313e-16;
    }
    v70 = v53;
    if ( v54 <= v48 )
    {
      v71 = (v101 - v98) * v44 / v48;
      v72 = (v97 - v96) * v44 / v48;
      v73 = (v84 - v82) * v44 / v48;
      v55 = v44 * (v80 - v78) / v48;
    }
    else
    {
      v55 = v43;
      v71 = v43;
      v72 = v43;
      v73 = v43;
    }
    v74 = v55;
    sub_100ACB40(&v64);
    if ( v24 >= *(_DWORD *)(a2 + 8) )
      invalid_parameter_noinfo();
    v24 += 168;
  }
  v56 = CGlobalEnv::GetGlobalEnv((char *)&v101 + 4);
  v104 = 3;
  v57 = *(_DWORD *)(*(_DWORD *)v56 + 144);
  if ( v57 )
  {
    v103 = (CDataMgr *)_RTDynamicCast(v57, 0, &IUnknown `RTTI Type Descriptor', &CDataMgr `RTTI Type Descriptor', 0);
    v58 = v103;
  }
  else
  {
    v58 = 0;
    v103 = 0;
  }
  HIDWORD(v99) = v58;
  if ( v58 )
    (*(void (__stdcall **)(CDataMgr *))(*(_DWORD *)v58 + 4))(v58);
  LOBYTE(v104) = 5;
  if ( HIDWORD(v101) )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)HIDWORD(v101) + 8))(HIDWORD(v101));
  v59 = CDataMgr::GetCurDateByMarket(v58, *(unsigned __int8 *)(*(_DWORD *)(a1[1] + 744) + 332), 0);
  v60 = v100;
  HIDWORD(v102) = v59;
  result = v100[1];
  if ( result )
  {
    result = (v100[2] - result) / 88;
    if ( result > 0 )
    {
      v61 = result - 1;
      v62 = v100[1];
      if ( !v62 || v61 >= (v100[2] - v62) / 88 )
        invalid_parameter_noinfo();
      result = HIDWORD(v102);
      if ( *(_DWORD *)(88 * v61 + v60[1]) < SHIDWORD(v102) )
      {
        memset(&v64, 0, 0x58u);
        v64 = HIDWORD(v102);
        result = sub_100ACB40(&v64);
      }
    }
  }
  v104 = -1;
  if ( v103 )
    result = (*(int (__stdcall **)(CDataMgr *))(*(_DWORD *)v103 + 8))(v103);
  return result;
}	
	
.text:100A9B20
.text:100A9B20 ; =============== S U B R O U T I N E =======================================
.text:100A9B20
.text:100A9B20 ; Attributes: bp-based frame
.text:100A9B20
.text:100A9B20 sub_100A9B20    proc near               ; CODE XREF: sub_10025230+7E1↑p
.text:100A9B20                                         ; sub_10025A80+7CC↑p ...
.text:100A9B20
	/*
.text:100A9B20 var_154         = dword ptr -154h
.text:100A9B20 var_150         = dword ptr -150h
.text:100A9B20 var_14C         = qword ptr -14Ch
.text:100A9B20 var_13C         = qword ptr -13Ch
.text:100A9B20 var_134         = qword ptr -134h
.text:100A9B20 var_12C         = qword ptr -12Ch
.text:100A9B20 var_124         = qword ptr -124h
.text:100A9B20 var_11C         = qword ptr -11Ch
.text:100A9B20 var_114         = qword ptr -114h
.text:100A9B20 var_10C         = qword ptr -10Ch
.text:100A9B20 var_104         = qword ptr -104h
.text:100A9B20 var_FC          = qword ptr -0FCh
.text:100A9B20 var_F4          = qword ptr -0F4h
.text:100A9B20 var_EC          = qword ptr -0ECh
.text:100A9B20 var_E4          = qword ptr -0E4h
.text:100A9B20 var_DC          = qword ptr -0DCh
.text:100A9B20 var_D4          = qword ptr -0D4h
.text:100A9B20 var_CC          = qword ptr -0CCh
.text:100A9B20 var_C4          = qword ptr -0C4h
.text:100A9B20 var_BC          = qword ptr -0BCh
.text:100A9B20 var_B4          = qword ptr -0B4h
.text:100A9B20 var_AC          = qword ptr -0ACh
.text:100A9B20 var_A4          = qword ptr -0A4h
.text:100A9B20 var_9C          = qword ptr -9Ch
.text:100A9B20 var_94          = qword ptr -94h
.text:100A9B20 var_8C          = qword ptr -8Ch
.text:100A9B20 var_84          = qword ptr -84h
.text:100A9B20 var_7C          = qword ptr -7Ch
.text:100A9B20 var_74          = qword ptr -74h
.text:100A9B20 var_6C          = qword ptr -6Ch
.text:100A9B20 var_64          = qword ptr -64h
.text:100A9B20 var_5C          = qword ptr -5Ch
.text:100A9B20 var_54          = qword ptr -54h
.text:100A9B20 var_4C          = qword ptr -4Ch
.text:100A9B20 var_44          = qword ptr -44h
.text:100A9B20 anonymous_0     = qword ptr -3Ch
.text:100A9B20 var_30          = dword ptr -30h
.text:100A9B20 anonymous_2     = qword ptr -2Ch
.text:100A9B20 anonymous_1     = qword ptr -24h
.text:100A9B20 var_18          = dword ptr -18h
.text:100A9B20 var_14          = dword ptr -14h
.text:100A9B20 var_C           = dword ptr -0Ch
.text:100A9B20 var_4           = dword ptr -4
.text:100A9B20 arg_0           = dword ptr  8
.text:100A9B20 arg_4           = dword ptr  0Ch
.text:100A9B20 arg_8           = byte ptr  10h
.text:100A9B20
.text:100A9B20 ; FUNCTION CHUNK AT .text:1006CB30 SIZE 0000000F BYTES
.text:100A9B20 ; FUNCTION CHUNK AT .text:100E54B0 SIZE 00000020 BYTES
.text:100A9B20
.text:100A9B20 ; __unwind { // SEH_100A9B20
.text:100A9B20                 push    ebp
.text:100A9B21                 mov     ebp, esp
.text:100A9B23                 push    0FFFFFFFFh
.text:100A9B25                 push    offset SEH_100A9B20
.text:100A9B2A                 mov     eax, large fs:0
.text:100A9B30                 push    eax
.text:100A9B31                 sub     esp, 148h
.text:100A9B37                 mov     eax, ___security_cookie
.text:100A9B3C                 xor     eax, ebp
.text:100A9B3E                 mov     [ebp+var_14], eax
.text:100A9B41                 push    ebx
.text:100A9B42                 push    esi
.text:100A9B43                 push    edi
.text:100A9B44                 push    eax
.text:100A9B45                 lea     eax, [ebp+var_C]
.text:100A9B48                 mov     large fs:0, eax
.text:100A9B4E                 mov     ecx, [ebp+arg_4]
.text:100A9B51                 mov     ebx, [ebp+arg_0]
.text:100A9B54                 mov     eax, [ebx+4]
.text:100A9B57                 test    eax, eax
.text:100A9B59                 jz      loc_100AA40F
.text:100A9B5F                 cmp     dword ptr [eax+2E8h], 0
.text:100A9B66                 jz      loc_100AA40F
.text:100A9B6C                 mov     eax, [ecx+4]
.text:100A9B6F                 test    eax, eax
.text:100A9B71                 jnz     short loc_100A9B77
.text:100A9B73                 xor     esi, esi
.text:100A9B75                 jmp     short loc_100A9B8D
.text:100A9B77 ; ---------------------------------------------------------------------------
.text:100A9B77
.text:100A9B77 loc_100A9B77:                           ; CODE XREF: sub_100A9B20+51↑j
.text:100A9B77                 mov     ecx, [ecx+8]
.text:100A9B7A                 sub     ecx, eax
.text:100A9B7C                 mov     eax, 30C30C31h
.text:100A9B81                 imul    ecx
.text:100A9B83                 sar     edx, 5
.text:100A9B86                 mov     esi, edx
.text:100A9B88                 shr     esi, 1Fh
.text:100A9B8B                 add     esi, edx
.text:100A9B8D
.text:100A9B8D loc_100A9B8D:                           ; CODE XREF: sub_100A9B20+55↑j
.text:100A9B8D                 mov     eax, [ebx+10h]
.text:100A9B90                 add     ebx, 0Ch
.text:100A9B93                 test    eax, eax
.text:100A9B95                 mov     [ebp+var_30], ebx
.text:100A9B98                 jz      short loc_100A9BB8
.text:100A9B9A                 mov     ecx, [ebx+8]
.text:100A9B9D                 sub     ecx, eax
.text:100A9B9F                 mov     eax, 2E8BA2E9h
.text:100A9BA4                 imul    ecx
.text:100A9BA6                 sar     edx, 4
.text:100A9BA9                 mov     eax, edx
.text:100A9BAB                 shr     eax, 1Fh
.text:100A9BAE                 add     eax, edx
.text:100A9BB0                 cmp     esi, eax
.text:100A9BB2                 jb      loc_100AA40F
.text:100A9BB8
.text:100A9BB8 loc_100A9BB8:                           ; CODE XREF: sub_100A9B20+78↑j
.text:100A9BB8                 cmp     [ebp+arg_8], 0
.text:100A9BBC                 jnz     loc_100A9C76
.text:100A9BC2                 mov     ecx, ebx
.text:100A9BC4                 call    sub_100ACAF0
.text:100A9BC9                 mov     ecx, [ebp+arg_4]
.text:100A9BCC                 mov     esi, eax
.text:100A9BCE                 call    sub_100ACC30
.text:100A9BD3                 cmp     eax, esi
.text:100A9BD5                 jnz     loc_100A9C76
.text:100A9BDB                 mov     ecx, [ebp+arg_4]
.text:100A9BDE                 call    sub_100ACC30
.text:100A9BE3                 test    eax, eax
.text:100A9BE5                 jbe     loc_100A9C76
.text:100A9BEB                 mov     ecx, [ebp+arg_4]
.text:100A9BEE                 call    sub_100ACC30
.text:100A9BF3                 xor     edi, edi
.text:100A9BF5                 mov     esi, ebx
.text:100A9BF7                 mov     [ebp+var_18], eax
.text:100A9BFA                 call    sub_100ACB10
.text:100A9BFF                 mov     esi, [ebp+arg_4]
.text:100A9C02                 mov     dword ptr [ebp+anonymous_1+4], eax
.text:100A9C05                 call    sub_100ACC50
.text:100A9C0A                 mov     eax, [eax]
.text:100A9C0C                 mov     ecx, dword ptr [ebp+anonymous_1+4]
.text:100A9C0F                 cmp     eax, [ecx]
.text:100A9C11                 jnz     short loc_100A9C76
.text:100A9C13                 mov     esi, ebx
.text:100A9C15                 call    sub_100ACB10
.text:100A9C1A                 mov     esi, [ebp+arg_4]
.text:100A9C1D                 add     eax, 4
.text:100A9C20                 mov     dword ptr [ebp+anonymous_1+4], eax
.text:100A9C23                 call    sub_100ACC50
.text:100A9C28                 mov     edx, [eax+4]
.text:100A9C2B                 mov     eax, dword ptr [ebp+anonymous_1+4]
.text:100A9C2E                 cmp     edx, [eax]
.text:100A9C30                 jnz     short loc_100A9C76
.text:100A9C32                 mov     edi, [ebp+var_18]
.text:100A9C35                 add     edi, 0FFFFFFFFh
.text:100A9C38                 mov     esi, ebx
.text:100A9C3A                 call    sub_100ACB10
.text:100A9C3F                 mov     esi, [ebp+arg_4]
.text:100A9C42                 mov     dword ptr [ebp+anonymous_1+4], eax
.text:100A9C45                 call    sub_100ACC50
.text:100A9C4A                 mov     ecx, [eax]
.text:100A9C4C                 mov     edx, dword ptr [ebp+anonymous_1+4]
.text:100A9C4F                 cmp     ecx, [edx]
.text:100A9C51                 jnz     short loc_100A9C76
.text:100A9C53                 mov     esi, ebx
.text:100A9C55                 call    sub_100ACB10
.text:100A9C5A                 mov     esi, [ebp+arg_4]
.text:100A9C5D                 add     eax, 4
.text:100A9C60                 mov     dword ptr [ebp+anonymous_1+4], eax
.text:100A9C63                 call    sub_100ACC50
.text:100A9C68                 mov     eax, [eax+4]
.text:100A9C6B                 mov     ecx, dword ptr [ebp+anonymous_1+4]
.text:100A9C6E                 cmp     eax, [ecx]
.text:100A9C70                 jz      loc_100AA40F
.text:100A9C76
.text:100A9C76 loc_100A9C76:                           ; CODE XREF: sub_100A9B20+9C↑j
.text:100A9C76                                         ; sub_100A9B20+B5↑j ...
.text:100A9C76                 mov     eax, ebx
.text:100A9C78                 call    sub_100ACBF0
.text:100A9C7D                 mov     esi, [ebp+arg_0]
.text:100A9C80                 mov     eax, [esi+4]
.text:100A9C83                 mov     ecx, [eax+170h]
.text:100A9C89                 movzx   edx, byte ptr [eax+174h]
.text:100A9C90                 push    ecx             ; wchar_t *
.text:100A9C91                 xor     edi, edi
.text:100A9C93                 push    edx             ; int
.text:100A9C94                 mov     [ebp+var_18], edi
.text:100A9C97                 call    ?IsZhiShu@@YA_NHPB_W@Z ; IsZhiShu(int,wchar_t const *)
.text:100A9C9C                 add     esp, 8
.text:100A9C9F                 test    al, al
.text:100A9CA1                 jnz     short loc_100A9CB3
.text:100A9CA3                 mov     eax, [esi+4]
.text:100A9CA6                 cmp     byte ptr [eax+174h], 5Ah
.text:100A9CAD                 jnz     loc_100A9D8B
.text:100A9CB3
.text:100A9CB3 loc_100A9CB3:                           ; CODE XREF: sub_100A9B20+181↑j
.text:100A9CB3                 lea     ecx, [ebp+anonymous_1+4]
.text:100A9CB6                 push    ecx
.text:100A9CB7                 mov     [ebp+var_18], 1
.text:100A9CBE                 call    ds:?GetGlobalEnv@CGlobalEnv@@SA?AV?$CComPtr@VCGlobalEnv@@@ATL@@XZ ; CGlobalEnv::GetGlobalEnv(void)
.text:100A9CC4                 add     esp, 4
.text:100A9CC7 ;   try {
.text:100A9CC7                 mov     [ebp+var_4], edi
.text:100A9CCA                 mov     eax, [eax]
.text:100A9CCC                 mov     eax, [eax+90h]
.text:100A9CD2                 call    sub_10046BF0
.text:100A9CD7                 mov     ebx, eax
.text:100A9CD9                 cmp     ebx, edi
.text:100A9CDB                 mov     dword ptr [ebp+anonymous_0+4], ebx
.text:100A9CDE                 jz      short loc_100A9CE8
.text:100A9CE0                 mov     edx, [ebx]
.text:100A9CE2                 mov     eax, [edx+4]
.text:100A9CE5                 push    ebx
.text:100A9CE6                 call    eax
.text:100A9CE6 ;   } // starts at 100A9CC7
.text:100A9CE8
.text:100A9CE8 loc_100A9CE8:                           ; CODE XREF: sub_100A9B20+1BE↑j
.text:100A9CE8 ;   try {
.text:100A9CE8                 mov     byte ptr [ebp+var_4], 2
.text:100A9CEC                 mov     eax, dword ptr [ebp+anonymous_1+4]
.text:100A9CEF                 cmp     eax, edi
.text:100A9CF1                 jz      short loc_100A9CFB
.text:100A9CF3                 mov     ecx, [eax]
.text:100A9CF5                 mov     edx, [ecx+8]
.text:100A9CF8                 push    eax
.text:100A9CF9                 call    edx
.text:100A9CFB
.text:100A9CFB loc_100A9CFB:                           ; CODE XREF: sub_100A9B20+1D1↑j
.text:100A9CFB                 call    off_1017E0B4
.text:100A9D01                 mov     eax, [esi+4]
.text:100A9D04                 mov     cl, [eax+174h]
.text:100A9D0A                 cmp     cl, 5Ah
.text:100A9D0D                 jz      short loc_100A9D1F
.text:100A9D0F                 movzx   eax, cl
.text:100A9D12                 push    eax             ; int
.text:100A9D13                 mov     ecx, ebx        ; this
.text:100A9D15                 call    ?GetTotalLTG@CDataMgr@@QAEMH@Z ; CDataMgr::GetTotalLTG(int)
.text:100A9D1A                 fstp    qword ptr [ebp-24h]
.text:100A9D1D                 jmp     short loc_100A9D78
.text:100A9D1F ; ---------------------------------------------------------------------------
.text:100A9D1F
.text:100A9D1F loc_100A9D1F:                           ; CODE XREF: sub_100A9B20+1ED↑j
.text:100A9D1F                 mov     edi, [eax+170h]
.text:100A9D25                 test    edi, edi
.text:100A9D27                 jnz     short loc_100A9D2D
.text:100A9D29                 xor     eax, eax
.text:100A9D2B                 jmp     short loc_100A9D62
.text:100A9D2D ; ---------------------------------------------------------------------------
.text:100A9D2D
.text:100A9D2D loc_100A9D2D:                           ; CODE XREF: sub_100A9B20+207↑j
.text:100A9D2D                 push    edi             ; lpString
.text:100A9D2E                 call    ds:lstrlenW
.text:100A9D34                 add     eax, 1
.text:100A9D37                 cmp     eax, 3FFFFFFFh
.text:100A9D3C                 jle     short loc_100A9D42
.text:100A9D3E                 xor     eax, eax
.text:100A9D40                 jmp     short loc_100A9D62
.text:100A9D42 ; ---------------------------------------------------------------------------
.text:100A9D42
.text:100A9D42 loc_100A9D42:                           ; CODE XREF: sub_100A9B20+21C↑j
.text:100A9D42                 lea     esi, [eax+eax]
.text:100A9D45                 mov     eax, esi
.text:100A9D47                 call    __alloca_probe_16
.text:100A9D4C                 mov     ecx, esi        ; cchMultiByte
.text:100A9D4E                 mov     edx, 3A8h       ; CodePage
.text:100A9D53                 mov     eax, edi
.text:100A9D55                 mov     esi, esp
.text:100A9D57                 mov     dword ptr [ebp+anonymous_2+4], esp
.text:100A9D5A                 call    sub_10046BC0
.text:100A9D5F                 mov     esi, [ebp+arg_0]
.text:100A9D62
.text:100A9D62 loc_100A9D62:                           ; CODE XREF: sub_100A9B20+20B↑j
.text:100A9D62                                         ; sub_100A9B20+220↑j
.text:100A9D62                 mov     ecx, [esi+4]
.text:100A9D65                 movzx   edx, byte ptr [ecx+174h]
.text:100A9D6C                 push    eax             ; char *
.text:100A9D6D                 push    edx             ; int
.text:100A9D6E                 mov     ecx, ebx        ; this
.text:100A9D70                 call    ?GetLTG@CDataMgr@@QAENHPAD@Z ; CDataMgr::GetLTG(int,char *)
.text:100A9D75                 fstp    qword ptr [ebp-24h]
.text:100A9D78
.text:100A9D78 loc_100A9D78:                           ; CODE XREF: sub_100A9B20+1FD↑j
.text:100A9D78                 test    ebx, ebx
.text:100A9D78 ;   } // starts at 100A9CE8
.text:100A9D7A                 mov     [ebp+var_4], 0FFFFFFFFh
.text:100A9D81                 jz      short loc_100A9D8B
.text:100A9D83                 mov     eax, [ebx]
.text:100A9D85                 mov     ecx, [eax+8]
.text:100A9D88                 push    ebx
.text:100A9D89                 call    ecx
.text:100A9D8B
.text:100A9D8B loc_100A9D8B:                           ; CODE XREF: sub_100A9B20+18D↑j
.text:100A9D8B                                         ; sub_100A9B20+261↑j
.text:100A9D8B                 mov     eax, [ebp+arg_4]
.text:100A9D8E                 mov     edi, [eax+4]
.text:100A9D91                 cmp     edi, [eax+8]
.text:100A9D94                 jbe     short loc_100A9D9C
.text:100A9D96                 call    ds:_invalid_parameter_noinfo
.text:100A9D9C
.text:100A9D9C loc_100A9D9C:                           ; CODE XREF: sub_100A9B20+274↑j
.text:100A9D9C                 mov     eax, [ebp+arg_4]
.text:100A9D9F                 mov     ebx, eax
.text:100A9DA1
.text:100A9DA1 loc_100A9DA1:                           ; CODE XREF: sub_100A9B20+7C9↓j
.text:100A9DA1                 mov     ecx, [eax+8]
.text:100A9DA4                 cmp     [eax+4], ecx
.text:100A9DA7                 mov     dword ptr [ebp+anonymous_2+4], ecx
.text:100A9DAA                 jbe     short loc_100A9DB2
.text:100A9DAC                 call    ds:_invalid_parameter_noinfo
.text:100A9DB2
.text:100A9DB2 loc_100A9DB2:                           ; CODE XREF: sub_100A9B20+28A↑j
.text:100A9DB2                 xor     esi, esi
.text:100A9DB4                 cmp     ebx, esi
.text:100A9DB6                 jz      short loc_100A9DBC
.text:100A9DB8                 cmp     ebx, ebx
.text:100A9DBA                 jz      short loc_100A9DC2
.text:100A9DBC
.text:100A9DBC loc_100A9DBC:                           ; CODE XREF: sub_100A9B20+296↑j
.text:100A9DBC                 call    ds:_invalid_parameter_noinfo
.text:100A9DC2
.text:100A9DC2 loc_100A9DC2:                           ; CODE XREF: sub_100A9B20+29A↑j
.text:100A9DC2                 cmp     edi, dword ptr [ebp+anonymous_2+4]
.text:100A9DC5                 jz      loc_100AA2EE
.text:100A9DCB                 cmp     [ebp+var_18], esi
.text:100A9DCE                 jnz     short loc_100A9DFE
.text:100A9DD0                 cmp     ebx, esi
.text:100A9DD2                 jnz     short loc_100A9DDA
.text:100A9DD4                 call    ds:_invalid_parameter_noinfo
.text:100A9DDA
.text:100A9DDA loc_100A9DDA:                           ; CODE XREF: sub_100A9B20+2B2↑j
.text:100A9DDA                 cmp     edi, [ebx+8]
.text:100A9DDD                 jb      short loc_100A9DE5
.text:100A9DDF                 call    ds:_invalid_parameter_noinfo
.text:100A9DE5
.text:100A9DE5 loc_100A9DE5:                           ; CODE XREF: sub_100A9B20+2BD↑j
.text:100A9DE5                 mov     edx, [edi]
.text:100A9DE7                 mov     eax, [ebp+arg_0]
.text:100A9DEA                 mov     esi, [eax+4]
.text:100A9DED                 push    edx
.text:100A9DEE                 call    sub_10063DA0
.text:100A9DF3                 fmul    ds:dbl_10145380
.text:100A9DF9                 xor     esi, esi
.text:100A9DFB                 fstp    qword ptr [ebp-24h]
.text:100A9DFE
.text:100A9DFE loc_100A9DFE:                           ; CODE XREF: sub_100A9B20+2AE↑j
.text:100A9DFE                 cmp     ebx, esi
.text:100A9E00                 jnz     short loc_100A9E08
.text:100A9E02                 call    ds:_invalid_parameter_noinfo
.text:100A9E08
.text:100A9E08 loc_100A9E08:                           ; CODE XREF: sub_100A9B20+2E0↑j
.text:100A9E08                 cmp     edi, [ebx+8]
.text:100A9E0B                 jb      short loc_100A9E13
.text:100A9E0D                 call    ds:_invalid_parameter_noinfo
.text:100A9E13
.text:100A9E13 loc_100A9E13:                           ; CODE XREF: sub_100A9B20+2EB↑j
.text:100A9E13                 mov     ecx, [edi+60h]
.text:100A9E16                 mov     eax, [edi+64h]
.text:100A9E19                 mov     dword ptr [ebp+var_CC], ecx
.text:100A9E1F                 mov     ecx, eax
.text:100A9E21                 and     eax, 7FFFFFFFh
.text:100A9E26                 and     ecx, 80000000h
.text:100A9E2C                 cmp     edi, [ebx+8]
.text:100A9E2F                 mov     dword ptr [ebp+var_CC+4], eax
.text:100A9E35                 fild    [ebp+var_CC]
.text:100A9E3B                 mov     dword ptr [ebp+var_6C+4], ecx
.text:100A9E3E                 mov     dword ptr [ebp+var_6C], esi
.text:100A9E41                 fild    [ebp+var_6C]
.text:100A9E44                 fchs
.text:100A9E46                 faddp   st(1), st
.text:100A9E48                 fstp    qword ptr [ebp-2Ch]
.text:100A9E4B                 jb      short loc_100A9E53
.text:100A9E4D                 call    ds:_invalid_parameter_noinfo
.text:100A9E53
.text:100A9E53 loc_100A9E53:                           ; CODE XREF: sub_100A9B20+32B↑j
.text:100A9E53                 mov     eax, [edi+5Ch]
.text:100A9E56                 mov     edx, [edi+58h]
.text:100A9E59                 mov     ecx, eax
.text:100A9E5B                 and     eax, 7FFFFFFFh
.text:100A9E60                 and     ecx, 80000000h
.text:100A9E66                 cmp     edi, [ebx+8]
.text:100A9E69                 mov     dword ptr [ebp+var_BC], edx
.text:100A9E6F                 mov     dword ptr [ebp+var_BC+4], eax
.text:100A9E75                 fild    [ebp+var_BC]
.text:100A9E7B                 mov     dword ptr [ebp+var_7C+4], ecx
.text:100A9E7E                 mov     dword ptr [ebp+var_7C], esi
.text:100A9E81                 fild    [ebp+var_7C]
.text:100A9E84                 fchs
.text:100A9E86                 faddp   st(1), st
.text:100A9E88                 fstp    [ebp+var_4C]
.text:100A9E8B                 jb      short loc_100A9E93
.text:100A9E8D                 call    ds:_invalid_parameter_noinfo
.text:100A9E93
.text:100A9E93 loc_100A9E93:                           ; CODE XREF: sub_100A9B20+36B↑j
.text:100A9E93                 mov     ecx, [edi+50h]
.text:100A9E96                 mov     eax, [edi+54h]
.text:100A9E99                 mov     dword ptr [ebp+var_F4], ecx
.text:100A9E9F                 mov     ecx, eax
.text:100A9EA1                 and     eax, 7FFFFFFFh
.text:100A9EA6                 and     ecx, 80000000h
.text:100A9EAC                 cmp     edi, [ebx+8]
.text:100A9EAF                 mov     dword ptr [ebp+var_F4+4], eax
.text:100A9EB5                 fild    [ebp+var_F4]
.text:100A9EBB                 mov     dword ptr [ebp+var_8C+4], ecx
.text:100A9EC1                 mov     dword ptr [ebp+var_8C], esi
.text:100A9EC7                 fild    [ebp+var_8C]
.text:100A9ECD                 fchs
.text:100A9ECF                 faddp   st(1), st
.text:100A9ED1                 fstp    [ebp+var_B4]
.text:100A9ED7                 jb      short loc_100A9EDF
.text:100A9ED9                 call    ds:_invalid_parameter_noinfo
.text:100A9EDF
.text:100A9EDF loc_100A9EDF:                           ; CODE XREF: sub_100A9B20+3B7↑j
.text:100A9EDF                 mov     eax, [edi+4Ch]
.text:100A9EE2                 mov     edx, [edi+48h]
.text:100A9EE5                 mov     ecx, eax
.text:100A9EE7                 and     eax, 7FFFFFFFh
.text:100A9EEC                 and     ecx, 80000000h
.text:100A9EF2                 cmp     edi, [ebx+8]
.text:100A9EF5                 mov     dword ptr [ebp+var_5C], edx
.text:100A9EF8                 mov     dword ptr [ebp+var_5C+4], eax
.text:100A9EFB                 fild    [ebp+var_5C]
.text:100A9EFE                 mov     dword ptr [ebp+var_9C+4], ecx
.text:100A9F04                 mov     dword ptr [ebp+var_9C], esi
.text:100A9F0A                 fild    [ebp+var_9C]
.text:100A9F10                 fchs
.text:100A9F12                 faddp   st(1), st
.text:100A9F14                 fstp    [ebp+var_D4]
.text:100A9F1A                 jb      short loc_100A9F22
.text:100A9F1C                 call    ds:_invalid_parameter_noinfo
.text:100A9F22
.text:100A9F22 loc_100A9F22:                           ; CODE XREF: sub_100A9B20+3FA↑j
.text:100A9F22                 mov     ecx, [edi+80h]
.text:100A9F28                 mov     eax, [edi+84h]
.text:100A9F2E                 mov     dword ptr [ebp+var_EC], ecx
.text:100A9F34                 mov     ecx, eax
.text:100A9F36                 and     eax, 7FFFFFFFh
.text:100A9F3B                 and     ecx, 80000000h
.text:100A9F41                 cmp     edi, [ebx+8]
.text:100A9F44                 mov     dword ptr [ebp+var_EC+4], eax
.text:100A9F4A                 fild    [ebp+var_EC]
.text:100A9F50                 mov     dword ptr [ebp+var_AC+4], ecx
.text:100A9F56                 mov     dword ptr [ebp+var_AC], esi
.text:100A9F5C                 fild    [ebp+var_AC]
.text:100A9F62                 fchs
.text:100A9F64                 faddp   st(1), st
.text:100A9F66                 fstp    [ebp+var_44]
.text:100A9F69                 jb      short loc_100A9F71
.text:100A9F6B                 call    ds:_invalid_parameter_noinfo
.text:100A9F71
.text:100A9F71 loc_100A9F71:                           ; CODE XREF: sub_100A9B20+449↑j
.text:100A9F71                 mov     eax, [edi+7Ch]
.text:100A9F74                 mov     edx, [edi+78h]
.text:100A9F77                 mov     ecx, eax
.text:100A9F79                 and     eax, 7FFFFFFFh
.text:100A9F7E                 and     ecx, 80000000h
.text:100A9F84                 cmp     edi, [ebx+8]
.text:100A9F87                 mov     dword ptr [ebp+var_DC], edx
.text:100A9F8D                 mov     dword ptr [ebp+var_DC+4], eax
.text:100A9F93                 fild    [ebp+var_DC]
.text:100A9F99                 mov     dword ptr [ebp+var_64+4], ecx
.text:100A9F9C                 mov     dword ptr [ebp+var_64], esi
.text:100A9F9F                 fild    [ebp+var_64]
.text:100A9FA2                 fchs
.text:100A9FA4                 faddp   st(1), st
.text:100A9FA6                 fstp    [ebp+var_54]
.text:100A9FA9                 jb      short loc_100A9FB1
.text:100A9FAB                 call    ds:_invalid_parameter_noinfo
.text:100A9FB1
.text:100A9FB1 loc_100A9FB1:                           ; CODE XREF: sub_100A9B20+489↑j
.text:100A9FB1                 mov     ecx, [edi+70h]
.text:100A9FB4                 mov     eax, [edi+74h]
.text:100A9FB7                 mov     dword ptr [ebp+var_74], ecx
.text:100A9FBA                 mov     ecx, eax
.text:100A9FBC                 and     eax, 7FFFFFFFh
.text:100A9FC1                 and     ecx, 80000000h
.text:100A9FC7                 cmp     edi, [ebx+8]
.text:100A9FCA                 mov     dword ptr [ebp+var_74+4], eax
.text:100A9FCD                 fild    [ebp+var_74]
.text:100A9FD0                 mov     dword ptr [ebp+var_84+4], ecx
.text:100A9FD3                 mov     dword ptr [ebp+var_84], esi
.text:100A9FD9                 fild    [ebp+var_84]
.text:100A9FDF                 fchs
.text:100A9FE1                 faddp   st(1), st
.text:100A9FE3                 fstp    [ebp+var_C4]
.text:100A9FE9                 jb      short loc_100A9FF1
.text:100A9FEB                 call    ds:_invalid_parameter_noinfo
.text:100A9FF1
.text:100A9FF1 loc_100A9FF1:                           ; CODE XREF: sub_100A9B20+4C9↑j
.text:100A9FF1                 mov     eax, [edi+6Ch]
.text:100A9FF4                 mov     edx, [edi+68h]
.text:100A9FF7                 mov     ecx, eax
.text:100A9FF9                 and     eax, 7FFFFFFFh
.text:100A9FFE                 and     ecx, 80000000h
.text:100AA004                 cmp     edi, [ebx+8]
.text:100AA007                 mov     dword ptr [ebp+var_94], edx
.text:100AA00D                 mov     dword ptr [ebp+var_94+4], eax
.text:100AA013                 fild    [ebp+var_94]
.text:100AA019                 mov     dword ptr [ebp+var_A4+4], ecx
.text:100AA01F                 mov     dword ptr [ebp+var_A4], esi
.text:100AA025                 fild    [ebp+var_A4]
.text:100AA02B                 fchs
.text:100AA02D                 faddp   st(1), st
.text:100AA02F                 fstp    [ebp+var_E4]
.text:100AA035                 jb      short loc_100AA05E
.text:100AA037                 call    ds:_invalid_parameter_noinfo
.text:100AA03D                 cmp     edi, [ebx+8]
.text:100AA040                 jb      short loc_100AA05E
.text:100AA042                 call    ds:_invalid_parameter_noinfo
.text:100AA048                 cmp     edi, [ebx+8]
.text:100AA04B                 jb      short loc_100AA05E
.text:100AA04D                 call    ds:_invalid_parameter_noinfo
.text:100AA053                 cmp     edi, [ebx+8]
.text:100AA056                 jb      short loc_100AA05E
.text:100AA058                 call    ds:_invalid_parameter_noinfo
.text:100AA05E
.text:100AA05E loc_100AA05E:                           ; CODE XREF: sub_100A9B20+515↑j
.text:100AA05E                                         ; sub_100A9B20+520↑j ...
.text:100AA05E                 mov     eax, [edi+94h]
.text:100AA064                 add     eax, [edi+90h]
.text:100AA06A                 add     eax, [edi+8Ch]
.text:100AA070                 add     eax, [edi+88h]
.text:100AA076                 test    eax, eax
.text:100AA078                 mov     dword ptr [ebp+anonymous_0+4], eax
.text:100AA07B                 fild    dword ptr [ebp+anonymous_0+4]
.text:100AA07E                 jge     short loc_100AA086
.text:100AA080                 fadd    ds:dbl_10145608
.text:100AA086
.text:100AA086 loc_100AA086:                           ; CODE XREF: sub_100A9B20+55E↑j
.text:100AA086                 cmp     edi, [ebx+8]
.text:100AA089                 fstp    [ebp+var_FC]
.text:100AA08F                 jb      short loc_100AA0B8
.text:100AA091                 call    ds:_invalid_parameter_noinfo
.text:100AA097                 cmp     edi, [ebx+8]
.text:100AA09A                 jb      short loc_100AA0B8
.text:100AA09C                 call    ds:_invalid_parameter_noinfo
.text:100AA0A2                 cmp     edi, [ebx+8]
.text:100AA0A5                 jb      short loc_100AA0B8
.text:100AA0A7                 call    ds:_invalid_parameter_noinfo
.text:100AA0AD                 cmp     edi, [ebx+8]
.text:100AA0B0                 jb      short loc_100AA0B8
.text:100AA0B2                 call    ds:_invalid_parameter_noinfo
.text:100AA0B8
.text:100AA0B8 loc_100AA0B8:                           ; CODE XREF: sub_100A9B20+56F↑j
.text:100AA0B8                                         ; sub_100A9B20+57A↑j ...
.text:100AA0B8                 mov     ecx, [edi+0A4h]
.text:100AA0BE                 add     ecx, [edi+0A0h]
.text:100AA0C4                 add     ecx, [edi+9Ch]
.text:100AA0CA                 add     ecx, [edi+98h]
.text:100AA0D0                 test    ecx, ecx
.text:100AA0D2                 mov     dword ptr [ebp+anonymous_0+4], ecx
.text:100AA0D5                 fild    dword ptr [ebp+anonymous_0+4]
.text:100AA0D8                 jge     short loc_100AA0E0
.text:100AA0DA                 fadd    ds:dbl_10145608
.text:100AA0E0
.text:100AA0E0 loc_100AA0E0:                           ; CODE XREF: sub_100A9B20+5B8↑j
.text:100AA0E0                 cmp     edi, [ebx+8]
.text:100AA0E3                 fstp    qword ptr [ebp-3Ch]
.text:100AA0E6                 jb      short loc_100AA0EE
.text:100AA0E8                 call    ds:_invalid_parameter_noinfo
.text:100AA0EE
.text:100AA0EE loc_100AA0EE:                           ; CODE XREF: sub_100A9B20+5C6↑j
.text:100AA0EE                 cmp     edi, [ebx+8]
.text:100AA0F1                 mov     edx, [edi]
.text:100AA0F3                 mov     [ebp+var_154], edx
.text:100AA0F9                 jb      short loc_100AA101
.text:100AA0FB                 call    ds:_invalid_parameter_noinfo
.text:100AA101
.text:100AA101 loc_100AA101:                           ; CODE XREF: sub_100A9B20+5D9↑j
.text:100AA101                 cmp     edi, [ebx+8]
.text:100AA104                 mov     eax, [edi+4]
.text:100AA107                 mov     [ebp+var_150], eax
.text:100AA10D                 jb      short loc_100AA136
.text:100AA10F                 call    ds:_invalid_parameter_noinfo
.text:100AA115                 cmp     edi, [ebx+8]
.text:100AA118                 jb      short loc_100AA136
.text:100AA11A                 call    ds:_invalid_parameter_noinfo
.text:100AA120                 cmp     edi, [ebx+8]
.text:100AA123                 jb      short loc_100AA136
.text:100AA125                 call    ds:_invalid_parameter_noinfo
.text:100AA12B                 cmp     edi, [ebx+8]
.text:100AA12E                 jb      short loc_100AA136
.text:100AA130                 call    ds:_invalid_parameter_noinfo
.text:100AA136
.text:100AA136 loc_100AA136:                           ; CODE XREF: sub_100A9B20+5ED↑j
.text:100AA136                                         ; sub_100A9B20+5F8↑j ...  浮点数操作
.text:100AA136                 fld     qword ptr [edi+20h]  超大单入
.text:100AA139                 fadd    qword ptr [edi+18h]  大单入
.text:100AA13C                 fsub    qword ptr [edi+40h]
.text:100AA13F                 fsub    qword ptr [edi+38h]
.text:100AA142                 fdiv    ds:dbl_10145380
.text:100AA148                 fstp    [ebp+var_14C]
.text:100AA14E                 fld     ds:dbl_101454E8
.text:100AA154                 fld     qword ptr [ebp-24h]
.text:100AA157                 fcom    st(1)
.text:100AA159                 fnstsw  ax
.text:100AA15B                 test    ah, 5
.text:100AA15E                 jp      short loc_100AA170
.text:100AA160                 fldz
.text:100AA162                 fst     [ebp+var_13C]
.text:100AA168                 fld     ds:dbl_10145390
.text:100AA16E                 jmp     short loc_100AA192
.text:100AA170 ; ---------------------------------------------------------------------------
.text:100AA170
.text:100AA170 loc_100AA170:                           ; CODE XREF: sub_100A9B20+63E↑j
.text:100AA170                 fld     [ebp+var_4C]
.text:100AA173                 fadd    qword ptr [ebp-2Ch]
.text:100AA176                 fsub    [ebp+var_44]
.text:100AA179                 fsub    [ebp+var_54]
.text:100AA17C                 fld     ds:dbl_10145390
.text:100AA182                 fmul    st(1), st
.text:100AA184                 fxch    st(1)
.text:100AA186                 fdiv    st, st(2)
.text:100AA188                 fstp    [ebp+var_13C]
.text:100AA18E                 fldz
.text:100AA190                 fxch    st(1)
.text:100AA192
.text:100AA192 loc_100AA192:                           ; CODE XREF: sub_100A9B20+64E↑j
.text:100AA192                 fld     qword ptr [ebp-3Ch]
.text:100AA195                 fld     st
.text:100AA197                 fld     [ebp+var_FC]
.text:100AA19D                 fadd    st(1), st
.text:100AA19F                 fld     st(4)
.text:100AA1A1                 fucomp  st(2)
.text:100AA1A3                 fnstsw  ax
.text:100AA1A5                 test    ah, 44h
.text:100AA1A8                 jnp     short loc_100AA1EB
.text:100AA1AA                 fxch    st(5)
.text:100AA1AC                 fcom    st(6)
.text:100AA1AE                 fnstsw  ax
.text:100AA1B0                 test    ah, 5
.text:100AA1B3                 jnp     short loc_100AA1E9
.text:100AA1B5                 fstp    st(6)
.text:100AA1B7                 fld     [ebp+var_D4]
.text:100AA1BD                 fadd    [ebp+var_B4]
.text:100AA1C3                 fadd    [ebp+var_C4]
.text:100AA1C9                 fadd    [ebp+var_E4]
.text:100AA1CF                 fld     st(2)
.text:100AA1D1                 fsub    st, st(6)
.text:100AA1D3                 fmulp   st(1), st
.text:100AA1D5                 fdiv    st, st(1)
.text:100AA1D7                 fmul    st, st(3)
.text:100AA1D9                 fdiv    st, st(6)
.text:100AA1DB                 fstp    [ebp+var_134]
.text:100AA1E1                 fld     ds:dbl_101454E8
.text:100AA1E7                 jmp     short loc_100AA1FD
.text:100AA1E9 ; ---------------------------------------------------------------------------
.text:100AA1E9
.text:100AA1E9 loc_100AA1E9:                           ; CODE XREF: sub_100A9B20+693↑j
.text:100AA1E9                 fxch    st(5)
.text:100AA1EB
.text:100AA1EB loc_100AA1EB:                           ; CODE XREF: sub_100A9B20+688↑j
.text:100AA1EB                 fxch    st(4)
.text:100AA1ED                 fst     [ebp+var_134]
.text:100AA1F3                 fxch    st(5)
.text:100AA1F5                 fxch    st(6)
.text:100AA1F7                 fxch    st(4)
.text:100AA1F9                 fxch    st(5)
.text:100AA1FB                 fxch    st(4)
.text:100AA1FD
.text:100AA1FD loc_100AA1FD:                           ; CODE XREF: sub_100A9B20+6C7↑j
.text:100AA1FD                 fld     st(4)
.text:100AA1FF                 fucomp  st(6)
.text:100AA201                 fnstsw  ax
.text:100AA203                 test    ah, 44h
.text:100AA206                 jnp     short loc_100AA240
.text:100AA208                 fld     st(4)
.text:100AA20A                 fucomp  st(3)
.text:100AA20C                 fnstsw  ax
.text:100AA20E                 test    ah, 44h
.text:100AA211                 jnp     short loc_100AA240
.text:100AA213                 fcom    st(6)
.text:100AA215                 fnstsw  ax
.text:100AA217                 test    ah, 41h
.text:100AA21A                 jz      short loc_100AA240
.text:100AA21C                 fstp    st
.text:100AA21E                 fld     [ebp+var_4C]
.text:100AA221                 fadd    qword ptr [ebp-2Ch]
.text:100AA224                 fdivrp  st(5), st
.text:100AA226                 fld     [ebp+var_54]
.text:100AA229                 fadd    [ebp+var_44]
.text:100AA22C                 fdivrp  st(2), st
.text:100AA22E                 fxch    st(4)
.text:100AA230                 fsubrp  st(1), st
.text:100AA232                 fstp    [ebp+var_12C]
.text:100AA238                 fld     ds:dbl_101454E8
.text:100AA23E                 jmp     short loc_100AA24E
.text:100AA240 ; ---------------------------------------------------------------------------
.text:100AA240
.text:100AA240 loc_100AA240:                           ; CODE XREF: sub_100A9B20+6E6↑j
.text:100AA240                                         ; sub_100A9B20+6F1↑j ...
.text:100AA240                 fstp    st(2)
.text:100AA242                 fstp    st(4)
.text:100AA244                 fxch    st(2)
.text:100AA246                 fst     [ebp+var_12C]
.text:100AA24C                 fxch    st(2)
.text:100AA24E
.text:100AA24E loc_100AA24E:                           ; CODE XREF: sub_100A9B20+71E↑j
.text:100AA24E                 fxch    st(3)
.text:100AA250                 fstp    [ebp+var_124]
.text:100AA256                 fxch    st(2)
.text:100AA258                 fcomp   st(3)
.text:100AA25A                 fnstsw  ax
.text:100AA25C                 test    ah, 41h
.text:100AA25F                 jnz     short loc_100AA279
.text:100AA261                 fstp    st(2)
.text:100AA263                 fstp    st
.text:100AA265                 fst     [ebp+var_11C]
.text:100AA26B                 fst     [ebp+var_114]
.text:100AA271                 fst     [ebp+var_10C]
.text:100AA277                 jmp     short loc_100AA2C1
.text:100AA279 ; ---------------------------------------------------------------------------
.text:100AA279
.text:100AA279 loc_100AA279:                           ; CODE XREF: sub_100A9B20+73F↑j
.text:100AA279                 fstp    st
.text:100AA27B                 fld     qword ptr [ebp-2Ch]
.text:100AA27E                 fsub    [ebp+var_44]
.text:100AA281                 fmul    st, st(1)
.text:100AA283                 fdiv    st, st(2)
.text:100AA285                 fstp    [ebp+var_11C]
.text:100AA28B                 fld     [ebp+var_4C]
.text:100AA28E                 fsub    [ebp+var_54]
.text:100AA291                 fmul    st, st(1)
.text:100AA293                 fdiv    st, st(2)
.text:100AA295                 fstp    [ebp+var_114]
.text:100AA29B                 fld     [ebp+var_B4]
.text:100AA2A1                 fsub    [ebp+var_C4]
.text:100AA2A7                 fmul    st, st(1)
.text:100AA2A9                 fdiv    st, st(2)
.text:100AA2AB                 fstp    [ebp+var_10C]
.text:100AA2B1                 fld     [ebp+var_D4]
.text:100AA2B7                 fsub    [ebp+var_E4]
.text:100AA2BD                 fmulp   st(1), st
.text:100AA2BF                 fdivrp  st(1), st
.text:100AA2C1
.text:100AA2C1 loc_100AA2C1:                           ; CODE XREF: sub_100A9B20+757↑j
.text:100AA2C1                 mov     esi, [ebp+var_30]
.text:100AA2C4                 fstp    [ebp+var_104]
.text:100AA2CA                 lea     ecx, [ebp+var_154]
.text:100AA2D0                 push    ecx
.text:100AA2D1                 call    sub_100ACB40
.text:100AA2D6                 cmp     edi, [ebx+8]
.text:100AA2D9                 jb      short loc_100AA2E1
.text:100AA2DB                 call    ds:_invalid_parameter_noinfo
.text:100AA2E1
.text:100AA2E1 loc_100AA2E1:                           ; CODE XREF: sub_100A9B20+7B9↑j
.text:100AA2E1                 add     edi, 0A8h
.text:100AA2E7                 mov     eax, ebx
.text:100AA2E9                 jmp     loc_100A9DA1
.text:100AA2EE ; ---------------------------------------------------------------------------
.text:100AA2EE
.text:100AA2EE loc_100AA2EE:                           ; CODE XREF: sub_100A9B20+2A5↑j
.text:100AA2EE                 lea     edx, [ebp+anonymous_2+4]
.text:100AA2F1                 push    edx
.text:100AA2F2                 call    ds:?GetGlobalEnv@CGlobalEnv@@SA?AV?$CComPtr@VCGlobalEnv@@@ATL@@XZ ; CGlobalEnv::GetGlobalEnv(void)
.text:100AA2F8                 add     esp, 4
.text:100AA2FB ;   try {
.text:100AA2FB                 mov     [ebp+var_4], 3
.text:100AA302                 mov     eax, [eax]
.text:100AA304                 mov     eax, [eax+90h]
.text:100AA30A                 cmp     eax, esi
.text:100AA30C                 jnz     short loc_100AA315
.text:100AA30E                 xor     edi, edi
.text:100AA310                 mov     [ebp+var_18], edi
.text:100AA313                 jmp     short loc_100AA32F
.text:100AA315 ; ---------------------------------------------------------------------------
.text:100AA315
.text:100AA315 loc_100AA315:                           ; CODE XREF: sub_100A9B20+7EC↑j
.text:100AA315                 push    esi
.text:100AA316                 push    offset ??_R0?AVCDataMgr@@@8 ; CDataMgr `RTTI Type Descriptor'
.text:100AA31B                 push    offset ??_R0?AUIUnknown@@@8 ; IUnknown `RTTI Type Descriptor'
.text:100AA320                 push    esi
.text:100AA321                 push    eax
.text:100AA322                 call    __RTDynamicCast
.text:100AA327                 add     esp, 14h
.text:100AA32A                 mov     [ebp+var_18], eax
.text:100AA32D                 mov     edi, eax
.text:100AA32F
.text:100AA32F loc_100AA32F:                           ; CODE XREF: sub_100A9B20+7F3↑j
.text:100AA32F                 cmp     edi, esi
.text:100AA331                 mov     dword ptr [ebp+anonymous_0+4], edi
.text:100AA334                 jz      short loc_100AA33E
.text:100AA336                 mov     eax, [edi]
.text:100AA338                 mov     ecx, [eax+4]
.text:100AA33B                 push    edi
.text:100AA33C                 call    ecx
.text:100AA33C ;   } // starts at 100AA2FB
.text:100AA33E
.text:100AA33E loc_100AA33E:                           ; CODE XREF: sub_100A9B20+814↑j
.text:100AA33E ;   try {
.text:100AA33E                 mov     byte ptr [ebp+var_4], 5
.text:100AA342                 mov     eax, dword ptr [ebp+anonymous_2+4]
.text:100AA345                 cmp     eax, esi
.text:100AA347                 jz      short loc_100AA351
.text:100AA349                 mov     edx, [eax]
.text:100AA34B                 push    eax
.text:100AA34C                 mov     eax, [edx+8]
.text:100AA34F                 call    eax
.text:100AA351
.text:100AA351 loc_100AA351:                           ; CODE XREF: sub_100A9B20+827↑j
.text:100AA351                 mov     ecx, [ebp+arg_0]
.text:100AA354                 mov     edx, [ecx+4]
.text:100AA357                 mov     eax, [edx+2E8h]
.text:100AA35D                 movzx   ecx, byte ptr [eax+14Ch]
.text:100AA364                 push    esi             ; char *
.text:100AA365                 push    ecx             ; int
.text:100AA366                 mov     ecx, edi        ; this
.text:100AA368                 call    ?GetCurDateByMarket@CDataMgr@@QAEHHPBD@Z ; CDataMgr::GetCurDateByMarket(int,char const *)
.text:100AA36D                 mov     edi, [ebp+var_30]
.text:100AA370                 mov     dword ptr [ebp+anonymous_1+4], eax
.text:100AA373                 mov     eax, [edi+4]
.text:100AA376                 cmp     eax, esi
.text:100AA378                 jz      short loc_100AA3F8
.text:100AA37A                 mov     ecx, [edi+8]
.text:100AA37D                 sub     ecx, eax
.text:100AA37F                 mov     eax, 2E8BA2E9h
.text:100AA384                 imul    ecx
.text:100AA386                 sar     edx, 4
.text:100AA389                 mov     eax, edx
.text:100AA38B                 shr     eax, 1Fh
.text:100AA38E                 add     eax, edx
.text:100AA390                 cmp     eax, esi
.text:100AA392                 jle     short loc_100AA3F8
.text:100AA394                 lea     ebx, [eax-1]
.text:100AA397                 mov     eax, [edi+4]
.text:100AA39A                 cmp     eax, esi
.text:100AA39C                 jz      short loc_100AA3B8
.text:100AA39E                 mov     ecx, [edi+8]
.text:100AA3A1                 sub     ecx, eax
.text:100AA3A3                 mov     eax, 2E8BA2E9h
.text:100AA3A8                 imul    ecx
.text:100AA3AA                 sar     edx, 4
.text:100AA3AD                 mov     eax, edx
.text:100AA3AF                 shr     eax, 1Fh
.text:100AA3B2                 add     eax, edx
.text:100AA3B4                 cmp     ebx, eax
.text:100AA3B6                 jb      short loc_100AA3BE
.text:100AA3B8
.text:100AA3B8 loc_100AA3B8:                           ; CODE XREF: sub_100A9B20+87C↑j
.text:100AA3B8                 call    ds:_invalid_parameter_noinfo
.text:100AA3BE
.text:100AA3BE loc_100AA3BE:                           ; CODE XREF: sub_100A9B20+896↑j
.text:100AA3BE                 mov     edx, [edi+4]
.text:100AA3C1                 imul    ebx, 58h
.text:100AA3C4                 mov     eax, dword ptr [ebp+anonymous_1+4]
.text:100AA3C7                 cmp     [ebx+edx], eax
.text:100AA3CA                 jge     short loc_100AA3F8
.text:100AA3CC                 push    58h             ; size_t
.text:100AA3CE                 lea     ecx, [ebp+var_154]
.text:100AA3D4                 push    0               ; int
.text:100AA3D6                 push    ecx             ; void *
.text:100AA3D7                 call    memset
.text:100AA3DC                 mov     edx, dword ptr [ebp+anonymous_1+4]
.text:100AA3DF                 add     esp, 0Ch
.text:100AA3E2                 lea     eax, [ebp+var_154]
.text:100AA3E8                 push    eax
.text:100AA3E9                 mov     esi, edi
.text:100AA3EB                 mov     [ebp+var_154], edx
.text:100AA3F1                 call    sub_100ACB40
.text:100AA3F6                 xor     esi, esi
.text:100AA3F8
.text:100AA3F8 loc_100AA3F8:                           ; CODE XREF: sub_100A9B20+858↑j
.text:100AA3F8                                         ; sub_100A9B20+872↑j ...
.text:100AA3F8                 cmp     [ebp+var_18], esi
.text:100AA3F8 ;   } // starts at 100AA33E
.text:100AA3FB                 mov     [ebp+var_4], 0FFFFFFFFh
.text:100AA402                 jz      short loc_100AA40F
.text:100AA404                 mov     eax, [ebp+var_18]
.text:100AA407                 mov     ecx, [eax]
.text:100AA409                 mov     edx, [ecx+8]
.text:100AA40C                 push    eax
.text:100AA40D                 call    edx
.text:100AA40F
.text:100AA40F loc_100AA40F:                           ; CODE XREF: sub_100A9B20+39↑j
.text:100AA40F                                         ; sub_100A9B20+46↑j ...
.text:100AA40F                 lea     esp, [ebp-164h]
.text:100AA415                 mov     ecx, [ebp+var_C]
.text:100AA418                 mov     large fs:0, ecx
.text:100AA41F                 pop     ecx
.text:100AA420                 pop     edi
.text:100AA421                 pop     esi
.text:100AA422                 pop     ebx
.text:100AA423                 mov     ecx, [ebp+var_14]
.text:100AA426                 xor     ecx, ebp
.text:100AA428                 call    @__security_check_cookie@4 ; __security_check_cookie(x)
.text:100AA42D                 mov     esp, ebp
.text:100AA42F                 pop     ebp
.text:100AA430                 retn    0Ch
.text:100AA430 ; } // starts at 100A9B20
*/
.text:100AA430 sub_100A9B20    endp
.text:100AA430
.text:100AA430 ; ---------------------------------------------------------------------------

	