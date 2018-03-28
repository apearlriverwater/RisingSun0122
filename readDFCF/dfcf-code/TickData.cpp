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