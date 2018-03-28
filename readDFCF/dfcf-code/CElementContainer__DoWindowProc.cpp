int __thiscall framebase_CElementContainer::DoLBDownUp(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // esi
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v9; // eax

  v4 = this;
  v5 = (signed __int16)a4 - this[9];
  v6 = SHIWORD(a4) - this[10];
  if ( !a2 )
    return (*(int (__stdcall **)(int, int))(*this + 80))(v5, v6);
  if ( this[63] )
  {
    if ( this[13] )
    {
      v7 = ((int (__stdcall *)(_DWORD *))framebase_CElementContainer::GetContainerWnd)(this);
      ((void (__thiscall *)(int))framebase_CElementContainerWnd::SetFocusObject)(v7);
      return (*(int (__thiscall **)(_DWORD *, int, int))(*v4 + 76))(v4, v5, v6);
    }
    v9 = ((int (__stdcall *)(_DWORD *))framebase_CElementContainer::GetViewManager)(this);
    ((void (__thiscall *)(int))framebase_CViewManager::SetFocusObject)(v9);
  }
  return (*(int (__thiscall **)(_DWORD *, int, int))(*v4 + 76))(v4, v5, v6);  //call sub_6F31830
}

signed int __thiscall sub_6F31830(void *this, int a2, int a3)
{
  void *v3; // ST04_4

  v3 = this;
  ((void (__thiscall *)(void *))framebase_CElementContainer::SkipMsg)(this);
  ((void (__thiscall *)(void *, _DWORD))unk_6F30F30)(v3, 0);
  return 1;
}

int __thiscall framebase_CElementContainer::DoWindowProc(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v15; // [esp+28h] [ebp-2Ch]
  int v16; // [esp+2Ch] [ebp-28h]
  int v17; // [esp+30h] [ebp-24h]
  int v18; // [esp+34h] [ebp-20h]
  unsigned int v19; // [esp+38h] [ebp-1Ch]
  int v20; // [esp+3Ch] [ebp-18h]
  int v21; // [esp+40h] [ebp-14h]
  int v22; // [esp+50h] [ebp-4h]

  v6 = this;
  v7 = this[14];
  if ( v7 )
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v7 + 160))(a2, a3, a4);
  v8 = a2;
  switch ( a2 )
  {
    case 512:
      ((void (__thiscall *)(_DWORD *, int, int))framebase_CElementContainer::DoMouseMove)(v6, a3, a4);
LABEL_62:
      v8 = a2;
      return (*(int (__thiscall **)(_DWORD *, int, int, int, int, int))(*v6 + 60))(v6, v8, a3, a4, a5, a6);
    case 32:
      (*(void (__thiscall **)(_DWORD *, int, int))(*v6 + 140))(v6, a3, a4);
      goto LABEL_62;
    case 61026:
      (*(void (__thiscall **)(_DWORD *, int))(*v6 + 104))(v6, a4);
      goto LABEL_62;
    case 275:
      v9 = ((int (*)(void))kernel32_GetTickCountStub)();
      ((void (__thiscall *)(_DWORD *, int))framebase_CElementContainer::DoTimer)(v6, v9);
      goto LABEL_62;
    case 61024:
      if ( a3 == v6[6] )
      {
        if ( v6[13] )
        {
          ((void (__thiscall *)(_DWORD *))framebase_CElementContainer::GetContainerWnd)(v6);
          v10 = ((int (__cdecl *)(unsigned int *, int))framebase_CElementContainerWnd::GetExData)(&v19, a4);
        }
        else
        {
          ((void (__thiscall *)(_DWORD *))framebase_CElementContainer::GetViewManager)(v6);
          v10 = ((int (__cdecl *)(unsigned int *, int))framebase_CViewManager::GetExData)(&v19, a4);
        }
        if ( v10 )
        {
          v11 = ((int (__cdecl *)(int *))globalenvironment_CGlobalEnv::GetGlobalEnv)(&v16);
          v12 = 0;
          v22 = 0;
          v13 = *(_DWORD *)(*(_DWORD *)v11 + 40);
          if ( v13 )
          {
            v15 = ((int (__cdecl *)(int, _DWORD, void *, void *, _DWORD))unk_1001CDB4)(
                    v13,
                    0,
                    &unk_10031120,
                    &unk_100311F4,
                    0);
            v12 = v15;
          }
          else
          {
            v15 = 0;
          }
          v18 = v12;
          if ( v12 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)v12 + 4))(v12);
            v12 = v15;
          }
          LOBYTE(v22) = 2;
          if ( v16 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
            v12 = v15;
          }
          v17 = (*(int (__stdcall **)(_DWORD, signed int, int, int))(*(_DWORD *)v12 + 28))(v6[12], 61024, a3, a4);
          if ( v19 < 0x400 || v19 >= 0xEE60 && v19 <= 0xF248 )
            framebase_CElementContainer::DoWindowProc(v19, v20, v21, a5, a6);
          else
            (*(void (__thiscall **)(_DWORD *, unsigned int, int, int))(*v6 + 120))(v6, v19, v20, v21);
          (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 32))(v17);
          v22 = -1;
          (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(v15);
        }
        goto LABEL_62;
      }
      break;
    case 61027:
      ((void (__thiscall *)(_DWORD *, int, int))framebase_CElementContainer::DoControlMessage)(v6, a3, a4);
      goto LABEL_62;
    case 61025:
      (*(void (__thiscall **)(_DWORD *, int, int))(*v6 + 136))(v6, a3, a4);
      goto LABEL_62;
    case 15:
      ((void (__thiscall *)(_DWORD *))framebase_CElementContainer::DoPaint)(v6);
      goto LABEL_62;
    case 273:
      ((void (__thiscall *)(_DWORD *, int, int))framebase_CElementContainer::DoCommand)(v6, a3, a4);
      goto LABEL_62;
    case 20:
      ((void (__thiscall *)(_DWORD *, int))framebase_CElementContainer::DoEraseBackground)(v6, a3);
      goto LABEL_62;
    case 24:
      ((void (__thiscall *)(_DWORD *, int))framebase_CElementContainer::DoShow)(v6, a3);
      goto LABEL_62;
    case 256:
    case 257:
      ((void (__thiscall *)(_DWORD *, bool, int, int))framebase_CElementContainer::DoKeyDownUp)(v6, a2 == 256, a3, a4);
      goto LABEL_62;
    case 513:
    case 514:
      ((void (__thiscall *)(_DWORD *, bool, int, int))framebase_CElementContainer::DoLBDownUp)(v6, a2 == 513, a3, a4);
      goto LABEL_62;
    case 516:
    case 517:
      ((void (__thiscall *)(_DWORD *, bool, int, int))framebase_CElementContainer::DoRBDownUp)(v6, a2 == 516, a3, a4);
      goto LABEL_62;
    case 515:
    case 518:
      ((void (__thiscall *)(_DWORD *, bool, int, int))framebase_CElementContainer::DoDBClick)(v6, a2 == 515, a3, a4);
      goto LABEL_62;
    case 522:
      ((void (__thiscall *)(_DWORD *, int, int))framebase_CElementContainer::DoMouseWheel)(v6, a3, a4);
      goto LABEL_62;
    case 5:
      ((void (__thiscall *)(_DWORD *, int, int))framebase_CElementContainer::DoSize)(v6, a3, a4);
      goto LABEL_62;
    case 675:
      (*(void (__thiscall **)(_DWORD *))(*v6 + 144))(v6);
      goto LABEL_62;
    case 258:
      ((void (__thiscall *)(_DWORD *, int, int))framebase_CElementContainer::DoChar)(v6, a3, a4);
      goto LABEL_62;
  }
  return (*(int (__thiscall **)(_DWORD *, int, int, int, int, int))(*v6 + 60))(v6, v8, a3, a4, a5, a6);
}