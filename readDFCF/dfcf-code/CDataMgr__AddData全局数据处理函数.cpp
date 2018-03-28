void __thiscall CDataMgr::AddData(CDataMgr *this, char **a2)
{
  LightLogger::CLogger *v2; // eax
  LightLogger::CLogger *v3; // eax
  int v4; // eax
  const WCHAR *v5; // eax
  LightLogger::CLogger *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  void *v10; // esp
  LightLogger::CLogger *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  LightLogger::CLogger *v18; // eax
  void *v19; // esp
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  wchar_t *v26; // eax
  int v27; // eax
  int v28; // eax
  char v29; // al
  LightLogger::CLogger *v30; // eax
  LightLogger::CLogger *v31; // eax
  LightLogger::CLogger *v32; // eax
  LightLogger::CLogger *v33; // eax
  int v34; // eax
  LightLogger::CLogger *v35; // eax
  LightLogger::CLogger *v36; // eax
  LightLogger::CLogger *v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  wchar_t *v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  LightLogger::CLogger *v47; // eax
  void *v48; // esp
  const WCHAR *v49; // eax
  int v50; // eax
  const CHAR *v51; // eax
  const WCHAR *v52; // eax
  const WCHAR *v53; // eax
  int v54; // eax
  int v55; // eax
  void *v56; // esp
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // eax
  wchar_t *v63; // eax
  int v64; // eax
  int v65; // eax
  char v66; // al
  LightLogger::CLogger *v67; // eax
  LightLogger::CLogger *v68; // eax
  int v69; // eax
  LightLogger::CLogger *v70; // eax
  int v71; // ecx
  void *v72; // esp
  const WCHAR *v73; // eax
  int v74; // eax
  const CHAR *v75; // eax
  const WCHAR *v76; // eax
  const WCHAR *v77; // eax
  CViewManager *v78; // eax
  HWND v79; // eax
  unsigned int v80; // eax
  int v81; // eax
  HWND v82; // eax
  unsigned int v83; // eax
  int v84; // eax
  HWND v85; // eax
  unsigned int v86; // eax
  int v87; // eax
  HWND v88; // eax
  unsigned int v89; // eax
  int v90; // eax
  HWND v91; // eax
  int v92; // eax
  int v93; // eax
  HWND *v94; // eax
  HWND v95; // eax
  HWND v96; // eax
  unsigned int v97; // eax
  int v98; // eax
  HWND v99; // eax
  unsigned int v100; // eax
  int v101; // eax
  HWND v102; // eax
  HWND v103; // eax
  unsigned int v104; // eax
  int v105; // eax
  HWND v106; // eax
  unsigned int v107; // eax
  int v108; // eax
  HWND v109; // eax
  unsigned int v110; // eax
  int v111; // eax
  HWND v112; // eax
  unsigned int v113; // eax
  int v114; // eax
  HWND v115; // eax
  HWND v116; // eax
  struct MainCapFlowShowDetailClientPaid *v117; // eax
  HWND v118; // eax
  struct MainCapFlowShowDetailClientPaid *v119; // eax
  HWND v120; // eax
  struct MainCapFlowShowDetailClientPaid *v121; // eax
  HWND v122; // eax
  struct MainCapFlowShowDetailClientPaid *v123; // eax
  HWND v124; // eax
  int v125; // eax
  int v126; // eax
  _BYTE *v127; // eax
  int v128; // eax
  int v129; // eax
  int v130; // eax
  int v131; // eax
  int v132; // eax
  int v133; // eax
  int v134; // eax
  int v135; // eax
  _BYTE *v136; // eax
  int v137; // eax
  int v138; // eax
  int v139; // eax
  int v140; // eax
  int v141; // eax
  int v142; // eax
  int v143; // eax
  int v144; // eax
  _BYTE *v145; // eax
  int v146; // eax
  int v147; // eax
  int v148; // eax
  int v149; // eax
  int v150; // eax
  int v151; // eax
  int v152; // eax
  int v153; // eax
  _BYTE *v154; // eax
  int v155; // eax
  int v156; // eax
  int v157; // eax
  int v158; // eax
  struct DAYDATA *v159; // eax
  int v160; // eax
  int v161; // eax
  int v162; // eax
  HWND v163; // eax
  int v164; // eax
  int v165; // eax
  int v166; // eax
  int v167; // eax
  int v168; // eax
  int v169; // eax
  int v170; // eax
  int v171; // eax
  int v172; // eax
  int v173; // eax
  _BYTE *v174; // eax
  int v175; // eax
  int v176; // eax
  int v177; // eax
  int v178; // eax
  int v179; // eax
  int v180; // eax
  int v181; // eax
  int v182; // eax
  int v183; // eax
  int v184; // eax
  int v185; // eax
  int v186; // eax
  int v187; // eax
  int v188; // eax
  int v189; // eax
  int v190; // eax
  int v191; // eax
  int v192; // eax
  int v193; // eax
  int v194; // eax
  int v195; // eax
  int v196; // eax
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v197; // ecx
  int v198; // eax
  int v199; // eax
  int v200; // eax
  int v201; // eax
  const wchar_t *v202; // eax
  const wchar_t *v203; // eax
  const wchar_t *v204; // eax
  LightLogger::CLogger *v205; // eax
  int v206; // ecx
  int v207; // eax
  int v208; // eax
  HWND *v209; // eax
  int v210; // eax
  int v211; // eax
  int v212; // eax
  int nCurDateByMarket; // eax
  int v214; // eax
  int v215; // eax
  int v216; // eax
  int v217; // eax
  HWND *v218; // eax
  int v219; // eax
  int v220; // eax
  HWND *v221; // eax
  int v222; // ecx
  int v223; // ecx
  float v224; // ecx
  int v225; // eax
  _BYTE *v226; // eax
  int v227; // eax
  int v228; // eax
  int v229; // eax
  int v230; // eax
  int v231; // eax
  int v232; // eax
  unsigned int v233; // eax
  int v234; // eax
  HWND *v235; // eax
  unsigned int v236; // eax
  int v237; // eax
  HWND *v238; // eax
  int v239; // eax
  int v240; // eax
  int v241; // eax
  int v242; // eax
  Request *v243; // eax
  LightLogger::CLogger *v244; // eax
  HWND v245; // eax
  HWND v246; // eax
  HWND v247; // eax
  int v248; // eax
  _DWORD *v249; // eax
  int v250; // eax
  int v251; // ecx
  int v252; // eax
  int v253; // eax
  int v254; // eax
  int v255; // eax
  int v256; // ecx
  CViewManager *v257; // eax
  int v258; // ecx
  int v259; // ecx
  int v260; // eax
  _BYTE *v261; // eax
  int v262; // eax
  int v263; // eax
  int v264; // eax
  int v265; // eax
  int v266; // eax
  int v267; // eax
  int v268; // eax
  int v269; // eax
  int v270; // eax
  int v271; // ecx
  int v272; // eax
  _DWORD *v273; // eax
  int v274; // eax
  int v275; // eax
  int v276; // ecx
  LightLogger::CLogger *v277; // eax
  const char *v278; // eax
  int v279; // ecx
  double v280; // [esp+8h] [ebp-27CCh]
  float v281; // [esp+10h] [ebp-27C4h]
  int *v282; // [esp+14h] [ebp-27C0h]
  char *v283; // [esp+18h] [ebp-27BCh]
  int v284; // [esp+1Ch] [ebp-27B8h]
  int v285; // [esp+20h] [ebp-27B4h]
  WCHAR *v286; // [esp+24h] [ebp-27B0h]
  UINT v287; // [esp+28h] [ebp-27ACh]
  int v288; // [esp+2Ch] [ebp-27A8h]
  int v289; // [esp+30h] [ebp-27A4h]
  int v290; // [esp+34h] [ebp-27A0h]
  int v291; // [esp+38h] [ebp-279Ch]
  int v292; // [esp+3Ch] [ebp-2798h]
  int v293; // [esp+40h] [ebp-2794h]
  int v294; // [esp+44h] [ebp-2790h]
  int v295; // [esp+48h] [ebp-278Ch]
  char v296; // [esp+4Ch] [ebp-2788h]
  int v297; // [esp+50h] [ebp-2784h]
  int v298; // [esp+54h] [ebp-2780h]
  int v299; // [esp+58h] [ebp-277Ch]
  int v300; // [esp+5Ch] [ebp-2778h]
  int v301; // [esp+60h] [ebp-2774h]
  int v302; // [esp+64h] [ebp-2770h]
  LPARAM v303; // [esp+68h] [ebp-276Ch]
  int v304; // [esp+6Ch] [ebp-2768h]
  int v305; // [esp+74h] [ebp-2760h]
  int v306; // [esp+78h] [ebp-275Ch]
  int v307; // [esp+7Ch] [ebp-2758h]
  int v308; // [esp+80h] [ebp-2754h]
  int v309; // [esp+84h] [ebp-2750h]
  int v310; // [esp+88h] [ebp-274Ch]
  int v311; // [esp+8Ch] [ebp-2748h]
  int v312; // [esp+90h] [ebp-2744h]
  int v313; // [esp+94h] [ebp-2740h]
  int v314; // [esp+98h] [ebp-273Ch]
  int v315; // [esp+9Ch] [ebp-2738h]
  int v316; // [esp+A0h] [ebp-2734h]
  int v317; // [esp+A4h] [ebp-2730h]
  int v318; // [esp+A8h] [ebp-272Ch]
  int v319; // [esp+ACh] [ebp-2728h]
  int v320; // [esp+B0h] [ebp-2724h]
  int v321; // [esp+B4h] [ebp-2720h]
  int v322; // [esp+B8h] [ebp-271Ch]
  int *v323; // [esp+BCh] [ebp-2718h]
  int *v324; // [esp+C0h] [ebp-2714h]
  int v325; // [esp+C4h] [ebp-2710h]
  int v326; // [esp+C8h] [ebp-270Ch]
  int v327; // [esp+CCh] [ebp-2708h]
  int v328; // [esp+D0h] [ebp-2704h]
  int v329; // [esp+D4h] [ebp-2700h]
  int v330; // [esp+D8h] [ebp-26FCh]
  int v331; // [esp+DCh] [ebp-26F8h]
  int v332; // [esp+E0h] [ebp-26F4h]
  int v333; // [esp+E4h] [ebp-26F0h]
  int v334; // [esp+E8h] [ebp-26ECh]
  int v335; // [esp+ECh] [ebp-26E8h]
  int v336; // [esp+F0h] [ebp-26E4h]
  int v337; // [esp+F4h] [ebp-26E0h]
  int v338; // [esp+F8h] [ebp-26DCh]
  int v339; // [esp+FCh] [ebp-26D8h]
  int v340; // [esp+100h] [ebp-26D4h]
  int v341; // [esp+104h] [ebp-26D0h]
  int v342; // [esp+108h] [ebp-26CCh]
  int v343; // [esp+10Ch] [ebp-26C8h]
  int v344; // [esp+110h] [ebp-26C4h]
  int v345; // [esp+114h] [ebp-26C0h]
  int v346; // [esp+118h] [ebp-26BCh]
  int v347; // [esp+11Ch] [ebp-26B8h]
  int v348; // [esp+120h] [ebp-26B4h]
  int v349; // [esp+124h] [ebp-26B0h]
  int v350; // [esp+128h] [ebp-26ACh]
  LPWSTR v351; // [esp+12Ch] [ebp-26A8h]
  int v352; // [esp+130h] [ebp-26A4h]
  int v353; // [esp+134h] [ebp-26A0h]
  int v354; // [esp+138h] [ebp-269Ch]
  int v355; // [esp+13Ch] [ebp-2698h]
  int v356; // [esp+140h] [ebp-2694h]
  LPWSTR v357; // [esp+144h] [ebp-2690h]
  int v358; // [esp+148h] [ebp-268Ch]
  int v359; // [esp+14Ch] [ebp-2688h]
  int v360; // [esp+150h] [ebp-2684h]
  int v361; // [esp+154h] [ebp-2680h]
  LPWSTR v362; // [esp+158h] [ebp-267Ch]
  int v363; // [esp+15Ch] [ebp-2678h]
  int v364; // [esp+160h] [ebp-2674h]
  int v365; // [esp+164h] [ebp-2670h]
  int v366; // [esp+168h] [ebp-266Ch]
  int v367; // [esp+16Ch] [ebp-2668h]
  int v368; // [esp+170h] [ebp-2664h]
  int v369; // [esp+174h] [ebp-2660h]
  int v370; // [esp+178h] [ebp-265Ch]
  LPWSTR v371; // [esp+17Ch] [ebp-2658h]
  int v372; // [esp+180h] [ebp-2654h]
  int v373; // [esp+184h] [ebp-2650h]
  int v374; // [esp+188h] [ebp-264Ch]
  int v375; // [esp+18Ch] [ebp-2648h]
  LPWSTR lpWideCharStr; // [esp+190h] [ebp-2644h]
  int v377; // [esp+194h] [ebp-2640h]
  int v378; // [esp+198h] [ebp-263Ch]
  int v379; // [esp+19Ch] [ebp-2638h]
  int v380; // [esp+1A0h] [ebp-2634h]
  int v381; // [esp+1A4h] [ebp-2630h]
  int v382; // [esp+1A8h] [ebp-262Ch]
  CDataMgr *this; // [esp+1ACh] [ebp-2628h]
  char v384; // [esp+1B0h] [ebp-2624h]
  int *v385; // [esp+1CCh] [ebp-2608h]
  int v386; // [esp+1D0h] [ebp-2604h]
  int v387; // [esp+1D4h] [ebp-2600h]
  int *v388; // [esp+1D8h] [ebp-25FCh]
  int v389; // [esp+1DCh] [ebp-25F8h]
  int v390; // [esp+1E0h] [ebp-25F4h]
  int *v391; // [esp+1E4h] [ebp-25F0h]
  void *v392; // [esp+1E8h] [ebp-25ECh]
  void *v393; // [esp+1ECh] [ebp-25E8h]
  int v394; // [esp+1F0h] [ebp-25E4h]
  int v395; // [esp+1F4h] [ebp-25E0h]
  int *v396; // [esp+1F8h] [ebp-25DCh]
  int v397; // [esp+1FCh] [ebp-25D8h]
  int v398; // [esp+200h] [ebp-25D4h]
  LPARAM v399; // [esp+204h] [ebp-25D0h]
  LPARAM v400; // [esp+208h] [ebp-25CCh]
  LPARAM v401; // [esp+20Ch] [ebp-25C8h]
  LPARAM v402; // [esp+210h] [ebp-25C4h]
  int v403; // [esp+214h] [ebp-25C0h]
  LPARAM v404; // [esp+218h] [ebp-25BCh]
  char v405; // [esp+21Ch] [ebp-25B8h]
  int v406; // [esp+220h] [ebp-25B4h]
  int v407; // [esp+224h] [ebp-25B0h]
  void *v408; // [esp+228h] [ebp-25ACh]
  double *v409; // [esp+22Ch] [ebp-25A8h]
  void *v410; // [esp+230h] [ebp-25A4h]
  int v411; // [esp+234h] [ebp-25A0h]
  int v412; // [esp+238h] [ebp-259Ch]
  int v413; // [esp+23Ch] [ebp-2598h]
  int v414; // [esp+240h] [ebp-2594h]
  int *v415; // [esp+244h] [ebp-2590h]
  int *v416; // [esp+248h] [ebp-258Ch]
  int *v417; // [esp+24Ch] [ebp-2588h]
  int *v418; // [esp+250h] [ebp-2584h]
  int *v419; // [esp+254h] [ebp-2580h]
  int v420; // [esp+258h] [ebp-257Ch]
  int v421; // [esp+25Ch] [ebp-2578h]
  struct DETAILREC *v422; // [esp+260h] [ebp-2574h]
  struct DETAILREC *v423; // [esp+264h] [ebp-2570h]
  struct DETAILREC *v424; // [esp+268h] [ebp-256Ch]
  char v425; // [esp+26Ch] [ebp-2568h]
  char v426; // [esp+274h] [ebp-2560h]
  char v427; // [esp+27Ch] [ebp-2558h]
  int **v428; // [esp+284h] [ebp-2550h]
  double *v429; // [esp+288h] [ebp-254Ch]
  char v430; // [esp+28Ch] [ebp-2548h]
  char v431; // [esp+290h] [ebp-2544h]
  char v432; // [esp+294h] [ebp-2540h]
  char v433; // [esp+298h] [ebp-253Ch]
  int v434; // [esp+29Ch] [ebp-2538h]
  int v435; // [esp+2A0h] [ebp-2534h]
  int v436; // [esp+2A4h] [ebp-2530h]
  int v437; // [esp+2A8h] [ebp-252Ch]
  int v438; // [esp+2ACh] [ebp-2528h]
  int v439; // [esp+2B0h] [ebp-2524h]
  int v440; // [esp+2B4h] [ebp-2520h]
  int v441; // [esp+2B8h] [ebp-251Ch]
  int v442; // [esp+2BCh] [ebp-2518h]
  int v443; // [esp+2C0h] [ebp-2514h]
  int v444; // [esp+2C4h] [ebp-2510h]
  int v445; // [esp+2C8h] [ebp-250Ch]
  int v446; // [esp+2CCh] [ebp-2508h]
  int v447; // [esp+2D0h] [ebp-2504h]
  int v448; // [esp+2D4h] [ebp-2500h]
  int v449; // [esp+2D8h] [ebp-24FCh]
  int v450; // [esp+2DCh] [ebp-24F8h]
  int v451; // [esp+2E0h] [ebp-24F4h]
  int v452; // [esp+2E4h] [ebp-24F0h]
  int v453; // [esp+2E8h] [ebp-24ECh]
  int v454; // [esp+2ECh] [ebp-24E8h]
  int v455; // [esp+2F0h] [ebp-24E4h]
  int v456; // [esp+2F4h] [ebp-24E0h]
  int v457; // [esp+2F8h] [ebp-24DCh]
  char v458; // [esp+2FCh] [ebp-24D8h]
  char v459; // [esp+304h] [ebp-24D0h]
  char v460; // [esp+30Ch] [ebp-24C8h]
  int *v461; // [esp+314h] [ebp-24C0h]
  char v462; // [esp+318h] [ebp-24BCh]
  int *v463; // [esp+39Ch] [ebp-2438h]
  int v464; // [esp+3A0h] [ebp-2434h]
  int v465; // [esp+3A4h] [ebp-2430h]
  int v466; // [esp+3A8h] [ebp-242Ch]
  int v467; // [esp+3ACh] [ebp-2428h]
  char v468; // [esp+3B0h] [ebp-2424h]
  int v469; // [esp+434h] [ebp-23A0h]
  int v470; // [esp+438h] [ebp-239Ch]
  int v471; // [esp+43Ch] [ebp-2398h]
  int v472; // [esp+440h] [ebp-2394h]
  int v473; // [esp+444h] [ebp-2390h]
  int v474; // [esp+448h] [ebp-238Ch]
  int v475; // [esp+44Ch] [ebp-2388h]
  int v476; // [esp+450h] [ebp-2384h]
  int v477; // [esp+454h] [ebp-2380h]
  int v478; // [esp+458h] [ebp-237Ch]
  char v479; // [esp+45Ch] [ebp-2378h]
  int i6; // [esp+460h] [ebp-2374h]
  _DWORD *v481; // [esp+464h] [ebp-2370h]
  int i5; // [esp+468h] [ebp-236Ch]
  int v483; // [esp+46Ch] [ebp-2368h]
  int v484; // [esp+470h] [ebp-2364h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v485; // [esp+474h] [ebp-2360h]
  int v486; // [esp+478h] [ebp-235Ch]
  int v487; // [esp+47Ch] [ebp-2358h]
  WCHAR v488; // [esp+480h] [ebp-2354h]
  char v489; // [esp+580h] [ebp-2254h]
  int v490; // [esp+584h] [ebp-2250h]
  char Dst; // [esp+588h] [ebp-224Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v492; // [esp+5A8h] [ebp-222Ch]
  int i4; // [esp+5ACh] [ebp-2228h]
  char v494; // [esp+5B0h] [ebp-2224h]
  int v495; // [esp+5B4h] [ebp-2220h]
  int v496; // [esp+5B8h] [ebp-221Ch]
  int v497; // [esp+5BCh] [ebp-2218h]
  int v498; // [esp+5C0h] [ebp-2214h]
  int v499; // [esp+5C4h] [ebp-2210h]
  int v500; // [esp+5C8h] [ebp-220Ch]
  int v501; // [esp+5CCh] [ebp-2208h]
  int v502; // [esp+5D0h] [ebp-2204h]
  int v503; // [esp+5D4h] [ebp-2200h]
  __int16 v504; // [esp+5D8h] [ebp-21FCh]
  int v505; // [esp+5DCh] [ebp-21F8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v506; // [esp+5E0h] [ebp-21F4h]
  char v507; // [esp+5E4h] [ebp-21F0h]
  int v508; // [esp+5F4h] [ebp-21E0h]
  int v509; // [esp+5F8h] [ebp-21DCh]
  int v510; // [esp+5FCh] [ebp-21D8h]
  int i2; // [esp+600h] [ebp-21D4h]
  bool v512; // [esp+604h] [ebp-21D0h]
  int v513; // [esp+608h] [ebp-21CCh]
  int v514; // [esp+60Ch] [ebp-21C8h]
  int v515; // [esp+610h] [ebp-21C4h]
  int v516; // [esp+614h] [ebp-21C0h]
  int v517; // [esp+618h] [ebp-21BCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v518; // [esp+61Ch] [ebp-21B8h]
  char v519; // [esp+620h] [ebp-21B4h]
  struct STK_PER *v520; // [esp+624h] [ebp-21B0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v521; // [esp+628h] [ebp-21ACh]
  struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *v522; // [esp+62Ch] [ebp-21A8h]
  int v523; // [esp+630h] [ebp-21A4h]
  int v524; // [esp+634h] [ebp-21A0h]
  struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *v525; // [esp+638h] [ebp-219Ch]
  struct _MSG_RET_QUOTE_EX_GLOBAL_MARKET *v526; // [esp+63Ch] [ebp-2198h]
  struct MSG_RET_GSS_STK_DETAIL *v527; // [esp+640h] [ebp-2194h]
  struct _MSG_RET_QUOTE_HQ_GLOBAL_MARKET *v528; // [esp+644h] [ebp-2190h]
  struct _MSG_RET_QUOTE_MINKLINE_GLOBAL_MARKET *v529; // [esp+648h] [ebp-218Ch]
  struct _MSG_RET_QUOTE_RT_GLOBAL_MARKET *v530; // [esp+64Ch] [ebp-2188h]
  struct MSG_RET_GSS_STK_LIST *v531; // [esp+650h] [ebp-2184h]
  struct MSG_RET_NLEVEL_ORDER_QUEUE *v532; // [esp+654h] [ebp-2180h]
  struct MSG_RET_MULTI_L2_QUOTE *v533; // [esp+658h] [ebp-217Ch]
  struct MSG_RET_MULTI_L2_QUOTE *v534; // [esp+65Ch] [ebp-2178h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v535; // [esp+660h] [ebp-2174h]
  int v536; // [esp+667h] [ebp-216Dh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v537; // [esp+66Ch] [ebp-2168h]
  CHAR MultiByteStr; // [esp+670h] [ebp-2164h]
  int v539; // [esp+671h] [ebp-2163h]
  int v540; // [esp+675h] [ebp-215Fh]
  int v541; // [esp+679h] [ebp-215Bh]
  __int16 v542; // [esp+67Dh] [ebp-2157h]
  char v543; // [esp+67Fh] [ebp-2155h]
  struct MSG_RET_HIS_TRENDLINE_CFS *v544; // [esp+680h] [ebp-2154h]
  struct MSG_RET_HIS_TRENDLINE *v545; // [esp+684h] [ebp-2150h]
  struct MSG_RET_TRENDLINE *v546; // [esp+688h] [ebp-214Ch]
  struct MSG_RET_TRENDLINE *v547; // [esp+68Ch] [ebp-2148h]
  int v548; // [esp+690h] [ebp-2144h]
  int v549; // [esp+718h] [ebp-20BCh]
  int v550; // [esp+7A0h] [ebp-2034h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v551; // [esp+830h] [ebp-1FA4h]
  int v552; // [esp+834h] [ebp-1FA0h]
  signed __int16 *v553; // [esp+838h] [ebp-1F9Ch]
  void *v554; // [esp+83Ch] [ebp-1F98h]
  signed __int16 *v555; // [esp+840h] [ebp-1F94h]
  char v556; // [esp+844h] [ebp-1F90h]
  char v557; // [esp+848h] [ebp-1F8Ch]
  char v558; // [esp+867h] [ebp-1F6Dh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v559; // [esp+868h] [ebp-1F6Ch]
  char v560; // [esp+86Fh] [ebp-1F65h]
  char v561; // [esp+870h] [ebp-1F64h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v562; // [esp+874h] [ebp-1F60h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v563; // [esp+878h] [ebp-1F5Ch]
  int v564; // [esp+87Ch] [ebp-1F58h]
  unsigned int v565; // [esp+880h] [ebp-1F54h]
  struct MSG_RET_FAV_QUOTE_LIST *v566; // [esp+884h] [ebp-1F50h]
  struct MSG_RET_STKS_DDE_LIST *v567; // [esp+888h] [ebp-1F4Ch]
  int v568; // [esp+88Ch] [ebp-1F48h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v569; // [esp+890h] [ebp-1F44h]
  char v570; // [esp+894h] [ebp-1F40h]
  wchar_t v571; // [esp+898h] [ebp-1F3Ch]
  char v572; // [esp+89Ah] [ebp-1F3Ah]
  char v573; // [esp+998h] [ebp-1E3Ch]
  int v574; // [esp+99Ch] [ebp-1E38h]
  LPARAM v575; // [esp+9A0h] [ebp-1E34h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v576; // [esp+9A4h] [ebp-1E30h]
  char v577[4]; // [esp+9A8h] [ebp-1E2Ch]
  LPARAM v578; // [esp+9ACh] [ebp-1E28h]
  unsigned int i8; // [esp+9B0h] [ebp-1E24h]
  LPARAM v580; // [esp+9B4h] [ebp-1E20h]
  unsigned int i7; // [esp+9B8h] [ebp-1E1Ch]
  char v582; // [esp+9BCh] [ebp-1E18h]
  char v583; // [esp+9C0h] [ebp-1E14h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *pIsGLOBAL_HIS_TRENDLINE; // [esp+9C4h] [ebp-1E10h]
  char v585[5]; // [esp+9CBh] [ebp-1E09h]
  char v586; // [esp+9D0h] [ebp-1E04h]
  int v587; // [esp+9D1h] [ebp-1E03h]
  int v588; // [esp+9D5h] [ebp-1DFFh]
  int v589; // [esp+9D9h] [ebp-1DFBh]
  __int16 v590; // [esp+9DDh] [ebp-1DF7h]
  char v591; // [esp+9DFh] [ebp-1DF5h]
  float i12; // [esp+9E0h] [ebp-1DF4h]
  int v593; // [esp+9E4h] [ebp-1DF0h]
  int v594; // [esp+9E8h] [ebp-1DECh]
  int v595; // [esp+9ECh] [ebp-1DE8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v596; // [esp+9F0h] [ebp-1DE4h]
  int v597; // [esp+9F4h] [ebp-1DE0h]
  void *v598; // [esp+9F8h] [ebp-1DDCh]
  int v599; // [esp+9FCh] [ebp-1DD8h]
  int v600; // [esp+A00h] [ebp-1DD4h]
  int v601; // [esp+A1Ch] [ebp-1DB8h]
  char v602; // [esp+A20h] [ebp-1DB4h]
  LPARAM v603; // [esp+A24h] [ebp-1DB0h]
  char v604; // [esp+A28h] [ebp-1DACh]
  char v605; // [esp+A2Ch] [ebp-1DA8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v606; // [esp+A30h] [ebp-1DA4h]
  char v607; // [esp+A34h] [ebp-1DA0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v608; // [esp+A38h] [ebp-1D9Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v609; // [esp+A3Ch] [ebp-1D98h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v610; // [esp+A40h] [ebp-1D94h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v611; // [esp+A44h] [ebp-1D90h]
  struct BK_ITEM *v612; // [esp+A48h] [ebp-1D8Ch]
  int i16; // [esp+A4Ch] [ebp-1D88h]
  int v614; // [esp+A50h] [ebp-1D84h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v615; // [esp+A54h] [ebp-1D80h]
  int i; // [esp+A58h] [ebp-1D7Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v617; // [esp+A5Ch] [ebp-1D78h]
  struct _MSG_RET_QUOTE_MINKLINE_GLOBAL_MARKET *v618; // [esp+A60h] [ebp-1D74h]
  struct _MSG_RET_QUOTE_RT_GLOBAL_MARKET *v619; // [esp+A64h] [ebp-1D70h]
  struct MSG_RET_MULTI_L2_QUOTE *pMULTI_L2_QUOTE; // [esp+A68h] [ebp-1D6Ch]
  struct MSG_RET_MULTI_L2_QUOTE *v621; // [esp+A6Ch] [ebp-1D68h]
  struct MSG_RET_TRENDLINE *v622; // [esp+A70h] [ebp-1D64h]
  struct MSG_RET_TRENDLINE *v623; // [esp+A74h] [ebp-1D60h]
  struct MSG_RET_L2QUOTE_RATIOPRICE *v624; // [esp+A78h] [ebp-1D5Ch]
  LPARAM v625; // [esp+A7Ch] [ebp-1D58h]
  int i20; // [esp+A80h] [ebp-1D54h]
  LPARAM v627; // [esp+A84h] [ebp-1D50h]
  int i19; // [esp+A88h] [ebp-1D4Ch]
  char v629; // [esp+A8Ch] [ebp-1D48h]
  char v630; // [esp+A90h] [ebp-1D44h]
  LPARAM v631; // [esp+A94h] [ebp-1D40h]
  char v632[5]; // [esp+A9Bh] [ebp-1D39h]
  char v633; // [esp+AA0h] [ebp-1D34h]
  int v634; // [esp+AA1h] [ebp-1D33h]
  int v635; // [esp+AA5h] [ebp-1D2Fh]
  int v636; // [esp+AA9h] [ebp-1D2Bh]
  __int16 v637; // [esp+AADh] [ebp-1D27h]
  char v638; // [esp+AAFh] [ebp-1D25h]
  struct MSG_RET_L2QUOTE_TRANSACTION *v639; // [esp+AB0h] [ebp-1D24h]
  struct MSG_RET_L2QUOTE_PRICEORDER *v640; // [esp+AB4h] [ebp-1D20h]
  struct MSG_RET_BK_BASIC_INFO *v641; // [esp+AB8h] [ebp-1D1Ch]
  int i25; // [esp+ABCh] [ebp-1D18h]
  char v643; // [esp+AC0h] [ebp-1D14h]
  LPARAM v644; // [esp+BBCh] [ebp-1C18h]
  LPARAM v645; // [esp+BC0h] [ebp-1C14h]
  LPARAM v646; // [esp+BC4h] [ebp-1C10h]
  bool v647; // [esp+BCBh] [ebp-1C09h]
  LPARAM v648; // [esp+BCCh] [ebp-1C08h]
  int i24; // [esp+BD0h] [ebp-1C04h]
  int v650; // [esp+BD4h] [ebp-1C00h]
  int i23; // [esp+BD8h] [ebp-1BFCh]
  int v652; // [esp+BDCh] [ebp-1BF8h]
  struct DETAILREC *v653; // [esp+BE0h] [ebp-1BF4h]
  unsigned int v654; // [esp+BE4h] [ebp-1BF0h]
  unsigned int v655; // [esp+BE8h] [ebp-1BECh]
  int v656; // [esp+BECh] [ebp-1BE8h]
  LPARAM v657; // [esp+BF0h] [ebp-1BE4h]
  unsigned int v658; // [esp+BF4h] [ebp-1BE0h]
  LPARAM v659; // [esp+BF8h] [ebp-1BDCh]
  char v660; // [esp+BFCh] [ebp-1BD8h]
  char v661; // [esp+C04h] [ebp-1BD0h]
  int v662; // [esp+C0Ch] [ebp-1BC8h]
  int v663; // [esp+C10h] [ebp-1BC4h]
  char i22; // [esp+C15h] [ebp-1BBFh]
  char i21; // [esp+C16h] [ebp-1BBEh]
  int v666; // [esp+C17h] [ebp-1BBDh]
  char v667; // [esp+CF8h] [ebp-1ADCh]
  int v668; // [esp+CF9h] [ebp-1ADBh]
  int v669; // [esp+CFDh] [ebp-1AD7h]
  int v670; // [esp+D01h] [ebp-1AD3h]
  __int16 v671; // [esp+D05h] [ebp-1ACFh]
  char v672; // [esp+D07h] [ebp-1ACDh]
  LPARAM v673; // [esp+D08h] [ebp-1ACCh]
  int i18; // [esp+D0Ch] [ebp-1AC8h]
  LPARAM v675; // [esp+D10h] [ebp-1AC4h]
  char v676; // [esp+D14h] [ebp-1AC0h]
  LPARAM v677; // [esp+D18h] [ebp-1ABCh]
  int v678; // [esp+D1Ch] [ebp-1AB8h]
  wchar_t v679; // [esp+D20h] [ebp-1AB4h]
  char v680; // [esp+D22h] [ebp-1AB2h]
  char v681; // [esp+1120h] [ebp-16B4h]
  int v682; // [esp+1124h] [ebp-16B0h]
  int v683; // [esp+112Ch] [ebp-16A8h]
  LPARAM pHIS_TRENDLINE_Data0; // [esp+1130h] [ebp-16A4h]  复合指针，可能有多种不同含义
  int pHIS_TRENDLINE_Data1; // [esp+1138h] [ebp-169Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v686; // [esp+1140h] [ebp-1694h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v687; // [esp+1144h] [ebp-1690h]
  int v688; // [esp+1148h] [ebp-168Ch]
  int v689; // [esp+114Ch] [ebp-1688h]
  char v690; // [esp+1150h] [ebp-1684h]
  char v691; // [esp+1154h] [ebp-1680h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v692; // [esp+1158h] [ebp-167Ch]
  struct MSG_RET_QUOTE_FENJIA *v693; // [esp+115Ch] [ebp-1678h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v694; // [esp+1160h] [ebp-1674h]
  char v695[5]; // [esp+1167h] [ebp-166Dh]
  char v696; // [esp+116Ch] [ebp-1668h]
  int v697; // [esp+116Dh] [ebp-1667h]
  int v698; // [esp+1171h] [ebp-1663h]
  int v699; // [esp+1175h] [ebp-165Fh]
  __int16 v700; // [esp+1179h] [ebp-165Bh]
  char v701; // [esp+117Bh] [ebp-1659h]
  struct MSG_RET_QUOTE_PANKOU *v702; // [esp+117Ch] [ebp-1658h]
  int i17; // [esp+1180h] [ebp-1654h]
  char v704[5]; // [esp+1187h] [ebp-164Dh]
  CHAR v705; // [esp+118Ch] [ebp-1648h]
  int v706; // [esp+118Dh] [ebp-1647h]
  int v707; // [esp+1191h] [ebp-1643h]
  int v708; // [esp+1195h] [ebp-163Fh]
  __int16 v709; // [esp+1199h] [ebp-163Bh]
  char v710; // [esp+119Bh] [ebp-1639h]
  int k; // [esp+119Ch] [ebp-1638h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v712; // [esp+11A0h] [ebp-1634h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v713; // [esp+11A4h] [ebp-1630h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v714; // [esp+11A8h] [ebp-162Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v715; // [esp+11ACh] [ebp-1628h]
  struct MSG_RET_L2QUOTE_PRICEORDER *v716; // [esp+11B0h] [ebp-1624h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v717; // [esp+11B4h] [ebp-1620h]
  struct MSG_RET_FAV_QUOTE_LIST *v718; // [esp+11B8h] [ebp-161Ch]
  struct MSG_RET_QUOTE_PUSH_QUOTETABLE_NEW *v719; // [esp+11BCh] [ebp-1618h]
  int j; // [esp+11C0h] [ebp-1614h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v721; // [esp+11C4h] [ebp-1610h]
  char v722; // [esp+11C8h] [ebp-160Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v723; // [esp+12C0h] [ebp-1514h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v724; // [esp+12C4h] [ebp-1510h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v725; // [esp+12C8h] [ebp-150Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v726; // [esp+12CCh] [ebp-1508h]
  struct MSG_RET_L2QUOTE_RATIOPRICE *v727; // [esp+12D0h] [ebp-1504h]
  char v728; // [esp+12D4h] [ebp-1500h]
  LPARAM v729; // [esp+12D8h] [ebp-14FCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v730; // [esp+12DCh] [ebp-14F8h]
  char v731; // [esp+12E0h] [ebp-14F4h]
  char v732; // [esp+12E4h] [ebp-14F0h]
  char v733; // [esp+12E8h] [ebp-14ECh]
  LPARAM v734; // [esp+12ECh] [ebp-14E8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v735; // [esp+12F0h] [ebp-14E4h]
  char v736; // [esp+12F4h] [ebp-14E0h]
  char v737; // [esp+12F8h] [ebp-14DCh]
  int v738; // [esp+12FCh] [ebp-14D8h]
  int v739; // [esp+1300h] [ebp-14D4h]
  int i11; // [esp+1304h] [ebp-14D0h]
  char v741; // [esp+1308h] [ebp-14CCh]
  char v742; // [esp+1318h] [ebp-14BCh]
  int v743; // [esp+131Ch] [ebp-14B8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v744; // [esp+1320h] [ebp-14B4h]
  char v745; // [esp+1324h] [ebp-14B0h]
  char v746; // [esp+1328h] [ebp-14ACh]
  char v747; // [esp+132Ch] [ebp-14A8h]
  int v748; // [esp+134Ch] [ebp-1488h]
  char v749; // [esp+1350h] [ebp-1484h]
  LPARAM v750; // [esp+1354h] [ebp-1480h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v751; // [esp+1358h] [ebp-147Ch]
  char v752; // [esp+135Ch] [ebp-1478h]
  char v753; // [esp+1360h] [ebp-1474h]
  char v754; // [esp+1364h] [ebp-1470h]
  LPARAM v755; // [esp+1368h] [ebp-146Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v756; // [esp+136Ch] [ebp-1468h]
  char v757; // [esp+1370h] [ebp-1464h]
  char v758; // [esp+1374h] [ebp-1460h]
  char v759; // [esp+1378h] [ebp-145Ch]
  LPARAM v760; // [esp+137Ch] [ebp-1458h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v761; // [esp+1380h] [ebp-1454h]
  char v762; // [esp+1384h] [ebp-1450h]
  char v763; // [esp+1388h] [ebp-144Ch]
  int v764; // [esp+138Ch] [ebp-1448h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v765; // [esp+1390h] [ebp-1444h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v766; // [esp+1394h] [ebp-1440h]
  struct MSG_RET_L2QUOTE_TRANSACTION *v767; // [esp+1398h] [ebp-143Ch]
  int v768; // [esp+139Ch] [ebp-1438h]
  unsigned int v769; // [esp+13A0h] [ebp-1434h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v770; // [esp+13A4h] [ebp-1430h]
  unsigned int v771; // [esp+13A8h] [ebp-142Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v772; // [esp+13ACh] [ebp-1428h]
  unsigned int v773; // [esp+13B0h] [ebp-1424h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v774; // [esp+13B4h] [ebp-1420h]
  int i3; // [esp+13B8h] [ebp-141Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v776; // [esp+13BCh] [ebp-1418h]
  int v777; // [esp+13C0h] [ebp-1414h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v778; // [esp+13C4h] [ebp-1410h]
  char v779; // [esp+13C8h] [ebp-140Ch]
  int v780; // [esp+13D8h] [ebp-13FCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v781; // [esp+13DCh] [ebp-13F8h]
  char v782; // [esp+13E0h] [ebp-13F4h]
  int v783; // [esp+13F0h] [ebp-13E4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v784; // [esp+13F4h] [ebp-13E0h]
  char v785; // [esp+13F8h] [ebp-13DCh]
  int v786; // [esp+1408h] [ebp-13CCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v787; // [esp+140Ch] [ebp-13C8h]
  char v788; // [esp+1410h] [ebp-13C4h]
  unsigned int v789; // [esp+1420h] [ebp-13B4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v790; // [esp+1424h] [ebp-13B0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v791; // [esp+1428h] [ebp-13ACh]
  char v792; // [esp+142Ch] [ebp-13A8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v793; // [esp+143Ch] [ebp-1398h]
  int i15; // [esp+1440h] [ebp-1394h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v795; // [esp+1444h] [ebp-1390h]
  unsigned int ll; // [esp+1448h] [ebp-138Ch]
  int v797; // [esp+144Ch] [ebp-1388h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v798; // [esp+1450h] [ebp-1384h]
  char v799; // [esp+1454h] [ebp-1380h]
  unsigned int kk; // [esp+1464h] [ebp-1370h]
  int v801; // [esp+1468h] [ebp-136Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v802; // [esp+146Ch] [ebp-1368h]
  char v803; // [esp+1470h] [ebp-1364h]
  unsigned int jj; // [esp+1480h] [ebp-1354h]
  int v805; // [esp+1484h] [ebp-1350h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v806; // [esp+1488h] [ebp-134Ch]
  char v807; // [esp+148Ch] [ebp-1348h]
  unsigned int n; // [esp+149Ch] [ebp-1338h]
  int v809; // [esp+14A0h] [ebp-1334h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v810; // [esp+14A4h] [ebp-1330h]
  char v811; // [esp+14A8h] [ebp-132Ch]
  unsigned int v812; // [esp+14B8h] [ebp-131Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v813; // [esp+14BCh] [ebp-1318h]
  unsigned int ii; // [esp+14C0h] [ebp-1314h]
  int v815; // [esp+14C4h] [ebp-1310h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v816; // [esp+14C8h] [ebp-130Ch]
  char v817; // [esp+14CCh] [ebp-1308h]
  unsigned int m; // [esp+14DCh] [ebp-12F8h]
  int v819; // [esp+14E0h] [ebp-12F4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v820; // [esp+14E4h] [ebp-12F0h]
  char v821; // [esp+14E8h] [ebp-12ECh]
  unsigned int v822; // [esp+14F8h] [ebp-12DCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v823; // [esp+14FCh] [ebp-12D8h]
  unsigned int v824; // [esp+1500h] [ebp-12D4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v825; // [esp+1504h] [ebp-12D0h]
  char v826; // [esp+1508h] [ebp-12CCh]
  char v827; // [esp+1510h] [ebp-12C4h]
  int v828; // [esp+1518h] [ebp-12BCh]
  char i10; // [esp+151Dh] [ebp-12B7h]
  char i9; // [esp+151Eh] [ebp-12B6h]
  int v831; // [esp+151Fh] [ebp-12B5h]
  char v832; // [esp+1604h] [ebp-11D0h]
  int v833; // [esp+1605h] [ebp-11CFh]
  int v834; // [esp+1609h] [ebp-11CBh]
  int v835; // [esp+160Dh] [ebp-11C7h]
  __int16 v836; // [esp+1611h] [ebp-11C3h]
  char v837; // [esp+1613h] [ebp-11C1h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v838; // [esp+1614h] [ebp-11C0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v839; // [esp+1618h] [ebp-11BCh]
  int i14; // [esp+161Ch] [ebp-11B8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v841; // [esp+1620h] [ebp-11B4h]
  unsigned int i1; // [esp+1624h] [ebp-11B0h]
  int v843; // [esp+1628h] [ebp-11ACh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v844; // [esp+162Ch] [ebp-11A8h]
  char v845; // [esp+1630h] [ebp-11A4h]
  unsigned int nn; // [esp+1640h] [ebp-1194h]
  int v847; // [esp+1644h] [ebp-1190h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v848; // [esp+1648h] [ebp-118Ch]
  char v849; // [esp+164Ch] [ebp-1188h]
  unsigned int mm; // [esp+165Ch] [ebp-1178h]
  int v851; // [esp+1660h] [ebp-1174h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v852; // [esp+1664h] [ebp-1170h]
  char v853; // [esp+1668h] [ebp-116Ch]
  unsigned int l; // [esp+1678h] [ebp-115Ch]
  int v855; // [esp+167Ch] [ebp-1158h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v856; // [esp+1680h] [ebp-1154h]
  char v857; // [esp+1684h] [ebp-1150h]
  unsigned int v858; // [esp+1694h] [ebp-1140h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v859; // [esp+1698h] [ebp-113Ch]
  int i13; // [esp+169Ch] [ebp-1138h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v861; // [esp+16A0h] [ebp-1134h]
  int v862; // [esp+16A4h] [ebp-1130h]
  int v863; // [esp+16A8h] [ebp-112Ch]
  char v864; // [esp+16ACh] [ebp-1128h]
  char v865; // [esp+16B0h] [ebp-1124h]
  char v866; // [esp+1AB4h] [ebp-D20h]
  char v867; // [esp+1AB8h] [ebp-D1Ch]
  char v868; // [esp+1ABCh] [ebp-D18h]
  char v869; // [esp+1AC0h] [ebp-D14h]
  char v870; // [esp+1AC4h] [ebp-D10h]
  LPARAM v871; // [esp+1AC8h] [ebp-D0Ch]
  LPCSTR v872; // [esp+1ACCh] [ebp-D08h]
  int v873; // [esp+1AD0h] [ebp-D04h]
  int v874; // [esp+1AD8h] [ebp-CFCh]
  char v875; // [esp+1ADCh] [ebp-CF8h]
  LPCSTR v876; // [esp+1AE0h] [ebp-CF4h]
  bool v877; // [esp+1AE7h] [ebp-CEDh]
  int v878; // [esp+1AE8h] [ebp-CECh]
  char v879; // [esp+1AECh] [ebp-CE8h]
  char v880; // [esp+1AF0h] [ebp-CE4h]
  bool v881; // [esp+1AFBh] [ebp-CD9h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v882; // [esp+1AFCh] [ebp-CD8h]
  int v883; // [esp+1B00h] [ebp-CD4h]
  char v884; // [esp+1B04h] [ebp-CD0h]
  int v885; // [esp+1B08h] [ebp-CCCh]
  LPARAM v886; // [esp+1B0Ch] [ebp-CC8h]
  char v887; // [esp+1B10h] [ebp-CC4h]
  char v888; // [esp+1B14h] [ebp-CC0h]
  int v889; // [esp+1B18h] [ebp-CBCh]
  char v890; // [esp+1B1Ch] [ebp-CB8h]
  char v891; // [esp+1B20h] [ebp-CB4h]
  LPARAM v892; // [esp+1B24h] [ebp-CB0h]
  char v893; // [esp+1B28h] [ebp-CACh]
  char v894; // [esp+1B2Ch] [ebp-CA8h]
  char Src; // [esp+1B30h] [ebp-CA4h]
  char v896; // [esp+1F30h] [ebp-8A4h]
  char v897; // [esp+1F34h] [ebp-8A0h]
  char v898; // [esp+1F38h] [ebp-89Ch]
  char v899; // [esp+1F3Ch] [ebp-898h]
  char v900; // [esp+1F40h] [ebp-894h]
  LPARAM lParam; // [esp+1F44h] [ebp-890h]
  char v902; // [esp+1F48h] [ebp-88Ch]
  char v903; // [esp+1F4Ch] [ebp-888h]
  LPCSTR lpMultiByteStr; // [esp+1F50h] [ebp-884h]
  bool v905; // [esp+1F57h] [ebp-87Dh]
  int v906; // [esp+1F58h] [ebp-87Ch]
  char v907; // [esp+1F5Ch] [ebp-878h]
  char v908; // [esp+1F60h] [ebp-874h]
  char v909; // [esp+1F64h] [ebp-870h]
  char v910; // [esp+1F68h] [ebp-86Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v911; // [esp+1F70h] [ebp-864h]
  int v912; // [esp+1F74h] [ebp-860h]
  char v913; // [esp+1F78h] [ebp-85Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v914; // [esp+1F7Ch] [ebp-858h]
  LPCSTR lpString; // [esp+1F80h] [ebp-854h]
  int v916; // [esp+1F84h] [ebp-850h]
  int v917; // [esp+1F88h] [ebp-84Ch]
  int cchWideChar; // [esp+1F90h] [ebp-844h]
  char v919; // [esp+1F94h] [ebp-840h]
  char v920; // [esp+1F98h] [ebp-83Ch]
  char v921; // [esp+1F9Ch] [ebp-838h]
  LPARAM v922; // [esp+1FA0h] [ebp-834h]
  char v923; // [esp+1FA4h] [ebp-830h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v924; // [esp+1FA8h] [ebp-82Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v925; // [esp+1FACh] [ebp-828h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v926; // [esp+1FB0h] [ebp-824h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *pGLOBAL_HIS_TRENDLINE; // [esp+1FB4h] [ebp-820h]
  WCHAR Caption; // [esp+1FB8h] [ebp-81Ch]
  char v929; // [esp+27C0h] [ebp-14h]
  char v930; // [esp+27C4h] [ebp-10h]
  int v931; // [esp+27D0h] [ebp-4h]

  this = this;
  CDataMgr::CheckThreadId(this);
  LightLogger::CLogger::GetLogger(&v930, L"DataRecv");
  v931 = 0;
  if ( *((_BYTE *)this + 494) )
  {
    v2 = (LightLogger::CLogger *)unknown_libname_97(&v930);
    LightLogger::CLogger::WriteLogLine(v2, L"AddData m_bStopRequest==true return.", 20000);
    v931 = -1;
    sub_4E3C780(&v930);
    return;
  }
  if ( QDataEngine::m_bDataReInit )
  {
    v3 = (LightLogger::CLogger *)unknown_libname_97(&v930);
    LightLogger::CLogger::WriteLogLine(v3, L"AddData m_bDataReInit==true return.", 20000);
    v931 = -1;
    sub_4E3C780(&v930);
    return;
  }
  pGLOBAL_HIS_TRENDLINE = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)*a2;
  v4 = sub_509C980(&v479);
  v382 = v4;
  v5 = (const WCHAR *)mfc80xU_870(v4);
  SetCurrentDirectoryW(v5);
  mfc80xU_577(&v479);
  wsprintfW(&Caption, L"Add data %d, len %d", *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2), *(_DWORD *)pGLOBAL_HIS_TRENDLINE);
  v6 = (LightLogger::CLogger *)unknown_libname_97(&v930);
  LightLogger::CLogger::WriteLogLine(v6, &Caption, 20000);
  CGlobalEnv::GetGlobalEnv(&v929);
  LOBYTE(v931) = 1;
  v381 = *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2);
  if ( v381 <= 322 )
  {
    if ( v381 == 322 )
    {
      v617 = pGLOBAL_HIS_TRENDLINE;
      if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
      {
        LOBYTE(v931) = 0;
        sub_4E3C780(&v929);
        v931 = -1;
        sub_4E3C780(&v930);
        return;
      }
      QDataEngine::SaveImportIndexLastDate(*(_DWORD *)((char *)v617 + 17), *(_DWORD *)((char *)v617 + 21));
      for ( i = 0; i < *(_DWORD *)((char *)v617 + 25); ++i )
      {
        QDataEngine::Add_ImportIndexData(
          1,
          (char *)v617 + 52 * i + 29,
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v617 + 52 * i + 29));
        v223 = i + 1;
      }
      v285 = v223;
      v419 = &v285;
      v316 = sub_4D9CB20(0);
      sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x706u, v285);
    }
    else
    {
      v381 -= 2;
      switch ( v381 )
      {
        case 0:
          if ( QDataEngine::GetLoginInStatus() )
          {
            *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 14) = 0;
            CDataMgr::OffLine(this);
            v7 = unknown_libname_97(&v929);
            MessageBoxW(*(HWND *)(v7 + 156), &word_51047BC, &word_51047B0, 0x30u);
            CDataMgr::ShowLogonDlg(this);
          }
          goto LABEL_1068;
        case 8:
          v725 = pGLOBAL_HIS_TRENDLINE;
          if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          QDataEngine::AddIndexSpecialData((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v725 + 17));
          CDataMgr::SendIndexSpToUI(this, *(_DWORD *)((char *)v725 + 6));
          goto LABEL_1068;
        case 11:
          v721 = pGLOBAL_HIS_TRENDLINE;
          sub_4DBA150(&v722);
          for ( j = 0; j < *(signed __int16 *)((char *)v721 + 17); ++j )
          {
            sub_4E35D20(&v722, (char *)v721 + 194 * j + 19);
            QDataEngine::Add_DynamicDataStock(
              *((_BYTE *)v721 + 194 * j + 19),
              (char *)v721 + 194 * j + 24,
              (struct _QUOTEREC *)&v722);
          }
          CDataMgr::SendRecordDataToUI(this, *(HWND *)((char *)v721 + 6), 0x711u);
          goto LABEL_1068;
        case 15:
          v774 = pGLOBAL_HIS_TRENDLINE;
          if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          v773 = *(_DWORD *)((char *)v774 + 49) - *(_DWORD *)((char *)v774 + 53);
          if ( (v773 & 0x80000000) != 0 )
            v773 = 0;
          v285 = *(_DWORD *)((char *)v774 + 17);
          v284 = (int)v774 + 57;
          QDataEngine::Add_DetailData(
            (char *)v774 + 26,
            *((_BYTE *)v774 + 25),
            v773,
            *(_DWORD *)((char *)v774 + 53),
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v774 + 57),
            v285);
          CDataMgr::SendF1DetailL1ToUI(
            this,
            *(HWND *)((char *)v774 + 6),
            (char *)v774 + 26,
            *((_BYTE *)v774 + 25),
            *(_DWORD *)((char *)v774 + 17));
          v285 = 1;
          v284 = 1;
          CDataMgr::PushDataRequest(
            (int)this + 497,
            *((_BYTE *)v774 + 25),
            (char *)v774 + 26,
            *(_DWORD *)((char *)v774 + 6),
            1,
            1);
          goto LABEL_1068;
        case 20:
          v766 = pGLOBAL_HIS_TRENDLINE;
          QDataEngine::SetRankList(*((char *)pGLOBAL_HIS_TRENDLINE + 17), 0, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)pGLOBAL_HIS_TRENDLINE + 18));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            1,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 1298));
          QDataEngine::SetRankList(*((char *)v766 + 17), 3, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 658));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            4,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 1938));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            5,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 5138));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            6,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 2578));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            7,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 3858));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            2,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 4498));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            9,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 3218));
          QDataEngine::SetRankList(
            *((char *)v766 + 17),
            8,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 5778));
          QDataEngine::SaveRankList();
          CDataMgr::SendRankToUI(this, *(HWND *)((char *)v766 + 6), *((char *)v766 + 17));
          goto LABEL_1068;
        case 23:
          v715 = pGLOBAL_HIS_TRENDLINE;
          v330 = mfc80xU_287(&v433, (char *)pGLOBAL_HIS_TRENDLINE + 26);
          v329 = v330;
          LOBYTE(v931) = 72;
          v285 = *(_DWORD *)((char *)v715 + 17);
          v202 = (const wchar_t *)mfc80xU_870(v330);
          QDataEngine::SaveHisRtData(
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v715 + 37),
            *(signed __int16 *)((char *)v715 + 35),
            *((_BYTE *)v715 + 25),
            v202,
            v285);
          LOBYTE(v931) = 1;
          mfc80xU_577(&v433);
          CDataMgr::SendHisTrendDataToUI(
            this,
            *(HWND *)((char *)v715 + 6),
            (char *)v715 + 26,
            *((_BYTE *)v715 + 25),
            *(_DWORD *)((char *)v715 + 17));
          goto LABEL_1068;
        case 28:
          v765 = pGLOBAL_HIS_TRENDLINE;
          if ( *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 17) )
          {
            QDataEngine::SetRankList(2, 1, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 19));
            QDataEngine::SetRankList(2, 4, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 659));
            QDataEngine::SetRankList(17, 1, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 1299));
            QDataEngine::SetRankList(17, 4, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 1939));
          }
          else
          {
            QDataEngine::SetRankList(2, 0, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 19));
            QDataEngine::SetRankList(2, 3, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 659));
            QDataEngine::SetRankList(17, 0, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 1299));
            QDataEngine::SetRankList(17, 3, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v765 + 1939));
          }
          QDataEngine::SaveRankList();
          if ( *(_DWORD *)((char *)v765 + 6) )
            CDataMgr::SendRankUpDownToUI(this, *(HWND *)((char *)v765 + 6), *((_BYTE *)v765 + 17));
          else
            CDataMgr::OnTimeSendRankUpDownToUI(this, *((_BYTE *)v765 + 17));
          goto LABEL_1068;
        case 139:
          v712 = pGLOBAL_HIS_TRENDLINE;
          for ( k = 0; k < *(_DWORD *)((char *)v712 + 18); ++k )
            QDataEngine::AddCMLD_Data(
              *((_BYTE *)v712 + 104 * k + 22),
              (char *)v712 + 104 * k + 23,
              (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v712 + 104 * k + 22));
          CDataMgr::SendDataArriveInfoToUI(this, *(HWND *)((char *)v712 + 6), 0x19u);
          goto LABEL_1068;
        case 141:
          v714 = pGLOBAL_HIS_TRENDLINE;
          v328 = mfc80xU_287(&v432, (char *)pGLOBAL_HIS_TRENDLINE + 18);
          v327 = v328;
          LOBYTE(v931) = 73;
          v285 = *(_DWORD *)((char *)v714 + 25);
          v203 = (const wchar_t *)mfc80xU_870(v328);
          QDataEngine::SaveHisRtData(
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v714 + 31),
            *(signed __int16 *)((char *)v714 + 29),
            *((_BYTE *)v714 + 17),
            v203,
            v285);
          LOBYTE(v931) = 1;
          mfc80xU_577(&v432);
          CDataMgr::SendHisTrendDataToUI(
            this,
            *(HWND *)((char *)v714 + 6),
            (char *)v714 + 18,
            *((_BYTE *)v714 + 17),
            *(_DWORD *)((char *)v714 + 25));
          goto LABEL_1068;
        case 181:
          v702 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || *(_DWORD *)((char *)v702 + 17) != QDataEngine::GetCurDateByMarket(8, 0) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::SendGzqhPankouToUI(this, *(HWND *)((char *)v702 + 6), v702);
          goto LABEL_1068;
        case 182:
          v693 = pGLOBAL_HIS_TRENDLINE;
          if ( *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            CDataMgr::SendGzqhRatioPriceToUI(this, *(HWND *)((char *)v693 + 6), v693);
          goto LABEL_1068;
        case 184:
          v839 = pGLOBAL_HIS_TRENDLINE;
          if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          v285 = (int)pGLOBAL_HIS_TRENDLINE;
          v461 = &v285;
          v349 = sub_4D9CB20(0);
          sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x705u, v285);
          break;
        default:
          goto LABEL_1067;
      }
    }
    goto LABEL_1068;
  }
  if ( v381 > 601 )
  {
    if ( v381 <= 1000 )
    {
      if ( v381 == 1000 )
      {
        QDataEngine::SetHisLoginInStatus(1);
      }
      else
      {
        v381 -= 602;
        switch ( v381 )
        {
          case 0:
            v856 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v856 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v855 = 0;
            sub_4E26720(&v857);
            LOBYTE(v931) = 38;
            v285 = 0;
            v284 = (int)&v855;
            v283 = &v857;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v856 + 17),
                                     *((_BYTE *)v856 + 21),
                                     (char *)v856 + 27,
                                     *(_DWORD *)((char *)v856 + 23),
                                     &v857,
                                     &v855,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v857);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( l = 0; ; ++l )
            {
            	//处理整个板块的股票当日实时资金流信息
              v80 = sub_4D33690(&v857);
              if ( l >= v80 )
                break;
              v284 = sub_4D336D0(l);//获取资金流信息的结构体
              v283 = (char *)sub_4D336D0(l);
              v81 = sub_4D336D0(l);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v81 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                1);
            }
            v285 = v855;
            v284 = 513;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v82 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v82, (unsigned int)v282, 0x501u, 0x201u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v857);
            goto LABEL_1068;
          case 1:
            v825 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v825 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( *((_BYTE *)v825 + 21) == 2 )
              sub_4E78200((char *)this + 569);
            v824 = 0;
            v285 = (int)&v824;
            if ( !CDataMgr::PreProcMoneyRankData(
                    this,
                    *(_DWORD *)((char *)v825 + 17),
                    *((_BYTE *)v825 + 21),
                    (char *)v825 + 26,
                    *(_DWORD *)((char *)v825 + 22),
                    &v824) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v824;
            v284 = 514;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v95 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v95, (unsigned int)v282, 0x501u, 0x202u, v285);
            goto LABEL_1068;
          case 2:
            v820 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v820 + 10) || *(_DWORD *)v820 < 1 )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v821);
            LOBYTE(v931) = 42;
            v819 = 0;
            v285 = 0;
            v284 = (int)&v819;
            v283 = &v821;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v820 + 17),
                                     *((_BYTE *)v820 + 21),
                                     (char *)v820 + 26,
                                     *(_DWORD *)((char *)v820 + 22),
                                     &v821,
                                     &v819,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v821);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( (unsigned int)sub_4D33690(&v821) < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v821);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( m = 0; ; ++m )
            {
              v97 = sub_4D33690(&v821);
              if ( m >= v97 )
                break;
              v284 = sub_4D336D0(m);
              v283 = (char *)sub_4D336D0(m);
              v98 = sub_4D336D0(m);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v98 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                1);
            }
            v285 = v819;
            v284 = 515;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v99 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v99, (unsigned int)v282, 0x501u, 0x203u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v821);
            goto LABEL_1068;
          case 3:
            v790 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( *((_BYTE *)v790 + 21) == 2 )
              sub_4E78200((char *)this + 585);
            v789 = 0;
            v285 = (int)&v789;
            if ( !CDataMgr::PreProcMoneyRankData(
                    this,
                    *(_DWORD *)((char *)v790 + 17),
                    *((_BYTE *)v790 + 21),
                    (char *)v790 + 27,
                    *(_DWORD *)((char *)v790 + 23),
                    &v789) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v789;
            v284 = 519;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v116 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v116, (unsigned int)v282, 0x501u, 0x207u, v285);
            goto LABEL_1068;
          case 4:
            v787 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v788);
            LOBYTE(v931) = 49;
            v786 = 0;
            v285 = 0;
            v284 = (int)&v786;
            v283 = &v788;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v787 + 17),
                                     *((_BYTE *)v787 + 21),
                                     (char *)v787 + 27,
                                     *(_DWORD *)((char *)v787 + 23),
                                     &v788,
                                     &v786,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v788);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( (unsigned int)sub_4D33690(&v788) < 1 )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v788);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v284 = sub_4D33690(&v788);
            v117 = (struct MainCapFlowShowDetailClientPaid *)sub_4E26770(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v787 + 22), v117, v284, 1);
            v285 = v786;
            v284 = 520;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v118 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v118, (unsigned int)v282, 0x501u, 0x208u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v788);
            goto LABEL_1068;
          case 5:
LABEL_317:
            v813 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( *((_BYTE *)v813 + 21) == 2 )
              sub_4E78200((char *)this + 569);
            v812 = 0;
            v285 = (int)&v812;
            if ( !CDataMgr::PreProcMoneyRankData(
                    this,
                    *(_DWORD *)((char *)v813 + 17),
                    *((_BYTE *)v813 + 21),
                    (char *)v813 + 30,
                    *(_DWORD *)((char *)v813 + 26),
                    &v812) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v812;
            v284 = 516;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v103 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v103, (unsigned int)v282, 0x501u, 0x204u, v285);
            goto LABEL_1068;
          case 6:
            v810 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v811);
            LOBYTE(v931) = 44;
            v809 = 0;
            v285 = 0;
            v284 = (int)&v809;
            v283 = &v811;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v810 + 17),
                                     *((_BYTE *)v810 + 21),
                                     (char *)v810 + 30,
                                     *(_DWORD *)((char *)v810 + 26),
                                     &v811,
                                     &v809,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v811);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( n = 0; ; ++n )
            {
              v104 = sub_4D33690(&v811);
              if ( n >= v104 )
                break;
              v284 = sub_4D336D0(n);
              v283 = (char *)sub_4D336D0(n);
              v105 = sub_4D336D0(n);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v105 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                1);
            }
            v285 = v809;
            v284 = 517;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v106 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v106, (unsigned int)v282, 0x501u, 0x205u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v811);
            goto LABEL_1068;
          case 8:
            v823 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v823 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( *((_BYTE *)v823 + 21) == 2 )
              sub_4E78200((char *)this + 585);
            v822 = 0;
            v285 = (int)&v822;
            if ( !CDataMgr::PreProcMoneyRankData(
                    this,
                    *(_DWORD *)((char *)v823 + 17),
                    *((_BYTE *)v823 + 21),
                    (char *)v823 + 26,
                    *(_DWORD *)((char *)v823 + 22),
                    &v822) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v822;
            v284 = 514;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v96 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v96, (unsigned int)v282, 0x501u, 0x202u, v285);
            goto LABEL_1068;
          case 9:
            v816 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v817);
            LOBYTE(v931) = 43;
            v815 = 0;
            v285 = *(_DWORD *)((char *)v816 + 13);
            v284 = (int)&v815;
            v283 = &v817;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v816 + 17),
                                     *((_BYTE *)v816 + 21),
                                     (char *)v816 + 26,
                                     *(_DWORD *)((char *)v816 + 22),
                                     &v817,
                                     &v815,
                                     v285) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v817);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( ii = 0; ; ++ii )
            {
              v100 = sub_4D33690(&v817);
              if ( ii >= v100 )
                break;
              v284 = sub_4D336D0(ii);
              v283 = (char *)sub_4D336D0(ii);
              v101 = sub_4D336D0(ii);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v101 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                1);
            }
            v285 = v815;
            v284 = 515;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v102 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v102, (unsigned int)v282, 0x501u, 0x203u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v817);
            goto LABEL_1068;
          case 11:
            v551 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            std::basic_ifstream<char,std::char_traits<char>>::basic_ifstream<char,std::char_traits<char>>(
              &v550,
              L"data\\datavernum.dat",
              1,
              64,
              1);
            LOBYTE(v931) = 98;
            if ( (unsigned __int8)std::ios_base::operator!((char *)&v550 + *(_DWORD *)(v550 + 4)) )
            {
              std::basic_ofstream<char,std::char_traits<char>>::basic_ofstream<char,std::char_traits<char>>(
                &v549,
                L"data\\datavernum.dat",
                2,
                64,
                1);
              LOBYTE(v931) = 99;
              if ( !(unsigned __int8)std::ios_base::operator!((char *)&v549 + *(_DWORD *)(v549 + 4)) )
              {
                std::basic_ostream<char,std::char_traits<char>>::operator<<(&v549, *(_DWORD *)((char *)v551 + 17));
                std::basic_ofstream<char,std::char_traits<char>>::close(&v549);
              }
              LOBYTE(v931) = 98;
              std::basic_ofstream<char,std::char_traits<char>>::`vbase destructor(&v549);
              LOBYTE(v931) = 1;
              std::basic_ifstream<char,std::char_traits<char>>::`vbase destructor(&v550);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v552 = 0;
            std::basic_istream<char,std::char_traits<char>>::operator>>(&v550, &v552);
            std::basic_ifstream<char,std::char_traits<char>>::close(&v550);
            if ( v552 != *(_DWORD *)((char *)v551 + 17) )
            {
              QDataEngine::ClearAllKlineData();
              QDataEngine::ClearAllRtlineData();
              std::basic_ofstream<char,std::char_traits<char>>::basic_ofstream<char,std::char_traits<char>>(
                &v548,
                L"data\\datavernum.dat",
                18,
                64,
                1);
              LOBYTE(v931) = 100;
              if ( (unsigned __int8)std::ios_base::operator!((char *)&v548 + *(_DWORD *)(v548 + 4)) )
              {
                LOBYTE(v931) = 98;
                std::basic_ofstream<char,std::char_traits<char>>::`vbase destructor(&v548);
                LOBYTE(v931) = 1;
                std::basic_ifstream<char,std::char_traits<char>>::`vbase destructor(&v550);
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              std::basic_ostream<char,std::char_traits<char>>::operator<<(&v548, *(_DWORD *)((char *)v551 + 17));
              std::basic_ofstream<char,std::char_traits<char>>::close(&v548);
              v257 = CDataMgr::GetReceiverWnd(this);
              CViewManager::PostBroadcastCommand(v257, 0x71u, 0);
              LOBYTE(v931) = 98;
              std::basic_ofstream<char,std::char_traits<char>>::`vbase destructor(&v548);
            }
            LOBYTE(v931) = 1;
            std::basic_ifstream<char,std::char_traits<char>>::`vbase destructor(&v550);
            goto LABEL_1068;
          case 19:
            v576 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || *((char *)v576 + 10) < 1 )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            *(_DWORD *)v577 = QDataEngine::GetShortDecisionDataDate();
            v574 = sub_5020160();
            if ( *(_DWORD *)v577 )
            {
              if ( !*((_BYTE *)v576 + 17) || (v239 = CDataMgr::GetCurDateByMarket(this, 1, 0), *(_DWORD *)v577 != v239) )
              {
                if ( v574 )
                  sub_4D62050(0x412u, 0, 0);
                v304 = CGlobalEnv::GetGlobalEnv(&v405);
                LOBYTE(v931) = 89;
                v240 = unknown_libname_97(v304);
                v241 = unknown_libname_97(v240 + 148);
                v242 = sub_4D789C0(v241);
                sub_4E3E5E0(v242);
                LOBYTE(v931) = 91;
                sub_4E3C780(&v405);
                v243 = (Request *)unknown_libname_97(&v573);
                Request::RequestShortDecisionData(v243, 0, 0, 0, 1u, 0, 0, 1, 0);
                v571 = 0;
                memset(&v572, 0, 0xFEu);
                LightLogger::CLogger::GetLogger(&v570, L"ShortDecisionProc");
                LOBYTE(v931) = 92;
                CDataMgr::GetCurDateByMarket(this, 1, 0);
                sub_4D3E590(&v571, L"Validate Error,Clear Data,DataDate:%d,QuoteDate:%d", v577[0]);
                v244 = (LightLogger::CLogger *)unknown_libname_97(&v570);
                LightLogger::CLogger::WriteLogLine(v244, &v571, 10000);
                LOBYTE(v931) = 91;
                sub_4E3C780(&v570);
                LOBYTE(v931) = 1;
                sub_4E3C780(&v573);
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
            }
            v403 = mfc80xU_762(16);
            LOBYTE(v931) = 93;
            if ( v403 )
              v303 = sub_4D5AB60(v403);
            else
              v303 = 0;
            v404 = v303;
            LOBYTE(v931) = 1;
            v575 = v303;
            if ( !v303 )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( !(unsigned __int8)CDataMgr::PreProcShortDecisionData(
                                     (char *)v576 + 22,
                                     *(_DWORD *)((char *)v576 + 18),
                                     v575) )
            {
              if ( v575 )
              {
                v401 = v575;
                v402 = v575;
                if ( v575 )
                  v302 = sub_4DF94F0(1);
                else
                  v302 = 0;
                v575 = 0;
              }
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( (unsigned __int8)sub_4D610A0(v575) )
            {
              if ( v575 )
              {
                v399 = v575;
                v400 = v575;
                if ( v575 )
                  v301 = sub_4DF94F0(1);
                else
                  v301 = 0;
                v575 = 0;
              }
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( v574 )
              sub_4D62050(0x412u, *((unsigned __int8 *)v576 + 17), v575);
            goto LABEL_1068;
          case 20:
            v569 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v568 = 0;
            v285 = (int)&v568;
            v284 = *(_DWORD *)((char *)v569 + 23);
            v283 = (char *)v569 + 27;
            v281 = *(float *)((char *)v569 + 17);
            LOBYTE(v282) = *((_BYTE *)v569 + 21);
            if ( !(unsigned __int8)CDataMgr::ProcStkDDEData(this, LODWORD(v281), v282, (char *)v569 + 27, v284, &v568) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v568;
            v284 = 54;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v245 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v245, (unsigned int)v282, (unsigned int)v283, v284, v285);
            goto LABEL_1068;
          case 21:
          case 23:
            v566 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v565 = 0;
            if ( !CDataMgr::ProcFavStkDDEData(this, v566, &v565) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v565;
            v284 = 56;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v246 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v246, (unsigned int)v282, 0x501u, 0x38u, v285);
            goto LABEL_1068;
          case 22:
            v567 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( !CDataMgr::ProcBkDDEData(this, v567) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::SendMsgToUI(this, *(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x37u);
            goto LABEL_1068;
          case 24:
            v563 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v564 = 0;
            v285 = (int)&v564;
            v284 = *(_DWORD *)((char *)v563 + 26);
            v283 = (char *)v563 + 30;
            v281 = *(float *)((char *)v563 + 17);
            LOBYTE(v282) = *((_BYTE *)v563 + 21);
            if ( !(unsigned __int8)CDataMgr::ProcStkDDEData(this, LODWORD(v281), v282, (char *)v563 + 30, v284, &v564) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = v564;
            v284 = 57;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v247 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v247, (unsigned int)v282, (unsigned int)v283, v284, v285);
            goto LABEL_1068;
          case 25:
            v784 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v785);
            LOBYTE(v931) = 50;
            v783 = 0;
            v285 = 0;
            v284 = (int)&v783;
            v283 = &v785;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v784 + 17),
                                     *((_BYTE *)v784 + 21),
                                     (char *)v784 + 27,
                                     *(_DWORD *)((char *)v784 + 23),
                                     &v785,
                                     &v783,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v785);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( (unsigned int)sub_4D33690(&v785) < 1 )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v785);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v284 = sub_4D33690(&v785);
            v119 = (struct MainCapFlowShowDetailClientPaid *)sub_4E26770(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v784 + 22), v119, v284, 3);
            v285 = v783;
            v284 = 530;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v120 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v120, (unsigned int)v282, 0x501u, 0x212u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v785);
            goto LABEL_1068;
          case 26:
            v781 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v782);
            LOBYTE(v931) = 51;
            v780 = 0;
            v285 = 0;
            v284 = (int)&v780;
            v283 = &v782;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v781 + 17),
                                     *((_BYTE *)v781 + 21),
                                     (char *)v781 + 27,
                                     *(_DWORD *)((char *)v781 + 23),
                                     &v782,
                                     &v780,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v782);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( (unsigned int)sub_4D33690(&v782) < 1 )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v782);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v284 = sub_4D33690(&v782);
            v121 = (struct MainCapFlowShowDetailClientPaid *)sub_4E26770(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v781 + 22), v121, v284, 5);
            v285 = v780;
            v284 = 531;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v122 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v122, (unsigned int)v282, 0x501u, 0x213u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v782);
            goto LABEL_1068;
          case 27:
            v778 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v779);
            LOBYTE(v931) = 52;
            v777 = 0;
            v285 = 0;
            v284 = (int)&v777;
            v283 = &v779;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v778 + 17),
                                     *((_BYTE *)v778 + 21),
                                     (char *)v778 + 27,
                                     *(_DWORD *)((char *)v778 + 23),
                                     &v779,
                                     &v777,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v779);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( (unsigned int)sub_4D33690(&v779) < 1 )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v779);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v284 = sub_4D33690(&v779);
            v123 = (struct MainCapFlowShowDetailClientPaid *)sub_4E26770(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v778 + 22), v123, v284, 10);
            v285 = v777;
            v284 = 532;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v124 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v124, (unsigned int)v282, 0x501u, 0x214u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v779);
            goto LABEL_1068;
          case 28:
            v806 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v807);
            LOBYTE(v931) = 45;
            v805 = 0;
            v285 = 0;
            v284 = (int)&v805;
            v283 = &v807;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v806 + 17),
                                     *((_BYTE *)v806 + 21),
                                     (char *)v806 + 30,
                                     *(_DWORD *)((char *)v806 + 26),
                                     &v807,
                                     &v805,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v807);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( jj = 0; ; ++jj )
            {
              v107 = sub_4D33690(&v807);
              if ( jj >= v107 )
                break;
              v284 = sub_4D336D0(jj);
              v283 = (char *)sub_4D336D0(jj);
              v108 = sub_4D336D0(jj);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v108 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                3);
            }
            v285 = v805;
            v284 = 533;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v109 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v109, (unsigned int)v282, 0x501u, 0x215u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v807);
            goto LABEL_1068;
          case 29:
            v802 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v803);
            LOBYTE(v931) = 46;
            v801 = 0;
            v285 = 0;
            v284 = (int)&v801;
            v283 = &v803;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v802 + 17),
                                     *((_BYTE *)v802 + 21),
                                     (char *)v802 + 30,
                                     *(_DWORD *)((char *)v802 + 26),
                                     &v803,
                                     &v801,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v803);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( kk = 0; ; ++kk )
            {
              v110 = sub_4D33690(&v803);
              if ( kk >= v110 )
                break;
              v284 = sub_4D336D0(kk);
              v283 = (char *)sub_4D336D0(kk);
              v111 = sub_4D336D0(kk);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v111 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                5);
            }
            v285 = v801;
            v284 = 534;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v112 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v112, (unsigned int)v282, 0x501u, 0x216u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v803);
            goto LABEL_1068;
          case 30:
            v798 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v799);
            LOBYTE(v931) = 47;
            v797 = 0;
            v285 = 0;
            v284 = (int)&v797;
            v283 = &v799;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v798 + 17),
                                     *((_BYTE *)v798 + 21),
                                     (char *)v798 + 30,
                                     *(_DWORD *)((char *)v798 + 26),
                                     &v799,
                                     &v797,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v799);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( ll = 0; ; ++ll )
            {
              v113 = sub_4D33690(&v799);
              if ( ll >= v113 )
                break;
              v284 = sub_4D336D0(ll);
              v283 = (char *)sub_4D336D0(ll);
              v114 = sub_4D336D0(ll);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v114 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                10);
            }
            v285 = v797;
            v284 = 535;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v115 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v115, (unsigned int)v282, 0x501u, 0x217u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v799);
            goto LABEL_1068;
          case 31:
            v852 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v852 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v853);
            LOBYTE(v931) = 39;
            v851 = 0;
            v285 = 0;
            v284 = (int)&v851;
            v283 = &v853;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v852 + 17),
                                     *((_BYTE *)v852 + 21),
                                     (char *)v852 + 27,
                                     *(_DWORD *)((char *)v852 + 23),
                                     &v853,
                                     &v851,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v853);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( mm = 0; ; ++mm )
            {
              v83 = sub_4D33690(&v853);
              if ( mm >= v83 )
                break;
              v284 = sub_4D336D0(mm);
              v283 = (char *)sub_4D336D0(mm);
              v84 = sub_4D336D0(mm);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v84 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                3);
            }
            v285 = v851;
            v284 = 536;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v85 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v85, (unsigned int)v282, 0x501u, 0x218u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v853);
            goto LABEL_1068;
          case 32:
            v848 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v848 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v849);
            LOBYTE(v931) = 40;
            v847 = 0;
            v285 = 0;
            v284 = (int)&v847;
            v283 = &v849;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v848 + 17),
                                     *((_BYTE *)v848 + 21),
                                     (char *)v848 + 27,
                                     *(_DWORD *)((char *)v848 + 23),
                                     &v849,
                                     &v847,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v849);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( nn = 0; ; ++nn )
            {
              v86 = sub_4D33690(&v849);
              if ( nn >= v86 )
                break;
              v284 = sub_4D336D0(nn);
              v283 = (char *)sub_4D336D0(nn);
              v87 = sub_4D336D0(nn);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v87 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                5);
            }
            v285 = v847;
            v284 = 537;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v88 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v88, (unsigned int)v282, 0x501u, 0x219u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v849);
            goto LABEL_1068;
          case 33:
            v844 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v844 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            sub_4E26720(&v845);
            LOBYTE(v931) = 41;
            v843 = 0;
            v285 = 0;
            v284 = (int)&v843;
            v283 = &v845;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v844 + 17),
                                     *((_BYTE *)v844 + 21),
                                     (char *)v844 + 27,
                                     *(_DWORD *)((char *)v844 + 23),
                                     &v845,
                                     &v843,
                                     0) )
            {
              LOBYTE(v931) = 1;
              sub_4E26750(&v845);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( i1 = 0; ; ++i1 )
            {
              v89 = sub_4D33690(&v845);
              if ( i1 >= v89 )
                break;
              v284 = sub_4D336D0(i1);
              v283 = (char *)sub_4D336D0(i1);
              v90 = sub_4D336D0(i1);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v90 + 16),
                v283,
                (struct MainCapFlowShowDetailClientPaid *)v284,
                10);
            }
            v285 = v843;
            v284 = 544;
            v283 = (char *)1281;
            v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
            v91 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v91, (unsigned int)v282, 0x501u, 0x220u, v285);
            LOBYTE(v931) = 1;
            sub_4E26750(&v845);
            goto LABEL_1068;
          case 109:
            v882 = pGLOBAL_HIS_TRENDLINE;
            mfc80xU_293(&v879);
            LOBYTE(v931) = 27;
            v466 = mfc80xU_762(28);
            if ( v466 )
              v360 = sub_4D9CDE0(v466);
            else
              v360 = 0;
            v467 = v360;
            sub_4E3E5E0(v360);
            LOBYTE(v931) = 28;
            v54 = unknown_libname_97(&v880);
            *(_DWORD *)unknown_libname_90(v54) = 0;
            v55 = unknown_libname_97(&v880);
            *(_DWORD *)(unknown_libname_90(v55) + 4) = 0;
            *(_DWORD *)((char *)this + 70) = *((_DWORD *)v882 + 7);
            *(_DWORD *)((char *)this + 46) = *(_DWORD *)((char *)v882 + 47);
            if ( *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              *(_DWORD *)((char *)this + 1242) = *((_DWORD *)v882 + 7);
              v881 = 0;
              if ( *((_DWORD *)v882 + 7) == 1
                && !strcmp(QDataEngine::m_LogonInfo, "guest")
                && !strcmp(byte_51A7448, "guest") )
              {
                v881 = 1;
              }
              *((_BYTE *)this + 496) = *((_BYTE *)v882 + 36) == 1;
              CDataMgr::ClearDataOfApp(this);
              QDataEngine::InitDHKey((const unsigned __int8 *)v882 + 39, 8);
              v877 = QDataEngine::SetServerInfo((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v882 + 17));
              v878 = sub_4D3E720();
              if ( v877 || *((_BYTE *)this + 45) )
              {
                v71 = *((unsigned __int8 *)this + 45);
                if ( !*((_BYTE *)this + 45) )
                {
                  v862 = 0;
                  CDataMgr::RequestCmd(this, 0, 1, 1, &v862, 0);
                }
                v285 = v71;
                v463 = &v285;
                v354 = sub_4D9CB20(0);
                sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0, v285);
              }
              else
              {
                v863 = 0;
                CDataMgr::RequestCmd(this, 0, 1, 1, &v863, 0);
              }
              QDataEngine::SetCurLoginUserName(QDataEngine::m_LogonInfo);
              mfc80xU_293(&v884);
              LOBYTE(v931) = 36;
              mfc80xU_293(&v875);
              LOBYTE(v931) = 37;
              mfc80xU_2311(&v884, (const char *)L".\\config\\user\\lastuser.ini");
              v876 = QDataEngine::m_LogonInfo;
              if ( QDataEngine::m_LogonInfo )
              {
                v883 = lstrlenA(v876) + 1;
                if ( v883 <= 0x3FFFFFFF )
                {
                  v72 = alloca(2 * v883);
                  v351 = (LPWSTR)&v286;
                  v352 = sub_4D3E5F0((LPWSTR)&v286, v876, v883, 0);
                }
                else
                {
                  v352 = 0;
                }
                v353 = v352;
              }
              else
              {
                v353 = 0;
              }
              v285 = v353;
              mfc80xU_2311(&v875, (const char *)L"%s", v353);
              v73 = (const WCHAR *)mfc80xU_2461(&v884);
              v74 = ATL::CW2AEX<128>::CW2AEX<128>(v73);
              v350 = v74;
              v75 = (const CHAR *)unknown_libname_97(v74);
              MakeSureDirectoryPathExists(v75);
              ATL::CW2AEX<128>::~CW2AEX<128>(&v462);
              v285 = -1;
              mfc80xU_5398(&v884);
              mfc80xU_870(&v884);
              v76 = (const WCHAR *)mfc80xU_870(&v875);
              WritePrivateProfileStringW(L"config", L"name", v76, (LPCWSTR)v285);
              CDataMgr::WriteUserRightCfgOfFree(this, v881);
              mfc80xU_2311(&v884, (const char *)L".\\config\\UserOwnerId.ini");
              v285 = *(_DWORD *)((char *)this + 41);
              mfc80xU_2311(&v875, (const char *)L"%d", v285);
              v285 = mfc80xU_870(&v884);
              v77 = (const WCHAR *)mfc80xU_870(&v875);
              WritePrivateProfileStringW(L"user", L"buildversion", v77, v286);
              CDataMgr::CopyUserCfgFiles(this);
              sub_4FDD940();
              QDataEngine::SetLoginInStatus(1);
              QDataEngine::SetOnlineStatus(1);
              v286 = 0;
              v285 = 4;
              v78 = CDataMgr::GetReceiverWnd(this);
              CViewManager::PostBroadcastCommand(v78, v285, v286);
              LOBYTE(v931) = 36;
              mfc80xU_577(&v875);
              LOBYTE(v931) = 28;
              mfc80xU_577(&v884);
              LOBYTE(v931) = 27;
              sub_4E3C780(&v880);
              LOBYTE(v931) = 1;
              mfc80xU_577(&v879);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
            }
            else
            {
              v873 = sub_4D3E720();
              v872 = (char *)v882 + 19;
              if ( v882 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-19 )
              {
                v359 = 0;
              }
              else
              {
                v874 = lstrlenA(v872) + 1;
                if ( v874 <= 0x3FFFFFFF )
                {
                  v56 = alloca(2 * v874);
                  v357 = (LPWSTR)&v286;
                  v358 = sub_4D3E5F0((LPWSTR)&v286, v872, v874, 0);
                }
                else
                {
                  v358 = 0;
                }
                v359 = v358;
              }
              v285 = v359;
              mfc80xU_2311(&v879, (const char *)L"%s ", v359);
              if ( *((_BYTE *)this + 45) )
              {
                CDataMgr::OffLine(this);
                v57 = unknown_libname_97(&v880);
                *(_DWORD *)(unknown_libname_90(v57) + 4) = 5;
                if ( *(_WORD *)((char *)pGLOBAL_HIS_TRENDLINE + 17) == 11 )
                {
                  v285 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(
                           &CDataMgr::LOGON_IN_FORCE_UPDATE,
                           v286);
                  mfc80xU_2311(&v879, (const char *)L"%s", v285);
                  v58 = unknown_libname_97(&v880);
                  *(_DWORD *)(unknown_libname_90(v58) + 4) = 4;
                }
                if ( *(_WORD *)((char *)pGLOBAL_HIS_TRENDLINE + 17) == 36 )
                {
                  v59 = unknown_libname_97(&v880);
                  *(_DWORD *)(unknown_libname_90(v59) + 4) = 7;
                }
                v464 = mfc80xU_762(28);
                LOBYTE(v931) = 29;
                if ( v464 )
                  v356 = sub_4E26660(v464);
                else
                  v356 = 0;
                v465 = v356;
                LOBYTE(v931) = 28;
                sub_4E3E5E0(v356);
                LOBYTE(v931) = 30;
                v285 = mfc80xU_2895(&v879) + 1;
                v60 = unknown_libname_97(&v870);
                unknown_libname_90(v60);
                sub_4E266D0(v285);
                v61 = mfc80xU_2895(&v879);
                v285 = mfc80xU_2460(&v879, v61);
                v62 = unknown_libname_97(&v870);
                unknown_libname_90(v62);
                v63 = (wchar_t *)sub_4E266F0(0);
                wcscpy(v63, (const wchar_t *)v285);
                v64 = unknown_libname_97(&v880);
                unknown_libname_90(v64);
                sub_4DA7300(&v870);
                CGlobalEnv::GetGlobalEnv(&v867);
                LOBYTE(v931) = 31;
                v355 = unknown_libname_97(&v867);
                v65 = unknown_libname_97(&v880);
                v871 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v355 + 36))(v355, v65);
                PostMessageW(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x501u, 0, v871);
                LightLogger::CLogger::GetLogger(&v868, L"Logon App");
                LOBYTE(v931) = 32;
                mfc80xU_283(&v869, L"(Login Error)post error msg to logondlg,Error msg is:");
                LOBYTE(v931) = 33;
                mfc80xU_896(&v869, &v879);
                v66 = mfc80xU_2461(&v869);
                sub_4D3E590(&Caption, L"%s", v66);
                mfc80xU_5398(&v869);
                v67 = (LightLogger::CLogger *)unknown_libname_97(&v868);
                LightLogger::CLogger::WriteLogLine(v67, &Caption, 10000);
                LOBYTE(v931) = 32;
                mfc80xU_577(&v869);
                LOBYTE(v931) = 31;
                sub_4E3C780(&v868);
                LOBYTE(v931) = 30;
                sub_4E3C780(&v867);
                LOBYTE(v931) = 28;
                sub_4E3C780(&v870);
              }
              else if ( *(_WORD *)((char *)v882 + 17) == 36 )
              {
                CDataMgr::OffLine(this);
                Sleep(0x1388u);
                if ( QDataEngine::m_bIsLoginPass )
                {
                  memset(&v865, 0, 0x400u);
                  sub_4E33A30(&v865, QDataEngine::m_szPassData);
                  CDataMgr::LogonFromPass(
                    this,
                    0,
                    QDataEngine::m_LogonInfo,
                    byte_51A7448,
                    QDataEngine::m_nPassDataLen,
                    &v865,
                    dword_51A7548,
                    (struct _PROXY_SERADDR_TAG_ *)&unk_51A7568);
                }
                else
                {
                  CDataMgr::Logon(
                    this,
                    0,
                    QDataEngine::m_LogonInfo,
                    byte_51A7448,
                    dword_51A7548,
                    (struct _PROXY_SERADDR_TAG_ *)&unk_51A7568);
                }
                LightLogger::CLogger::GetLogger(&v866, L"Logon App");
                LOBYTE(v931) = 34;
                sub_4D3E590(&Caption, L"(Login Error)post errorid =36", (char)v286);
                v68 = (LightLogger::CLogger *)unknown_libname_97(&v866);
                LightLogger::CLogger::WriteLogLine(v68, &Caption, 10000);
                LOBYTE(v931) = 28;
                sub_4E3C780(&v866);
              }
              else
              {
                CDataMgr::OffLine(this);
                v284 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(
                         &CDataMgr::AUTO_CONNECT_LOGON_ERROR_TITTLE,
                         48);
                v285 = mfc80xU_870(&v879);
                v69 = unknown_libname_97(&v929);
                MessageBoxW(*(HWND *)(v69 + 156), (LPCWSTR)v285, v286, v287);
                CDataMgr::ShowLogonDlg(this);
                LightLogger::CLogger::GetLogger(&v864, L"Logon App");
                LOBYTE(v931) = 35;
                sub_4D3E590(&Caption, L"(Login Error)pop logonDlg", v288);
                v287 = 10000;
                v286 = &Caption;
                v70 = (LightLogger::CLogger *)unknown_libname_97(&v864);
                LightLogger::CLogger::WriteLogLine(v70, v286, v287);
                LOBYTE(v931) = 28;
                sub_4E3C780(&v864);
              }
              LOBYTE(v931) = 27;
              sub_4E3C780(&v880);
              LOBYTE(v931) = 1;
              mfc80xU_577(&v879);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
            }
            return;
          case 110:
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v924 = pGLOBAL_HIS_TRENDLINE;
            CGlobalEnv::GetGlobalEnv(&v921);
            LOBYTE(v931) = 2;
            v477 = mfc80xU_762(28);
            if ( v477 )
              v380 = sub_4D9CDE0(v477);
            else
              v380 = 0;
            v478 = v380;
            sub_4E3E5E0(v380);
            LOBYTE(v931) = 3;
            v475 = mfc80xU_762(16);
            if ( v475 )
              v379 = sub_4E26340(v475);
            else
              v379 = 0;
            v476 = v379;
            sub_4E3E5E0(v379);
            LOBYTE(v931) = 4;
            v8 = unknown_libname_97(&v923);
            *(_DWORD *)unknown_libname_90(v8) = 127;
            v9 = unknown_libname_97(&v923);
            *(_DWORD *)(unknown_libname_90(v9) + 4) = 0;
            if ( *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              *(_DWORD *)((char *)this + 58) = *(_DWORD *)((char *)v924 + 47);
              QDataEngine::SetTrendLoginInStatus(1);
              *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 3) = 1;
              v13 = unknown_libname_97(&v920);
              *(_BYTE *)unknown_libname_90(v13) = 1;
            }
            else
            {
              mfc80xU_293(&v917);
              LOBYTE(v931) = 5;
              v916 = sub_4D3E720();
              lpString = (char *)v924 + 19;
              if ( v924 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-19 )
              {
                v378 = 0;
              }
              else
              {
                cchWideChar = lstrlenA(lpString) + 1;
                if ( cchWideChar <= 0x3FFFFFFF )
                {
                  v10 = alloca(2 * cchWideChar);
                  lpWideCharStr = (LPWSTR)&v286;
                  v377 = sub_4D3E5F0((LPWSTR)&v286, lpString, cchWideChar, 0);
                }
                else
                {
                  v377 = 0;
                }
                v378 = v377;
              }
              ((void (__cdecl *)(int *, const wchar_t *, int, WCHAR *, UINT))mfc80xU_2311)(
                &v917,
                L"trend server logon failed: %s ",
                v378,
                v286,
                v287);
              LightLogger::CLogger::GetLogger(&v919, L"logon on");
              LOBYTE(v931) = 6;
              wsprintfW(&Caption, L"logon fail %s", v917);
              v11 = (LightLogger::CLogger *)unknown_libname_97(&v919);
              LightLogger::CLogger::WriteLogLine(v11, &Caption, 20000);
              v12 = unknown_libname_97(&v920);
              *(_BYTE *)unknown_libname_90(v12) = 0;
              LOBYTE(v931) = 5;
              sub_4E3C780(&v919);
              LOBYTE(v931) = 4;
              mfc80xU_577(&v917);
            }
            v14 = unknown_libname_97(&v923);
            unknown_libname_90(v14);
            sub_4DA7300(&v920);
            v375 = unknown_libname_97(&v921);
            v15 = unknown_libname_97(&v923);
            v922 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v375 + 36))(v375, v15);
            if ( *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
              QDataEngine::SendMsgDataToUI(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), v922, 0x7Fu);
            LOBYTE(v931) = 3;
            sub_4E3C780(&v920);
            LOBYTE(v931) = 2;
            sub_4E3C780(&v923);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v921);
            goto LABEL_1068;
          case 115:
            CDataMgr::ProcAllStkDictList(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 116:
            CDataMgr::ProcStkOptionQuoteTable(this, pGLOBAL_HIS_TRENDLINE, *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2));
            goto LABEL_1068;
          case 117:
            CDataMgr::ProcBufferListData(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 118:
          case 131:
            v718 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::UpdatePushFavQuoteTable(this, v718);
            goto LABEL_1068;
          case 119:
            v719 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::UpdatePushQuoteTableNew(this, v719);
            goto LABEL_1068;
          case 120:
            v793 = pGLOBAL_HIS_TRENDLINE;
            sub_4E267A0(&v792);
            LOBYTE(v931) = 48;
            v285 = (int)&v792;
            if ( !(unsigned __int8)CDataMgr::PreProcBkData(
                                     *(_DWORD *)((char *)v793 + 17),
                                     *((_BYTE *)v793 + 21),
                                     (char *)v793 + 27,
                                     *(_DWORD *)((char *)v793 + 23),
                                     &v792) )
            {
              LOBYTE(v931) = 1;
              sub_4E267D0(&v792);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 314));
            CDataMgr::SendMsgToUIs((int)this + 740, 0x709u);
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 314));
            LOBYTE(v931) = 1;
            sub_4E267D0(&v792);
            goto LABEL_1068;
          case 122:
            v717 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( CDataMgr::AddFavBkData(
                   this,
                   *(_DWORD *)((char *)v717 + 17),
                   *((_BYTE *)v717 + 21),
                   (char *)v717 + 26,
                   *(_DWORD *)((char *)v717 + 22),
                   *(HWND *)((char *)v717 + 6),
                   *(_DWORD *)((char *)v717 + 13)) )
            {
              goto LABEL_1068;
            }
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          case 123:
            CDataMgr::ProcPushOptionQuote(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 126:
            goto LABEL_488;
          case 129:
            CDataMgr::ProcBkStkQuoteTable(this, pGLOBAL_HIS_TRENDLINE, *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2));
            goto LABEL_1068;
          case 132:
            v521 = pGLOBAL_HIS_TRENDLINE;
            v389 = mfc80xU_762(44);
            if ( v389 )
              v295 = sub_4E26950(v389);
            else
              v295 = 0;
            v390 = v295;
            sub_4E3E5E0(v295);
            LOBYTE(v931) = 101;
            if ( !unknown_libname_97(&v519) )
            {
              LOBYTE(v931) = 1;
              sub_4E3C780(&v519);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v520 = QDataEngine::App_OneStkInfo((const char *)v521 + 18, *((_BYTE *)v521 + 17));
            if ( v520 )
            {
              if ( !*(_DWORD *)((char *)v520 + 81) )
              {
                sub_50B7740();
                sub_50B8420(0, v520);
              }
              if ( *(_DWORD *)((char *)v520 + 81) )
              {
                *(float *)(*(_DWORD *)((char *)v520 + 81) + 37) = *(float *)((char *)v521 + 38);
                *(float *)(*(_DWORD *)((char *)v520 + 81) + 41) = *(float *)((char *)v521 + 42);
              }
            }
            v260 = unknown_libname_97(&v519);
            v261 = (_BYTE *)unknown_libname_90(v260);
            *v261 = *((_BYTE *)v521 + 17);
            v284 = (int)v521 + 18;
            v262 = unknown_libname_97(&v519);
            v263 = unknown_libname_90(v262);
            sub_4DFCBC0((char *)(v263 + 1), (char *)v284, 0x10u);
            v264 = unknown_libname_97(&v519);
            v265 = unknown_libname_90(v264);
            *(_DWORD *)(v265 + 17) = *(_DWORD *)((char *)v521 + 34);
            v266 = unknown_libname_97(&v519);
            v267 = unknown_libname_90(v266);
            *(float *)(v267 + 25) = *(float *)((char *)v521 + 42);
            v268 = unknown_libname_97(&v519);
            v269 = unknown_libname_90(v268);
            *(float *)(v269 + 21) = *(float *)((char *)v521 + 38);
            v270 = unknown_libname_97(&v519);
            v285 = v271;
            v388 = &v285;
            v294 = sub_4E3E5E0(v270);
            sub_4FE3630(*(HWND *)((char *)v521 + 6), 0x69u, v285);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v519);
            goto LABEL_1068;
          case 133:
            v518 = pGLOBAL_HIS_TRENDLINE;
            v517 = 0;
            if ( !pGLOBAL_HIS_TRENDLINE || *(_DWORD *)((char *)v518 + 49) < 1 )
              QDataEngine::PostBroadcastCommand(0x88u, 0);
            sub_4E24CC0(&v512);
            sub_4D31770((char *)this + 1186);
            sub_4E262E0((char *)this + 1226);
            for ( i2 = 0; i2 < *(_DWORD *)((char *)v518 + 49); ++i2 )
            {
              v513 = *(_DWORD *)((char *)v518 + 22 * i2 + 54);
              v514 = *(_DWORD *)((char *)v518 + 22 * i2 + 58);
              v512 = *((_BYTE *)v518 + 22 * i2 + 53) == 1;
              v515 = *(_DWORD *)((char *)v518 + 22 * i2 + 67);
              v516 = *(_DWORD *)((char *)v518 + 22 * i2 + 71);
              if ( v516 == 1000 )
                v517 = 1;
              if ( v516 == 1000 && v512 == 1 )
              {
                v510 = QDataEngine::GetSeverUserID();
                if ( v510 & 1 )
                {
                  v516 = 1000;
                  v512 = 0;
                }
              }
              sub_4E26270(&v512);
            }
            if ( !v517 )
            {
              sub_4E24CC0(&v507);
              v509 = QDataEngine::GetSeverUserID();
              if ( v509 & 1 )
              {
                v508 = 1000;
                v507 = 0;
              }
              sub_4E26270(&v507);
            }
            (*(void (__thiscall **)(char *))(*(_DWORD *)((char *)this + 1186) + 28))((char *)this + 1186);
            QDataEngine::PostBroadcastCommand(0x88u, 0);
            goto LABEL_1068;
          case 135:
            v776 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            for ( i3 = 0; i3 < *((char *)v776 + 17); ++i3 )
              sub_4E354C0(0, (int)v776 + 210 * i3 + 18, 0);
            goto LABEL_1068;
          case 136:
            v911 = pGLOBAL_HIS_TRENDLINE;
            mfc80xU_293(&v907);
            LOBYTE(v931) = 7;
            v473 = mfc80xU_762(28);
            if ( v473 )
              v374 = sub_4D9CDE0(v473);
            else
              v374 = 0;
            v474 = v374;
            sub_4E3E5E0(v374);
            LOBYTE(v931) = 8;
            v16 = unknown_libname_97(&v910);
            *(_DWORD *)unknown_libname_90(v16) = 0;
            v17 = unknown_libname_97(&v910);
            *(_DWORD *)(unknown_libname_90(v17) + 4) = 0;
            *(_DWORD *)((char *)this + 70) = *((_DWORD *)v911 + 7);
            *(_DWORD *)((char *)this + 46) = *(_DWORD *)((char *)v911 + 47);
            v906 = sub_4D3E720();
            mfc80xU_293(&v908);
            LOBYTE(v931) = 9;
            LightLogger::CLogger::GetLogger(&v909, L"Logon App");
            LOBYTE(v931) = 10;
            ((void (__cdecl *)(char *, const wchar_t *, _DWORD, _DWORD, WCHAR *))mfc80xU_2311)(
              &v908,
              L"rec 738.tp->bResult=%d, m_bLoginUI=%d",
              *((char *)pGLOBAL_HIS_TRENDLINE + 10),
              *((unsigned __int8 *)this + 45),
              v286);
            v285 = mfc80xU_870(&v908);
            v18 = (LightLogger::CLogger *)unknown_libname_97(&v909);
            LightLogger::CLogger::WriteLogLine(v18, (const wchar_t *)v285, v286);
            if ( *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LightLogger::CLogger::GetLogger(&v893, L"Logon App");
              LOBYTE(v931) = 19;
              sub_4D3E590(&Caption, L"(Login Info)VerifyUserLogon", (char)v286);
              v36 = (LightLogger::CLogger *)unknown_libname_97(&v893);
              LightLogger::CLogger::WriteLogLine(v36, &Caption, 10000);
              sub_4D3E590(&Caption, L"(Login Info)user type=%d", *((_BYTE *)v911 + 109));
              v37 = (LightLogger::CLogger *)unknown_libname_97(&v893);
              LightLogger::CLogger::WriteLogLine(v37, &Caption, 10000);
              *(_DWORD *)((char *)this + 1250) = *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6);
              v368 = QDataEngine::GetAppCurVersionType();
              switch ( v368 )
              {
                case 0:
                  if ( !CDataMgr::VerifyLevel2UserLogon(
                          this,
                          *((unsigned __int8 *)v911 + 109),
                          *(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6)) )
                    goto LABEL_127;
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v893);
                  LOBYTE(v931) = 9;
                  sub_4E3C780(&v909);
                  LOBYTE(v931) = 8;
                  mfc80xU_577(&v908);
                  LOBYTE(v931) = 7;
                  sub_4E3C780(&v910);
                  LOBYTE(v931) = 1;
                  mfc80xU_577(&v907);
                  LOBYTE(v931) = 0;
                  sub_4E3C780(&v929);
                  v931 = -1;
                  sub_4E3C780(&v930);
                  break;
                case 1:
                  if ( !CDataMgr::VerifyUserLogon(this, *((_BYTE *)v911 + 109)) )
                  {
                    if ( *((_BYTE *)v911 + 109) == 1 )
                    {
                      *((_BYTE *)this + 496) = (signed int)*((unsigned __int8 *)v911 + 36) < 1;
                    }
                    else if ( *((_BYTE *)v911 + 109) == 2 )
                    {
                      *((_BYTE *)this + 496) = (signed int)*((unsigned __int8 *)v911 + 36) < 2;
                    }
                    goto LABEL_127;
                  }
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v893);
                  LOBYTE(v931) = 9;
                  sub_4E3C780(&v909);
                  LOBYTE(v931) = 8;
                  mfc80xU_577(&v908);
                  LOBYTE(v931) = 7;
                  sub_4E3C780(&v910);
                  LOBYTE(v931) = 1;
                  mfc80xU_577(&v907);
                  LOBYTE(v931) = 0;
                  sub_4E3C780(&v929);
                  v931 = -1;
                  sub_4E3C780(&v930);
                  break;
                case 3:
                  if ( !CDataMgr::VerifyMasterUserLogon(this, *((_BYTE *)v911 + 109)) )
                  {
                    if ( *((_BYTE *)v911 + 109) == 1 )
                      *((_BYTE *)this + 496) = (signed int)*((unsigned __int8 *)v911 + 36) < 1;
                    goto LABEL_127;
                  }
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v893);
                  LOBYTE(v931) = 9;
                  sub_4E3C780(&v909);
                  LOBYTE(v931) = 8;
                  mfc80xU_577(&v908);
                  LOBYTE(v931) = 7;
                  sub_4E3C780(&v910);
                  LOBYTE(v931) = 1;
                  mfc80xU_577(&v907);
                  LOBYTE(v931) = 0;
                  sub_4E3C780(&v929);
                  v931 = -1;
                  sub_4E3C780(&v930);
                  break;
                case 4:
                  if ( !CDataMgr::VerifyLevel2UserLogon(this, *((unsigned __int8 *)v911 + 109), 0) )
                    goto LABEL_127;
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v893);
                  LOBYTE(v931) = 9;
                  sub_4E3C780(&v909);
                  LOBYTE(v931) = 8;
                  mfc80xU_577(&v908);
                  LOBYTE(v931) = 7;
                  sub_4E3C780(&v910);
                  LOBYTE(v931) = 1;
                  mfc80xU_577(&v907);
                  LOBYTE(v931) = 0;
                  sub_4E3C780(&v929);
                  v931 = -1;
                  sub_4E3C780(&v930);
                  break;
                case 5:
                  if ( !CDataMgr::VerifyL1ProUserLogin(this, *((_BYTE *)v911 + 109)) )
                    goto LABEL_127;
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v893);
                  LOBYTE(v931) = 9;
                  sub_4E3C780(&v909);
                  LOBYTE(v931) = 8;
                  mfc80xU_577(&v908);
                  LOBYTE(v931) = 7;
                  sub_4E3C780(&v910);
                  LOBYTE(v931) = 1;
                  mfc80xU_577(&v907);
                  LOBYTE(v931) = 0;
                  sub_4E3C780(&v929);
                  v931 = -1;
                  sub_4E3C780(&v930);
                  break;
                case 6:
                  if ( *((_BYTE *)v911 + 109) == 1 || *((_BYTE *)v911 + 109) == 2 )
                  {
                    if ( !CDataMgr::VerifyHighEndUserLogon(this, *((_BYTE *)v911 + 109)) )
                    {
LABEL_127:
                      LOBYTE(v931) = 10;
                      sub_4E3C780(&v893);
                      *(_DWORD *)((char *)this + 1242) = *((_DWORD *)v911 + 7);
                      QDataEngine::m_nCurUserLoginRight = *((unsigned __int8 *)v911 + 109);
                      CDataMgr::ClearDataOfApp(this);
                      QDataEngine::InitDHKey((const unsigned __int8 *)v911 + 39, 8);
                      v905 = QDataEngine::SetServerInfo((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v911 + 17));
                      if ( v905 || *((_BYTE *)this + 45) )
                      {
                        if ( !*((_BYTE *)this + 45) )
                        {
                          v885 = 0;
                          CDataMgr::RequestCmd(this, 0, 1, 1, &v885, 0);
                        }
                        CGlobalEnv::GetGlobalEnv(&v887);
                        LOBYTE(v931) = 23;
                        v45 = unknown_libname_97(&v910);
                        *(_DWORD *)(unknown_libname_90(v45) + 4) = 0;
                        v365 = unknown_libname_97(&v887);
                        v46 = unknown_libname_97(&v910);
                        v886 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v365 + 36))(v365, v46);
                        PostMessageW(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x501u, 0, v886);
                        LightLogger::CLogger::GetLogger(&v888, L"Logon App");
                        LOBYTE(v931) = 24;
                        sub_4D3E590(&Caption, L"(Login Info)post logon success msg to logondlg", (char)v286);
                        v47 = (LightLogger::CLogger *)unknown_libname_97(&v888);
                        LightLogger::CLogger::WriteLogLine(v47, &Caption, 10000);
                        LOBYTE(v931) = 23;
                        sub_4E3C780(&v888);
                        LOBYTE(v931) = 10;
                        sub_4E3C780(&v887);
                      }
                      else
                      {
                        v889 = 0;
                        CDataMgr::RequestCmd(this, 0, 1, 1, &v889, 0);
                      }
                      QDataEngine::SetCurLoginUserName(QDataEngine::m_LogonInfo);
                      mfc80xU_293(&v913);
                      LOBYTE(v931) = 25;
                      mfc80xU_293(&v903);
                      LOBYTE(v931) = 26;
                      mfc80xU_2311(&v913, (const char *)L".\\config\\user\\lastuser.ini");
                      lpMultiByteStr = QDataEngine::m_LogonInfo;
                      if ( QDataEngine::m_LogonInfo )
                      {
                        v912 = lstrlenA(lpMultiByteStr) + 1;
                        if ( v912 <= 0x3FFFFFFF )
                        {
                          v48 = alloca(2 * v912);
                          v362 = (LPWSTR)&v286;
                          v363 = sub_4D3E5F0((LPWSTR)&v286, lpMultiByteStr, v912, 0);
                        }
                        else
                        {
                          v363 = 0;
                        }
                        v364 = v363;
                      }
                      else
                      {
                        v364 = 0;
                      }
                      mfc80xU_2311(&v903, (const char *)L"%s", v364);
                      v49 = (const WCHAR *)mfc80xU_2461(&v913);
                      v50 = ATL::CW2AEX<128>::CW2AEX<128>(v49);
                      v361 = v50;
                      v51 = (const CHAR *)unknown_libname_97(v50);
                      MakeSureDirectoryPathExists(v51);
                      ATL::CW2AEX<128>::~CW2AEX<128>(&v468);
                      mfc80xU_5398(&v913);
                      mfc80xU_870(&v913);
                      v52 = (const WCHAR *)mfc80xU_870(&v903);
                      WritePrivateProfileStringW(L"config", L"name", v52, (LPCWSTR)0xFFFFFFFF);
                      *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 14) = *((_BYTE *)v911 + 109) == 1
                                                                     && *((_DWORD *)v911 + 7) != 100
                                                                     && QDataEngine::GetAppCurVersionType() == 1;
                      mfc80xU_2311(&v913, (const char *)L".\\config\\UserOwnerId.ini");
                      mfc80xU_2311(&v903, (const char *)L"%d", *(_DWORD *)((char *)this + 41));
                      v285 = mfc80xU_870(&v913);
                      v53 = (const WCHAR *)mfc80xU_870(&v903);
                      WritePrivateProfileStringW(L"user", L"buildversion", v53, (LPCWSTR)v285);
                      CDataMgr::CopyUserCfgFiles(this);
                      sub_4FDD940();
                      if ( *((_BYTE *)v911 + 109) == 1 )
                        *(_DWORD *)((char *)this + 1058) = *((_DWORD *)v911 + 7);
                      else
                        *(_DWORD *)((char *)this + 1058) = 0;
                      QDataEngine::SetLoginInStatus(1);
                      QDataEngine::SetOnlineStatus(1);
                      QDataEngine::PostBroadcastCommand(4u, 0);
                      LOBYTE(v931) = 25;
                      mfc80xU_577(&v903);
                      LOBYTE(v931) = 10;
                      mfc80xU_577(&v913);
                      LOBYTE(v931) = 9;
                      sub_4E3C780(&v909);
                      LOBYTE(v931) = 8;
                      mfc80xU_577(&v908);
                      LOBYTE(v931) = 7;
                      sub_4E3C780(&v910);
                      LOBYTE(v931) = 1;
                      mfc80xU_577(&v907);
                      goto LABEL_1068;
                    }
                    LOBYTE(v931) = 10;
                    sub_4E3C780(&v893);
                    LOBYTE(v931) = 9;
                    sub_4E3C780(&v909);
                    LOBYTE(v931) = 8;
                    mfc80xU_577(&v908);
                    LOBYTE(v931) = 7;
                    sub_4E3C780(&v910);
                    LOBYTE(v931) = 1;
                    mfc80xU_577(&v907);
                    LOBYTE(v931) = 0;
                    sub_4E3C780(&v929);
                    v931 = -1;
                    sub_4E3C780(&v930);
                  }
                  else
                  {
                    CDataMgr::OffLine(this);
                    if ( *((_BYTE *)this + 45) )
                    {
                      v38 = unknown_libname_97(&v910);
                      *(_DWORD *)(unknown_libname_90(v38) + 4) = 5;
                      mfc80xU_776(&v907, &unk_5104B48);
                      v469 = mfc80xU_762(28);
                      LOBYTE(v931) = 20;
                      if ( v469 )
                        v367 = sub_4E26660(v469);
                      else
                        v367 = 0;
                      v470 = v367;
                      LOBYTE(v931) = 19;
                      sub_4E3E5E0(v367);
                      LOBYTE(v931) = 21;
                      v285 = mfc80xU_2895(&v907) + 1;
                      v39 = unknown_libname_97(&v891);
                      unknown_libname_90(v39);
                      sub_4E266D0(v285);
                      v40 = mfc80xU_2895(&v907);
                      v285 = mfc80xU_2460(&v907, v40);
                      v41 = unknown_libname_97(&v891);
                      unknown_libname_90(v41);
                      v42 = (wchar_t *)sub_4E266F0(0);
                      wcscpy(v42, (const wchar_t *)v285);
                      v43 = unknown_libname_97(&v910);
                      unknown_libname_90(v43);
                      sub_4DA7300(&v891);
                      CGlobalEnv::GetGlobalEnv(&v890);
                      LOBYTE(v931) = 22;
                      v366 = unknown_libname_97(&v890);
                      v44 = unknown_libname_97(&v910);
                      v892 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v366 + 36))(v366, v44);
                      PostMessageW(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x501u, 0, v892);
                      LOBYTE(v931) = 21;
                      sub_4E3C780(&v890);
                      LOBYTE(v931) = 19;
                      sub_4E3C780(&v891);
                    }
                    LOBYTE(v931) = 10;
                    sub_4E3C780(&v893);
                    LOBYTE(v931) = 9;
                    sub_4E3C780(&v909);
                    LOBYTE(v931) = 8;
                    mfc80xU_577(&v908);
                    LOBYTE(v931) = 7;
                    sub_4E3C780(&v910);
                    LOBYTE(v931) = 1;
                    mfc80xU_577(&v907);
                    LOBYTE(v931) = 0;
                    sub_4E3C780(&v929);
                    v931 = -1;
                    sub_4E3C780(&v930);
                  }
                  break;
                default:
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v893);
                  LOBYTE(v931) = 9;
                  sub_4E3C780(&v909);
                  LOBYTE(v931) = 8;
                  mfc80xU_577(&v908);
                  LOBYTE(v931) = 7;
                  sub_4E3C780(&v910);
                  LOBYTE(v931) = 1;
                  mfc80xU_577(&v907);
                  LOBYTE(v931) = 0;
                  sub_4E3C780(&v929);
                  v931 = -1;
                  sub_4E3C780(&v930);
                  break;
              }
            }
            else
            {
              lpMultiByteStr = (char *)v911 + 19;
              if ( v911 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-19 )
              {
                v373 = 0;
              }
              else
              {
                v912 = lstrlenA(lpMultiByteStr) + 1;
                if ( v912 <= 0x3FFFFFFF )
                {
                  v19 = alloca(2 * v912);
                  v371 = (LPWSTR)&v286;
                  v372 = sub_4D3E5F0((LPWSTR)&v286, lpMultiByteStr, v912, 0);
                }
                else
                {
                  v372 = 0;
                }
                v373 = v372;
              }
              mfc80xU_2311(&v907, (const char *)L"%s ", v373, v286, v287);
              if ( *((_BYTE *)this + 45) )
              {
                CDataMgr::OffLine(this);
                v20 = unknown_libname_97(&v910);
                *(_DWORD *)(unknown_libname_90(v20) + 4) = 5;
                if ( *(_WORD *)((char *)pGLOBAL_HIS_TRENDLINE + 17) == 11 )
                {
                  v285 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(
                           &CDataMgr::LOGON_IN_FORCE_UPDATE,
                           v286);
                  mfc80xU_2311(&v907, (const char *)L"%s", v285);
                  v21 = unknown_libname_97(&v910);
                  *(_DWORD *)(unknown_libname_90(v21) + 4) = 4;
                }
                if ( *(_WORD *)((char *)pGLOBAL_HIS_TRENDLINE + 17) == 36 )
                {
                  v22 = unknown_libname_97(&v910);
                  *(_DWORD *)(unknown_libname_90(v22) + 4) = 7;
                }
                v471 = mfc80xU_762(28);
                LOBYTE(v931) = 11;
                if ( v471 )
                  v370 = sub_4E26660(v471);
                else
                  v370 = 0;
                v472 = v370;
                LOBYTE(v931) = 10;
                sub_4E3E5E0(v370);
                LOBYTE(v931) = 12;
                v285 = mfc80xU_2895(&v907) + 1;
                v23 = unknown_libname_97(&v900);
                unknown_libname_90(v23);
                sub_4E266D0(v285);
                v24 = mfc80xU_2895(&v907);
                v285 = mfc80xU_2460(&v907, v24);
                v25 = unknown_libname_97(&v900);
                unknown_libname_90(v25);
                v26 = (wchar_t *)sub_4E266F0(0);
                wcscpy(v26, (const wchar_t *)v285);
                v27 = unknown_libname_97(&v910);
                unknown_libname_90(v27);
                sub_4DA7300(&v900);
                CGlobalEnv::GetGlobalEnv(&v897);
                LOBYTE(v931) = 13;
                v369 = unknown_libname_97(&v897);
                v28 = unknown_libname_97(&v910);
                lParam = (*(int (__thiscall **)(int, int))(*(_DWORD *)v369 + 36))(v369, v28);
                PostMessageW(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x501u, 0, lParam);
                LightLogger::CLogger::GetLogger(&v898, L"Logon App");
                LOBYTE(v931) = 14;
                mfc80xU_283(&v899, L"(Login Error)post error msg to logondlg,Error msg is:");
                LOBYTE(v931) = 15;
                mfc80xU_896(&v899, &v907);
                v29 = mfc80xU_2461(&v899);
                sub_4D3E590(&Caption, L"%s", v29);
                mfc80xU_5398(&v899);
                v30 = (LightLogger::CLogger *)unknown_libname_97(&v898);
                LightLogger::CLogger::WriteLogLine(v30, &Caption, 10000);
                LOBYTE(v931) = 14;
                mfc80xU_577(&v899);
                LOBYTE(v931) = 13;
                sub_4E3C780(&v898);
                LOBYTE(v931) = 12;
                sub_4E3C780(&v897);
                LOBYTE(v931) = 10;
                sub_4E3C780(&v900);
              }
              else
              {
                v285 = QDataEngine::m_bIsLoginPass;
                v284 = *(signed __int16 *)((char *)v911 + 17);
                mfc80xU_2311(
                  &v908,
                  (const char *)L"rec 738. response)->body.nErrorId=%d, QDataEngine::m_bIsLoginPass=%d",
                  v284,
                  QDataEngine::m_bIsLoginPass);
                v285 = mfc80xU_870(&v908);
                v31 = (LightLogger::CLogger *)unknown_libname_97(&v909);
                LightLogger::CLogger::WriteLogLine(v31, (const wchar_t *)v285, v286);
                if ( *(_WORD *)((char *)v911 + 17) == 36 )
                {
                  CDataMgr::OffLine(this);
                  Sleep(0x1388u);
                  if ( QDataEngine::m_bIsLoginPass )
                  {
                    memset(&Src, 0, 0x400u);
                    sub_4E33A30(&Src, QDataEngine::m_szPassData);
                    CDataMgr::LogonFromPass(
                      this,
                      0,
                      QDataEngine::m_LogonInfo,
                      byte_51A7448,
                      QDataEngine::m_nPassDataLen,
                      &Src,
                      dword_51A7548,
                      (struct _PROXY_SERADDR_TAG_ *)&unk_51A7568);
                  }
                  else
                  {
                    CDataMgr::Logon(
                      this,
                      0,
                      QDataEngine::m_LogonInfo,
                      byte_51A7448,
                      dword_51A7548,
                      (struct _PROXY_SERADDR_TAG_ *)&unk_51A7568);
                  }
                  LightLogger::CLogger::GetLogger(&v896, L"Logon App");
                  LOBYTE(v931) = 16;
                  sub_4D3E590(&Caption, L"(Login Error)post errorid =36", (char)v286);
                  v32 = (LightLogger::CLogger *)unknown_libname_97(&v896);
                  LightLogger::CLogger::WriteLogLine(v32, &Caption, 10000);
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v896);
                }
                else
                {
                  CDataMgr::OffLine(this);
                  LightLogger::CLogger::GetLogger(&v894, L"Logon App");
                  LOBYTE(v931) = 17;
                  sub_4D3E590(&Caption, L"(Login Error)pop logonDlg", (char)v286);
                  v33 = (LightLogger::CLogger *)unknown_libname_97(&v894);
                  LightLogger::CLogger::WriteLogLine(v33, &Caption, 10000);
                  v282 = (int *)std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(
                                  &CDataMgr::AUTO_CONNECT_LOGON_ERROR_TITTLE,
                                  48);
                  v283 = (char *)mfc80xU_870(&v907);
                  v34 = unknown_libname_97(&v929);
                  MessageBoxW(*(HWND *)(v34 + 156), (LPCWSTR)v283, (LPCWSTR)v284, v285);
                  CDataMgr::ShowLogonDlg(this);
                  LOBYTE(v931) = 10;
                  sub_4E3C780(&v894);
                }
              }
              LightLogger::CLogger::GetLogger(&v902, L"Logon App");
              LOBYTE(v931) = 18;
              sub_4D3E590(&Caption, L"(Login Error)errorId:%d", *(_WORD *)((char *)v911 + 17));
              v35 = (LightLogger::CLogger *)unknown_libname_97(&v902);
              LightLogger::CLogger::WriteLogLine(v35, &Caption, 10000);
              LOBYTE(v931) = 10;
              sub_4E3C780(&v902);
              LOBYTE(v931) = 9;
              sub_4E3C780(&v909);
              LOBYTE(v931) = 8;
              mfc80xU_577(&v908);
              LOBYTE(v931) = 7;
              sub_4E3C780(&v910);
              LOBYTE(v931) = 1;
              mfc80xU_577(&v907);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
            }
            return;
          case 139:
          case 145:
            v506 = pGLOBAL_HIS_TRENDLINE;
            v386 = mfc80xU_762(32);
            LOBYTE(v931) = 102;
            if ( v386 )
              v293 = sub_4E26970(v386);
            else
              v293 = 0;
            v387 = v293;
            LOBYTE(v931) = 1;
            sub_4E3E5E0(v293);
            LOBYTE(v931) = 103;
            if ( !unknown_libname_97(&v494) )
            {
              LOBYTE(v931) = 1;
              sub_4E3C780(&v494);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v272 = unknown_libname_97(&v494);
            v273 = (_DWORD *)unknown_libname_90(v272);
            *v273 = *(_DWORD *)((char *)v506 + 17);
            v505 = *(_DWORD *)((char *)v506 + 21);
            for ( i4 = 0; i4 < v505; ++i4 )
            {
              v495 = *(_DWORD *)((char *)v506 + 46 * i4 + 25);
              v496 = *(_DWORD *)((char *)v506 + 46 * i4 + 29);
              v497 = *(_DWORD *)((char *)v506 + 46 * i4 + 33);
              v498 = *(_DWORD *)((char *)v506 + 46 * i4 + 37);
              v499 = *(_DWORD *)((char *)v506 + 46 * i4 + 41);
              v500 = *(_DWORD *)((char *)v506 + 46 * i4 + 45);
              v501 = *(_DWORD *)((char *)v506 + 46 * i4 + 49);
              v502 = *(_DWORD *)((char *)v506 + 46 * i4 + 53);
              v503 = *(_DWORD *)((char *)v506 + 46 * i4 + 57);
              v504 = *(_WORD *)((char *)v506 + 46 * i4 + 61);
              v274 = unknown_libname_97(&v494);
              unknown_libname_90(v274);
              sub_4E259D0(&v495);
            }
            v275 = unknown_libname_97(&v494);
            v285 = v276;
            v385 = &v285;
            v292 = sub_4E3E5E0(v275);
            sub_4FE3630(*(HWND *)((char *)v506 + 6), *((_WORD *)pGLOBAL_HIS_TRENDLINE + 2) != 747 ? 115 : 130, v285);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v494);
            goto LABEL_1068;
          case 151:
            goto LABEL_1033;
          case 175:
            if ( pGLOBAL_HIS_TRENDLINE )
            {
              v485 = pGLOBAL_HIS_TRENDLINE;
              if ( *(signed __int16 *)((char *)pGLOBAL_HIS_TRENDLINE + 17) > 0 )
              {
                v483 = 0;
                v484 = QDataEngine::GetSeverUserID();
                sub_4D31770((char *)this + 1186);
                v486 = sub_4E01B30((char *)this + 1226);
                for ( i5 = 0; i5 < v486; ++i5 )
                {
                  v481 = (_DWORD *)sub_4E26240(i5);
                  if ( v481[4] == 1000 && v484 & 1 )
                  {
                    for ( i6 = 0; i6 < *(signed __int16 *)((char *)v485 + 17); ++i6 )
                    {
                      if ( *(_DWORD *)((char *)v485 + 16 * i6 + 19) == 1 )
                      {
                        if ( v481[1] )
                        {
                          if ( v481[1] >= *(_DWORD *)((char *)v485 + 16 * i6 + 23) )
                            v289 = *(_DWORD *)((char *)v485 + 16 * i6 + 23);
                          else
                            v289 = v481[1];
                          v481[1] = v289;
                        }
                        else
                        {
                          v481[1] = *(_DWORD *)((char *)v485 + 16 * i6 + 23);
                        }
                        if ( v481[2] <= *(_DWORD *)((char *)v485 + 16 * i6 + 27) )
                          v288 = *(_DWORD *)((char *)v485 + 16 * i6 + 27);
                        else
                          v288 = v481[2];
                        v481[2] = v288;
                        v483 = 1;
                      }
                    }
                  }
                }
                (*(void (__thiscall **)(char *))(*(_DWORD *)((char *)this + 1186) + 28))((char *)this + 1186);
                if ( v483 )
                  QDataEngine::PostBroadcastCommand(0x88u, 0);
              }
            }
            goto LABEL_1068;
          case 200:
            v716 = pGLOBAL_HIS_TRENDLINE;
            if ( *(_DWORD *)pGLOBAL_HIS_TRENDLINE <= 0 || !*((_BYTE *)v716 + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::ProcWeiTuoAndSendToUI(this, v716);
            goto LABEL_1068;
          case 201:
            *(_DWORD *)&v585[1] = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v586 = 0;
            v587 = 0;
            v588 = 0;
            v589 = 0;
            v590 = 0;
            v591 = 0;
            v585[0] = 0;
            sub_509F6E0(*(_DWORD *)(*(_DWORD *)&v585[1] + 17), &v586, (int)v585);
            if ( !QDataEngine::AddOrderQueueData(
                    v585[0],
                    &v586,
                    (struct RET_ITEM_ORDER_QUEUE *)(*(_DWORD *)&v585[1] + 22),
                    *(_BYTE *)(*(_DWORD *)&v585[1] + 21)) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( *((_BYTE *)this + 706) )
              CDataMgr::SendOrderListToUI(this, *(HWND *)((char *)this + 702));
            goto LABEL_1068;
          case 202:
            v767 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v767 < 1 )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::ProcTradeDetailAndSendToUI(this, v767);
            goto LABEL_1068;
          case 203:
            v726 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            QDataEngine::SetCancelOrderRank((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v726 + 17));
            CDataMgr::m_bHasCancelOrderData = 1;
            if ( *(_DWORD *)((char *)v726 + 6) )
              CDataMgr::SendCancelOrderDataToUI(this, *(_DWORD *)((char *)v726 + 6));
            else
              CDataMgr::OnTimeSendCancelOrderDataToUI(this, 12);
            goto LABEL_1068;
          case 206:
            pIsGLOBAL_HIS_TRENDLINE = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CGlobalEnv::GetGlobalEnv(&v583);
            LOBYTE(v931) = 87;
            v406 = mfc80xU_762(28);
            if ( v406 )
              v307 = sub_4D9CDE0(v406);
            else
              v307 = 0;
            v407 = v307;
            sub_4E3E5E0(v307);
            LOBYTE(v931) = 88;
            if ( !(unsigned __int8)CDataMgr::ProcT0MoneyFlowData(pIsGLOBAL_HIS_TRENDLINE, &v582) )  //当日资金流处理？？，隐含this对象参数
            {
              LOBYTE(v931) = 87;
              sub_4E3C780(&v582);
              LOBYTE(v931) = 1;
              sub_4E3C780(&v583);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 242));
            for ( i7 = 0; ; ++i7 )
            {
              v233 = sub_4D82EA0((char *)this + 649);
              if ( i7 >= v233 )
                break;
              v306 = unknown_libname_97(&v583);
              v234 = unknown_libname_97(&v582);
              v580 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v306 + 36))(v306, v234);
              v285 = v580;
              v235 = (HWND *)sub_4E3DB70(i7);  //向窗体发送信息，数据推送？？
              sub_4FDD810(*v235, 0x501u, 0x2011u, v285);
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 242));
            EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 266));
            for ( i8 = 0; ; ++i8 )
            {
              v236 = sub_4D82EA0((char *)this + 665);
              if ( i8 >= v236 )
                break;
              v305 = unknown_libname_97(&v583);
              v237 = unknown_libname_97(&v582);
              v578 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v305 + 36))(v305, v237);
              v285 = v578;
              v238 = (HWND *)sub_4E3DB70(i8);
              sub_4FDD810(*v238, 0x501u, 0xEu, v285);
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 266));
            LOBYTE(v931) = 87;
            sub_4E3C780(&v582);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v583);
            goto LABEL_1068;
          case 210:
            v838 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v832 = 0;
            v833 = 0;
            v834 = 0;
            v835 = 0;
            v836 = 0;
            v837 = 0;
            LOBYTE(v831) = 0;
            sub_4DBA1B0((char *)&v831 + 1);
            if ( *(_DWORD *)((char *)v838 + 6) )
            {
              for ( i9 = 0; i9 < *((char *)v838 + 17); ++i9 )
              {
                sub_50A00A0(*(_DWORD *)((char *)v838 + 178 * i9 + 18), &v832, (int)&v831);
                memcpy((char *)&v831 + 1, (char *)v838 + 178 * i9 + 18, 0xB2u);
                QDataEngine::AddSpGZQH_Dyn(v831, &v832, (struct SNAPSHOT_GZQH *)((char *)&v831 + 1));
              }
              CDataMgr::SendMsgToUI(this, *(HWND *)((char *)v838 + 6), 0x25u);
            }
            else
            {
              EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 122));
              if ( (unsigned int)unknown_libname_94((char *)this + 756) < 1 )
              {
                LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 122));
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              for ( i10 = 0; i10 < *((char *)v838 + 17); ++i10 )
              {
                sub_50A00A0(*(_DWORD *)((char *)v838 + 178 * i10 + 18), &v832, (int)&v831);
                memcpy((char *)&v831 + 1, (char *)v838 + 178 * i10 + 18, 0xB2u);
                QDataEngine::AddSpGZQH_Dyn(v831, &v832, (struct SNAPSHOT_GZQH *)((char *)&v831 + 1));
                v828 = sub_509F6C0(&v832, v831);
                sub_4E25DD0(&v827, (int)&v828);
                v92 = sub_4E08970(&v460);
                if ( !(unsigned __int8)sub_4D5CFF0(v92) )
                {
                  sub_4E20840(&v827);
                  sub_4E50EF0(&v826);
                  while ( 1 )
                  {
                    sub_4E20840(&v827);
                    v93 = sub_4D7C7B0(&v458);
                    if ( !(unsigned __int8)sub_4D5B600(v93) )
                      break;
                    v94 = (HWND *)sub_4E37B30(&v826);
                    CDataMgr::SendMsgToUI(this, *v94, 0x25u);
                    sub_4E26560(&v459, 0);
                  }
                }
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 122));
            }
            goto LABEL_1068;
          case 211:
            v694 = pGLOBAL_HIS_TRENDLINE;
            *(_DWORD *)&v695[1] = (char *)pGLOBAL_HIS_TRENDLINE + 17;
            v696 = 0;
            v697 = 0;
            v698 = 0;
            v699 = 0;
            v700 = 0;
            v701 = 0;
            v695[0] = 0;
            if ( sub_509F6E0(*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 17), &v696, (int)v695) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::SendGzqhFengbiToUI(
              this,
              *(HWND *)((char *)v694 + 6),
              *(struct MSG_RET_QUOTE_FENBI_BODY **)&v695[1]);
            break;
          case 214:
            v727 = pGLOBAL_HIS_TRENDLINE;
            CDataMgr::SendRatioPriceToUI(this, *(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 215:
            v533 = pGLOBAL_HIS_TRENDLINE;
            CDataMgr::ProcHundredsL2Quote(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 216:
            v532 = pGLOBAL_HIS_TRENDLINE;
            CDataMgr::ProcOrderQueue(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 217:
            v534 = pGLOBAL_HIS_TRENDLINE;
            CDataMgr::ProcStkMultiL2Quote(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 218:
            CDataMgr::ProcProbUpData(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 219:
            CDataMgr::ProcProbUpDaysData(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 220:
            CDataMgr::ProcHisProbUpData(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          default:
            goto LABEL_1067;
        }
      }
      goto LABEL_1068;
    }
    if ( v381 <= 2003 )
    {
      if ( v381 == 2003 )
      {
LABEL_581:
        v687 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)pGLOBAL_HIS_TRENDLINE + 17);
        v688 = 0;
      }
      else
      {
        v381 -= 1002;
        switch ( v381 )
        {
          case 0:
            v692 = pGLOBAL_HIS_TRENDLINE;
            mfc80xU_293(&v691);
            LOBYTE(v931) = 75;
            v324 = (int *)mfc80xU_287(&v430, (char *)v692 + 18);
            v323 = v324;
            LOBYTE(v931) = 76;
            v285 = *v324;
            mfc80xU_2311(&v691, (const char *)L"%s", v285);
            LOBYTE(v931) = 75;
            mfc80xU_577(&v430);
            if ( *(_DWORD *)((char *)v692 + 34) > 0 )
            {
              v285 = *(_DWORD *)((char *)v692 + 30);
              v284 = *(_DWORD *)((char *)v692 + 26);
              v283 = *(char **)((char *)v692 + 34);
              v282 = (int *)((char *)v692 + 38);
              LODWORD(v281) = *((unsigned __int8 *)v692 + 25);
              HIDWORD(v280) = *((char *)v692 + 17);
              LODWORD(v280) = v692;
              v429 = &v280;
              v322 = mfc80xU_280(&v280, &v691);
              QDataEngine::WriteF10(SBYTE4(v280), LODWORD(v281), v282, v283, v284, v285, v286);
              v286 = (WCHAR *)&v690;
              v285 = (int)&v689;
              v284 = *((unsigned __int8 *)v692 + 25);
              v283 = (char *)*((char *)v692 + 17);
              v282 = (int *)v284;
              v428 = &v282;
              v321 = mfc80xU_280(&v282, &v691);
              CDataMgr::SendF10InfoToUI(*(HWND *)((char *)v692 + 6), SLOBYTE(v281), (int)v282, (int)v283, v284, v285);
            }
            LOBYTE(v931) = 1;
            mfc80xU_577(&v691);
            goto LABEL_1068;
          case 3:
            goto LABEL_581;
          case 4:
          case 5:
            v926 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            *(_DWORD *)((char *)this + 50) = *(_DWORD *)((char *)v926 + 51);
            QDataEngine::SetHisLoginInStatus(1);
            *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 2) = 1;
            goto LABEL_1068;
          case 9:
            v562 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v397 = mfc80xU_762(16);
            if ( v397 )
              v300 = sub_4E268C0(v397);
            else
              v300 = 0;
            v398 = v300;
            sub_4E3E5E0(v300);
            LOBYTE(v931) = 94;
            v248 = unknown_libname_97(&v561);
            v249 = (_DWORD *)unknown_libname_90(v248);
            *v249 = *(_DWORD *)((char *)v562 + 17);
            v250 = unknown_libname_97(&v561);
            v285 = v251;
            v396 = &v285;
            v299 = sub_4E3E5E0(v250);
            sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x44u, v285);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v561);
            goto LABEL_1068;
          case 10:
            v559 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || *((char *)v559 + 10) < 1 || (signed int)*((unsigned __int8 *)v559 + 17) < 1 )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v394 = mfc80xU_762(56);
            LOBYTE(v931) = 95;
            if ( v394 )
              v298 = sub_4E268E0(v394);
            else
              v298 = 0;
            v395 = v298;
            LOBYTE(v931) = 1;
            sub_4E3E5E0(v298);
            LOBYTE(v931) = 96;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(&v557);
            LOBYTE(v931) = 97;
            v560 = *((_BYTE *)v559 + 17);
            v555 = (signed __int16 *)((char *)v559 + 18);
            v558 = 1;
            while ( v560 > 0 )
            {
              v393 = (void *)mfc80xU_265(*v555 + 1);
              v554 = v393;
              memcpy(v393, v555 + 1, *v555);
              *((_BYTE *)v554 + *v555) = 0;
              v553 = v555;
              v555 = (signed __int16 *)((char *)v555 + *v555 + 2);
              if ( v558 )
              {
                v285 = (int)v554;
                v252 = unknown_libname_97(&v556);
                v253 = unknown_libname_90(v252);
                std::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(v253, v285);
                v558 = 0;
              }
              else
              {
                std::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(&v557, v554);
                v254 = unknown_libname_97(&v556);
                unknown_libname_90(v254);
                sub_4D48EF0(&v557);
              }
              --v560;
              if ( v554 )
              {
                v392 = v554;
                mfc80xU_266(v554);
                v554 = 0;
              }
            }
            v255 = unknown_libname_97(&v556);
            v285 = v256;
            v391 = &v285;
            v297 = sub_4E3E5E0(v255);
            sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x45u, v285);
            LOBYTE(v931) = 96;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v557);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v556);
            goto LABEL_1068;
          case 12:
            v713 = pGLOBAL_HIS_TRENDLINE;
            v326 = mfc80xU_287(&v431, (char *)pGLOBAL_HIS_TRENDLINE + 18);
            v325 = v326;
            LOBYTE(v931) = 74;
            v285 = *(_DWORD *)((char *)v713 + 25);
            v204 = (const wchar_t *)mfc80xU_870(v326);
            QDataEngine::SaveGzqhHisRtData(
              (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v713 + 31),
              *(signed __int16 *)((char *)v713 + 29),
              *((_BYTE *)v713 + 17),
              v204,
              v285);
            LOBYTE(v931) = 1;
            mfc80xU_577(&v431);
            CDataMgr::SendHisTrendDataToUI(
              this,
              *(HWND *)((char *)v713 + 6),
              (char *)v713 + 18,
              *((_BYTE *)v713 + 17),
              *(_DWORD *)((char *)v713 + 25));
            goto LABEL_1068;
          case 13:
            v545 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v545 + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::ProcHisTrendData(this, v545);
            goto LABEL_1068;
          case 14:
          case 17:
            v544 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v544 + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            CDataMgr::ProcHisTrendCfsData(this, v544);
            goto LABEL_1068;
          case 18:
            CDataMgr::ProcHisDayKlineData(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 19:
            CDataMgr::ProcHisMinKlineData(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 20:
            CDataMgr::ProcGloabalHisStkTrend(this, pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          case 21:
            v535 = pGLOBAL_HIS_TRENDLINE;
            CDataMgr::ProcHisRtLineValidDays(
              this,
              *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 17),
              (LPCSTR)pGLOBAL_HIS_TRENDLINE + 18,
              (int *)((char *)pGLOBAL_HIS_TRENDLINE + 38),
              *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 34),
              77,
              *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6));
            goto LABEL_1068;
          case 22:
            v537 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v537 + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            LOBYTE(v536) = 0;
            MultiByteStr = 0;
            v539 = 0;
            v540 = 0;
            v541 = 0;
            v542 = 0;
            v543 = 0;
            *(int *)((char *)&v536 + 1) = sub_50A00A0(*(_DWORD *)((char *)v537 + 17), &MultiByteStr, (int)&v536);
            if ( *(int *)((char *)&v536 + 1) == -1 )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v285 = *(_DWORD *)((char *)v537 + 6);
            v284 = 77;
            CDataMgr::ProcHisRtLineValidDays(
              this,
              v536,
              &MultiByteStr,
              (int *)((char *)v537 + 25),
              *(_DWORD *)((char *)v537 + 21),
              77,
              v285);
            goto LABEL_1068;
          case 25:
            v761 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v456 = mfc80xU_762(32);
            if ( v456 )
              v348 = sub_4DD6540(v456);
            else
              v348 = 0;
            v457 = v348;
            sub_4E3E5E0(v348);
            LOBYTE(v931) = 53;
            v126 = unknown_libname_97(&v763);
            v127 = (_BYTE *)unknown_libname_90(v126);
            *v127 = *((_BYTE *)v761 + 17);
            v285 = (int)v761 + 18;
            v128 = unknown_libname_97(&v763);
            v129 = unknown_libname_90(v128);
            strcpy_s((char *)(v129 + 1), 0x10u, (const char *)v285);
            CGlobalEnv::GetGlobalEnv(&v759);
            LOBYTE(v931) = 54;
            v454 = mfc80xU_762(28);
            if ( v454 )
              v347 = sub_4D9CDE0(v454);
            else
              v347 = 0;
            v455 = v347;
            sub_4E3E5E0(v347);
            LOBYTE(v931) = 55;
            v130 = unknown_libname_97(&v762);
            *(_DWORD *)unknown_libname_90(v130) = 41;
            v131 = unknown_libname_97(&v762);
            unknown_libname_90(v131);
            sub_4DA7300(&v763);
            v764 = CDataMgr::ChangeCycleNetToUI(this, *((unsigned __int8 *)v761 + 41));
            if ( *(_DWORD *)((char *)v761 + 42) <= 0 || v764 < 0 )
            {
              v133 = unknown_libname_97(&v762);
              *(_DWORD *)(unknown_libname_90(v133) + 4) = 6;
            }
            else
            {
              QDataEngine::Add_HisData(
                *((_BYTE *)v761 + 17),
                (char *)v761 + 18,
                v764,
                *(_DWORD *)((char *)v761 + 42),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v761 + 46));
              v132 = unknown_libname_97(&v762);
              *(_DWORD *)(unknown_libname_90(v132) + 4) = 0;
            }
            v346 = unknown_libname_97(&v759);
            v134 = unknown_libname_97(&v762);
            v760 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v346 + 36))(v346, v134);
            sub_4FDD810(*(HWND *)((char *)v761 + 6), 0x501u, 0x29u, v760);
            LOBYTE(v931) = 54;
            sub_4E3C780(&v762);
            LOBYTE(v931) = 53;
            sub_4E3C780(&v759);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v763);
            goto LABEL_1068;
          case 26:
LABEL_488:
            v744 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v444 = mfc80xU_762(32);
            if ( v444 )
              v339 = sub_4DD6540(v444);
            else
              v339 = 0;
            v445 = v339;
            sub_4E3E5E0(v339);
            LOBYTE(v931) = 62;
            v153 = unknown_libname_97(&v746);
            v154 = (_BYTE *)unknown_libname_90(v153);
            *v154 = *((_BYTE *)v744 + 17);
            v285 = (int)v744 + 18;
            v155 = unknown_libname_97(&v746);
            v156 = unknown_libname_90(v155);
            strcpy_s((char *)(v156 + 1), 0x10u, (const char *)v285);
            CGlobalEnv::GetGlobalEnv(&v742);
            LOBYTE(v931) = 63;
            v442 = mfc80xU_762(28);
            if ( v442 )
              v338 = sub_4D9CDE0(v442);
            else
              v338 = 0;
            v443 = v338;
            sub_4E3E5E0(v338);
            LOBYTE(v931) = 64;
            v157 = unknown_libname_97(&v745);
            *(_DWORD *)unknown_libname_90(v157) = 41;
            v158 = unknown_libname_97(&v745);
            unknown_libname_90(v158);
            sub_4DA7300(&v746);
            sub_4D5A3B0(&v741);
            LOBYTE(v931) = 65;
            v748 = CDataMgr::ChangeCycleNetToUI(this, *((unsigned __int8 *)v744 + 41));
            if ( *(_DWORD *)((char *)v744 + 42) <= 0 || v748 < 0 )
            {
              v161 = unknown_libname_97(&v745);
              *(_DWORD *)(unknown_libname_90(v161) + 4) = 6;
            }
            else
            {
              for ( i11 = 0; i11 < *(_DWORD *)((char *)v744 + 42); ++i11 )
              {
                memcpy(&v747, (char *)v744 + 52 * i11 + 46, 0x20u);
                sub_4E26820(&v747);
              }
              v159 = (struct DAYDATA *)sub_4E267F0(0);
              QDataEngine::Add_HisData(
                *((_BYTE *)v744 + 17),
                (char *)v744 + 18,
                v748,
                *(_DWORD *)((char *)v744 + 42),
                v159);
              QDataEngine::Add_GZQHHisData(
                *((_BYTE *)v744 + 17),
                (char *)v744 + 18,
                v748,
                *(_DWORD *)((char *)v744 + 42),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v744 + 46));
              v160 = unknown_libname_97(&v745);
              *(_DWORD *)(unknown_libname_90(v160) + 4) = 0;
            }
            v337 = unknown_libname_97(&v742);
            v162 = unknown_libname_97(&v745);
            v743 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v337 + 36))(v337, v162);
            v285 = v743;
            v284 = 41;
            v283 = (char *)1281;
            v282 = *(int **)((char *)v744 + 6);
            v163 = CDataMgr::GetReceiverSafeHandle(this);
            CViewManager::PostExDataMessage(v163, (unsigned int)v282, 0x501u, 0x29u, v285);
            LOBYTE(v931) = 64;
            sub_4D65180(&v741);
            LOBYTE(v931) = 63;
            sub_4E3C780(&v745);
            LOBYTE(v931) = 62;
            sub_4E3C780(&v742);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v746);
            goto LABEL_1068;
          case 27:
            CGlobalEnv::GetGlobalEnv(&v602);
            LOBYTE(v931) = 82;
            v413 = mfc80xU_762(28);
            if ( v413 )
              v311 = sub_4D9CDE0(v413);
            else
              v311 = 0;
            v414 = v311;
            sub_4E3E5E0(v311);
            LOBYTE(v931) = 83;
            v411 = mfc80xU_762(32);
            if ( v411 )
              v310 = sub_4DD6540(v411);
            else
              v310 = 0;
            v412 = v310;
            sub_4E3E5E0(v310);
            LOBYTE(v931) = 84;
            v606 = pGLOBAL_HIS_TRENDLINE;
            if ( !pGLOBAL_HIS_TRENDLINE || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
            {
              LOBYTE(v931) = 83;
              sub_4E3C780(&v605);
              LOBYTE(v931) = 82;
              sub_4E3C780(&v604);
              LOBYTE(v931) = 1;
              sub_4E3C780(&v602);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            if ( strlen((const char *)v606 + 18) < 1 )
            {
              LOBYTE(v931) = 83;
              sub_4E3C780(&v605);
              LOBYTE(v931) = 82;
              sub_4E3C780(&v604);
              LOBYTE(v931) = 1;
              sub_4E3C780(&v602);
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v225 = unknown_libname_97(&v605);
            v226 = (_BYTE *)unknown_libname_90(v225);
            *v226 = *((_BYTE *)v606 + 17);
            v285 = (int)v606 + 18;
            v227 = unknown_libname_97(&v605);
            v228 = unknown_libname_90(v227);
            strcpy_s((char *)(v228 + 1), 0x10u, (const char *)v285);
            v229 = unknown_libname_97(&v604);
            unknown_libname_90(v229);
            sub_4DA7300(&v605);
            v230 = unknown_libname_97(&v604);
            *(_DWORD *)unknown_libname_90(v230) = 52;
            if ( *(_DWORD *)((char *)v606 + 42) <= 0 )
            {
              v232 = unknown_libname_97(&v604);
              *(_DWORD *)(unknown_libname_90(v232) + 4) = 6;
            }
            else
            {
              v596 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v606 + 46);
              if ( v606 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-46 )
              {
                LOBYTE(v931) = 83;
                sub_4E3C780(&v605);
                LOBYTE(v931) = 82;
                sub_4E3C780(&v604);
                LOBYTE(v931) = 1;
                sub_4E3C780(&v602);
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              v410 = (void *)mfc80xU_265(168 * *(_DWORD *)((char *)v606 + 42) | -(168
                                                                                * (unsigned __int64)*(unsigned int *)((char *)v606 + 42) >> 32 != 0));
              v598 = v410;
              memset(v410, 0, 168 * *(_DWORD *)((char *)v606 + 42));
              mfc80xU_293(&v594);
              LOBYTE(v931) = 85;
              sub_509CC40((LPCSTR)v606 + 18, (int)&v594);
              v599 = CDataMgr::ChangeCycleNetToUI(this, *((unsigned __int8 *)v606 + 41));
              v601 = 0;
              v593 = 0;
              for ( i12 = 0.0; SLODWORD(i12) < *(_DWORD *)((char *)v606 + 42); ++LODWORD(i12) )
              {
                *((_DWORD *)v598 + 42 * LODWORD(i12)) = *((_DWORD *)v596 + 41 * LODWORD(i12));
                if ( v599 < 9 )
                {
                  v285 = (int)&v593;
                  v284 = (int)&v601;
                  v283 = (char *)v598;
                  v282 = *(int **)((char *)v606 + 42);
                  v281 = i12;
                  v280 = COERCE_DOUBLE(__PAIR__(v599, (unsigned int)v282));
                  v409 = &v280;
                  v309 = mfc80xU_280(&v280, &v594);
                  sub_50A0E00(*((char *)v606 + 17), SLOBYTE(v280), HIDWORD(v280), LODWORD(v281), v282, v283, v284, v285);
                  *((_DWORD *)v598 + 42 * LODWORD(i12) + 1) = 0;
                }
                *((_DWORD *)v598 + 42 * LODWORD(i12) + 1) = 100 * (v593 + 100 * v601);
                memcpy((char *)v598 + 168 * LODWORD(i12) + 8, (char *)v596 + 164 * LODWORD(i12) + 4, 0xA0u);
              }
              v595 = -1;
              std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v600);
              LOBYTE(v931) = 86;
              sub_509CB80((LPCSTR)v606 + 18, (int)&v600);
              v285 = (int)&v595;
              v284 = *(_DWORD *)((char *)v606 + 42);
              v283 = (char *)v598;
              v282 = &v600;
              v281 = *(float *)&v599;
              v597 = QDataEngine::WriteCapitalFlowKLineData(
                       *((_BYTE *)v606 + 17),
                       v599,
                       (int)&v600,
                       v598,
                       v284,
                       (int)&v595);
              if ( v598 )
              {
                v408 = v598;
                mfc80xU_266(v598);
                v598 = 0;
              }
              if ( v597 < 1 )
              {
                LOBYTE(v931) = 85;
                std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v600);
                LOBYTE(v931) = 84;
                mfc80xU_577(&v594);
                LOBYTE(v931) = 83;
                sub_4E3C780(&v605);
                LOBYTE(v931) = 82;
                sub_4E3C780(&v604);
                LOBYTE(v931) = 1;
                sub_4E3C780(&v602);
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              v231 = unknown_libname_97(&v604);
              *(_DWORD *)(unknown_libname_90(v231) + 4) = 0;
              LOBYTE(v931) = 85;
              std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v600);
              LOBYTE(v931) = 84;
              mfc80xU_577(&v594);
            }
            v308 = unknown_libname_97(&v602);
            v285 = unknown_libname_97(&v604);
            v603 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v308 + 36))(v308, v285);
            v285 = v603;
            v284 = 52;
            v283 = (char *)1281;
            sub_4FDD810(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x501u, 0x34u, v603);
            LOBYTE(v931) = 83;
            sub_4E3C780(&v605);
            LOBYTE(v931) = 82;
            sub_4E3C780(&v604);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v602);
            goto LABEL_1068;
          case 29:
            v756 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v452 = mfc80xU_762(32);
            if ( v452 )
              v345 = sub_4DD6540(v452);
            else
              v345 = 0;
            v453 = v345;
            sub_4E3E5E0(v345);
            LOBYTE(v931) = 56;
            v135 = unknown_libname_97(&v758);
            v136 = (_BYTE *)unknown_libname_90(v135);
            *v136 = *((_BYTE *)v756 + 17);
            v285 = (int)v756 + 18;
            v137 = unknown_libname_97(&v758);
            v138 = unknown_libname_90(v137);
            strcpy_s((char *)(v138 + 1), 0x10u, (const char *)v285);
            CGlobalEnv::GetGlobalEnv(&v754);
            LOBYTE(v931) = 57;
            v450 = mfc80xU_762(28);
            if ( v450 )
              v344 = sub_4D9CDE0(v450);
            else
              v344 = 0;
            v451 = v344;
            sub_4E3E5E0(v344);
            LOBYTE(v931) = 58;
            v139 = unknown_libname_97(&v757);
            *(_DWORD *)unknown_libname_90(v139) = 118;
            v140 = unknown_libname_97(&v757);
            unknown_libname_90(v140);
            sub_4DA7300(&v758);
            if ( *(_DWORD *)((char *)v756 + 26) )
            {
              QDataEngine::WriteMarginTradeHisData(
                (LPCSTR)v756 + 18,
                *((char *)v756 + 17),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v756 + 30),
                *(_DWORD *)((char *)v756 + 26));
              v141 = unknown_libname_97(&v757);
              *(_DWORD *)(unknown_libname_90(v141) + 4) = 0;
            }
            else
            {
              v142 = unknown_libname_97(&v757);
              *(_DWORD *)(unknown_libname_90(v142) + 4) = 6;
            }
            v343 = unknown_libname_97(&v754);
            v143 = unknown_libname_97(&v757);
            v755 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v343 + 36))(v343, v143);
            sub_4FDD810(*(HWND *)((char *)v756 + 6), 0x501u, 0x76u, v755);
            LOBYTE(v931) = 57;
            sub_4E3C780(&v757);
            LOBYTE(v931) = 56;
            sub_4E3C780(&v754);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v758);
            goto LABEL_1068;
          case 30:
            v735 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v440 = mfc80xU_762(32);
            if ( v440 )
              v336 = sub_4DD6540(v440);
            else
              v336 = 0;
            v441 = v336;
            sub_4E3E5E0(v336);
            LOBYTE(v931) = 66;
            v285 = (int)v735 + 17;
            v164 = unknown_libname_97(&v737);
            v165 = unknown_libname_90(v164);
            strcpy_s((char *)(v165 + 1), 0x10u, (const char *)v285);
            CGlobalEnv::GetGlobalEnv(&v733);
            LOBYTE(v931) = 67;
            v438 = mfc80xU_762(28);
            if ( v438 )
              v335 = sub_4D9CDE0(v438);
            else
              v335 = 0;
            v439 = v335;
            sub_4E3E5E0(v335);
            LOBYTE(v931) = 68;
            v166 = unknown_libname_97(&v736);
            *(_DWORD *)unknown_libname_90(v166) = 116;
            v167 = unknown_libname_97(&v736);
            unknown_libname_90(v167);
            sub_4DA7300(&v737);
            v738 = CDataMgr::ChangeCycleNetToUI(this, *((unsigned __int8 *)v735 + 24));
            v739 = strcmp((const char *)v735 + 17, "HGT") != 0 ? 116 : 1;
            if ( *(_DWORD *)((char *)v735 + 25) <= 0 )
            {
              v169 = unknown_libname_97(&v736);
              *(_DWORD *)(unknown_libname_90(v169) + 4) = 6;
            }
            else
            {
              QDataEngine::WriteHgtLimitHisData(
                (char *)v735 + 17,
                v739,
                (char *)v735 + 29,
                *(_DWORD *)((char *)v735 + 25),
                v738);
              v168 = unknown_libname_97(&v736);
              *(_DWORD *)(unknown_libname_90(v168) + 4) = 0;
            }
            v334 = unknown_libname_97(&v733);
            v170 = unknown_libname_97(&v736);
            v734 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v334 + 36))(v334, v170);
            sub_4FDD810(*(HWND *)((char *)v735 + 6), 0x501u, 0x74u, v734);
            LOBYTE(v931) = 67;
            sub_4E3C780(&v736);
            LOBYTE(v931) = 66;
            sub_4E3C780(&v733);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v737);
            goto LABEL_1068;
          case 33:
            v751 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v448 = mfc80xU_762(32);
            if ( v448 )
              v342 = sub_4DD6540(v448);
            else
              v342 = 0;
            v449 = v342;
            sub_4E3E5E0(v342);
            LOBYTE(v931) = 59;
            v144 = unknown_libname_97(&v753);
            v145 = (_BYTE *)unknown_libname_90(v144);
            *v145 = *((_BYTE *)v751 + 17);
            v285 = (int)v751 + 18;
            v146 = unknown_libname_97(&v753);
            v147 = unknown_libname_90(v146);
            strcpy_s((char *)(v147 + 1), 0x10u, (const char *)v285);
            CGlobalEnv::GetGlobalEnv(&v749);
            LOBYTE(v931) = 60;
            v446 = mfc80xU_762(28);
            if ( v446 )
              v341 = sub_4D9CDE0(v446);
            else
              v341 = 0;
            v447 = v341;
            sub_4E3E5E0(v341);
            LOBYTE(v931) = 61;
            v148 = unknown_libname_97(&v752);
            *(_DWORD *)unknown_libname_90(v148) = 119;
            v149 = unknown_libname_97(&v752);
            unknown_libname_90(v149);
            sub_4DA7300(&v753);
            if ( *(_DWORD *)((char *)v751 + 42) <= 0 )
            {
              v151 = unknown_libname_97(&v752);
              *(_DWORD *)(unknown_libname_90(v151) + 4) = 6;
            }
            else
            {
              QDataEngine::WriteIndexStatHisData(
                (LPCSTR)v751 + 18,
                *((char *)v751 + 17),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v751 + 46),
                *(_DWORD *)((char *)v751 + 42));
              v150 = unknown_libname_97(&v752);
              *(_DWORD *)(unknown_libname_90(v150) + 4) = 0;
            }
            v340 = unknown_libname_97(&v749);
            v152 = unknown_libname_97(&v752);
            v750 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v340 + 36))(v340, v152);
            sub_4FDD810(*(HWND *)((char *)v751 + 6), 0x501u, 0x77u, v750);
            LOBYTE(v931) = 60;
            sub_4E3C780(&v752);
            LOBYTE(v931) = 59;
            sub_4E3C780(&v749);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v753);
            goto LABEL_1068;
          case 38:
            v730 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            v436 = mfc80xU_762(76);
            if ( v436 )
              v333 = sub_4E26890(v436);
            else
              v333 = 0;
            v437 = v333;
            sub_4E3E5E0(v333);
            LOBYTE(v931) = 69;
            v285 = (int)v730 + 25;
            v171 = unknown_libname_97(&v732);
            v172 = unknown_libname_90(v171);
            strcpy_s((char *)(v172 + 1), 0x10u, (const char *)v285);
            v173 = unknown_libname_97(&v732);
            v174 = (_BYTE *)unknown_libname_90(v173);
            *v174 = *((_BYTE *)v730 + 19);
            v175 = unknown_libname_97(&v732);
            v176 = unknown_libname_90(v175);
            *(_BYTE *)(v176 + 17) = *((_BYTE *)v730 + 18);
            v177 = unknown_libname_97(&v732);
            v178 = unknown_libname_90(v177);
            *(_DWORD *)(v178 + 18) = *(_DWORD *)((char *)v730 + 41);
            v179 = unknown_libname_97(&v732);
            v180 = unknown_libname_90(v179);
            *(_DWORD *)(v180 + 22) = *(_DWORD *)((char *)v730 + 45);
            v181 = unknown_libname_97(&v732);
            v182 = unknown_libname_90(v181);
            *(_DWORD *)(v182 + 26) = *(_DWORD *)((char *)v730 + 49);
            v183 = unknown_libname_97(&v732);
            v184 = unknown_libname_90(v183);
            *(_DWORD *)(v184 + 30) = *(_DWORD *)((char *)v730 + 53);
            v185 = unknown_libname_97(&v732);
            v186 = unknown_libname_90(v185);
            *(_DWORD *)(v186 + 34) = *(_DWORD *)((char *)v730 + 57);
            v187 = unknown_libname_97(&v732);
            v188 = unknown_libname_90(v187);
            *(_DWORD *)(v188 + 38) = *(_DWORD *)((char *)v730 + 61);
            v189 = unknown_libname_97(&v732);
            v190 = unknown_libname_90(v189);
            *(_DWORD *)(v190 + 42) = *(_DWORD *)((char *)v730 + 65);
            v191 = unknown_libname_97(&v732);
            v192 = unknown_libname_90(v191);
            *(_DWORD *)(v192 + 46) = *(_DWORD *)((char *)v730 + 69);
            v193 = unknown_libname_97(&v732);
            v194 = unknown_libname_90(v193);
            *(_DWORD *)(v194 + 50) = *(_DWORD *)((char *)v730 + 73);
            v195 = unknown_libname_97(&v732);
            v196 = unknown_libname_90(v195);
            v197 = v730;
            *(_DWORD *)(v196 + 54) = *(_DWORD *)((char *)v730 + 77);
            *(_DWORD *)(v196 + 58) = *(_DWORD *)((char *)v197 + 81);
            CGlobalEnv::GetGlobalEnv(&v728);
            LOBYTE(v931) = 70;
            v434 = mfc80xU_762(28);
            if ( v434 )
              v332 = sub_4D9CDE0(v434);
            else
              v332 = 0;
            v435 = v332;
            sub_4E3E5E0(v332);
            LOBYTE(v931) = 71;
            v198 = unknown_libname_97(&v731);
            *(_DWORD *)unknown_libname_90(v198) = 131;
            v199 = unknown_libname_97(&v731);
            unknown_libname_90(v199);
            sub_4DA7300(&v732);
            v200 = unknown_libname_97(&v731);
            *(_DWORD *)(unknown_libname_90(v200) + 4) = 0;
            v331 = unknown_libname_97(&v728);
            v201 = unknown_libname_97(&v731);
            v729 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v331 + 36))(v331, v201);
            sub_4FDD810(*(HWND *)((char *)v730 + 6), 0x501u, 0x83u, v729);
            LOBYTE(v931) = 70;
            sub_4E3C780(&v731);
            LOBYTE(v931) = 69;
            sub_4E3C780(&v728);
            LOBYTE(v931) = 1;
            sub_4E3C780(&v732);
            break;
          default:
            goto LABEL_1067;
        }
      }
      goto LABEL_1068;
    }
    if ( v381 > 8001 )
    {
      v381 -= 8002;
      switch ( v381 )
      {
        case 0:
LABEL_1033:
          if ( pGLOBAL_HIS_TRENDLINE )
          {
            v492 = pGLOBAL_HIS_TRENDLINE;
            if ( *((_WORD *)pGLOBAL_HIS_TRENDLINE + 2) == 753 )
              QDataEngine::SetAppServerCurDate(*(_DWORD *)((char *)v492 + 17), *(_DWORD *)((char *)v492 + 21));
            if ( *((_BYTE *)v492 + 25) & 1 )
            {
              wsprintfW(
                &v488,
                L"server alive type = %d, %d",
                *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2),
                *((unsigned __int8 *)v492 + 25));
              LightLogger::CLogger::GetLogger(&v489, L"ProcServerList");
              LOBYTE(v931) = 104;
              v277 = (LightLogger::CLogger *)unknown_libname_97(&v489);
              LightLogger::CLogger::WriteLogLine(v277, &v488, 20000);
              sub_4DC3800(&v490);
              v490 = 1;
              if ( !strcmp(QDataEngine::m_LogonInfo, "guest") && !strcmp(byte_51A7448, "guest") )
              {
                strcpy_s(&Dst, 0x20u, "guest");
              }
              else
              {
                v487 = sub_500BCD0();
                v291 = sub_4D62D80(&v384);
                v290 = v291;
                LOBYTE(v931) = 105;
                v278 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(v291);
                strcpy_s(&Dst, 0x20u, v278);
                LOBYTE(v931) = 104;
                std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v384);
              }
              CDataMgr::RequestCmd(this, 0, 125, 1, &v490, 0);
              LOBYTE(v931) = 1;
              sub_4E3C780(&v489);
            }
          }
          goto LABEL_1068;
        case 98:
          v531 = pGLOBAL_HIS_TRENDLINE;
          CDataMgr::ProcGssStkListData(this, pGLOBAL_HIS_TRENDLINE);
          goto LABEL_1068;
        case 101:
          v530 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v530 + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcGlobalStkTrend(this, v530);
          goto LABEL_1068;
        case 102:
          v529 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v529 + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcGlobalStkKLine(this, v529);
          goto LABEL_1068;
        case 103:
          v527 = pGLOBAL_HIS_TRENDLINE;
          CDataMgr::ProcGssStkDetailData(this, pGLOBAL_HIS_TRENDLINE);
          goto LABEL_1068;
        case 106:
          CDataMgr::ProcGssMarketInfo(this, pGLOBAL_HIS_TRENDLINE);
          goto LABEL_1068;
        case 107:
          CDataMgr::ProcGssBufferListData(this, pGLOBAL_HIS_TRENDLINE);
          goto LABEL_1068;
        case 108:
          v525 = pGLOBAL_HIS_TRENDLINE;
          v296 = *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 18);
          switch ( v296 )
          {
            case 5:
              v285 = *((unsigned __int8 *)v525 + 19) != 201 ? 1817 : 1811;
              v258 = *(_DWORD *)((char *)this + 1106);
              v524 = sub_50C4CF0(v285);
              if ( !v524 )
              {
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              (*(void (__thiscall **)(int, struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *))(*(_DWORD *)v524 + 4))(v524, v525);
              break;
            case 6:
              CDataMgr::ProcFavGssBkIndexQuoteTable(this, v525);
              break;
            case 7:
              v285 = *((unsigned __int8 *)v525 + 19) != 201 ? 1824 : 1812;
              v259 = *(_DWORD *)((char *)this + 1106);
              v523 = sub_50C4CF0(v285);
              if ( !v523 )
              {
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              (*(void (__thiscall **)(int, struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *))(*(_DWORD *)v523 + 4))(v523, v525);
              break;
            default:
              CDataMgr::ProcGssQuoteTable(this, v525);
              goto LABEL_1068;
          }
          goto LABEL_1068;
        case 109:
          v528 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v528 + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcGlobalStkHQRecord(this, v528);
          goto LABEL_1068;
        case 112:
          CDataMgr::ProcGssBkStkQuoteTable(this, pGLOBAL_HIS_TRENDLINE);
          goto LABEL_1068;
        case 114:
          v522 = pGLOBAL_HIS_TRENDLINE;
          if ( *((_BYTE *)pGLOBAL_HIS_TRENDLINE + 18) != 6 )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcFavGssBkIndexQuoteTable(this, v522);
          goto LABEL_1068;
        case 115:
          v526 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v526 + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcGlobalStkHQEx(this, v526);
          break;
        case 126:
          CDataMgr::ProcGssMarketBkStkQuoteTable(this, pGLOBAL_HIS_TRENDLINE);
          goto LABEL_1068;
        default:
          goto LABEL_1067;
      }
      goto LABEL_1068;
    }
    if ( v381 != 8001 )
    {
      if ( v381 > 4005 )
      {
        if ( v381 >= 4006 )
        {
          if ( v381 <= 4007 )
          {
            v914 = pGLOBAL_HIS_TRENDLINE;
            if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
            {
              LOBYTE(v931) = 0;
              sub_4E3C780(&v929);
              v931 = -1;
              sub_4E3C780(&v930);
              return;
            }
            *(_DWORD *)((char *)this + 62) = *(_DWORD *)((char *)v914 + 51);
            QDataEngine::SetMineLoginInStatus(1);
            *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 5) = 1;
            *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 6) = 1;
            *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 7) = 1;
            goto LABEL_1068;
          }
          if ( v381 == 4180 )
          {
            QDataEngine::ReceiveMineInfo(pGLOBAL_HIS_TRENDLINE);
            goto LABEL_1068;
          }
        }
        goto LABEL_1067;
      }
      switch ( v381 )
      {
        case 4005:
          goto LABEL_1068;
        case 3020:
          v547 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v547 + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcStkTrend(this, v547);
          goto LABEL_1068;
        case 3021:
          v546 = pGLOBAL_HIS_TRENDLINE;
          if ( !pGLOBAL_HIS_TRENDLINE || !*((_BYTE *)v546 + 10) )
          {
            LOBYTE(v931) = 0;
            sub_4E3C780(&v929);
            v931 = -1;
            sub_4E3C780(&v930);
            return;
          }
          CDataMgr::ProcStkTrendCfs(this, v546);
          goto LABEL_1068;
      }
      if ( v381 != 4002 )
      {
LABEL_1067:
        v285 = (int)pGLOBAL_HIS_TRENDLINE;
        v284 = *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2);
        v279 = *(_DWORD *)((char *)this + 1106);
        sub_50C4D60(v284, pGLOBAL_HIS_TRENDLINE);
        goto LABEL_1068;
      }
    }
    v925 = pGLOBAL_HIS_TRENDLINE;
    if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
    {
      LOBYTE(v931) = 0;
      sub_4E3C780(&v929);
      v931 = -1;
      sub_4E3C780(&v930);
      return;
    }
    *(_DWORD *)((char *)this + 66) = *(_DWORD *)((char *)v925 + 51);
    QDataEngine::SetGssLoginInStatus(1);
    *(_BYTE *)(*(_DWORD *)((char *)this + 37) + 4) = 1;
    QDataEngine::SetMcmVersion(*((_DWORD *)v925 + 5));
    if ( *((_BYTE *)this + 1053) )
    {
      CDataMgr::RequestCmd(this, 0, 90, 1, 0, 0);
      *((_BYTE *)this + 1053) = 0;
    }
    CDataMgr::DoSomethingAfterLoginTest(this);
    if ( QDataEngine::GetLoginInStatus() )
      CDataMgr::DoSomethingAfterGssLogin(this);
    CDataMgr::ClearDataOfGss(this);
    goto LABEL_1068;
  }
  if ( v381 != 601 )
  {
    v381 -= 323;
    switch ( v381 )
    {
      case 0:
        v861 = pGLOBAL_HIS_TRENDLINE;
        if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        for ( i13 = 0; i13 < *((signed __int16 *)v861 + 9); ++i13 )
          QDataEngine::Add_DynamicDataStockEx(
            *((_BYTE *)v861 + 93 * i13 + 20),
            (LPCSTR)v861 + 93 * i13 + 21,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v861 + 93 * i13 + 20));
        CDataMgr::SendMsgToUI(this, *(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x701u);
        goto LABEL_1068;
      case 2:
        v841 = pGLOBAL_HIS_TRENDLINE;
        if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        for ( i14 = 0; i14 < *((signed __int16 *)v841 + 9); ++i14 )
          QDataEngine::Add_MoneyFlowDetailDataStockPaid(
            *((_BYTE *)v841 + 193 * i14 + 36),
            (char *)v841 + 193 * i14 + 20,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v841 + 193 * i14 + 20),
            1);
        CDataMgr::SendDataArriveInfoToUI(this, *(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x201u);
        goto LABEL_1068;
      case 3:
        goto LABEL_199;
      case 7:
        goto LABEL_317;
      case 8:
        v795 = pGLOBAL_HIS_TRENDLINE;
        for ( i15 = 0; i15 < *(_DWORD *)((char *)v795 + 21); ++i15 )
          QDataEngine::Add_MoneyFlowDetailDataStockPaid(
            *((_BYTE *)v795 + 193 * i15 + 41),
            (char *)v795 + 193 * i15 + 25,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v795 + 193 * i15 + 25),
            1);
        if ( *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
          CDataMgr::SendDataArriveInfoToUI(this, *(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x205u);
        goto LABEL_1068;
      case 12:
        v615 = pGLOBAL_HIS_TRENDLINE;
        if ( !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        v614 = 0;
        for ( i16 = 0; i16 < *((signed __int16 *)v615 + 9); ++i16 )
        {
          v612 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v615 + v614 + 20);
          v614 += 20 * *(unsigned __int16 *)((char *)v615 + v614 + 36) + 18;
          QDataEngine::AddAllBKMoneyFlow(v612, 1, *((unsigned __int8 *)v615 + 17));
        }
        v285 = *((signed __int16 *)v615 + 9);
        v418 = &v285;
        v315 = sub_4D9CB20(0);
        sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x209u, v285);
        goto LABEL_1068;
      case 13:
        v611 = pGLOBAL_HIS_TRENDLINE;
        if ( !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        v285 = (int)v611 + 36;
        v284 = *((unsigned __int8 *)v611 + 17);
        HIWORD(v224) = HIWORD(v611);
        v283 = *(char **)((char *)v611 + 18);
        LOWORD(v224) = *((_WORD *)v611 + 17);
        v282 = (int *)LODWORD(v224);
        v281 = v224;
        QDataEngine::AddSBKMoneyFlow(
          *(double *)((char *)v611 + 22),
          *(float *)((char *)v611 + 30),
          LOWORD(v224),
          (int)v283,
          v284,
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v611 + 36));
        v417 = &v285;
        v314 = sub_4D9CB20(0);
        v284 = 8208;
        sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x2010u, v285);
        goto LABEL_1068;
      case 31:
        v610 = pGLOBAL_HIS_TRENDLINE;
        if ( !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        QDataEngine::SetBKCapRankSimple(
          *((_BYTE *)v610 + 17),
          *((_BYTE *)v610 + 18),
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v610 + 19));
        v416 = &v285;
        v313 = sub_4D9CB20(0);
        sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x31u, v285);
        goto LABEL_1068;
      case 32:
        v609 = pGLOBAL_HIS_TRENDLINE;
        if ( !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        QDataEngine::SetZCBankSimple(
          *((_BYTE *)v609 + 17),
          *((_BYTE *)v609 + 18),
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v609 + 19));
        v415 = &v285;
        v312 = sub_4D9CB20(0);
        sub_4FE3630(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x32u, v285);
        goto LABEL_1068;
      case 33:
        v724 = pGLOBAL_HIS_TRENDLINE;
        QDataEngine::AddContributionData(
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)pGLOBAL_HIS_TRENDLINE + 22),
          *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 18),
          *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2),
          *((char *)pGLOBAL_HIS_TRENDLINE + 17));
        CDataMgr::SendContriDataToUI(
          this,
          *(HWND *)((char *)v724 + 6),
          *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2),
          *((char *)v724 + 17),
          16);
        goto LABEL_1068;
      case 34:
        v723 = pGLOBAL_HIS_TRENDLINE;
        QDataEngine::AddContributionData(
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)pGLOBAL_HIS_TRENDLINE + 22),
          *(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 18),
          *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2),
          *((char *)pGLOBAL_HIS_TRENDLINE + 17));
        CDataMgr::SendContriDataToUI(
          this,
          *(HWND *)((char *)v723 + 6),
          *((signed __int16 *)pGLOBAL_HIS_TRENDLINE + 2),
          *((char *)v723 + 17),
          17);
        goto LABEL_1068;
      case 47:
        v791 = pGLOBAL_HIS_TRENDLINE;
        if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        if ( !CDataMgr::AddMultiBkData(
                this,
                *(_DWORD *)((char *)v791 + 17),
                *((_BYTE *)v791 + 21),
                (char *)v791 + 27,
                *(_DWORD *)((char *)v791 + 23)) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        if ( *(_DWORD *)((char *)v791 + 6) )
          CDataMgr::SendDataArriveInfoToUI(this, *(HWND *)((char *)v791 + 6), 0x708u);
        else
          CDataMgr::OnTimeSendBKIndexZJLToUI(this, *((char *)v791 + 22), 1800);
        goto LABEL_1068;
      case 48:
        CGlobalEnv::GetGlobalEnv(&v607);
        LOBYTE(v931) = 81;
        v608 = pGLOBAL_HIS_TRENDLINE;
        if ( !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
        {
          LOBYTE(v931) = 1;
          sub_4E3C780(&v607);
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        if ( !CDataMgr::AddMultiBkData(
                this,
                *(_DWORD *)((char *)v608 + 17),
                *((_BYTE *)v608 + 21),
                (char *)v608 + 26,
                *(_DWORD *)((char *)v608 + 22)) )
        {
          LOBYTE(v931) = 1;
          sub_4E3C780(&v607);
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        sub_4FDD810(*(HWND *)((char *)pGLOBAL_HIS_TRENDLINE + 6), 0x501u, 0x33u, 0);
        LOBYTE(v931) = 1;
        sub_4E3C780(&v607);
        goto LABEL_1068;
      case 78:
        v683 = sub_4D3E720();
        v686 = pGLOBAL_HIS_TRENDLINE;
        if ( *(signed __int16 *)((char *)pGLOBAL_HIS_TRENDLINE + 17) <= 0 )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        pHIS_TRENDLINE_Data0 = 0;
        pHIS_TRENDLINE_Data1 = 0;
        v682 = 0;
        break;
      case 82:
        *(_DWORD *)&v704[1] = pGLOBAL_HIS_TRENDLINE;
        v705 = 0;
        v706 = 0;
        v707 = 0;
        v708 = 0;
        v709 = 0;
        v710 = 0;
        v704[0] = 0;
        for ( i17 = 0; i17 < *(char *)(*(_DWORD *)&v704[1] + 17); ++i17 )
        {
          sub_50A00A0(*(_DWORD *)(*(_DWORD *)&v704[1] + 34 * i17 + 26), &v705, (int)v704);
          QDataEngine::AddIndex_Data(v704[0], &v705, (struct _MAIJOR_INDEX2 *)(*(_DWORD *)&v704[1] + 34 * i17 + 18));
        }
        CDataMgr::SendMsgToUIs((int)this + 708, 0x1Au);
        goto LABEL_1068;
      case 189:
        v772 = pGLOBAL_HIS_TRENDLINE;
        if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        v771 = 0;
        if ( *(_DWORD *)((char *)v772 + 25) >= 0 )
          v771 = *(_DWORD *)((char *)v772 + 25);
        if ( !CDataMgr::m_bIsF1DetailPush )
        {
          v285 = QDataEngine::GetCurDateByMarket(*((char *)v772 + 17), 0);
          v284 = (int)v772 + 33;
          QDataEngine::Add_DetailData(
            (char *)v772 + 18,
            *((_BYTE *)v772 + 17),
            v771,
            *(_DWORD *)((char *)v772 + 29),
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v772 + 33),
            v285);
          v125 = QDataEngine::GetCurDateByMarket(*((char *)v772 + 17), 0);
          CDataMgr::PushDataSendDetailL1ToUI(this, (char *)v772 + 18, *((_BYTE *)v772 + 17), v125);
        }
        goto LABEL_1068;
      case 195:
        v770 = pGLOBAL_HIS_TRENDLINE;
        if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) )
        {
          LOBYTE(v931) = 0;
          sub_4E3C780(&v929);
          v931 = -1;
          sub_4E3C780(&v930);
          return;
        }
        v768 = QDataEngine::GetCurDateByMarket(*((char *)v770 + 17), 0);
        v769 = QDataEngine::App_TickDataCount((char *)v770 + 18, *((_BYTE *)v770 + 17), v768);
        v285 = v768;
        v284 = (int)v770 + 45;
        QDataEngine::Add_DetailData(
          (char *)v770 + 18,
          *((_BYTE *)v770 + 17),
          v769,
          *(_DWORD *)((char *)v770 + 41),
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v770 + 45),
          v768);
        CDataMgr::PushDataSendDetailL1ToUI(this, (char *)v770 + 18, *((_BYTE *)v770 + 17), v768);
        goto LABEL_1068;
      default:
        goto LABEL_1067;
    }
    while ( 1 )
    {
      if ( v682 >= *(signed __int16 *)((char *)v686 + 17) )
        goto LABEL_1068;
      pHIS_TRENDLINE_Data0 = (LPARAM)pGLOBAL_HIS_TRENDLINE + pHIS_TRENDLINE_Data1 + 19;   //数据指针？？？
      pHIS_TRENDLINE_Data1 += *(_DWORD *)pHIS_TRENDLINE_Data0 + 17;
      if ( !*(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
      {
        v679 = 0;
        memset(&v680, 0, 0x3FEu);
        v677 = pHIS_TRENDLINE_Data0;
        mfc80xU_293(&v678);
        LOBYTE(v931) = 77;
        sub_509CC40((LPCSTR)(v677 + 19), (int)&v678);
        LightLogger::CLogger::GetLogger(&v681, L"MultiplePkg");
        LOBYTE(v931) = 78;
        v285 = v678;
        sub_4D3E590(&v679, L"Recv Error Package,MsgId = %d,ErrorMsg=%s", *(_WORD *)(pHIS_TRENDLINE_Data0 + 4));
        v205 = (LightLogger::CLogger *)unknown_libname_97(&v681);
        LightLogger::CLogger::WriteLogLine(v205, &v679, 10000);
        LOBYTE(v931) = 77;
        sub_4E3C780(&v681);
        LOBYTE(v931) = 1;
        mfc80xU_577(&v678);
        goto LABEL_586;
      }
      if ( *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 3020
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 3021
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 808
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 804
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 802
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 819
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 817
        || *(_WORD *)(pHIS_TRENDLINE_Data0 + 4) == 8103 )
      {
        CGlobalEnv::GetGlobalEnv(&v676);
        if ( unknown_libname_97(&v676) && *(_DWORD *)(unknown_libname_97(&v676) + 140) )
        {
          v285 = pHIS_TRENDLINE_Data0;
          v284 = 0;
          v283 = (char *)6026;
          v206 = *(_DWORD *)(unknown_libname_97(&v676) + 140);
          sub_4D3E310(0x178Au, 0, v285);
        }
        sub_4E3C780(&v676);
      }
      v320 = *(signed __int16 *)(pHIS_TRENDLINE_Data0 + 4);
      if ( v320 > 718 )
      {
        if ( v320 > 3020 )
        {
          switch ( v320 )
          {
            case 3021:
              v622 = (struct MSG_RET_TRENDLINE *)pHIS_TRENDLINE_Data0;
              if ( pHIS_TRENDLINE_Data0 && *((_BYTE *)v622 + 10) )
                CDataMgr::ProcStkTrendCfs(this, v622);
              break;
            case 8103:
              v619 = (struct _MSG_RET_QUOTE_RT_GLOBAL_MARKET *)pHIS_TRENDLINE_Data0;
              if ( pHIS_TRENDLINE_Data0 && *((_BYTE *)v619 + 10) )
                CDataMgr::ProcGlobalStkTrend(this, v619);
              break;
            case 8104:
              v618 = (struct _MSG_RET_QUOTE_MINKLINE_GLOBAL_MARKET *)pHIS_TRENDLINE_Data0;
              if ( pHIS_TRENDLINE_Data0 && *((_BYTE *)v618 + 10) )
                CDataMgr::ProcGlobalStkKLine(this, v618);
              break;
            default:
LABEL_759:
              v285 = pHIS_TRENDLINE_Data0;
              v284 = *(signed __int16 *)(pHIS_TRENDLINE_Data0 + 4);
              v222 = *(_DWORD *)((char *)this + 1106);
              sub_50C4D60(v284, pHIS_TRENDLINE_Data0);
              break;
          }
        }
        else if ( v320 == 3020 )
        {
          v623 = (struct MSG_RET_TRENDLINE *)pHIS_TRENDLINE_Data0;
          if ( pHIS_TRENDLINE_Data0 && *((_BYTE *)v623 + 10) )
            CDataMgr::ProcStkTrend(this, v623);
        }
        else
        {
          v320 -= 725;
          switch ( v320 )
          {
            case 0:
              CDataMgr::ProcPushOptionQuote(this, (struct MSG_RET_PUSH_OPTION_QUOTE *)pHIS_TRENDLINE_Data0);
              break;
            case 6:
              CDataMgr::ProcStkOptionQuoteTable(
                this,
                (struct MSG_RET_PUSH_STK_OPTION_QUOTE_TABLE *)pHIS_TRENDLINE_Data0,
                *(signed __int16 *)(pHIS_TRENDLINE_Data0 + 4));
              goto LABEL_757;
            case 12:
              v675 = pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                for ( i18 = 0; i18 < *(char *)(v675 + 17); ++i18 )
                  sub_4E354C0(*(HWND *)(v675 + 6), v675 + 210 * i18 + 18, 0);
              }
              break;
            case 77:
              v640 = (struct MSG_RET_L2QUOTE_PRICEORDER *)pHIS_TRENDLINE_Data0;
              if ( *(_DWORD *)pHIS_TRENDLINE_Data0 > 0 && *((_BYTE *)v640 + 10) )
                CDataMgr::ProcWeiTuoAndSendToUI(this, v640);
              break;
            case 78:
              *(_DWORD *)&v632[1] = pHIS_TRENDLINE_Data0;
              if ( pHIS_TRENDLINE_Data0 )
              {
                if ( *(_BYTE *)(*(_DWORD *)&v632[1] + 10) )
                {
                  v633 = 0;
                  v634 = 0;
                  v635 = 0;
                  v636 = 0;
                  v637 = 0;
                  v638 = 0;
                  v632[0] = 0;
                  sub_509F6E0(*(_DWORD *)(*(_DWORD *)&v632[1] + 17), &v633, (int)v632);
                  if ( QDataEngine::AddOrderQueueData(
                         v632[0],
                         &v633,
                         (struct RET_ITEM_ORDER_QUEUE *)(*(_DWORD *)&v632[1] + 22),
                         *(_BYTE *)(*(_DWORD *)&v632[1] + 21)) )
                  {
                    if ( *((_BYTE *)this + 706) )
                      CDataMgr::SendOrderListToUI(this, *(HWND *)((char *)this + 702));
                  }
                }
              }
              break;
            case 79:
              v639 = (struct MSG_RET_L2QUOTE_TRANSACTION *)pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) && *(_DWORD *)v639 >= 1 )
                CDataMgr::ProcTradeDetailAndSendToUI(this, v639);
              break;
            case 83:
              v631 = pHIS_TRENDLINE_Data0;
              if ( pHIS_TRENDLINE_Data0 && *(_BYTE *)(v631 + 10) )
              {
                CGlobalEnv::GetGlobalEnv(&v630);
                LOBYTE(v931) = 79;
                v420 = mfc80xU_762(28);
                if ( v420 )
                  v319 = sub_4D9CDE0(v420);
                else
                  v319 = 0;
                v421 = v319;
                sub_4E3E5E0(v319);
                LOBYTE(v931) = 80;
                if ( (unsigned __int8)CDataMgr::ProcT0MoneyFlowData(v631, &v629) )
                {
                  EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 242));
                  for ( i19 = 0; ; ++i19 )
                  {
                    v216 = sub_4D82EA0((char *)this + 649);
                    if ( i19 >= v216 )
                      break;
                    v318 = unknown_libname_97(&v630);
                    v217 = unknown_libname_97(&v629);
                    v627 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v318 + 36))(v318, v217);
                    v285 = v627;
                    v218 = (HWND *)sub_4E3DB70(i19);
                    sub_4FDD810(*v218, 0x501u, 0x2011u, v285);
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 242));
                  EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 266));
                  for ( i20 = 0; ; ++i20 )
                  {
                    v219 = sub_4D82EA0((char *)this + 665);
                    if ( i20 >= v219 )
                      break;
                    v317 = unknown_libname_97(&v630);
                    v220 = unknown_libname_97(&v629);
                    v625 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v317 + 36))(v317, v220);
                    v285 = v625;
                    v221 = (HWND *)sub_4E3DB70(i20);
                    sub_4FDD810(*v221, 0x501u, 0xEu, v285);
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 266));
                  LOBYTE(v931) = 79;
                  sub_4E3C780(&v629);
                  LOBYTE(v931) = 1;
                  sub_4E3C780(&v630);
                }
                else
                {
                  LOBYTE(v931) = 79;
                  sub_4E3C780(&v629);
                  LOBYTE(v931) = 1;
                  sub_4E3C780(&v630);
                }
              }
              break;
            case 87:
              v673 = pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                v667 = 0;
                v668 = 0;
                v669 = 0;
                v670 = 0;
                v671 = 0;
                v672 = 0;
                LOBYTE(v666) = 0;
                sub_4DBA1B0((char *)&v666 + 1);
                if ( *(_DWORD *)(v673 + 6) )
                {
                  for ( i21 = 0; i21 < *(char *)(v673 + 17); ++i21 )
                  {
                    sub_509F6E0(*(_DWORD *)(v673 + 178 * i21 + 18), &v667, (int)&v666);
                    memcpy((char *)&v666 + 1, (const void *)(v673 + 178 * i21 + 18), 0xB2u);
                    QDataEngine::AddSpGZQH_Dyn(v666, &v667, (struct SNAPSHOT_GZQH *)((char *)&v666 + 1));
                  }
                  CDataMgr::SendMsgToUI(this, *(HWND *)(v673 + 6), 0x25u);
                }
                else
                {
                  EnterCriticalSection((LPCRITICAL_SECTION)((char *)this + 122));
                  if ( (unsigned int)unknown_libname_94((char *)this + 756) >= 1 )
                  {
                    for ( i22 = 0; i22 < *(char *)(v673 + 17); ++i22 )
                    {
                      sub_509F6E0(*(_DWORD *)(v673 + 178 * i22 + 18), &v667, (int)&v666);
                      v662 = 178;
                      memcpy((char *)&v666 + 1, (const void *)(v673 + 178 * i22 + 18), 0xB2u);
                      QDataEngine::AddSpGZQH_Dyn(v666, &v667, (struct SNAPSHOT_GZQH *)((char *)&v666 + 1));
                      v663 = sub_509F6C0(&v667, v666);
                      if ( v663 != -1 )
                      {
                        sub_4E25DD0(&v661, (int)&v663);
                        v207 = sub_4E08970(&v427);
                        if ( !(unsigned __int8)sub_4D5CFF0(v207) )
                        {
                          sub_4E20840(&v661);
                          sub_4E50EF0(&v660);
                          while ( 1 )
                          {
                            sub_4E20840(&v661);
                            v208 = sub_4D7C7B0(&v425);
                            if ( !(unsigned __int8)sub_4D5B600(v208) )
                              break;
                            v209 = (HWND *)sub_4E37B30(&v660);
                            CDataMgr::SendMsgToUI(this, *v209, 0x25u);
                            sub_4E26560(&v426, 0);
                          }
                        }
                      }
                    }
                    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 122));
                  }
                  else
                  {
                    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)this + 122));
                  }
                }
              }
              break;
            case 91:
              v624 = (struct MSG_RET_L2QUOTE_RATIOPRICE *)pHIS_TRENDLINE_Data0;
              CDataMgr::SendRatioPriceToUI(this, *(HWND *)(pHIS_TRENDLINE_Data0 + 6), (struct MSG_RET_L2QUOTE_RATIOPRICE *)pHIS_TRENDLINE_Data0);
              break;
            case 92:
              pMULTI_L2_QUOTE = (struct MSG_RET_MULTI_L2_QUOTE *)pHIS_TRENDLINE_Data0;
              if ( !pHIS_TRENDLINE_Data0 || *((char *)pMULTI_L2_QUOTE + 10) < 1 )
              {
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              CDataMgr::ProcHundredsL2Quote(this, pMULTI_L2_QUOTE);  //读入买卖委托队列，不含每个价位具体组成、但又总笔数和总单数
              break;
            case 94:
              v621 = (struct MSG_RET_MULTI_L2_QUOTE *)pHIS_TRENDLINE_Data0;
              if ( !pHIS_TRENDLINE_Data0 || *((char *)v621 + 10) < 1 )
              {
                LOBYTE(v931) = 0;
                sub_4E3C780(&v929);
                v931 = -1;
                sub_4E3C780(&v930);
                return;
              }
              CDataMgr::ProcStkMultiL2Quote(this, v621);
              break;
            case 95:
              CDataMgr::ProcProbUpData(this, (struct MSG_RET_QUOTE_PROBABILITY_UP *)pHIS_TRENDLINE_Data0);
              break;
            case 96:
              CDataMgr::ProcProbUpDaysData(this, (struct MSG_RET_QUOTE_PROB_UP_DAYS *)pHIS_TRENDLINE_Data0);
              break;
            case 97:
              CDataMgr::ProcHisProbUpData(this, (struct MSG_RET_QUOTE_PROB_UP_HIS *)pHIS_TRENDLINE_Data0);
              break;
            default:
              goto LABEL_759;
          }
        }
      }
      else
      {
        if ( v320 == 718 )
        {
LABEL_757:
          CDataMgr::ProcBkStkQuoteTable(
            this,
            (struct MSG_RET_PUSH_BK_STK_QUOTE_TABLE *)pHIS_TRENDLINE_Data0,
            *(signed __int16 *)(pHIS_TRENDLINE_Data0 + 4));
          goto LABEL_586;
        }
        if ( v320 > 30 )
        {
          switch ( v320 )
          {
            case 370:
              v641 = (struct MSG_RET_BK_BASIC_INFO *)pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                QDataEngine::AddBKIndexZJLInfo(v641);
                if ( *(_DWORD *)((char *)v641 + 6) )
                  CDataMgr::SendDataArriveInfoToUI(this, *(HWND *)((char *)v641 + 6), 0x708u);
                else
                  CDataMgr::OnTimeSendBKIndexZJLToUI(this, *(_DWORD *)((char *)v641 + 17), 1800);
              }
              break;
            case 512:
              v659 = pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                v658 = 0;
                if ( *(_DWORD *)(v659 + 25) >= 0 )
                  v658 = *(_DWORD *)(v659 + 25);
                if ( !CDataMgr::m_bIsF1DetailPush )
                {
                  v210 = QDataEngine::GetCurDateByMarket(*(char *)(v659 + 17), 0);
                  v284 = v659 + 33;
                  QDataEngine::Add_DetailData(
                    (char *)(v659 + 18),
                    *(_BYTE *)(v659 + 17),
                    v658,
                    *(_DWORD *)(v659 + 29),
                    (struct DETAILREC *)(v659 + 33),
                    v210);
                  v211 = QDataEngine::GetCurDateByMarket(*(char *)(v659 + 17), 0);
                  CDataMgr::PushDataSendDetailL1ToUI(this, (char *)(v659 + 18), *(_BYTE *)(v659 + 17), v211);
                }
              }
              break;
            case 518:
              v657 = pHIS_TRENDLINE_Data0;
              if ( !*(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
                break;
              v212 = QDataEngine::GetCurDateByMarket(*(char *)(v657 + 17), 0);
              v655 = QDataEngine::App_TickDataCount((char *)(v657 + 18), *(_BYTE *)(v657 + 17), v212);  //L1 TickData当日数据
              v656 = 0;
              v654 = 0;
              if ( (signed int)v655 <= 0 )
              {
                v654 = 0;
LABEL_672:
                v285 = QDataEngine::GetCurDateByMarket(*(char *)(v657 + 17), 0);
                QDataEngine::Add_DetailData(
                  (char *)(v657 + 18),
                  *(_BYTE *)(v657 + 17),
                  v654,
                  *(_DWORD *)(v657 + 41) - v656,
                  (struct DETAILREC *)(v657 + 14 * v656 + 45),
                  v285);
                v215 = QDataEngine::GetCurDateByMarket(*(char *)(v657 + 17), 0);
                CDataMgr::PushDataSendDetailL1ToUI(this, (char *)(v657 + 18), *(_BYTE *)(v657 + 17), v215);
                break;
              }
              v654 = v655;
              v424 = (struct DETAILREC *)mfc80xU_265(14 * v655 | -(14 * (unsigned __int64)v655 >> 32 != 0));
              v653 = v424;
              if ( !v424 )
                break;
              nCurDateByMarket = QDataEngine::GetCurDateByMarket(*(char *)(v657 + 17), 0);
              QDataEngine::App_TickData((char *)(v657 + 18), *(_BYTE *)(v657 + 17), v653, v655, nCurDateByMarket);
              v652 = *((char *)v653 + 14 * (v655 - 1) + 2)
                   + 100 * *((char *)v653 + 14 * (v655 - 1) + 1)
                   + 10000 * *((char *)v653 + 14 * (v655 - 1));
              for ( i23 = 0; i23 < *(_DWORD *)(v657 + 41); ++i23 )
              {
                v650 = *(char *)(v657 + 14 * i23 + 47)
                     + 100 * *(char *)(v657 + 14 * i23 + 46)
                     + 10000 * *(char *)(v657 + 14 * i23 + 45);
                if ( v650 == v652 )
                {
                  --v654;
                  for ( i24 = v655 - 2;
                        i24 >= 0
                     && (v654 & 0x80000000) == 0
                     && *((char *)v653 + 14 * i24 + 2)
                      + 100 * *((char *)v653 + 14 * i24 + 1)
                      + 10000 * *((char *)v653 + 14 * i24) == v652;
                        --i24 )
                  {
                    --v654;
                  }
                }
                if ( v650 >= v652 )
                  break;
                ++v656;
              }
              if ( *(_DWORD *)(v657 + 41) - v656 > 0 )
              {
                if ( v653 )
                {
                  v422 = v653;
                  mfc80xU_266(v653);
                  v653 = 0;
                }
                goto LABEL_672;
              }
              v214 = QDataEngine::GetCurDateByMarket(*(char *)(v657 + 17), 0);
              CDataMgr::PushDataSendDetailL1ToUI(this, (char *)(v657 + 18), *(_BYTE *)(v657 + 17), v214);
              if ( v653 )
              {
                v423 = v653;
                mfc80xU_266(v653);
                v653 = 0;
              }
              break;
            default:
              goto LABEL_759;
          }
        }
        else
        {
          switch ( v320 )
          {
            case 30:
              v645 = pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                if ( *(_BYTE *)(v645 + 17) )
                {
                  QDataEngine::SetRankList(2, 1, (struct RANK_FLOAT *)(v645 + 19));
                  QDataEngine::SetRankList(2, 4, (struct RANK_FLOAT *)(v645 + 659));
                  QDataEngine::SetRankList(17, 1, (struct RANK_FLOAT *)(v645 + 1299));
                  QDataEngine::SetRankList(17, 4, (struct RANK_FLOAT *)(v645 + 1939));
                }
                else
                {
                  QDataEngine::SetRankList(2, 0, (struct RANK_FLOAT *)(v645 + 19));
                  QDataEngine::SetRankList(2, 3, (struct RANK_FLOAT *)(v645 + 659));
                  QDataEngine::SetRankList(17, 0, (struct RANK_FLOAT *)(v645 + 1299));
                  QDataEngine::SetRankList(17, 3, (struct RANK_FLOAT *)(v645 + 1939));
                }
                QDataEngine::SaveRankList();
                if ( *(_DWORD *)(v645 + 6) )
                  CDataMgr::SendRankUpDownToUI(this, *(HWND *)(v645 + 6), *(_BYTE *)(v645 + 17));
                else
                  CDataMgr::OnTimeSendRankUpDownToUI(this, *(_BYTE *)(v645 + 17));
              }
              break;
            case 11:
              v648 = pHIS_TRENDLINE_Data0;
              v647 = *(_DWORD *)(pHIS_TRENDLINE_Data0 + 13) == 1;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
                sub_4E35DA0(*(HWND *)(v648 + 6), v648 + 17, v647);
              break;
            case 13:
              v644 = pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                sub_4DBA150(&v643);
                for ( i25 = 0; i25 < *(signed __int16 *)(v644 + 17); ++i25 )
                {
                  sub_4E35D20(&v643, v644 + 194 * i25 + 19);
                  QDataEngine::Add_DynamicDataStock(
                    *(_BYTE *)(v644 + 194 * i25 + 19),
                    (char *)(v644 + 194 * i25 + 24),
                    (struct _QUOTEREC *)&v643);
                }
                CDataMgr::SendRecordDataToUI(this, *(HWND *)(v644 + 6), 0x702u);
              }
              break;
            case 22:
              v646 = pHIS_TRENDLINE_Data0;
              if ( *(_BYTE *)(pHIS_TRENDLINE_Data0 + 10) )
              {
                QDataEngine::SetRankList(*(char *)(v646 + 17), 0, (struct RANK_FLOAT *)(v646 + 18));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 1, (struct RANK_FLOAT *)(v646 + 1298));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 3, (struct RANK_FLOAT *)(v646 + 658));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 4, (struct RANK_FLOAT *)(v646 + 1938));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 5, (struct RANK_FLOAT *)(v646 + 5138));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 6, (struct RANK_FLOAT *)(v646 + 2578));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 7, (struct RANK_FLOAT *)(v646 + 3858));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 2, (struct RANK_FLOAT *)(v646 + 4498));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 9, (struct RANK_FLOAT *)(v646 + 3218));
                QDataEngine::SetRankList(*(char *)(v646 + 17), 8, (struct RANK_FLOAT *)(v646 + 5778));
                QDataEngine::SaveRankList();
                CDataMgr::SendRankToUI(this, *(HWND *)(v646 + 6), *(char *)(v646 + 17));
              }
              break;
            default:
              goto LABEL_759;
          }
        }
      }
LABEL_586:
      ++v682;
    }
  }
LABEL_199:
  v859 = pGLOBAL_HIS_TRENDLINE;
  if ( !*((_BYTE *)pGLOBAL_HIS_TRENDLINE + 10) || *(_DWORD *)v859 < 1 || !*(_DWORD *)((char *)pGLOBAL_HIS_TRENDLINE + 6) )
  {
    LOBYTE(v931) = 0;
    sub_4E3C780(&v929);
    v931 = -1;
    sub_4E3C780(&v930);
    return;
  }
  if ( *((_BYTE *)v859 + 21) == 2 )
    sub_4E78200((char *)this + 569);
  v858 = 0;
  v285 = (int)&v858;
  if ( !CDataMgr::PreProcMoneyRankData(
          this,
          *(_DWORD *)((char *)v859 + 17),
          *((_BYTE *)v859 + 21),
          (char *)v859 + 27,
          *(_DWORD *)((char *)v859 + 23),
          &v858) )
  {
    LOBYTE(v931) = 0;
    sub_4E3C780(&v929);
    v931 = -1;
    sub_4E3C780(&v930);
    return;
  }
  v285 = v858;
  v284 = 512;
  v283 = (char *)1281;
  v282 = *(int **)((char *)pGLOBAL_HIS_TRENDLINE + 6);
  v79 = CDataMgr::GetReceiverSafeHandle(this);
  CViewManager::PostExDataMessage(v79, (unsigned int)v282, 0x501u, 0x200u, v285);
LABEL_1068:
  LOBYTE(v931) = 0;
  sub_4E3C780(&v929);
  v931 = -1;
  sub_4E3C780(&v930);
}