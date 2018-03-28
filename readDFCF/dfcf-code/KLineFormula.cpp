int __thiscall datacenter_CDataMgr::GetFormulaCalcDataExtraConst
(void *this, int a2, unsigned __int8 a3, int a4, int a5, _DWORD *a6, 
unsigned int a7, unsigned int a8, int a9, int a10)
{
  void *v10; // ST48_4
  _DWORD *v12; // edx
  _DWORD *v13; // [esp+4h] [ebp-4ACh]
  int v14; // [esp+8h] [ebp-4A8h]
  int v15; // [esp+14h] [ebp-49Ch]
  int v16; // [esp+1Ch] [ebp-494h]
  _DWORD *v17; // [esp+28h] [ebp-488h]
  int v18; // [esp+2Ch] [ebp-484h]
  int v19; // [esp+30h] [ebp-480h]
  int v20; // [esp+34h] [ebp-47Ch]
  int v21; // [esp+38h] [ebp-478h]
  int v22; // [esp+3Ch] [ebp-474h]
  int v23; // [esp+40h] [ebp-470h]
  char v24; // [esp+44h] [ebp-46Ch]
  char v25; // [esp+45h] [ebp-46Bh]
  int v26; // [esp+448h] [ebp-68h]
  int v27; // [esp+44Ch] [ebp-64h]
  int v28; // [esp+450h] [ebp-60h]
  int v29; // [esp+47Ch] [ebp-34h]
  int v30; // [esp+480h] [ebp-30h]
  __int16 v31; // [esp+484h] [ebp-2Ch]
  char v32; // [esp+486h] [ebp-2Ah]
  int v33; // [esp+488h] [ebp-28h]
  __int16 v34; // [esp+48Ch] [ebp-24h]
  char v35; // [esp+48Eh] [ebp-22h]
  int v36; // [esp+490h] [ebp-20h]
  int v37; // [esp+494h] [ebp-1Ch]
  int v38; // [esp+498h] [ebp-18h]
  int v39; // [esp+49Ch] [ebp-14h]
  int v40; // [esp+4A0h] [ebp-10h]
  int v41; // [esp+4ACh] [ebp-4h]

  v10 = this;
  ((void (__thiscall *)(int *))unk_4D978B0)(&v28);
  v28 = a5;
  v29 = 0;
  v27 = 0;
  v39 = 0;
  v26 = 0;
  v37 = 0;
  v36 = 0;
  v24 = 0;
  ((void (__cdecl *)(char *, _DWORD, signed int))unk_4EE2C86)(&v25, 0, 1023);
  v38 = 0;
  v40 = 0;
  v37 = ((int (__thiscall *)(void *, _DWORD, _DWORD))datacenter_CDataMgr::GetCurTimeByMarket)(v10, a3, 0);
  v36 = ((int (__thiscall *)(void *, _DWORD, _DWORD))datacenter_CDataMgr::GetCurDateByMarket)(v10, a3, 0);
  if ( !(unsigned __int8)((int (__cdecl *)(unsigned int, int))unk_4EEE9D0)(a8, a4) )
    return 0;
  ((void (__cdecl *)(_DWORD, int *, char *, char *))unk_4D97970)(*a6, &v30, (char *)&v30 + 2, (char *)&v30 + 3);
  ((void (__cdecl *)(_DWORD, __int16 *, char *, char *))unk_4D97A10)(a6[1], &v31, (char *)&v31 + 1, &v32);
  ((void (__cdecl *)(_DWORD, int *, char *, char *))unk_4D97970)(
    a6[10 * (a7 - 1)],
    &v33,
    (char *)&v33 + 2,
    (char *)&v33 + 3);
  ((void (__cdecl *)(_DWORD, __int16 *, char *, char *))unk_4D97A10)(
    a6[10 * (a7 - 1) + 1],
    &v34,
    (char *)&v34 + 1,
    &v35);
  v26 = ((int (__cdecl *)(unsigned int))unk_4EE242E)(51 * a7 | -(51 * (unsigned __int64)a7 >> 32 != 0));
  ((void (__cdecl *)(_DWORD, int, _DWORD *, int, unsigned int, int))unk_4EF53A0)(a3, a2, a6, v26, a7, a10);
  v27 = emfccore_FORMULA_CORE_Create_Use_KLine_Data_Formula(
          sub_4EF6EE0,
          &unk_4EF3380,
          &unk_503CF30,
          v36,
          a4,
          a3,
          a2,
          v30,
          v31,
          v33,
          v34,
          v26,
          a7,
          __PAIR__(&v28, a8));
  if ( v27 )
  {
    v39 = ((int (__cdecl *)(int, int *, char *, unsigned int, int))emfccore_FORMULA_CORE_Exec_Formula_ExtraConst)(
            v27,
            &v38,
            &v24,
            a8,
            a9);
    if ( v39 )
    {
      v16 = ((int (__cdecl *)(signed int))unk_4EE23FE)(16);
      v41 = 0;
      if ( v16 )
        v14 = ((int (__thiscall *)(int))unk_4CC7550)(v16);
      else
        v14 = 0;
      v41 = -1;
      v29 = v14;
      ((void (__thiscall *)(int *))unk_4D97900)(&v18);
      while ( (unsigned __int8)emfccore_FORMULA_CORE_GetNextOutput(v27, v39, &v18) )
      {
        v15 = ((int (__cdecl *)(signed int))unk_4EE23FE)(28);
        if ( v15 )
          v13 = (_DWORD *)((int (__thiscall *)(int))unk_4D97920)(v15);
        else
          v13 = 0;
        v17 = v13;
        v12 = v13 + 1;
        *v12 = v18;
        v12[1] = v19;
        v12[2] = v20;
        v12[3] = v21;
        v12[4] = v22;
        v12[5] = v23;
        *v17 = v38;
        ((void (__thiscall *)(int, _DWORD **))unk_4CC7580)(v29, &v17);
      }
    }
  }
  if ( v26 )
  {
    ((void (__cdecl *)(int))unk_4EE23AA)(v26);
    v26 = 0;
  }
  if ( v29 )
    ((void (__cdecl *)(int, int))unk_4EF37F0)(v29, v27);
  else
    ((void (__cdecl *)(int))emfccore_FORMULA_CORE_Destroy)(v27);
  return v29;
}

_DWORD *__thiscall CDataMgr::GetFormulaCalcData
	(CDataMgr *this, int a2, int a3, int a4, unsigned __int8 a5, 
	int a6, int a7, _DWORD *a8, signed int a9, int a10, int a11)
{
  CDataMgr *v11; // ST48_4
  int v13; // ST28_4
  int v14; // [esp-1Ch] [ebp-4CCh]
  int v15; // [esp+8h] [ebp-4A8h]
  int v16; // [esp+1Ch] [ebp-494h]
  int v17; // [esp+2Ch] [ebp-484h]
  char v18; // [esp+44h] [ebp-46Ch]
  char v19; // [esp+45h] [ebp-46Bh]
  int v20; // [esp+448h] [ebp-68h]
  int v21; // [esp+44Ch] [ebp-64h]
  int v22; // [esp+450h] [ebp-60h]
  int v23; // [esp+47Ch] [ebp-34h]
  int v24; // [esp+480h] [ebp-30h]
  __int16 v25; // [esp+484h] [ebp-2Ch]
  char v26; // [esp+486h] [ebp-2Ah]
  int v27; // [esp+488h] [ebp-28h]
  __int16 v28; // [esp+48Ch] [ebp-24h]
  char v29; // [esp+48Eh] [ebp-22h]
  int v30; // [esp+490h] [ebp-20h]
  int v31; // [esp+494h] [ebp-1Ch]
  int v32; // [esp+498h] [ebp-18h]
  int v33; // [esp+49Ch] [ebp-14h]
  int v34; // [esp+4A0h] [ebp-10h]
  int v35; // [esp+4ACh] [ebp-4h]

  v11 = this;
  sub_4FA78B0(&v22);
  v23 = 0;
  v21 = 0;
  v33 = 0;
  v20 = 0;
  v31 = 0;
  v30 = 0;
  v18 = 0;
  memset(&v19, 0, 0x3FFu);
  v32 = 0;
  v34 = 0;
  v22 = a7;
  v31 = CDataMgr::GetCurTimeByMarket(v11, a5, 0);// 时间
  v30 = CDataMgr::GetCurDateByMarket(v11, a5, 0);// 日期
  if ( !(unsigned __int8)sub_50FE9D0(a10, a6) )
    return 0;
  if ( !a8 || a9 <= 0 )
    return 0;
  sub_4FA7970(*a8, &v24, (char *)&v24 + 2, (char *)&v24 + 3);
  sub_4FA7A10(a8[1], &v25, (char *)&v25 + 1, &v26);
  sub_4FA7970(a8[10 * (a9 - 1)], &v27, (char *)&v27 + 2, (char *)&v27 + 3);
  sub_4FA7A10(a8[10 * (a9 - 1) + 1], &v28, (char *)&v28 + 1, &v29);
  v20 = mfc80xU_265(51 * a9 | -(51 * (unsigned __int64)(unsigned int)a9 >> 32 != 0));
  sub_51053A0(a5, a4, a8, v20, a9, a11);
  LOWORD(v13) = v28;
  BYTE2(v13) = v29;
  LOWORD(v14) = v25;
  BYTE2(v14) = v26;
  v21 = FORMULA_CORE_Create_Use_KLine_Data_Formula(
          sub_5106EE0,
          sub_5103380,
          &unk_524CF2C,
          v30,
          a6,
          a5,
          a4,
          v24,
          v14,
          v27,
          v13,
          v20,
          a9,
          a10,
          &v22);
  if ( v21 )
  {
    v33 = a10 ? FORMULA_CORE_Exec_Formula(v21, &v32, &v18, a10) : FORMULA_CORE_Exec(v21, a2, a3, &v32, &v18);
    if ( v33 )
    {
      v16 = mfc80xU_762(16);
      v35 = 0;
      if ( v16 )
        v15 = sub_4ED7550(v16);
      else
        v15 = 0;
      v35 = -1;
      v23 = v15;
      _AFX_CONTROLPOS::_AFX_CONTROLPOS((_AFX_CONTROLPOS *)&v17);
      FORMULA_CORE_GetNextOutput(v21, v33, &v17);
      JUMPOUT(loc_5108FA5);
    }
  }
  if ( v20 )
  {
    mfc80xU_266(v20);
    v20 = 0;
  }
  if ( v23 )
    sub_51037F0(v23, v21);
  else
    FORMULA_CORE_Destroy(v21);
  return (_DWORD *)v23;
}


// 处理K线信息？？  
 // FORMULA_CORE_Create_Use_KLine_Data_Formula
int __cdecl sub_52902F0(
   void (__cdecl *a1)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD),
   void (__cdecl *a2)(int, signed int), 
   int a3, int a4, int a5, int a6, int a7, int a8, 
   int a9, int a10, int a11, unsigned __int16 *a12, int nBarCountA13, double a14)
{
  int v14; // ebp
  unsigned __int16 *v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  unsigned __int16 *v23; // ecx
  unsigned __int16 *v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  __int16 v28; // dx
  int v29; // edx
  int v30; // ecx
  __int16 v31; // dx
  int v32; // edx
  bool v33; // zf
  bool v34; // sf
  unsigned __int16 *v35; // esi
  int v36; // eax
  unsigned __int16 *v37; // esi
  char *v38; // edi
  int v39; // eax
  _BYTE *v40; // esi
  int v41; // edi
  unsigned __int8 v42; // of
  int v43; // edi
  char *v44; // esi
  char v45; // cl
  char v46; // al
  char v47; // dl
  char v48; // cl
  char v49; // al
  unsigned __int16 *v50; // eax
  unsigned int v51; // edi
  int v52; // ecx
  __int16 v53; // dx
  int v54; // edx
  unsigned __int16 *v55; // ecx
  unsigned int v56; // edi
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // ebx
  int v61; // edx
  int v62; // ecx
  int v63; // eax
  double v64; // st7
  unsigned int v65; // esi
  int v66; // edi
  int v67; // eax
  int v68; // eax
  int v69; // eax
  char v70; // al
  int v71; // ecx
  __int16 v72; // dx
  int v73; // edx
  const void *v74; // eax
  int v75; // ebx
  int v76; // edx
  __int16 v77; // cx
  int v78; // ecx
  const void *v79; // eax
  void (__cdecl *v80)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD); // esi
  unsigned int v81; // edi
  int v82; // ecx
  __int16 v83; // dx
  int v84; // edx
  __int16 v85; // dx
  char v86; // cl
  int v87; // edx
  __int16 v88; // cx
  int v89; // ecx
  __int16 v90; // dx
  int v91; // edx
  _BYTE *v92; // eax
  int v93; // edx
  int v94; // edx
  __int16 v95; // cx
  int v96; // ecx
  unsigned __int16 *v97; // eax
  unsigned __int16 *v98; // ecx
  bool v99; // cf
  unsigned int v100; // ecx
  int v101; // eax
  unsigned __int16 *v102; // eax
  unsigned int v103; // edi
  unsigned __int16 *v104; // ebx
  unsigned int v105; // ebx
  int v106; // esi
  unsigned int v107; // edi
  unsigned int v108; // edi
  int v109; // ebx
  int v110; // eax
  int v111; // eax
  int v112; // eax
  int v113; // esi
  int v114; // esi
  int v115; // ecx
  __int16 v116; // dx
  int v117; // edx
  int v118; // eax
  int v119; // edx
  __int16 v120; // cx
  int v121; // ecx
  int v122; // edi
  int v124; // [esp+40h] [ebp-7Ch]
  __int16 v125; // [esp+44h] [ebp-78h]
  char v126; // [esp+46h] [ebp-76h]
  int v127; // [esp+48h] [ebp-74h]
  double v128; // [esp+4Ch] [ebp-70h]
  double v129; // [esp+54h] [ebp-68h]
  int nBarCount; // [esp+6Ch] [ebp-50h]
  int v131; // [esp+70h] [ebp-4Ch]
  int v132; // [esp+74h] [ebp-48h]
  unsigned __int16 *v133; // [esp+78h] [ebp-44h]
  double v134; // [esp+7Ch] [ebp-40h]
  double v135; // [esp+84h] [ebp-38h]
  unsigned __int16 *v136; // [esp+8Ch] [ebp-30h]
  unsigned __int16 *v137; // [esp+90h] [ebp-2Ch]
  char v138; // [esp+94h] [ebp-28h]
  char v139; // [esp+95h] [ebp-27h]
  char v140; // [esp+96h] [ebp-26h]
  char v141; // [esp+98h] [ebp-24h]
  int v142; // [esp+9Ch] [ebp-20h]
  int v143; // [esp+A0h] [ebp-1Ch]
  int v144; // [esp+A4h] [ebp-18h]
  char v145; // [esp+A8h] [ebp-14h]
  double v146; // [esp+B4h] [ebp-8h]
  int v147; // [esp+ECh] [ebp+30h]
  unsigned __int16 *v148; // [esp+ECh] [ebp+30h]
  void *v149; // [esp+ECh] [ebp+30h]

  v14 = 0;
  if ( !a12 )
    return 0;
  if ( nBarCountA13 <= 0 )
    return 0;
  LOWORD(v128) = 0;
  BYTE2(v128) = 0;
  v125 = 0;
  v126 = 0;
  nBarCount = 0;
  v15 = (unsigned __int16 *)((int (__cdecl *)(signed int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int *, _DWORD, _DWORD))a1)(
                              128,
                              a5,
                              a6,
                              a7,
                              0,
                              *(_DWORD *)&v125,
                              0,
                              LODWORD(v128),
                              &nBarCount,
                              LODWORD(a14),
                              HIDWORD(a14));
  v16 = *(_DWORD *)LODWORD(a14);
  v136 = (unsigned __int16 *)nBarCount;
  v137 = v15;
  if ( !(unsigned __int8)((int (__thiscall *)(void *, int, unsigned __int16 *, int))unk_523227A)(
                           &unk_5361140,
                           v16,
                           v15,
                           nBarCount) )
    return 0;
  v17 = ((int (__cdecl *)(signed int))unk_530BD5C)(20);
  if ( v17 )
    v18 = ((int (__thiscall *)(int))unk_52316B8)(v17);
  else
    v18 = 0;
    
  v131 = v18;
  v19 = ((int (__thiscall *)(int, signed int, void *))unk_523309E)(v18 + 4, 2288, &unk_5231C44);
  if ( v19 )
    v14 = ((int (__thiscall *)(int))unk_5232B44)(v19);
  v20 = 0;
  ((void (__thiscall *)(int, int))unk_52340E8)(v14, a3);
  ((void (__thiscall *)(int, int))unk_52340E8)(v14 + 32, a7);
  *(_DWORD *)(v14 + 40) = a1;
  *(_DWORD *)(v14 + 44) = a2;
  *(_DWORD *)(v14 + 28) = a6;
  *(_DWORD *)(v14 + 4) = a4;                    // lastest trade date
  *(_DWORD *)(v14 + 8) = a8;
  *(_WORD *)(v14 + 12) = a9;
  *(_DWORD *)(v14 + 15) = a10;
  *(_BYTE *)(v14 + 14) = BYTE2(a9);
  *(_WORD *)(v14 + 19) = a11;
  *(_BYTE *)(v14 + 21) = BYTE2(a11);
  *(_DWORD *)(v14 + 2272) = v14 + 48;
  v21 = v131;
  HIDWORD(v129) = 0;
  *(_DWORD *)(v14 + 24) = a5;
  *(_DWORD *)(v14 + 36) = 0;
  *(_DWORD *)(v14 + 156) = v14 + 160;
  *(_BYTE *)(v14 + 328) = 0;
  *(_BYTE *)(v14 + 2284) = 0;
  *(_DWORD *)(v14 + 2280) = 0;
  *(_DWORD *)(v14 + 2148) = v21;
  *(_DWORD *)(v14 + 60) = v21;
  v22 = off_53649AC(HIDWORD(v129));
  off_53649E8(v22);
  *(_DWORD *)(v14 + 2124) = *(_DWORD *)HIDWORD(a14);
  *(_DWORD *)(v14 + 2156) = a2;
  v23 = v136;
  *(_DWORD *)(v14 + 2152) = a1;
  v24 = v137;
  *(_DWORD *)(v14 + 2160) = a6;
  *(_DWORD *)(v14 + 2228) = v23;
  v25 = v131;
  *(_DWORD *)(v14 + 2224) = v24;
  nBarCount = nBarCountA13;
  *(_DWORD *)(v14 + 2280) = nBarCountA13;
  ((void (__thiscall *)(int, int))emfccore_GSHELPER::CGSHelper::SetBarCount)(v25, nBarCount);
  v26 = ((int (__thiscall *)(int, signed int, int))unk_52326D0)(v131 + 4, 51, nBarCountA13);
  HIDWORD(v129) = 51 * nBarCountA13;
  LODWORD(v129) = a12;
  HIDWORD(v128) = v26;
  *(_DWORD *)(v14 + 2120) = v26;
  ((void (__cdecl *)(_DWORD, _DWORD, _DWORD))unk_5318F86)(HIDWORD(v128), LODWORD(v129), HIDWORD(v129));
  if ( (unsigned __int8)((int (__cdecl *)(_DWORD))unk_523171C)(*(_DWORD *)(LODWORD(a14) + 298)) )
  {
    if ( a6 == 1 )
    {
      v27 = *(_DWORD *)(v14 + 15);
      v129 = a14;
      v28 = *(_WORD *)(v14 + 19);
      HIDWORD(v128) = &nBarCount;
      v127 = v27;
      LOBYTE(v27) = *(_BYTE *)(v14 + 21);
      LOWORD(v128) = v28;
      v29 = *(_DWORD *)(v14 + 8);
      BYTE2(v128) = v27;
      LOWORD(v27) = *(_WORD *)(v14 + 12);
      v124 = v29;
      LOBYTE(v29) = *(_BYTE *)(v14 + 14);
      v125 = v27;
      v126 = v29;
      v20 = ((int (__cdecl *)(signed int, int, signed int, const char *, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD))a1)(
              1,
              a5,
              1,
              "000001",
              v124,
              *(_DWORD *)&v125,
              v127,
              LODWORD(v128),
              &nBarCount,
              LODWORD(a14),
              HIDWORD(a14));
    }
    else
    {
      v20 = 0;
      if ( a6 )
      {
        nBarCount = 0;
      }
      else
      {
        v129 = a14;
        v30 = *(_DWORD *)(v14 + 15);
        HIDWORD(v128) = &nBarCount;
        v31 = *(_WORD *)(v14 + 19);
        v127 = v30;
        LOBYTE(v30) = *(_BYTE *)(v14 + 21);
        LOWORD(v128) = v31;
        v32 = *(_DWORD *)(v14 + 8);
        BYTE2(v128) = v30;
        LOWORD(v30) = *(_WORD *)(v14 + 12);
        v124 = v32;
        LOBYTE(v32) = *(_BYTE *)(v14 + 14);
        v125 = v30;
        v126 = v32;
        v20 = ((int (__cdecl *)(signed int, int, _DWORD, const char *, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD))a1)(
                1,
                a5,
                0,
                "399001",
                v124,
                *(_DWORD *)&v125,
                v127,
                LODWORD(v128),
                &nBarCount,
                LODWORD(a14),
                HIDWORD(a14));
      }
    }
  }
  v33 = *(_DWORD *)(v14 + 2280) == 0;
  v34 = *(_DWORD *)(v14 + 2280) < 0;
  v133 = (unsigned __int16 *)-1;
  v132 = 0;
  if ( !v34 && !v33 )
  {
    v35 = a12;
    v136 = a12;
    do                                          // 逐个BAR进行计算？？
    {
      ((void (__thiscall *)(int, unsigned __int16 *))unk_5235240)(v14 + 396, v35);
      ((void (__thiscall *)(int, unsigned __int16 *))unk_5235240)(v14 + 412, v35);
      if ( v20 )
      {
        v137 = (unsigned __int16 *)((int (__cdecl *)(int, int, unsigned __int16 *, _DWORD, int))unk_5231B68)(
                                     v20,
                                     nBarCount,
                                     v35,
                                     0,
                                     nBarCount - 1);
        if ( (signed int)v137 >= 0 )
        {
          v36 = ((int (__thiscall *)(int, int))unk_5231190)(v14 + 412, v132);
          v37 = v137;
          v38 = (char *)v36;
          v133 = v137;
LABEL_22:
          v40 = (_BYTE *)(v20 + 51 * (_DWORD)v37);
          qmemcpy(v38, v40, 0x30u);
          v40 += 48;
          v41 = (int)(v38 + 48);
          *(_WORD *)v41 = *(_WORD *)v40;
          *(_BYTE *)(v41 + 2) = v40[2];
          v35 = v136;
          goto LABEL_23;
        }
        if ( (signed int)v133 >= 0 )
        {
          v39 = ((int (__thiscall *)(int, int))unk_5231190)(v14 + 412, v132);
          v37 = v133;
          v38 = (char *)v39;
          goto LABEL_22;
        }
      }
LABEL_23:
      v35 = (unsigned __int16 *)((char *)v35 + 51);
      v42 = __OFSUB__(v132 + 1, *(_DWORD *)(v14 + 2280));
      v34 = v132++ + 1 - *(_DWORD *)(v14 + 2280) < 0;
      v136 = v35;
    }
    while ( v34 ^ v42 );
  }
  v43 = 0;
  if ( *(_DWORD *)(v14 + 2280) > 0 )
  {
    v44 = (char *)a12 + 3;
    do
    {
      v45 = *v44;
      v46 = *(v44 - 1);
      LOWORD(v137) = *(_WORD *)(v44 - 3);
      v47 = v44[1];
      HIBYTE(v137) = v45;
      v48 = v44[3];
      BYTE2(v137) = v46;
      v49 = v44[2];
      v138 = v47;
      v140 = v48;
      v139 = v49;
      ((void (__thiscall *)(int, unsigned __int16 **))unk_523584E)(v14 + 428, &v137);
      ++v43;
      v44 += 51;
    }
    while ( v43 < *(_DWORD *)(v14 + 2280) );
  }
  a2(v20, 1);
  *(_QWORD *)&v129 = *(unsigned int *)(v14 + 2280);
  v50 = (unsigned __int16 *)((int (__thiscall *)(int, _DWORD, _DWORD, _DWORD, _DWORD))emfccore_GSHELPER::CGSHelper::CreateDoubleArray)(
                              v131,
                              COERCE_UNSIGNED_INT64(0.0),
                              COERCE_UNSIGNED_INT64(0.0) >> 32,
                              LODWORD(v129),
                              HIDWORD(v129));
  v51 = LODWORD(a14);
  HIDWORD(v129) = *(_DWORD *)(LODWORD(a14) + 298);
  v136 = v50;
  if ( !(unsigned __int8)((int (__cdecl *)(_DWORD))unk_52342C8)(HIDWORD(v129)) )
    goto LABEL_128;
  v52 = *(_DWORD *)(v14 + 15);
  v53 = *(_WORD *)(v14 + 19);
  v129 = a14;
  HIDWORD(v128) = &nBarCount;
  v127 = v52;
  LOBYTE(v52) = *(_BYTE *)(v14 + 21);
  LOWORD(v128) = v53;
  v54 = *(_DWORD *)(v14 + 8);
  BYTE2(v128) = v52;
  LOWORD(v52) = *(_WORD *)(v14 + 12);
  v124 = v54;
  LOBYTE(v54) = *(_BYTE *)(v14 + 14);
  v125 = v52;
  v126 = v54;
  v55 = (unsigned __int16 *)((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD))a1)(
                              2,
                              0,
                              a6,
                              a7,
                              v124,
                              *(_DWORD *)&v125,
                              v127,
                              LODWORD(v128),
                              &nBarCount,
                              LODWORD(a14),
                              HIDWORD(a14));
  v137 = v55;
  if ( !v55 )
    goto LABEL_128;
  if ( nBarCount > 0 )
  {
    ((void (__cdecl *)(unsigned __int16 *, unsigned __int16 *, int, void *))unk_5233B34)(
      v55,
      &v55[10 * nBarCount],
      20 * nBarCount / 20,
      &unk_5233DEB);
    v56 = 0;
    if ( *(_DWORD *)(v14 + 2280) > 0 )
    {
      v147 = 0;
      do
      {
        v57 = *(_DWORD *)(v14 + 400);
        if ( !v57 || v56 >= (*(_DWORD *)(v14 + 404) - v57) / 51 )
          off_5364924();
          
        v133 = (unsigned __int16 *)(v147 + *(_DWORD *)(v14 + 400));
        
        v58 = *(_DWORD *)(v14 + 400);
        if ( !v58 || v56 >= (*(_DWORD *)(v14 + 404) - v58) / 51 )
          off_5364924();
          
        v59 = *(_DWORD *)(v14 + 400);
        v60 = v147 + *(_DWORD *)(v14 + 400);
        if ( !v59 || v56 >= (*(_DWORD *)(v14 + 404) - v59) / 51 )
          off_5364924();
          
        v61 = *(_DWORD *)(v14 + 400);
        v62 = *(unsigned __int8 *)(v60 + 2);
        v129 = COERCE_DOUBLE(__PAIR__(&v145, *((unsigned __int8 *)v133 + 3)));
        HIDWORD(v128) = v62;
        ((void (__cdecl *)(unsigned __int16 *, int, _DWORD, int, _DWORD, char *))unk_5231D52)(
          v137,
          nBarCount,
          *(unsigned __int16 *)(v61 + v147),
          v62,
          LODWORD(v129),
          &v145);
          
        ((void (__thiscall *)(int, char *))unk_5232A3B)(v14 + 2048, &v145);
        
        if ( (unsigned __int8)((int (__thiscall *)(int, _DWORD, _DWORD))emfccore_GSHELPER::CGSHelper::IsZero)(
                                v131,
                                LODWORD(v146),
                                HIDWORD(v146))
          || (unsigned __int8)((int (__thiscall *)(int, _DWORD, _DWORD))emfccore_GSHELPER::CGSHelper::IsNullValue)(
                                v131,
                                LODWORD(v146),
                                HIDWORD(v146)) )
        {
          v64 = 0.0;
        }
        else
        {
          v63 = ((int (__thiscall *)(int, unsigned int))unk_5231190)(v14 + 396, v56);
          v64 = *(double *)(v63 + 31) / v146;
        }
        v147 += 51;
        *(double *)&v136[4 * v56++] = v64;
      }
      while ( (signed int)v56 < *(_DWORD *)(v14 + 2280) );
    }
    a2((int)v137, 2);
  }
  else
  {
LABEL_128:
    v65 = 0;
    if ( *(_DWORD *)(v14 + 2280) <= 0 )
      goto LABEL_60;
    v66 = 0;
    do
    {
      v67 = *(_DWORD *)(v14 + 400);
      if ( !v67 || v65 >= (*(_DWORD *)(v14 + 404) - v67) / 51 )
        off_5364924();
      v68 = *(_DWORD *)(v14 + 400);
      LOWORD(v133) = *(_WORD *)(v66 + *(_DWORD *)(v14 + 400));
      if ( !v68 || v65 >= (*(_DWORD *)(v14 + 404) - v68) / 51 )
        off_5364924();
      v69 = *(_DWORD *)(v14 + 400);
      BYTE2(v133) = *(_BYTE *)(v69 + v66 + 2);
      if ( !v69 || v65 >= (*(_DWORD *)(v14 + 404) - v69) / 51 )
        off_5364924();
      v70 = *(_BYTE *)(*(_DWORD *)(v14 + 400) + v66 + 3);
      v135 = 0.0;
      v134 = 0.0;
      HIBYTE(v133) = v70;
      ((void (__thiscall *)(int, unsigned __int16 **))unk_5232A3B)(v14 + 2048, &v133);
      *(double *)&v136[4 * v65++] = 0.0;
      v66 += 51;
    }
    while ( (signed int)v65 < *(_DWORD *)(v14 + 2280) );
  }
  v51 = LODWORD(a14);
LABEL_60:
  *(_DWORD *)(v14 + 2112) = v136;
  HIDWORD(v129) = *(_DWORD *)(v51 + 298);
  if ( !(unsigned __int8)((int (__cdecl *)(_DWORD))unk_52324B4)(HIDWORD(v129)) )
    goto LABEL_129;
  v71 = *(_DWORD *)(v14 + 15);
  v72 = *(_WORD *)(v14 + 19);
  v129 = COERCE_DOUBLE(__PAIR__(HIDWORD(a14), v51));
  HIDWORD(v128) = &nBarCount;
  v127 = v71;
  LOBYTE(v71) = *(_BYTE *)(v14 + 21);
  LOWORD(v128) = v72;
  v73 = *(_DWORD *)(v14 + 8);
  BYTE2(v128) = v71;
  LOWORD(v71) = *(_WORD *)(v14 + 12);
  v124 = v73;
  LOBYTE(v73) = *(_BYTE *)(v14 + 14);
  v125 = v71;
  v126 = v73;
  v74 = (const void *)((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, unsigned int, _DWORD))a1)(
                        4,
                        0,
                        a6,
                        a7,
                        v124,
                        *(_DWORD *)&v125,
                        v127,
                        LODWORD(v128),
                        &nBarCount,
                        v51,
                        HIDWORD(a14));
  if ( v74 )
  {
    v129 = COERCE_DOUBLE(__PAIR__(4, (unsigned int)v74));
    qmemcpy((void *)(v14 + 1744), v74, 0x130u);
    a2(LODWORD(v129), HIDWORD(v129));
  }
  else
  {
LABEL_129:
    ((void (__cdecl *)(int, _DWORD, signed int))unk_5318E76)(v14 + 1744, 0, 304);
  }
  HIDWORD(v129) = *(_DWORD *)(LODWORD(a14) + 298);
  v75 = a6;
  if ( !(unsigned __int8)((int (__cdecl *)(_DWORD))unk_5234B42)(HIDWORD(v129)) )
    goto LABEL_130;
  v76 = *(_DWORD *)(v14 + 15);
  v129 = a14;
  HIDWORD(v128) = &nBarCount;
  v77 = *(_WORD *)(v14 + 19);
  v127 = v76;
  LOBYTE(v76) = *(_BYTE *)(v14 + 21);
  LOWORD(v128) = v77;
  v78 = *(_DWORD *)(v14 + 8);
  BYTE2(v128) = v76;
  LOWORD(v76) = *(_WORD *)(v14 + 12);
  v124 = v78;
  LOBYTE(v78) = *(_BYTE *)(v14 + 14);
  v125 = v76;
  v126 = v78;
  v79 = (const void *)((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD))a1)(
                        8,
                        0,
                        a6,
                        a7,
                        v124,
                        *(_DWORD *)&v125,
                        v127,
                        LODWORD(v128),
                        &nBarCount,
                        LODWORD(a14),
                        HIDWORD(a14));
  if ( v79 )
  {
    v129 = COERCE_DOUBLE(__PAIR__(8, (unsigned int)v79));
    qmemcpy((void *)(v14 + 444), v79, 0x514u);
    a2(LODWORD(v129), HIDWORD(v129));
    v80 = a1;
  }
  else
  {
LABEL_130:
    v80 = a1;
    ((void (__cdecl *)(int, _DWORD, signed int))unk_5318E76)(v14 + 444, 0, 1300);
  }
  v81 = LODWORD(a14);
  v82 = *(_DWORD *)(v14 + 15);
  v129 = a14;
  HIDWORD(v128) = &nBarCount;
  v83 = *(_WORD *)(v14 + 19);
  v127 = v82;
  LOBYTE(v82) = *(_BYTE *)(v14 + 21);
  LOWORD(v128) = v83;
  v84 = *(_DWORD *)(v14 + 8);
  BYTE2(v128) = v82;
  LOWORD(v82) = *(_WORD *)(v14 + 12);
  v124 = v84;
  LOBYTE(v84) = *(_BYTE *)(v14 + 14);
  v125 = v82;
  v126 = v84;
  v80(16, 0, a6, a7, v124, *(_DWORD *)&v125, v127, LODWORD(v128), &nBarCount, LODWORD(a14), HIDWORD(a14));
  v85 = *(_WORD *)(v14 + 19);
  v129 = a14;
  HIDWORD(v128) = &nBarCount;
  *(_DWORD *)(v14 + 2132) = nBarCount;
  v127 = *(_DWORD *)(v14 + 15);
  v86 = *(_BYTE *)(v14 + 21);
  LOWORD(v128) = v85;
  v87 = *(_DWORD *)(v14 + 8);
  BYTE2(v128) = v86;
  v88 = *(_WORD *)(v14 + 12);
  v124 = v87;
  LOBYTE(v87) = *(_BYTE *)(v14 + 14);
  v125 = v88;
  v126 = v87;
  v80(32, 0, a6, a7, v124, *(_DWORD *)&v125, v127, LODWORD(v128), (int *)HIDWORD(v128), LODWORD(v129), HIDWORD(v129));
  *(_DWORD *)(v14 + 2136) = nBarCount;
  ((void (__cdecl *)(int, int, int, int))unk_52358CB)(a6, nBarCount, v14 + 2140, v14 + 2144);
  v89 = *(_DWORD *)(v14 + 15);
  v90 = *(_WORD *)(v14 + 19);
  v129 = a14;
  HIDWORD(v128) = &nBarCount;
  v127 = v89;
  LOBYTE(v89) = *(_BYTE *)(v14 + 21);
  LOWORD(v128) = v90;
  v91 = *(_DWORD *)(v14 + 8);
  BYTE2(v128) = v89;
  LOWORD(v89) = *(_WORD *)(v14 + 12);
  v124 = v91;
  LOBYTE(v91) = *(_BYTE *)(v14 + 14);
  v125 = v89;
  v126 = v91;
  v92 = (_BYTE *)((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, _DWORD, _DWORD))v80)(
                   64,
                   0,
                   a6,
                   a7,
                   v124,
                   *(_DWORD *)&v125,
                   v127,
                   LODWORD(v128),
                   &nBarCount,
                   LODWORD(a14),
                   HIDWORD(a14));
  if ( v92 )
  {
    qmemcpy((void *)(v14 + 329), v92, 0x3Eu);
    v129 = COERCE_DOUBLE(__PAIR__(64, (unsigned int)v92));
    *(_BYTE *)(v14 + 391) = v92[62];
    a2(LODWORD(v129), HIDWORD(v129));
    v80 = a1;
    v81 = LODWORD(a14);
  }
  v93 = *(_DWORD *)(v81 + 298);
  v142 = 0;
  v143 = 0;
  v144 = 0;
  if ( (unsigned __int8)((int (__cdecl *)(int, char *))unk_52338F0)(v93, &v141) )
  {
    v94 = *(_DWORD *)(v14 + 15);
    v129 = COERCE_DOUBLE(__PAIR__(HIDWORD(a14), v81));
    HIDWORD(v128) = &nBarCount;
    v95 = *(_WORD *)(v14 + 19);
    v127 = v94;
    LOBYTE(v94) = *(_BYTE *)(v14 + 21);
    LOWORD(v128) = v95;
    v96 = *(_DWORD *)(v14 + 8);
    BYTE2(v128) = v94;
    LOWORD(v94) = *(_WORD *)(v14 + 12);
    v124 = v96;
    LOBYTE(v96) = *(_BYTE *)(v14 + 14);
    v125 = v94;
    v126 = v96;
    v97 = (unsigned __int16 *)((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, unsigned int, _DWORD))v80)(
                                256,
                                0,
                                a6,
                                a7,
                                v124,
                                *(_DWORD *)&v125,
                                v127,
                                LODWORD(v128),
                                &nBarCount,
                                v81,
                                HIDWORD(a14));
    v148 = v97;
    if ( v97 )
    {
      v98 = (unsigned __int16 *)*((_DWORD *)v97 + 1);
      v99 = (unsigned int)v98 < *((_DWORD *)v97 + 2);
      v33 = v98 == *((unsigned __int16 **)v97 + 2);
      v137 = (unsigned __int16 *)*((_DWORD *)v97 + 1);
      if ( !v99 && !v33 )
      {
        off_5364924();
        v98 = v137;
        v97 = v148;
      }
      LODWORD(v134) = v98;
      while ( 1 )
      {
        v100 = *((_DWORD *)v97 + 2);
        v99 = *((_DWORD *)v97 + 1) < v100;
        v33 = *((_DWORD *)v97 + 1) == v100;
        v137 = (unsigned __int16 *)*((_DWORD *)v97 + 2);
        if ( !v99 && !v33 )
        {
          off_5364924();
          v97 = v148;
        }
        v133 = v97;
        if ( !v97 )
          off_5364924();
        if ( (unsigned __int16 *)LODWORD(v134) == v137 )
          break;
        if ( !v133 )
          off_5364924();
        if ( LODWORD(v134) >= *((_DWORD *)v133 + 2) )
          off_5364924();
        v101 = *(_DWORD *)(LODWORD(v134) + 12);
        if ( v101 && (*(_DWORD *)(LODWORD(v134) + 16) - v101) / 12 )
        {
          HIDWORD(v129) = 12 * *(_DWORD *)(v14 + 2280) | -(12 * (unsigned __int64)*(unsigned int *)(v14 + 2280) >> 32 != 0);
          v102 = (unsigned __int16 *)((int (__cdecl *)(_DWORD))unk_530BD68)(HIDWORD(v129));
          v103 = LODWORD(v134);
          v99 = LODWORD(v134) < *((_DWORD *)v148 + 2);
          v104 = v102;
          v137 = v102;
          if ( !v99 )
            off_5364924();
          *(_DWORD *)((int (__thiscall *)(int, unsigned int))unk_5234179)(v14 + 2064, v103) = v104;
          if ( v103 >= *((_DWORD *)v148 + 2) )
            off_5364924();
          v105 = *(_DWORD *)(v103 + 16);
          v106 = v103 + 8;
          if ( *(_DWORD *)(v103 + 12) > v105 )
            off_5364924();
          if ( v103 >= *((_DWORD *)v148 + 2) )
            off_5364924();
          v107 = *(_DWORD *)(v103 + 12);
          if ( v107 > *(_DWORD *)(v106 + 8) )
            off_5364924();
          ((void (__cdecl *)(unsigned int, unsigned int, int, void *))unk_523435E)(
            v107,
            v105,
            (signed int)(v105 - v107) / 12,
            &unk_5235920);
          v108 = 0;
          if ( *(_DWORD *)(v14 + 2280) > 0 )
          {
            v109 = 0;
            v136 = v137;
            do
            {
              v110 = *(_DWORD *)(v14 + 400);
              if ( !v110 || v108 >= (*(_DWORD *)(v14 + 404) - v110) / 51 )
                off_5364924();
              v137 = (unsigned __int16 *)(v109 + *(_DWORD *)(v14 + 400));
              v111 = *(_DWORD *)(v14 + 400);
              if ( !v111 || v108 >= (*(_DWORD *)(v14 + 404) - v111) / 51 )
                off_5364924();
              v112 = *(_DWORD *)(v14 + 400);
              v113 = v109 + *(_DWORD *)(v14 + 400);
              if ( !v112 || v108 >= (*(_DWORD *)(v14 + 404) - v112) / 51 )
                off_5364924();
              v114 = *(unsigned __int8 *)(*(_DWORD *)(v14 + 400) + v109 + 3)
                   + 100 * (100 * *v137 + *(unsigned __int8 *)(v113 + 2));
              if ( LODWORD(v134) >= *((_DWORD *)v148 + 2) )
                off_5364924();
              ((void (__cdecl *)(int, int, unsigned __int16 *))unk_523400C)(LODWORD(v134) + 8, v114, v136);
              v136 += 6;
              ++v108;
              v109 += 51;
            }
            while ( (signed int)v108 < *(_DWORD *)(v14 + 2280) );
          }
        }
        if ( LODWORD(v134) >= *((_DWORD *)v148 + 2) )
          off_5364924();
        LODWORD(v134) += 24;
        v75 = a6;
        v81 = LODWORD(a14);
        v80 = a1;
        v97 = v148;
      }
    }
  }
  if ( !off_53610F4 )
  {
    v115 = *(_DWORD *)(v14 + 15);
    v116 = *(_WORD *)(v14 + 19);
    v129 = COERCE_DOUBLE(__PAIR__(HIDWORD(a14), v81));
    HIDWORD(v128) = &nBarCount;
    v127 = v115;
    LOBYTE(v115) = *(_BYTE *)(v14 + 21);
    LOWORD(v128) = v116;
    v117 = *(_DWORD *)(v14 + 8);
    BYTE2(v128) = v115;
    LOWORD(v115) = *(_WORD *)(v14 + 12);
    v124 = v117;
    LOBYTE(v117) = *(_BYTE *)(v14 + 14);
    v125 = v115;
    v126 = v117;
    v118 = ((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, unsigned int, _DWORD))v80)(
             512,
             0,
             v75,
             a7,
             v124,
             *(_DWORD *)&v125,
             v127,
             LODWORD(v128),
             &nBarCount,
             v81,
             HIDWORD(a14));
    v149 = (void *)v118;
    if ( v118 )
    {
      LODWORD(v135) = v118;
      v133 = (unsigned __int16 *)512;
      v134 = COERCE_DOUBLE(__PAIR__((unsigned int)a2, (unsigned int)v80));
      ((void (__thiscall *)(void *, unsigned __int16 **))unk_5233F62)(&unk_5361130, &v133);
      off_53649EC("g_hmStkBkData size:%d\n", *(_DWORD *)(*(_DWORD *)v149 + 12));
    }
    off_53646E4(&unk_5360BB8);
    off_53610F4 = v149;
    off_53646E0(&unk_5360BB8);
  }
  *(_DWORD *)(v14 + 2104) = off_53610F4;
  if ( !off_53610F8 )
  {
    v119 = *(_DWORD *)(v14 + 15);
    v129 = COERCE_DOUBLE(__PAIR__(HIDWORD(a14), v81));
    HIDWORD(v128) = &nBarCount;
    v120 = *(_WORD *)(v14 + 19);
    v127 = v119;
    LOBYTE(v119) = *(_BYTE *)(v14 + 21);
    LOWORD(v128) = v120;
    v121 = *(_DWORD *)(v14 + 8);
    BYTE2(v128) = v119;
    LOWORD(v119) = *(_WORD *)(v14 + 12);
    v124 = v121;
    LOBYTE(v121) = *(_BYTE *)(v14 + 14);
    v125 = v119;
    v126 = v121;
    v122 = ((int (__cdecl *)(signed int, _DWORD, int, int, int, _DWORD, int, _DWORD, int *, unsigned int, _DWORD))v80)(
             2048,
             0,
             v75,
             a7,
             v124,
             *(_DWORD *)&v125,
             v127,
             LODWORD(v128),
             &nBarCount,
             v81,
             HIDWORD(a14));
    if ( v122 )
    {
      LODWORD(v135) = v122;
      v133 = (unsigned __int16 *)2048;
      v134 = COERCE_DOUBLE(__PAIR__((unsigned int)a2, (unsigned int)v80));
      ((void (__thiscall *)(void *, unsigned __int16 **))unk_5233F62)(&unk_5361130, &v133);
      HIDWORD(v129) = *(_DWORD *)(v122 + 12);
      off_53649EC("g_hmFinFutureTargetData size:%d\n", HIDWORD(v129));
    }
    off_53646E4(&unk_5360BB8);
    off_53610F8 = (void **)v122;
    off_53646E0(&unk_5360BB8);
  }
  *(_DWORD *)(v14 + 2108) = off_53610F8;
  if ( v142 )
    ((void (__cdecl *)(int))unk_530BD56)(v142);
  return v14;
}

