
typedef struct L2QUOTE
{
	DWORD dwPrice,    //委托价格？？？ 针对第一笔动态计算相对差，线性关系  
				dwTotals,   //委托总股数
				dwPointer,  //委托列表指针？？？   可能在显示时才读取列表？？？何时读入？？
				dwPens,     //委托总笔数
				chWhat;     //？？？作用不明
}

char __thiscall CDataMgr::ProcStkMultiL2Quote(CDataMgr *this, struct MSG_RET_MULTI_L2_QUOTE *pMSG_RET_MULTI_L2_QUOTE)
{
  int v3; // esi
  char v4; // al
  double v5; // st7
  int v6; // esi
  char v7; // al
  double v8; // st7
  wchar_t *v9; // eax
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // edi
  int *v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  _BYTE *v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  float v28; // ecx
  HWND *v29; // eax
  int v30; // eax
  _BYTE *v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  float v35; // ecx
  float v36[2]; // [esp+10h] [ebp-654h]
  int v37; // [esp+18h] [ebp-64Ch]
  int v38; // [esp+28h] [ebp-63Ch]
  int v39; // [esp+2Ch] [ebp-638h]
  int v40; // [esp+30h] [ebp-634h]
  int v41; // [esp+34h] [ebp-630h]
  double v42; // [esp+38h] [ebp-62Ch]
  bool v43; // [esp+43h] [ebp-621h]
  float v44; // [esp+44h] [ebp-620h]
  bool v45; // [esp+4Bh] [ebp-619h]
  float v46; // [esp+4Ch] [ebp-618h]
  bool v47; // [esp+53h] [ebp-611h]
  float v48; // [esp+54h] [ebp-610h]
  char v49; // [esp+5Bh] [ebp-609h]
  CDataMgr *v50; // [esp+5Ch] [ebp-608h]
  char v51; // [esp+63h] [ebp-601h]
  float *v52; // [esp+64h] [ebp-600h]
  int v53; // [esp+68h] [ebp-5FCh]
  int v54; // [esp+6Ch] [ebp-5F8h]
  float *v55; // [esp+70h] [ebp-5F4h]
  int v56; // [esp+74h] [ebp-5F0h]
  int v57; // [esp+78h] [ebp-5ECh]
  char v58; // [esp+7Ch] [ebp-5E8h]
  char v59; // [esp+84h] [ebp-5E0h]
  char v60; // [esp+8Ch] [ebp-5D8h]
  char v61; // [esp+94h] [ebp-5D0h]
  char v62; // [esp+9Ch] [ebp-5C8h]
  char v63; // [esp+A0h] [ebp-5C4h]
  char v64; // [esp+A4h] [ebp-5C0h]
  int j; // [esp+ACh] [ebp-5B8h]
  char v66; // [esp+2C0h] [ebp-3A4h]
  int v67; // [esp+2C8h] [ebp-39Ch]
  int i; // [esp+2CCh] [ebp-398h]
  int v69; // [esp+2D3h] [ebp-391h]
  int v70; // [esp+2D8h] [ebp-38Ch]
  struct CListCompressIf *v71; // [esp+2DCh] [ebp-388h]
  int v72; // [esp+2E0h] [ebp-384h]
  char Src; // [esp+2E4h] [ebp-380h]
  int v74; // [esp+2E5h] [ebp-37Fh]
  int v75; // [esp+2E9h] [ebp-37Bh]
  int v76; // [esp+2EDh] [ebp-377h]
  __int16 v77; // [esp+2F1h] [ebp-373h]
  char v78; // [esp+2F3h] [ebp-371h]
  int v79; // [esp+2F4h] [ebp-370h]
  struct MSG_RET_MULTI_L2_QUOTE *v80; // [esp+2F8h] [ebp-36Ch]
  char v81; // [esp+2FCh] [ebp-368h]
  int v82; // [esp+301h] [ebp-363h]
  float v83; // [esp+30Dh] [ebp-357h]
  float v84; // [esp+311h] [ebp-353h]
  float v85; // [esp+315h] [ebp-34Fh]
  float v86; // [esp+319h] [ebp-34Bh]
  float v87; // [esp+31Dh] [ebp-347h]
  double v88; // [esp+321h] [ebp-343h]
  unsigned __int64 v89; // [esp+329h] [ebp-33Bh]
  float v90; // [esp+331h] [ebp-333h]
  float v91; // [esp+335h] [ebp-32Fh]
  float v92; // [esp+339h] [ebp-32Bh]
  float v93; // [esp+33Dh] [ebp-327h]
  float v94; // [esp+341h] [ebp-323h]
  int v95; // [esp+381h] [ebp-2E3h]
  int v96; // [esp+389h] [ebp-2DBh]
  int v97; // [esp+391h] [ebp-2D3h]
  int v98; // [esp+399h] [ebp-2CBh]
  int v99; // [esp+3A1h] [ebp-2C3h]
  char v100; // [esp+421h] [ebp-243h]
  char v101; // [esp+471h] [ebp-1F3h]
  float v102; // [esp+485h] [ebp-1DFh]
  float v103; // [esp+489h] [ebp-1DBh]
  float v104; // [esp+48Dh] [ebp-1D7h]
  float v105; // [esp+491h] [ebp-1D3h]
  float v106; // [esp+495h] [ebp-1CFh]
  int v107; // [esp+4D5h] [ebp-18Fh]
  int v108; // [esp+4DDh] [ebp-187h]
  int v109; // [esp+4E5h] [ebp-17Fh]
  int v110; // [esp+4EDh] [ebp-177h]
  int v111; // [esp+4F5h] [ebp-16Fh]
  char v112; // [esp+575h] [ebp-EFh]
  char v113; // [esp+5C5h] [ebp-9Fh]
  char v114; // [esp+5D9h] [ebp-8Bh]
  int v115; // [esp+5DAh] [ebp-8Ah]
  unsigned __int64 v116; // [esp+5E2h] [ebp-82h]
  unsigned __int64 v117; // [esp+5EAh] [ebp-7Ah]
  char v118; // [esp+5F2h] [ebp-72h]
  float v119; // [esp+612h] [ebp-52h]
  unsigned __int64 v120; // [esp+616h] [ebp-4Eh]
  char v121; // [esp+61Eh] [ebp-46h]
  int v122; // [esp+64Ch] [ebp-18h]
  struct STK_PER *v123; // [esp+650h] [ebp-14h]
  int *v124; // [esp+654h] [ebp-10h]
  int v125; // [esp+660h] [ebp-4h]

  v124 = &v37;
  v50 = this;
  if ( !pMSG_RET_MULTI_L2_QUOTE || (signed int)*((unsigned __int8 *)pMSG_RET_MULTI_L2_QUOTE + 22) < 1 )
    return 0;
  if ( *(_DWORD *)((char *)pMSG_RET_MULTI_L2_QUOTE + 13) == 1 && *((_BYTE *)pMSG_RET_MULTI_L2_QUOTE + 21) == 2 )
    return 0;
  sub_721C5F0(&v81);
  v80 = (struct MSG_RET_MULTI_L2_QUOTE *)((char *)pMSG_RET_MULTI_L2_QUOTE + 23);
  v123 = 0;
  v71 = 0;
  v122 = 0;
  v72 = 0;
  Src = 0;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0;
  LOBYTE(v69) = 0;
  mfc80xU_293(&v79);
  v125 = 0;
  for ( i = 0; i < *((unsigned __int8 *)pMSG_RET_MULTI_L2_QUOTE + 22); ++i )
  {
    if ( *(_DWORD *)((char *)pMSG_RET_MULTI_L2_QUOTE + 13) == 1 )
      v71 = CDataMgr::GetListCompressPtr(819, *(_DWORD *)((char *)v80 + 9 * i), *((char *)pMSG_RET_MULTI_L2_QUOTE + 21));
    else
      v71 = CListCompressIf::CreateInstance();
      	
    if ( v71 )
    {
      LOBYTE(v125) = 1;
      v49 = (*(int (__thiscall **)(struct CListCompressIf *, int, _DWORD, char *))(*(_DWORD *)v71 + 16))(
              v71,
              (int)v80 + 9 * i + 8,
              *(_DWORD *)((char *)v80 + 9 * i + 4),
              &v81);
              
      if ( v49 )
      {
        v125 = 0;
        v67 = sub_74800A0(*(_DWORD *)((char *)v80 + 9 * i), &Src, (int)&v69);
        if ( v67 != -1 )
        {
          v123 = QDataEngine::App_OneStkInfo(&Src, v69);
          if ( v123 )
          {
            if ( *(_DWORD *)((char *)v123 + 85) || (sub_7497740(), sub_7498420(1, v123)) )
            {
              if ( *(_DWORD *)((char *)v123 + 85) )
              {
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 54) = v83;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 1) = v82;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 58) = v84;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 62) = v85;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 66) = v86;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 70) = v87;
                *(double *)(*(_DWORD *)((char *)v123 + 85) + 74) = v88;
                v3 = *(_DWORD *)((char *)v123 + 85);
                v4 = sub_747FAD0(v69, &Src);
                v5 = v87;
                sub_7128C90(v87, v83, v4);
                *(float *)(v3 + 170) = v5;
                v6 = *(_DWORD *)((char *)v123 + 85);
                v7 = sub_747FAD0(v69, &Src);
                v8 = v87;
                sub_747F640(v87, v83, v7);
                *(float *)(v6 + 174) = v8;
                v48 = v85 - 0.0;
                v47 = log(v48) < 0.00001;
                if ( v47
                  || (v46 = v86 - 0.0, (v45 = log(v46) < 0.00001) != 0)
                  || (v44 = v83 - 0.0, (v43 = log(v44) < 0.00001) != 0) )
                {
                  v42 = 0.0;
                }
                else
                {
                  v42 = (v85 - v86) * 100.0 / v83;
                }
                
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 178) = v42;
                sub_747CC40(&Src, (int)&v79);
                v9 = (wchar_t *)mfc80xU_870(&v79);
                if ( (unsigned __int8)sub_747E750(v69, v9) )
                {
                  v10 = *(_DWORD *)((char *)v123 + 85);
                  *(_QWORD *)v36 = 100i64;
                  *(_QWORD *)(v10 + 82) = v89 / 0x64;
                  v11 = *(_DWORD *)((char *)v123 + 85);
                  *(_QWORD *)v36 = 100i64;
                  *(_QWORD *)(v11 + 214) = v117 / 0x64;
                  v12 = *(_DWORD *)((char *)v123 + 85);
                  *(_QWORD *)v36 = 100i64;
                  *(_QWORD *)(v12 + 206) = v116 / 0x64;
                  v13 = *(_DWORD *)((char *)v123 + 85);
                  *(_QWORD *)v36 = 100i64;
                  *(_QWORD *)(v13 + 194) = v120 / 0x64;
                  *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 202) = v115 / 100;
                }
                else
                {
                  *(_QWORD *)(*(_DWORD *)((char *)v123 + 85) + 82) = v89;
                  *(_QWORD *)(*(_DWORD *)((char *)v123 + 85) + 214) = v117;
                  *(_QWORD *)(*(_DWORD *)((char *)v123 + 85) + 206) = v116;
                  *(_QWORD *)(*(_DWORD *)((char *)v123 + 85) + 194) = v120;
                  *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 202) = v115;
                }
                
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 190) = v119;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 90) = v90;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 98) = v91;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 106) = v92;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 114) = v93;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 122) = v94;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 94) = v95;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 102) = v96;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 110) = v97;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 118) = v98;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 126) = v99;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 130) = v102;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 138) = v103;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 146) = v104;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 154) = v105;
                *(float *)(*(_DWORD *)((char *)v123 + 85) + 162) = v106;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 134) = v107;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 142) = v108;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 150) = v109;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 158) = v110;
                *(_DWORD *)(*(_DWORD *)((char *)v123 + 85) + 166) = v111;
                
                if ( *(_DWORD *)((char *)v123 + 89) || (sub_7497740(), sub_7498420(2, v123)) )
                {
                  if ( *(_DWORD *)((char *)v123 + 89) )
                  {
                    *(_BYTE *)(*(_DWORD *)((char *)v123 + 89) + 684) = v114;
                    memcpy(*(void **)((char *)v123 + 89), &v81, 4u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 4), &v90, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 84), &v95, 0xA0u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 244), &v100, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 324), &v101, 0x14u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 344), &v102, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 424), &v107, 0xA0u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 584), &v112, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 664), &v113, 0x14u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 685), &v118, 0x20u);
                    memcpy((void *)(*(_DWORD *)((char *)v123 + 89) + 717), &v121, 0x24u);
                    if ( *(_DWORD *)((char *)pMSG_RET_MULTI_L2_QUOTE + 13) != 1 )
                    {
                      FreeInstance(v71);
                      v71 = 0;
                    }
                    sub_7157890(v82, 0);
                    v14 = sub_71577D0(&v66);
                    v15 = 100 * sub_7157810(&v66);
                    v122 = v14 + v15 + 10000 * sub_7157850(&v66);
                    v16 = sub_71576A0(&v66);
                    v17 = 100 * sub_7157750(&v66);
                    v72 = v16 + v17 + 10000 * sub_7157790(&v66);
                    QDataEngine::UpdateAppQuoteDateAndTime(v69, v122, v72);
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        if ( *(_DWORD *)((char *)pMSG_RET_MULTI_L2_QUOTE + 13) != 1 )
        {
          FreeInstance(v71);
          v71 = 0;
        }
        LOBYTE(v125) = 0;
      }
    }
  }
  sub_71B6520((char *)&v69 + 1);
  for ( j = 0; j < *((unsigned __int8 *)pMSG_RET_MULTI_L2_QUOTE + 22); ++j )
  {
    LODWORD(v36[1]) = &v69;
    if ( sub_74800A0(*(_DWORD *)((char *)v80 + 9 * j), &Src, (int)&v69) != -1 )
    {
      if ( *(_DWORD *)((char *)pMSG_RET_MULTI_L2_QUOTE + 13) == 1 )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)((char *)v50 + 98));
        LODWORD(v36[1]) = (char *)v80 + 9 * j;
        v18 = sub_7205DD0(&v61, SLODWORD(v36[1]));
        v19 = *v18;
        v20 = v18[1];
        *(int *)((char *)&v69 + 1) = v19;
        v70 = v20;
        v21 = sub_71E8970(&v60);
        if ( (unsigned __int8)sub_713CFF0(v21) )
        {
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v50 + 98));
        }
        else
        {
          LODWORD(v36[1]) = &v64;
          sub_7200840((char *)&v69 + 1);
          sub_7230EF0(LODWORD(v36[1]));
          while ( 1 )
          {
            LODWORD(v36[1]) = &v58;
            sub_7200840((char *)&v69 + 1);
            v22 = sub_715C7B0(LODWORD(v36[1]));
            if ( !(unsigned __int8)sub_713B600(v22) )
              break;
            v56 = mfc80xU_762(32);
            if ( v56 )
              v41 = sub_71B6540(v56);
            else
              v41 = 0;
            v57 = v41;
            sub_721E5E0(v41);
            LOBYTE(v125) = 5;
            v23 = unknown_libname_97(&v63);
            v24 = (_BYTE *)unknown_libname_90(v23);
            *v24 = v69;
            LODWORD(v36[1]) = &Src;
            v25 = unknown_libname_97(&v63);
            v26 = unknown_libname_90(v25);
            strcpy_s((char *)(v26 + 1), 0x10u, (const char *)LODWORD(v36[1]));
            v27 = unknown_libname_97(&v63);
            v36[1] = v28;
            v55 = &v36[1];
            v40 = sub_721E5E0(v27);
            v29 = (HWND *)sub_7217B30(&v64);
            sub_73C3630(*v29, 6u, SLOBYTE(v36[1]));
            LOBYTE(v125) = 0;
            sub_721C780(&v63);
            sub_7206560(&v59, 0);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v50 + 98));
        }
      }
      else
      {
        v53 = mfc80xU_762(32);
        if ( v53 )
          v39 = sub_71B6540(v53);
        else
          v39 = 0;
        v54 = v39;
        sub_721E5E0(v39);
        LOBYTE(v125) = 6;
        v30 = unknown_libname_97(&v62);
        v31 = (_BYTE *)unknown_libname_90(v30);
        *v31 = v69;
        LODWORD(v36[1]) = &Src;
        v32 = unknown_libname_97(&v62);
        v33 = unknown_libname_90(v32);
        strcpy_s((char *)(v33 + 1), 0x10u, (const char *)LODWORD(v36[1]));
        v34 = unknown_libname_97(&v62);
        v36[1] = v35;
        v52 = &v36[1];
        v38 = sub_721E5E0(v34);
        sub_73C3630(*(HWND *)((char *)pMSG_RET_MULTI_L2_QUOTE + 6), 6u, SLOBYTE(v36[1]));
        LOBYTE(v125) = 0;
        sub_721C780(&v62);
      }
    }
  }
  v51 = 1;
  v125 = -1;
  mfc80xU_577(&v79);
  return v51;
}


char __userpurge sub_4EA7550@<al>(COleDispParams *a1@<esi>, _DWORD *ptr)
{
  char result; // al
  int v3; // edi
  int v4; // edx
  int v5; // eax
  int v6; // ecx

  result = (unsigned int)sub_4EA6660(ptr[1], a1);//初始化数据项总数
  v3 = 0;
  if ( *((_DWORD *)a1 + 1) > 0 )
  {
    v4 = 0;
    do
    {
      v5 = v4 + *ptr;   
      v6 = v4 + *(_DWORD *)a1; 
      *(_DWORD *)v6 = *(_DWORD *)(*ptr + v4);   //委托数据搬运，格式待定
      *(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + 4);
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 8);
      *(_DWORD *)(v6 + 12) = *(_DWORD *)(v5 + 12);
      result = *(_BYTE *)(v5 + 16);
      ++v3;
      *(_BYTE *)(v6 + 16) = result;
      v4 += 17;
    }
    while ( v3 < *((_DWORD *)a1 + 1) );
  }
  return result;
}

unsigned int __thiscall sub_4DFF090(_DWORD *this, unsigned int nIndex)
{
  _DWORD *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  if ( nIndex >= sub_4E40A60(this) )
    invalid_parameter_noinfo();
  return v3[1] + 17 * nIndex;
}

char __thiscall sub_4F258D0(int this, void *a2, size_t a3, int a4)
{
  int v4; // eax
  char v6; // [esp+Ch] [ebp-48h]
  int v7; // [esp+50h] [ebp-4h]

  if ( !a2
    || (signed int)a3 <= 0
    || !(unsigned __int8)sub_4F33D10(a3, a2, (void *)(this + 1716), this + 1720, this + 1748, this + 1764) )
  {
    return 0;
  }
  v4 = sub_4F23DF0(&v6);
  v7 = 0;
  sub_4F25990(a4, v4);   //买卖委托有关数据存入A4 
  sub_4EBCDA0(&v6);
  return 1;
}

int __userpurge sub_4F25990@<eax>(int a1@<edi>, int a2)
{
  *(_DWORD *)a1 = *(_DWORD *)a2;
  *(float *)(a1 + 4) = *(float *)(a2 + 4);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a2 + 12);
  *(_WORD *)(a1 + 16) = *(_WORD *)(a2 + 16);
  *(_DWORD *)(a1 + 18) = *(_DWORD *)(a2 + 18);
  *(float *)(a1 + 22) = *(float *)(a2 + 22);
  *(_DWORD *)(a1 + 26) = *(_DWORD *)(a2 + 26);
  *(_DWORD *)(a1 + 30) = *(_DWORD *)(a2 + 30);
  *(_WORD *)(a1 + 34) = *(_WORD *)(a2 + 34);
  *(_DWORD *)(a1 + 36) = *(_DWORD *)(a2 + 36);
  sub_4F27550((COleDispParams *)(a1 + 40), (_DWORD *)(a2 + 40));  
  sub_4F27550((COleDispParams *)(a1 + 48), (_DWORD *)(a2 + 48));
  return a1;
}

char __userpurge sub_4F27550@<al>(COleDispParams *a1@<esi>, _DWORD *a2)
{
  char result; // al
  int v3; // edi
  int v4; // edx
  int v5; // eax
  int v6; // ecx

  result = (unsigned int)sub_4F26660(a2[1], a1);
  v3 = 0;
  if ( *((_DWORD *)a1 + 1) > 0 )
  {
    v4 = 0;
    do
    {
      v5 = v4 + *a2;
      v6 = v4 + *(_DWORD *)a1;
      *(_DWORD *)v6 = *(_DWORD *)(*a2 + v4);
      *(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + 4);
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 8);
      *(_DWORD *)(v6 + 12) = *(_DWORD *)(v5 + 12);
      result = *(_BYTE *)(v5 + 16);
      ++v3;
      *(_BYTE *)(v6 + 16) = result;
      v4 += 17;
    }
    while ( v3 < *((_DWORD *)a1 + 1) );
  }
  return result;
}

//对pL2Quote的内容没有实质性影像，作用？？？？
char __thiscall CDataMgr::ProcHundredsL2Quote(CDataMgr *this, struct MSG_RET_MULTI_L2_QUOTE *pL2Quote)
{
  char result; // al
  void *v3; // ST04_4
  void *v4; // eax
  void *v5; // ST04_4
  void *v6; // eax
  int *v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _BYTE *v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  HWND *v17; // eax
  int v18; // eax
  _BYTE *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // [esp-4h] [ebp-140h]
  int v25; // [esp+4h] [ebp-138h]
  int v26; // [esp+8h] [ebp-134h]
  int v27; // [esp+Ch] [ebp-130h]
  int v28; // [esp+10h] [ebp-12Ch]
  CDataMgr *this; // [esp+14h] [ebp-128h]
  char v30; // [esp+1Bh] [ebp-121h]
  int *v31; // [esp+1Ch] [ebp-120h]
  int v32; // [esp+20h] [ebp-11Ch]
  int v33; // [esp+24h] [ebp-118h]
  int *v34; // [esp+28h] [ebp-114h]
  int v35; // [esp+2Ch] [ebp-110h]
  int v36; // [esp+30h] [ebp-10Ch]
  char v37; // [esp+34h] [ebp-108h]
  char v38; // [esp+3Ch] [ebp-100h]
  char v39; // [esp+44h] [ebp-F8h]
  char v40; // [esp+4Ch] [ebp-F0h]
  char v41; // [esp+58h] [ebp-E4h]
  char v42; // [esp+5Ch] [ebp-E0h]
  char v43; // [esp+60h] [ebp-DCh]
  int j; // [esp+68h] [ebp-D4h]
  int v45; // [esp+6Ch] [ebp-D0h]
  int i; // [esp+70h] [ebp-CCh]
  int v47; // [esp+74h] [ebp-C8h]
  char v48; // [esp+78h] [ebp-C4h]
  char v49; // [esp+7Ch] [ebp-C0h]
  void *thisV50; // [esp+A0h] [ebp-9Ch]
  int v51; // [esp+A4h] [ebp-98h]
  void *v52; // [esp+A8h] [ebp-94h]
  int v53; // [esp+ACh] [ebp-90h]
  char v54[5]; // [esp+B3h] [ebp-89h]
  char v55; // [esp+B8h] [ebp-84h]
  int v56; // [esp+BCh] [ebp-80h]
  int v57; // [esp+C0h] [ebp-7Ch]
  char Src; // [esp+C4h] [ebp-78h]
  int v59; // [esp+C5h] [ebp-77h]
  int v60; // [esp+C9h] [ebp-73h]
  int v61; // [esp+CDh] [ebp-6Fh]
  __int16 v62; // [esp+D1h] [ebp-6Bh]
  char v63; // [esp+D3h] [ebp-69h]
  struct MSG_RET_MULTI_L2_QUOTE *v64; // [esp+D4h] [ebp-68h]
  char v65[4]; // [esp+D8h] [ebp-64h]
  char v66; // [esp+E0h] [ebp-5Ch]
  char v67; // [esp+104h] [ebp-38h]
  char v68; // [esp+114h] [ebp-28h]
  int v69; // [esp+138h] [ebp-4h]

  this = this;
  if ( !pL2Quote || (signed int)*((unsigned __int8 *)pL2Quote + 22) < 1 )
    return 0;
  if ( *((_BYTE *)pL2Quote + 21) == 2 )
    return 0;
  *(_DWORD *)&v54[1] = 0;
  v47 = *((unsigned __int8 *)pL2Quote + 22);
  v64 = (struct MSG_RET_MULTI_L2_QUOTE *)((char *)pL2Quote + 23);
  sub_4E3C520(&v48);  //栈指针的有关变量初始化为0
  v69 = 0;
  sub_4E3CDD0(v65);
  LOBYTE(v69) = 1;
  for ( i = 0; i < v47; ++i )
  {
    if ( *(_DWORD *)((char *)pL2Quote + 13) == 1 )  首笔委托总单数？？？
      *(_DWORD *)&v54[1] = CDataMgr::GetListCompressPtr(this, 817, *(_DWORD *)((char *)v64 + 9 * i), *((char *)pL2Quote + 21));
    else
      *(_DWORD *)&v54[1] = CListCompressIf::CreateInstance();
    if ( *(_DWORD *)&v54[1] )
    {
    	//调用sub_4F258D0  利用其中的函数截获委托队列信息
    	//其中计算买卖委托队列的价位总数，即项数   委托数据已获得
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int, _DWORD, char *))(**(_DWORD **)&v54[1] + 8))(  
             *(_DWORD *)&v54[1],
             (int)v64 + 9 * i + 8,                      
             *(_DWORD *)((char *)v64 + 9 * i + 4),
             &v48) )     //&v48  买卖委托数据存入相关指针
      {
        if ( *(_DWORD *)((char *)pL2Quote + 13) != 1 )
        {
          FreeInstance(*(_DWORD *)&v54[1]);
          *(_DWORD *)&v54[1] = 0;
        }
        v45 = sub_509F6E0(*(_DWORD *)((char *)v64 + 9 * i), &v65[1], (int)v65);
        if ( v45 != -1 )
        {
          memcpy(&v66, &v49, 0x24u);  ???
          if ( thisV50 && v51 > 0 )
          {
            sub_4E3D910(v51);   //无用函数，干扰用？？？
            v24 = 17 * v51;    //委买总笔数，每笔17字节？  其他线程会在数据解码时设置此变量的值
            v3 = thisV50;
            v4 = (void *)sub_4DFF090(&v67, 0);   结果存在何处？？？  v4=&v67[1] + 17 * 0  v67：堆栈上变量，其他线程设置值
            memcpy(v4, v3, v24);
          }
          if ( v52 && v53 > 0 )
          {
            sub_4E3D910(v53);  //无用函数，干扰用？？？
            v24 = 17 * v53;    //委卖总笔数，每笔17字节？  其他线程会在数据解码时设置此变量的值
            v5 = v52;
            v6 = (void *)sub_4DFF090(&v68, 0);   //v6=&v68[1] + 17 * 0  v68：堆栈上变量，其他线程设置值
            memcpy(v6, v5, v24);
          }
          sub_4E3DE20((char *)v64 + 9 * i);
          sub_4E3CE30(v65);
        }
      }
      else if ( *(_DWORD *)((char *)pL2Quote + 13) != 1 )
      {
        FreeInstance(*(_DWORD *)&v54[1]);
        *(_DWORD *)&v54[1] = 0;
      }
    }
  }
  CGlobalEnv::GetGlobalEnv(&v55);
  LOBYTE(v69) = 2;
  if ( (unsigned __int8)unknown_libname_87(&v55) )
  {
    LOBYTE(v69) = 1;
    sub_4E3C780(&v55);
    LOBYTE(v69) = 0;
    sub_4E37AC0(v65);
    v69 = -1;
    sub_4E3CDA0(&v48);
    result = 0;
  }
  else
  {
    sub_4DD6520(&v56);
    Src = 0;
    v59 = 0;
    v60 = 0;
    v61 = 0;
    v62 = 0;
    v63 = 0;
    v54[0] = 0;
    for ( j = 0; j < *((unsigned __int8 *)pL2Quote + 22); ++j )
    {
      v24 = (int)v54;
      if ( sub_50A00A0(*(_DWORD *)((char *)v64 + 9 * j), &Src, (int)v54) != -1 )
      {
        if ( *(_DWORD *)((char *)pL2Quote + 13) == 1 )
        {
          EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 194));
          v24 = (int)v64 + 9 * j;
          v7 = (int *)sub_4E25DD0(&v40, v24);
          v8 = v7[1];
          v56 = *v7;
          v57 = v8;
          v9 = sub_4E08970(&v39);
          if ( (unsigned __int8)sub_4D5CFF0(v9) )
          {
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 194));
          }
          else
          {
            v24 = (int)&v43;
            sub_4E20840(&v56);
            sub_4E50EF0(v24);
            while ( 1 )
            {
              v24 = (int)&v37;
              sub_4E20840(&v56);
              v10 = sub_4D7C7B0(v24);
              if ( !(unsigned __int8)sub_4D5B600(v10) )
                break;
              v35 = mfc80xU_762(32);
              if ( v35 )
                v28 = sub_4DD6540(v35);
              else
                v28 = 0;
              v36 = v28;
              sub_4E3E5E0(v28);
              LOBYTE(v69) = 3;
              v11 = unknown_libname_97(&v42);
              v12 = (_BYTE *)unknown_libname_90(v11);
              *v12 = v54[0];
              v24 = (int)&Src;
              v13 = unknown_libname_97(&v42);
              v14 = unknown_libname_90(v13);
              strcpy_s((char *)(v14 + 1), 0x10u, (const char *)v24);  含股票代码
              v15 = unknown_libname_97(&v42);
              v24 = v16;
              v34 = &v24;
              v27 = sub_4E3E5E0(v15);
              v17 = (HWND *)sub_4E37B30(&v43);
              sub_4FE3630(*v17, 0x51u, v24);
              LOBYTE(v69) = 2;
              sub_4E3C780(&v42);
              sub_4E26560(&v38, 0);
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 194));
          }
        }
        else
        {
          v32 = mfc80xU_762(32);
          if ( v32 )
            v26 = sub_4DD6540(v32);
          else
            v26 = 0;
          v33 = v26;
          sub_4E3E5E0(v26);
          LOBYTE(v69) = 4;
          v18 = unknown_libname_97(&v41);
          v19 = (_BYTE *)unknown_libname_90(v18);
          *v19 = v54[0];
          v24 = (int)&Src;
          v20 = unknown_libname_97(&v41);
          v21 = unknown_libname_90(v20);
          strcpy_s((char *)(v21 + 1), 0x10u, (const char *)v24);
          v22 = unknown_libname_97(&v41);
          v24 = v23;
          v31 = &v24;
          v25 = sub_4E3E5E0(v22);
          sub_4FE3630(*(HWND *)((char *)pL2Quote + 6), 0x51u, v24);
          LOBYTE(v69) = 2;
          sub_4E3C780(&v41);
        }
      }
    }
    v30 = 1;
    LOBYTE(v69) = 1;
    sub_4E3C780(&v55);
    LOBYTE(v69) = 0;
    sub_4E37AC0(v65);
    v69 = -1;
    sub_4E3CDA0(&v48);
    result = v30;
  }
  return result;
}

char __thiscall CDataMgr::ProcStkMultiL2Quote(CDataMgr *this, struct MSG_RET_MULTI_L2_QUOTE *pL2Quote)
{
  int v3; // esi
  char v4; // al
  double v5; // st7
  int v6; // esi
  char v7; // al
  double v8; // st7
  wchar_t *v9; // eax
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // edi
  int *v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  _BYTE *v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  HWND *v29; // eax
  int v30; // eax
  _BYTE *v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  __int64 v36; // [esp+10h] [ebp-654h]
  int v37; // [esp+18h] [ebp-64Ch]
  int v38; // [esp+28h] [ebp-63Ch]
  int v39; // [esp+2Ch] [ebp-638h]
  int v40; // [esp+30h] [ebp-634h]
  int v41; // [esp+34h] [ebp-630h]
  double v42; // [esp+38h] [ebp-62Ch]
  bool v43; // [esp+43h] [ebp-621h]
  float v44; // [esp+44h] [ebp-620h]
  bool v45; // [esp+4Bh] [ebp-619h]
  float v46; // [esp+4Ch] [ebp-618h]
  bool v47; // [esp+53h] [ebp-611h]
  float v48; // [esp+54h] [ebp-610h]
  char v49; // [esp+5Bh] [ebp-609h]
  CDataMgr *thisV50; // [esp+5Ch] [ebp-608h]
  char v51; // [esp+63h] [ebp-601h]
  __int64 *v52; // [esp+64h] [ebp-600h]
  int v53; // [esp+68h] [ebp-5FCh]
  int v54; // [esp+6Ch] [ebp-5F8h]
  __int64 *v55; // [esp+70h] [ebp-5F4h]
  int v56; // [esp+74h] [ebp-5F0h]
  int v57; // [esp+78h] [ebp-5ECh]
  char v58; // [esp+7Ch] [ebp-5E8h]
  char v59; // [esp+8Ch] [ebp-5D8h]
  char v60; // [esp+94h] [ebp-5D0h]
  char v61; // [esp+9Ch] [ebp-5C8h]
  char v62; // [esp+A0h] [ebp-5C4h]
  char v63; // [esp+A4h] [ebp-5C0h]
  int j; // [esp+ACh] [ebp-5B8h]
  char v65; // [esp+2C0h] [ebp-3A4h]
  int v66; // [esp+2C8h] [ebp-39Ch]
  int i; // [esp+2CCh] [ebp-398h]
  int v68; // [esp+2D3h] [ebp-391h]
  int v69; // [esp+2D8h] [ebp-38Ch]
  struct CListCompressIf *v70; // [esp+2DCh] [ebp-388h]
  int v71; // [esp+2E0h] [ebp-384h]
  char Src; // [esp+2E4h] [ebp-380h]
  int v73; // [esp+2E5h] [ebp-37Fh]
  int v74; // [esp+2E9h] [ebp-37Bh]
  int v75; // [esp+2EDh] [ebp-377h]
  __int16 v76; // [esp+2F1h] [ebp-373h]
  char v77; // [esp+2F3h] [ebp-371h]
  int v78; // [esp+2F4h] [ebp-370h]
  struct MSG_RET_MULTI_L2_QUOTE *v79; // [esp+2F8h] [ebp-36Ch]
  char v80; // [esp+2FCh] [ebp-368h]
  int v81; // [esp+301h] [ebp-363h]
  float v82; // [esp+30Dh] [ebp-357h]
  float v83; // [esp+311h] [ebp-353h]
  float v84; // [esp+315h] [ebp-34Fh]
  float v85; // [esp+319h] [ebp-34Bh]
  float v86; // [esp+31Dh] [ebp-347h]
  double v87; // [esp+321h] [ebp-343h]
  unsigned __int64 v88; // [esp+329h] [ebp-33Bh]
  float v89; // [esp+331h] [ebp-333h]
  float v90; // [esp+335h] [ebp-32Fh]
  float v91; // [esp+339h] [ebp-32Bh]
  float v92; // [esp+33Dh] [ebp-327h]
  float v93; // [esp+341h] [ebp-323h]
  int v94; // [esp+381h] [ebp-2E3h]
  int v95; // [esp+389h] [ebp-2DBh]
  int v96; // [esp+391h] [ebp-2D3h]
  int v97; // [esp+399h] [ebp-2CBh]
  int v98; // [esp+3A1h] [ebp-2C3h]
  char v99; // [esp+421h] [ebp-243h]
  char v100; // [esp+471h] [ebp-1F3h]
  float v101; // [esp+485h] [ebp-1DFh]
  float v102; // [esp+489h] [ebp-1DBh]
  float v103; // [esp+48Dh] [ebp-1D7h]
  float v104; // [esp+491h] [ebp-1D3h]
  float v105; // [esp+495h] [ebp-1CFh]
  int v106; // [esp+4D5h] [ebp-18Fh]
  int v107; // [esp+4DDh] [ebp-187h]
  int v108; // [esp+4E5h] [ebp-17Fh]
  int v109; // [esp+4EDh] [ebp-177h]
  int v110; // [esp+4F5h] [ebp-16Fh]
  char v111; // [esp+575h] [ebp-EFh]
  char v112; // [esp+5C5h] [ebp-9Fh]
  char v113; // [esp+5D9h] [ebp-8Bh]
  int v114; // [esp+5DAh] [ebp-8Ah]
  unsigned __int64 v115; // [esp+5E2h] [ebp-82h]
  unsigned __int64 v116; // [esp+5EAh] [ebp-7Ah]
  char v117; // [esp+5F2h] [ebp-72h]
  float v118; // [esp+612h] [ebp-52h]
  unsigned __int64 v119; // [esp+616h] [ebp-4Eh]
  char v120; // [esp+61Eh] [ebp-46h]
  int v121; // [esp+64Ch] [ebp-18h]
  struct STK_PER *v122; // [esp+650h] [ebp-14h]
  int *v123; // [esp+654h] [ebp-10h]
  int v124; // [esp+660h] [ebp-4h]

  v123 = &v37;
  thisV50 = this;
  if ( !pL2Quote || (signed int)*((unsigned __int8 *)pL2Quote + 22) < 1 )   //第二个委托的总单数  ？？
    return 0;
  if ( *(_DWORD *)((char *)pL2Quote + 13) == 1 && *((_BYTE *)pL2Quote + 21) == 2 )  //第1个委托的总笔数  ？？ 第2个委托的总单数
    return 0; 
  sub_4EBC5F0(&v80);
  v79 = (struct MSG_RET_MULTI_L2_QUOTE *)((char *)pL2Quote + 23);
  v122 = 0;
  v70 = 0;
  v121 = 0;
  v71 = 0;
  Src = 0;
  v73 = 0;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  LOBYTE(v68) = 0;
  mfc80xU_293(&v78);
  v124 = 0;
  for ( i = 0; i < *((unsigned __int8 *)pL2Quote + 22); ++i )
  {
    if ( *(_DWORD *)((char *)pL2Quote + 13) == 1 )
      v70 = (struct CListCompressIf *)CDataMgr::GetListCompressPtr(
                                        thisV50,
                                        819,
                                        *(_DWORD *)((char *)v79 + 9 * i),
                                        *((char *)pL2Quote + 21));
    else
      v70 = CListCompressIf::CreateInstance();
    if ( v70 )
    {
      LOBYTE(v124) = 1;
      v49 = (*(int (__thiscall **)(struct CListCompressIf *, int, _DWORD, char *))(*(_DWORD *)v70 + 16))(
              v70,
              (int)v79 + 9 * i + 8,
              *(_DWORD *)((char *)v79 + 9 * i + 4),
              &v80);
      if ( v49 )
      {
        v124 = 0;
        v66 = sub_51200A0(*(_DWORD *)((char *)v79 + 9 * i), &Src, (int)&v68);
        if ( v66 != -1 )
        {
          v122 = QDataEngine::App_OneStkInfo(&Src, v68);
          if ( v122 )
          {
            if ( *(_DWORD *)((char *)v122 + 85) || (sub_5137740(), sub_5138420(1, v122)) )
            {
              if ( *(_DWORD *)((char *)v122 + 85) )
              {
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 54) = v82;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 1) = v81;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 58) = v83;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 62) = v84;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 66) = v85;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 70) = v86;
                *(double *)(*(_DWORD *)((char *)v122 + 85) + 74) = v87;
                v3 = *(_DWORD *)((char *)v122 + 85);
                v4 = sub_511FAD0(v68, &Src);
                v5 = v86;
                sub_4DC8C90(v86, v82, v4);
                *(float *)(v3 + 170) = v5;
                v6 = *(_DWORD *)((char *)v122 + 85);
                v7 = sub_511FAD0(v68, &Src);
                v8 = v86;
                sub_511F640(v86, v82, v7);
                *(float *)(v6 + 174) = v8;
                v48 = v84 - 0.0;
                v47 = log(v48) < 0.00001;
                if ( v47
                  || (v46 = v85 - 0.0, (v45 = log(v46) < 0.00001) != 0)
                  || (v44 = v82 - 0.0, (v43 = log(v44) < 0.00001) != 0) )
                {
                  v42 = 0.0;
                }
                else
                {
                  v42 = (v84 - v85) * 100.0 / v82;
                }
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 178) = v42;
                sub_511CC40(&Src, (int)&v78);
                v9 = (wchar_t *)mfc80xU_870(&v78);
                if ( (unsigned __int8)sub_511E750(v68, v9) )
                {
                  v10 = *(_DWORD *)((char *)v122 + 85);
                  v36 = 100i64;
                  *(_QWORD *)(v10 + 82) = v88 / 0x64;
                  v11 = *(_DWORD *)((char *)v122 + 85);
                  v36 = 100i64;
                  *(_QWORD *)(v11 + 214) = v116 / 0x64;
                  v12 = *(_DWORD *)((char *)v122 + 85);
                  v36 = 100i64;
                  *(_QWORD *)(v12 + 206) = v115 / 0x64;
                  v13 = *(_DWORD *)((char *)v122 + 85);
                  v36 = 100i64;
                  *(_QWORD *)(v13 + 194) = v119 / 0x64;
                  *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 202) = v114 / 100;
                }
                else
                {
                  *(_QWORD *)(*(_DWORD *)((char *)v122 + 85) + 82) = v88;
                  *(_QWORD *)(*(_DWORD *)((char *)v122 + 85) + 214) = v116;
                  *(_QWORD *)(*(_DWORD *)((char *)v122 + 85) + 206) = v115;
                  *(_QWORD *)(*(_DWORD *)((char *)v122 + 85) + 194) = v119;
                  *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 202) = v114;
                }
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 190) = v118;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 90) = v89;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 98) = v90;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 106) = v91;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 114) = v92;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 122) = v93;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 94) = v94;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 102) = v95;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 110) = v96;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 118) = v97;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 126) = v98;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 130) = v101;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 138) = v102;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 146) = v103;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 154) = v104;
                *(float *)(*(_DWORD *)((char *)v122 + 85) + 162) = v105;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 134) = v106;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 142) = v107;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 150) = v108;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 158) = v109;
                *(_DWORD *)(*(_DWORD *)((char *)v122 + 85) + 166) = v110;
                if ( *(_DWORD *)((char *)v122 + 89) || (sub_5137740(), sub_5138420(2, v122)) )
                {
                  if ( *(_DWORD *)((char *)v122 + 89) )
                  {
                    *(_BYTE *)(*(_DWORD *)((char *)v122 + 89) + 684) = v113;
                    memcpy(*(void **)((char *)v122 + 89), &v80, 4u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 4), &v89, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 84), &v94, 0xA0u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 244), &v99, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 324), &v100, 0x14u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 344), &v101, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 424), &v106, 0xA0u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 584), &v111, 0x50u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 664), &v112, 0x14u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 685), &v117, 0x20u);
                    memcpy((void *)(*(_DWORD *)((char *)v122 + 89) + 717), &v120, 0x24u);
                    if ( *(_DWORD *)((char *)pL2Quote + 13) != 1 )
                    {
                      FreeInstance(v70);
                      v70 = 0;
                    }
                    sub_4DF7890(v36, 0);
                    v14 = sub_4DF77D0(&v65);
                    v15 = 100 * sub_4DF7810(&v65);
                    v121 = v14 + v15 + 10000 * sub_4DF7850(&v65);
                    v16 = sub_4DF76A0(&v65);
                    v17 = 100 * sub_4DF7750(&v65);
                    v71 = v16 + v17 + 10000 * sub_4DF7790(&v65);
                    QDataEngine::UpdateAppQuoteDateAndTime(v68, v121, v71);
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        if ( *(_DWORD *)((char *)pL2Quote + 13) != 1 )
        {
          FreeInstance(v70);
          v70 = 0;
        }
        LOBYTE(v124) = 0;
      }
    }
  }
  sub_4E56520((char *)&v68 + 1);
  for ( j = 0; j < *((unsigned __int8 *)pL2Quote + 22); ++j )
  {
    HIDWORD(v36) = &v68;
    if ( sub_51200A0(*(_DWORD *)((char *)v79 + 9 * j), &Src, (int)&v68) != -1 )
    {
      if ( *(_DWORD *)((char *)pL2Quote + 13) == 1 )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)((char *)thisV50 + 98));
        HIDWORD(v36) = (char *)v79 + 9 * j;
        v18 = sub_4EA5DD0(&v60, SHIDWORD(v36));
        v19 = *v18;
        v20 = v18[1];
        *(int *)((char *)&v68 + 1) = v19;
        v69 = v20;
        v21 = sub_4E88970(&v59);
        if ( (unsigned __int8)sub_4DDCFF0(v21) )
        {
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)thisV50 + 98));
        }
        else
        {
          HIDWORD(v36) = &v63;
          sub_4EA0840((char *)&v68 + 1);
          sub_4ED0EF0(HIDWORD(v36));
          while ( 1 )
          {
            HIDWORD(v36) = &v58;
            sub_4EA0840((char *)&v68 + 1);
            v22 = sub_4DFC7B0(HIDWORD(v36));
            if ( !(unsigned __int8)sub_4DDB600(v22) )
              break;
            v56 = mfc80xU_762(32);
            if ( v56 )
              v41 = sub_4E56540(v56);
            else
              v41 = 0;
            v57 = v41;
            sub_4EBE5E0(v41);
            LOBYTE(v124) = 5;
            v23 = unknown_libname_97(&v62);
            v24 = (_BYTE *)unknown_libname_90(v23);
            *v24 = v68;
            HIDWORD(v36) = &Src;
            v25 = unknown_libname_97(&v62);
            v26 = unknown_libname_90(v25);
            strcpy_s((char *)(v26 + 1), 0x10u, (const char *)HIDWORD(v36));
            v27 = unknown_libname_97(&v62);
            HIDWORD(v36) = v28;
            v55 = (__int64 *)((char *)&v36 + 4);
            v40 = sub_4EBE5E0(v27);
            v29 = (HWND *)sub_4EB7B30(&v63);
            sub_5063630(*v29, 6u, SBYTE4(v36));
            LOBYTE(v124) = 0;
            sub_4EBC780(&v62);
            sub_4EA6560(v36, 0);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)thisV50 + 98));
        }
      }
      else
      {
        v53 = mfc80xU_762(32);
        if ( v53 )
          v39 = sub_4E56540(v53);
        else
          v39 = 0;
        v54 = v39;
        sub_4EBE5E0(v39);
        LOBYTE(v124) = 6;
        v30 = unknown_libname_97(&v61);
        v31 = (_BYTE *)unknown_libname_90(v30);
        *v31 = v68;
        HIDWORD(v36) = &Src;
        v32 = unknown_libname_97(&v61);
        v33 = unknown_libname_90(v32);
        strcpy_s((char *)(v33 + 1), 0x10u, (const char *)HIDWORD(v36));
        v34 = unknown_libname_97(&v61);
        HIDWORD(v36) = v35;
        v52 = (__int64 *)((char *)&v36 + 4);
        v38 = sub_4EBE5E0(v34);
        sub_5063630(*(HWND *)((char *)pL2Quote + 6), 6u, SBYTE4(v36));
        LOBYTE(v124) = 0;
        sub_4EBC780(&v61);
      }
    }
  }
  v51 = 1;
  v124 = -1;
  mfc80xU_577(&v78);
  return v51;
}