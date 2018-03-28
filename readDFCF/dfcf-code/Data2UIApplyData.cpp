void __thiscall CDataMgr::ApplyData(CDataMgr *this, struct _CREQUEST *a2, bool a3)
{
  LightLogger::CLogger *v3; // eax
  LightLogger::CLogger *v4; // eax
  LightLogger::CLogger *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  Request *v9; // eax
  Request *v10; // eax
  Request *v11; // eax
  Request *v12; // eax
  Request *v13; // eax
  int v14; // eax
  HWND v15; // edx
  int v16; // ecx
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  Request *v20; // eax
  struct _CREQUEST *v21; // eax
  Request *v22; // eax
  struct _CREQUEST *v23; // eax
  Request *v24; // eax
  struct _CREQUEST *v25; // eax
  Request *v26; // eax
  struct _CREQUEST *v27; // eax
  Request *v28; // eax
  struct _CREQUEST *v29; // eax
  Request *v30; // eax
  int v31; // eax
  Request *v32; // eax
  void *v33; // esp
  HWND v34; // ecx
  Request *v35; // eax
  void *v36; // esp
  void *v37; // esp
  void *v38; // esp
  int v39; // edx
  Request *v40; // eax
  void *v41; // esp
  int v42; // edx
  Request *v43; // eax
  void *v44; // esp
  int v45; // edx
  HWND v46; // ecx
  Request *v47; // eax
  void *v48; // esp
  int v49; // edx
  HWND v50; // ecx
  Request *v51; // eax
  void *v52; // esp
  int v53; // ecx
  Request *v54; // eax
  void *v55; // esp
  HWND v56; // ecx
  Request *v57; // eax
  struct _CREQUEST *v58; // ecx
  Request *v59; // eax
  int v60; // edx
  Request *v61; // eax
  int v62; // ecx
  HWND v63; // edx
  Request *v64; // eax
  int v65; // edx
  HWND v66; // eax
  Request *v67; // eax
  void *v68; // esp
  HWND v69; // edx
  Request *v70; // eax
  void *v71; // esp
  HWND v72; // edx
  Request *v73; // eax
  Request *v74; // eax
  Request *v75; // eax
  HWND *v76; // eax
  _DWORD *v77; // eax
  int *v78; // eax
  int v79; // edx
  int v80; // eax
  int v81; // edx
  Request *v82; // eax
  HWND *v83; // eax
  _DWORD *v84; // eax
  int v85; // eax
  int v86; // eax
  int v87; // eax
  int v88; // eax
  int v89; // eax
  int v90; // eax
  Request *v91; // eax
  struct _CREQUEST *v92; // ecx
  Request *v93; // eax
  struct _CREQUEST *v94; // ecx
  Request *v95; // eax
  int v96; // eax
  void *v97; // esp
  int v98; // ecx
  Request *v99; // eax
  int v100; // eax
  int v101; // eax
  int v102; // eax
  int v103; // eax
  int v104; // eax
  int v105; // edx
  HWND v106; // ecx
  int *v107; // ecx
  Request *v108; // eax
  Request *v109; // eax
  HWND v110; // ecx
  Request *v111; // eax
  HWND *v112; // eax
  _DWORD *v113; // eax
  int v114; // eax
  unsigned int v115; // eax
  _BYTE *v116; // eax
  int v117; // eax
  unsigned int v118; // eax
  HWND v119; // ecx
  int v120; // eax
  Request *v121; // eax
  void *v122; // esp
  HWND v123; // ecx
  int v124; // ecx
  Request *v125; // eax
  char *v126; // eax
  Request *v127; // eax
  char *v128; // eax
  Request *v129; // eax
  char *v130; // eax
  Request *v131; // eax
  char *v132; // eax
  Request *v133; // eax
  char *v134; // eax
  Request *v135; // eax
  int v136; // edx
  Request *v137; // eax
  void *v138; // esp
  HWND *v139; // eax
  _DWORD *v140; // eax
  int v141; // eax
  int v142; // eax
  Request *v143; // eax
  struct _CREQUEST *v144; // edx
  Request *v145; // eax
  struct _CREQUEST *v146; // edx
  Request *v147; // eax
  struct _CREQUEST *v148; // edx
  Request *v149; // eax
  struct _CREQUEST *v150; // edx
  Request *v151; // eax
  struct _CREQUEST *v152; // edx
  Request *v153; // eax
  struct _CREQUEST *v154; // edx
  Request *v155; // eax
  Request *v156; // eax
  Request *v157; // eax
  Request *v158; // eax
  int v159; // eax
  int v160; // eax
  HWND *v161; // eax
  _DWORD *v162; // eax
  int v163; // eax
  HWND *v164; // eax
  _DWORD *v165; // eax
  int v166; // eax
  HWND v167; // ecx
  char *v168; // eax
  Request *v169; // eax
  HWND v170; // ecx
  char *v171; // eax
  Request *v172; // eax
  Request *v173; // eax
  Request *v174; // eax
  Request *v175; // eax
  Request *v176; // eax
  Request *v177; // eax
  Request *v178; // eax
  Request *v179; // eax
  Request *v180; // eax
  Request *v181; // eax
  Request *v182; // eax
  Request *v183; // eax
  Request *v184; // eax
  Request *v185; // eax
  Request *v186; // eax
  Request *v187; // eax
  Request *v188; // eax
  Request *v189; // eax
  HWND v190; // ecx
  Request *v191; // eax
  Request *v192; // eax
  Request *v193; // eax
  HWND v194; // eax
  Request *v195; // eax
  Request *v196; // eax
  struct _CREQUEST *v197; // edx
  _BYTE *v198; // ecx
  Request *v199; // eax
  struct _CREQUEST *v200; // ecx
  _BYTE *v201; // eax
  Request *v202; // eax
  unsigned int v203; // eax
  unsigned __int16 *v204; // eax
  char *v205; // eax
  int v206; // eax
  HWND v207; // ecx
  Request *v208; // eax
  int v209; // eax
  Request *v210; // eax
  unsigned int v211; // eax
  LightLogger::CLogger *v212; // eax
  const wchar_t *v213; // eax
  struct _CREQUEST *v214; // ecx
  Request *v215; // eax
  struct _CREQUEST *v216; // ecx
  Request *v217; // eax
  unsigned int v218; // eax
  char *v219; // eax
  Request *v220; // eax
  HWND v221; // eax
  int v222; // edx
  HWND v223; // ecx
  int v224; // edx
  Request *v225; // eax
  HWND v226; // eax
  HWND v227; // ecx
  int v228; // eax
  HWND v229; // edx
  int v230; // eax
  Request *v231; // eax
  HWND v232; // eax
  int v233; // edx
  HWND v234; // ecx
  int v235; // edx
  Request *v236; // eax
  int v237; // edx
  HWND v238; // ecx
  int v239; // eax
  int v240; // edx
  Request *v241; // eax
  const WCHAR *v242; // eax
  const char *v243; // eax
  int v244; // ecx
  HWND v245; // eax
  HWND v246; // edx
  Request *v247; // eax
  Request *v248; // eax
  int v249; // eax
  int v250; // edx
  Request *v251; // eax
  int v252; // eax
  int v253; // eax
  char *v254; // eax
  int v255; // eax
  int v256; // eax
  char *v257; // eax
  HWND v258; // edx
  Request *v259; // eax
  bool v260; // al
  BOOL v261; // edx
  Request *v262; // eax
  Request *v263; // eax
  HWND v264; // eax
  Request *v265; // eax
  const WCHAR *v266; // eax
  int v267; // eax
  char *v268; // eax
  int v269; // eax
  int *v270; // eax
  int v271; // edx
  int v272; // eax
  int v273; // eax
  _DWORD *v274; // esi
  int v275; // eax
  const char *v276; // eax
  int v277; // ecx
  HWND v278; // eax
  Request *v279; // eax
  int v280; // eax
  char *v281; // eax
  int v282; // ecx
  int v283; // eax
  const char *v284; // eax
  int v285; // eax
  _DWORD *v286; // eax
  const char *v287; // eax
  int v288; // eax
  _DWORD *v289; // eax
  const char *v290; // eax
  const char *v291; // eax
  int v292; // eax
  struct _CREQUEST *v293; // ecx
  HWND v294; // edx
  Request *v295; // eax
  Request *v296; // eax
  int v297; // ecx
  HWND v298; // [esp-34h] [ebp-D64h]
  HWND v299; // [esp-30h] [ebp-D60h]
  int v300; // [esp-2Ch] [ebp-D5Ch]
  char v301; // [esp-28h] [ebp-D58h]
  HWND v302; // [esp-24h] [ebp-D54h]
  HWND v303; // [esp-20h] [ebp-D50h]
  HWND v304; // [esp-1Ch] [ebp-D4Ch]
  HWND v305; // [esp-18h] [ebp-D48h]
  HWND v306; // [esp-14h] [ebp-D44h]
  int v307; // [esp-10h] [ebp-D40h]
  HWND v308; // [esp-Ch] [ebp-D3Ch]
  int v309; // [esp-8h] [ebp-D38h]
  HWND v310; // [esp-4h] [ebp-D34h]
  int v311; // [esp+0h] [ebp-D30h]
  int v312; // [esp+8h] [ebp-D28h]
  char *v313; // [esp+Ch] [ebp-D24h]
  int v314; // [esp+10h] [ebp-D20h]
  int v315; // [esp+14h] [ebp-D1Ch]
  int v316; // [esp+18h] [ebp-D18h]
  int v317; // [esp+1Ch] [ebp-D14h]
  int v318; // [esp+20h] [ebp-D10h]
  int v319; // [esp+24h] [ebp-D0Ch]
  int v320; // [esp+28h] [ebp-D08h]
  int v321; // [esp+2Ch] [ebp-D04h]
  LPSTR v322; // [esp+30h] [ebp-D00h]
  char *v323; // [esp+34h] [ebp-CFCh]
  char *v324; // [esp+38h] [ebp-CF8h]
  int v325; // [esp+3Ch] [ebp-CF4h]
  int v326; // [esp+40h] [ebp-CF0h]
  LPSTR v327; // [esp+44h] [ebp-CECh]
  char *v328; // [esp+48h] [ebp-CE8h]
  char *v329; // [esp+4Ch] [ebp-CE4h]
  int v330; // [esp+50h] [ebp-CE0h]
  int v331; // [esp+54h] [ebp-CDCh]
  int v332; // [esp+58h] [ebp-CD8h]
  int v333; // [esp+5Ch] [ebp-CD4h]
  int v334; // [esp+60h] [ebp-CD0h]
  int v335; // [esp+64h] [ebp-CCCh]
  int v336; // [esp+68h] [ebp-CC8h]
  int v337; // [esp+6Ch] [ebp-CC4h]
  HWND v338; // [esp+70h] [ebp-CC0h]
  HWND v339; // [esp+74h] [ebp-CBCh]
  int v340; // [esp+78h] [ebp-CB8h]
  int v341; // [esp+7Ch] [ebp-CB4h]
  int v342; // [esp+80h] [ebp-CB0h]
  LPSTR v343; // [esp+84h] [ebp-CACh]
  char *v344; // [esp+88h] [ebp-CA8h]
  char *v345; // [esp+8Ch] [ebp-CA4h]
  int v346; // [esp+90h] [ebp-CA0h]
  int v347; // [esp+94h] [ebp-C9Ch]
  int v348; // [esp+98h] [ebp-C98h]
  int v349; // [esp+9Ch] [ebp-C94h]
  int v350; // [esp+A0h] [ebp-C90h]
  int v351; // [esp+A4h] [ebp-C8Ch]
  LPSTR v352; // [esp+A8h] [ebp-C88h]
  char *v353; // [esp+ACh] [ebp-C84h]
  char *v354; // [esp+B0h] [ebp-C80h]
  int v355; // [esp+B4h] [ebp-C7Ch]
  int v356; // [esp+B8h] [ebp-C78h]
  LPSTR v357; // [esp+BCh] [ebp-C74h]
  char *v358; // [esp+C0h] [ebp-C70h]
  char *v359; // [esp+C4h] [ebp-C6Ch]
  int v360; // [esp+C8h] [ebp-C68h]
  int v361; // [esp+CCh] [ebp-C64h]
  int v362; // [esp+D0h] [ebp-C60h]
  LPSTR v363; // [esp+D4h] [ebp-C5Ch]
  char *v364; // [esp+D8h] [ebp-C58h]
  char *v365; // [esp+DCh] [ebp-C54h]
  int v366; // [esp+E0h] [ebp-C50h]
  int v367; // [esp+E4h] [ebp-C4Ch]
  LPSTR v368; // [esp+E8h] [ebp-C48h]
  char *v369; // [esp+ECh] [ebp-C44h]
  char *v370; // [esp+F0h] [ebp-C40h]
  int v371; // [esp+F4h] [ebp-C3Ch]
  int v372; // [esp+F8h] [ebp-C38h]
  LPSTR v373; // [esp+FCh] [ebp-C34h]
  char *v374; // [esp+100h] [ebp-C30h]
  char *v375; // [esp+104h] [ebp-C2Ch]
  LPSTR v376; // [esp+108h] [ebp-C28h]
  char *v377; // [esp+10Ch] [ebp-C24h]
  char *v378; // [esp+110h] [ebp-C20h]
  LPSTR v379; // [esp+114h] [ebp-C1Ch]
  char *v380; // [esp+118h] [ebp-C18h]
  char *v381; // [esp+11Ch] [ebp-C14h]
  int v382; // [esp+120h] [ebp-C10h]
  int v383; // [esp+124h] [ebp-C0Ch]
  LPSTR v384; // [esp+128h] [ebp-C08h]
  char *v385; // [esp+12Ch] [ebp-C04h]
  char *v386; // [esp+130h] [ebp-C00h]
  LPSTR v387; // [esp+134h] [ebp-BFCh]
  char *v388; // [esp+138h] [ebp-BF8h]
  char *v389; // [esp+13Ch] [ebp-BF4h]
  LPSTR v390; // [esp+140h] [ebp-BF0h]
  char *v391; // [esp+144h] [ebp-BECh]
  char *v392; // [esp+148h] [ebp-BE8h]
  LPSTR lpMultiByteStr; // [esp+14Ch] [ebp-BE4h]
  char *v394; // [esp+150h] [ebp-BE0h]
  char *Src; // [esp+154h] [ebp-BDCh]
  int v396; // [esp+158h] [ebp-BD8h]
  void *v397; // [esp+15Ch] [ebp-BD4h]
  void *v398; // [esp+160h] [ebp-BD0h]
  CDataMgr *v399; // [esp+164h] [ebp-BCCh]
  char v400; // [esp+168h] [ebp-BC8h]
  char v401; // [esp+184h] [ebp-BACh]
  char v402; // [esp+1A0h] [ebp-B90h]
  char v403; // [esp+1A8h] [ebp-B88h]
  char v404; // [esp+1B0h] [ebp-B80h]
  char v405; // [esp+1CCh] [ebp-B64h]
  char v406; // [esp+1D4h] [ebp-B5Ch]
  char v407; // [esp+1DCh] [ebp-B54h]
  char v408; // [esp+1E4h] [ebp-B4Ch]
  char v409; // [esp+1ECh] [ebp-B44h]
  char v410; // [esp+1F4h] [ebp-B3Ch]
  char v411; // [esp+1FCh] [ebp-B34h]
  char v412; // [esp+204h] [ebp-B2Ch]
  int v413; // [esp+20Ch] [ebp-B24h]
  char v414; // [esp+210h] [ebp-B20h]
  char v415; // [esp+218h] [ebp-B18h]
  char v416; // [esp+220h] [ebp-B10h]
  char v417; // [esp+228h] [ebp-B08h]
  int v418; // [esp+230h] [ebp-B00h]
  int v419; // [esp+234h] [ebp-AFCh]
  int v420; // [esp+238h] [ebp-AF8h]
  int v421; // [esp+23Ch] [ebp-AF4h]
  int v422; // [esp+240h] [ebp-AF0h]
  char v423; // [esp+244h] [ebp-AECh]
  char v424; // [esp+24Ch] [ebp-AE4h]
  char v425; // [esp+254h] [ebp-ADCh]
  int v426; // [esp+25Ch] [ebp-AD4h]
  char v427; // [esp+260h] [ebp-AD0h]
  char v428; // [esp+268h] [ebp-AC8h]
  char v429; // [esp+270h] [ebp-AC0h]
  char v430; // [esp+278h] [ebp-AB8h]
  char v431; // [esp+280h] [ebp-AB0h]
  char v432; // [esp+288h] [ebp-AA8h]
  char v433; // [esp+290h] [ebp-AA0h]
  int *v434; // [esp+294h] [ebp-A9Ch]
  char v435; // [esp+298h] [ebp-A98h]
  char v436; // [esp+2A0h] [ebp-A90h]
  char v437; // [esp+2A8h] [ebp-A88h]
  HWND *v438; // [esp+2B0h] [ebp-A80h]
  int *v439; // [esp+2B4h] [ebp-A7Ch]
  HWND *v440; // [esp+2B8h] [ebp-A78h]
  HWND *v441; // [esp+2BCh] [ebp-A74h]
  HWND *v442; // [esp+2C0h] [ebp-A70h]
  int *v443; // [esp+2C4h] [ebp-A6Ch]
  int v444; // [esp+2C8h] [ebp-A68h]
  int v445; // [esp+2CCh] [ebp-A64h]
  HWND *v446; // [esp+2D0h] [ebp-A60h]
  int v447; // [esp+2D4h] [ebp-A5Ch]
  int v448; // [esp+2D8h] [ebp-A58h]
  int v449; // [esp+2DCh] [ebp-A54h]
  int v450; // [esp+2E0h] [ebp-A50h]
  char v451; // [esp+2E4h] [ebp-A4Ch]
  char v452; // [esp+2ECh] [ebp-A44h]
  char v453; // [esp+2F4h] [ebp-A3Ch]
  char v454; // [esp+2FCh] [ebp-A34h]
  char v455; // [esp+304h] [ebp-A2Ch]
  char v456; // [esp+30Ch] [ebp-A24h]
  char v457; // [esp+314h] [ebp-A1Ch]
  char v458; // [esp+31Ch] [ebp-A14h]
  char v459; // [esp+320h] [ebp-A10h]
  char v460; // [esp+324h] [ebp-A0Ch]
  char v461; // [esp+328h] [ebp-A08h]
  char v462; // [esp+32Ch] [ebp-A04h]
  char v463; // [esp+330h] [ebp-A00h]
  char v464; // [esp+334h] [ebp-9FCh]
  char v465; // [esp+33Ch] [ebp-9F4h]
  char v466; // [esp+344h] [ebp-9ECh]
  char v467; // [esp+34Bh] [ebp-9E5h]
  int v468; // [esp+34Ch] [ebp-9E4h]
  int v469; // [esp+350h] [ebp-9E0h]
  char v470; // [esp+356h] [ebp-9DAh]
  char v471; // [esp+357h] [ebp-9D9h]
  char v472; // [esp+358h] [ebp-9D8h]
  char v473; // [esp+359h] [ebp-9D7h]
  char v474; // [esp+370h] [ebp-9C0h]
  char v475; // [esp+371h] [ebp-9BFh]
  int v476; // [esp+372h] [ebp-9BEh]
  int v477; // [esp+376h] [ebp-9BAh]
  int v478; // [esp+37Ah] [ebp-9B6h]
  int v479; // [esp+380h] [ebp-9B0h]
  char v480; // [esp+384h] [ebp-9ACh]
  char v481; // [esp+385h] [ebp-9ABh]
  char v482; // [esp+38Ch] [ebp-9A4h]
  char v483; // [esp+38Dh] [ebp-9A3h]
  int v484; // [esp+38Eh] [ebp-9A2h]
  int v485; // [esp+392h] [ebp-99Eh]
  int v486; // [esp+396h] [ebp-99Ah]
  int v487; // [esp+39Ch] [ebp-994h]
  char v488; // [esp+3A0h] [ebp-990h]
  int v489; // [esp+3A1h] [ebp-98Fh]
  __int16 v490; // [esp+3A5h] [ebp-98Bh]
  int v491; // [esp+3A8h] [ebp-988h]
  int v492; // [esp+3ACh] [ebp-984h]
  BOOL v493; // [esp+3B0h] [ebp-980h]
  char v494; // [esp+3B4h] [ebp-97Ch]
  char v495; // [esp+3B5h] [ebp-97Bh]
  char *v496; // [esp+3C8h] [ebp-968h]
  int v497; // [esp+3CCh] [ebp-964h]
  char v498; // [esp+3D0h] [ebp-960h]
  char v499; // [esp+3F4h] [ebp-93Ch]
  char v500; // [esp+404h] [ebp-92Ch]
  __int16 v501; // [esp+40Ch] [ebp-924h]
  char v502; // [esp+40Eh] [ebp-922h]
  _DWORD *v503; // [esp+430h] [ebp-900h]
  char v504; // [esp+434h] [ebp-8FCh]
  char v505; // [esp+444h] [ebp-8ECh]
  int v506; // [esp+44Ch] [ebp-8E4h]
  char v507; // [esp+450h] [ebp-8E0h]
  _DWORD *v508; // [esp+474h] [ebp-8BCh]
  char v509; // [esp+478h] [ebp-8B8h]
  int v510; // [esp+488h] [ebp-8A8h]
  char v511; // [esp+48Ch] [ebp-8A4h]
  int v512; // [esp+49Ch] [ebp-894h]
  char v513; // [esp+4A0h] [ebp-890h]
  char v514; // [esp+4B0h] [ebp-880h]
  char v515; // [esp+4C0h] [ebp-870h]
  char v516; // [esp+4D0h] [ebp-860h]
  char v517; // [esp+4D1h] [ebp-85Fh]
  char v518; // [esp+4F4h] [ebp-83Ch]
  char v519; // [esp+4FCh] [ebp-834h]
  HWND *v520; // [esp+50Ch] [ebp-824h]
  int v521; // [esp+510h] [ebp-820h]
  int v522; // [esp+514h] [ebp-81Ch]
  char v523; // [esp+518h] [ebp-818h]
  int v524; // [esp+53Ch] [ebp-7F4h]
  int v525; // [esp+540h] [ebp-7F0h]
  char v526; // [esp+544h] [ebp-7ECh]
  int *v527; // [esp+550h] [ebp-7E0h]
  char v528; // [esp+557h] [ebp-7D9h]
  char v529; // [esp+558h] [ebp-7D8h]
  char v530; // [esp+559h] [ebp-7D7h]
  char *v531; // [esp+55Ch] [ebp-7D4h]
  int v532; // [esp+560h] [ebp-7D0h]
  int v533; // [esp+564h] [ebp-7CCh]
  char v534; // [esp+580h] [ebp-7B0h]
  _BYTE *v535; // [esp+590h] [ebp-7A0h]
  char v536; // [esp+594h] [ebp-79Ch]
  char v537; // [esp+595h] [ebp-79Bh]
  int v538; // [esp+5A5h] [ebp-78Bh]
  int v539; // [esp+5A9h] [ebp-787h]
  char *v540; // [esp+5B0h] [ebp-780h]
  int v541; // [esp+5B4h] [ebp-77Ch]
  char v542; // [esp+5B8h] [ebp-778h]
  void *v543; // [esp+5D4h] [ebp-75Ch]
  char v544; // [esp+5D8h] [ebp-758h]
  char v545; // [esp+5E0h] [ebp-750h]
  int v546; // [esp+5F0h] [ebp-740h]
  int v547; // [esp+5F4h] [ebp-73Ch]
  _DWORD *v548; // [esp+5F8h] [ebp-738h]
  char v549; // [esp+5FCh] [ebp-734h]
  char v550; // [esp+604h] [ebp-72Ch]
  int v551; // [esp+614h] [ebp-71Ch]
  int v552; // [esp+618h] [ebp-718h]
  _DWORD *v553; // [esp+61Ch] [ebp-714h]
  int v554; // [esp+620h] [ebp-710h]
  int v555; // [esp+624h] [ebp-70Ch]
  char v556; // [esp+640h] [ebp-6F0h]
  int v557; // [esp+641h] [ebp-6EFh]
  int v558; // [esp+645h] [ebp-6EBh]
  int v559; // [esp+649h] [ebp-6E7h]
  int v560; // [esp+64Dh] [ebp-6E3h]
  int v561; // [esp+651h] [ebp-6DFh]
  int v562; // [esp+655h] [ebp-6DBh]
  int v563; // [esp+659h] [ebp-6D7h]
  int v564; // [esp+65Dh] [ebp-6D3h]
  int v565; // [esp+664h] [ebp-6CCh]
  int v566; // [esp+668h] [ebp-6C8h]
  int v567; // [esp+66Ch] [ebp-6C4h]
  int v568; // [esp+670h] [ebp-6C0h]
  int v569; // [esp+674h] [ebp-6BCh]
  int v570; // [esp+678h] [ebp-6B8h]
  char v571; // [esp+67Ch] [ebp-6B4h]
  int v572; // [esp+680h] [ebp-6B0h]
  int v573; // [esp+684h] [ebp-6ACh]
  int v574; // [esp+688h] [ebp-6A8h]
  int v575; // [esp+68Ch] [ebp-6A4h]
  int v576; // [esp+694h] [ebp-69Ch]
  int v577; // [esp+698h] [ebp-698h]
  int v578; // [esp+69Ch] [ebp-694h]
  char v579; // [esp+6A0h] [ebp-690h]
  unsigned int v580; // [esp+6A4h] [ebp-68Ch]
  _DWORD *v581; // [esp+6A8h] [ebp-688h]
  char *v582; // [esp+6ACh] [ebp-684h]
  unsigned int l; // [esp+6B0h] [ebp-680h]
  char v584; // [esp+6B4h] [ebp-67Ch]
  int v585; // [esp+6C4h] [ebp-66Ch]
  char v586; // [esp+6C8h] [ebp-668h]
  int v587; // [esp+6D8h] [ebp-658h]
  _BYTE *v588; // [esp+6DCh] [ebp-654h]
  _BYTE *v589; // [esp+6E0h] [ebp-650h]
  int v590; // [esp+6E4h] [ebp-64Ch]
  int v591; // [esp+6E8h] [ebp-648h]
  char *v592; // [esp+6ECh] [ebp-644h]
  unsigned int ii; // [esp+6F0h] [ebp-640h]
  HWND v594; // [esp+6F4h] [ebp-63Ch]
  char v595; // [esp+6F8h] [ebp-638h]
  int v596; // [esp+708h] [ebp-628h]
  char v597; // [esp+70Ch] [ebp-624h]
  char v598; // [esp+710h] [ebp-620h]
  char v599; // [esp+714h] [ebp-61Ch]
  wchar_t v600; // [esp+724h] [ebp-60Ch]
  char v601; // [esp+726h] [ebp-60Ah]
  char v602; // [esp+928h] [ebp-408h]
  HWND *v603; // [esp+938h] [ebp-3F8h]
  char v604; // [esp+93Ch] [ebp-3F4h]
  char v605; // [esp+94Ch] [ebp-3E4h]
  int v606; // [esp+95Ch] [ebp-3D4h]
  int v607; // [esp+960h] [ebp-3D0h]
  int v608; // [esp+964h] [ebp-3CCh]
  unsigned int k; // [esp+968h] [ebp-3C8h]
  char v610; // [esp+96Ch] [ebp-3C4h]
  int v611; // [esp+970h] [ebp-3C0h]
  char v612; // [esp+974h] [ebp-3BCh]
  int v613; // [esp+984h] [ebp-3ACh]
  _BYTE *v614; // [esp+988h] [ebp-3A8h]
  _BYTE *v615; // [esp+98Ch] [ebp-3A4h]
  int *v616; // [esp+990h] [ebp-3A0h]
  int v617; // [esp+994h] [ebp-39Ch]
  HWND *v618; // [esp+998h] [ebp-398h]
  int v619; // [esp+99Ch] [ebp-394h]
  int v620; // [esp+9A0h] [ebp-390h]
  HWND *v621; // [esp+9A4h] [ebp-38Ch]
  int *v622; // [esp+9A8h] [ebp-388h]
  int *v623; // [esp+9ACh] [ebp-384h]
  HWND *v624; // [esp+9B0h] [ebp-380h]
  int v625; // [esp+9B4h] [ebp-37Ch]
  char *v626; // [esp+9B8h] [ebp-378h]
  char *v627; // [esp+9BCh] [ebp-374h]
  int v628; // [esp+9C0h] [ebp-370h]
  int v629; // [esp+9C4h] [ebp-36Ch]
  int v630; // [esp+9C8h] [ebp-368h]
  char v631; // [esp+9CCh] [ebp-364h]
  int j; // [esp+9D4h] [ebp-35Ch]
  char v633[4]; // [esp+9D8h] [ebp-358h]
  int v634; // [esp+9DCh] [ebp-354h]
  int v635; // [esp+9E0h] [ebp-350h]
  int v636; // [esp+9E4h] [ebp-34Ch]
  char v637; // [esp+9E8h] [ebp-348h]
  char v638; // [esp+9ECh] [ebp-344h]
  int v639; // [esp+9F4h] [ebp-33Ch]
  char v640; // [esp+9FBh] [ebp-335h]
  HWND *v641; // [esp+9FCh] [ebp-334h]
  int v642; // [esp+A00h] [ebp-330h]
  unsigned __int8 *v643; // [esp+A04h] [ebp-32Ch]
  _BYTE *v644; // [esp+A08h] [ebp-328h]
  _BYTE *v645; // [esp+A0Ch] [ebp-324h]
  _BYTE *v646; // [esp+A10h] [ebp-320h]
  _BYTE *v647; // [esp+A14h] [ebp-31Ch]
  _BYTE *v648; // [esp+A18h] [ebp-318h]
  _BYTE *v649; // [esp+A1Ch] [ebp-314h]
  _BYTE *v650; // [esp+A20h] [ebp-310h]
  char v651; // [esp+A24h] [ebp-30Ch]
  char v652; // [esp+A2Ch] [ebp-304h]
  int v653; // [esp+A2Dh] [ebp-303h]
  int v654; // [esp+A31h] [ebp-2FFh]
  int v655; // [esp+A35h] [ebp-2FBh]
  __int16 v656; // [esp+A39h] [ebp-2F7h]
  char v657; // [esp+A3Bh] [ebp-2F5h]
  _BYTE *v658; // [esp+A3Ch] [ebp-2F4h]
  char v659; // [esp+A40h] [ebp-2F0h]
  int v660; // [esp+A44h] [ebp-2ECh]
  unsigned int v661; // [esp+A48h] [ebp-2E8h]
  char v662; // [esp+A4Ch] [ebp-2E4h]
  int v663; // [esp+A50h] [ebp-2E0h]
  unsigned int v664; // [esp+A54h] [ebp-2DCh]
  char v665; // [esp+A58h] [ebp-2D8h]
  int v666; // [esp+A5Ch] [ebp-2D4h]
  unsigned int v667; // [esp+A60h] [ebp-2D0h]
  char v668; // [esp+A64h] [ebp-2CCh]
  int v669; // [esp+A68h] [ebp-2C8h]
  unsigned int v670; // [esp+A6Ch] [ebp-2C4h]
  char v671; // [esp+A70h] [ebp-2C0h]
  int v672; // [esp+A74h] [ebp-2BCh]
  unsigned int v673; // [esp+A78h] [ebp-2B8h]
  int v674; // [esp+A7Ch] [ebp-2B4h]
  HWND *v675; // [esp+A80h] [ebp-2B0h]
  int v676; // [esp+A84h] [ebp-2ACh]
  unsigned int n; // [esp+A88h] [ebp-2A8h]
  char v678; // [esp+A8Ch] [ebp-2A4h]
  char v679; // [esp+A9Ch] [ebp-294h]
  _DWORD *v680; // [esp+AACh] [ebp-284h]
  int v681; // [esp+AB0h] [ebp-280h]
  unsigned int m; // [esp+AB4h] [ebp-27Ch]
  char v683; // [esp+AB8h] [ebp-278h]
  char v684; // [esp+AC8h] [ebp-268h]
  int v685; // [esp+AD8h] [ebp-258h]
  int v686; // [esp+ADCh] [ebp-254h]
  char v687; // [esp+AE0h] [ebp-250h]
  _DWORD *v688; // [esp+AE8h] [ebp-248h]
  char v689; // [esp+AECh] [ebp-244h]
  int v690; // [esp+AEDh] [ebp-243h]
  HWND v691; // [esp+AF1h] [ebp-23Fh]
  char DstBuf; // [esp+AF7h] [ebp-239h]
  int *v693; // [esp+B08h] [ebp-228h]
  int v694; // [esp+B0Ch] [ebp-224h]
  int v695; // [esp+B10h] [ebp-220h]
  HWND v696; // [esp+B14h] [ebp-21Ch]
  char v697; // [esp+B18h] [ebp-218h]
  char v698; // [esp+B1Ch] [ebp-214h]
  int v699; // [esp+B24h] [ebp-20Ch]
  LPCWSTR lpWideCharStr; // [esp+B28h] [ebp-208h]
  char v701; // [esp+B2Ch] [ebp-204h]
  int v702; // [esp+B2Dh] [ebp-203h]
  int v703; // [esp+B31h] [ebp-1FFh]
  int v704; // [esp+B35h] [ebp-1FBh]
  __int16 v705; // [esp+B39h] [ebp-1F7h]
  char v706; // [esp+B3Bh] [ebp-1F5h]
  int v707; // [esp+B3Ch] [ebp-1F4h]
  int v708; // [esp+B40h] [ebp-1F0h]
  int v709; // [esp+B44h] [ebp-1ECh]
  char v710[4]; // [esp+B48h] [ebp-1E8h]
  int *v711; // [esp+B4Ch] [ebp-1E4h]
  int *v712; // [esp+B50h] [ebp-1E0h]
  char v713; // [esp+B54h] [ebp-1DCh]
  LPARAM lParam; // [esp+B58h] [ebp-1D8h]
  char v715; // [esp+B5Ch] [ebp-1D4h]
  char v716; // [esp+B60h] [ebp-1D0h]
  HWND *v717; // [esp+B64h] [ebp-1CCh]
  int v718; // [esp+B68h] [ebp-1C8h]
  char v719; // [esp+B6Fh] [ebp-1C1h]
  int v720; // [esp+B70h] [ebp-1C0h]
  char v721; // [esp+B74h] [ebp-1BCh]
  _BYTE *v722; // [esp+B7Ch] [ebp-1B4h]
  int v723; // [esp+B80h] [ebp-1B0h]
  int v724; // [esp+B84h] [ebp-1ACh]
  _BYTE *v725; // [esp+B88h] [ebp-1A8h]
  char v726; // [esp+B8Ch] [ebp-1A4h]
  int v727; // [esp+B94h] [ebp-19Ch]
  char v728; // [esp+B9Ah] [ebp-196h]
  const char *v729; // [esp+BACh] [ebp-184h]
  char v730; // [esp+BB0h] [ebp-180h]
  char v731; // [esp+BB7h] [ebp-179h]
  char v732; // [esp+BB8h] [ebp-178h]
  int v733; // [esp+BB9h] [ebp-177h]
  int v734; // [esp+BBDh] [ebp-173h]
  int v735; // [esp+BC1h] [ebp-16Fh]
  char *v736; // [esp+BC8h] [ebp-168h]
  int v737; // [esp+BCCh] [ebp-164h]
  int v738; // [esp+BD0h] [ebp-160h]
  bool v739; // [esp+BD7h] [ebp-159h]
  unsigned __int8 v740; // [esp+BD8h] [ebp-158h]
  char v741; // [esp+BD9h] [ebp-157h]
  char v742; // [esp+BE9h] [ebp-147h]
  char v743; // [esp+BEAh] [ebp-146h]
  int v744; // [esp+BEBh] [ebp-145h]
  int v745; // [esp+BEFh] [ebp-141h]
  int v746; // [esp+BF3h] [ebp-13Dh]
  int v747; // [esp+BF8h] [ebp-138h]
  int v748; // [esp+BFCh] [ebp-134h]
  int v749; // [esp+C00h] [ebp-130h]
  int v750; // [esp+C04h] [ebp-12Ch]
  int v751; // [esp+C08h] [ebp-128h]
  int i; // [esp+C0Ch] [ebp-124h]
  char v753; // [esp+C13h] [ebp-11Dh]
  _DWORD *v754; // [esp+C14h] [ebp-11Ch]
  int v755; // [esp+C18h] [ebp-118h]
  _BYTE *v756; // [esp+C1Ch] [ebp-114h]
  _BYTE *v757; // [esp+C20h] [ebp-110h]
  int v758; // [esp+C24h] [ebp-10Ch]
  int v759; // [esp+C28h] [ebp-108h]
  int v760; // [esp+C2Ch] [ebp-104h]
  int v761; // [esp+C30h] [ebp-100h]
  char v762; // [esp+C34h] [ebp-FCh]
  char v763; // [esp+C35h] [ebp-FBh]
  int v764; // [esp+C36h] [ebp-FAh]
  char *v765; // [esp+C3Ch] [ebp-F4h]
  char v766; // [esp+C40h] [ebp-F0h]
  char v767; // [esp+C50h] [ebp-E0h]
  int v768; // [esp+C51h] [ebp-DFh]
  int v769; // [esp+C55h] [ebp-DBh]
  int v770; // [esp+C59h] [ebp-D7h]
  __int16 v771; // [esp+C5Dh] [ebp-D3h]
  char v772; // [esp+C5Fh] [ebp-D1h]
  int v773; // [esp+C60h] [ebp-D0h]
  char *v774; // [esp+C64h] [ebp-CCh]
  char v775; // [esp+C68h] [ebp-C8h]
  char v776; // [esp+C78h] [ebp-B8h]
  char v777; // [esp+C79h] [ebp-B7h]
  int v778; // [esp+C7Ah] [ebp-B6h]
  int v779; // [esp+C80h] [ebp-B0h]
  char *v780; // [esp+C84h] [ebp-ACh]
  char v781; // [esp+C88h] [ebp-A8h]
  _BYTE *v782; // [esp+C98h] [ebp-98h]
  char *v783; // [esp+C9Ch] [ebp-94h]
  _BYTE *v784; // [esp+CA0h] [ebp-90h]
  _BYTE *v785; // [esp+CA4h] [ebp-8Ch]
  _BYTE *v786; // [esp+CA8h] [ebp-88h]
  _BYTE *v787; // [esp+CACh] [ebp-84h]
  _BYTE *v788; // [esp+CB0h] [ebp-80h]
  char *v789; // [esp+CB4h] [ebp-7Ch]
  char v790; // [esp+CB8h] [ebp-78h]
  char v791; // [esp+CC0h] [ebp-70h]
  char Dst; // [esp+CC1h] [ebp-6Fh]
  char v793; // [esp+CE4h] [ebp-4Ch]
  char v794; // [esp+CF4h] [ebp-3Ch]
  int v795; // [esp+CFCh] [ebp-34h]
  LPCWSTR lpString; // [esp+D00h] [ebp-30h]
  char v797; // [esp+D04h] [ebp-2Ch]
  bool v798; // [esp+D08h] [ebp-28h]
  int v799; // [esp+D09h] [ebp-27h]
  int v800; // [esp+D0Dh] [ebp-23h]
  int v801; // [esp+D11h] [ebp-1Fh]
  __int16 v802; // [esp+D15h] [ebp-1Bh]
  char v803; // [esp+D17h] [ebp-19h]
  int v804; // [esp+D1Ch] [ebp-14h]
  char v805; // [esp+D20h] [ebp-10h]
  int v806; // [esp+D2Ch] [ebp-4h]

  v399 = this;
  v798 = 0;
  v799 = 0;
  v800 = 0;
  v801 = 0;
  v802 = 0;
  v803 = 0;
  v795 = sub_4D8E720();
  LightLogger::CLogger::GetLogger(&v805, L"DataReq");
  v806 = 0;
  if ( *((_BYTE *)v399 + 494) )
  {
    v3 = (LightLogger::CLogger *)unknown_libname_96(&v805);
    LightLogger::CLogger::WriteLogLine(v3, L"ApplyData m_bStopRequest==true return.", 20000);
    PostMessageW(*(HWND *)((char *)v399 + 21), 0x467u, 0, 0);
    v806 = -1;
    sub_4E8C780(&v805);
    return;
  }
  if ( QDataEngine::m_bDataReInit )
  {
    v4 = (LightLogger::CLogger *)unknown_libname_96(&v805);
    LightLogger::CLogger::WriteLogLine(v4, L"ApplyData m_bDataReInit==true return.", 20000);
    PostMessageW(*(HWND *)((char *)v399 + 21), 0x467u, 0, 0);
    v806 = -1;
    sub_4E8C780(&v805);
    return;
  }
  if ( !QDataEngine::GetLoginInStatus()
    && *((_DWORD *)a2 + 2) != 1
    && *((_DWORD *)a2 + 2) != 42
    && *((_DWORD *)a2 + 2) != 21
    && *((_DWORD *)a2 + 2) != 90
    && *((_DWORD *)a2 + 2) != 125 )
  {
    mfc80xU_293(&v794);
    LOBYTE(v806) = 1;
    v310 = (HWND)*((_DWORD *)a2 + 2);
    v309 = QDataEngine::GetLoginInStatus();
    mfc80xU_2311(
      &v794,
      (const char *)L"ApplyData return! QDataEngine::GetLoginInStatus() = %d, req->iReqType=%d",
      v309,
      v310);
    v310 = (HWND)mfc80xU_870(&v794);
    v5 = (LightLogger::CLogger *)unknown_libname_96(&v805);
    LightLogger::CLogger::WriteLogLine(v5, (const wchar_t *)v310, v311);
    PostMessageW(*(HWND *)((char *)v399 + 21), 0x467u, 0, 0);
    LOBYTE(v806) = 0;
    mfc80xU_577(&v794);
    v806 = -1;
    sub_4E8C780(&v805);
    return;
  }
  v398 = (void *)CGlobalEnv::GetGlobalEnv(&v466);
  v397 = v398;
  LOBYTE(v806) = 2;
  v6 = unknown_libname_96(v398);
  v7 = unknown_libname_96((void *)(v6 + 148));
  v8 = sub_4DC89C0(v7);
  sub_4E8E5E0(v8);
  LOBYTE(v806) = 4;
  sub_4E8C780(&v466);
  v396 = *((_DWORD *)a2 + 2);
  if ( v396 <= 256 )
  {
    if ( v396 == 256 )
    {
      HIWORD(v170) = HIWORD(a2);
      v626 = (char *)*((_DWORD *)a2 + 3);
      v171 = v626;
      LOWORD(v170) = *(_WORD *)(v626 + 33);
      v310 = v170;
      LOBYTE(v171) = v626[16];
      v309 = (int)v171;
      v308 = (HWND)v626;
      v307 = *(_DWORD *)(v626 + 29);
      v306 = *(HWND *)(v626 + 25);
      v305 = *(HWND *)(v626 + 21);
      v304 = *(HWND *)(v626 + 17);
      v303 = *(HWND *)a2;
      v172 = (Request *)unknown_libname_96(&v797);
      Request::RequestReportMsgTip(
        v172,
        (int)v303,
        (int)v304,
        (int)v305,
        (int)v306,
        v307,
        (char *)v308,
        v309,
        (unsigned __int16)v310);
    }
    else
    {
      switch ( --v396 )
      {
        case 0:
          sub_4E75770(&v793);
          LOBYTE(v806) = 5;
          sub_4E75CA0(&v790);
          while ( 1 )
          {
            v14 = sub_4E58970(&v464);
            if ( !(unsigned __int8)sub_4DAB600(v14) )
              break;
            v791 = *(_BYTE *)sub_4E70840(&v790);
            if ( !*(_DWORD *)((char *)v399 + 1318)
              || (LOBYTE(v15) = v791, v310 = v15, v16 = *(_DWORD *)((char *)v399 + 1318), !sub_4FF4070(v791)) )
            {
              v17 = sub_4E70840(&v790);
              v18 = (const char *)sub_5096A60(*(_DWORD *)(v17 + 4));
              strcpy_s(&Dst, 0x21u, v18);
              sub_4E757C0(&v791);
            }
            sub_4E70860(&v465, 0);
          }
          v310 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestAppStkDict(&v793, v310);
          LOBYTE(v806) = 4;
          sub_4E757A0(&v793);
          goto LABEL_694;
        case 1:
          v750 = *((_DWORD *)a2 + 3);
          v751 = CDataMgr::ChangeCycleUIToNet(v399, *(unsigned __int8 *)(v750 + 17));
          if ( v751 >= 0 )
          {
            v310 = 0;
            v309 = *(_DWORD *)(v750 + 27);
            v308 = *(HWND *)(v750 + 23);
            v62 = v750;
            v63 = *(HWND *)(v750 + 19);
            v307 = *(_DWORD *)(v750 + 19);
            LOBYTE(v62) = *(_BYTE *)(v750 + 18);
            v306 = (HWND)v62;
            LOBYTE(v63) = v751;
            v305 = v63;
            v304 = (HWND)(v750 + 1);
            LOBYTE(v63) = *(_BYTE *)v750;
            v303 = v63;
            v302 = *(HWND *)a2;
            v64 = (Request *)unknown_libname_96(&v797);
            Request::RequestQuoteChartDayLineFromStatic(
              v64,
              (int)v302,
              (char)v303,
              (const char *const )v304,
              (char)v305,
              (char)v306,
              v307,
              (unsigned int)v308,
              v309,
              0);
          }
          goto LABEL_694;
        case 2:
          v760 = *((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v760 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v41 = alloca(2 * v804);
              v379 = (LPSTR)&v311;
              v380 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v380 = 0;
            }
            v381 = v380;
          }
          else
          {
            v381 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v381);
          if ( *((_DWORD *)a2 + 1) != 3 )
            CDataMgr::SendF1DetailL1ToUI(v399, *(HWND *)a2, (char *)&v798, *(_BYTE *)v760, *(_DWORD *)(v760 + 5));
          if ( !*(_DWORD *)(v760 + 10) )
          {
            v310 = *(HWND *)(v760 + 10);
            v42 = *(_DWORD *)(v760 + 5);
            v309 = *(_DWORD *)(v760 + 5);
            v308 = (HWND)&v798;
            LOBYTE(v42) = *(_BYTE *)v760;
            v307 = v42;
            v306 = *(HWND *)a2;
            v43 = (Request *)unknown_libname_96(&v797);
            Request::RequestDetailL1(v43, (int)v306, v307, (const char *const )&v798, v309, (int)v310);
          }
          if ( *(_BYTE *)(v760 + 9) == 1 )
          {
            CDataMgr::m_bIsF1DetailPush = 1;
          }
          else if ( *(_BYTE *)(v760 + 9) == 2 )
          {
            CDataMgr::m_bIsF1DetailPush = 0;
          }
          goto LABEL_694;
        case 3:
          v759 = *((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v759 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v44 = alloca(2 * v804);
              v376 = (LPSTR)&v311;
              v377 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v377 = 0;
            }
            v378 = v377;
          }
          else
          {
            v378 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v378);
          v310 = (HWND)1;
          v309 = *(_DWORD *)(v759 + 14);
          v45 = v759;
          v308 = *(HWND *)(v759 + 10);
          LOBYTE(v45) = *(_BYTE *)(v759 + 9);
          v307 = v45;
          v306 = (HWND)mfc80xU_870(v759 + 1);
          LOBYTE(v46) = *(_BYTE *)v759;
          v305 = v46;
          v304 = *(HWND *)a2;
          v47 = (Request *)unknown_libname_96(&v797);
          Request::RequestDetailL2(v47, (int)v304, (char)v305, (LPCWSTR)v306, v307, (int)v308, v309, 1);
          goto LABEL_694;
        case 4:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v780 = (char *)*((_DWORD *)a2 + 3);
          if ( !v780 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          lpString = (LPCWSTR)mfc80xU_870(v780 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v36 = alloca(2 * v804);
              v390 = (LPSTR)&v311;
              v391 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v391 = 0;
            }
            v392 = v391;
          }
          else
          {
            v392 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v392);
          if ( (unsigned __int8)sub_4DB2170(*v780) )
          {
            v777 = 1;
            v776 = 5;
            v778 = sub_50EF6C0((char *)&v798, *v780);
            v310 = 0;
            v309 = 0;
            v308 = (HWND)1;
            v307 = (int)"REQID_QUOTE_PUSH_OPTION_QUOTE";
            v306 = (HWND)725;
            v305 = (HWND)&v776;
            v304 = *(HWND *)a2;
            unknown_libname_96(&v797);
            sub_4ECA0E0(0, (int)v304, &v776, 725, "REQID_QUOTE_PUSH_OPTION_QUOTE", 1, 0, 0);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7550(&v781);
          LOBYTE(v806) = 6;
          v779 = sub_50EF6C0((char *)&v798, *v780);
          if ( v779 == -1 )
          {
            LOBYTE(v806) = 4;
            sub_4DE6AF0(&v781);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7580(&v779);
          v310 = 0;
          v309 = *(_DWORD *)a2;
          unknown_libname_96(&v797);
          Request::RequestPushStockRecord(&v781, 5, 737, v309, 0);
          LOBYTE(v806) = 4;
          sub_4DE6AF0(&v781);
          goto LABEL_694;
        case 5:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v765 = (char *)*((_DWORD *)a2 + 3);
          if ( !mfc80xU_1476(v765 + 1, &unk_515404C) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v767 = 0;
          v768 = 0;
          v769 = 0;
          v770 = 0;
          v771 = 0;
          v772 = 0;
          lpString = (LPCWSTR)mfc80xU_870(v765 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v38 = alloca(2 * v804);
              v384 = (LPSTR)&v311;
              v385 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v385 = 0;
            }
            v386 = v385;
          }
          else
          {
            v386 = 0;
          }
          strcpy_s(&v767, 0x10u, v386);
          if ( (unsigned __int8)sub_4DB2170(*v765) )
          {
            v763 = 1;
            v762 = 5;
            v764 = sub_50EF6C0(&v767, *v765);
            v310 = 0;
            v309 = 0;
            v308 = (HWND)1;
            v307 = (int)"REQID_QUOTE_PUSH_OPTION_QUOTE";
            v306 = (HWND)725;
            v305 = (HWND)&v762;
            v304 = *(HWND *)a2;
            unknown_libname_96(&v797);
            sub_4ECA0E0(0, (int)v304, &v762, 725, "REQID_QUOTE_PUSH_OPTION_QUOTE", 1, 0, 0);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7550(&v766);
          LOBYTE(v806) = 8;
          if ( *v765 != 3 && *v765 != 1 && *v765 && *v765 != 90 )
          {
            v383 = mfc80xU_287(&v463, &v767);
            v382 = v383;
            LOBYTE(v806) = 9;
            v310 = (HWND)1;
            v309 = 11;
            v308 = (HWND)mfc80xU_870(v383);
            LOBYTE(v39) = *v765;
            v307 = v39;
            v306 = *(HWND *)a2;
            v40 = (Request *)unknown_libname_96(&v797);
            Request::RequestQuoteRecord(v40, (int)v306, v307, (LPCWSTR)v308, 11, 1);
            LOBYTE(v806) = 8;
            mfc80xU_577(&v463);
          }
          else
          {
            v761 = sub_50EF6C0(&v767, *v765);
            if ( v761 == -1 )
            {
              LOBYTE(v806) = 4;
              sub_4DE6AF0(&v766);
              LOBYTE(v806) = 0;
              sub_4E8C780(&v797);
              v806 = -1;
              sub_4E8C780(&v805);
              return;
            }
            sub_4DD7580(&v761);
            v310 = (HWND)819;
            v309 = 5;
            v308 = (HWND)&v766;
            v307 = *(_DWORD *)a2;
            v306 = (HWND)*((_DWORD *)v399 + 203);
            unknown_libname_96(&v797);
            Request::RequestStkL2MultiQuote(v306, v307, &v766, 5, 819);
          }
          LOBYTE(v806) = 4;
          sub_4DE6AF0(&v766);
          goto LABEL_694;
        case 6:
          v782 = (_BYTE *)*((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v782 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v33 = alloca(2 * v804);
              lpMultiByteStr = (LPSTR)&v311;
              v394 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v394 = 0;
            }
            Src = v394;
          }
          else
          {
            Src = 0;
          }
          strcpy_s((char *)&v798, 0x10u, Src);
          CDataMgr::SendOrderListToUI(v399, *(HWND *)a2);
          v310 = (HWND)1;
          v309 = (int)&v798;
          LOBYTE(v34) = *v782;
          v308 = v34;
          v307 = *(_DWORD *)a2;
          v35 = (Request *)unknown_libname_96(&v797);
          Request::RequestStockOrderQueue(v35, v307, (char)v308, (const char *)&v798, 1);
          *((_BYTE *)v399 + 706) = 1;
          *(_DWORD *)((char *)v399 + 702) = *(_DWORD *)a2;
          goto LABEL_694;
        case 7:
          v58 = a2;
          v755 = *((_DWORD *)a2 + 3);
          LOBYTE(v58) = *(_BYTE *)(v755 + 4);
          v310 = (HWND)v58;
          v309 = *(_DWORD *)a2;
          v59 = (Request *)unknown_libname_96(&v797);
          Request::RequestQuoteRank(v59, v309, (char)v310);
          goto LABEL_694;
        case 8:
          v753 = 0;
          v754 = (_DWORD *)*((_DWORD *)a2 + 3);
          for ( i = 0; ; ++i )
          {
            v60 = i;
            if ( i >= *v754 )
              break;
            if ( v754[i + 6] == 1 )
              v753 = 1;
          }
          v310 = (HWND)2;
          LOBYTE(v60) = v753;
          v309 = v60;
          v308 = *(HWND *)a2;
          v61 = (Request *)unknown_libname_96(&v797);
          Request::RequestQuoteRankUpDown(v61, (int)v308, v309, 2);
          goto LABEL_694;
        case 9:
          v725 = (_BYTE *)*((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v725 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v71 = alloca(2 * v804);
              v352 = (LPSTR)&v311;
              v353 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v353 = 0;
            }
            v354 = v353;
          }
          else
          {
            v354 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v354);
          v351 = mfc80xU_287(&v458, &v798);
          v350 = v351;
          LOBYTE(v806) = 14;
          v309 = mfc80xU_870(v351);
          LOBYTE(v72) = *v725;
          v308 = v72;
          v307 = *(_DWORD *)a2;
          v73 = (Request *)unknown_libname_96(&v797);
          Request::RequestL2RatioPrice(v73, v307, (char)v308, (LPCWSTR)v309, (bool)v310);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v458);
          goto LABEL_694;
        case 11:
          v310 = *(HWND *)a2;
          v74 = (Request *)unknown_libname_96(&v797);
          Request::RequestCancelOrderRank(v74, (int)v310);
          if ( CDataMgr::m_bHasCancelOrderData )
            CDataMgr::SendCancelOrderDataToUI(v399, *(_DWORD *)a2);
          goto LABEL_694;
        case 12:
          v310 = *(HWND *)a2;
          v75 = (Request *)unknown_libname_96(&v797);
          Request::RequestQuoteIndex(v75, (int)v310);
          CDataMgr::SendIndexSpToUI(v399, *(_DWORD *)a2);
          goto LABEL_694;
        case 13:
          v722 = (_BYTE *)*((_DWORD *)a2 + 3);
          sub_4E26520(&v723);
          EnterCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 266));
          v310 = (HWND)a2;
          v76 = (HWND *)sub_4DCC7B0((CDataMgr *)((char *)v399 + 665), (int)&v457);
          v309 = (int)v76[1];
          v308 = *v76;
          v77 = (_DWORD *)sub_4EA0EF0(&v456);
          v78 = (int *)sub_4DC2CA0(&v455, *v77, v77[1], (char)v308, v309, a2);
          v79 = v78[1];
          v723 = *v78;
          v724 = v79;
          v80 = sub_4DCC7B0((CDataMgr *)((char *)v399 + 665), (int)&v454);
          if ( (unsigned __int8)sub_4DAB600(v80) )
          {
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 266));
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7580(a2);
          v310 = (HWND)808;
          v309 = 1;
          v308 = (HWND)mfc80xU_870(v722 + 1);
          LOBYTE(v81) = *v722;
          v307 = v81;
          v82 = (Request *)unknown_libname_96(&v797);
          Request::RequestT0AndMoneyFlow(v82, 0, v307, (LPCWSTR)v308, 1, 808);
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 266));
          goto LABEL_694;
        case 14:
          v717 = (HWND *)*((_DWORD *)a2 + 3);
          v720 = 0;
          v718 = 0;
          QDataEngine::GetLastDataSerialIdAndTime(&v720, &v718);
          v717[1] = 0;
          v719 = 0;
          EnterCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 290));
          v310 = (HWND)a2;
          v83 = (HWND *)sub_4DCC7B0((_DWORD *)v399 + 181, (int)&v453);
          v309 = (int)v83[1];
          v308 = *v83;
          v84 = (_DWORD *)sub_4EA0EF0(&v452);
          sub_4DC2CA0(&v721, *v84, v84[1], (char)v308, v309, a2);
          v85 = sub_4DCC7B0((_DWORD *)v399 + 181, (int)&v451);
          if ( (unsigned __int8)sub_4DACFF0(v85) )
          {
            sub_4DD7580(a2);
            v719 = 1;
            CGlobalEnv::GetGlobalEnv(&v713);
            LOBYTE(v806) = 15;
            v449 = mfc80xU_762(28);
            if ( v449 )
              v349 = sub_4DECDE0(v449);
            else
              v349 = 0;
            v450 = v349;
            sub_4E8E5E0(v349);
            LOBYTE(v806) = 16;
            v447 = mfc80xU_762(16);
            if ( v447 )
              v348 = sub_4E76340(v447);
            else
              v348 = 0;
            v448 = v348;
            sub_4E8E5E0(v348);
            LOBYTE(v806) = 17;
            v86 = unknown_libname_96(&v716);
            *(_DWORD *)unknown_libname_89(v86) = 15;
            v87 = unknown_libname_96(&v716);
            *(_DWORD *)(unknown_libname_89(v87) + 4) = 0;
            v88 = unknown_libname_96(&v715);
            *(_BYTE *)unknown_libname_89(v88) = 0;
            v89 = unknown_libname_96(&v716);
            unknown_libname_89(v89);
            sub_4DF7300(&v715);
            v347 = unknown_libname_96(&v713);
            v90 = unknown_libname_96(&v716);
            lParam = (*(int (__thiscall **)(int, int))(*(_DWORD *)v347 + 36))(v347, v90);
            CDataMgr::SendMsgDataToUI(v399, *(HWND *)a2, lParam, 15);
            LOBYTE(v806) = 16;
            sub_4E8C780(&v715);
            LOBYTE(v806) = 15;
            sub_4E8C780(&v716);
            LOBYTE(v806) = 4;
            sub_4E8C780(&v713);
          }
          if ( sub_4DD2EA0((char *)v399 + 724) == 1 && v719 )
          {
            *v717 = (HWND)1;
            v310 = 0;
            v309 = 1;
            v308 = v717[1];
            v307 = v718;
            v306 = *v717;
            v305 = (HWND)v720;
            v91 = (Request *)unknown_libname_96(&v797);
            Request::RequestShortDecisionData(v91, 0, 0, (int)v305, (unsigned int)v306, v307, (int)v308, 1, 0);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 290));
          goto LABEL_694;
        case 15:
          v92 = a2;
          v712 = (int *)*((_DWORD *)a2 + 3);
          v310 = (HWND)356;
          LOBYTE(v92) = *(_BYTE *)v712;
          v309 = (int)v92;
          v308 = *(HWND *)a2;
          v93 = (Request *)unknown_libname_96(&v797);
          Request::RequestContribution(v93, (int)v308, v309, 356);
          CDataMgr::SendContriDataToUI(v399, *(HWND *)a2, *((_DWORD *)a2 + 2), *v712, 16);
          goto LABEL_694;
        case 16:
          v94 = a2;
          v711 = (int *)*((_DWORD *)a2 + 3);
          v310 = (HWND)357;
          LOBYTE(v94) = *(_BYTE *)v711;
          v309 = (int)v94;
          v308 = *(HWND *)a2;
          v95 = (Request *)unknown_libname_96(&v797);
          Request::RequestContribution(v95, (int)v308, v309, 357);
          CDataMgr::SendContriDataToUI(v399, *(HWND *)a2, *((_DWORD *)a2 + 2), *v711, 17);
          goto LABEL_694;
        case 18:
          *(_DWORD *)v710 = *((_DWORD *)a2 + 3);
          v708 = 0;
          v709 = 0;
          v310 = (HWND)&v709;
          v309 = (int)&v708;
          v308 = *(HWND *)(*(_DWORD *)v710 + 5);
          v307 = (char)**(_BYTE **)v710;
          v306 = *(HWND *)v710;
          v446 = &v306;
          v346 = mfc80xU_280(&v306, *(_DWORD *)v710 + 1);
          CDataMgr::SendF10InfoToUI(*(HWND *)a2, (char)v306, v307, (int)v308, v309, (int)v310);
          v310 = 0;
          v309 = (char)**(_BYTE **)v710;
          v96 = QDataEngine::GetCurDateByMarket(v309, 0);
          if ( v708 < v96 || (v310 = 0, v309 = (char)**(_BYTE **)v710, !QDataEngine::GetCurDateByMarket(v309, 0)) )
          {
            v701 = 0;
            v702 = 0;
            v703 = 0;
            v704 = 0;
            v705 = 0;
            v706 = 0;
            v699 = sub_4D8E720();
            lpWideCharStr = (LPCWSTR)mfc80xU_870(*(_DWORD *)v710 + 1);
            if ( lpWideCharStr )
            {
              v707 = lstrlenW(lpWideCharStr) + 1;
              if ( v707 <= 0x3FFFFFFF )
              {
                v97 = alloca(2 * v707);
                v343 = (LPSTR)&v311;
                v344 = (char *)sub_4D98AA0((LPSTR)&v311, lpWideCharStr, 2 * v707, 0);
              }
              else
              {
                v344 = 0;
              }
              v345 = v344;
            }
            else
            {
              v345 = 0;
            }
            strcpy_s(&v701, 0x10u, v345);
            v98 = v709;
            v310 = (HWND)v709;
            v309 = v708;
            LOBYTE(v98) = *(_BYTE *)(*(_DWORD *)v710 + 5);
            v308 = (HWND)v98;
            v307 = (int)&v701;
            LOBYTE(v98) = **(_BYTE **)v710;
            v306 = (HWND)v98;
            v305 = *(HWND *)a2;
            v99 = (Request *)unknown_libname_96(&v797);
            Request::RequestF10FromStatic(
              v99,
              (int)v305,
              (char)v306,
              (const char *const )v307,
              (char)v308,
              v309,
              (int)v310);
          }
          goto LABEL_694;
        case 20:
          v696 = (HWND)*((_DWORD *)a2 + 3);
          v444 = mfc80xU_762(32);
          if ( v444 )
            v342 = sub_4E6F9A0(v444);
          else
            v342 = 0;
          v445 = v342;
          sub_4E8E5E0(v342);
          LOBYTE(v806) = 18;
          v310 = v696;
          v100 = unknown_libname_96(&v697);
          v101 = unknown_libname_89(v100);
          mfc80xU_774(v101, v310);
          v309 = (int)(v696 + 1);
          v102 = unknown_libname_96(&v697);
          v103 = unknown_libname_89(v102);
          mfc80xU_774(v103 + 4, v309);
          v104 = unknown_libname_96(&v697);
          sub_4E8E5E0(v104);
          LOBYTE(v806) = 19;
          v309 = (int)v696 + 13;
          v443 = &v309;
          v341 = mfc80xU_280(&v309, (char *)v696 + 13);
          v340 = v341;
          LOBYTE(v806) = 20;
          LOBYTE(v105) = *((_BYTE *)v696 + 17);
          v307 = v105;
          v306 = v696;
          v442 = &v306;
          v339 = (HWND)sub_4DA6D00(&v698);
          v338 = v339;
          LOBYTE(v806) = 21;
          v305 = v339;
          v441 = &v305;
          v337 = mfc80xU_283(&v305, &unk_515422C);
          v336 = v337;
          LOBYTE(v806) = 22;
          v303 = (HWND)24;
          v302 = v106;
          v440 = &v302;
          v335 = mfc80xU_283(&v302, &unk_5154230);
          v334 = v335;
          LOBYTE(v806) = 23;
          v300 = (int)(v696 + 1);
          v439 = &v300;
          v333 = mfc80xU_280(&v300, v696 + 1);
          v332 = v333;
          LOBYTE(v806) = 24;
          v300 = *((unsigned __int8 *)v696 + 8);
          v299 = *(HWND *)((char *)v696 + 9);
          v298 = v299;
          v438 = &v298;
          v331 = mfc80xU_280(&v298, v696);
          v300 = 0;
          v299 = *(HWND *)a2;
          unknown_libname_96(&v797);
          LOBYTE(v806) = 19;
          Request::RequestDataFromWeb(
            v299,
            v300,
            v301,
            v302,
            v303,
            (char)v304,
            (char)v305,
            v306,
            v307,
            (char)v308,
            v309,
            (char)v310);
          LOBYTE(v806) = 18;
          sub_4E8C780(&v698);
          LOBYTE(v806) = 4;
          sub_4E8C780(&v697);
          goto LABEL_694;
        case 22:
          v675 = (HWND *)*((_DWORD *)a2 + 3);
          v310 = v675[2];
          v309 = (int)v675[1];
          v308 = *v675;
          v307 = *(_DWORD *)a2;
          v121 = (Request *)unknown_libname_96(&v797);
          Request::RequestSearchStk(v121, v307, (char *)v308, v309, (int)v310);
          goto LABEL_694;
        case 23:
          v674 = *((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v674 + 10);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v122 = alloca(2 * v804);
              v327 = (LPSTR)&v311;
              v328 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v328 = 0;
            }
            v329 = v328;
          }
          else
          {
            v329 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v329);
          if ( *((_DWORD *)a2 + 1) != 3 )
            CDataMgr::SendWeiTuoL2ToUI(v399, *(HWND *)a2, (char *)&v798, *(_BYTE *)(v674 + 9), *(_DWORD *)(v674 + 14));ËÆºõÎÞÓÃ20171231
          v326 = mfc80xU_287(&v433, &v798);
          v325 = v326;
          LOBYTE(v806) = 29;
          v309 = mfc80xU_870(v326);
          LOBYTE(v123) = *(_BYTE *)(v674 + 9);
          v308 = v123;
          v307 = *(_DWORD *)(v674 + 5);
          v124 = v674;
          v306 = *(HWND *)(v674 + 1);
          LOBYTE(v124) = *(_BYTE *)v674;
          v305 = (HWND)v124;
          v304 = *(HWND *)a2;
          v125 = (Request *)unknown_libname_96(&v797);
          Request::RequestZubiWeituo(
            v125,
            (int)v304,
            (char)v305,
            (int)v306,
            v307,
            (char)v308,
            (LPCWSTR)v309,
            (bool)v310);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v433);
          goto LABEL_694;
        case 24:
          v641 = (HWND *)*((_DWORD *)a2 + 3);
          v310 = *v641;
          v309 = *(_DWORD *)a2;
          v158 = (Request *)unknown_libname_96(&v797);
          Request::RequestHqCMLD(v158, v309, (int)v310);
          goto LABEL_694;
        case 25:
          v639 = *((_DWORD *)a2 + 3);
          if ( !v639 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          if ( unknown_libname_93(v639) < 1 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v640 = 0;
          if ( IsWindow(*(HWND *)a2) )
          {
            for ( j = 0; ; ++j )
            {
              v159 = unknown_libname_93(v639);
              if ( j >= v159 )
                break;
              v160 = sub_4D88D60(j);
              *(_DWORD *)v633 = *(_DWORD *)v160;
              v634 = *(_DWORD *)(v160 + 4);
              v635 = *(_DWORD *)(v160 + 8);
              v636 = *(_DWORD *)(v160 + 12);
              v637 = *(_BYTE *)(v160 + 16);
              v630 = sub_50EF6C0(&v633[1], v633[0]);
              v310 = (HWND)&v630;
              v161 = (HWND *)sub_4DCC7B0((CDataMgr *)((char *)v399 + 553), (int)&v429);
              v309 = (int)v161[1];
              v308 = *v161;
              v162 = (_DWORD *)sub_4EA0EF0(&v428);
              sub_4DC2CA0(&v631, *v162, v162[1], (char)v308, v309, &v630);
              v163 = sub_4DCC7B0((CDataMgr *)((char *)v399 + 553), (int)&v427);
              if ( (unsigned __int8)sub_4DACFF0(v163) )
              {
                v426 = v630;
                sub_4DD7580(&v426);
                v640 = 1;
              }
            }
          }
          v310 = (HWND)a2;
          v164 = (HWND *)sub_4DCC7B0((_DWORD *)v399 + 177, (int)&v425);
          v309 = (int)v164[1];
          v308 = *v164;
          v165 = (_DWORD *)sub_4EA0EF0(&v424);
          sub_4DC2CA0(&v638, *v165, v165[1], (char)v308, v309, a2);
          v166 = sub_4DCC7B0((_DWORD *)v399 + 177, (int)&v423);
          if ( (unsigned __int8)sub_4DACFF0(v166) )
          {
            sub_4DD7580(a2);
            CDataMgr::SendMsgToUI(v399, *(HWND *)a2, 0x1Au);
          }
          if ( v640 )
          {
            unknown_libname_96(&v797);
            Request::RequestPushMainIndex(0, (char *)v399 + 553, 1);
          }
          goto LABEL_694;
        case 29:
          v627 = (char *)*((_DWORD *)a2 + 3);
          v310 = *(HWND *)(v627 + 23);
          HIWORD(v167) = HIWORD(v627);
          v309 = *(_DWORD *)(v627 + 19);
          v168 = v627;
          LOWORD(v167) = *(_WORD *)(v627 + 17);
          v308 = v167;
          LOBYTE(v168) = v627[16];
          v307 = (int)v168;
          v306 = (HWND)v627;
          v305 = *(HWND *)a2;
          v169 = (Request *)unknown_libname_96(&v797);
          Request::RequestPageMinesData(
            v169,
            (int)v305,
            (const char *)v306,
            v307,
            (unsigned __int16)v308,
            v309,
            (int)v310);
          goto LABEL_694;
        case 31:
        case 32:
        case 33:
        case 34:
        case 70:
        case 93:
        case 95:
        case 101:
        case 105:
        case 106:
        case 107:
        case 108:
        case 134:
          goto LABEL_369;
        case 35:
          v758 = *((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v758 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v48 = alloca(2 * v804);
              v373 = (LPSTR)&v311;
              v374 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v374 = 0;
            }
            v375 = v374;
          }
          else
          {
            v375 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v375);
          v372 = mfc80xU_287(&v462, &v798);
          v371 = v372;
          LOBYTE(v806) = 10;
          v310 = *(HWND *)(v758 + 14);
          v49 = v758;
          v309 = *(_DWORD *)(v758 + 10);
          LOBYTE(v49) = *(_BYTE *)(v758 + 9);
          v308 = (HWND)v49;
          v307 = mfc80xU_870(v372);
          LOBYTE(v50) = *(_BYTE *)v758;
          v306 = v50;
          v305 = *(HWND *)a2;
          v51 = (Request *)unknown_libname_96(&v797);
          Request::RequestGZQHPankou(v51, (int)v305, (char)v306, (LPCWSTR)v307, (bool)v308, v309, (int)v310);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v462);
          goto LABEL_694;
        case 36:
          v774 = (char *)*((_DWORD *)a2 + 3);
          sub_4DD7550(&v775);
          LOBYTE(v806) = 7;
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 4;
            sub_4DE6AF0(&v775);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          if ( (unsigned __int8)mfc80xU_3927(v774 + 1) )
          {
            LOBYTE(v806) = 4;
            sub_4DE6AF0(&v775);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          lpString = (LPCWSTR)mfc80xU_870(v774 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v37 = alloca(2 * v804);
              v387 = (LPSTR)&v311;
              v388 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v388 = 0;
            }
            v389 = v388;
          }
          else
          {
            v389 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v389);
          v773 = sub_50EF6C0((char *)&v798, *v774);
          if ( v773 == -1 )
          {
            LOBYTE(v806) = 4;
            sub_4DE6AF0(&v775);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7580(&v773);
          v310 = 0;
          v309 = *(_DWORD *)a2;
          unknown_libname_96(&v797);
          Request::RequestPushStockRecord(&v775, 5, 812, v309, 0);
          LOBYTE(v806) = 4;
          sub_4DE6AF0(&v775);
          goto LABEL_694;
        case 37:
          v756 = (_BYTE *)*((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v756 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v55 = alloca(2 * v804);
              v363 = (LPSTR)&v311;
              v364 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v364 = 0;
            }
            v365 = v364;
          }
          else
          {
            v365 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v365);
          v362 = mfc80xU_287(&v460, &v798);
          v361 = v362;
          LOBYTE(v806) = 12;
          v309 = mfc80xU_870(v362);
          LOBYTE(v56) = *v756;
          v308 = v56;
          v307 = *(_DWORD *)a2;
          v57 = (Request *)unknown_libname_96(&v797);
          Request::RequestGZQHFenBi(v57, v307, (char)v308, (LPCWSTR)v309, (bool)v310);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v460);
          goto LABEL_694;
        case 38:
          v757 = (_BYTE *)*((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v757 + 1);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v52 = alloca(2 * v804);
              v368 = (LPSTR)&v311;
              v369 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v369 = 0;
            }
            v370 = v369;
          }
          else
          {
            v370 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v370);
          v367 = mfc80xU_287(&v461, &v798);
          v366 = v367;
          LOBYTE(v806) = 11;
          v310 = (HWND)mfc80xU_870(v367);
          LOBYTE(v53) = *v757;
          v309 = v53;
          v308 = *(HWND *)a2;
          v54 = (Request *)unknown_libname_96(&v797);
          Request::RequestGZQHFenJia(v54, (int)v308, v309, (const wchar_t *)v310);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v461);
          goto LABEL_694;
        case 39:
          v738 = *((_DWORD *)a2 + 3);
          lpString = (LPCWSTR)mfc80xU_870(v738 + 4);
          if ( lpString )
          {
            v804 = lstrlenW(lpString) + 1;
            if ( v804 <= 0x3FFFFFFF )
            {
              v68 = alloca(2 * v804);
              v357 = (LPSTR)&v311;
              v358 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
            }
            else
            {
              v358 = 0;
            }
            v359 = v358;
          }
          else
          {
            v359 = 0;
          }
          strcpy_s((char *)&v798, 0x10u, v359);
          v739 = CDataMgr::SendHisTrendDataToUI(
                   v399,
                   *(HWND *)a2,
                   (char *)&v798,
                   *(_BYTE *)v738,
                   *(_DWORD *)(v738 + 12));
          if ( v739 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v356 = mfc80xU_287(&v459, &v798);
          v355 = v356;
          LOBYTE(v806) = 13;
          v310 = (HWND)143;
          v309 = *(_DWORD *)(v738 + 8);
          v308 = *(HWND *)(v738 + 16);
          v307 = *(_DWORD *)(v738 + 12);
          v306 = (HWND)mfc80xU_870(v356);
          LOBYTE(v69) = *(_BYTE *)v738;
          v305 = v69;
          v304 = *(HWND *)a2;
          v70 = (Request *)unknown_libname_96(&v797);
          Request::RequestQuoteChartHisRtLine(v70, (int)v304, (char)v305, (LPCWSTR)v306, v307, (int)v308, v309, 143);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v459);
          goto LABEL_694;
        case 40:
          v748 = *((_DWORD *)a2 + 3);
          v749 = CDataMgr::ChangeCycleUIToNet(v399, *(unsigned __int8 *)(v748 + 17));
          if ( v749 >= 0 )
          {
            v747 = 1;
            v360 = v749 - 8;
            switch ( v749 )
            {
              case 8:
                v747 = 5;
                v749 = 7;
                break;
              case 9:
                v747 = 22;
                v749 = 7;
                break;
              case 10:
                v747 = 66;
                v749 = 7;
                break;
              case 11:
                v747 = 132;
                v749 = 7;
                break;
              case 12:
                v747 = 264;
                v749 = 7;
                break;
              default:
                break;
            }
            *(_DWORD *)(v748 + 27) *= v747;
            if ( CDataMgr::IsGssMarket(v399, *(_BYTE *)v748) )
            {
              v746 = *(_DWORD *)(v748 + 27);
              v744 = *(_DWORD *)(v748 + 19);
              v745 = *(_DWORD *)(v748 + 23);
              v743 = *(_BYTE *)(v748 + 18);
              v742 = v749;
              v740 = *(_BYTE *)v748;
              strcpy_s(&v741, 0x10u, (const char *)(v748 + 1));
              if ( v749 == 7 )
              {
                v310 = 0;
                v309 = 0;
                v308 = 0;
                v307 = (int)"REQID_HIS_DAYKLINE_GLOBAL";
                v306 = (HWND)1020;
                v305 = (HWND)&v740;
                v304 = *(HWND *)a2;
                unknown_libname_96(&v797);
                sub_4E83A50(1, (int)v304, &v740, 1020, "REQID_HIS_DAYKLINE_GLOBAL", 0, 0, 0);
              }
              else
              {
                v310 = 0;
                v309 = 0;
                v308 = 0;
                v307 = (int)"REQID_HIS_MINKLINE_GLOBAL";
                v306 = (HWND)1021;
                v305 = (HWND)&v740;
                v304 = *(HWND *)a2;
                unknown_libname_96(&v797);
                sub_4E83A50(1, (int)v304, &v740, 1021, "REQID_HIS_MINKLINE_GLOBAL", 0, 0, 0);
              }
            }
            else
            {
              v310 = (HWND)1;
              v309 = *(_DWORD *)(v748 + 27);
              v308 = *(HWND *)(v748 + 23);
              v65 = v748;
              v66 = *(HWND *)(v748 + 19);
              v307 = *(_DWORD *)(v748 + 19);
              LOBYTE(v65) = *(_BYTE *)(v748 + 18);
              v306 = (HWND)v65;
              LOBYTE(v66) = v749;
              v305 = v66;
              v304 = (HWND)(v748 + 1);
              LOBYTE(v66) = *(_BYTE *)v748;
              v303 = v66;
              v302 = *(HWND *)a2;
              v67 = (Request *)unknown_libname_96(&v797);
              Request::RequestQuoteChartDayLineFromStatic(
                v67,
                (int)v302,
                (char)v303,
                (const char *const )v304,
                (char)v305,
                (char)v306,
                v307,
                (unsigned int)v308,
                v309,
                1);
            }
          }
          goto LABEL_694;
        case 42:
          v619 = *((_DWORD *)a2 + 3);
          v620 = 3;
          v190 = *(HWND *)(v619 + 16);
          v310 = *(HWND *)(v619 + 16);
          v309 = (int)"News_Info_Querier_ForFree";
          v308 = (HWND)54;
          v307 = 3;
          LOWORD(v190) = *(_WORD *)(v619 + 20);
          v306 = v190;
          v305 = *(HWND *)(v619 + 12);
          v304 = *(HWND *)(v619 + 8);
          v303 = *(HWND *)(v619 + 4);
          v302 = *(HWND *)v619;
          *(_DWORD *)&v301 = *(_DWORD *)a2;
          v191 = (Request *)unknown_libname_96(&v797);
          Request::RequestMsgNewsData(
            v191,
            *(int *)&v301,
            (int)v302,
            (int)v303,
            (int)v304,
            (int)v305,
            (unsigned __int16)v306,
            3,
            54,
            "News_Info_Querier_ForFree",
            (int)v310);
          goto LABEL_694;
        case 43:
          v310 = *(HWND *)a2;
          v9 = (Request *)unknown_libname_96(&v797);
          Request::SDSKeepAlive(v9, (int)v310);
          goto LABEL_694;
        case 44:
          v310 = *(HWND *)a2;
          v13 = (Request *)unknown_libname_96(&v797);
          Request::AppKeepAlive(v13, (int)v310);
          goto LABEL_694;
        case 45:
          v310 = *(HWND *)a2;
          v10 = (Request *)unknown_libname_96(&v797);
          Request::RTSKeepAlive(v10, (int)v310);
          goto LABEL_694;
        case 46:
          v310 = *(HWND *)a2;
          v12 = (Request *)unknown_libname_96(&v797);
          Request::MQSKeepAlive(v12, (int)v310);
          goto LABEL_694;
        case 47:
          v310 = *(HWND *)a2;
          v11 = (Request *)unknown_libname_96(&v797);
          Request::IMSKeepAlive(v11, (int)v310);
          goto LABEL_694;
        case 48:
          v197 = a2;
          v615 = (_BYTE *)*((_DWORD *)a2 + 3);
          v198 = v615;
          LOBYTE(v197) = v615[1];
          v310 = (HWND)v197;
          LOBYTE(v198) = *v615;
          v309 = (int)v198;
          v308 = *(HWND *)a2;
          v199 = (Request *)unknown_libname_96(&v797);
          Request::RequestBkCapRankSimple(v199, (int)v308, v309, (unsigned __int8)v310);
          goto LABEL_694;
        case 49:
          v200 = a2;
          v614 = (_BYTE *)*((_DWORD *)a2 + 3);
          v201 = v614;
          LOBYTE(v200) = v614[1];
          v310 = (HWND)v200;
          LOBYTE(v201) = *v614;
          v309 = (int)v201;
          v308 = *(HWND *)a2;
          v202 = (Request *)unknown_libname_96(&v797);
          Request::RequestZCUpDownRankSimple(v202, (int)v308, v309, (unsigned __int8)v310);
          goto LABEL_694;
        case 50:
          v613 = *((_DWORD *)a2 + 3);
          if ( !v613 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v611 = 0;
          mfc80xU_304(&v610, &unk_51483CB);
          LOBYTE(v806) = 35;
          sub_4DD7550(&v612);
          LOBYTE(v806) = 36;
          for ( k = 0; ; ++k )
          {
            v203 = sub_4D840E0(v613);
            if ( k >= v203 )
              break;
            v204 = (unsigned __int16 *)sub_4E75720(k);
            mfc80xU_2313(&v610, "BK%04d", *v204);
            v205 = (char *)mfc80xU_872(&v610);
            v611 = sub_50EF6C0(v205, 90);
            sub_4DD7580(&v611);
          }
          v310 = (HWND)1;
          v309 = (int)&v612;
          v308 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestPushBlocksInfo(v308, &v612, 1);
          LOBYTE(v806) = 35;
          sub_4DE6AF0(&v612);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v610);
          goto LABEL_694;
        case 51:
          v607 = *((_DWORD *)a2 + 3);
          if ( !v607 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v608 = CDataMgr::ChangeCycleUIToNet(v399, *(unsigned __int8 *)(v607 + 17));
          if ( v608 < 0 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)1029;
          v309 = *(_DWORD *)(v607 + 27);
          v308 = *(HWND *)(v607 + 23);
          v206 = v607;
          v207 = *(HWND *)(v607 + 19);
          v307 = *(_DWORD *)(v607 + 19);
          LOBYTE(v206) = *(_BYTE *)(v607 + 18);
          v306 = (HWND)v206;
          LOBYTE(v207) = v608;
          v305 = v207;
          v304 = (HWND)(v607 + 1);
          LOBYTE(v207) = *(_BYTE *)v607;
          v303 = v207;
          v302 = *(HWND *)a2;
          v208 = (Request *)unknown_libname_96(&v797);
          Request::RequestCapitalFlowDay(
            v208,
            (int)v302,
            (char)v303,
            (const char *)v304,
            (char)v305,
            (char)v306,
            v307,
            (int)v308,
            v309,
            1029);
          goto LABEL_694;
        case 52:
          v606 = *((_DWORD *)a2 + 3);
          if ( !v606 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = *(HWND *)(v606 + 15);
          v209 = *(_DWORD *)(v606 + 11);
          v309 = *(_DWORD *)(v606 + 11);
          v308 = (HWND)(v606 + 4);
          LOBYTE(v209) = *(_BYTE *)v606;
          v307 = v209;
          v306 = *(HWND *)a2;
          v210 = (Request *)unknown_libname_96(&v797);
          Request::RequestCoreConception(v210, (int)v306, v307, (const char *)v308, v309, (int)v310);
          goto LABEL_694;
        case 53:
          v214 = a2;
          v589 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v589 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)622;
          v309 = 1;
          LOBYTE(v214) = *v589;
          v308 = (HWND)v214;
          v307 = *(_DWORD *)a2;
          v215 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v215, v307, (char)v308, 1, 622);
          goto LABEL_694;
        case 54:
          v216 = a2;
          v588 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v588 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)624;
          v309 = 1;
          LOBYTE(v216) = *v588;
          v308 = (HWND)v216;
          v307 = *(_DWORD *)a2;
          v217 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v217, v307, (char)v308, 1, 624);
          goto LABEL_694;
        case 55:
          v587 = *((_DWORD *)a2 + 3);
          if ( !v587 || (unsigned int)sub_4E90A60(v587) < 1 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7550(&v586);
          LOBYTE(v806) = 45;
          sub_4DD7550(&v584);
          LOBYTE(v806) = 46;
          v585 = 0;
          for ( l = 0; ; ++l )
          {
            v218 = sub_4E90A60(v587);
            if ( l >= v218 )
              break;
            v582 = (char *)sub_4E756D0(l);
            if ( *v582 != 1 && *v582 )
            {
              if ( *v582 == 90 )
              {
                v585 = sub_50EF6C0(v582 + 1, *v582);
                v418 = v585;
                sub_4DD7580(&v418);
              }
            }
            else
            {
              v585 = sub_50EF6C0(v582 + 1, *v582);
              v419 = v585;
              sub_4DD7580(&v419);
            }
          }
          if ( sub_4DD2EA0(&v586) )
          {
            v310 = 0;
            v309 = 623;
            v308 = (HWND)1;
            v307 = (int)&v586;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v586, 1, 623, 0);
          }
          if ( sub_4DD2EA0(&v584) )
          {
            v310 = 0;
            v309 = 625;
            v308 = (HWND)1;
            v307 = (int)&v584;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v584, 1, 625, 0);
          }
          LOBYTE(v806) = 45;
          sub_4DE6AF0(&v584);
          LOBYTE(v806) = 4;
          sub_4DE6AF0(&v586);
          goto LABEL_694;
        case 56:
          v581 = (_DWORD *)*((_DWORD *)a2 + 3);
          if ( !v581 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          mfc80xU_310(&v579);
          LOBYTE(v806) = 47;
          mfc80xU_2313(&v579, "BK%04d", *v581);
          v219 = (char *)mfc80xU_872(&v579);
          v580 = sub_50EF6C0(v219, 90);
          v310 = 0;
          v309 = 626;
          v308 = (HWND)1;
          v307 = v580;
          v306 = *(HWND *)a2;
          v220 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkStkList(v220, (int)v306, v307, 1, 626, 0);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v579);
          goto LABEL_694;
        case 57:
        case 58:
        case 61:
        case 62:
          v576 = *((_DWORD *)a2 + 3);
          sub_4DF8110(&v571);
          v570 = 0;
          if ( !CDataMgr::GetCategoryIdByDataType(v399, *((_DWORD *)a2 + 2), &v570) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          if ( *(_WORD *)(v576 + 35) == 4 || *(_WORD *)(v576 + 35) == 20 )
            goto LABEL_506;
          if ( *(_WORD *)(v576 + 35) == 2 )
          {
            if ( *(_BYTE *)(v576 + 32) == 1 && !strcmp((const char *)(v576 + 16), "000001")
              || *(_BYTE *)(v576 + 32) == 1 && !strcmp((const char *)(v576 + 16), "000300")
              || !*(_BYTE *)(v576 + 32) && !strcmp((const char *)(v576 + 16), "399001") )
            {
              LOBYTE(v806) = 0;
              sub_4E8C780(&v797);
              v806 = -1;
              sub_4E8C780(&v805);
              return;
            }
            *(_WORD *)(v576 + 33) = -1;
          }
          else
          {
            *(_WORD *)(v576 + 33) = -1;
          }
LABEL_506:
          if ( *(_DWORD *)a2 )
          {
            v226 = (HWND)QDataEngine::ReadMsgTipDataNew(
                           (struct MSGTIP_DATA_BASE_SAFE_TAG *)&v571,
                           (char *)(v576 + 16),
                           *(_BYTE *)(v576 + 32),
                           *((_DWORD *)a2 + 2),
                           *(char *)(v576 + 37));
            if ( (_BYTE)v226 )
            {
              if ( *(_DWORD *)v576 < v574 && *(_DWORD *)(v576 + 8) > v572 )
              {
                if ( *(_DWORD *)v576 >= v572 && *(_DWORD *)(v576 + 8) <= v574 )
                {
                  LOBYTE(v806) = 0;
                  sub_4E8C780(&v797);
                  v806 = -1;
                  sub_4E8C780(&v805);
                  return;
                }
                if ( *(_DWORD *)v576 >= v572 || *(_DWORD *)(v576 + 8) > v574 )
                {
                  if ( *(_DWORD *)(v576 + 8) < v574 || *(_DWORD *)v576 <= v572 )
                  {
                    HIWORD(v226) = HIWORD(v576);
                    if ( *(_DWORD *)(v576 + 8) >= v574 )
                    {
                      v226 = *(HWND *)v576;
                      if ( *(_DWORD *)v576 < v572 )
                      {
                        v566 = *(_DWORD *)(v576 + 8);
                        v567 = *(_DWORD *)(v576 + 12);
                        if ( *(_WORD *)(v576 + 35) != 4 )
                        {
                          *(_DWORD *)(v576 + 8) = v572;
                          HIWORD(v232) = HIWORD(v576);
                          *(_DWORD *)(v576 + 12) = v573;
                          v233 = v576;
                          LOWORD(v232) = *(_WORD *)(v576 + 38);
                          v310 = v232;
                          HIWORD(v234) = HIWORD(v576);
                          LOBYTE(v233) = *(_BYTE *)(v576 + 37);
                          v309 = v233;
                          HIWORD(v232) = HIWORD(v576);
                          LOWORD(v234) = *(_WORD *)(v576 + 35);
                          v308 = v234;
                          v235 = v576;
                          LOWORD(v232) = *(_WORD *)(v576 + 33);
                          v307 = (int)v232;
                          LOBYTE(v235) = *(_BYTE *)(v576 + 32);
                          v306 = (HWND)v235;
                          v305 = (HWND)(v576 + 16);
                          v304 = *(HWND *)(v576 + 12);
                          v303 = *(HWND *)(v576 + 8);
                          v302 = *(HWND *)(v576 + 4);
                          *(_DWORD *)&v301 = *(_DWORD *)v576;
                          v300 = v570;
                          v299 = *(HWND *)a2;
                          v236 = (Request *)unknown_libname_96(&v797);
                          Request::RequestMsgTip(
                            v236,
                            (int)v299,
                            v300,
                            *(int *)&v301,
                            (int)v302,
                            (int)v303,
                            (int)v304,
                            (char *)v305,
                            (char)v306,
                            v307,
                            (unsigned __int16)v308,
                            v309,
                            (unsigned __int16)v310);
                        }
                        *(_DWORD *)(v576 + 8) = v566;
                        *(_DWORD *)(v576 + 12) = v567;
                        *(_DWORD *)v576 = v574;
                        HIWORD(v226) = HIWORD(v576);
                        *(_DWORD *)(v576 + 4) = v575;
                      }
                    }
                  }
                  else
                  {
                    HIWORD(v226) = HIWORD(v574);
                    *(_DWORD *)v576 = v574;
                    *(_DWORD *)(v576 + 4) = v575;
                  }
                }
                else if ( *(_DWORD *)(v576 + 8) != v574 || *(_DWORD *)(v576 + 12) <= v575 )
                {
                  *(_DWORD *)(v576 + 8) = v572;
                  HIWORD(v226) = HIWORD(v573);
                  *(_DWORD *)(v576 + 12) = v573;
                }
                else
                {
                  v568 = *(_DWORD *)(v576 + 8);
                  v569 = *(_DWORD *)(v576 + 12);
                  if ( *(_WORD *)(v576 + 35) != 4 )
                  {
                    *(_DWORD *)(v576 + 8) = v572;
                    HIWORD(v227) = HIWORD(v576);
                    *(_DWORD *)(v576 + 12) = v573;
                    v228 = v576;
                    LOWORD(v227) = *(_WORD *)(v576 + 38);
                    v310 = v227;
                    HIWORD(v229) = HIWORD(v576);
                    LOBYTE(v228) = *(_BYTE *)(v576 + 37);
                    v309 = v228;
                    HIWORD(v227) = HIWORD(v576);
                    LOWORD(v229) = *(_WORD *)(v576 + 35);
                    v308 = v229;
                    v230 = v576;
                    LOWORD(v227) = *(_WORD *)(v576 + 33);
                    v307 = (int)v227;
                    LOBYTE(v230) = *(_BYTE *)(v576 + 32);
                    v306 = (HWND)v230;
                    v305 = (HWND)(v576 + 16);
                    v304 = *(HWND *)(v576 + 12);
                    v303 = *(HWND *)(v576 + 8);
                    v302 = *(HWND *)(v576 + 4);
                    *(_DWORD *)&v301 = *(_DWORD *)v576;
                    v300 = v570;
                    v299 = *(HWND *)a2;
                    v231 = (Request *)unknown_libname_96(&v797);
                    Request::RequestMsgTip(
                      v231,
                      (int)v299,
                      v300,
                      *(int *)&v301,
                      (int)v302,
                      (int)v303,
                      (int)v304,
                      (char *)v305,
                      (char)v306,
                      v307,
                      (unsigned __int16)v308,
                      v309,
                      (unsigned __int16)v310);
                  }
                  *(_DWORD *)v576 = v574;
                  *(_DWORD *)(v576 + 4) = v575;
                  HIWORD(v226) = HIWORD(v568);
                  *(_DWORD *)(v576 + 8) = v568;
                  *(_DWORD *)(v576 + 12) = v569;
                }
              }
              else if ( *(_DWORD *)v576 != v574 || *(_DWORD *)(v576 + 12) <= v575 )
              {
                if ( *(_DWORD *)(v576 + 8) != v572 || *(_DWORD *)(v576 + 4) >= v573 )
                {
                  LOBYTE(v806) = 0;
                  sub_4E8C780(&v797);
                  v806 = -1;
                  sub_4E8C780(&v805);
                  return;
                }
                HIWORD(v226) = HIWORD(v576);
                *(_DWORD *)(v576 + 12) = v573;
              }
              else
              {
                HIWORD(v226) = HIWORD(v576);
                *(_DWORD *)(v576 + 4) = v575;
              }
            }
          }
          else
          {
            if ( !QDataEngine::ReadMsgTipDataNew(
                    (struct MSGTIP_DATA_BASE_SAFE_TAG *)&v571,
                    (char *)(v576 + 16),
                    *(_BYTE *)(v576 + 32),
                    *((_DWORD *)a2 + 2),
                    *(char *)(v576 + 37)) )
            {
              LOBYTE(v806) = 0;
              sub_4E8C780(&v797);
              v806 = -1;
              sub_4E8C780(&v805);
              return;
            }
            *(_DWORD *)v576 = v574;
            *(_DWORD *)(v576 + 4) = v575;
            *(_DWORD *)(v576 + 8) = QDataEngine::m_nAppCurDate + 10;
            HIWORD(v226) = HIWORD(v576);
            *(_DWORD *)(v576 + 12) = &unk_399B7;
          }
          v237 = v576;
          LOWORD(v226) = *(_WORD *)(v576 + 38);
          v310 = v226;
          HIWORD(v238) = HIWORD(v576);
          LOBYTE(v237) = *(_BYTE *)(v576 + 37);
          v309 = v237;
          HIWORD(v239) = HIWORD(v576);
          LOWORD(v238) = *(_WORD *)(v576 + 35);
          v308 = v238;
          v240 = v576;
          LOWORD(v239) = *(_WORD *)(v576 + 33);
          v307 = v239;
          LOBYTE(v240) = *(_BYTE *)(v576 + 32);
          v306 = (HWND)v240;
          v305 = (HWND)(v576 + 16);
          v304 = *(HWND *)(v576 + 12);
          v303 = *(HWND *)(v576 + 8);
          v302 = *(HWND *)(v576 + 4);
          *(_DWORD *)&v301 = *(_DWORD *)v576;
          v300 = v570;
          v299 = *(HWND *)a2;
          v241 = (Request *)unknown_libname_96(&v797);
          Request::RequestMsgTip(
            v241,
            (int)v299,
            v300,
            *(int *)&v301,
            (int)v302,
            (int)v303,
            (int)v304,
            (char *)v305,
            (char)v306,
            v307,
            (unsigned __int16)v308,
            v309,
            (unsigned __int16)v310);
          goto LABEL_694;
        case 60:
        case 79:
          v577 = 0;
          if ( !CDataMgr::GetCategoryIdByDataType(v399, *((_DWORD *)a2 + 2), &v577) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          HIWORD(v221) = HIWORD(a2);
          v578 = *((_DWORD *)a2 + 3);
          v222 = v578;
          LOWORD(v221) = *(_WORD *)(v578 + 38);
          v310 = v221;
          HIWORD(v223) = HIWORD(v578);
          LOBYTE(v222) = *(_BYTE *)(v578 + 37);
          v309 = v222;
          HIWORD(v221) = HIWORD(v578);
          LOWORD(v223) = *(_WORD *)(v578 + 35);
          v308 = v223;
          v224 = v578;
          LOWORD(v221) = *(_WORD *)(v578 + 33);
          v307 = (int)v221;
          LOBYTE(v224) = *(_BYTE *)(v578 + 32);
          v306 = (HWND)v224;
          v305 = (HWND)(v578 + 16);
          v304 = *(HWND *)(v578 + 12);
          v303 = *(HWND *)(v578 + 8);
          v302 = *(HWND *)(v578 + 4);
          *(_DWORD *)&v301 = *(_DWORD *)v578;
          v300 = v577;
          v299 = *(HWND *)a2;
          v225 = (Request *)unknown_libname_96(&v797);
          Request::RequestMsgTip(
            v225,
            (int)v299,
            v300,
            *(int *)&v301,
            (int)v302,
            (int)v303,
            (int)v304,
            (char *)v305,
            (char)v306,
            v307,
            (unsigned __int16)v308,
            v309,
            (unsigned __int16)v310);
          goto LABEL_694;
        case 63:
        case 64:
          v629 = *((_DWORD *)a2 + 3);
          v628 = 0;
          CDataMgr::GetCategoryIdByDataType(v399, *((_DWORD *)a2 + 2), &v628);
          sub_5009D40(*(_DWORD *)a2, v628, v629);
          goto LABEL_694;
        case 66:
          sub_509B110(*(_DWORD *)a2);
          v565 = *((_DWORD *)a2 + 3);
          if ( !v565 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(&v555);
          LOBYTE(v806) = 48;
          v556 = 0;
          v557 = 0;
          v558 = 0;
          v559 = 0;
          v560 = 0;
          v561 = 0;
          v562 = 0;
          v563 = 0;
          v564 = 0;
          v242 = (const WCHAR *)mfc80xU_2461(&QDataEngine::m_strCID);
          sub_50ECD00(v242, (int)&v555);
          mfc80xU_5398(&QDataEngine::m_strCID);
          v243 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(&v555);
          strcpy_s(&v556, 0x21u, v243);
          HIWORD(v244) = HIWORD(v565);
          v310 = *(HWND *)(v565 + 20);
          LOWORD(v244) = *(_WORD *)(v565 + 16);
          v309 = v244;
          v308 = (HWND)&v556;
          HIWORD(v245) = HIWORD(v565);
          v307 = *(unsigned __int16 *)(v565 + 24);
          HIWORD(v246) = HIWORD(v565);
          LOWORD(v245) = *(_WORD *)(v565 + 12);
          v306 = v245;
          LOWORD(v246) = *(_WORD *)(v565 + 8);
          v305 = v246;
          v304 = *(HWND *)(v565 + 4);
          v303 = *(HWND *)v565;
          v302 = *(HWND *)a2;
          v247 = (Request *)unknown_libname_96(&v797);
          Request::RequestPopWndData(
            v247,
            (int)v302,
            (int)v303,
            (int)v304,
            (__int16)v305,
            (__int16)v306,
            v307,
            &v556,
            v309,
            (int)v310);
          LOBYTE(v806) = 4;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v555);
          goto LABEL_694;
        case 67:
          v310 = *(HWND *)a2;
          v248 = (Request *)unknown_libname_96(&v797);
          Request::RequestCloseDataEnable(v248, (int)v310);
          goto LABEL_694;
        case 68:
          v554 = *((_DWORD *)a2 + 3);
          if ( !v554 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)(v554 + 20);
          v309 = *(_DWORD *)(v554 + 16);
          v308 = *(HWND *)(v554 + 12);
          v249 = v554;
          v307 = *(_DWORD *)(v554 + 8);
          v250 = v554;
          LOBYTE(v249) = *(_BYTE *)(v554 + 4);
          v306 = (HWND)v249;
          LOBYTE(v250) = *(_BYTE *)v554;
          v305 = (HWND)v250;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestCloseDataUrls(v304, (char)v305, (char)v306, v307, v308, v309, v310);
          goto LABEL_694;
        case 71:
          v251 = (Request *)unknown_libname_96(&v797);
          Request::RequestDataErrorNotify(v251);
          goto LABEL_694;
        case 72:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v553 = (_DWORD *)*((_DWORD *)a2 + 3);
          if ( !v553 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DC7C50(&v550);
          LOBYTE(v806) = 49;
          sub_4EA0EF0(&v549);
          while ( 1 )
          {
            v252 = sub_4DCC7B0(v553, (int)&v416);
            if ( !(unsigned __int8)sub_4DAB600(v252) )
              break;
            v253 = sub_4D83880(&v549);
            LOBYTE(v253) = *(_BYTE *)(v253 + 16);
            v310 = (HWND)v253;
            v254 = (char *)sub_4D83880(&v549);
            v551 = sub_50EF6C0(v254, (char)v310);
            if ( v551 != -1 )
            {
              v552 = *(_DWORD *)(sub_4D83880(&v549) + 17) + 10000 * (QDataEngine::m_AppServerDate % 1000000);
              sub_4DC7C80(&v551);
            }
            sub_4E76360(&v417, 0);
          }
          v310 = (HWND)3020;
          v309 = 5;
          v308 = (HWND)&v550;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestPushRtLine(v306, v307, &v550, 5, 3020);
          LOBYTE(v806) = 4;
          sub_4E264A0(&v550);
          goto LABEL_694;
        case 73:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v548 = (_DWORD *)*((_DWORD *)a2 + 3);
          if ( !v548 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DC7C50(&v545);
          LOBYTE(v806) = 50;
          sub_4EA0EF0(&v544);
          while ( 1 )
          {
            v255 = sub_4DCC7B0(v548, (int)&v414);
            if ( !(unsigned __int8)sub_4DAB600(v255) )
              break;
            v256 = sub_4D83880(&v544);
            LOBYTE(v256) = *(_BYTE *)(v256 + 16);
            v310 = (HWND)v256;
            v257 = (char *)sub_4D83880(&v544);
            v546 = sub_50EF6C0(v257, (char)v310);
            if ( v546 != -1 )
            {
              v547 = *(_DWORD *)(sub_4D83880(&v544) + 17) + 10000 * (QDataEngine::m_AppServerDate % 1000000);
              sub_4DC7C80(&v546);
            }
            sub_4E76360(&v415, 0);
          }
          v310 = (HWND)3021;
          v309 = 5;
          v308 = (HWND)&v545;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestPushRtLine(v306, v307, &v545, 5, 3021);
          LOBYTE(v806) = 4;
          sub_4E264A0(&v545);
          goto LABEL_694;
        case 74:
          v543 = (void *)*((_DWORD *)a2 + 3);
          if ( !v543 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          if ( CDataMgr::IsGssMarket(v399, *(_BYTE *)v543) )
          {
            memcpy(&v542, v543, 0x19u);
            v310 = 0;
            v309 = 0;
            v308 = 0;
            v307 = (int)"REQID_HIS_TRENDLINE_GLOBAL";
            v306 = (HWND)1022;
            v305 = (HWND)&v542;
            v304 = *(HWND *)a2;
            unknown_libname_96(&v797);
            sub_4E84320(1, (int)v304, &v542, 1022, "REQID_HIS_TRENDLINE_GLOBAL", 0, 0, 0);
          }
          else
          {
            v310 = (HWND)1015;
            v309 = (int)v543 + 1;
            LOBYTE(v258) = *(_BYTE *)v543;
            v308 = v258;
            v307 = *(_DWORD *)((char *)v543 + 21);
            v306 = *(HWND *)((char *)v543 + 17);
            v305 = *(HWND *)a2;
            v259 = (Request *)unknown_libname_96(&v797);
            Request::RequestHisTrendAndCfs(
              v259,
              (int)v305,
              (unsigned int)v306,
              v307,
              (char)v308,
              (const char *)v309,
              1015);
          }
          goto LABEL_694;
        case 75:
          v541 = *((_DWORD *)a2 + 3);
          if ( !v541 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v260 = CDataMgr::IsPayUser(v399);
          v261 = v260;
          if ( v260 )
          {
            v310 = (HWND)1016;
            v309 = v541 + 1;
            LOBYTE(v261) = *(_BYTE *)v541;
            v308 = (HWND)v261;
            v307 = *(_DWORD *)(v541 + 21);
            v306 = *(HWND *)(v541 + 17);
            v305 = *(HWND *)a2;
            v262 = (Request *)unknown_libname_96(&v797);
            Request::RequestHisTrendAndCfs(
              v262,
              (int)v305,
              (unsigned int)v306,
              v307,
              (char)v308,
              (const char *)v309,
              1016);
          }
          else
          {
            v310 = (HWND)1019;
            v309 = v541 + 1;
            LOBYTE(v261) = *(_BYTE *)v541;
            v308 = (HWND)v261;
            v307 = *(_DWORD *)(v541 + 21);
            v306 = *(HWND *)(v541 + 17);
            v305 = *(HWND *)a2;
            v263 = (Request *)unknown_libname_96(&v797);
            Request::RequestHisTrendAndCfs(
              v263,
              (int)v305,
              (unsigned int)v306,
              v307,
              (char)v308,
              (const char *)v309,
              1019);
          }
          goto LABEL_694;
        case 76:
          v540 = (char *)*((_DWORD *)a2 + 3);
          if ( !v540 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          if ( QDataEngine::IsGssMarket(*v540) )
          {
            v539 = *(_DWORD *)(v540 + 17);
            v536 = *v540;
            v538 = QDataEngine::GetCurDateByMarket(*v540, v540 + 1);
            strcpy_s(&v537, 0x10u, v540 + 1);
            v310 = 0;
            v309 = 0;
            v308 = 0;
            v307 = (int)"REQID_VALIDKLINE_GLOBAL";
            v306 = (HWND)1023;
            v305 = (HWND)&v536;
            v304 = *(HWND *)a2;
            unknown_libname_96(&v797);
            sub_4E84320(1, (int)v304, &v536, 1023, "REQID_VALIDKLINE_GLOBAL", 0, 0, 0);
          }
          else
          {
            v264 = *(HWND *)(v540 + 17);
            v310 = *(HWND *)(v540 + 17);
            v309 = (int)(v540 + 1);
            LOBYTE(v264) = *v540;
            v308 = v264;
            v307 = *(_DWORD *)a2;
            v265 = (Request *)unknown_libname_96(&v797);
            Request::RequestHisRtLineValidDay(v265, v307, (char)v308, (const char *)v309, (int)v310);
          }
          goto LABEL_694;
        case 80:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v535 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v535 || (unsigned __int8)mfc80xU_3927(v535 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(&v533);
          LOBYTE(v806) = 51;
          v266 = (const WCHAR *)mfc80xU_870(v535 + 1);
          v267 = sub_50ECD00(v266, (int)&v533);
          LOBYTE(v267) = *v535;
          v310 = (HWND)v267;
          v268 = (char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(&v533);
          v532 = sub_50EF6C0(v268, (char)v310);
          if ( v532 == -1 )
          {
            LOBYTE(v806) = 4;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v533);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7550(&v534);
          LOBYTE(v806) = 52;
          sub_4DD7580(&v532);
          v310 = (HWND)817;
          v309 = 5;
          v308 = (HWND)&v534;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestStkL2MultiQuote(v306, v307, &v534, 5, 817);
          LOBYTE(v806) = 51;
          sub_4DE6AF0(&v534);
          LOBYTE(v806) = 4;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v533);
          goto LABEL_694;
        case 82:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v531 = (char *)*((_DWORD *)a2 + 3);
          if ( !v531 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v529 = 5;
          v530 = *v531;
          v310 = 0;
          v309 = 0;
          v308 = (HWND)1;
          v307 = (int)"REQID_QUOTE_PUSH_PROBABILITY_UP";
          v306 = (HWND)820;
          v305 = (HWND)&v529;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4E84610(0, (int)v304, &v529, 820, "REQID_QUOTE_PUSH_PROBABILITY_UP", 1, 0, 0);
          goto LABEL_694;
        case 83:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = 0;
          v309 = 0;
          v308 = 0;
          v307 = (int)"REQID_QUOTE_PUSH_PROB_UP_DAYS";
          v306 = (HWND)821;
          v305 = (HWND)&v528;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4EB3D00(0, (int)v304, &v528, 821, "REQID_QUOTE_PUSH_PROB_UP_DAYS", 0, 0, 0);
          goto LABEL_694;
        case 84:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v527 = (int *)*((_DWORD *)a2 + 3);
          if ( !v527 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E49720(&v526);
          LOBYTE(v806) = 53;
          QDataEngine::GetAllDateAndMd5(&v526);
          v413 = *v527;
          sub_4E763C0(&v524, &v413);
          v269 = sub_4E58970(&v412);
          if ( (unsigned __int8)sub_4DACFF0(v269) )
          {
            v522 = *v527;
            v310 = 0;
            v309 = 0;
            v308 = (HWND)1;
            v307 = (int)"REQID_QUOTE_PUSH_PROB_UP_HIS";
            v306 = (HWND)822;
            v305 = (HWND)&v522;
            v304 = *(HWND *)a2;
            unknown_libname_96(&v797);
            sub_4E84900(0, (int)v304, &v522, 822, "REQID_QUOTE_PUSH_PROB_UP_HIS", 1, 0, 0);
          }
          else
          {
            v270 = (int *)sub_4E75CA0(&v411);
            v271 = *v270;
            v272 = v270[1];
            v524 = v271;
            v525 = v272;
            while ( 1 )
            {
              v273 = sub_4E58970(&v409);
              if ( !(unsigned __int8)sub_4DAB600(v273) )
                break;
              v274 = (_DWORD *)sub_4E70840(&v524);
              if ( *v274 != QDataEngine::GetCurDateByMarket(1, 0) )
              {
                v522 = *(_DWORD *)sub_4E70840(&v524);
                v275 = sub_4E70840(&v524);
                v276 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(v275 + 4);
                strcpy_s(&v523, 0x21u, v276);
                v310 = 0;
                v309 = 0;
                v308 = (HWND)1;
                v307 = (int)"REQID_QUOTE_PUSH_PROB_UP_HIS";
                v306 = (HWND)822;
                v305 = (HWND)&v522;
                v304 = *(HWND *)a2;
                unknown_libname_96(&v797);
                sub_4E84900(0, (int)v304, &v522, 822, "REQID_QUOTE_PUSH_PROB_UP_HIS", 1, 0, 0);
              }
              sub_4E72150(&v410, 0);
            }
          }
          LOBYTE(v806) = 4;
          sub_4E75610(&v526);
          goto LABEL_694;
        case 85:
          v277 = *((_DWORD *)a2 + 3);
          v521 = *((_DWORD *)a2 + 3);
          if ( !v521 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)(v521 + 14);
          HIWORD(v278) = HIWORD(v521);
          LOWORD(v277) = *(_WORD *)(v521 + 10);
          v309 = v277;
          LOWORD(v278) = *(_WORD *)(v521 + 8);
          v308 = v278;
          v307 = *(_DWORD *)(v521 + 4);
          v306 = *(HWND *)v521;
          v305 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestStrategyPoolPopWnd(v305, v306, v307, (__int16)v308, v309, v310);
          goto LABEL_694;
        case 86:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E76450(&v514);
          LOBYTE(v806) = 56;
          if ( !(unsigned __int8)CDataMgr::ConvertRequestStructToUnionStruct(
                                   *((_DWORD *)a2 + 2),
                                   *((_DWORD *)a2 + 3),
                                   &v514) )
          {
            LOBYTE(v806) = 4;
            sub_4E76480(&v514);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)5;
          v309 = 8104;
          v308 = (HWND)&v514;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestQuoteChartMinKLineGlobal(v306, v307, &v514, 8104, 5);
          LOBYTE(v806) = 4;
          sub_4E76480(&v514);
          goto LABEL_694;
        case 87:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E76450(&v515);
          LOBYTE(v806) = 55;
          if ( !(unsigned __int8)CDataMgr::ConvertRequestStructToUnionStruct(
                                   *((_DWORD *)a2 + 2),
                                   *((_DWORD *)a2 + 3),
                                   &v515) )
          {
            LOBYTE(v806) = 4;
            sub_4E76480(&v515);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)5;
          v309 = 8103;
          v308 = (HWND)&v515;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestQuoteChartRtLineGlobal(v306, v307, &v515, 8103, 5);
          LOBYTE(v806) = 4;
          sub_4E76480(&v515);
          goto LABEL_694;
        case 88:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E76450(&v513);
          LOBYTE(v806) = 57;
          if ( !(unsigned __int8)CDataMgr::ConvertRequestStructToUnionStruct(
                                   *((_DWORD *)a2 + 2),
                                   *((_DWORD *)a2 + 3),
                                   &v513) )
          {
            LOBYTE(v806) = 4;
            sub_4E76480(&v513);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)5;
          v309 = 8111;
          v308 = (HWND)&v513;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestHqGlobal(v306, v307, &v513, 8111, 5);
          v310 = (HWND)5;
          v309 = 8117;
          v308 = (HWND)&v513;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestQuoteExGlobal(v306, v307, &v513, 8117, 5);
          LOBYTE(v806) = 4;
          sub_4E76480(&v513);
          goto LABEL_694;
        case 89:
          sub_4E75770(&v519);
          LOBYTE(v806) = 54;
          if ( (unsigned __int8)sub_4DECD30((char *)QDataEngine::m_pDataCenter + 160) )
          {
            LOBYTE(v806) = 4;
            sub_4E757A0(&v519);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E75CA0(&v518);
          while ( 1 )
          {
            v280 = sub_4E58970(&v407);
            if ( !(unsigned __int8)sub_4DAB600(v280) )
              break;
            v281 = (char *)sub_4E70840(&v518);
            v516 = *v281;
            if ( !*(_DWORD *)((char *)v399 + 1318)
              || (LOBYTE(v281) = v516, v310 = (HWND)v281, v282 = *(_DWORD *)((char *)v399 + 1318), !sub_4FF4070(v516)) )
            {
              v283 = sub_4E70840(&v518);
              v284 = (const char *)sub_5096A60(*(_DWORD *)(v283 + 4));
              strcpy_s(&v517, 0x21u, v284);
              sub_4E757C0(&v516);
            }
            sub_4E70860(&v408, 0);
          }
          unknown_libname_96(&v797);
          Request::RequestGssStkList(&v519, 0);
          LOBYTE(v806) = 4;
          sub_4E757A0(&v519);
          goto LABEL_694;
        case 90:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v512 = *((_DWORD *)a2 + 3);
          if ( !v512 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)5;
          v309 = v512;
          v308 = *(HWND *)a2;
          v307 = *((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestPushGssStkDetail(v307, v308, v309, 5);
          goto LABEL_694;
        case 94:
          v510 = *((_DWORD *)a2 + 3);
          if ( !v510 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_50C72C0(*(_DWORD *)a2, v510, 0);
          goto LABEL_694;
        case 96:
          v508 = (_DWORD *)*((_DWORD *)a2 + 3);
          if ( !v508 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E76510(&v509);
          LOBYTE(v806) = 59;
          sub_4E74C20(&v506);
          sub_4EA0EF0(&v505);
          while ( 1 )
          {
            v285 = sub_4DCC7B0(v508, (int)&v405);
            if ( !(unsigned __int8)sub_4DAB600(v285) )
              break;
            v506 = *(_DWORD *)sub_4E87B30(&v505);
            v286 = (_DWORD *)sub_4E87B30(&v505);
            v319 = QDataEngine::GetMd5OfSpecialBuffer(&v404, *v286, 0);
            v318 = v319;
            LOBYTE(v806) = 60;
            v287 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(v319);
            strcpy_s(&v507, 0x21u, v287);
            LOBYTE(v806) = 59;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v404);
            sub_4DEF8D0(&v506);
            sub_4E76560(&v406, 0);
          }
          v310 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestBufferList(&v509, v310);
          LOBYTE(v806) = 4;
          sub_4E76540(&v509);
          goto LABEL_694;
        case 97:
          v623 = (int *)*((_DWORD *)a2 + 3);
          if ( !v623 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)74;
          v309 = (int)"MSQ_FINANCIAL_GSS";
          v308 = (HWND)v623[1];
          v307 = *v623;
          v306 = *(HWND *)a2;
          v187 = (Request *)unknown_libname_96(&v797);
          Request::RequestPinYinData(v187, (int)v306, v307, (int)v308, "MSQ_FINANCIAL_GSS", 74);
          goto LABEL_694;
        case 98:
          v520 = (HWND *)*((_DWORD *)a2 + 3);
          if ( !v520 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = v520[2];
          v309 = (int)v520[1];
          v308 = *v520;
          v307 = *(_DWORD *)a2;
          v279 = (Request *)unknown_libname_96(&v797);
          Request::RequestStrategyPoolTypeList(v279, v307, (int)v308, v309, (int)v310);
          goto LABEL_694;
        case 104:
          v496 = (char *)*((_DWORD *)a2 + 3);
          v494 = *v496;
          sub_4E4CBC0(&v495, v496 + 1, 0x10u);
          v310 = 0;
          v309 = 0;
          v308 = 0;
          v307 = (int)"REQID_STK_STATIC_DATA";
          v306 = (HWND)734;
          v305 = (HWND)&v494;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4EB73E0(0, (int)v304, &v494, 734, "REQID_STK_STATIC_DATA", 0, 0, 0);
          goto LABEL_694;
        case 109:
          if ( !*((_DWORD *)a2 + 1) )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E76450(&v511);
          LOBYTE(v806) = 58;
          if ( !(unsigned __int8)CDataMgr::ConvertRequestStructToUnionStruct(
                                   *((_DWORD *)a2 + 2),
                                   *((_DWORD *)a2 + 3),
                                   &v511) )
          {
            LOBYTE(v806) = 4;
            sub_4E76480(&v511);
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)5;
          v309 = 8117;
          v308 = (HWND)&v511;
          v307 = *(_DWORD *)a2;
          v306 = (HWND)*((_DWORD *)v399 + 203);
          unknown_libname_96(&v797);
          Request::RequestQuoteExGlobal(v306, v307, &v511, 8117, 5);
          LOBYTE(v806) = 4;
          sub_4E76480(&v511);
          goto LABEL_694;
        case 112:
          v621 = (HWND *)*((_DWORD *)a2 + 3);
          if ( !v621 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = 0;
          v309 = (int)"MSQ_FINANCIAL_SB";
          v308 = (HWND)80;
          v307 = 0;
          v306 = 0;
          v305 = v621[1];
          v304 = *v621;
          v303 = *(HWND *)a2;
          v189 = (Request *)unknown_libname_96(&v797);
          Request::RequestMsgFinZdyData(v189, (int)v303, (int)v304, (int)v305, 0, 0, 80, "MSQ_FINANCIAL_SB", 0);
          goto LABEL_694;
        case 113:
          v622 = (int *)*((_DWORD *)a2 + 3);
          if ( !v622 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)76;
          v309 = (int)"MSQ_IPO_SB";
          v308 = (HWND)v622[1];
          v307 = *v622;
          v306 = *(HWND *)a2;
          v188 = (Request *)unknown_libname_96(&v797);
          Request::RequestPinYinData(v188, (int)v306, v307, (int)v308, "MSQ_IPO_SB", 76);
          goto LABEL_694;
        case 114:
        case 129:
          v493 = *((_DWORD *)a2 + 2) == 115;
          v491 = 4 * (*((_DWORD *)a2 + 1) != 0) + 1;
          v492 = *((_DWORD *)a2 + 3);
          v489 = *(_DWORD *)v492;
          v490 = *(_WORD *)(v492 + 4);
          v488 = v491;
          if ( v493 )
            v313 = "REQID_TYPE_HGTED_TREND";
          else
            v313 = "REQID_TYPE_SGTED_TREND";
          v310 = 0;
          v309 = v491;
          v308 = 0;
          v307 = (int)v313;
          v306 = (HWND)(v493 != 0 ? 741 : 747);
          v305 = (HWND)&v488;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4E84BF0(0, (int)v304, &v488, (int)v306, v313, 0, v309, 0);
          goto LABEL_694;
        case 115:
          v736 = (char *)*((_DWORD *)a2 + 3);
          v737 = CDataMgr::ChangeCycleUIToNet(v399, (unsigned __int8)v736[7]);
          if ( v737 > 7 )
            v737 = 7;
          strcpy_s(&v730, 7u, v736);
          v731 = v737;
          v732 = v736[8];
          v733 = *(_DWORD *)(v736 + 9);
          v734 = *(_DWORD *)(v736 + 13);
          v735 = *(_DWORD *)(v736 + 17);
          v310 = 0;
          v309 = 0;
          v308 = 0;
          v307 = (int)"REQ_TYPE_HUGANGTONG_HIS";
          v306 = (HWND)1032;
          v305 = (HWND)&v730;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4E83D40(1, (int)v304, &v730, 1032, "REQ_TYPE_HUGANGTONG_HIS", 0, 0, 0);
          goto LABEL_694;
        case 116:
          sub_4E76510(&v499);
          LOBYTE(v806) = 63;
          sub_4E74C20(&v497);
          v497 = 6;
          v315 = QDataEngine::GetMd5OfSpecialBuffer(&v400, 6, 0);
          v314 = v315;
          LOBYTE(v806) = 64;
          v291 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(v315);
          strcpy_s(&v498, 0x21u, v291);
          LOBYTE(v806) = 63;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v400);
          sub_4DEF8D0(&v497);
          v310 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestBufferList(&v499, v310);
          LOBYTE(v806) = 4;
          sub_4E76540(&v499);
          goto LABEL_694;
        case 117:
          v487 = *((_DWORD *)a2 + 3);
          v486 = *(_DWORD *)(v487 + 27);
          v484 = *(_DWORD *)(v487 + 19);
          v485 = *(_DWORD *)(v487 + 23);
          v483 = *(_BYTE *)(v487 + 18);
          v482 = 7;
          v480 = *(_BYTE *)v487;
          strcpy_s(&v481, 7u, (const char *)(v487 + 1));
          v310 = 0;
          v309 = 0;
          v308 = 0;
          v307 = (int)"REQ_TYPE_MARGIN_TRADE_DAY";
          v306 = (HWND)1031;
          v305 = (HWND)&v480;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4E84EE0(1, (int)v304, &v480, 1031, "REQ_TYPE_MARGIN_TRADE_DAY", 0, 0, 0);
          goto LABEL_694;
        case 118:
          v479 = *((_DWORD *)a2 + 3);
          v478 = *(_DWORD *)(v479 + 34);
          v476 = *(_DWORD *)(v479 + 26);
          v477 = *(_DWORD *)(v479 + 30);
          v475 = *(_BYTE *)(v479 + 25);
          v474 = 7;
          v472 = *(_BYTE *)v479;
          strcpy_s(&v473, 0x17u, (const char *)(v479 + 1));
          v310 = 0;
          v309 = 0;
          v308 = 0;
          v307 = (int)"REQ_TYPE_INDEX_STAT_DAY";
          v306 = (HWND)1035;
          v305 = (HWND)&v472;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4E851D0(1, (int)v304, &v472, 1035, "REQ_TYPE_INDEX_STAT_DAY", 0, 0, 0);
          goto LABEL_694;
        case 120:
          sub_50A3360(*(_DWORD *)a2);
          goto LABEL_694;
        case 126:
          v469 = *(_DWORD *)((char *)v399 + 41);
          v471 = v469 % 100;
          v469 /= 100;
          v467 = v469 % 100;
          v469 /= 100;
          v470 = v469 % 100;
          v468 = 0;
          v292 = QDataEngine::GetAppCurVersionType();
          if ( v292 == 3 )
          {
            v468 = -7;
          }
          else
          {
            v292 = QDataEngine::GetAppCurVersionType();
            if ( v292 == 1 )
            {
              v468 = -5;
            }
            else
            {
              v292 = QDataEngine::GetAppCurVersionType();
              if ( v292 == 6 )
              {
                v468 = -11;
              }
              else
              {
                v292 = CDataMgr::GetL2StandardLogonRight(v399);
                if ( v292 == 1 )
                {
                  v468 = -8;
                  v312 = -8;
                }
                else
                {
                  v468 = -5;
                  v292 = -5;
                  v312 = -5;
                }
              }
            }
          }
          v310 = 0;
          v309 = 2;
          v293 = a2;
          v294 = *(HWND *)a2;
          v308 = *(HWND *)a2;
          LOBYTE(v292) = v471;
          v307 = v292;
          LOBYTE(v293) = v467;
          v305 = (HWND)v293;
          LOBYTE(v294) = v470;
          v304 = v294;
          v303 = (HWND)v468;
          v295 = (Request *)unknown_libname_96(&v797);
          Request::InitLogin(
            v295,
            0,
            QDataEngine::m_LogonInfo,
            aLovezfmeDfcf20,
            (int)v303,
            (char)v304,
            (char)v305,
            0,
            v307,
            (int)v308,
            2,
            0);
          goto LABEL_694;
        case 130:
          v729 = (const char *)*((_DWORD *)a2 + 3);
          sub_4E74C40(&v726);
          strcpy_s(&v728, 0x10u, v729 + 1);
          v727 = *(unsigned __int8 *)v729;
          v310 = 0;
          v309 = 0;
          v308 = 0;
          v307 = (int)"REQID_TYPE_HIS_STATISTICS";
          v306 = (HWND)1040;
          v305 = (HWND)&v726;
          v304 = *(HWND *)a2;
          unknown_libname_96(&v797);
          sub_4EC09F0(1, (int)v304, &v726, 1040, "REQID_TYPE_HIS_STATISTICS", 0, 0, 0);
          goto LABEL_694;
        case 133:
          v310 = (HWND)777;
          v309 = 0;
          v308 = *(HWND *)a2;
          v296 = (Request *)unknown_libname_96(&v797);
          Request::RequestEmptyBodyData(v296, (int)v308, 0, 777);
          goto LABEL_694;
        case 138:
          v503 = (_DWORD *)*((_DWORD *)a2 + 3);
          if ( !v503 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4E765A0(&v504);
          LOBYTE(v806) = 61;
          sub_4EA0EF0(&v500);
          while ( 1 )
          {
            v288 = sub_4DCC7B0(v503, (int)&v402);
            if ( !(unsigned __int8)sub_4DAB600(v288) )
              break;
            v501 = *(_WORD *)sub_4E87B30(&v500);
            v289 = (_DWORD *)sub_4E87B30(&v500);
            v317 = QDataEngine::GetMd5OfSpecialBuffer(&v401, 0, *v289);
            v316 = v317;
            LOBYTE(v806) = 62;
            v290 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(v317);
            strcpy_s(&v502, 0x21u, v290);
            LOBYTE(v806) = 61;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v401);
            sub_4E765F0(&v501);
            sub_4E76560(&v403, 0);
          }
          v310 = *(HWND *)a2;
          unknown_libname_96(&v797);
          Request::RequestBufferListGss(&v504, v310);
          LOBYTE(v806) = 4;
          sub_4E765D0(&v504);
          break;
        default:
          goto LABEL_691;
      }
    }
    goto LABEL_694;
  }
  if ( v396 <= 777 )
  {
    if ( v396 == 777 )
    {
      v695 = *((_DWORD *)a2 + 3);
      CDataMgr::m_GBApplyData = *(_DWORD *)v695;
      byte_51F8D40 = *(_BYTE *)(v695 + 4);
      mfc80xU_774(&unk_51F8D41, v695 + 5);
      mfc80xU_774(&unk_51F8D45, v695 + 9);
      CDataMgr::m_hGBReqWnd = *(_DWORD *)a2;
      if ( CDataMgr::m_nGBEvent )
      {
        KillTimer(0, CDataMgr::m_nGBEvent);
        CDataMgr::m_nGBEvent = 0;
      }
      CDataMgr::m_nGBEvent = SetTimer(0, 0, 0x3E8u, CDataMgr::OnGBRequestTimer);
    }
    else
    {
      v396 -= 512;
      switch ( v396 )
      {
        case 0:
          v21 = a2;
          v788 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)601;
          v309 = 1;
          LOBYTE(v21) = *v788;
          v308 = (HWND)v21;
          v307 = *(_DWORD *)a2;
          v22 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v22, v307, (char)v308, 1, 601);
          goto LABEL_694;
        case 1:
          v23 = a2;
          v787 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v787 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)602;
          v309 = 1;
          LOBYTE(v23) = *v787;
          v308 = (HWND)v23;
          v307 = *(_DWORD *)a2;
          v24 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v24, v307, (char)v308, 1, 602);
          goto LABEL_694;
        case 2:
          v685 = *((_DWORD *)a2 + 3);
          if ( !v685 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7550(&v684);
          LOBYTE(v806) = 25;
          sub_4DD7550(&v683);
          LOBYTE(v806) = 26;
          for ( m = 0; ; ++m )
          {
            v115 = sub_4E90A60(v685 + 8);
            if ( m >= v115 )
              break;
            v116 = (_BYTE *)sub_4E756D0(m);
            LOBYTE(v116) = *v116;
            v310 = (HWND)v116;
            v117 = sub_4E756D0(m);
            v681 = sub_50EF6C0((char *)(v117 + 1), (char)v310);
            if ( *(_BYTE *)sub_4E756D0(m) == 90 )
              sub_4DD7580(&v681);
            else
              sub_4DD7580(&v681);
          }
          if ( sub_4DD2EA0(&v684) )
          {
            v310 = 0;
            v309 = 603;
            v308 = (HWND)1;
            v307 = (int)&v684;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v684, 1, 603, 0);
          }
          if ( sub_4DD2EA0(&v683) )
          {
            v310 = 0;
            v309 = 610;
            v308 = (HWND)1;
            v307 = (int)&v683;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v683, 1, 610, 0);
          }
          LOBYTE(v806) = 25;
          sub_4DE6AF0(&v683);
          LOBYTE(v806) = 4;
          sub_4DE6AF0(&v684);
          goto LABEL_694;
        case 3:
          v680 = (_DWORD *)*((_DWORD *)a2 + 3);
          if ( !v680 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          sub_4DD7550(&v679);
          LOBYTE(v806) = 27;
          sub_4DD7550(&v678);
          LOBYTE(v806) = 28;
          for ( n = 0; ; ++n )
          {
            v118 = sub_4E90A60(v680 + 2);
            if ( n >= v118 )
              break;
            LOBYTE(v119) = *(_BYTE *)sub_4E756D0(n);
            v310 = v119;
            v120 = sub_4E756D0(n);
            v676 = sub_50EF6C0((char *)(v120 + 1), (char)v310);
            if ( *(_BYTE *)sub_4E756D0(n) == 90 )
              sub_4DD7580(&v676);
            else
              sub_4DD7580(&v676);
          }
          if ( sub_4DD2EA0(&v679) )
          {
            v310 = (HWND)(v680[1] + 10000 * *v680);
            v309 = 604;
            v308 = (HWND)1;
            v307 = (int)&v679;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v679, 1, 604, v310);
          }
          if ( sub_4DD2EA0(&v678) )
          {
            v310 = (HWND)(v680[1] + 10000 * *v680);
            v309 = 611;
            v308 = (HWND)1;
            v307 = (int)&v678;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v678, 1, 611, v310);
          }
          LOBYTE(v806) = 27;
          sub_4DE6AF0(&v678);
          LOBYTE(v806) = 4;
          sub_4DE6AF0(&v679);
          goto LABEL_694;
        case 4:
          v672 = *((_DWORD *)a2 + 3);
          mfc80xU_310(&v671);
          LOBYTE(v806) = 30;
          mfc80xU_2313(&v671, "BK%04d", *(_DWORD *)(v672 + 4));
          v126 = (char *)mfc80xU_872(&v671);
          v673 = sub_50EF6C0(v126, 90);
          v310 = 0;
          v309 = 607;
          v308 = (HWND)1;
          v307 = v673;
          v306 = *(HWND *)a2;
          v127 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkStkList(v127, (int)v306, v307, 1, 607, 0);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v671);
          goto LABEL_694;
        case 5:
          v669 = *((_DWORD *)a2 + 3);
          mfc80xU_310(&v668);
          LOBYTE(v806) = 31;
          mfc80xU_2313(&v668, "BK%04d", *(_DWORD *)(v669 + 4));
          v128 = (char *)mfc80xU_872(&v668);
          v670 = sub_50EF6C0(v128, 90);
          v310 = 0;
          v309 = 608;
          v308 = (HWND)1;
          v307 = v670;
          v306 = *(HWND *)a2;
          v129 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkStkList(v129, (int)v306, v307, 1, 608, 0);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v668);
          goto LABEL_694;
        case 6:
          v658 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)317;
          v309 = 1;
          v308 = (HWND)mfc80xU_2461(v658 + 1);
          LOBYTE(v136) = *v658;
          v307 = v136;
          v306 = *(HWND *)a2;
          v137 = (Request *)unknown_libname_96(&v797);
          Request::RequestMaincapflowSingle(v137, (int)v306, v307, (LPCWSTR)v308, 1, 317);
          goto LABEL_694;
        case 7:
          v146 = a2;
          v648 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)605;
          v309 = 1;
          LOBYTE(v146) = *v648;
          v308 = (HWND)v146;
          v307 = *(_DWORD *)a2;
          v147 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkMoneyFlow(v147, v307, (char)v308, 1, 605);
          goto LABEL_694;
        case 8:
          v148 = a2;
          v647 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)606;
          v309 = 1;
          LOBYTE(v148) = *v647;
          v308 = (HWND)v148;
          v307 = *(_DWORD *)a2;
          v149 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v149, v307, (char)v308, 1, 606);
          goto LABEL_694;
        case 9:
          v643 = (unsigned __int8 *)*((_DWORD *)a2 + 3);
          v310 = (HWND)335;
          v309 = *v643;
          v308 = *(HWND *)a2;
          v156 = (Request *)unknown_libname_96(&v797);
          Request::RequestAllInDuBkCp(v156, (int)v308, v309, 335);
          goto LABEL_694;
        case 18:
          v150 = a2;
          v646 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)627;
          v309 = 1;
          LOBYTE(v150) = *v646;
          v308 = (HWND)v150;
          v307 = *(_DWORD *)a2;
          v151 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v151, v307, (char)v308, 1, 627);
          goto LABEL_694;
        case 19:
          v152 = a2;
          v645 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)628;
          v309 = 1;
          LOBYTE(v152) = *v645;
          v308 = (HWND)v152;
          v307 = *(_DWORD *)a2;
          v153 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v153, v307, (char)v308, 1, 628);
          goto LABEL_694;
        case 20:
          v154 = a2;
          v644 = (_BYTE *)*((_DWORD *)a2 + 3);
          v310 = (HWND)629;
          v309 = 1;
          LOBYTE(v154) = *v644;
          v308 = (HWND)v154;
          v307 = *(_DWORD *)a2;
          v155 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v155, v307, (char)v308, 1, 629);
          goto LABEL_694;
        case 21:
          v666 = *((_DWORD *)a2 + 3);
          mfc80xU_310(&v665);
          LOBYTE(v806) = 32;
          mfc80xU_2313(&v665, "BK%04d", *(_DWORD *)(v666 + 4));
          v130 = (char *)mfc80xU_872(&v665);
          v667 = sub_50EF6C0(v130, 90);
          v310 = 0;
          v309 = 630;
          v308 = (HWND)1;
          v307 = v667;
          v306 = *(HWND *)a2;
          v131 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkStkList(v131, (int)v306, v307, 1, 630, 0);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v665);
          goto LABEL_694;
        case 22:
          v663 = *((_DWORD *)a2 + 3);
          mfc80xU_310(&v662);
          LOBYTE(v806) = 33;
          mfc80xU_2313(&v662, "BK%04d", *(_DWORD *)(v663 + 4));
          v132 = (char *)mfc80xU_872(&v662);
          v664 = sub_50EF6C0(v132, 90);
          v310 = 0;
          v309 = 631;
          v308 = (HWND)1;
          v307 = v664;
          v306 = *(HWND *)a2;
          v133 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkStkList(v133, (int)v306, v307, 1, 631, 0);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v662);
          goto LABEL_694;
        case 23:
          v660 = *((_DWORD *)a2 + 3);
          mfc80xU_310(&v659);
          LOBYTE(v806) = 34;
          mfc80xU_2313(&v659, "BK%04d", *(_DWORD *)(v660 + 4));
          v134 = (char *)mfc80xU_872(&v659);
          v661 = sub_50EF6C0(v134, 90);
          v310 = 0;
          v309 = 632;
          v308 = (HWND)1;
          v307 = v661;
          v306 = *(HWND *)a2;
          v135 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushBkStkList(v135, (int)v306, v307, 1, 632, 0);
          LOBYTE(v806) = 4;
          mfc80xU_578(&v659);
          goto LABEL_694;
        case 24:
          v25 = a2;
          v786 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v786 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)633;
          v309 = 1;
          LOBYTE(v25) = *v786;
          v308 = (HWND)v25;
          v307 = *(_DWORD *)a2;
          v26 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v26, v307, (char)v308, 1, 633);
          goto LABEL_694;
        case 25:
          v27 = a2;
          v785 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v785 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)634;
          v309 = 1;
          LOBYTE(v27) = *v785;
          v308 = (HWND)v27;
          v307 = *(_DWORD *)a2;
          v28 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v28, v307, (char)v308, 1, 634);
          goto LABEL_694;
        case 32:
          v29 = a2;
          v784 = (_BYTE *)*((_DWORD *)a2 + 3);
          if ( !v784 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v310 = (HWND)635;
          v309 = 1;
          LOBYTE(v29) = *v784;
          v308 = (HWND)v29;
          v307 = *(_DWORD *)a2;
          v30 = (Request *)unknown_libname_96(&v797);
          Request::RequestPushMoneyFlow(v30, v307, (char)v308, 1, 635);
          break;
        default:
          goto LABEL_691;
      }
    }
    goto LABEL_694;
  }
  if ( v396 > 1793 )
  {
    if ( v396 > 1797 )
    {
      if ( v396 <= 1813 )
      {
        if ( v396 == 1813 )
        {
LABEL_418:
          v603 = (HWND *)*((_DWORD *)a2 + 3);
          if ( !v603 || (unsigned int)sub_4E90A60(v603 + 2) < 1 )
          {
            LOBYTE(v806) = 0;
            sub_4E8C780(&v797);
            v806 = -1;
            sub_4E8C780(&v805);
            return;
          }
          v596 = 0;
          mfc80xU_293(&v598);
          LOBYTE(v806) = 37;
          mfc80xU_293(&v594);
          LOBYTE(v806) = 38;
          sub_4DD7550(&v599);
          LOBYTE(v806) = 39;
          sub_4DD7550(&v595);
          LOBYTE(v806) = 40;
          sub_4E90350(&v604);
          LOBYTE(v806) = 41;
          sub_4E90350(&v605);
          LOBYTE(v806) = 42;
          sub_4E90350(&v602);
          LOBYTE(v806) = 43;
          for ( ii = 0; ; ++ii )
          {
            v211 = sub_4E90A60(v603 + 2);
            if ( ii >= v211 )
              break;
            v592 = (char *)sub_4E756D0(ii);
            if ( CDataMgr::IsGssMarket(v399, *v592) )
            {
              if ( *v592 != 116 || (unsigned __int8)sub_502EF90(1000, (char *)v399 + 1226) )
                sub_4D82520(v592);
              else
                sub_4D82520(v592);
            }
            else if ( *v592 != 1 && *v592 && *v592 != 8 && !(unsigned __int8)sub_4DB2170(*v592) )
            {
              if ( *(_BYTE *)sub_4E756D0(ii) == 90 )
              {
                v596 = sub_50EF6C0(v592 + 1, *v592);
                v421 = v596;
                sub_4DD7580(&v421);
              }
              else
              {
                v591 = 0;
                sub_4D8E430(v592 + 1, (int)&v591);
                if ( (unsigned __int8)mfc80xU_3927(&v598) )
                {
                  v310 = (HWND)v591;
                  v309 = (unsigned __int8)*v592;
                  mfc80xU_2311(&v598, (const char *)L"%d.%s,", v309, v591);
                }
                else
                {
                  mfc80xU_774(&v594, &v598);
                  v310 = (HWND)v591;
                  v309 = (unsigned __int8)*v592;
                  v308 = v594;
                  mfc80xU_2311(&v598, (const char *)L"%s%d.%s,", v594, v309, v591);
                }
                if ( v591 )
                {
                  v420 = v591;
                  mfc80xU_266(v591);
                  v591 = 0;
                }
              }
            }
            else
            {
              v596 = sub_50EF6C0(v592 + 1, *v592);
              v422 = v596;
              sub_4DD7580(&v422);
            }
          }
          v600 = 0;
          memset(&v601, 0, 0x1FEu);
          LightLogger::CLogger::GetLogger(&v597, L"Req FavStkList");
          LOBYTE(v806) = 44;
          v310 = *(HWND *)a2;
          v309 = (int)v603[1];
          v308 = *v603;
          sub_4D8E590(&v600, L"req type:%d,SequenceType:%d SequenceIndex:%d containId:%ld", *((_DWORD *)a2 + 2));
          v212 = (LightLogger::CLogger *)unknown_libname_96(&v597);
          LightLogger::CLogger::WriteLogLine(v212, &v600, 10000);
          if ( sub_4DD2EA0(&v599) )
          {
            if ( *((_DWORD *)a2 + 2) == 1809 )
            {
              v310 = v603[1] + 2500 * (_DWORD)*v603;
              v309 = 720;
              v308 = (HWND)1;
              v307 = (int)&v599;
              v306 = *(HWND *)a2;
              unknown_libname_96(&v797);
              Request::RequestPushQuoteFav(v306, &v599, 1, 720, v310);
            }
            else
            {
              v310 = v603[1] + 2500 * (_DWORD)*v603;
              v309 = 733;
              v308 = (HWND)1;
              v307 = (int)&v599;
              v306 = *(HWND *)a2;
              v305 = (HWND)*((_DWORD *)v399 + 203);
              unknown_libname_96(&v797);
              Request::RequestPushQuoteFavMuti(v305, v306, &v599, 1, 733, v310);
              sub_4DD7580(a2);
            }
          }
          if ( sub_4DD2EA0(&v595) )
          {
            v310 = v603[1] + 2500 * (_DWORD)*v603;
            v309 = 724;
            v308 = (HWND)1;
            v307 = (int)&v595;
            v306 = *(HWND *)a2;
            unknown_libname_96(&v797);
            Request::RequestPushQuoteFav(v306, &v595, 1, 724, v310);
          }
          if ( !(unsigned __int8)sub_4E756B0(&v602) )
          {
            if ( (signed int)*v603 < 0 )
              *v603 = 0;
            if ( (signed int)v603[1] < 0 )
              v603[1] = 0;
            if ( (unsigned __int8)sub_502EF90(1000, (char *)v399 + 1226) )
            {
              v590 = 1;
              v320 = 1;
            }
            else
            {
              v590 = 5;
              v320 = 5;
            }
            v310 = (HWND)8116;
            v309 = 6;
            v308 = v603[1] + 2500 * (_DWORD)*v603 + 2500000;
            v307 = 1;
            v306 = (HWND)&v602;
            v305 = *(HWND *)a2;
            v304 = (HWND)*((_DWORD *)v399 + 203);
            unknown_libname_96(&v797);
            Request::RequestPushGssFavQuoteTable(v304, v305, &v602, 1, v308, 6, 8116);
          }
          if ( sub_4E90A60(&v604) )
          {
            v310 = (HWND)8110;
            v309 = 1;
            v308 = v603[1] + 2500 * (_DWORD)*v603;
            v307 = 1;
            v306 = (HWND)&v604;
            v305 = *(HWND *)a2;
            v304 = (HWND)*((_DWORD *)v399 + 203);
            unknown_libname_96(&v797);
            Request::RequestPushGssFavQuoteTable(v304, v305, &v604, 1, v308, 1, 8110);
          }
          if ( !(unsigned __int8)sub_4E756B0(&v605) )
          {
            v310 = (HWND)8110;
            v309 = 1;
            v308 = v603[1] + 2500 * (_DWORD)*v603;
            v307 = 5;
            v306 = (HWND)&v605;
            v305 = *(HWND *)a2;
            v304 = (HWND)*((_DWORD *)v399 + 203);
            unknown_libname_96(&v797);
            Request::RequestPushGssFavQuoteTable(v304, v305, &v605, 5, v308, 1, 8110);
          }
          if ( !(unsigned __int8)mfc80xU_3927(&v598) )
          {
            *(_BYTE *)(*(_DWORD *)((char *)v399 + 37) + 194) = 1;
            *(_WORD *)(*(_DWORD *)((char *)v399 + 37) + 192) = 6;
            *(_DWORD *)(*(_DWORD *)((char *)v399 + 37) + 188) = *(_DWORD *)a2;
            v213 = (const wchar_t *)mfc80xU_2461(&v598);
            wcscpy_s((wchar_t *)(*(_DWORD *)((char *)v399 + 37) + 196), 0x1388u, v213);
            v310 = HWND_MESSAGE|0x2;
            mfc80xU_5398(&v598);
          }
          LOBYTE(v806) = 43;
          sub_4E8C780(&v597);
          LOBYTE(v806) = 42;
          sub_4E02D30(&v602);
          LOBYTE(v806) = 41;
          sub_4E02D30(&v605);
          LOBYTE(v806) = 40;
          sub_4E02D30(&v604);
          LOBYTE(v806) = 39;
          sub_4DE6AF0(&v595);
          LOBYTE(v806) = 38;
          sub_4DE6AF0(&v599);
          LOBYTE(v806) = 37;
          mfc80xU_577(&v594);
          LOBYTE(v806) = 4;
          mfc80xU_577(&v598);
        }
        else
        {
          v396 -= 1798;
          switch ( v396 )
          {
            case 0:
              v616 = (int *)*((_DWORD *)a2 + 3);
              v310 = (HWND)v616[1];
              v309 = *v616;
              v308 = *(HWND *)a2;
              v196 = (Request *)unknown_libname_96(&v797);
              Request::RequestImportantIndex(v196, (int)v308, v309, (int)v310);
              goto LABEL_694;
            case 1:
              if ( !*((_DWORD *)a2 + 1) )
              {
                LOBYTE(v806) = 0;
                sub_4E8C780(&v797);
                v806 = -1;
                sub_4E8C780(&v805);
                return;
              }
              v693 = (int *)*((_DWORD *)a2 + 3);
              v107 = v693;
              v694 = v693[1];
              if ( !v693 )
              {
                LOBYTE(v806) = 0;
                sub_4E8C780(&v797);
                v806 = -1;
                sub_4E8C780(&v805);
                return;
              }
              switch ( *v693 )
              {
                case 19:
                  v310 = (HWND)5;
                  LOBYTE(v107) = v694;
                  v309 = (int)v107;
                  v308 = *(HWND *)a2;
                  v307 = *((_DWORD *)v399 + 203);
                  v108 = (Request *)unknown_libname_96(&v797);
                  Request::RequestPushGssQuoteTable(v108, v307, (int)v308, v309, 5);
                  break;
                case 24:
                  CDataMgr::RequestPushGssClassQuote(v399, *(_DWORD *)a2, v694, 5, 0);
                  break;
                case 20:
                  sub_4E74C00(&v689);
                  v689 = 5;
                  v691 = *(HWND *)a2;
                  v690 = *((_DWORD *)v399 + 203);
                  sprintf_s(&DstBuf, 0x10u, "MK%04d", v693[1]);
                  v310 = 0;
                  v309 = 0;
                  v308 = 0;
                  v307 = (int)"REQID_TYPE_GSS_QUOTE_TABLE";
                  v306 = (HWND)8110;
                  v305 = (HWND)&v689;
                  v304 = *(HWND *)a2;
                  unknown_libname_96(&v797);
                  sub_4E84030(4, (int)v304, &v689, 8110, "REQID_TYPE_GSS_QUOTE_TABLE", 0, 0, 0);
                  break;
                default:
                  if ( v694 == 39
                    || v694 == 27
                    || v694 == 41
                    || v694 == 51
                    || v694 == 52
                    || v694 == 53
                    || v694 == 61
                    || v694 == 62
                    || v694 == 63
                    || v694 == 64
                    || v694 == 65
                    || v694 == 66
                    || v694 == 67 )
                  {
                    CDataMgr::ApplyPushStkList(v399, *(_DWORD *)a2, *v693, v693[1], *((_DWORD *)a2 + 1));
                  }
                  else
                  {
                    v310 = (HWND)721;
                    v309 = 5;
                    v308 = (HWND)v693[1];
                    v307 = *v693;
                    v306 = *(HWND *)a2;
                    v109 = (Request *)unknown_libname_96(&v797);
                    Request::RequestPushQuoteList(v109, (int)v306, v307, (int)v308, 5, 721);
                  }
                  break;
              }
              goto LABEL_694;
            case 2:
              v144 = a2;
              v649 = (_BYTE *)*((_DWORD *)a2 + 3);
              if ( !v649 )
              {
                LOBYTE(v806) = 0;
                sub_4E8C780(&v797);
                v806 = -1;
                sub_4E8C780(&v805);
                return;
              }
              v310 = (HWND)370;
              v309 = 1;
              LOBYTE(v144) = *v649;
              v308 = (HWND)v144;
              v307 = *(_DWORD *)a2;
              v145 = (Request *)unknown_libname_96(&v797);
              Request::RequestPushMainMoneyDetail(v145, v307, (char)v308, 1, 370);
              goto LABEL_694;
            case 3:
              v688 = (_DWORD *)*((_DWORD *)a2 + 3);
              if ( !v688 )
              {
                LOBYTE(v806) = 0;
                sub_4E8C780(&v797);
                v806 = -1;
                sub_4E8C780(&v805);
                return;
              }
              EnterCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 314));
              if ( *((_DWORD *)v399 + 201) == *v688 && sub_4DD2EA0((char *)v399 + 740) )
              {
                v310 = (HWND)a2;
                v112 = (HWND *)sub_4DCC7B0((_DWORD *)v399 + 185, (int)&v437);
                v309 = (int)v112[1];
                v308 = *v112;
                v113 = (_DWORD *)sub_4EA0EF0(&v436);
                sub_4DC2CA0(&v687, *v113, v113[1], (char)v308, v309, a2);
                v114 = sub_4DCC7B0((_DWORD *)v399 + 185, (int)&v435);
                if ( (unsigned __int8)sub_4DACFF0(v114) )
                {
                  sub_4DD7580(a2);
                  CDataMgr::SendMsgToUI(v399, *(HWND *)a2, 0x709u);
                }
              }
              else
              {
                *((_DWORD *)v399 + 201) = *v688;
                sub_4EC8200((char *)v399 + 740);
                sub_4DD7580(a2);
                v310 = (HWND)722;
                v309 = 1;
                LOBYTE(v110) = *(_BYTE *)v688;
                v308 = v110;
                v111 = (Request *)unknown_libname_96(&v797);
                Request::RequestPushBkList(v111, 0, (char)v308, 1, 722);
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 314));
              goto LABEL_694;
            case 10:
              if ( !*((_DWORD *)a2 + 1) )
              {
                LOBYTE(v806) = 0;
                sub_4E8C780(&v797);
                v806 = -1;
                sub_4E8C780(&v805);
                return;
              }
              CDataMgr::RequestBkStkQuoteTable(v399, *((_DWORD *)a2 + 3), 5, *(_DWORD *)a2);
              break;
            case 11:
              goto LABEL_418;
            default:
              goto LABEL_691;
          }
        }
        goto LABEL_694;
      }
      if ( v396 == 8208 )
      {
        v642 = *((_DWORD *)a2 + 3);
        v310 = (HWND)336;
        v309 = *(unsigned __int8 *)(v642 + 4);
        v308 = *(HWND *)v642;
        v307 = *(_DWORD *)a2;
        v157 = (Request *)unknown_libname_96(&v797);
        Request::RequestSingelBkCp(v157, v307, (int)v308, v309, 336);
        goto LABEL_694;
      }
      if ( v396 == 8209 )
      {
        v650 = (_BYTE *)*((_DWORD *)a2 + 3);
        if ( (unsigned __int8)sub_4E6F980(v650 + 1, &unk_5154280) )
        {
          LOBYTE(v806) = 0;
          sub_4E8C780(&v797);
          v806 = -1;
          sub_4E8C780(&v805);
          return;
        }
        EnterCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 242));
        v652 = 0;
        v653 = 0;
        v654 = 0;
        v655 = 0;
        v656 = 0;
        v657 = 0;
        lpString = (LPCWSTR)mfc80xU_870(v650 + 1);
        if ( lpString )
        {
          v804 = lstrlenW(lpString) + 1;
          if ( v804 <= 0x3FFFFFFF )
          {
            v138 = alloca(2 * v804);
            v322 = (LPSTR)&v311;
            v323 = (char *)sub_4D98AA0((LPSTR)&v311, lpString, 2 * v804, 0);
          }
          else
          {
            v323 = 0;
          }
          v324 = v323;
        }
        else
        {
          v324 = 0;
        }
        strcpy_s(&v652, 0x10u, v324);
        if ( stricmp((const char *)v399 + 682, &v652) )
        {
          strcpy_s((char *)v399 + 682, 0x10u, &v652);
          sub_4EC8200((char *)v399 + 649);
        }
        v310 = (HWND)a2;
        v139 = (HWND *)sub_4DCC7B0((CDataMgr *)((char *)v399 + 649), (int)&v432);
        v309 = (int)v139[1];
        v308 = *v139;
        v140 = (_DWORD *)sub_4EA0EF0(&v431);
        sub_4DC2CA0(&v651, *v140, v140[1], (char)v308, v309, a2);
        v141 = sub_4DCC7B0((CDataMgr *)((char *)v399 + 649), (int)&v430);
        if ( (unsigned __int8)sub_4DAB600(v141) )
        {
          LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 242));
          LOBYTE(v806) = 0;
          sub_4E8C780(&v797);
          v806 = -1;
          sub_4E8C780(&v805);
          return;
        }
        sub_4DD7580(a2);
        v310 = (HWND)808;
        v309 = 1;
        v142 = mfc80xU_870(v650 + 1);
        v308 = (HWND)v142;
        LOBYTE(v142) = *v650;
        v307 = v142;
        v143 = (Request *)unknown_libname_96(&v797);
        Request::RequestT0AndMoneyFlow(v143, 0, v307, (LPCWSTR)v308, 1, 808);
        LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v399 + 242));
        goto LABEL_694;
      }
    }
    else
    {
      if ( v396 == 1797 )
      {
        HIWORD(v31) = HIWORD(a2);
        v783 = (char *)*((_DWORD *)a2 + 3);
        if ( !v783 )
        {
          LOBYTE(v806) = 0;
          sub_4E8C780(&v797);
          v806 = -1;
          sub_4E8C780(&v805);
          return;
        }
        v310 = (HWND)186;
        LOWORD(v31) = *v783;
        v309 = v31;
        v308 = *(HWND *)a2;
        v32 = (Request *)unknown_libname_96(&v797);
        Request::RequestQuoteStockTable(v32, (int)v308, v309, 186);
        goto LABEL_694;
      }
      if ( v396 == 1794 )
      {
        v686 = *((_DWORD *)a2 + 3);
        v310 = (HWND)13;
        v309 = v686;
        v434 = &v309;
        v330 = mfc80xU_280(&v309, v686);
        v308 = *(HWND *)a2;
        unknown_libname_96(&v797);
        Request::RequestQuoteFavorite(v308, v309, v310);
        goto LABEL_694;
      }
    }
  }
  else
  {
    if ( v396 == 1793 )
    {
      HIWORD(v19) = HIWORD(a2);
      v789 = (char *)*((_DWORD *)a2 + 3);
      v310 = (HWND)323;
      LOWORD(v19) = *v789;
      v309 = v19;
      v308 = *(HWND *)a2;
      v20 = (Request *)unknown_libname_96(&v797);
      Request::RequestQuoteStockTable(v20, (int)v308, v309, 323);
      goto LABEL_694;
    }
    if ( v396 > 1027 )
    {
      if ( v396 == 1282 )
      {
LABEL_369:
        v624 = (HWND *)*((_DWORD *)a2 + 3);
        v625 = 0;
        v321 = *((_DWORD *)a2 + 2);
        if ( v321 <= 1282 )
        {
          if ( v321 == 1282 )
          {
            v625 = 5;
            v310 = 0;
            v309 = (int)"Financial_Data_Querier_ForFree";
            v308 = (HWND)3;
            v307 = 5;
            v306 = v624[2];
            v305 = v624[1];
            v304 = *v624;
            v303 = *(HWND *)a2;
            v184 = (Request *)unknown_libname_96(&v797);
            Request::RequestMsgFinData(
              v184,
              (int)v303,
              (int)v304,
              (int)v305,
              (int)v306,
              5,
              3,
              "Financial_Data_Querier_ForFree",
              0);
          }
          else
          {
            v321 -= 32;
            switch ( v321 )
            {
              case 0:
                v310 = 0;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = (HWND)55;
                v307 = v625;
                v306 = v624[2];
                v305 = v624[1];
                v304 = *v624;
                v303 = *(HWND *)a2;
                v173 = (Request *)unknown_libname_96(&v797);
                Request::RequestMsgFinData(
                  v173,
                  (int)v303,
                  (int)v304,
                  (int)v305,
                  (int)v306,
                  v307,
                  55,
                  "Financial_Data_Querier_ForFree",
                  0);
                break;
              case 1:
                v310 = (HWND)"Financial_Data_Querier_ForFree";
                v309 = (int)v624[1];
                v308 = *v624;
                v307 = *(_DWORD *)a2;
                v174 = (Request *)unknown_libname_96(&v797);
                Request::RequestCQCXData(v174, v307, (int)v308, v309, "Financial_Data_Querier_ForFree");
                break;
              case 2:
                v310 = 0;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = (HWND)4;
                v307 = v625;
                v306 = v624[2];
                v305 = v624[1];
                v304 = *v624;
                v303 = *(HWND *)a2;
                v175 = (Request *)unknown_libname_96(&v797);
                Request::RequestMsgFinData(
                  v175,
                  (int)v303,
                  (int)v304,
                  (int)v305,
                  (int)v306,
                  v307,
                  4,
                  "Financial_Data_Querier_ForFree",
                  0);
                break;
              case 3:
                v625 = 3;
                v310 = (HWND)67;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v182 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v182, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 67);
                break;
              case 39:
                v310 = (HWND)26;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v183 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v183, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 26);
                break;
              case 62:
                v310 = (HWND)42;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v176 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v176, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 42);
                break;
              case 64:
                v310 = (HWND)71;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v179 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v179, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 71);
                break;
              case 70:
                v310 = 0;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = (HWND)70;
                v307 = v625;
                v306 = v624[2];
                v305 = v624[1];
                v304 = *v624;
                v303 = *(HWND *)a2;
                v177 = (Request *)unknown_libname_96(&v797);
                Request::RequestMsgFinData(
                  v177,
                  (int)v303,
                  (int)v304,
                  (int)v305,
                  (int)v306,
                  v307,
                  70,
                  "Financial_Data_Querier_ForFree",
                  0);
                break;
              case 74:
                v310 = (HWND)58;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v181 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v181, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 58);
                break;
              case 75:
                v310 = (HWND)59;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v180 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v180, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 59);
                break;
              case 76:
                v310 = (HWND)66;
                v309 = (int)"Financial_Data_Querier_ForFree";
                v308 = v624[1];
                v307 = (int)*v624;
                v306 = *(HWND *)a2;
                v185 = (Request *)unknown_libname_96(&v797);
                Request::RequestPinYinData(v185, (int)v306, v307, (int)v308, "Financial_Data_Querier_ForFree", 66);
                break;
              case 77:
                v310 = (HWND)"CQCX_GSS";
                v309 = (int)v624[1];
                v308 = *v624;
                v307 = *(_DWORD *)a2;
                v186 = (Request *)unknown_libname_96(&v797);
                Request::RequestCQCXGssData(v186, v307, (int)v308, v309, "CQCX_GSS");
                break;
              case 103:
                v310 = 0;
                v309 = (int)"MSQ_MG_BK_LIST";
                v308 = (HWND)81;
                v307 = v625;
                v306 = v624[2];
                v305 = v624[1];
                v304 = *v624;
                v303 = *(HWND *)a2;
                v178 = (Request *)unknown_libname_96(&v797);
                Request::RequestMsgFinData(
                  v178,
                  (int)v303,
                  (int)v304,
                  (int)v305,
                  (int)v306,
                  v307,
                  81,
                  "MSQ_MG_BK_LIST",
                  0);
                break;
              default:
                goto LABEL_694;
            }
          }
        }
        goto LABEL_694;
      }
    }
    else
    {
      switch ( v396 )
      {
        case 1027:
          v617 = *((_DWORD *)a2 + 3);
          v310 = (HWND)"News_Info_Querier_ForFree";
          v309 = 7;
          v308 = (HWND)1;
          v307 = 0;
          v306 = *(HWND *)(v617 + 21);
          v194 = *(HWND *)(v617 + 17);
          v305 = *(HWND *)(v617 + 17);
          v304 = (HWND)(v617 + 1);
          LOBYTE(v194) = *(_BYTE *)v617;
          v303 = v194;
          v302 = *(HWND *)a2;
          v195 = (Request *)unknown_libname_96(&v797);
          Request::RequestReportStk(
            v195,
            (int)v302,
            (char)v303,
            (char *)v304,
            (int)v305,
            (int)v306,
            0,
            1,
            7,
            "News_Info_Querier_ForFree");
          goto LABEL_694;
        case 1025:
          v618 = (HWND *)*((_DWORD *)a2 + 3);
          v310 = (HWND)"News_Info_Querier_ForFree";
          v309 = 6;
          v308 = (HWND)103;
          v307 = (int)v618[1];
          v306 = *v618;
          v305 = *(HWND *)a2;
          v192 = (Request *)unknown_libname_96(&v797);
          Request::RequestReportHomeData(v192, (int)v305, (int)v306, v307, 103, 6, "News_Info_Querier_ForFree");
          goto LABEL_694;
        case 1026:
          v310 = (HWND)"News_Info_Querier_ForFree";
          v309 = 8;
          v308 = (HWND)1;
          v307 = *(_DWORD *)a2;
          v193 = (Request *)unknown_libname_96(&v797);
          Request::RequestReportHome2Data(v193, v307, 1, 8, "News_Info_Querier_ForFree");
          goto LABEL_694;
      }
    }
  }
LABEL_691:
  if ( !*((_DWORD *)a2 + 1) )
  {
    LOBYTE(v806) = 0;
    sub_4E8C780(&v797);
    v806 = -1;
    sub_4E8C780(&v805);
    return;
  }
  v310 = *(HWND *)a2;
  v309 = *((_DWORD *)a2 + 3);
  v308 = (HWND)5;
  v307 = *((_DWORD *)a2 + 2);
  v297 = *(_DWORD *)((char *)v399 + 1106);
  sub_5114DA0(v307, 5, v309, v310);
LABEL_694:
  LOBYTE(v806) = 0;
  sub_4E8C780(&v797);
  v806 = -1;
  sub_4E8C780(&v805);
}