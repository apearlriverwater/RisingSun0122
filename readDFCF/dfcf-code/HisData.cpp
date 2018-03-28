int __cdecl QDataEngine::Add_HisData(char a1, char *szStockCode, char a3, unsigned int a4, struct DAYDATA *a5)
{
  int v5; // ecx

  v5 = *((_DWORD *)QDataEngine::m_pDataCenter + 10);
  return sub_51301A0(szStockCode, a1, a3, a4, a5, 0);
}

int __thiscall sub_51301A0(void *this, int a2, unsigned __int8 a3, unsigned __int8 a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // edx
  char v9; // ST04_1
  int v11; // [esp-10h] [ebp-6Ch]
  int v12; // [esp-Ch] [ebp-68h]
  int v13; // [esp-8h] [ebp-64h]
  _DWORD *v14; // [esp-4h] [ebp-60h]
  int v15; // [esp+0h] [ebp-5Ch]
  int v16; // [esp+4h] [ebp-58h]
  int v17; // [esp+8h] [ebp-54h]
  int v18; // [esp+Ch] [ebp-50h]
  int v19; // [esp+10h] [ebp-4Ch]
  void *v20; // [esp+14h] [ebp-48h]
  int *v21; // [esp+18h] [ebp-44h]
  char v22; // [esp+1Ch] [ebp-40h]
  int v23; // [esp+38h] [ebp-24h]
  unsigned __int8 v24; // [esp+3Fh] [ebp-1Dh]
  int v25; // [esp+40h] [ebp-1Ch]
  char v26; // [esp+44h] [ebp-18h]
  int v27; // [esp+48h] [ebp-14h]
  int v28; // [esp+4Ch] [ebp-10h]
  int v29; // [esp+58h] [ebp-4h]

  v20 = this;
  sub_4E3C4B0(this);
  v27 = 0;
  v25 = a4;
  v24 = a3;
  v28 = sub_5130110(&v24, &v25);
  if ( v28 )
  {
    v23 = 0;
    v19 = sub_4E0F450(&v22, a2, &v23);
    v18 = v19;
    v29 = 0;
    v7 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(v19, v15);
    mfc80xU_283(&v26, v7);
    LOBYTE(v29) = 2;
    std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v22);
    v15 = a7;
    v14 = (_DWORD *)a4;
    v13 = a5;
    v12 = a6;
    v11 = a5;
    v21 = &v11;
    v17 = mfc80xU_280(&v11, &v26);
    v16 = sub_51343F0(v28, v8, a3, v9, *(float *)&v11, v12, v13, v14);
    v27 = v16;
    v29 = -1;
    mfc80xU_577(&v26);
  }
  else
  {
    v27 = 0;
  }
  sub_4E61190();
  return v27;
}

int __fastcall sub_51343F0(int a1, int a2, int a3, char a4, float a5, int a6, signed int a7, _DWORD *a8)
{
  float v8; // ecx
  int result; // eax
  void *v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // edx
  wchar_t *v14; // eax
  void *v15; // eax
  void *v16; // eax
  int v17; // eax
  void *v18; // eax
  void *v19; // eax
  int v20; // eax
  void *v21; // eax
  void *v22; // eax
  int v23; // eax
  void *v24; // eax
  void *v25; // eax
  int v26; // eax
  void *v27; // eax
  wchar_t *v28; // eax
  _DWORD *v29; // edx
  int v30; // eax
  int v31; // [esp-18h] [ebp-A4h]
  signed int v32; // [esp-14h] [ebp-A0h]
  int v33; // [esp-10h] [ebp-9Ch]
  int *v34; // [esp-Ch] [ebp-98h]
  int *v35; // [esp-8h] [ebp-94h]
  int *v36; // [esp-4h] [ebp-90h]
  float v37; // [esp+0h] [ebp-8Ch]
  int v38; // [esp+8h] [ebp-84h]
  int v39; // [esp+Ch] [ebp-80h]
  int v40; // [esp+10h] [ebp-7Ch]
  int v41; // [esp+14h] [ebp-78h]
  int v42; // [esp+18h] [ebp-74h]
  int *v43; // [esp+1Ch] [ebp-70h]
  int v44; // [esp+24h] [ebp-68h]
  int v45; // [esp+28h] [ebp-64h]
  int j; // [esp+2Ch] [ebp-60h]
  int i; // [esp+30h] [ebp-5Ch]
  int v48; // [esp+34h] [ebp-58h]
  int v49; // [esp+38h] [ebp-54h]
  int v50; // [esp+48h] [ebp-44h]
  int k; // [esp+4Ch] [ebp-40h]
  int v52; // [esp+50h] [ebp-3Ch]
  char v53; // [esp+54h] [ebp-38h]
  int v54; // [esp+64h] [ebp-28h]
  char v55; // [esp+68h] [ebp-24h]
  int v56; // [esp+78h] [ebp-14h]
  int v57; // [esp+7Ch] [ebp-10h]
  int v58; // [esp+88h] [ebp-4h]

  v39 = a1;
  v58 = 0;
  v48 = 0;
  v57 = 0;
  v52 = 0;
  for ( i = a6 - 1; i > 0; --i )
  {
    v37 = *(float *)&a1;
    if ( log(*(float *)(LODWORD(a5) + 32 * i + 4)) >= 0.0000009999999974752427 )
      break;
    LODWORD(v37) = 32 * i;
    if ( log(*(float *)(LODWORD(a5) + 32 * i + 8)) >= 0.0000009999999974752427 )
      break;
    v37 = a5;
    if ( log(*(float *)(LODWORD(a5) + 32 * i + 12)) >= 0.0000009999999974752427 )
      break;
    v37 = v8;
    if ( log(*(float *)(LODWORD(a5) + 32 * i + 16)) >= 0.0000009999999974752427 )
      break;
    ++v52;
    a1 = i - 1;
  }
  a6 -= v52;
  if ( a6 > 0 )
  {
    sub_4E389C0(a6);
    LOBYTE(v58) = 1;
    LODWORD(v37) = 40 * a6;
    v10 = (void *)sub_4ED4200(0);
    memset(v10, 0, LODWORD(v37));
    for ( j = 0; j < a6; ++j )
    {
      v44 = sub_4ED4200(j);
      /*v44结构指针  浮点数要从浮点运算寄存器读取，否则要自行编写代码转换
      	Message("close=%1.3e,",st0),0
      	
      	     dw0：           0  Date
      	     dw1：          +4  Time
      	     float1:				+8  Close
      	     float2:				+12 High
      	     float3:				+16 Low
      	     float4:				+20 Open
      	     dw2：					+24 Vol
      	     dw?：					+28
      	     double1：			+32  Amount    
      	 
      	v45结构指针
      	     dw0：           0
      	     float0:				+4
      	     float1:				+8
      	     float2:				+12
      	     float3:				+16
      	     dw1:						+20
      	     double：				+24
      	    
      */
      v45 = LODWORD(a5) + 32 * j;
      *(_DWORD *)v44 = *(_DWORD *)v45;
      *(float *)(v44 + 8) = *(float *)(v45 + 4);
      *(float *)(v44 + 12) = *(float *)(v45 + 8);
      *(float *)(v44 + 16) = *(float *)(v45 + 12);
      *(float *)(v44 + 20) = *(float *)(v45 + 16);
      
      if ( a7 >= 9 )
      {
        *(_DWORD *)(v44 + 4) = 0;
        *(_DWORD *)(v44 + 24) = *(_DWORD *)(v45 + 20);
        *(_DWORD *)(v44 + 28) = 0;
        *(double *)(v44 + 32) = *(double *)(v45 + 24);
        
      }
      else
      {
        if ( j && *(_DWORD *)v45 == *(_DWORD *)(LODWORD(a5) + 32 * (j - 1)) )
        {
          *(_DWORD *)(v44 + 24) = *(_DWORD *)(v45 + 20) - *(_DWORD *)(LODWORD(a5) + 32 * (j - 1) + 20);
          *(_DWORD *)(v44 + 28) = 0;
          *(double *)(v44 + 32) = *(double *)(v45 + 24) - *(double *)(LODWORD(a5) + 32 * (j - 1) + 24);
        }
        else
        {
          *(_DWORD *)(v44 + 24) = *(_DWORD *)(v45 + 20);
          *(_DWORD *)(v44 + 28) = 0;
          *(double *)(v44 + 32) = *(double *)(v45 + 24);
        }
        v37 = COERCE_FLOAT(&v57);
        v36 = &v48;
        v35 = (int *)LODWORD(a5);
        v34 = (int *)a6;
        v33 = j;
        v32 = a7;
        v31 = j;
        v43 = &v31;
        v38 = mfc80xU_280(&v31, &a4);
        sub_5151740(a3, v31, v32, v33, v34, v35, v36, LODWORD(v37));
        
        *(_DWORD *)(v44 + 4) = 100 * v57 + 10000 * v48;
        
      }
    }
    sub_4E38990(&v49);
    LOBYTE(v58) = 2;
    v54 = 0;
    v37 = COERCE_FLOAT(&v54);
    v36 = &v49;
    v14 = (wchar_t *)mfc80xU_870(&a4);
    sub_4E38EB0(v14, (int)v36, SLODWORD(v37));
    v56 = sub_4E65130(&v49);
    sub_4E389C0(a6 + v56);
    LOBYTE(v58) = 3;
    LODWORD(v37) = 40 * (a6 + v56);
    v36 = 0;
    v15 = (void *)sub_4ED4200(0);
    memset(v15, (int)v36, LODWORD(v37));
    v50 = 0;
    k = 0;
    if ( v56 > 0 )
    {
      v37 = COERCE_FLOAT(sub_4ED4200(0));
      v17 = sub_4ED4200(a6 - 1);
      if ( (unsigned __int8)sub_4E388C0(v17, LODWORD(v37)) )
      {
        LODWORD(v37) = 40 * a6;
        v36 = (int *)sub_4ED4200(0);
        v18 = (void *)sub_4ED4200(0);
        memcpy(v18, v36, LODWORD(v37));
        LODWORD(v37) = 40 * v56;
        v36 = (int *)sub_4ED4200(0);
        v19 = (void *)sub_4ED4200(a6);
        memcpy(v19, v36, LODWORD(v37));
        v50 = v56 + a6;
      }
      else
      {
        v37 = COERCE_FLOAT(sub_4ED4200(0));
        v20 = sub_4ED4200(v56 - 1);
        if ( (unsigned __int8)sub_4E388C0(v20, LODWORD(v37)) )
        {
          LODWORD(v37) = 40 * v56;
          v36 = (int *)sub_4ED4200(0);
          v21 = (void *)sub_4ED4200(0);
          memcpy(v21, v36, LODWORD(v37));
          LODWORD(v37) = 40 * a6;
          v36 = (int *)sub_4ED4200(0);
          v22 = (void *)sub_4ED4200(v56);
          memcpy(v22, v36, LODWORD(v37));
          v50 = v56 + a6;
        }
        else
        {
          for ( k = 0; k < v56; ++k )
          {
            v37 = COERCE_FLOAT(sub_4ED4200(0));
            v23 = sub_4ED4200(k);
            if ( !(unsigned __int8)sub_4E388C0(v23, LODWORD(v37)) )
              break;
          }
          if ( k > 0 )
          {
            LODWORD(v37) = 40 * k;
            v36 = (int *)sub_4ED4200(0);
            v24 = (void *)sub_4ED4200(0);
            memcpy(v24, v36, LODWORD(v37));
            v50 += k;
          }
          LODWORD(v37) = 40 * a6;
          v36 = (int *)sub_4ED4200(0);
          v25 = (void *)sub_4ED4200(v50);
          memcpy(v25, v36, LODWORD(v37));
          v50 += a6;
          while ( k < v56 )
          {
            v37 = COERCE_FLOAT(sub_4ED4200(a6 - 1));
            v26 = sub_4ED4200(k);
            if ( (unsigned __int8)sub_4E38910(v26, LODWORD(v37)) )
              break;
            ++k;
          }
          if ( k < v56 )
          {
            LODWORD(v37) = 40 * (v56 - k);
            v36 = (int *)sub_4ED4200(k);
            v27 = (void *)sub_4ED4200(v50);
            memcpy(v27, v36, LODWORD(v37));
            v50 += v56 - k;
          }
        }
      }
    }
    else
    {
      LODWORD(v37) = 40 * a6;
      v36 = (int *)sub_4ED4200(0);
      v16 = (void *)sub_4ED4200(0);
      memcpy(v16, v36, LODWORD(v37));
      v50 = a6;
    }
    v42 = v50;
    v41 = 0;
    v37 = COERCE_FLOAT(&v54);
    v36 = (int *)sub_4ED4200(0);
    v35 = &v42;
    v34 = &v41;
    v28 = (wchar_t *)mfc80xU_870(&a4);
    sub_4E38F90(v28, (int)v34, (int)v35, (int)v36, SLODWORD(v37));
    if ( a8 )
    {
      v29 = a8;
      v30 = v39;
      *a8 = *(_DWORD *)(v39 + 288);
      v29[1] = *(_DWORD *)(v30 + 292);
    }
    v40 = 1;
    LOBYTE(v58) = 2;
    sub_4ED4010(&v55);
    LOBYTE(v58) = 1;
    sub_4ED4010(&v49);
    LOBYTE(v58) = 0;
    sub_4ED4010(&v53);
    v58 = -1;
    mfc80xU_577(&a4);
    result = v40;
  }
  else
  {
    v58 = -1;
    mfc80xU_577(&a4);
    result = 0;
  }
  return result;
}