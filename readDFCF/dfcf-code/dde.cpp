//处理当日DDE数据
char __thiscall CDataMgr::ProcStkDDEData(CDataMgr *this, char a2, char a3, int a4, signed int a5, _DWORD *a6)
{
  float v7; // ST164_4
  char v8; // al
  double v9; // st7
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ST28_4
  int v16; // eax
  int v17; // [esp+2Ch] [ebp-1CCh]
  int v18; // [esp+30h] [ebp-1C8h]
  double v19; // [esp+64h] [ebp-194h]
  double v20; // [esp+90h] [ebp-168h]
  double v21; // [esp+BCh] [ebp-13Ch]
  double v22; // [esp+F8h] [ebp-100h]
  double v23; // [esp+124h] [ebp-D4h]
  double v24; // [esp+150h] [ebp-A8h]
  signed int v25; // [esp+15Ch] [ebp-9Ch]
  CDataMgr *v26; // [esp+168h] [ebp-90h]
  int v27; // [esp+170h] [ebp-88h]
  int v28; // [esp+178h] [ebp-80h]
  int v29; // [esp+180h] [ebp-78h]
  int v30; // [esp+184h] [ebp-74h]
  int i; // [esp+188h] [ebp-70h]
  char v32[5]; // [esp+18Fh] [ebp-69h]
  char Dst; // [esp+194h] [ebp-64h]
  int v34; // [esp+195h] [ebp-63h]
  __int16 v35; // [esp+199h] [ebp-5Fh]
  char v36; // [esp+19Ch] [ebp-5Ch]
  char v37; // [esp+1A0h] [ebp-58h]
  char v38; // [esp+1A4h] [ebp-54h]
  struct CListCompressIf *v39; // [esp+1A8h] [ebp-50h]
  char v40; // [esp+1AFh] [ebp-49h]
  struct STK_PER *v41; // [esp+1B0h] [ebp-48h]
  int v42; // [esp+1B4h] [ebp-44h]
  char v43; // [esp+1B8h] [ebp-40h]
  char v44; // [esp+1B9h] [ebp-3Fh]
  __int64 v45; // [esp+1BAh] [ebp-3Eh]
  char v46; // [esp+1C4h] [ebp-34h]
  CHAR MultiByteStr; // [esp+1D4h] [ebp-24h]
  char Src[4]; // [esp+1D5h] [ebp-23h]
  int v49; // [esp+1D9h] [ebp-1Fh]
  int v50; // [esp+1DDh] [ebp-1Bh]
  __int16 v51; // [esp+1E1h] [ebp-17h]
  char v52; // [esp+1E3h] [ebp-15h]
  int v53; // [esp+1E8h] [ebp-10h]
  int v54; // [esp+1F4h] [ebp-4h]

  v26 = this;
  if ( a5 < 1 || !a4 )
    return 0;
  v39 = CDataMgr::GetListCompressPtr(this, a2, a3);
  if ( !v39 )
    return 0;
  *(_DWORD *)&v32[1] = 0;
  v53 = 0;
  v40 = 0;
  if ( !(*(unsigned __int8 (__thiscall **)(struct CListCompressIf *, int, signed int, char *, int *, char *))(*(_DWORD *)v39 + 52))(
          v39,
          a4,
          a5,
          &v32[1],
          &v53,
          &v40) )
    return 0;
  sub_4E90250(&v46);
  v54 = 0;
  MultiByteStr = 0;
  *(_DWORD *)Src = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  Dst = 0;
  v34 = 0;
  v35 = 0;
  v32[0] = -1;
  v41 = 0;
  for ( i = 0; i < v53; ++i )  //V53返回数据的股票总数
  {
    v30 = *(_DWORD *)&v32[1] + 124 * i;
    sub_50EF6E0(*(_DWORD *)(*(_DWORD *)&v32[1] + 124 * i), &MultiByteStr, (int)v32);
    v41 = QDataEngine::App_OneStkInfo(&MultiByteStr, v32[0]);
    if ( v41 )
    {
      if ( !*(_DWORD *)((char *)v41 + 85) )
      {
        sub_5107740();
        sub_5108420(1, (int)v41);
      }
      if ( *(_DWORD *)((char *)v41 + 85) )
      {
        v43 = v32[0];
        v7 = *(float *)(*(_DWORD *)((char *)v41 + 85) + 70) - *(float *)(v30 + 4);
        if ( log(v7) >= 0.001 )
        {
          v44 = 1;
          v42 = *(unsigned __int16 *)((char *)v41 + 69);
          if ( *(float *)(v30 + 4) * 1000.0 <= 0.0 )
            v25 = (signed int)(*(float *)(v30 + 4) * 1000.0 - 0.5);
          else
            v25 = (signed int)(*(float *)(v30 + 4) * 1000.0 + 0.5);
          v45 = v25;
          sub_4E8D2A0(&v42);
        }
        *(float *)(*(_DWORD *)((char *)v41 + 85) + 70) = *(float *)(v30 + 4);
        v8 = sub_50EFAD0(v32[0], &MultiByteStr);
        v9 = *(float *)(v30 + 4);
        sub_50EF640(*(float *)(v30 + 4), *(float *)(v30 + 8), v8);
        *(float *)(*(_DWORD *)((char *)v41 + 85) + 174) = v9;
        *(float *)(*(_DWORD *)((char *)v41 + 85) + 54) = *(float *)(v30 + 8);
        if ( v32[0] == 90 )
        {
          sub_4E99F50(&Dst, &Src[1], 5u);
          v10 = atoi(&Dst);
          v29 = CDataMgr::GetBkStockListById(v26, v10, 0);
          if ( v29 )
          {
            *(float *)(v29 + 117) = *(float *)(v30 + 4);
            *(float *)(v29 + 133) = *(float *)(v30 + 8);
            *(float *)(v29 + 177) = *(float *)(*(_DWORD *)((char *)v41 + 85) + 174);
          }
        }
        if ( *(_DWORD *)((char *)v41 + 153) || (sub_5107740(), sub_5108420(18, (int)v41)) )
        {
          if ( *(_DWORD *)((char *)v41 + 153) )
          {
            **(float **)((char *)v41 + 153) = *(float *)(v30 + 20);
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 4) = *(float *)(v30 + 24);
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 8) = *(float *)(v30 + 28);
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 12) = *(float *)(v30 + 32);
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 16) = *(float *)(v30 + 36);
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 20) = *(float *)(v30 + 40);
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 24) = *(float *)(v30 + 44);
            *(_DWORD *)(*(_DWORD *)((char *)v41 + 153) + 28) = *(_DWORD *)(v30 + 48);
            *(_DWORD *)(*(_DWORD *)((char *)v41 + 153) + 32) = *(_DWORD *)(v30 + 52);
            *(_DWORD *)(*(_DWORD *)((char *)v41 + 153) + 36) = *(_DWORD *)(v30 + 56);
            if ( *(_QWORD *)(v30 + 12) )
              v24 = (double)*(unsigned __int64 *)(v30 + 108) / (double)*(unsigned __int64 *)(v30 + 12);
            else
              v24 = 0.0;
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 40) = v24;
            if ( *(_QWORD *)(v30 + 12) )
              v23 = (double)*(unsigned __int64 *)(v30 + 116) / (double)*(unsigned __int64 *)(v30 + 12);
            else
              v23 = 0.0;
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 44) = v23;
            if ( *(_QWORD *)(v30 + 12) )
              v22 = ((double)*(unsigned __int64 *)(v30 + 108) - (double)*(unsigned __int64 *)(v30 + 116))
                  / (double)*(unsigned __int64 *)(v30 + 12);
            else
              v22 = 0.0;
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 48) = v22;
            if ( *(_QWORD *)(v30 + 12) )
              v21 = (double)*(unsigned __int64 *)(v30 + 92) / (double)*(unsigned __int64 *)(v30 + 12);
            else
              v21 = 0.0;
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 52) = v21;
            if ( *(_QWORD *)(v30 + 12) )
              v20 = (double)*(unsigned __int64 *)(v30 + 100) / (double)*(unsigned __int64 *)(v30 + 12);
            else
              v20 = 0.0;
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 56) = v20;
            if ( *(_QWORD *)(v30 + 12) )
              v19 = ((double)*(unsigned __int64 *)(v30 + 92) - (double)*(unsigned __int64 *)(v30 + 100))
                  / (double)*(unsigned __int64 *)(v30 + 12);
            else
              v19 = 0.0;
            *(float *)(*(_DWORD *)((char *)v41 + 153) + 60) = v19;
          }
        }
      }
    }
  }
  v28 = mfc80xU_762(40);
  LOBYTE(v54) = 1;
  if ( v28 )
    v18 = sub_4E8EB10(v28);
  else
    v18 = 0;
  LOBYTE(v54) = 0;
  sub_4E8E5E0(v18);
  LOBYTE(v54) = 2;
  v27 = mfc80xU_762(28);
  if ( v27 )
    v17 = sub_4DECDE0(v27);
  else
    v17 = 0;
  sub_4E8E5E0(v17);
  LOBYTE(v54) = 3;
  CGlobalEnv::GetGlobalEnv(&v37);
  LOBYTE(v54) = 4;
  v11 = sub_4DAD4E0(&v46);
  v12 = unknown_libname_96(&v36);
  *(_DWORD *)(unknown_libname_89(v12) + 8) = v11;
  v13 = unknown_libname_96(&v36);
  unknown_libname_89(v13);
  sub_4E8D110(&v46);
  v14 = unknown_libname_96(&v38);
  unknown_libname_89(v14);
  sub_4DF7300(&v36);
  v15 = unknown_libname_96(&v37);
  v16 = unknown_libname_96(&v38);
  *a6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v15 + 36))(v15, v16);
  LOBYTE(v54) = 3;
  sub_4E8C780(&v37);
  LOBYTE(v54) = 2;
  sub_4E8C780(&v38);
  LOBYTE(v54) = 0;
  sub_4E8C780(&v36);
  v54 = -1;
  sub_4E90280(&v46);
  return 1;
}