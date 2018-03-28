char __thiscall datacenter_CDataMgr::ProcTradeDetailAndSendToUI(void *this, int szStockCode)
{
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  char result; // al
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _BYTE *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // [esp-1Ch] [ebp-2C0h]
  int v18; // [esp-Ch] [ebp-2B0h]
  signed int v19; // [esp-8h] [ebp-2ACh]
  int v20; // [esp-4h] [ebp-2A8h]
  int nCurTradeDate; // [esp+0h] [ebp-2A4h]
  int v22; // [esp+8h] [ebp-29Ch]
  int v23; // [esp+Ch] [ebp-298h]
  int v24; // [esp+10h] [ebp-294h]
  int v25; // [esp+14h] [ebp-290h]
  int v26; // [esp+18h] [ebp-28Ch]
  int v27; // [esp+1Ch] [ebp-288h]
  void *v28; // [esp+20h] [ebp-284h]
  char v29; // [esp+27h] [ebp-27Dh]
  int v30; // [esp+28h] [ebp-27Ch]
  int *v31; // [esp+2Ch] [ebp-278h]
  char v32; // [esp+33h] [ebp-271h]
  int v33; // [esp+34h] [ebp-270h]
  char v34; // [esp+38h] [ebp-26Ch]
  int *v35; // [esp+54h] [ebp-250h]
  int v36; // [esp+58h] [ebp-24Ch]
  int v37; // [esp+5Ch] [ebp-248h]
  int i; // [esp+64h] [ebp-240h]
  char v39; // [esp+6Bh] [ebp-239h]
  int nCurTradeDate; // [esp+6Ch] [ebp-238h]
  int nL2Count; // [esp+70h] [ebp-234h]
  int nCurTradeDateRaw; // [esp+74h] [ebp-230h]
  char v43; // [esp+78h] [ebp-22Ch]
  int v44; // [esp+278h] [ebp-2Ch]
  char v45; // [esp+27Ch] [ebp-28h]
  char szStockCode; // [esp+280h] [ebp-24h]
  int v47; // [esp+281h] [ebp-23h]
  int v48; // [esp+285h] [ebp-1Fh]
  int v49; // [esp+289h] [ebp-1Bh]
  __int16 v50; // [esp+28Dh] [ebp-17h]
  char v51; // [esp+28Fh] [ebp-15h]
  char v52; // [esp+294h] [ebp-10h]
  int v53; // [esp+2A0h] [ebp-4h]

  v28 = this;
  ((void (__cdecl *)(char *, const wchar_t *))logmanager_LightLogger::CLogger::GetLogger)(&v52, L"PushTradeDetail");
  v53 = 0;
  ((void (__cdecl *)(char *, const wchar_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))unk_70CE590)(
    &v43,
    L"data len is: nPkgSize= %d bCompressed=%d bEncrypt=%d bResult=%d nMagicId=%d nOwnerId=%d",
    *(_DWORD *)szStockCode,
    *(char *)(szStockCode + 12),
    *(char *)(szStockCode + 11),
    *(char *)(szStockCode + 10),
    *(_DWORD *)(szStockCode + 13),
    *(_DWORD *)(szStockCode + 6));
  v2 = ((int (__thiscall *)(char *, char *, signed int))unk_71AF8F0)(&v52, &v43, 10000);
  ((void (__thiscall *)(int))logmanager_LightLogger::CLogger::WriteLogLine)(v2);
  ((void (__cdecl *)(char *, const wchar_t *, _DWORD, _DWORD))unk_70CE590)(
    &v43,
    L"data len is:nIncrementId = %d PushStatus=%d",
    *(_DWORD *)(szStockCode + 17),
    *(char *)(szStockCode + 21));
  v3 = ((int (__thiscall *)(char *, char *, signed int))unk_71AF8F0)(&v52, &v43, 10000);
  ((void (__thiscall *)(int))logmanager_LightLogger::CLogger::WriteLogLine)(v3);
  LOBYTE(v4) = *(_BYTE *)(szStockCode + 21);
  v44 = ((int (__thiscall *)(void *, _DWORD, int))datacenter_CDataMgr::GetListCompressPtr)(
          v28,
          *(_DWORD *)(szStockCode + 17),
          v4);
  if ( v44 )
  {
    if ( *(_DWORD *)(szStockCode + 30) >= 1u && szStockCode != -34 )
    {
      ((void (__cdecl *)(char *, const wchar_t *, _DWORD, _DWORD, _DWORD))unk_70CE590)(
        &v43,
        L"data len is:%d nBeginIndex=%d nStockId=%d",
        *(_DWORD *)(szStockCode + 30),
        *(_DWORD *)(szStockCode + 26),
        *(_DWORD *)(szStockCode + 22));
      v7 = ((int (__thiscall *)(char *, char *, signed int))unk_71AF8F0)(&v52, &v43, 10000);
      ((void (__thiscall *)(int))logmanager_LightLogger::CLogger::WriteLogLine)(v7);
      nCurTradeDateRaw = 0;
      nL2Count = 0;
      if ( (*(unsigned __int8 (__thiscall **)(int, int, _DWORD, int *, int *))(*(_DWORD *)v44 + 48))(
             v44,
             szStockCode + 34,
             *(_DWORD *)(szStockCode + 30),
             &nCurTradeDateRaw,    分笔数据指针
             &nL2Count) )  分笔总数
      {
        if ( nCurTradeDateRaw && nL2Count >= 1 )
        {
          v39 = 0;
          szStockCode = 0;
          v47 = 0;
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v36 = ((int (__cdecl *)(signed int))unk_73323FE)(64);
          LOBYTE(v53) = 1;
          if ( v36 )
            v27 = ((int (__thiscall *)(int))unk_71CEBF0)(v36);
          else
            v27 = 0;
          v37 = v27;
          LOBYTE(v53) = 0;
          ((void (__thiscall *)(char *, int))unk_71CE5E0)(&v45, v27);
          LOBYTE(v53) = 2;
          ((void (__cdecl *)(_DWORD, char *, char *))unk_742F6E0)(*(_DWORD *)(szStockCode + 22), &szStockCode, &v39);
          v8 = ((int (__thiscall *)(char *))unk_71AF8F0)(&v45);
          *(_DWORD *)(((int (__thiscall *)(int))unk_7145220)(v8) + 29) = *(_DWORD *)(szStockCode + 26);
          v9 = ((int (__thiscall *)(char *))unk_71AF8F0)(&v45);
          v10 = (_BYTE *)((int (__thiscall *)(int))unk_7145220)(v9);
          *v10 = v39;
          v35 = &v17;
          v26 = ((int (__thiscall *)(int *, char *))unk_573348C1)(&v17, &szStockCode);
          v25 = ((int (__cdecl *)(char *))unk_71CC330)(&v34);
          v24 = v25;
          LOBYTE(v53) = 3;
          v11 = ((int (__thiscall *)(char *, int, int))unk_71AF8F0)(&v45, v25, v20);
          v12 = ((int (__thiscall *)(int))unk_7145220)(v11);
          ((void (__thiscall *)(int))unk_57342C52)(v12 + 1);
          LOBYTE(v53) = 2;
          ((void (__thiscall *)(char *))msvcp80_std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >)(&v34);
          v20 = 17 * nL2Count | -(17 * (unsigned __int64)(unsigned int)nL2Count >> 32 != 0);
          v33 = ((int (__cdecl *)(int))unk_733242E)(v20);
          nCurTradeDate = v33;
          if ( v33 )
          {
            for ( i = 0; i < nL2Count; ++i )
            {  分笔数据转换
              *(_BYTE *)(nCurTradeDate + 17 * i + 16) = *(_BYTE *)(nCurTradeDateRaw + 17 * i + 8);
              if ( *(float *)(nCurTradeDateRaw + 17 * i + 9) * 1000.0 <= 0.0 )
                v23 = ((int (__usercall *)@<eax>(double@<st0>))unk_745AA00)(*(float *)(nCurTradeDateRaw + 17 * i + 9) * 1000.0 - 0.5);
              else
                v23 = ((int (__usercall *)@<eax>(double@<st0>))unk_745AA00)(*(float *)(nCurTradeDateRaw + 17 * i + 9) * 1000.0 + 0.5);
              *(_DWORD *)(nCurTradeDate + 17 * i + 8) = v23;
              *(_DWORD *)(nCurTradeDate + 17 * i + 12) = *(_DWORD *)(nCurTradeDateRaw + 17 * i + 13);
              *(_DWORD *)(nCurTradeDate + 17 * i) = *(_DWORD *)(nCurTradeDateRaw + 17 * i);
              *(_DWORD *)(nCurTradeDate + 17 * i + 4) = *(_DWORD *)(nCurTradeDateRaw + 17 * i + 4);
            }
            v20 = nL2Count;
            ((void (__cdecl *)(char *, const wchar_t *, _DWORD, int))unk_70CE590)(
              &v43,
              L"L2Minxin nBeginIndex=%d, nRecCount=%d",
              *(_DWORD *)(szStockCode + 26),
              nL2Count);
              
            v13 = ((int (__thiscall *)(char *, char *, signed int, int))unk_71AF8F0)(&v52, &v43, 20000, nCurTradeDate);
            ((void (__thiscall *)(int))logmanager_LightLogger::CLogger::WriteLogLine)(v13);
            nCurTradeDate = ((int (__cdecl *)(_DWORD, _DWORD))datacenter_QDataEngine::GetCurDateByMarket)(v39, 0);
            v20 = nCurTradeDate;
            v14 = nL2Count;
            v19 = nL2Count;
            v18 = *(_DWORD *)(szStockCode + 26);
            LOBYTE(v14) = v39;
            ((void (__cdecl *)(char *, int, int, int, int, int))datacenter_QDataEngine::Add_L2DetailData)(
              &szStockCode,
              v14,
              v18,
              nL2Count,
              pL2Data,
              nCurTradeDate);
            v15 = ((int (__thiscall *)(char *))unk_71AF8F0)(&v45);
            v31 = &nCurTradeDate;
            v22 = ((int (__thiscall *)(int *, int, int))unk_71CE5E0)(&nCurTradeDate, v15, v16);
            v19 = 4;
            ((void (__cdecl *)(_DWORD, signed int))unk_7373630)(*(_DWORD *)(szStockCode + 6), 4);
            if ( nCurTradeDate )
            {
              v30 = nCurTradeDate;
              ((void (__cdecl *)(int))unk_73323AA)(nCurTradeDate);
              nCurTradeDate = 0;
            }
            v29 = 1;
            LOBYTE(v53) = 0;
            sub_71CC780(&v45);
            v53 = -1;
            sub_71CC780(&v52);
            result = v29;
          }
          else
          {
            v32 = 0;
            LOBYTE(v53) = 0;
            sub_71CC780(&v45);
            v53 = -1;
            sub_71CC780(&v52);
            result = v32;
          }
        }
        else
        {
          v53 = -1;
          sub_71CC780(&v52);
          result = 0;
        }
      }
      else
      {
        v53 = -1;
        sub_71CC780(&v52);
        result = 0;
      }
    }
    else
    {
      ((void (__cdecl *)(char *, const wchar_t *, _DWORD))unk_70CE590)(
        &v43,
        L"data addr is null or data len is:%d",
        *(_DWORD *)(szStockCode + 30));
      v6 = ((int (__thiscall *)(char *, char *, signed int))unk_71AF8F0)(&v52, &v43, 10000);
      ((void (__thiscall *)(int))logmanager_LightLogger::CLogger::WriteLogLine)(v6);
      v53 = -1;
      sub_71CC780(&v52);
      result = 0;
    }
  }
  else
  {
    v53 = -1;
    sub_71CC780(&v52);
    result = 0;
  }
  return result;
}

int __usercall datacenter_QDataEngine::Add_L2DetailData@<eax>(int a1@<esi>, int szStockCode, unsigned __int8 a3, 
    int a4, unsigned int nL2Count, int pL2Data, int nCurTradeDate)
{
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // edx
  int v11; // ST14_4
  int v12; // [esp+4h] [ebp-68h]
  int v13; // [esp+4h] [ebp-68h]
  int v14; // [esp+8h] [ebp-64h]
  int v15; // [esp+Ch] [ebp-60h]
  int v16; // [esp+10h] [ebp-5Ch]
  int v17; // [esp+14h] [ebp-58h]
  unsigned int i; // [esp+14h] [ebp-58h]
  int v19; // [esp+18h] [ebp-54h]
  int v20; // [esp+1Ch] [ebp-50h]
  int v21; // [esp+20h] [ebp-4Ch]
  int v22; // [esp+24h] [ebp-48h]
  int v23; // [esp+28h] [ebp-44h]
  int v24; // [esp+2Ch] [ebp-40h]
  int v25; // [esp+30h] [ebp-3Ch]
  int v26; // [esp+34h] [ebp-38h]
  int v27; // [esp+38h] [ebp-34h]
  int v28; // [esp+3Ch] [ebp-30h]
  int v29; // [esp+44h] [ebp-28h]
  int v30; // [esp+48h] [ebp-24h]
  int v31; // [esp+4Ch] [ebp-20h]
  int v32; // [esp+50h] [ebp-1Ch]
  int v33; // [esp+54h] [ebp-18h]
  int *v34; // [esp+58h] [ebp-14h]
  int v35; // [esp+5Ch] [ebp-10h]
  int *v36; // [esp+60h] [ebp-Ch]
  int *v37; // [esp+64h] [ebp-8h]
  int *v38; // [esp+68h] [ebp-4h]
  int savedregs; // [esp+6Ch] [ebp+0h]

  ((void (__stdcall *)(unsigned int, int, int, int, int, int, int, 
  															int, int, int, int, int, int, int, 
  															int, int, int, unsigned int, int, 
  															int, int, int, int, int *, int, 
  															int *, int, void *))unk_70CE720)(
    (unsigned int)&savedregs ^ dword_75240A8,
    a1,
    v12,
    v14,
    v15,
    v16,
    v17,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    (unsigned int)&savedregs ^ dword_75240A8,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v7,
    &unk_746476C);
  if ( szStockCode )
  {
    v35 = ((int (__stdcall *)(int))kernel32_lstrlenAStub)(szStockCode) + 1;
    if ( v35 <= 0x3FFFFFFF )
    {
      ((void (*)(void))unk_745A8F0)();
      v13 = ((int (__stdcall *)(int *, int, int, _DWORD))unk_70CE5F0)(&savedregs, szStockCode, v35, 0);
    }
    else
    {
      v13 = 0;
    }
    ((void (__thiscall *)(int *, int))unk_57341E49)(&v22, v13);
  }
  else
  {
    ((void (__thiscall *)(int *, _DWORD))unk_57341E49)(&v22, 0);
  }
  v38 = &v22;
  v37 = (int *)a3;
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, int *))unk_70F4320)(
         *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
         a3,
         &v22);
  if ( nCurTradeDate != v8 )
  {
    v36 = &v22;
    LOBYTE(v8) = a3;
    v35 = v8;
    ((void (__thiscall *)(_DWORD, int, int *))unk_70F44B0)(
      *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
      v8,
      &v22);
  }
  if ( nL2Count )
  {
    ((void (__thiscall *)(int *, unsigned int, int *, int *))unk_70F42D0)(&v29, nL2Count, v37, v38);
    LOBYTE(v38) = 1;
    for ( i = 0; i < nL2Count; ++i )
    {
      *(_DWORD *)(((int (__thiscall *)(int *, unsigned int))unk_718F090)(&v29, i) + 8) = *(_DWORD *)(pL2Data + 17 * i + 8);
      *(_DWORD *)(((int (__thiscall *)(int *, unsigned int))unk_718F090)(&v29, i) + 12) = *(_DWORD *)(pL2Data + 17 * i + 12);
      *(_DWORD *)((int (__thiscall *)(int *, unsigned int))unk_718F090)(&v29, i) = *(_DWORD *)(pL2Data + 17 * i);
      *(_DWORD *)(((int (__thiscall *)(int *, unsigned int))unk_718F090)(&v29, i) + 4) = *(_DWORD *)(pL2Data + 17 * i + 4);
      *(_BYTE *)(((int (__thiscall *)(int *, unsigned int))unk_718F090)(&v29, i) + 16) = *(_BYTE *)(pL2Data + 17 * i + 16);
    }
    v38 = (int *)1;
    v37 = &v33;
    v36 = (int *)((int (__thiscall *)(int *, _DWORD, unsigned int, int))unk_718F090)   
                                     (&v29, 0, nL2Count, nCurTradeDate);                    //处理后的分笔数据
    v35 = a4;
    v34 = &v22;
    LOBYTE(v10) = a3;
    v33 = v10;
    v11 = ((int (__thiscall *)(_DWORD, int, int *, int, int *))unk_70F4510)(
            *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
            v10,
            &v22,
            a4,
            v36);
    LOBYTE(v38) = 0;
    ((void (__thiscall *)(int *))unk_7142D30)(&v29);
    v38 = (int *)-1;
    ((void (__thiscall *)(int *))msvcp80_std::basic_string<wchar_t,std::char_traits<wchar_t>,
            std::allocator<wchar_t> >::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >)(&v22);
    result = v11;
  }
  else
  {
    v38 = (int *)-1;
    ((void (__thiscall *)(int *))msvcp80_std::basic_string<wchar_t,std::char_traits<wchar_t>,
           std::allocator<wchar_t> >::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >)(&v22);
    result = 0;
  }
  return result;
}