

int __thiscall datacenter_CDataMgr::App_L2TickData(void *this, int a2, char a3, int a4, int a5, int a6)
{
  int v6; // eax

  ((void (__thiscall *)(void *, void *))datacenter_CDataMgr::CheckThreadId)(this, this);
  v6 = a6;
  LOBYTE(v6) = a3;
  return ((int (__cdecl *)(int, int, int, int, int))datacenter_QDataEngine::App_L2TickData)(a2, v6, a4, a5, a6);
  考虑在此处加入跳转，换取解码后的数据，在此处代替本函数的返回。
}


int __cdecl datacenter_QDataEngine::App_L2TickData(int a1, unsigned __int8 a2, int a3, unsigned int a4, int a5)
{
  int v5; // eax
  int result; // eax
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp+0h] [ebp-78h]
  int v13; // [esp+4h] [ebp-74h]
  int *v14; // [esp+8h] [ebp-70h]
  int v15; // [esp+Ch] [ebp-6Ch]
  int v16; // [esp+10h] [ebp-68h]
  unsigned int v17; // [esp+14h] [ebp-64h]
  int v18; // [esp+18h] [ebp-60h]
  int v19; // [esp+1Ch] [ebp-5Ch]
  unsigned int i; // [esp+20h] [ebp-58h]
  int v21; // [esp+24h] [ebp-54h]
  int v22; // [esp+28h] [ebp-50h]
  int v23; // [esp+2Ch] [ebp-4Ch]
  char v24; // [esp+30h] [ebp-48h]
  unsigned int v25; // [esp+50h] [ebp-28h]
  int v26; // [esp+58h] [ebp-20h]
  char v27; // [esp+5Ch] [ebp-1Ch]
  int v28; // [esp+74h] [ebp-4h]

  v23 = ((int (*)(void))unk_715E720)();
  v21 = a1;
  if ( a1 )
  {
    v26 = ((int (__stdcall *)(int))kernel32_lstrlenAStub)(v21) + 1;
    if ( v26 <= 0x3FFFFFFF )
    {
      ((void (*)(void))unk_74EA8F0)();
      v14 = &v12;
      v15 = ((int (__stdcall *)(int *, int, int, _DWORD))unk_715E5F0)(&v12, v21, v26, 0);
    }
    else
    {
      v15 = 0;
    }
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  ((void (__thiscall *)(char *, int))unk_6A971E49)(&v24, v16);
  v28 = 0;
  v5 = ((int (__thiscall *)(_DWORD, _DWORD, char *))unk_7184320)(
         *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
         a2,
         &v24);
  v22 = v5;
  if ( a5 == v5 )
  {
    if ( !a3 )
      ((void (__thiscall *)(_DWORD, _DWORD, char *, signed int))unk_71843E0)(
        *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
        a2,
        &v24,
        -1);
    if ( a4 )
    {
      ((void (__thiscall *)(char *))unk_7260350)(&v27);
      LOBYTE(v28) = 1;
      ((void (__thiscall *)(_DWORD, _DWORD, char *, char *, signed int))unk_7184440)(
        *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
        a2,
        &v24,
        &v27,
        -1);
      if ( a4 >= ((int (__thiscall *)(char *))unk_7260A60)(&v27) )
        v13 = ((int (__thiscall *)(char *))unk_7260A60)(&v27);
      else
        v13 = a4;
      v25 = v13;
      for ( i = 0; i < v25; ++i )
      {
        v7 = ((int (__thiscall *)(char *, unsigned int))unk_721F090)(&v27, i);
        *(_DWORD *)(a3 + 17 * i + 8) = *(_DWORD *)(v7 + 8);
        v8 = ((int (__thiscall *)(char *, unsigned int))unk_721F090)(&v27, i);
        *(_DWORD *)(a3 + 17 * i + 12) = *(_DWORD *)(v8 + 12);
        v9 = (_DWORD *)((int (__thiscall *)(char *, unsigned int))unk_721F090)(&v27, i);
        *(_DWORD *)(a3 + 17 * i) = *v9;
        v10 = ((int (__thiscall *)(char *, unsigned int))unk_721F090)(&v27, i);
        *(_DWORD *)(a3 + 17 * i + 4) = *(_DWORD *)(v10 + 4);
        v11 = ((int (__thiscall *)(char *, unsigned int))unk_721F090)(&v27, i);
        *(_BYTE *)(a3 + 17 * i + 16) = *(_BYTE *)(v11 + 16);
      }
      v17 = v25;
      LOBYTE(v28) = 0;
      sub_71D2D30(&v27);
      v28 = -1;
      ((void (__thiscall *)(char *))msvcp80_std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >)(&v24);
      result = v17;
    }
    else
    {
      v18 = 0;
      v28 = -1;
      ((void (__thiscall *)(char *))msvcp80_std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >)(&v24);
      result = v18;
    }
  }
  else
  {
    LOBYTE(v5) = a2;
    ((void (__thiscall *)(_DWORD, int, char *))unk_71844B0)(
      *((_DWORD *)datacenter_QDataEngine::m_pDataCenter + 3),
      v5,
      &v24);
    v19 = 0;
    v28 = -1;
    ((void (__thiscall *)(char *))msvcp80_std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >)(&v24);
    result = v19;
  }
  return result;
}

unsigned int __cdecl QDataEngine::App_TickData(char *a1, char a2, struct DETAILREC *a3, unsigned int a4, int a5)
{
	//当日推送L1tick数据
	           //a1股票代码
  void *v5; // esp a1  股票代码，
            // a5  日期的16进制表示
            //     a4  数据项数
  int v6; // ecx
  int v7; // ecx
  unsigned int result; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  signed int v16; // eax
  double v17; // st7
  int v18; // [esp+0h] [ebp-78h]
  unsigned int v19; // [esp+4h] [ebp-74h]
  LPWSTR lpWideCharStr; // [esp+8h] [ebp-70h]
  int v21; // [esp+Ch] [ebp-6Ch]
  int v22; // [esp+10h] [ebp-68h]
  unsigned int v23; // [esp+14h] [ebp-64h]
  unsigned int v24; // [esp+18h] [ebp-60h]
  unsigned int v25; // [esp+1Ch] [ebp-5Ch]
  unsigned int i; // [esp+20h] [ebp-58h]
  LPCSTR lpString; // [esp+24h] [ebp-54h]
  int v28; // [esp+28h] [ebp-50h]
  int v29; // [esp+2Ch] [ebp-4Ch]
  char v30; // [esp+30h] [ebp-48h]
  unsigned int v31; // [esp+50h] [ebp-28h]
  int cchWideChar; // [esp+58h] [ebp-20h]
  char v33; // [esp+5Ch] [ebp-1Ch]
  int v34; // [esp+74h] [ebp-4h]

  v29 = sub_4D8E720();
  lpString = a1;                                // 股票代码
  if ( a1 )
  {
    cchWideChar = lstrlenA(lpString) + 1;
    if ( cchWideChar <= 0x3FFFFFFF )
    {
      v5 = alloca(2 * cchWideChar);
      lpWideCharStr = (LPWSTR)&v18;
      v21 = sub_4D8E5F0((LPWSTR)&v18, lpString, cchWideChar, 0);
    }
    else
    {
      v21 = 0;
    }
    v22 = v21;
  }
  else
  {
    v22 = 0;
  }
  std::basic_string<wchar_t,std::char_traits<wchar_t>,
  	std::allocator<wchar_t>>::basic_string<wchar_t,
  	std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v30,
    v22);
    
  v34 = 0;
  v6 = *((_DWORD *)QDataEngine::m_pDataCenter + 2);
  v28 = sub_4DB3E70((unsigned __int8)a2, &v30);
  if ( a5 == v28 )
  {
    if ( !a3 )
    {
      v9 = *((_DWORD *)QDataEngine::m_pDataCenter + 2);
      sub_4DB3F30((unsigned __int8)a2, &v30, -1);
    }
    if ( a4 )
    {
      sub_4DB3DD0(&v33);
      LOBYTE(v34) = 1;
      v10 = *((_DWORD *)QDataEngine::m_pDataCenter + 2);
      sub_4DB3F90((unsigned __int8)a2, &v30, &v33, -1);
      if ( a4 >= sub_4DAD640(&v33) )
        v19 = sub_4DAD640(&v33);
      else
        v19 = a4;
      v31 = v19;                                // TickData  分时成交数据
      for ( i = 0; i < v31; ++i )
      {
        v11 = sub_4DB1160(i);
        *((_BYTE *)a3 + 14 * i) = *(_BYTE *)(v11 + 20);    小时
        v12 = sub_4DB1160(i);
        *((_BYTE *)a3 + 14 * i + 1) = *(_BYTE *)(v12 + 21);  分钟
        v13 = sub_4DB1160(i);
        *((_BYTE *)a3 + 14 * i + 2) = *(_BYTE *)(v13 + 22);  秒
        v15 = sub_4DB1160(i);
        *((_BYTE *)a3 + 14 * i + 3) = *(_BYTE *)(v15 + 23);  买卖方向
        
        v16 = (signed int)*(float *)(sub_4DB1160(i) + 4);    
        *(_DWORD *)((char *)a3 + 14 * i + 4) = v16;        当前价位*1000
        
        v17 = *(float *)sub_4DB1160(i);
        *(_DWORD *)((char *)a3 + 14 * i + 8) = (signed int)v17;   成交量（股数）
        
        v14 = sub_4DB1160(i);
        *((_WORD *)a3 + 7 * i + 12) = *(_WORD *)(v14 + 24);  //成交笔数
      
      }
      v23 = v31;
      LOBYTE(v34) = 0;
      sub_4DB3E50(&v33);
      v34 = -1;
      std::basic_string<wchar_t,std::char_traits<wchar_t>,
      		std::allocator<wchar_t>>::~basic_string<wchar_t,
      		std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v30);
      result = v23;
    }
    else
    {
      v24 = 0;
      v34 = -1;
      std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v30);
      result = v24;
    }
  }
  else
  {
    v7 = *((_DWORD *)QDataEngine::m_pDataCenter + 2);
    sub_4DB4000(a2, &v30);
    v25 = 0;
    v34 = -1;
    std::basic_string<wchar_t,std::char_traits<wchar_t>,
    		std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,
    		std::allocator<wchar_t>>(&v30);
    			
    result = v25;
  }
  return result;
}