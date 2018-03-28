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
  _DWORD *v92; // eax
  int v93; // eax
  int v94; // eax
  HWND *v95; // eax
  HWND v96; // eax
  HWND v97; // eax
  unsigned int v98; // eax
  int v99; // eax
  HWND v100; // eax
  unsigned int v101; // eax
  int v102; // eax
  HWND v103; // eax
  HWND v104; // eax
  unsigned int v105; // eax
  int v106; // eax
  HWND v107; // eax
  unsigned int v108; // eax
  int v109; // eax
  HWND v110; // eax
  unsigned int v111; // eax
  int v112; // eax
  HWND v113; // eax
  unsigned int v114; // eax
  int v115; // eax
  HWND v116; // eax
  HWND v117; // eax
  struct MainCapFlowShowDetailClientPaid *v118; // eax
  HWND v119; // eax
  struct MainCapFlowShowDetailClientPaid *v120; // eax
  HWND v121; // eax
  struct MainCapFlowShowDetailClientPaid *v122; // eax
  HWND v123; // eax
  struct MainCapFlowShowDetailClientPaid *v124; // eax
  HWND v125; // eax
  int v126; // eax
  int v127; // eax
  _BYTE *v128; // eax
  int v129; // eax
  int v130; // eax
  int v131; // eax
  int v132; // eax
  int v133; // eax
  int v134; // eax
  int v135; // eax
  int v136; // eax
  _BYTE *v137; // eax
  int v138; // eax
  int v139; // eax
  int v140; // eax
  int v141; // eax
  int v142; // eax
  int v143; // eax
  int v144; // eax
  int v145; // eax
  _BYTE *v146; // eax
  int v147; // eax
  int v148; // eax
  int v149; // eax
  int v150; // eax
  int v151; // eax
  int v152; // eax
  int v153; // eax
  int v154; // eax
  _BYTE *v155; // eax
  int v156; // eax
  int v157; // eax
  int v158; // eax
  int v159; // eax
  struct DAYDATA *v160; // eax
  int v161; // eax
  int v162; // eax
  int v163; // eax
  HWND v164; // eax
  int v165; // eax
  int v166; // eax
  int v167; // eax
  int v168; // eax
  int v169; // eax
  int v170; // eax
  int v171; // eax
  int v172; // eax
  int v173; // eax
  int v174; // eax
  _BYTE *v175; // eax
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
  int v197; // eax
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v198; // ecx
  int v199; // eax
  int v200; // eax
  int v201; // eax
  int v202; // eax
  const wchar_t *v203; // eax
  const wchar_t *v204; // eax
  const wchar_t *v205; // eax
  LightLogger::CLogger *v206; // eax
  int v207; // ecx
  _DWORD *v208; // eax
  int v209; // eax
  int v210; // eax
  HWND *v211; // eax
  int v212; // eax
  int v213; // eax
  int v214; // eax
  int v215; // eax
  int v216; // eax
  int v217; // eax
  int v218; // eax
  int v219; // eax
  HWND *v220; // eax
  int v221; // eax
  int v222; // eax
  HWND *v223; // eax
  int v224; // ecx
  int v225; // ecx
  float v226; // ecx
  int v227; // eax
  _BYTE *v228; // eax
  int v229; // eax
  int v230; // eax
  int v231; // eax
  int v232; // eax
  int v233; // eax
  int v234; // eax
  unsigned int v235; // eax
  int v236; // eax
  HWND *v237; // eax
  unsigned int v238; // eax
  int v239; // eax
  HWND *v240; // eax
  char v241; // al
  LightLogger::CLogger *v242; // eax
  HWND v243; // eax
  HWND v244; // eax
  HWND v245; // eax
  int v246; // eax
  _DWORD *v247; // eax
  int v248; // eax
  int v249; // ecx
  int v250; // eax
  int v251; // eax
  int v252; // eax
  int v253; // eax
  int v254; // ecx
  CViewManager *v255; // eax
  int v256; // ecx
  int v257; // ecx
  int v258; // eax
  _BYTE *v259; // eax
  int v260; // eax
  int v261; // eax
  int v262; // eax
  int v263; // eax
  int v264; // eax
  int v265; // eax
  int v266; // eax
  int v267; // eax
  int v268; // eax
  int v269; // ecx
  int v270; // eax
  _DWORD *v271; // eax
  int v272; // eax
  int v273; // eax
  int v274; // ecx
  LightLogger::CLogger *v275; // eax
  const char *v276; // eax
  int v277; // ecx
  double v278; // [esp+8h] [ebp-27B8h]
  float v279; // [esp+10h] [ebp-27B0h]
  int *v280; // [esp+14h] [ebp-27ACh]
  char *v281; // [esp+18h] [ebp-27A8h]
  int v282; // [esp+1Ch] [ebp-27A4h]
  int v283; // [esp+20h] [ebp-27A0h]
  WCHAR *v284; // [esp+24h] [ebp-279Ch]
  UINT v285; // [esp+28h] [ebp-2798h]
  int v286; // [esp+2Ch] [ebp-2794h]
  int v287; // [esp+30h] [ebp-2790h]
  int v288; // [esp+34h] [ebp-278Ch]
  int v289; // [esp+38h] [ebp-2788h]
  int v290; // [esp+3Ch] [ebp-2784h]
  int v291; // [esp+40h] [ebp-2780h]
  int v292; // [esp+44h] [ebp-277Ch]
  int v293; // [esp+48h] [ebp-2778h]
  char v294; // [esp+4Ch] [ebp-2774h]
  int v295; // [esp+50h] [ebp-2770h]
  int v296; // [esp+54h] [ebp-276Ch]
  int v297; // [esp+58h] [ebp-2768h]
  int v298; // [esp+5Ch] [ebp-2764h]
  int v299; // [esp+60h] [ebp-2760h]
  int v300; // [esp+64h] [ebp-275Ch]
  LPARAM v301; // [esp+68h] [ebp-2758h]
  int v302; // [esp+6Ch] [ebp-2754h]
  int v303; // [esp+70h] [ebp-2750h]
  int v304; // [esp+74h] [ebp-274Ch]
  int v305; // [esp+78h] [ebp-2748h]
  int v306; // [esp+7Ch] [ebp-2744h]
  int v307; // [esp+80h] [ebp-2740h]
  int v308; // [esp+84h] [ebp-273Ch]
  int v309; // [esp+88h] [ebp-2738h]
  int v310; // [esp+8Ch] [ebp-2734h]
  int v311; // [esp+90h] [ebp-2730h]
  int v312; // [esp+94h] [ebp-272Ch]
  int v313; // [esp+98h] [ebp-2728h]
  int v314; // [esp+9Ch] [ebp-2724h]
  int v315; // [esp+A0h] [ebp-2720h]
  int v316; // [esp+A4h] [ebp-271Ch]
  int v317; // [esp+A8h] [ebp-2718h]
  int v318; // [esp+ACh] [ebp-2714h]
  int v319; // [esp+B0h] [ebp-2710h]
  int *v320; // [esp+B4h] [ebp-270Ch]
  int *v321; // [esp+B8h] [ebp-2708h]
  int v322; // [esp+BCh] [ebp-2704h]
  int v323; // [esp+C0h] [ebp-2700h]
  int v324; // [esp+C4h] [ebp-26FCh]
  int v325; // [esp+C8h] [ebp-26F8h]
  int v326; // [esp+CCh] [ebp-26F4h]
  int v327; // [esp+D0h] [ebp-26F0h]
  int v328; // [esp+D4h] [ebp-26ECh]
  int v329; // [esp+D8h] [ebp-26E8h]
  int v330; // [esp+DCh] [ebp-26E4h]
  int v331; // [esp+E0h] [ebp-26E0h]
  int v332; // [esp+E4h] [ebp-26DCh]
  int v333; // [esp+E8h] [ebp-26D8h]
  int v334; // [esp+ECh] [ebp-26D4h]
  int v335; // [esp+F0h] [ebp-26D0h]
  int v336; // [esp+F4h] [ebp-26CCh]
  int v337; // [esp+F8h] [ebp-26C8h]
  int v338; // [esp+FCh] [ebp-26C4h]
  int v339; // [esp+100h] [ebp-26C0h]
  int v340; // [esp+104h] [ebp-26BCh]
  int v341; // [esp+108h] [ebp-26B8h]
  int v342; // [esp+10Ch] [ebp-26B4h]
  int v343; // [esp+110h] [ebp-26B0h]
  int v344; // [esp+114h] [ebp-26ACh]
  int v345; // [esp+118h] [ebp-26A8h]
  int v346; // [esp+11Ch] [ebp-26A4h]
  int v347; // [esp+120h] [ebp-26A0h]
  LPWSTR v348; // [esp+124h] [ebp-269Ch]
  int v349; // [esp+128h] [ebp-2698h]
  int v350; // [esp+12Ch] [ebp-2694h]
  int v351; // [esp+130h] [ebp-2690h]
  int v352; // [esp+134h] [ebp-268Ch]
  int v353; // [esp+138h] [ebp-2688h]
  LPWSTR v354; // [esp+13Ch] [ebp-2684h]
  int v355; // [esp+140h] [ebp-2680h]
  int v356; // [esp+144h] [ebp-267Ch]
  int v357; // [esp+148h] [ebp-2678h]
  int v358; // [esp+14Ch] [ebp-2674h]
  LPWSTR v359; // [esp+150h] [ebp-2670h]
  int v360; // [esp+154h] [ebp-266Ch]
  int v361; // [esp+158h] [ebp-2668h]
  int v362; // [esp+15Ch] [ebp-2664h]
  int v363; // [esp+160h] [ebp-2660h]
  int v364; // [esp+164h] [ebp-265Ch]
  int v365; // [esp+168h] [ebp-2658h]
  int v366; // [esp+16Ch] [ebp-2654h]
  int v367; // [esp+170h] [ebp-2650h]
  LPWSTR v368; // [esp+174h] [ebp-264Ch]
  int v369; // [esp+178h] [ebp-2648h]
  int v370; // [esp+17Ch] [ebp-2644h]
  int v371; // [esp+180h] [ebp-2640h]
  int v372; // [esp+184h] [ebp-263Ch]
  LPWSTR lpWideCharStr; // [esp+188h] [ebp-2638h]
  int v374; // [esp+18Ch] [ebp-2634h]
  int v375; // [esp+190h] [ebp-2630h]
  int v376; // [esp+194h] [ebp-262Ch]
  int v377; // [esp+198h] [ebp-2628h]
  int v378; // [esp+19Ch] [ebp-2624h]
  int v379; // [esp+1A0h] [ebp-2620h]
  CDataMgr *v380; // [esp+1A4h] [ebp-261Ch]
  char v381; // [esp+1A8h] [ebp-2618h]
  int *v382; // [esp+1C4h] [ebp-25FCh]
  int v383; // [esp+1C8h] [ebp-25F8h]
  int v384; // [esp+1CCh] [ebp-25F4h]
  int *v385; // [esp+1D0h] [ebp-25F0h]
  int v386; // [esp+1D4h] [ebp-25ECh]
  int v387; // [esp+1D8h] [ebp-25E8h]
  int *v388; // [esp+1DCh] [ebp-25E4h]
  void *v389; // [esp+1E0h] [ebp-25E0h]
  void *v390; // [esp+1E4h] [ebp-25DCh]
  int v391; // [esp+1E8h] [ebp-25D8h]
  int v392; // [esp+1ECh] [ebp-25D4h]
  int *v393; // [esp+1F0h] [ebp-25D0h]
  int v394; // [esp+1F4h] [ebp-25CCh]
  int v395; // [esp+1F8h] [ebp-25C8h]
  LPARAM v396; // [esp+1FCh] [ebp-25C4h]
  LPARAM v397; // [esp+200h] [ebp-25C0h]
  LPARAM v398; // [esp+204h] [ebp-25BCh]
  LPARAM v399; // [esp+208h] [ebp-25B8h]
  int v400; // [esp+20Ch] [ebp-25B4h]
  LPARAM v401; // [esp+210h] [ebp-25B0h]
  int v402; // [esp+214h] [ebp-25ACh]
  int v403; // [esp+218h] [ebp-25A8h]
  void *v404; // [esp+21Ch] [ebp-25A4h]
  double *v405; // [esp+220h] [ebp-25A0h]
  void *v406; // [esp+224h] [ebp-259Ch]
  int v407; // [esp+228h] [ebp-2598h]
  int v408; // [esp+22Ch] [ebp-2594h]
  int v409; // [esp+230h] [ebp-2590h]
  int v410; // [esp+234h] [ebp-258Ch]
  int *v411; // [esp+238h] [ebp-2588h]
  int *v412; // [esp+23Ch] [ebp-2584h]
  int *v413; // [esp+240h] [ebp-2580h]
  int *v414; // [esp+244h] [ebp-257Ch]
  int *v415; // [esp+248h] [ebp-2578h]
  int v416; // [esp+24Ch] [ebp-2574h]
  int v417; // [esp+250h] [ebp-2570h]
  struct DETAILREC *v418; // [esp+254h] [ebp-256Ch]
  struct DETAILREC *v419; // [esp+258h] [ebp-2568h]
  struct DETAILREC *v420; // [esp+25Ch] [ebp-2564h]
  char v421; // [esp+260h] [ebp-2560h]
  char v422; // [esp+268h] [ebp-2558h]
  char v423; // [esp+270h] [ebp-2550h]
  int **v424; // [esp+278h] [ebp-2548h]
  double *v425; // [esp+27Ch] [ebp-2544h]
  char v426; // [esp+280h] [ebp-2540h]
  char v427; // [esp+284h] [ebp-253Ch]
  char v428; // [esp+288h] [ebp-2538h]
  char v429; // [esp+28Ch] [ebp-2534h]
  int v430; // [esp+290h] [ebp-2530h]
  int v431; // [esp+294h] [ebp-252Ch]
  int v432; // [esp+298h] [ebp-2528h]
  int v433; // [esp+29Ch] [ebp-2524h]
  int v434; // [esp+2A0h] [ebp-2520h]
  int v435; // [esp+2A4h] [ebp-251Ch]
  int v436; // [esp+2A8h] [ebp-2518h]
  int v437; // [esp+2ACh] [ebp-2514h]
  int v438; // [esp+2B0h] [ebp-2510h]
  int v439; // [esp+2B4h] [ebp-250Ch]
  int v440; // [esp+2B8h] [ebp-2508h]
  int v441; // [esp+2BCh] [ebp-2504h]
  int v442; // [esp+2C0h] [ebp-2500h]
  int v443; // [esp+2C4h] [ebp-24FCh]
  int v444; // [esp+2C8h] [ebp-24F8h]
  int v445; // [esp+2CCh] [ebp-24F4h]
  int v446; // [esp+2D0h] [ebp-24F0h]
  int v447; // [esp+2D4h] [ebp-24ECh]
  int v448; // [esp+2D8h] [ebp-24E8h]
  int v449; // [esp+2DCh] [ebp-24E4h]
  int v450; // [esp+2E0h] [ebp-24E0h]
  int v451; // [esp+2E4h] [ebp-24DCh]
  int v452; // [esp+2E8h] [ebp-24D8h]
  int v453; // [esp+2ECh] [ebp-24D4h]
  char v454; // [esp+2F0h] [ebp-24D0h]
  char v455; // [esp+2F8h] [ebp-24C8h]
  char v456; // [esp+300h] [ebp-24C0h]
  int *v457; // [esp+308h] [ebp-24B8h]
  char v458; // [esp+30Ch] [ebp-24B4h]
  int *v459; // [esp+390h] [ebp-2430h]
  int v460; // [esp+394h] [ebp-242Ch]
  int v461; // [esp+398h] [ebp-2428h]
  int v462; // [esp+39Ch] [ebp-2424h]
  int v463; // [esp+3A0h] [ebp-2420h]
  char v464; // [esp+3A4h] [ebp-241Ch]
  int v465; // [esp+428h] [ebp-2398h]
  int v466; // [esp+42Ch] [ebp-2394h]
  int v467; // [esp+430h] [ebp-2390h]
  int v468; // [esp+434h] [ebp-238Ch]
  int v469; // [esp+438h] [ebp-2388h]
  int v470; // [esp+43Ch] [ebp-2384h]
  int v471; // [esp+440h] [ebp-2380h]
  int v472; // [esp+444h] [ebp-237Ch]
  int v473; // [esp+448h] [ebp-2378h]
  int v474; // [esp+44Ch] [ebp-2374h]
  char v475; // [esp+450h] [ebp-2370h]
  int i6; // [esp+454h] [ebp-236Ch]
  _DWORD *v477; // [esp+458h] [ebp-2368h]
  int i5; // [esp+45Ch] [ebp-2364h]
  int v479; // [esp+460h] [ebp-2360h]
  int v480; // [esp+464h] [ebp-235Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v481; // [esp+468h] [ebp-2358h]
  int v482; // [esp+46Ch] [ebp-2354h]
  int v483; // [esp+470h] [ebp-2350h]
  WCHAR v484; // [esp+474h] [ebp-234Ch]
  char v485; // [esp+574h] [ebp-224Ch]
  int v486; // [esp+578h] [ebp-2248h]
  char Dst; // [esp+57Ch] [ebp-2244h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v488; // [esp+59Ch] [ebp-2224h]
  int i4; // [esp+5A0h] [ebp-2220h]
  char v490; // [esp+5A4h] [ebp-221Ch]
  int v491; // [esp+5A8h] [ebp-2218h]
  int v492; // [esp+5ACh] [ebp-2214h]
  int v493; // [esp+5B0h] [ebp-2210h]
  int v494; // [esp+5B4h] [ebp-220Ch]
  int v495; // [esp+5B8h] [ebp-2208h]
  int v496; // [esp+5BCh] [ebp-2204h]
  int v497; // [esp+5C0h] [ebp-2200h]
  int v498; // [esp+5C4h] [ebp-21FCh]
  int v499; // [esp+5C8h] [ebp-21F8h]
  __int16 v500; // [esp+5CCh] [ebp-21F4h]
  int v501; // [esp+5D0h] [ebp-21F0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v502; // [esp+5D4h] [ebp-21ECh]
  char v503; // [esp+5D8h] [ebp-21E8h]
  int v504; // [esp+5E8h] [ebp-21D8h]
  int v505; // [esp+5ECh] [ebp-21D4h]
  int v506; // [esp+5F0h] [ebp-21D0h]
  int i2; // [esp+5F4h] [ebp-21CCh]
  bool v508; // [esp+5F8h] [ebp-21C8h]
  int v509; // [esp+5FCh] [ebp-21C4h]
  int v510; // [esp+600h] [ebp-21C0h]
  int v511; // [esp+604h] [ebp-21BCh]
  int v512; // [esp+608h] [ebp-21B8h]
  int v513; // [esp+60Ch] [ebp-21B4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v514; // [esp+610h] [ebp-21B0h]
  char v515; // [esp+614h] [ebp-21ACh]
  struct STK_PER *v516; // [esp+618h] [ebp-21A8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v517; // [esp+61Ch] [ebp-21A4h]
  struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *v518; // [esp+620h] [ebp-21A0h]
  int v519; // [esp+624h] [ebp-219Ch]
  int v520; // [esp+628h] [ebp-2198h]
  struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *v521; // [esp+62Ch] [ebp-2194h]
  struct _MSG_RET_QUOTE_EX_GLOBAL_MARKET *v522; // [esp+630h] [ebp-2190h]
  struct MSG_RET_GSS_STK_DETAIL *v523; // [esp+634h] [ebp-218Ch]
  struct _MSG_RET_QUOTE_HQ_GLOBAL_MARKET *v524; // [esp+638h] [ebp-2188h]
  struct _MSG_RET_QUOTE_MINKLINE_GLOBAL_MARKET *v525; // [esp+63Ch] [ebp-2184h]
  struct _MSG_RET_QUOTE_RT_GLOBAL_MARKET *v526; // [esp+640h] [ebp-2180h]
  struct MSG_RET_GSS_STK_LIST *v527; // [esp+644h] [ebp-217Ch]
  struct MSG_RET_NLEVEL_ORDER_QUEUE *v528; // [esp+648h] [ebp-2178h]
  struct MSG_RET_MULTI_L2_QUOTE *v529; // [esp+64Ch] [ebp-2174h]
  struct MSG_RET_MULTI_L2_QUOTE *v530; // [esp+650h] [ebp-2170h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v531; // [esp+654h] [ebp-216Ch]
  int v532; // [esp+65Bh] [ebp-2165h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v533; // [esp+660h] [ebp-2160h]
  CHAR MultiByteStr; // [esp+664h] [ebp-215Ch]
  int v535; // [esp+665h] [ebp-215Bh]
  int v536; // [esp+669h] [ebp-2157h]
  int v537; // [esp+66Dh] [ebp-2153h]
  __int16 v538; // [esp+671h] [ebp-214Fh]
  char v539; // [esp+673h] [ebp-214Dh]
  struct MSG_RET_HIS_TRENDLINE_CFS *v540; // [esp+674h] [ebp-214Ch]
  struct MSG_RET_HIS_TRENDLINE *v541; // [esp+678h] [ebp-2148h]
  struct MSG_RET_TRENDLINE *v542; // [esp+67Ch] [ebp-2144h]
  struct MSG_RET_TRENDLINE *v543; // [esp+680h] [ebp-2140h]
  int v544; // [esp+684h] [ebp-213Ch]
  int v545; // [esp+70Ch] [ebp-20B4h]
  int v546; // [esp+794h] [ebp-202Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v547; // [esp+824h] [ebp-1F9Ch]
  int v548; // [esp+828h] [ebp-1F98h]
  signed __int16 *v549; // [esp+82Ch] [ebp-1F94h]
  void *v550; // [esp+830h] [ebp-1F90h]
  signed __int16 *v551; // [esp+834h] [ebp-1F8Ch]
  char v552; // [esp+838h] [ebp-1F88h]
  char v553; // [esp+83Ch] [ebp-1F84h]
  char v554; // [esp+85Bh] [ebp-1F65h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v555; // [esp+85Ch] [ebp-1F64h]
  char v556; // [esp+863h] [ebp-1F5Dh]
  char v557; // [esp+864h] [ebp-1F5Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v558; // [esp+868h] [ebp-1F58h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v559; // [esp+86Ch] [ebp-1F54h]
  int v560; // [esp+870h] [ebp-1F50h]
  unsigned int v561; // [esp+874h] [ebp-1F4Ch]
  struct MSG_RET_FAV_QUOTE_LIST *v562; // [esp+878h] [ebp-1F48h]
  struct MSG_RET_STKS_DDE_LIST *v563; // [esp+87Ch] [ebp-1F44h]
  int v564; // [esp+880h] [ebp-1F40h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v565; // [esp+884h] [ebp-1F3Ch]
  char v566; // [esp+888h] [ebp-1F38h]
  wchar_t v567; // [esp+88Ch] [ebp-1F34h]
  char v568; // [esp+88Eh] [ebp-1F32h]
  int v569; // [esp+98Ch] [ebp-1E34h]
  LPARAM v570; // [esp+990h] [ebp-1E30h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v571; // [esp+994h] [ebp-1E2Ch]
  LPARAM v572; // [esp+998h] [ebp-1E28h]
  unsigned int i8; // [esp+99Ch] [ebp-1E24h]
  LPARAM v574; // [esp+9A0h] [ebp-1E20h]
  unsigned int i7; // [esp+9A4h] [ebp-1E1Ch]
  char v576; // [esp+9A8h] [ebp-1E18h]
  char v577; // [esp+9ACh] [ebp-1E14h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v578; // [esp+9B0h] [ebp-1E10h]
  char v579[5]; // [esp+9B7h] [ebp-1E09h]
  char v580; // [esp+9BCh] [ebp-1E04h]
  int v581; // [esp+9BDh] [ebp-1E03h]
  int v582; // [esp+9C1h] [ebp-1DFFh]
  int v583; // [esp+9C5h] [ebp-1DFBh]
  __int16 v584; // [esp+9C9h] [ebp-1DF7h]
  char v585; // [esp+9CBh] [ebp-1DF5h]
  float i12; // [esp+9CCh] [ebp-1DF4h]
  int v587; // [esp+9D0h] [ebp-1DF0h]
  int v588; // [esp+9D4h] [ebp-1DECh]
  int v589; // [esp+9D8h] [ebp-1DE8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v590; // [esp+9DCh] [ebp-1DE4h]
  int v591; // [esp+9E0h] [ebp-1DE0h]
  void *v592; // [esp+9E4h] [ebp-1DDCh]
  int v593; // [esp+9E8h] [ebp-1DD8h]
  int v594; // [esp+9ECh] [ebp-1DD4h]
  int v595; // [esp+A08h] [ebp-1DB8h]
  char v596; // [esp+A0Ch] [ebp-1DB4h]
  LPARAM v597; // [esp+A10h] [ebp-1DB0h]
  char v598; // [esp+A14h] [ebp-1DACh]
  char v599; // [esp+A18h] [ebp-1DA8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v600; // [esp+A1Ch] [ebp-1DA4h]
  char v601; // [esp+A20h] [ebp-1DA0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v602; // [esp+A24h] [ebp-1D9Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v603; // [esp+A28h] [ebp-1D98h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v604; // [esp+A2Ch] [ebp-1D94h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v605; // [esp+A30h] [ebp-1D90h]
  struct BK_ITEM *v606; // [esp+A34h] [ebp-1D8Ch]
  int i16; // [esp+A38h] [ebp-1D88h]
  int v608; // [esp+A3Ch] [ebp-1D84h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v609; // [esp+A40h] [ebp-1D80h]
  int i; // [esp+A44h] [ebp-1D7Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v611; // [esp+A48h] [ebp-1D78h]
  struct _MSG_RET_QUOTE_MINKLINE_GLOBAL_MARKET *v612; // [esp+A4Ch] [ebp-1D74h]
  struct _MSG_RET_QUOTE_RT_GLOBAL_MARKET *v613; // [esp+A50h] [ebp-1D70h]
  struct MSG_RET_MULTI_L2_QUOTE *v614; // [esp+A54h] [ebp-1D6Ch]
  struct MSG_RET_MULTI_L2_QUOTE *v615; // [esp+A58h] [ebp-1D68h]
  struct MSG_RET_TRENDLINE *v616; // [esp+A5Ch] [ebp-1D64h]
  struct MSG_RET_TRENDLINE *v617; // [esp+A60h] [ebp-1D60h]
  struct MSG_RET_L2QUOTE_RATIOPRICE *v618; // [esp+A64h] [ebp-1D5Ch]
  LPARAM v619; // [esp+A68h] [ebp-1D58h]
  int i20; // [esp+A6Ch] [ebp-1D54h]
  LPARAM v621; // [esp+A70h] [ebp-1D50h]
  int i19; // [esp+A74h] [ebp-1D4Ch]
  char v623; // [esp+A78h] [ebp-1D48h]
  char v624; // [esp+A7Ch] [ebp-1D44h]
  LPARAM v625; // [esp+A80h] [ebp-1D40h]
  char v626[5]; // [esp+A87h] [ebp-1D39h]
  char v627; // [esp+A8Ch] [ebp-1D34h]
  int v628; // [esp+A8Dh] [ebp-1D33h]
  int v629; // [esp+A91h] [ebp-1D2Fh]
  int v630; // [esp+A95h] [ebp-1D2Bh]
  __int16 v631; // [esp+A99h] [ebp-1D27h]
  char v632; // [esp+A9Bh] [ebp-1D25h]
  struct MSG_RET_L2QUOTE_TRANSACTION *v633; // [esp+A9Ch] [ebp-1D24h]
  struct MSG_RET_L2QUOTE_PRICEORDER *v634; // [esp+AA0h] [ebp-1D20h]
  struct MSG_RET_BK_BASIC_INFO *v635; // [esp+AA4h] [ebp-1D1Ch]
  int i25; // [esp+AA8h] [ebp-1D18h]
  char v637; // [esp+AACh] [ebp-1D14h]
  LPARAM v638; // [esp+BA8h] [ebp-1C18h]
  LPARAM v639; // [esp+BACh] [ebp-1C14h]
  LPARAM v640; // [esp+BB0h] [ebp-1C10h]
  bool v641; // [esp+BB7h] [ebp-1C09h]
  LPARAM v642; // [esp+BB8h] [ebp-1C08h]
  int i24; // [esp+BBCh] [ebp-1C04h]
  int v644; // [esp+BC0h] [ebp-1C00h]
  int i23; // [esp+BC4h] [ebp-1BFCh]
  int v646; // [esp+BC8h] [ebp-1BF8h]
  struct DETAILREC *v647; // [esp+BCCh] [ebp-1BF4h]
  unsigned int v648; // [esp+BD0h] [ebp-1BF0h]
  unsigned int v649; // [esp+BD4h] [ebp-1BECh]
  int v650; // [esp+BD8h] [ebp-1BE8h]
  LPARAM v651; // [esp+BDCh] [ebp-1BE4h]
  unsigned int v652; // [esp+BE0h] [ebp-1BE0h]
  LPARAM v653; // [esp+BE4h] [ebp-1BDCh]
  char v654; // [esp+BE8h] [ebp-1BD8h]
  char v655; // [esp+BF0h] [ebp-1BD0h]
  int v656; // [esp+BF8h] [ebp-1BC8h]
  int v657; // [esp+BFCh] [ebp-1BC4h]
  char i22; // [esp+C01h] [ebp-1BBFh]
  char i21; // [esp+C02h] [ebp-1BBEh]
  int v660; // [esp+C03h] [ebp-1BBDh]
  char v661; // [esp+CE4h] [ebp-1ADCh]
  int v662; // [esp+CE5h] [ebp-1ADBh]
  int v663; // [esp+CE9h] [ebp-1AD7h]
  int v664; // [esp+CEDh] [ebp-1AD3h]
  __int16 v665; // [esp+CF1h] [ebp-1ACFh]
  char v666; // [esp+CF3h] [ebp-1ACDh]
  LPARAM v667; // [esp+CF4h] [ebp-1ACCh]
  int i18; // [esp+CF8h] [ebp-1AC8h]
  LPARAM v669; // [esp+CFCh] [ebp-1AC4h]
  char v670; // [esp+D00h] [ebp-1AC0h]
  LPARAM v671; // [esp+D04h] [ebp-1ABCh]
  int v672; // [esp+D08h] [ebp-1AB8h]
  wchar_t v673; // [esp+D0Ch] [ebp-1AB4h]
  char v674; // [esp+D0Eh] [ebp-1AB2h]
  char v675; // [esp+110Ch] [ebp-16B4h]
  int v676; // [esp+1110h] [ebp-16B0h]
  int v677; // [esp+1118h] [ebp-16A8h]
  LPARAM v678; // [esp+111Ch] [ebp-16A4h]
  int v679; // [esp+1124h] [ebp-169Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v680; // [esp+112Ch] [ebp-1694h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v681; // [esp+1130h] [ebp-1690h]
  int v682; // [esp+1134h] [ebp-168Ch]
  int v683; // [esp+1138h] [ebp-1688h]
  char v684; // [esp+113Ch] [ebp-1684h]
  char v685; // [esp+1140h] [ebp-1680h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v686; // [esp+1144h] [ebp-167Ch]
  struct MSG_RET_QUOTE_FENJIA *v687; // [esp+1148h] [ebp-1678h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v688; // [esp+114Ch] [ebp-1674h]
  char v689[5]; // [esp+1153h] [ebp-166Dh]
  char v690; // [esp+1158h] [ebp-1668h]
  int v691; // [esp+1159h] [ebp-1667h]
  int v692; // [esp+115Dh] [ebp-1663h]
  int v693; // [esp+1161h] [ebp-165Fh]
  __int16 v694; // [esp+1165h] [ebp-165Bh]
  char v695; // [esp+1167h] [ebp-1659h]
  struct MSG_RET_QUOTE_PANKOU *v696; // [esp+1168h] [ebp-1658h]
  int i17; // [esp+116Ch] [ebp-1654h]
  char v698[5]; // [esp+1173h] [ebp-164Dh]
  CHAR v699; // [esp+1178h] [ebp-1648h]
  int v700; // [esp+1179h] [ebp-1647h]
  int v701; // [esp+117Dh] [ebp-1643h]
  int v702; // [esp+1181h] [ebp-163Fh]
  __int16 v703; // [esp+1185h] [ebp-163Bh]
  char v704; // [esp+1187h] [ebp-1639h]
  int k; // [esp+1188h] [ebp-1638h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v706; // [esp+118Ch] [ebp-1634h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v707; // [esp+1190h] [ebp-1630h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v708; // [esp+1194h] [ebp-162Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v709; // [esp+1198h] [ebp-1628h]
  struct MSG_RET_L2QUOTE_PRICEORDER *v710; // [esp+119Ch] [ebp-1624h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v711; // [esp+11A0h] [ebp-1620h]
  struct MSG_RET_FAV_QUOTE_LIST *v712; // [esp+11A4h] [ebp-161Ch]
  struct MSG_RET_QUOTE_PUSH_QUOTETABLE_NEW *v713; // [esp+11A8h] [ebp-1618h]
  int j; // [esp+11ACh] [ebp-1614h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v715; // [esp+11B0h] [ebp-1610h]
  char v716; // [esp+11B4h] [ebp-160Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v717; // [esp+12ACh] [ebp-1514h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v718; // [esp+12B0h] [ebp-1510h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v719; // [esp+12B4h] [ebp-150Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v720; // [esp+12B8h] [ebp-1508h]
  struct MSG_RET_L2QUOTE_RATIOPRICE *v721; // [esp+12BCh] [ebp-1504h]
  char v722; // [esp+12C0h] [ebp-1500h]
  LPARAM v723; // [esp+12C4h] [ebp-14FCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v724; // [esp+12C8h] [ebp-14F8h]
  char v725; // [esp+12CCh] [ebp-14F4h]
  char v726; // [esp+12D0h] [ebp-14F0h]
  char v727; // [esp+12D4h] [ebp-14ECh]
  LPARAM v728; // [esp+12D8h] [ebp-14E8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v729; // [esp+12DCh] [ebp-14E4h]
  char v730; // [esp+12E0h] [ebp-14E0h]
  char v731; // [esp+12E4h] [ebp-14DCh]
  int v732; // [esp+12E8h] [ebp-14D8h]
  int v733; // [esp+12ECh] [ebp-14D4h]
  int i11; // [esp+12F0h] [ebp-14D0h]
  char v735; // [esp+12F4h] [ebp-14CCh]
  char v736; // [esp+1304h] [ebp-14BCh]
  int v737; // [esp+1308h] [ebp-14B8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v738; // [esp+130Ch] [ebp-14B4h]
  char v739; // [esp+1310h] [ebp-14B0h]
  char v740; // [esp+1314h] [ebp-14ACh]
  char v741; // [esp+1318h] [ebp-14A8h]
  int v742; // [esp+1338h] [ebp-1488h]
  char v743; // [esp+133Ch] [ebp-1484h]
  LPARAM v744; // [esp+1340h] [ebp-1480h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v745; // [esp+1344h] [ebp-147Ch]
  char v746; // [esp+1348h] [ebp-1478h]
  char v747; // [esp+134Ch] [ebp-1474h]
  char v748; // [esp+1350h] [ebp-1470h]
  LPARAM v749; // [esp+1354h] [ebp-146Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v750; // [esp+1358h] [ebp-1468h]
  char v751; // [esp+135Ch] [ebp-1464h]
  char v752; // [esp+1360h] [ebp-1460h]
  char v753; // [esp+1364h] [ebp-145Ch]
  LPARAM v754; // [esp+1368h] [ebp-1458h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v755; // [esp+136Ch] [ebp-1454h]
  char v756; // [esp+1370h] [ebp-1450h]
  char v757; // [esp+1374h] [ebp-144Ch]
  int v758; // [esp+1378h] [ebp-1448h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v759; // [esp+137Ch] [ebp-1444h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v760; // [esp+1380h] [ebp-1440h]
  struct MSG_RET_L2QUOTE_TRANSACTION *v761; // [esp+1384h] [ebp-143Ch]
  int v762; // [esp+1388h] [ebp-1438h]
  unsigned int v763; // [esp+138Ch] [ebp-1434h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v764; // [esp+1390h] [ebp-1430h]
  unsigned int v765; // [esp+1394h] [ebp-142Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v766; // [esp+1398h] [ebp-1428h]
  unsigned int v767; // [esp+139Ch] [ebp-1424h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v768; // [esp+13A0h] [ebp-1420h]
  int i3; // [esp+13A4h] [ebp-141Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v770; // [esp+13A8h] [ebp-1418h]
  int v771; // [esp+13ACh] [ebp-1414h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v772; // [esp+13B0h] [ebp-1410h]
  char v773; // [esp+13B4h] [ebp-140Ch]
  int v774; // [esp+13C4h] [ebp-13FCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v775; // [esp+13C8h] [ebp-13F8h]
  char v776; // [esp+13CCh] [ebp-13F4h]
  int v777; // [esp+13DCh] [ebp-13E4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v778; // [esp+13E0h] [ebp-13E0h]
  char v779; // [esp+13E4h] [ebp-13DCh]
  int v780; // [esp+13F4h] [ebp-13CCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v781; // [esp+13F8h] [ebp-13C8h]
  char v782; // [esp+13FCh] [ebp-13C4h]
  unsigned int v783; // [esp+140Ch] [ebp-13B4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v784; // [esp+1410h] [ebp-13B0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v785; // [esp+1414h] [ebp-13ACh]
  char v786; // [esp+1418h] [ebp-13A8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v787; // [esp+1428h] [ebp-1398h]
  int i15; // [esp+142Ch] [ebp-1394h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v789; // [esp+1430h] [ebp-1390h]
  unsigned int ll; // [esp+1434h] [ebp-138Ch]
  int v791; // [esp+1438h] [ebp-1388h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v792; // [esp+143Ch] [ebp-1384h]
  char v793; // [esp+1440h] [ebp-1380h]
  unsigned int kk; // [esp+1450h] [ebp-1370h]
  int v795; // [esp+1454h] [ebp-136Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v796; // [esp+1458h] [ebp-1368h]
  char v797; // [esp+145Ch] [ebp-1364h]
  unsigned int jj; // [esp+146Ch] [ebp-1354h]
  int v799; // [esp+1470h] [ebp-1350h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v800; // [esp+1474h] [ebp-134Ch]
  char v801; // [esp+1478h] [ebp-1348h]
  unsigned int n; // [esp+1488h] [ebp-1338h]
  int v803; // [esp+148Ch] [ebp-1334h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v804; // [esp+1490h] [ebp-1330h]
  char v805; // [esp+1494h] [ebp-132Ch]
  unsigned int v806; // [esp+14A4h] [ebp-131Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v807; // [esp+14A8h] [ebp-1318h]
  unsigned int ii; // [esp+14ACh] [ebp-1314h]
  int v809; // [esp+14B0h] [ebp-1310h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v810; // [esp+14B4h] [ebp-130Ch]
  char v811; // [esp+14B8h] [ebp-1308h]
  unsigned int m; // [esp+14C8h] [ebp-12F8h]
  int v813; // [esp+14CCh] [ebp-12F4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v814; // [esp+14D0h] [ebp-12F0h]
  char v815; // [esp+14D4h] [ebp-12ECh]
  unsigned int v816; // [esp+14E4h] [ebp-12DCh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v817; // [esp+14E8h] [ebp-12D8h]
  unsigned int v818; // [esp+14ECh] [ebp-12D4h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v819; // [esp+14F0h] [ebp-12D0h]
  char v820; // [esp+14F4h] [ebp-12CCh]
  char v821; // [esp+14FCh] [ebp-12C4h]
  int v822; // [esp+1504h] [ebp-12BCh]
  char i10; // [esp+1509h] [ebp-12B7h]
  char i9; // [esp+150Ah] [ebp-12B6h]
  int v825; // [esp+150Bh] [ebp-12B5h]
  char v826; // [esp+15F0h] [ebp-11D0h]
  int v827; // [esp+15F1h] [ebp-11CFh]
  int v828; // [esp+15F5h] [ebp-11CBh]
  int v829; // [esp+15F9h] [ebp-11C7h]
  __int16 v830; // [esp+15FDh] [ebp-11C3h]
  char v831; // [esp+15FFh] [ebp-11C1h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v832; // [esp+1600h] [ebp-11C0h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v833; // [esp+1604h] [ebp-11BCh]
  int i14; // [esp+1608h] [ebp-11B8h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v835; // [esp+160Ch] [ebp-11B4h]
  unsigned int i1; // [esp+1610h] [ebp-11B0h]
  int v837; // [esp+1614h] [ebp-11ACh]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v838; // [esp+1618h] [ebp-11A8h]
  char v839; // [esp+161Ch] [ebp-11A4h]
  unsigned int nn; // [esp+162Ch] [ebp-1194h]
  int v841; // [esp+1630h] [ebp-1190h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v842; // [esp+1634h] [ebp-118Ch]
  char v843; // [esp+1638h] [ebp-1188h]
  unsigned int mm; // [esp+1648h] [ebp-1178h]
  int v845; // [esp+164Ch] [ebp-1174h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v846; // [esp+1650h] [ebp-1170h]
  char v847; // [esp+1654h] [ebp-116Ch]
  unsigned int l; // [esp+1664h] [ebp-115Ch]
  int v849; // [esp+1668h] [ebp-1158h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v850; // [esp+166Ch] [ebp-1154h]
  char v851; // [esp+1670h] [ebp-1150h]
  unsigned int v852; // [esp+1680h] [ebp-1140h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v853; // [esp+1684h] [ebp-113Ch]
  int i13; // [esp+1688h] [ebp-1138h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v855; // [esp+168Ch] [ebp-1134h]
  int v856; // [esp+1690h] [ebp-1130h]
  int v857; // [esp+1694h] [ebp-112Ch]
  char v858; // [esp+1698h] [ebp-1128h]
  char v859; // [esp+169Ch] [ebp-1124h]
  char v860; // [esp+1AA0h] [ebp-D20h]
  char v861; // [esp+1AA4h] [ebp-D1Ch]
  char v862; // [esp+1AA8h] [ebp-D18h]
  char v863; // [esp+1AACh] [ebp-D14h]
  char v864; // [esp+1AB0h] [ebp-D10h]
  LPARAM v865; // [esp+1AB4h] [ebp-D0Ch]
  LPCSTR v866; // [esp+1AB8h] [ebp-D08h]
  int v867; // [esp+1ABCh] [ebp-D04h]
  int v868; // [esp+1AC4h] [ebp-CFCh]
  char v869; // [esp+1AC8h] [ebp-CF8h]
  LPCSTR v870; // [esp+1ACCh] [ebp-CF4h]
  bool v871; // [esp+1AD3h] [ebp-CEDh]
  int v872; // [esp+1AD4h] [ebp-CECh]
  char v873; // [esp+1AD8h] [ebp-CE8h]
  char v874; // [esp+1ADCh] [ebp-CE4h]
  bool v875; // [esp+1AE7h] [ebp-CD9h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v876; // [esp+1AE8h] [ebp-CD8h]
  int v877; // [esp+1AECh] [ebp-CD4h]
  char v878; // [esp+1AF0h] [ebp-CD0h]
  int v879; // [esp+1AF4h] [ebp-CCCh]
  LPARAM v880; // [esp+1AF8h] [ebp-CC8h]
  char v881; // [esp+1AFCh] [ebp-CC4h]
  char v882; // [esp+1B00h] [ebp-CC0h]
  int v883; // [esp+1B04h] [ebp-CBCh]
  char v884; // [esp+1B08h] [ebp-CB8h]
  char v885; // [esp+1B0Ch] [ebp-CB4h]
  LPARAM v886; // [esp+1B10h] [ebp-CB0h]
  char v887; // [esp+1B14h] [ebp-CACh]
  char v888; // [esp+1B18h] [ebp-CA8h]
  char Src; // [esp+1B1Ch] [ebp-CA4h]
  char v890; // [esp+1F1Ch] [ebp-8A4h]
  char v891; // [esp+1F20h] [ebp-8A0h]
  char v892; // [esp+1F24h] [ebp-89Ch]
  char v893; // [esp+1F28h] [ebp-898h]
  char v894; // [esp+1F2Ch] [ebp-894h]
  LPARAM lParam; // [esp+1F30h] [ebp-890h]
  char v896; // [esp+1F34h] [ebp-88Ch]
  char v897; // [esp+1F38h] [ebp-888h]
  LPCSTR lpMultiByteStr; // [esp+1F3Ch] [ebp-884h]
  bool v899; // [esp+1F43h] [ebp-87Dh]
  int v900; // [esp+1F44h] [ebp-87Ch]
  char v901; // [esp+1F48h] [ebp-878h]
  char v902; // [esp+1F4Ch] [ebp-874h]
  char v903; // [esp+1F50h] [ebp-870h]
  char v904; // [esp+1F54h] [ebp-86Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v905; // [esp+1F5Ch] [ebp-864h]
  int v906; // [esp+1F60h] [ebp-860h]
  char v907; // [esp+1F64h] [ebp-85Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v908; // [esp+1F68h] [ebp-858h]
  LPCSTR lpString; // [esp+1F6Ch] [ebp-854h]
  int v910; // [esp+1F70h] [ebp-850h]
  int v911; // [esp+1F74h] [ebp-84Ch]
  int cchWideChar; // [esp+1F7Ch] [ebp-844h]
  char v913; // [esp+1F80h] [ebp-840h]
  char v914; // [esp+1F84h] [ebp-83Ch]
  char v915; // [esp+1F88h] [ebp-838h]
  LPARAM v916; // [esp+1F8Ch] [ebp-834h]
  char v917; // [esp+1F90h] [ebp-830h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v918; // [esp+1F94h] [ebp-82Ch]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v919; // [esp+1F98h] [ebp-828h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v920; // [esp+1F9Ch] [ebp-824h]
  struct MSG_RET_GLOBAL_HIS_TRENDLINE *v921; // [esp+1FA0h] [ebp-820h]
  WCHAR Caption; // [esp+1FA4h] [ebp-81Ch]
  char v923; // [esp+27ACh] [ebp-14h]
  char v924; // [esp+27B0h] [ebp-10h]
  int v925; // [esp+27BCh] [ebp-4h]

  v380 = this;
  CDataMgr::CheckThreadId(this);
  LightLogger::CLogger::GetLogger(&v924, L"DataRecv");
  v925 = 0;
  if ( *((_BYTE *)v380 + 494) )
  {
    v2 = (LightLogger::CLogger *)unknown_libname_100(&v924);
    LightLogger::CLogger::WriteLogLine(v2, L"AddData m_bStopRequest==true return.", 20000);
    v925 = -1;
    sub_100D5E60(&v924);
    return;
  }
  if ( QDataEngine::m_bDataReInit )
  {
    v3 = (LightLogger::CLogger *)unknown_libname_100(&v924);
    LightLogger::CLogger::WriteLogLine(v3, L"AddData m_bDataReInit==true return.", 20000);
    v925 = -1;
    sub_100D5E60(&v924);
    return;
  }
  v921 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)*a2;
  v4 = sub_1036D010(&v475);
  v379 = v4;
  v5 = (const WCHAR *)mfc80xU_870(v4);
  SetCurrentDirectoryW(v5);
  mfc80xU_577(&v475);
  wsprintfW(&Caption, L"Add data %d, len %d", *((signed __int16 *)v921 + 2), *(_DWORD *)v921);
  v6 = (LightLogger::CLogger *)unknown_libname_100(&v924);
  LightLogger::CLogger::WriteLogLine(v6, &Caption, 20000);
  CGlobalEnv::GetGlobalEnv(&v923);
  LOBYTE(v925) = 1;
  v378 = *((signed __int16 *)v921 + 2);
  if ( v378 <= 322 )
  {
    if ( v378 == 322 )
    {
      v611 = v921;
      if ( !*((_BYTE *)v921 + 10) || !*(_DWORD *)((char *)v921 + 6) )
      {
        LOBYTE(v925) = 0;
        sub_100D5E60(&v923);
        v925 = -1;
        sub_100D5E60(&v924);
        return;
      }
      QDataEngine::SaveImportIndexLastDate(*(_DWORD *)((char *)v611 + 17), *(_DWORD *)((char *)v611 + 21));
      for ( i = 0; i < *(_DWORD *)((char *)v611 + 25); ++i )
      {
        QDataEngine::Add_ImportIndexData(
          1,
          (char *)v611 + 52 * i + 29,
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v611 + 52 * i + 29));
        v225 = i + 1;
      }
      v283 = v225;
      v415 = &v283;
      v313 = sub_1006A2B0(0);
      sub_102B3660(*(HWND *)((char *)v921 + 6), 0x706u, v283);
    }
    else
    {
      v378 -= 2;
      switch ( v378 )
      {
        case 0:
          if ( QDataEngine::GetLoginInStatus() )
          {
            *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 14) = 0;
            CDataMgr::OffLine(v380);
            v7 = unknown_libname_100(&v923);
            MessageBoxW(*(HWND *)(v7 + 156), &word_103D585C, &word_103D5850, 0x30u);
            CDataMgr::ShowLogonDlg(v380);
          }
          goto LABEL_1064;
        case 8:
          v719 = v921;
          if ( !*((_BYTE *)v921 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          QDataEngine::AddIndexSpecialData((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v719 + 17));
          CDataMgr::SendIndexSpToUI(v380, *(_DWORD *)((char *)v719 + 6));
          goto LABEL_1064;
        case 11:
          v715 = v921;
          sub_10086DB0(&v716);
          for ( j = 0; j < *(signed __int16 *)((char *)v715 + 17); ++j )
          {
            sub_10105F60(&v716, (char *)v715 + 194 * j + 19);
            QDataEngine::Add_DynamicDataStock(
              *((_BYTE *)v715 + 194 * j + 19),
              (char *)v715 + 194 * j + 24,
              (struct _QUOTEREC *)&v716);
          }
          CDataMgr::SendRecordDataToUI(v380, *(HWND *)((char *)v715 + 6), 0x711u);
          goto LABEL_1064;
        case 15:
          v768 = v921;
          if ( !*((_BYTE *)v921 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          v767 = *(_DWORD *)((char *)v768 + 49) - *(_DWORD *)((char *)v768 + 53);
          if ( (v767 & 0x80000000) != 0 )
            v767 = 0;
          v283 = *(_DWORD *)((char *)v768 + 17);
          v282 = (int)v768 + 57;
          QDataEngine::Add_DetailData(
            (char *)v768 + 26,
            *((_BYTE *)v768 + 25),
            v767,
            *(_DWORD *)((char *)v768 + 53),
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v768 + 57),
            v283);
          CDataMgr::SendF1DetailL1ToUI(
            v380,
            *(HWND *)((char *)v768 + 6),
            (char *)v768 + 26,
            *((_BYTE *)v768 + 25),
            *(_DWORD *)((char *)v768 + 17));
          v283 = 1;
          v282 = 1;
          CDataMgr::PushDataRequest(
            (int)v380 + 497,
            *((_BYTE *)v768 + 25),
            (char *)v768 + 26,
            *(_DWORD *)((char *)v768 + 6),
            1,
            1);
          goto LABEL_1064;
        case 20:
          v760 = v921;
          QDataEngine::SetRankList(*((char *)v921 + 17), 0, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v921 + 18));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            1,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 1298));
          QDataEngine::SetRankList(*((char *)v760 + 17), 3, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 658));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            4,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 1938));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            5,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 5138));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            6,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 2578));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            7,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 3858));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            2,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 4498));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            9,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 3218));
          QDataEngine::SetRankList(
            *((char *)v760 + 17),
            8,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v760 + 5778));
          QDataEngine::SaveRankList();
          CDataMgr::SendRankToUI(v380, *(HWND *)((char *)v760 + 6), *((char *)v760 + 17));
          goto LABEL_1064;
        case 23:
          v709 = v921;
          v327 = mfc80xU_287(&v429, (char *)v921 + 26);
          v326 = v327;
          LOBYTE(v925) = 72;
          v283 = *(_DWORD *)((char *)v709 + 17);
          v203 = (const wchar_t *)mfc80xU_870(v327);
          QDataEngine::SaveHisRtData(
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v709 + 37),
            *(signed __int16 *)((char *)v709 + 35),
            *((_BYTE *)v709 + 25),
            v203,
            v283);
          LOBYTE(v925) = 1;
          mfc80xU_577(&v429);
          CDataMgr::SendHisTrendDataToUI(
            v380,
            *(HWND *)((char *)v709 + 6),
            (char *)v709 + 26,
            *((_BYTE *)v709 + 25),
            *(_DWORD *)((char *)v709 + 17));
          goto LABEL_1064;
        case 28:
          v759 = v921;
          if ( *((_BYTE *)v921 + 17) )
          {
            QDataEngine::SetRankList(2, 1, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 19));
            QDataEngine::SetRankList(2, 4, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 659));
            QDataEngine::SetRankList(17, 1, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 1299));
            QDataEngine::SetRankList(17, 4, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 1939));
          }
          else
          {
            QDataEngine::SetRankList(2, 0, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 19));
            QDataEngine::SetRankList(2, 3, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 659));
            QDataEngine::SetRankList(17, 0, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 1299));
            QDataEngine::SetRankList(17, 3, (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v759 + 1939));
          }
          QDataEngine::SaveRankList();
          if ( *(_DWORD *)((char *)v759 + 6) )
            CDataMgr::SendRankUpDownToUI(v380, *(HWND *)((char *)v759 + 6), *((_BYTE *)v759 + 17));
          else
            CDataMgr::OnTimeSendRankUpDownToUI(v380, *((_BYTE *)v759 + 17));
          goto LABEL_1064;
        case 139:
          v706 = v921;
          for ( k = 0; k < *(_DWORD *)((char *)v706 + 18); ++k )
            QDataEngine::AddCMLD_Data(
              *((_BYTE *)v706 + 104 * k + 22),
              (char *)v706 + 104 * k + 23,
              (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v706 + 104 * k + 22));
          CDataMgr::SendDataArriveInfoToUI(v380, *(HWND *)((char *)v706 + 6), 0x19u);
          goto LABEL_1064;
        case 141:
          v708 = v921;
          v325 = mfc80xU_287(&v428, (char *)v921 + 18);
          v324 = v325;
          LOBYTE(v925) = 73;
          v283 = *(_DWORD *)((char *)v708 + 25);
          v204 = (const wchar_t *)mfc80xU_870(v325);
          QDataEngine::SaveHisRtData(
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v708 + 31),
            *(signed __int16 *)((char *)v708 + 29),
            *((_BYTE *)v708 + 17),
            v204,
            v283);
          LOBYTE(v925) = 1;
          mfc80xU_577(&v428);
          CDataMgr::SendHisTrendDataToUI(
            v380,
            *(HWND *)((char *)v708 + 6),
            (char *)v708 + 18,
            *((_BYTE *)v708 + 17),
            *(_DWORD *)((char *)v708 + 25));
          goto LABEL_1064;
        case 181:
          v696 = v921;
          if ( !v921 || *(_DWORD *)((char *)v696 + 17) != QDataEngine::GetCurDateByMarket(8, 0) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::SendGzqhPankouToUI(v380, *(HWND *)((char *)v696 + 6), v696);
          goto LABEL_1064;
        case 182:
          v687 = v921;
          if ( *(_DWORD *)((char *)v921 + 6) )
            CDataMgr::SendGzqhRatioPriceToUI(v380, *(HWND *)((char *)v687 + 6), v687);
          goto LABEL_1064;
        case 184:
          v833 = v921;
          if ( !*((_BYTE *)v921 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          v283 = (int)v921;
          v457 = &v283;
          v346 = sub_1006A2B0(0);
          sub_102B3660(*(HWND *)((char *)v921 + 6), 0x705u, v283);
          break;
        default:
          goto LABEL_1063;
      }
    }
    goto LABEL_1064;
  }
  if ( v378 > 601 )
  {
    if ( v378 <= 1000 )
    {
      if ( v378 == 1000 )
      {
        QDataEngine::SetHisLoginInStatus(1);
      }
      else
      {
        v378 -= 602;
        switch ( v378 )
        {
          case 0:
            v850 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v850 < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v849 = 0;
            sub_100F5920(&v851);
            LOBYTE(v925) = 38;
            v283 = 0;
            v282 = (int)&v849;
            v281 = &v851;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v850 + 17),
                                     *((_BYTE *)v850 + 21),
                                     (char *)v850 + 27,
                                     *(_DWORD *)((char *)v850 + 23),
                                     &v851,
                                     &v849,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v851);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( l = 0; ; ++l )
            {
              v80 = sub_10003950(&v851);
              if ( l >= v80 )
                break;
              v282 = sub_10003990(l);
              v281 = (char *)sub_10003990(l);
              v81 = sub_10003990(l);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v81 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                1);
            }
            v283 = v849;
            v282 = 513;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v82 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v82, (unsigned int)v280, 0x501u, 0x201u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v851);
            goto LABEL_1064;
          case 1:
            v819 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v819 < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( *((_BYTE *)v819 + 21) == 2 )
              sub_10128E30((char *)v380 + 569);
            v818 = 0;
            v283 = (int)&v818;
            if ( !CDataMgr::PreProcMoneyRankData(
                    v380,
                    *(_DWORD *)((char *)v819 + 17),
                    *((_BYTE *)v819 + 21),
                    (char *)v819 + 26,
                    *(_DWORD *)((char *)v819 + 22),
                    &v818) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v818;
            v282 = 514;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v96 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v96, (unsigned int)v280, 0x501u, 0x202u, v283);
            goto LABEL_1064;
          case 2:
            v814 = v921;
            if ( !v921 || !*((_BYTE *)v814 + 10) || *(_DWORD *)v814 < 1 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v815);
            LOBYTE(v925) = 42;
            v813 = 0;
            v283 = 0;
            v282 = (int)&v813;
            v281 = &v815;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v814 + 17),
                                     *((_BYTE *)v814 + 21),
                                     (char *)v814 + 26,
                                     *(_DWORD *)((char *)v814 + 22),
                                     &v815,
                                     &v813,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v815);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( (unsigned int)sub_10003950(&v815) < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v815);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( m = 0; ; ++m )
            {
              v98 = sub_10003950(&v815);
              if ( m >= v98 )
                break;
              v282 = sub_10003990(m);
              v281 = (char *)sub_10003990(m);
              v99 = sub_10003990(m);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v99 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                1);
            }
            v283 = v813;
            v282 = 515;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v100 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v100, (unsigned int)v280, 0x501u, 0x203u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v815);
            goto LABEL_1064;
          case 3:
            v784 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( *((_BYTE *)v784 + 21) == 2 )
              sub_10128E30((char *)v380 + 585);
            v783 = 0;
            v283 = (int)&v783;
            if ( !CDataMgr::PreProcMoneyRankData(
                    v380,
                    *(_DWORD *)((char *)v784 + 17),
                    *((_BYTE *)v784 + 21),
                    (char *)v784 + 27,
                    *(_DWORD *)((char *)v784 + 23),
                    &v783) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v783;
            v282 = 519;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v117 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v117, (unsigned int)v280, 0x501u, 0x207u, v283);
            goto LABEL_1064;
          case 4:
            v781 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v782);
            LOBYTE(v925) = 49;
            v780 = 0;
            v283 = 0;
            v282 = (int)&v780;
            v281 = &v782;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v781 + 17),
                                     *((_BYTE *)v781 + 21),
                                     (char *)v781 + 27,
                                     *(_DWORD *)((char *)v781 + 23),
                                     &v782,
                                     &v780,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v782);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( (unsigned int)sub_10003950(&v782) < 1 )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v782);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v282 = sub_10003950(&v782);
            v118 = (struct MainCapFlowShowDetailClientPaid *)sub_100F5970(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v781 + 22), v118, v282, 1);
            v283 = v780;
            v282 = 520;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v119 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v119, (unsigned int)v280, 0x501u, 0x208u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v782);
            goto LABEL_1064;
          case 5:
LABEL_317:
            v807 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( *((_BYTE *)v807 + 21) == 2 )
              sub_10128E30((char *)v380 + 569);
            v806 = 0;
            v283 = (int)&v806;
            if ( !CDataMgr::PreProcMoneyRankData(
                    v380,
                    *(_DWORD *)((char *)v807 + 17),
                    *((_BYTE *)v807 + 21),
                    (char *)v807 + 30,
                    *(_DWORD *)((char *)v807 + 26),
                    &v806) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v806;
            v282 = 516;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v104 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v104, (unsigned int)v280, 0x501u, 0x204u, v283);
            goto LABEL_1064;
          case 6:
            v804 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v805);
            LOBYTE(v925) = 44;
            v803 = 0;
            v283 = 0;
            v282 = (int)&v803;
            v281 = &v805;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v804 + 17),
                                     *((_BYTE *)v804 + 21),
                                     (char *)v804 + 30,
                                     *(_DWORD *)((char *)v804 + 26),
                                     &v805,
                                     &v803,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v805);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( n = 0; ; ++n )
            {
              v105 = sub_10003950(&v805);
              if ( n >= v105 )
                break;
              v282 = sub_10003990(n);
              v281 = (char *)sub_10003990(n);
              v106 = sub_10003990(n);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v106 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                1);
            }
            v283 = v803;
            v282 = 517;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v107 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v107, (unsigned int)v280, 0x501u, 0x205u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v805);
            goto LABEL_1064;
          case 8:
            v817 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v817 < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( *((_BYTE *)v817 + 21) == 2 )
              sub_10128E30((char *)v380 + 585);
            v816 = 0;
            v283 = (int)&v816;
            if ( !CDataMgr::PreProcMoneyRankData(
                    v380,
                    *(_DWORD *)((char *)v817 + 17),
                    *((_BYTE *)v817 + 21),
                    (char *)v817 + 26,
                    *(_DWORD *)((char *)v817 + 22),
                    &v816) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v816;
            v282 = 514;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v97 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v97, (unsigned int)v280, 0x501u, 0x202u, v283);
            goto LABEL_1064;
          case 9:
            v810 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v811);
            LOBYTE(v925) = 43;
            v809 = 0;
            v283 = *(_DWORD *)((char *)v810 + 13);
            v282 = (int)&v809;
            v281 = &v811;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v810 + 17),
                                     *((_BYTE *)v810 + 21),
                                     (char *)v810 + 26,
                                     *(_DWORD *)((char *)v810 + 22),
                                     &v811,
                                     &v809,
                                     v283) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v811);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( ii = 0; ; ++ii )
            {
              v101 = sub_10003950(&v811);
              if ( ii >= v101 )
                break;
              v282 = sub_10003990(ii);
              v281 = (char *)sub_10003990(ii);
              v102 = sub_10003990(ii);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v102 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                1);
            }
            v283 = v809;
            v282 = 515;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v103 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v103, (unsigned int)v280, 0x501u, 0x203u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v811);
            goto LABEL_1064;
          case 11:
            v547 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            std::basic_ifstream<char,std::char_traits<char>>::basic_ifstream<char,std::char_traits<char>>(
              &v546,
              L"data\\datavernum.dat",
              1,
              64,
              1);
            LOBYTE(v925) = 95;
            if ( (unsigned __int8)std::ios_base::operator!((char *)&v546 + *(_DWORD *)(v546 + 4)) )
            {
              std::basic_ofstream<char,std::char_traits<char>>::basic_ofstream<char,std::char_traits<char>>(
                &v545,
                L"data\\datavernum.dat",
                2,
                64,
                1);
              LOBYTE(v925) = 96;
              if ( !(unsigned __int8)std::ios_base::operator!((char *)&v545 + *(_DWORD *)(v545 + 4)) )
              {
                std::basic_ostream<char,std::char_traits<char>>::operator<<(&v545, *(_DWORD *)((char *)v547 + 17));
                std::basic_ofstream<char,std::char_traits<char>>::close(&v545);
              }
              LOBYTE(v925) = 95;
              std::basic_ofstream<char,std::char_traits<char>>::`vbase destructor(&v545);
              LOBYTE(v925) = 1;
              std::basic_ifstream<char,std::char_traits<char>>::`vbase destructor(&v546);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v548 = 0;
            std::basic_istream<char,std::char_traits<char>>::operator>>(&v546, &v548);
            std::basic_ifstream<char,std::char_traits<char>>::close(&v546);
            if ( v548 != *(_DWORD *)((char *)v547 + 17) )
            {
              QDataEngine::ClearAllKlineData();
              QDataEngine::ClearAllRtlineData();
              std::basic_ofstream<char,std::char_traits<char>>::basic_ofstream<char,std::char_traits<char>>(
                &v544,
                L"data\\datavernum.dat",
                18,
                64,
                1);
              LOBYTE(v925) = 97;
              if ( (unsigned __int8)std::ios_base::operator!((char *)&v544 + *(_DWORD *)(v544 + 4)) )
              {
                LOBYTE(v925) = 95;
                std::basic_ofstream<char,std::char_traits<char>>::`vbase destructor(&v544);
                LOBYTE(v925) = 1;
                std::basic_ifstream<char,std::char_traits<char>>::`vbase destructor(&v546);
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              std::basic_ostream<char,std::char_traits<char>>::operator<<(&v544, *(_DWORD *)((char *)v547 + 17));
              std::basic_ofstream<char,std::char_traits<char>>::close(&v544);
              v255 = CDataMgr::GetReceiverWnd(v380);
              CViewManager::PostBroadcastCommand(v255, 0x71u, 0);
              LOBYTE(v925) = 95;
              std::basic_ofstream<char,std::char_traits<char>>::`vbase destructor(&v544);
            }
            LOBYTE(v925) = 1;
            std::basic_ifstream<char,std::char_traits<char>>::`vbase destructor(&v546);
            goto LABEL_1064;
          case 19:
            v571 = v921;
            if ( !v921 || *((char *)v571 + 10) < 1 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v569 = sub_102F07C0();
            if ( !*((_BYTE *)v571 + 17) )
            {
              v567 = 0;
              memset(&v568, 0, 0xFEu);
              LightLogger::CLogger::GetLogger(&v566, L"ShortDecisionProc");
              LOBYTE(v925) = 89;
              v241 = CDataMgr::GetCurDateByMarket(v380, 1, 0);
              sub_1000EBE0(&v567, L"Validate Error,Clear Data,QuoteDate:%d", v241);
              v242 = (LightLogger::CLogger *)unknown_libname_100(&v566);
              LightLogger::CLogger::WriteLogLine(v242, &v567, 10000);
              LOBYTE(v925) = 1;
              sub_100D5E60(&v566);
            }
            v400 = mfc80xU_762(16);
            LOBYTE(v925) = 90;
            if ( v400 )
              v301 = sub_10129100(v400);
            else
              v301 = 0;
            v401 = v301;
            LOBYTE(v925) = 1;
            v570 = v301;
            if ( !v301 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( !(unsigned __int8)CDataMgr::PreProcShortDecisionData(
                                     (char *)v571 + 22,
                                     *(_DWORD *)((char *)v571 + 18),
                                     v570) )
            {
              if ( v570 )
              {
                v398 = v570;
                v399 = v570;
                if ( v570 )
                  v300 = sub_100C6A50(1);
                else
                  v300 = 0;
                v570 = 0;
              }
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( (unsigned __int8)sub_10030900(v570) )
            {
              if ( v570 )
              {
                v396 = v570;
                v397 = v570;
                if ( v570 )
                  v299 = sub_100C6A50(1);
                else
                  v299 = 0;
                v570 = 0;
              }
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( v569 )
              sub_10031730(0x412u, *((unsigned __int8 *)v571 + 17), v570);
            goto LABEL_1064;
          case 20:
            v565 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v564 = 0;
            v283 = (int)&v564;
            v282 = *(_DWORD *)((char *)v565 + 23);
            v281 = (char *)v565 + 27;
            v279 = *(float *)((char *)v565 + 17);
            LOBYTE(v280) = *((_BYTE *)v565 + 21);
            if ( !(unsigned __int8)CDataMgr::ProcStkDDEData(v380, LODWORD(v279), v280, (char *)v565 + 27, v282, &v564) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v564;
            v282 = 54;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v243 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v243, (unsigned int)v280, (unsigned int)v281, v282, v283);
            goto LABEL_1064;
          case 21:
          case 23:
            v562 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v561 = 0;
            if ( !CDataMgr::ProcFavStkDDEData(v380, v562, &v561) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v561;
            v282 = 56;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v244 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v244, (unsigned int)v280, 0x501u, 0x38u, v283);
            goto LABEL_1064;
          case 22:
            v563 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( !CDataMgr::ProcBkDDEData(v380, v563) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::SendMsgToUI(v380, *(HWND *)((char *)v921 + 6), 0x37u);
            goto LABEL_1064;
          case 24:
            v559 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v560 = 0;
            v283 = (int)&v560;
            v282 = *(_DWORD *)((char *)v559 + 26);
            v281 = (char *)v559 + 30;
            v279 = *(float *)((char *)v559 + 17);
            LOBYTE(v280) = *((_BYTE *)v559 + 21);
            if ( !(unsigned __int8)CDataMgr::ProcStkDDEData(v380, LODWORD(v279), v280, (char *)v559 + 30, v282, &v560) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = v560;
            v282 = 57;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v245 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v245, (unsigned int)v280, (unsigned int)v281, v282, v283);
            goto LABEL_1064;
          case 25:
            v778 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v779);
            LOBYTE(v925) = 50;
            v777 = 0;
            v283 = 0;
            v282 = (int)&v777;
            v281 = &v779;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v778 + 17),
                                     *((_BYTE *)v778 + 21),
                                     (char *)v778 + 27,
                                     *(_DWORD *)((char *)v778 + 23),
                                     &v779,
                                     &v777,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v779);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( (unsigned int)sub_10003950(&v779) < 1 )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v779);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v282 = sub_10003950(&v779);
            v120 = (struct MainCapFlowShowDetailClientPaid *)sub_100F5970(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v778 + 22), v120, v282, 3);
            v283 = v777;
            v282 = 530;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v121 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v121, (unsigned int)v280, 0x501u, 0x212u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v779);
            goto LABEL_1064;
          case 26:
            v775 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v776);
            LOBYTE(v925) = 51;
            v774 = 0;
            v283 = 0;
            v282 = (int)&v774;
            v281 = &v776;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v775 + 17),
                                     *((_BYTE *)v775 + 21),
                                     (char *)v775 + 27,
                                     *(_DWORD *)((char *)v775 + 23),
                                     &v776,
                                     &v774,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v776);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( (unsigned int)sub_10003950(&v776) < 1 )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v776);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v282 = sub_10003950(&v776);
            v122 = (struct MainCapFlowShowDetailClientPaid *)sub_100F5970(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v775 + 22), v122, v282, 5);
            v283 = v774;
            v282 = 531;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v123 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v123, (unsigned int)v280, 0x501u, 0x213u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v776);
            goto LABEL_1064;
          case 27:
            v772 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v773);
            LOBYTE(v925) = 52;
            v771 = 0;
            v283 = 0;
            v282 = (int)&v771;
            v281 = &v773;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v772 + 17),
                                     *((_BYTE *)v772 + 21),
                                     (char *)v772 + 27,
                                     *(_DWORD *)((char *)v772 + 23),
                                     &v773,
                                     &v771,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v773);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( (unsigned int)sub_10003950(&v773) < 1 )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v773);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v282 = sub_10003950(&v773);
            v124 = (struct MainCapFlowShowDetailClientPaid *)sub_100F5970(0);
            QDataEngine::AddBKIndexMonyeDetailPaid(*((_BYTE *)v772 + 22), v124, v282, 10);
            v283 = v771;
            v282 = 532;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v125 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v125, (unsigned int)v280, 0x501u, 0x214u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v773);
            goto LABEL_1064;
          case 28:
            v800 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v801);
            LOBYTE(v925) = 45;
            v799 = 0;
            v283 = 0;
            v282 = (int)&v799;
            v281 = &v801;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v800 + 17),
                                     *((_BYTE *)v800 + 21),
                                     (char *)v800 + 30,
                                     *(_DWORD *)((char *)v800 + 26),
                                     &v801,
                                     &v799,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v801);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( jj = 0; ; ++jj )
            {
              v108 = sub_10003950(&v801);
              if ( jj >= v108 )
                break;
              v282 = sub_10003990(jj);
              v281 = (char *)sub_10003990(jj);
              v109 = sub_10003990(jj);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v109 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                3);
            }
            v283 = v799;
            v282 = 533;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v110 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v110, (unsigned int)v280, 0x501u, 0x215u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v801);
            goto LABEL_1064;
          case 29:
            v796 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v797);
            LOBYTE(v925) = 46;
            v795 = 0;
            v283 = 0;
            v282 = (int)&v795;
            v281 = &v797;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v796 + 17),
                                     *((_BYTE *)v796 + 21),
                                     (char *)v796 + 30,
                                     *(_DWORD *)((char *)v796 + 26),
                                     &v797,
                                     &v795,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v797);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( kk = 0; ; ++kk )
            {
              v111 = sub_10003950(&v797);
              if ( kk >= v111 )
                break;
              v282 = sub_10003990(kk);
              v281 = (char *)sub_10003990(kk);
              v112 = sub_10003990(kk);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v112 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                5);
            }
            v283 = v795;
            v282 = 534;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v113 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v113, (unsigned int)v280, 0x501u, 0x216u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v797);
            goto LABEL_1064;
          case 30:
            v792 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v793);
            LOBYTE(v925) = 47;
            v791 = 0;
            v283 = 0;
            v282 = (int)&v791;
            v281 = &v793;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v792 + 17),
                                     *((_BYTE *)v792 + 21),
                                     (char *)v792 + 30,
                                     *(_DWORD *)((char *)v792 + 26),
                                     &v793,
                                     &v791,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v793);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( ll = 0; ; ++ll )
            {
              v114 = sub_10003950(&v793);
              if ( ll >= v114 )
                break;
              v282 = sub_10003990(ll);
              v281 = (char *)sub_10003990(ll);
              v115 = sub_10003990(ll);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v115 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                10);
            }
            v283 = v791;
            v282 = 535;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v116 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v116, (unsigned int)v280, 0x501u, 0x217u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v793);
            goto LABEL_1064;
          case 31:
            v846 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v846 < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v847);
            LOBYTE(v925) = 39;
            v845 = 0;
            v283 = 0;
            v282 = (int)&v845;
            v281 = &v847;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v846 + 17),
                                     *((_BYTE *)v846 + 21),
                                     (char *)v846 + 27,
                                     *(_DWORD *)((char *)v846 + 23),
                                     &v847,
                                     &v845,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v847);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( mm = 0; ; ++mm )
            {
              v83 = sub_10003950(&v847);
              if ( mm >= v83 )
                break;
              v282 = sub_10003990(mm);
              v281 = (char *)sub_10003990(mm);
              v84 = sub_10003990(mm);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v84 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                3);
            }
            v283 = v845;
            v282 = 536;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v85 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v85, (unsigned int)v280, 0x501u, 0x218u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v847);
            goto LABEL_1064;
          case 32:
            v842 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v842 < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v843);
            LOBYTE(v925) = 40;
            v841 = 0;
            v283 = 0;
            v282 = (int)&v841;
            v281 = &v843;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v842 + 17),
                                     *((_BYTE *)v842 + 21),
                                     (char *)v842 + 27,
                                     *(_DWORD *)((char *)v842 + 23),
                                     &v843,
                                     &v841,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v843);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( nn = 0; ; ++nn )
            {
              v86 = sub_10003950(&v843);
              if ( nn >= v86 )
                break;
              v282 = sub_10003990(nn);
              v281 = (char *)sub_10003990(nn);
              v87 = sub_10003990(nn);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v87 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                5);
            }
            v283 = v841;
            v282 = 537;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v88 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v88, (unsigned int)v280, 0x501u, 0x219u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v843);
            goto LABEL_1064;
          case 33:
            v838 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v838 < 1 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            sub_100F5920(&v839);
            LOBYTE(v925) = 41;
            v837 = 0;
            v283 = 0;
            v282 = (int)&v837;
            v281 = &v839;
            if ( !(unsigned __int8)CDataMgr::PreProcMoneyFlowData(
                                     *(_DWORD *)((char *)v838 + 17),
                                     *((_BYTE *)v838 + 21),
                                     (char *)v838 + 27,
                                     *(_DWORD *)((char *)v838 + 23),
                                     &v839,
                                     &v837,
                                     0) )
            {
              LOBYTE(v925) = 1;
              sub_100F5950(&v839);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( i1 = 0; ; ++i1 )
            {
              v89 = sub_10003950(&v839);
              if ( i1 >= v89 )
                break;
              v282 = sub_10003990(i1);
              v281 = (char *)sub_10003990(i1);
              v90 = sub_10003990(i1);
              QDataEngine::Add_MoneyFlowDetailDataStockPaid(
                *(_BYTE *)(v90 + 16),
                v281,
                (struct MainCapFlowShowDetailClientPaid *)v282,
                10);
            }
            v283 = v837;
            v282 = 544;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v921 + 6);
            v91 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v91, (unsigned int)v280, 0x501u, 0x220u, v283);
            LOBYTE(v925) = 1;
            sub_100F5950(&v839);
            goto LABEL_1064;
          case 109:
            v876 = v921;
            mfc80xU_293(&v873);
            LOBYTE(v925) = 27;
            v462 = mfc80xU_762(28);
            if ( v462 )
              v357 = sub_1006A4F0(v462);
            else
              v357 = 0;
            v463 = v357;
            sub_100D75D0(v357);
            LOBYTE(v925) = 28;
            v54 = unknown_libname_100(&v874);
            *(_DWORD *)unknown_libname_96(v54) = 0;
            v55 = unknown_libname_100(&v874);
            *(_DWORD *)(unknown_libname_96(v55) + 4) = 0;
            *(_DWORD *)((char *)v380 + 70) = *((_DWORD *)v876 + 7);
            *(_DWORD *)((char *)v380 + 46) = *(_DWORD *)((char *)v876 + 47);
            if ( *((_BYTE *)v921 + 10) )
            {
              *(_DWORD *)((char *)v380 + 1242) = *((_DWORD *)v876 + 7);
              v875 = 0;
              if ( *((_DWORD *)v876 + 7) == 1
                && !strcmp(QDataEngine::m_LogonInfo, "guest")
                && !strcmp(byte_10479458, "guest") )
              {
                v875 = 1;
              }
              *((_BYTE *)v380 + 496) = *((_BYTE *)v876 + 36) == 1;
              CDataMgr::ClearDataOfApp(v380);
              QDataEngine::InitDHKey((const unsigned __int8 *)v876 + 39, 8);
              v871 = QDataEngine::SetServerInfo((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v876 + 17));
              v872 = sub_1000ED70();
              if ( v871 || *((_BYTE *)v380 + 45) )
              {
                v71 = *((unsigned __int8 *)v380 + 45);
                if ( !*((_BYTE *)v380 + 45) )
                {
                  v856 = 0;
                  CDataMgr::RequestCmd(v380, 0, 1, 1, &v856, 0);
                }
                v283 = v71;
                v459 = &v283;
                v351 = sub_1006A2B0(0);
                sub_102B3660(*(HWND *)((char *)v921 + 6), 0, v283);
              }
              else
              {
                v857 = 0;
                CDataMgr::RequestCmd(v380, 0, 1, 1, &v857, 0);
              }
              QDataEngine::SetCurLoginUserName(QDataEngine::m_LogonInfo);
              mfc80xU_293(&v878);
              LOBYTE(v925) = 36;
              mfc80xU_293(&v869);
              LOBYTE(v925) = 37;
              mfc80xU_2311(&v878, (const char *)L".\\config\\user\\lastuser.ini");
              v870 = QDataEngine::m_LogonInfo;
              if ( QDataEngine::m_LogonInfo )
              {
                v877 = lstrlenA(v870) + 1;
                if ( v877 <= 0x3FFFFFFF )
                {
                  v72 = alloca(2 * v877);
                  v348 = (LPWSTR)&v284;
                  v349 = sub_1000EC40((LPWSTR)&v284, v870, v877, 0);
                }
                else
                {
                  v349 = 0;
                }
                v350 = v349;
              }
              else
              {
                v350 = 0;
              }
              v283 = v350;
              mfc80xU_2311(&v869, (const char *)L"%s", v350);
              v73 = (const WCHAR *)mfc80xU_2461(&v878);
              v74 = ATL::CW2AEX<128>::CW2AEX<128>(v73);
              v347 = v74;
              v75 = (const CHAR *)unknown_libname_100(v74);
              MakeSureDirectoryPathExists(v75);
              ATL::CW2AEX<128>::~CW2AEX<128>(&v458);
              v283 = -1;
              mfc80xU_5398(&v878);
              mfc80xU_870(&v878);
              v76 = (const WCHAR *)mfc80xU_870(&v869);
              WritePrivateProfileStringW(L"config", L"name", v76, (LPCWSTR)v283);
              CDataMgr::WriteUserRightCfgOfFree(v380, v875);
              mfc80xU_2311(&v878, (const char *)L".\\config\\UserOwnerId.ini");
              v283 = *(_DWORD *)((char *)v380 + 41);
              mfc80xU_2311(&v869, (const char *)L"%d", v283);
              v283 = mfc80xU_870(&v878);
              v77 = (const WCHAR *)mfc80xU_870(&v869);
              WritePrivateProfileStringW(L"user", L"buildversion", v77, v284);
              CDataMgr::CopyUserCfgFiles(v380);
              sub_102AD970();
              QDataEngine::SetLoginInStatus(1);
              QDataEngine::SetOnlineStatus(1);
              v284 = 0;
              v283 = 4;
              v78 = CDataMgr::GetReceiverWnd(v380);
              CViewManager::PostBroadcastCommand(v78, v283, v284);
              LOBYTE(v925) = 36;
              mfc80xU_577(&v869);
              LOBYTE(v925) = 28;
              mfc80xU_577(&v878);
              LOBYTE(v925) = 27;
              sub_100D5E60(&v874);
              LOBYTE(v925) = 1;
              mfc80xU_577(&v873);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
            }
            else
            {
              v867 = sub_1000ED70();
              v866 = (char *)v876 + 19;
              if ( v876 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-19 )
              {
                v356 = 0;
              }
              else
              {
                v868 = lstrlenA(v866) + 1;
                if ( v868 <= 0x3FFFFFFF )
                {
                  v56 = alloca(2 * v868);
                  v354 = (LPWSTR)&v284;
                  v355 = sub_1000EC40((LPWSTR)&v284, v866, v868, 0);
                }
                else
                {
                  v355 = 0;
                }
                v356 = v355;
              }
              v283 = v356;
              mfc80xU_2311(&v873, (const char *)L"%s ", v356);
              if ( *((_BYTE *)v380 + 45) )
              {
                CDataMgr::OffLine(v380);
                v57 = unknown_libname_100(&v874);
                *(_DWORD *)(unknown_libname_96(v57) + 4) = 5;
                if ( *(_WORD *)((char *)v921 + 17) == 11 )
                {
                  v283 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(&CDataMgr::LOGON_IN_FORCE_UPDATE);
                  mfc80xU_2311(&v873, (const char *)L"%s", v283);
                  v58 = unknown_libname_100(&v874);
                  *(_DWORD *)(unknown_libname_96(v58) + 4) = 4;
                }
                if ( *(_WORD *)((char *)v921 + 17) == 36 )
                {
                  v59 = unknown_libname_100(&v874);
                  *(_DWORD *)(unknown_libname_96(v59) + 4) = 7;
                }
                v460 = mfc80xU_762(28);
                LOBYTE(v925) = 29;
                if ( v460 )
                  v353 = sub_100F5860(v460);
                else
                  v353 = 0;
                v461 = v353;
                LOBYTE(v925) = 28;
                sub_100D75D0(v353);
                LOBYTE(v925) = 30;
                v283 = mfc80xU_2895(&v873) + 1;
                v60 = unknown_libname_100(&v864);
                unknown_libname_96(v60);
                sub_100F58D0(v283);
                v61 = mfc80xU_2895(&v873);
                v283 = mfc80xU_2460(&v873, v61);
                v62 = unknown_libname_100(&v864);
                unknown_libname_96(v62);
                v63 = (wchar_t *)sub_100F58F0(0);
                wcscpy(v63, (const wchar_t *)v283);
                v64 = unknown_libname_100(&v874);
                unknown_libname_96(v64);
                sub_10119EF0(&v864);
                CGlobalEnv::GetGlobalEnv(&v861);
                LOBYTE(v925) = 31;
                v352 = unknown_libname_100(&v861);
                v65 = unknown_libname_100(&v874);
                v865 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v352 + 36))(v352, v65);
                PostMessageW(*(HWND *)((char *)v921 + 6), 0x501u, 0, v865);
                LightLogger::CLogger::GetLogger(&v862, L"Logon App");
                LOBYTE(v925) = 32;
                mfc80xU_283(&v863, L"(Login Error)post error msg to logondlg,Error msg is:");
                LOBYTE(v925) = 33;
                mfc80xU_896(&v863, &v873);
                v66 = mfc80xU_2461(&v863);
                sub_1000EBE0(&Caption, L"%s", v66);
                mfc80xU_5398(&v863);
                v67 = (LightLogger::CLogger *)unknown_libname_100(&v862);
                LightLogger::CLogger::WriteLogLine(v67, &Caption, 10000);
                LOBYTE(v925) = 32;
                mfc80xU_577(&v863);
                LOBYTE(v925) = 31;
                sub_100D5E60(&v862);
                LOBYTE(v925) = 30;
                sub_100D5E60(&v861);
                LOBYTE(v925) = 28;
                sub_100D5E60(&v864);
              }
              else if ( *(_WORD *)((char *)v876 + 17) == 36 )
              {
                CDataMgr::OffLine(v380);
                Sleep(0x1388u);
                if ( QDataEngine::m_bIsLoginPass )
                {
                  memset(&v859, 0, 0x400u);
                  sub_10103690(&v859, QDataEngine::m_szPassData);
                  CDataMgr::LogonFromPass(
                    v380,
                    0,
                    QDataEngine::m_LogonInfo,
                    byte_10479458,
                    QDataEngine::m_nPassDataLen,
                    &v859,
                    dword_10479558,
                    (struct _PROXY_SERADDR_TAG_ *)&unk_10479578);
                }
                else
                {
                  CDataMgr::Logon(
                    v380,
                    0,
                    QDataEngine::m_LogonInfo,
                    byte_10479458,
                    dword_10479558,
                    (struct _PROXY_SERADDR_TAG_ *)&unk_10479578);
                }
                LightLogger::CLogger::GetLogger(&v860, L"Logon App");
                LOBYTE(v925) = 34;
                sub_1000EBE0(&Caption, L"(Login Error)post errorid =36", (char)v284);
                v68 = (LightLogger::CLogger *)unknown_libname_100(&v860);
                LightLogger::CLogger::WriteLogLine(v68, &Caption, 10000);
                LOBYTE(v925) = 28;
                sub_100D5E60(&v860);
              }
              else
              {
                CDataMgr::OffLine(v380);
                v282 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(&CDataMgr::AUTO_CONNECT_LOGON_ERROR_TITTLE);
                v283 = mfc80xU_870(&v873);
                v69 = unknown_libname_100(&v923);
                MessageBoxW(*(HWND *)(v69 + 156), (LPCWSTR)v283, v284, v285);
                CDataMgr::ShowLogonDlg(v380);
                LightLogger::CLogger::GetLogger(&v858, L"Logon App");
                LOBYTE(v925) = 35;
                sub_1000EBE0(&Caption, L"(Login Error)pop logonDlg", v286);
                v285 = 10000;
                v284 = &Caption;
                v70 = (LightLogger::CLogger *)unknown_libname_100(&v858);
                LightLogger::CLogger::WriteLogLine(v70, v284, v285);
                LOBYTE(v925) = 28;
                sub_100D5E60(&v858);
              }
              LOBYTE(v925) = 27;
              sub_100D5E60(&v874);
              LOBYTE(v925) = 1;
              mfc80xU_577(&v873);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
            }
            return;
          case 110:
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v918 = v921;
            CGlobalEnv::GetGlobalEnv(&v915);
            LOBYTE(v925) = 2;
            v473 = mfc80xU_762(28);
            if ( v473 )
              v377 = sub_1006A4F0(v473);
            else
              v377 = 0;
            v474 = v377;
            sub_100D75D0(v377);
            LOBYTE(v925) = 3;
            v471 = mfc80xU_762(16);
            if ( v471 )
              v376 = sub_100F5550(v471);
            else
              v376 = 0;
            v472 = v376;
            sub_100D75D0(v376);
            LOBYTE(v925) = 4;
            v8 = unknown_libname_100(&v917);
            *(_DWORD *)unknown_libname_96(v8) = 127;
            v9 = unknown_libname_100(&v917);
            *(_DWORD *)(unknown_libname_96(v9) + 4) = 0;
            if ( *((_BYTE *)v921 + 10) )
            {
              *(_DWORD *)((char *)v380 + 58) = *(_DWORD *)((char *)v918 + 47);
              QDataEngine::SetTrendLoginInStatus(1);
              *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 3) = 1;
              v13 = unknown_libname_100(&v914);
              *(_BYTE *)unknown_libname_96(v13) = 1;
            }
            else
            {
              mfc80xU_293(&v911);
              LOBYTE(v925) = 5;
              v910 = sub_1000ED70();
              lpString = (char *)v918 + 19;
              if ( v918 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-19 )
              {
                v375 = 0;
              }
              else
              {
                cchWideChar = lstrlenA(lpString) + 1;
                if ( cchWideChar <= 0x3FFFFFFF )
                {
                  v10 = alloca(2 * cchWideChar);
                  lpWideCharStr = (LPWSTR)&v284;
                  v374 = sub_1000EC40((LPWSTR)&v284, lpString, cchWideChar, 0);
                }
                else
                {
                  v374 = 0;
                }
                v375 = v374;
              }
              ((void (__cdecl *)(int *, const wchar_t *, int, WCHAR *, UINT))mfc80xU_2311)(
                &v911,
                L"trend server logon failed: %s ",
                v375,
                v284,
                v285);
              LightLogger::CLogger::GetLogger(&v913, L"logon on");
              LOBYTE(v925) = 6;
              wsprintfW(&Caption, L"logon fail %s", v911);
              v11 = (LightLogger::CLogger *)unknown_libname_100(&v913);
              LightLogger::CLogger::WriteLogLine(v11, &Caption, 20000);
              v12 = unknown_libname_100(&v914);
              *(_BYTE *)unknown_libname_96(v12) = 0;
              LOBYTE(v925) = 5;
              sub_100D5E60(&v913);
              LOBYTE(v925) = 4;
              mfc80xU_577(&v911);
            }
            v14 = unknown_libname_100(&v917);
            unknown_libname_96(v14);
            sub_10119EF0(&v914);
            v372 = unknown_libname_100(&v915);
            v15 = unknown_libname_100(&v917);
            v916 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v372 + 36))(v372, v15);
            if ( *(_DWORD *)((char *)v921 + 6) )
              QDataEngine::SendMsgDataToUI(*(HWND *)((char *)v921 + 6), v916, 0x7Fu);
            LOBYTE(v925) = 3;
            sub_100D5E60(&v914);
            LOBYTE(v925) = 2;
            sub_100D5E60(&v917);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v915);
            goto LABEL_1064;
          case 115:
            CDataMgr::ProcAllStkDictList(v380, v921);
            goto LABEL_1064;
          case 116:
            CDataMgr::ProcStkOptionQuoteTable(v380, v921, *((signed __int16 *)v921 + 2));
            goto LABEL_1064;
          case 117:
            CDataMgr::ProcBufferListData(v380, v921);
            goto LABEL_1064;
          case 118:
          case 131:
            v712 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::UpdatePushFavQuoteTable(v380, v712);
            goto LABEL_1064;
          case 119:
            v713 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::UpdatePushQuoteTableNew(v380, v713);
            goto LABEL_1064;
          case 120:
            v787 = v921;
            sub_100F59A0(&v786);
            LOBYTE(v925) = 48;
            v283 = (int)&v786;
            if ( !(unsigned __int8)CDataMgr::PreProcBkData(
                                     *(_DWORD *)((char *)v787 + 17),
                                     *((_BYTE *)v787 + 21),
                                     (char *)v787 + 27,
                                     *(_DWORD *)((char *)v787 + 23),
                                     &v786) )
            {
              LOBYTE(v925) = 1;
              sub_100F59D0(&v786);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 314));
            CDataMgr::SendMsgToUIs((int)v380 + 740, 0x709u);
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 314));
            LOBYTE(v925) = 1;
            sub_100F59D0(&v786);
            goto LABEL_1064;
          case 122:
            v711 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( CDataMgr::AddFavBkData(
                   v380,
                   *(_DWORD *)((char *)v711 + 17),
                   *((_BYTE *)v711 + 21),
                   (char *)v711 + 26,
                   *(_DWORD *)((char *)v711 + 22),
                   *(HWND *)((char *)v711 + 6),
                   *(_DWORD *)((char *)v711 + 13)) )
            {
              goto LABEL_1064;
            }
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          case 123:
            CDataMgr::ProcPushOptionQuote(v380, v921);
            goto LABEL_1064;
          case 126:
            goto LABEL_488;
          case 129:
            CDataMgr::ProcBkStkQuoteTable(v380, v921, *((signed __int16 *)v921 + 2));
            goto LABEL_1064;
          case 132:
            v517 = v921;
            v386 = mfc80xU_762(44);
            if ( v386 )
              v293 = sub_100F5B50(v386);
            else
              v293 = 0;
            v387 = v293;
            sub_100D75D0(v293);
            LOBYTE(v925) = 98;
            if ( !unknown_libname_100(&v515) )
            {
              LOBYTE(v925) = 1;
              sub_100D5E60(&v515);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v516 = QDataEngine::App_OneStkInfo((const char *)v517 + 18, *((_BYTE *)v517 + 17));
            if ( v516 )
            {
              if ( !*(_DWORD *)((char *)v516 + 81) )
              {
                sub_10387DA0();
                sub_10388A80(0, v516);
              }
              if ( *(_DWORD *)((char *)v516 + 81) )
              {
                *(float *)(*(_DWORD *)((char *)v516 + 81) + 37) = *(float *)((char *)v517 + 38);
                *(float *)(*(_DWORD *)((char *)v516 + 81) + 41) = *(float *)((char *)v517 + 42);
              }
            }
            v258 = unknown_libname_100(&v515);
            v259 = (_BYTE *)unknown_libname_96(v258);
            *v259 = *((_BYTE *)v517 + 17);
            v282 = (int)v517 + 18;
            v260 = unknown_libname_100(&v515);
            v261 = unknown_libname_96(v260);
            sub_100CB310((char *)(v261 + 1), (char *)v282, 0x10u);
            v262 = unknown_libname_100(&v515);
            v263 = unknown_libname_96(v262);
            *(_DWORD *)(v263 + 17) = *(_DWORD *)((char *)v517 + 34);
            v264 = unknown_libname_100(&v515);
            v265 = unknown_libname_96(v264);
            *(float *)(v265 + 25) = *(float *)((char *)v517 + 42);
            v266 = unknown_libname_100(&v515);
            v267 = unknown_libname_96(v266);
            *(float *)(v267 + 21) = *(float *)((char *)v517 + 38);
            v268 = unknown_libname_100(&v515);
            v283 = v269;
            v385 = &v283;
            v292 = sub_100D75D0(v268);
            sub_102B3660(*(HWND *)((char *)v517 + 6), 0x69u, v283);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v515);
            goto LABEL_1064;
          case 133:
            v514 = v921;
            v513 = 0;
            if ( !v921 || *(_DWORD *)((char *)v514 + 49) < 1 )
              QDataEngine::PostBroadcastCommand(0x88u, 0);
            sub_100F4000(&v508);
            sub_10001790((char *)v380 + 1186);
            sub_10049920((char *)v380 + 1226);
            for ( i2 = 0; i2 < *(_DWORD *)((char *)v514 + 49); ++i2 )
            {
              v509 = *(_DWORD *)((char *)v514 + 22 * i2 + 54);
              v510 = *(_DWORD *)((char *)v514 + 22 * i2 + 58);
              v508 = *((_BYTE *)v514 + 22 * i2 + 53) == 1;
              v511 = *(_DWORD *)((char *)v514 + 22 * i2 + 67);
              v512 = *(_DWORD *)((char *)v514 + 22 * i2 + 71);
              if ( v512 == 1000 )
                v513 = 1;
              if ( v512 == 1000 && v508 == 1 )
              {
                v506 = QDataEngine::GetSeverUserID();
                if ( v506 & 1 )
                {
                  v512 = 1000;
                  v508 = 0;
                }
              }
              sub_100F5410(&v508);
            }
            if ( !v513 )
            {
              sub_100F4000(&v503);
              v505 = QDataEngine::GetSeverUserID();
              if ( v505 & 1 )
              {
                v504 = 1000;
                v503 = 0;
              }
              sub_100F5410(&v503);
            }
            (*(void (__thiscall **)(char *))(*(_DWORD *)((char *)v380 + 1186) + 28))((char *)v380 + 1186);
            QDataEngine::PostBroadcastCommand(0x88u, 0);
            goto LABEL_1064;
          case 135:
            v770 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            for ( i3 = 0; i3 < *((char *)v770 + 17); ++i3 )
              sub_10105700(0, (int)v770 + 210 * i3 + 18, 0);
            goto LABEL_1064;
          case 136:
            v905 = v921;
            mfc80xU_293(&v901);
            LOBYTE(v925) = 7;
            v469 = mfc80xU_762(28);
            if ( v469 )
              v371 = sub_1006A4F0(v469);
            else
              v371 = 0;
            v470 = v371;
            sub_100D75D0(v371);
            LOBYTE(v925) = 8;
            v16 = unknown_libname_100(&v904);
            *(_DWORD *)unknown_libname_96(v16) = 0;
            v17 = unknown_libname_100(&v904);
            *(_DWORD *)(unknown_libname_96(v17) + 4) = 0;
            *(_DWORD *)((char *)v380 + 70) = *((_DWORD *)v905 + 7);
            *(_DWORD *)((char *)v380 + 46) = *(_DWORD *)((char *)v905 + 47);
            v900 = sub_1000ED70();
            mfc80xU_293(&v902);
            LOBYTE(v925) = 9;
            LightLogger::CLogger::GetLogger(&v903, L"Logon App");
            LOBYTE(v925) = 10;
            ((void (__cdecl *)(char *, const wchar_t *, _DWORD, _DWORD, WCHAR *))mfc80xU_2311)(
              &v902,
              L"rec 738.tp->bResult=%d, m_bLoginUI=%d",
              *((char *)v921 + 10),
              *((unsigned __int8 *)v380 + 45),
              v284);
            v283 = mfc80xU_870(&v902);
            v18 = (LightLogger::CLogger *)unknown_libname_100(&v903);
            LightLogger::CLogger::WriteLogLine(v18, (const wchar_t *)v283, v284);
            if ( *((_BYTE *)v921 + 10) )
            {
              LightLogger::CLogger::GetLogger(&v887, L"Logon App");
              LOBYTE(v925) = 19;
              sub_1000EBE0(&Caption, L"(Login Info)VerifyUserLogon", (char)v284);
              v36 = (LightLogger::CLogger *)unknown_libname_100(&v887);
              LightLogger::CLogger::WriteLogLine(v36, &Caption, 10000);
              sub_1000EBE0(&Caption, L"(Login Info)user type=%d", *((_BYTE *)v905 + 109));
              v37 = (LightLogger::CLogger *)unknown_libname_100(&v887);
              LightLogger::CLogger::WriteLogLine(v37, &Caption, 10000);
              *(_DWORD *)((char *)v380 + 1250) = *(_DWORD *)((char *)v921 + 6);
              v365 = QDataEngine::GetAppCurVersionType();
              switch ( v365 )
              {
                case 0:
                  if ( !CDataMgr::VerifyLevel2UserLogon(
                          v380,
                          *((unsigned __int8 *)v905 + 109),
                          *(HWND *)((char *)v921 + 6)) )
                    goto LABEL_127;
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v887);
                  LOBYTE(v925) = 9;
                  sub_100D5E60(&v903);
                  LOBYTE(v925) = 8;
                  mfc80xU_577(&v902);
                  LOBYTE(v925) = 7;
                  sub_100D5E60(&v904);
                  LOBYTE(v925) = 1;
                  mfc80xU_577(&v901);
                  LOBYTE(v925) = 0;
                  sub_100D5E60(&v923);
                  v925 = -1;
                  sub_100D5E60(&v924);
                  break;
                case 1:
                  if ( !CDataMgr::VerifyUserLogon(v380, *((_BYTE *)v905 + 109)) )
                  {
                    if ( *((_BYTE *)v905 + 109) == 1 )
                    {
                      *((_BYTE *)v380 + 496) = (signed int)*((unsigned __int8 *)v905 + 36) < 1;
                    }
                    else if ( *((_BYTE *)v905 + 109) == 2 )
                    {
                      *((_BYTE *)v380 + 496) = (signed int)*((unsigned __int8 *)v905 + 36) < 2;
                    }
                    goto LABEL_127;
                  }
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v887);
                  LOBYTE(v925) = 9;
                  sub_100D5E60(&v903);
                  LOBYTE(v925) = 8;
                  mfc80xU_577(&v902);
                  LOBYTE(v925) = 7;
                  sub_100D5E60(&v904);
                  LOBYTE(v925) = 1;
                  mfc80xU_577(&v901);
                  LOBYTE(v925) = 0;
                  sub_100D5E60(&v923);
                  v925 = -1;
                  sub_100D5E60(&v924);
                  break;
                case 3:
                  if ( !CDataMgr::VerifyMasterUserLogon(v380, *((_BYTE *)v905 + 109)) )
                  {
                    if ( *((_BYTE *)v905 + 109) == 1 )
                      *((_BYTE *)v380 + 496) = (signed int)*((unsigned __int8 *)v905 + 36) < 1;
                    goto LABEL_127;
                  }
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v887);
                  LOBYTE(v925) = 9;
                  sub_100D5E60(&v903);
                  LOBYTE(v925) = 8;
                  mfc80xU_577(&v902);
                  LOBYTE(v925) = 7;
                  sub_100D5E60(&v904);
                  LOBYTE(v925) = 1;
                  mfc80xU_577(&v901);
                  LOBYTE(v925) = 0;
                  sub_100D5E60(&v923);
                  v925 = -1;
                  sub_100D5E60(&v924);
                  break;
                case 4:
                  if ( !CDataMgr::VerifyLevel2UserLogon(v380, *((unsigned __int8 *)v905 + 109), 0) )
                    goto LABEL_127;
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v887);
                  LOBYTE(v925) = 9;
                  sub_100D5E60(&v903);
                  LOBYTE(v925) = 8;
                  mfc80xU_577(&v902);
                  LOBYTE(v925) = 7;
                  sub_100D5E60(&v904);
                  LOBYTE(v925) = 1;
                  mfc80xU_577(&v901);
                  LOBYTE(v925) = 0;
                  sub_100D5E60(&v923);
                  v925 = -1;
                  sub_100D5E60(&v924);
                  break;
                case 5:
                  if ( !CDataMgr::VerifyL1ProUserLogin(v380, *((_BYTE *)v905 + 109)) )
                    goto LABEL_127;
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v887);
                  LOBYTE(v925) = 9;
                  sub_100D5E60(&v903);
                  LOBYTE(v925) = 8;
                  mfc80xU_577(&v902);
                  LOBYTE(v925) = 7;
                  sub_100D5E60(&v904);
                  LOBYTE(v925) = 1;
                  mfc80xU_577(&v901);
                  LOBYTE(v925) = 0;
                  sub_100D5E60(&v923);
                  v925 = -1;
                  sub_100D5E60(&v924);
                  break;
                case 6:
                  if ( *((_BYTE *)v905 + 109) == 1 || *((_BYTE *)v905 + 109) == 2 )
                  {
                    if ( !CDataMgr::VerifyHighEndUserLogon(v380, *((_BYTE *)v905 + 109)) )
                    {
LABEL_127:
                      LOBYTE(v925) = 10;
                      sub_100D5E60(&v887);
                      *(_DWORD *)((char *)v380 + 1242) = *((_DWORD *)v905 + 7);
                      QDataEngine::m_nCurUserLoginRight = *((unsigned __int8 *)v905 + 109);
                      CDataMgr::ClearDataOfApp(v380);
                      QDataEngine::InitDHKey((const unsigned __int8 *)v905 + 39, 8);
                      v899 = QDataEngine::SetServerInfo((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v905 + 17));
                      if ( v899 || *((_BYTE *)v380 + 45) )
                      {
                        if ( !*((_BYTE *)v380 + 45) )
                        {
                          v879 = 0;
                          CDataMgr::RequestCmd(v380, 0, 1, 1, &v879, 0);
                        }
                        CGlobalEnv::GetGlobalEnv(&v881);
                        LOBYTE(v925) = 23;
                        v45 = unknown_libname_100(&v904);
                        *(_DWORD *)(unknown_libname_96(v45) + 4) = 0;
                        v362 = unknown_libname_100(&v881);
                        v46 = unknown_libname_100(&v904);
                        v880 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v362 + 36))(v362, v46);
                        PostMessageW(*(HWND *)((char *)v921 + 6), 0x501u, 0, v880);
                        LightLogger::CLogger::GetLogger(&v882, L"Logon App");
                        LOBYTE(v925) = 24;
                        sub_1000EBE0(&Caption, L"(Login Info)post logon success msg to logondlg", (char)v284);
                        v47 = (LightLogger::CLogger *)unknown_libname_100(&v882);
                        LightLogger::CLogger::WriteLogLine(v47, &Caption, 10000);
                        LOBYTE(v925) = 23;
                        sub_100D5E60(&v882);
                        LOBYTE(v925) = 10;
                        sub_100D5E60(&v881);
                      }
                      else
                      {
                        v883 = 0;
                        CDataMgr::RequestCmd(v380, 0, 1, 1, &v883, 0);
                      }
                      QDataEngine::SetCurLoginUserName(QDataEngine::m_LogonInfo);
                      mfc80xU_293(&v907);
                      LOBYTE(v925) = 25;
                      mfc80xU_293(&v897);
                      LOBYTE(v925) = 26;
                      mfc80xU_2311(&v907, (const char *)L".\\config\\user\\lastuser.ini");
                      lpMultiByteStr = QDataEngine::m_LogonInfo;
                      if ( QDataEngine::m_LogonInfo )
                      {
                        v906 = lstrlenA(lpMultiByteStr) + 1;
                        if ( v906 <= 0x3FFFFFFF )
                        {
                          v48 = alloca(2 * v906);
                          v359 = (LPWSTR)&v284;
                          v360 = sub_1000EC40((LPWSTR)&v284, lpMultiByteStr, v906, 0);
                        }
                        else
                        {
                          v360 = 0;
                        }
                        v361 = v360;
                      }
                      else
                      {
                        v361 = 0;
                      }
                      mfc80xU_2311(&v897, (const char *)L"%s", v361);
                      v49 = (const WCHAR *)mfc80xU_2461(&v907);
                      v50 = ATL::CW2AEX<128>::CW2AEX<128>(v49);
                      v358 = v50;
                      v51 = (const CHAR *)unknown_libname_100(v50);
                      MakeSureDirectoryPathExists(v51);
                      ATL::CW2AEX<128>::~CW2AEX<128>(&v464);
                      mfc80xU_5398(&v907);
                      mfc80xU_870(&v907);
                      v52 = (const WCHAR *)mfc80xU_870(&v897);
                      WritePrivateProfileStringW(L"config", L"name", v52, (LPCWSTR)0xFFFFFFFF);
                      *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 14) = *((_BYTE *)v905 + 109) == 1
                                                                     && *((_DWORD *)v905 + 7) != 100
                                                                     && QDataEngine::GetAppCurVersionType() == 1;
                      mfc80xU_2311(&v907, (const char *)L".\\config\\UserOwnerId.ini");
                      mfc80xU_2311(&v897, (const char *)L"%d", *(_DWORD *)((char *)v380 + 41));
                      v283 = mfc80xU_870(&v907);
                      v53 = (const WCHAR *)mfc80xU_870(&v897);
                      WritePrivateProfileStringW(L"user", L"buildversion", v53, (LPCWSTR)v283);
                      CDataMgr::CopyUserCfgFiles(v380);
                      sub_102AD970();
                      if ( *((_BYTE *)v905 + 109) == 1 )
                        *(_DWORD *)((char *)v380 + 1058) = *((_DWORD *)v905 + 7);
                      else
                        *(_DWORD *)((char *)v380 + 1058) = 0;
                      QDataEngine::SetLoginInStatus(1);
                      QDataEngine::SetOnlineStatus(1);
                      QDataEngine::PostBroadcastCommand(4u, 0);
                      LOBYTE(v925) = 25;
                      mfc80xU_577(&v897);
                      LOBYTE(v925) = 10;
                      mfc80xU_577(&v907);
                      LOBYTE(v925) = 9;
                      sub_100D5E60(&v903);
                      LOBYTE(v925) = 8;
                      mfc80xU_577(&v902);
                      LOBYTE(v925) = 7;
                      sub_100D5E60(&v904);
                      LOBYTE(v925) = 1;
                      mfc80xU_577(&v901);
                      goto LABEL_1064;
                    }
                    LOBYTE(v925) = 10;
                    sub_100D5E60(&v887);
                    LOBYTE(v925) = 9;
                    sub_100D5E60(&v903);
                    LOBYTE(v925) = 8;
                    mfc80xU_577(&v902);
                    LOBYTE(v925) = 7;
                    sub_100D5E60(&v904);
                    LOBYTE(v925) = 1;
                    mfc80xU_577(&v901);
                    LOBYTE(v925) = 0;
                    sub_100D5E60(&v923);
                    v925 = -1;
                    sub_100D5E60(&v924);
                  }
                  else
                  {
                    CDataMgr::OffLine(v380);
                    if ( *((_BYTE *)v380 + 45) )
                    {
                      v38 = unknown_libname_100(&v904);
                      *(_DWORD *)(unknown_libname_96(v38) + 4) = 5;
                      mfc80xU_776(&v901, &unk_103D5BE8);
                      v465 = mfc80xU_762(28);
                      LOBYTE(v925) = 20;
                      if ( v465 )
                        v364 = sub_100F5860(v465);
                      else
                        v364 = 0;
                      v466 = v364;
                      LOBYTE(v925) = 19;
                      sub_100D75D0(v364);
                      LOBYTE(v925) = 21;
                      v283 = mfc80xU_2895(&v901) + 1;
                      v39 = unknown_libname_100(&v885);
                      unknown_libname_96(v39);
                      sub_100F58D0(v283);
                      v40 = mfc80xU_2895(&v901);
                      v283 = mfc80xU_2460(&v901, v40);
                      v41 = unknown_libname_100(&v885);
                      unknown_libname_96(v41);
                      v42 = (wchar_t *)sub_100F58F0(0);
                      wcscpy(v42, (const wchar_t *)v283);
                      v43 = unknown_libname_100(&v904);
                      unknown_libname_96(v43);
                      sub_10119EF0(&v885);
                      CGlobalEnv::GetGlobalEnv(&v884);
                      LOBYTE(v925) = 22;
                      v363 = unknown_libname_100(&v884);
                      v44 = unknown_libname_100(&v904);
                      v886 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v363 + 36))(v363, v44);
                      PostMessageW(*(HWND *)((char *)v921 + 6), 0x501u, 0, v886);
                      LOBYTE(v925) = 21;
                      sub_100D5E60(&v884);
                      LOBYTE(v925) = 19;
                      sub_100D5E60(&v885);
                    }
                    LOBYTE(v925) = 10;
                    sub_100D5E60(&v887);
                    LOBYTE(v925) = 9;
                    sub_100D5E60(&v903);
                    LOBYTE(v925) = 8;
                    mfc80xU_577(&v902);
                    LOBYTE(v925) = 7;
                    sub_100D5E60(&v904);
                    LOBYTE(v925) = 1;
                    mfc80xU_577(&v901);
                    LOBYTE(v925) = 0;
                    sub_100D5E60(&v923);
                    v925 = -1;
                    sub_100D5E60(&v924);
                  }
                  break;
                default:
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v887);
                  LOBYTE(v925) = 9;
                  sub_100D5E60(&v903);
                  LOBYTE(v925) = 8;
                  mfc80xU_577(&v902);
                  LOBYTE(v925) = 7;
                  sub_100D5E60(&v904);
                  LOBYTE(v925) = 1;
                  mfc80xU_577(&v901);
                  LOBYTE(v925) = 0;
                  sub_100D5E60(&v923);
                  v925 = -1;
                  sub_100D5E60(&v924);
                  break;
              }
            }
            else
            {
              lpMultiByteStr = (char *)v905 + 19;
              if ( v905 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-19 )
              {
                v370 = 0;
              }
              else
              {
                v906 = lstrlenA(lpMultiByteStr) + 1;
                if ( v906 <= 0x3FFFFFFF )
                {
                  v19 = alloca(2 * v906);
                  v368 = (LPWSTR)&v284;
                  v369 = sub_1000EC40((LPWSTR)&v284, lpMultiByteStr, v906, 0);
                }
                else
                {
                  v369 = 0;
                }
                v370 = v369;
              }
              mfc80xU_2311(&v901, (const char *)L"%s ", v370, v284, v285);
              if ( *((_BYTE *)v380 + 45) )
              {
                CDataMgr::OffLine(v380);
                v20 = unknown_libname_100(&v904);
                *(_DWORD *)(unknown_libname_96(v20) + 4) = 5;
                if ( *(_WORD *)((char *)v921 + 17) == 11 )
                {
                  v283 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(&CDataMgr::LOGON_IN_FORCE_UPDATE);
                  mfc80xU_2311(&v901, (const char *)L"%s", v283);
                  v21 = unknown_libname_100(&v904);
                  *(_DWORD *)(unknown_libname_96(v21) + 4) = 4;
                }
                if ( *(_WORD *)((char *)v921 + 17) == 36 )
                {
                  v22 = unknown_libname_100(&v904);
                  *(_DWORD *)(unknown_libname_96(v22) + 4) = 7;
                }
                v467 = mfc80xU_762(28);
                LOBYTE(v925) = 11;
                if ( v467 )
                  v367 = sub_100F5860(v467);
                else
                  v367 = 0;
                v468 = v367;
                LOBYTE(v925) = 10;
                sub_100D75D0(v367);
                LOBYTE(v925) = 12;
                v283 = mfc80xU_2895(&v901) + 1;
                v23 = unknown_libname_100(&v894);
                unknown_libname_96(v23);
                sub_100F58D0(v283);
                v24 = mfc80xU_2895(&v901);
                v283 = mfc80xU_2460(&v901, v24);
                v25 = unknown_libname_100(&v894);
                unknown_libname_96(v25);
                v26 = (wchar_t *)sub_100F58F0(0);
                wcscpy(v26, (const wchar_t *)v283);
                v27 = unknown_libname_100(&v904);
                unknown_libname_96(v27);
                sub_10119EF0(&v894);
                CGlobalEnv::GetGlobalEnv(&v891);
                LOBYTE(v925) = 13;
                v366 = unknown_libname_100(&v891);
                v28 = unknown_libname_100(&v904);
                lParam = (*(int (__thiscall **)(int, int))(*(_DWORD *)v366 + 36))(v366, v28);
                PostMessageW(*(HWND *)((char *)v921 + 6), 0x501u, 0, lParam);
                LightLogger::CLogger::GetLogger(&v892, L"Logon App");
                LOBYTE(v925) = 14;
                mfc80xU_283(&v893, L"(Login Error)post error msg to logondlg,Error msg is:");
                LOBYTE(v925) = 15;
                mfc80xU_896(&v893, &v901);
                v29 = mfc80xU_2461(&v893);
                sub_1000EBE0(&Caption, L"%s", v29);
                mfc80xU_5398(&v893);
                v30 = (LightLogger::CLogger *)unknown_libname_100(&v892);
                LightLogger::CLogger::WriteLogLine(v30, &Caption, 10000);
                LOBYTE(v925) = 14;
                mfc80xU_577(&v893);
                LOBYTE(v925) = 13;
                sub_100D5E60(&v892);
                LOBYTE(v925) = 12;
                sub_100D5E60(&v891);
                LOBYTE(v925) = 10;
                sub_100D5E60(&v894);
              }
              else
              {
                v283 = QDataEngine::m_bIsLoginPass;
                v282 = *(signed __int16 *)((char *)v905 + 17);
                mfc80xU_2311(
                  &v902,
                  (const char *)L"rec 738. response)->body.nErrorId=%d, QDataEngine::m_bIsLoginPass=%d",
                  v282,
                  QDataEngine::m_bIsLoginPass);
                v283 = mfc80xU_870(&v902);
                v31 = (LightLogger::CLogger *)unknown_libname_100(&v903);
                LightLogger::CLogger::WriteLogLine(v31, (const wchar_t *)v283, v284);
                if ( *(_WORD *)((char *)v905 + 17) == 36 )
                {
                  CDataMgr::OffLine(v380);
                  Sleep(0x1388u);
                  if ( QDataEngine::m_bIsLoginPass )
                  {
                    memset(&Src, 0, 0x400u);
                    sub_10103690(&Src, QDataEngine::m_szPassData);
                    CDataMgr::LogonFromPass(
                      v380,
                      0,
                      QDataEngine::m_LogonInfo,
                      byte_10479458,
                      QDataEngine::m_nPassDataLen,
                      &Src,
                      dword_10479558,
                      (struct _PROXY_SERADDR_TAG_ *)&unk_10479578);
                  }
                  else
                  {
                    CDataMgr::Logon(
                      v380,
                      0,
                      QDataEngine::m_LogonInfo,
                      byte_10479458,
                      dword_10479558,
                      (struct _PROXY_SERADDR_TAG_ *)&unk_10479578);
                  }
                  LightLogger::CLogger::GetLogger(&v890, L"Logon App");
                  LOBYTE(v925) = 16;
                  sub_1000EBE0(&Caption, L"(Login Error)post errorid =36", (char)v284);
                  v32 = (LightLogger::CLogger *)unknown_libname_100(&v890);
                  LightLogger::CLogger::WriteLogLine(v32, &Caption, 10000);
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v890);
                }
                else
                {
                  CDataMgr::OffLine(v380);
                  LightLogger::CLogger::GetLogger(&v888, L"Logon App");
                  LOBYTE(v925) = 17;
                  sub_1000EBE0(&Caption, L"(Login Error)pop logonDlg", (char)v284);
                  v33 = (LightLogger::CLogger *)unknown_libname_100(&v888);
                  LightLogger::CLogger::WriteLogLine(v33, &Caption, 10000);
                  v280 = (int *)std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::c_str(&CDataMgr::AUTO_CONNECT_LOGON_ERROR_TITTLE);
                  v281 = (char *)mfc80xU_870(&v901);
                  v34 = unknown_libname_100(&v923);
                  MessageBoxW(*(HWND *)(v34 + 156), (LPCWSTR)v281, (LPCWSTR)v282, v283);
                  CDataMgr::ShowLogonDlg(v380);
                  LOBYTE(v925) = 10;
                  sub_100D5E60(&v888);
                }
              }
              LightLogger::CLogger::GetLogger(&v896, L"Logon App");
              LOBYTE(v925) = 18;
              sub_1000EBE0(&Caption, L"(Login Error)errorId:%d", *(_WORD *)((char *)v905 + 17));
              v35 = (LightLogger::CLogger *)unknown_libname_100(&v896);
              LightLogger::CLogger::WriteLogLine(v35, &Caption, 10000);
              LOBYTE(v925) = 10;
              sub_100D5E60(&v896);
              LOBYTE(v925) = 9;
              sub_100D5E60(&v903);
              LOBYTE(v925) = 8;
              mfc80xU_577(&v902);
              LOBYTE(v925) = 7;
              sub_100D5E60(&v904);
              LOBYTE(v925) = 1;
              mfc80xU_577(&v901);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
            }
            return;
          case 139:
          case 145:
            v502 = v921;
            v383 = mfc80xU_762(32);
            LOBYTE(v925) = 99;
            if ( v383 )
              v291 = sub_100F5B70(v383);
            else
              v291 = 0;
            v384 = v291;
            LOBYTE(v925) = 1;
            sub_100D75D0(v291);
            LOBYTE(v925) = 100;
            if ( !unknown_libname_100(&v490) )
            {
              LOBYTE(v925) = 1;
              sub_100D5E60(&v490);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v270 = unknown_libname_100(&v490);
            v271 = (_DWORD *)unknown_libname_96(v270);
            *v271 = *(_DWORD *)((char *)v502 + 17);
            v501 = *(_DWORD *)((char *)v502 + 21);
            for ( i4 = 0; i4 < v501; ++i4 )
            {
              v491 = *(_DWORD *)((char *)v502 + 46 * i4 + 25);
              v492 = *(_DWORD *)((char *)v502 + 46 * i4 + 29);
              v493 = *(_DWORD *)((char *)v502 + 46 * i4 + 33);
              v494 = *(_DWORD *)((char *)v502 + 46 * i4 + 37);
              v495 = *(_DWORD *)((char *)v502 + 46 * i4 + 41);
              v496 = *(_DWORD *)((char *)v502 + 46 * i4 + 45);
              v497 = *(_DWORD *)((char *)v502 + 46 * i4 + 49);
              v498 = *(_DWORD *)((char *)v502 + 46 * i4 + 53);
              v499 = *(_DWORD *)((char *)v502 + 46 * i4 + 57);
              v500 = *(_WORD *)((char *)v502 + 46 * i4 + 61);
              v272 = unknown_libname_100(&v490);
              unknown_libname_96(v272);
              sub_100F4C50(&v491);
            }
            v273 = unknown_libname_100(&v490);
            v283 = v274;
            v382 = &v283;
            v290 = sub_100D75D0(v273);
            sub_102B3660(*(HWND *)((char *)v502 + 6), *((_WORD *)v921 + 2) != 747 ? 115 : 130, v283);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v490);
            goto LABEL_1064;
          case 151:
            goto LABEL_1029;
          case 175:
            if ( v921 )
            {
              v481 = v921;
              if ( *(signed __int16 *)((char *)v921 + 17) > 0 )
              {
                v479 = 0;
                v480 = QDataEngine::GetSeverUserID();
                sub_10001790((char *)v380 + 1186);
                v482 = sub_100CCCB0((char *)v380 + 1226);
                for ( i5 = 0; i5 < v482; ++i5 )
                {
                  v477 = (_DWORD *)sub_1010EF70(i5);
                  if ( v477[4] == 1000 && v480 & 1 )
                  {
                    for ( i6 = 0; i6 < *(signed __int16 *)((char *)v481 + 17); ++i6 )
                    {
                      if ( *(_DWORD *)((char *)v481 + 16 * i6 + 19) == 1 )
                      {
                        if ( v477[1] )
                        {
                          if ( v477[1] >= *(_DWORD *)((char *)v481 + 16 * i6 + 23) )
                            v287 = *(_DWORD *)((char *)v481 + 16 * i6 + 23);
                          else
                            v287 = v477[1];
                          v477[1] = v287;
                        }
                        else
                        {
                          v477[1] = *(_DWORD *)((char *)v481 + 16 * i6 + 23);
                        }
                        if ( v477[2] <= *(_DWORD *)((char *)v481 + 16 * i6 + 27) )
                          v286 = *(_DWORD *)((char *)v481 + 16 * i6 + 27);
                        else
                          v286 = v477[2];
                        v477[2] = v286;
                        v479 = 1;
                      }
                    }
                  }
                }
                (*(void (__thiscall **)(char *))(*(_DWORD *)((char *)v380 + 1186) + 28))((char *)v380 + 1186);
                if ( v479 )
                  QDataEngine::PostBroadcastCommand(0x88u, 0);
              }
            }
            goto LABEL_1064;
          case 200:
            v710 = v921;
            if ( *(_DWORD *)v921 <= 0 || !*((_BYTE *)v710 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::ProcWeiTuoAndSendToUI(v380, v710);
            goto LABEL_1064;
          case 201:
            *(_DWORD *)&v579[1] = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v580 = 0;
            v581 = 0;
            v582 = 0;
            v583 = 0;
            v584 = 0;
            v585 = 0;
            v579[0] = 0;
            sub_1036FDF0(*(_DWORD *)(*(_DWORD *)&v579[1] + 17), &v580, (int)v579);
            if ( !QDataEngine::AddOrderQueueData(
                    v579[0],
                    &v580,
                    (struct RET_ITEM_ORDER_QUEUE *)(*(_DWORD *)&v579[1] + 22),
                    *(_BYTE *)(*(_DWORD *)&v579[1] + 21)) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( *((_BYTE *)v380 + 706) )
              CDataMgr::SendOrderListToUI(v380, *(HWND *)((char *)v380 + 702));
            goto LABEL_1064;
          case 202:
            v761 = v921;
            if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v761 < 1 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::ProcTradeDetailAndSendToUI(v380, v761);
            goto LABEL_1064;
          case 203:
            v720 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            QDataEngine::SetCancelOrderRank((struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v720 + 17));
            CDataMgr::m_bHasCancelOrderData = 1;
            if ( *(_DWORD *)((char *)v720 + 6) )
              CDataMgr::SendCancelOrderDataToUI(v380, *(_DWORD *)((char *)v720 + 6));
            else
              CDataMgr::OnTimeSendCancelOrderDataToUI(v380, 12);
            goto LABEL_1064;
          case 206:
            v578 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CGlobalEnv::GetGlobalEnv(&v577);
            LOBYTE(v925) = 87;
            v402 = mfc80xU_762(28);
            if ( v402 )
              v304 = sub_1006A4F0(v402);
            else
              v304 = 0;
            v403 = v304;
            sub_100D75D0(v304);
            LOBYTE(v925) = 88;
            if ( !(unsigned __int8)CDataMgr::ProcT0MoneyFlowData(v578, &v576) )
            {
              LOBYTE(v925) = 87;
              sub_100D5E60(&v576);
              LOBYTE(v925) = 1;
              sub_100D5E60(&v577);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 242));
            for ( i7 = 0; ; ++i7 )
            {
              v235 = sub_1003EF10((char *)v380 + 649);
              if ( i7 >= v235 )
                break;
              v303 = unknown_libname_100(&v577);
              v236 = unknown_libname_100(&v576);
              v574 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v303 + 36))(v303, v236);
              v283 = v574;
              v237 = (HWND *)sub_1010DCD0(i7);
              sub_102AD840(*v237, 0x501u, 0x2011u, v283);
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 242));
            EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 266));
            for ( i8 = 0; ; ++i8 )
            {
              v238 = sub_1003EF10((char *)v380 + 665);
              if ( i8 >= v238 )
                break;
              v302 = unknown_libname_100(&v577);
              v239 = unknown_libname_100(&v576);
              v572 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v302 + 36))(v302, v239);
              v283 = v572;
              v240 = (HWND *)sub_1010DCD0(i8);
              sub_102AD840(*v240, 0x501u, 0xEu, v283);
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 266));
            LOBYTE(v925) = 87;
            sub_100D5E60(&v576);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v577);
            goto LABEL_1064;
          case 210:
            v832 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v826 = 0;
            v827 = 0;
            v828 = 0;
            v829 = 0;
            v830 = 0;
            v831 = 0;
            LOBYTE(v825) = 0;
            sub_10086E10((char *)&v825 + 1);
            if ( *(_DWORD *)((char *)v832 + 6) )
            {
              for ( i9 = 0; i9 < *((char *)v832 + 17); ++i9 )
              {
                sub_103707B0(*(_DWORD *)((char *)v832 + 178 * i9 + 18), &v826, (int)&v825);
                memcpy((char *)&v825 + 1, (char *)v832 + 178 * i9 + 18, 0xB2u);
                QDataEngine::AddSpGZQH_Dyn(v825, &v826, (struct SNAPSHOT_GZQH *)((char *)&v825 + 1));
              }
              CDataMgr::SendMsgToUI(v380, *(HWND *)((char *)v832 + 6), 0x25u);
            }
            else
            {
              EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 122));
              if ( (unsigned int)unknown_libname_95((char *)v380 + 756) < 1 )
              {
                LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 122));
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              for ( i10 = 0; i10 < *((char *)v832 + 17); ++i10 )
              {
                sub_103707B0(*(_DWORD *)((char *)v832 + 178 * i10 + 18), &v826, (int)&v825);
                memcpy((char *)&v825 + 1, (char *)v832 + 178 * i10 + 18, 0xB2u);
                QDataEngine::AddSpGZQH_Dyn(v825, &v826, (struct SNAPSHOT_GZQH *)((char *)&v825 + 1));
                v822 = sub_1036FDD0(&v826, v825);
                sub_100F4EF0(&v821, &v822);
                v92 = (_DWORD *)sub_101298A0(&v456);
                if ( !sub_100D2530(&v821, v92) )
                {
                  v93 = sub_100F5BE0(&v821);
                  sub_1012BF80((_DWORD *)(v93 + 4), (int)&v820);
                  while ( 1 )
                  {
                    sub_100F5BE0(&v821);
                    v94 = sub_101489C0(&v454);
                    if ( !(unsigned __int8)sub_100D23C0(&v820, v94) )
                      break;
                    v95 = (HWND *)sub_10035540(&v820);
                    CDataMgr::SendMsgToUI(v380, *v95, 0x25u);
                    sub_10081D50(&v455, 0);
                  }
                }
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 122));
            }
            goto LABEL_1064;
          case 211:
            v688 = v921;
            *(_DWORD *)&v689[1] = (char *)v921 + 17;
            v690 = 0;
            v691 = 0;
            v692 = 0;
            v693 = 0;
            v694 = 0;
            v695 = 0;
            v689[0] = 0;
            if ( sub_1036FDF0(*(_DWORD *)((char *)v921 + 17), &v690, (int)v689) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::SendGzqhFengbiToUI(
              v380,
              *(HWND *)((char *)v688 + 6),
              *(struct MSG_RET_QUOTE_FENBI_BODY **)&v689[1]);
            break;
          case 214:
            v721 = v921;
            CDataMgr::SendRatioPriceToUI(v380, *(HWND *)((char *)v921 + 6), v921);
            goto LABEL_1064;
          case 215:
            v529 = v921;
            CDataMgr::ProcHundredsL2Quote(v380, v921);
            goto LABEL_1064;
          case 216:
            v528 = v921;
            CDataMgr::ProcOrderQueue(v380, v921);
            goto LABEL_1064;
          case 217:
            v530 = v921;
            CDataMgr::ProcStkMultiL2Quote(v380, v921);
            goto LABEL_1064;
          case 218:
            CDataMgr::ProcProbUpData(v380, v921);
            goto LABEL_1064;
          case 219:
            CDataMgr::ProcProbUpDaysData(v380, v921);
            goto LABEL_1064;
          case 220:
            CDataMgr::ProcHisProbUpData(v380, v921);
            goto LABEL_1064;
          default:
            goto LABEL_1063;
        }
      }
      goto LABEL_1064;
    }
    if ( v378 <= 2003 )
    {
      if ( v378 == 2003 )
      {
LABEL_581:
        v681 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v921 + 17);
        v682 = 0;
      }
      else
      {
        v378 -= 1002;
        switch ( v378 )
        {
          case 0:
            v686 = v921;
            mfc80xU_293(&v685);
            LOBYTE(v925) = 75;
            v321 = (int *)mfc80xU_287(&v426, (char *)v686 + 18);
            v320 = v321;
            LOBYTE(v925) = 76;
            v283 = *v321;
            mfc80xU_2311(&v685, (const char *)L"%s", v283);
            LOBYTE(v925) = 75;
            mfc80xU_577(&v426);
            if ( *(_DWORD *)((char *)v686 + 34) > 0 )
            {
              v283 = *(_DWORD *)((char *)v686 + 30);
              v282 = *(_DWORD *)((char *)v686 + 26);
              v281 = *(char **)((char *)v686 + 34);
              v280 = (int *)((char *)v686 + 38);
              LODWORD(v279) = *((unsigned __int8 *)v686 + 25);
              HIDWORD(v278) = *((char *)v686 + 17);
              LODWORD(v278) = v686;
              v425 = &v278;
              v319 = mfc80xU_280(&v278, &v685);
              QDataEngine::WriteF10(SBYTE4(v278), LODWORD(v279), v280, v281, v282, v283, v284);
              v284 = (WCHAR *)&v684;
              v283 = (int)&v683;
              v282 = *((unsigned __int8 *)v686 + 25);
              v281 = (char *)*((char *)v686 + 17);
              v280 = (int *)v282;
              v424 = &v280;
              v318 = mfc80xU_280(&v280, &v685);
              CDataMgr::SendF10InfoToUI(*(HWND *)((char *)v686 + 6), SLOBYTE(v279), (int)v280, (int)v281, v282, v283);
            }
            LOBYTE(v925) = 1;
            mfc80xU_577(&v685);
            goto LABEL_1064;
          case 3:
            goto LABEL_581;
          case 4:
          case 5:
            v920 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            *(_DWORD *)((char *)v380 + 50) = *(_DWORD *)((char *)v920 + 51);
            QDataEngine::SetHisLoginInStatus(1);
            *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 2) = 1;
            goto LABEL_1064;
          case 9:
            v558 = v921;
            if ( !v921 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v394 = mfc80xU_762(16);
            if ( v394 )
              v298 = sub_100F5AC0(v394);
            else
              v298 = 0;
            v395 = v298;
            sub_100D75D0(v298);
            LOBYTE(v925) = 91;
            v246 = unknown_libname_100(&v557);
            v247 = (_DWORD *)unknown_libname_96(v246);
            *v247 = *(_DWORD *)((char *)v558 + 17);
            v248 = unknown_libname_100(&v557);
            v283 = v249;
            v393 = &v283;
            v297 = sub_100D75D0(v248);
            sub_102B3660(*(HWND *)((char *)v921 + 6), 0x44u, v283);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v557);
            goto LABEL_1064;
          case 10:
            v555 = v921;
            if ( !v921 || *((char *)v555 + 10) < 1 || (signed int)*((unsigned __int8 *)v555 + 17) < 1 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v391 = mfc80xU_762(56);
            LOBYTE(v925) = 92;
            if ( v391 )
              v296 = sub_100F5AE0(v391);
            else
              v296 = 0;
            v392 = v296;
            LOBYTE(v925) = 1;
            sub_100D75D0(v296);
            LOBYTE(v925) = 93;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(&v553);
            LOBYTE(v925) = 94;
            v556 = *((_BYTE *)v555 + 17);
            v551 = (signed __int16 *)((char *)v555 + 18);
            v554 = 1;
            while ( v556 > 0 )
            {
              v390 = (void *)mfc80xU_265(*v551 + 1);
              v550 = v390;
              memcpy(v390, v551 + 1, *v551);
              *((_BYTE *)v550 + *v551) = 0;
              v549 = v551;
              v551 = (signed __int16 *)((char *)v551 + *v551 + 2);
              if ( v554 )
              {
                v283 = (int)v550;
                v250 = unknown_libname_100(&v552);
                v251 = unknown_libname_96(v250);
                std::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(v251, v283);
                v554 = 0;
              }
              else
              {
                std::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(&v553, v550);
                v252 = unknown_libname_100(&v552);
                unknown_libname_96(v252);
                sub_10019530(&v553);
              }
              --v556;
              if ( v550 )
              {
                v389 = v550;
                mfc80xU_266(v550);
                v550 = 0;
              }
            }
            v253 = unknown_libname_100(&v552);
            v283 = v254;
            v388 = &v283;
            v295 = sub_100D75D0(v253);
            sub_102B3660(*(HWND *)((char *)v921 + 6), 0x45u, v283);
            LOBYTE(v925) = 93;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v553);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v552);
            goto LABEL_1064;
          case 12:
            v707 = v921;
            v323 = mfc80xU_287(&v427, (char *)v921 + 18);
            v322 = v323;
            LOBYTE(v925) = 74;
            v283 = *(_DWORD *)((char *)v707 + 25);
            v205 = (const wchar_t *)mfc80xU_870(v323);
            QDataEngine::SaveGzqhHisRtData(
              (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v707 + 31),
              *(signed __int16 *)((char *)v707 + 29),
              *((_BYTE *)v707 + 17),
              v205,
              v283);
            LOBYTE(v925) = 1;
            mfc80xU_577(&v427);
            CDataMgr::SendHisTrendDataToUI(
              v380,
              *(HWND *)((char *)v707 + 6),
              (char *)v707 + 18,
              *((_BYTE *)v707 + 17),
              *(_DWORD *)((char *)v707 + 25));
            goto LABEL_1064;
          case 13:
            v541 = v921;
            if ( !v921 || !*((_BYTE *)v541 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::ProcHisTrendData(v380, v541);
            goto LABEL_1064;
          case 14:
          case 17:
            v540 = v921;
            if ( !v921 || !*((_BYTE *)v540 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            CDataMgr::ProcHisTrendCfsData(v380, v540);
            goto LABEL_1064;
          case 18:
            CDataMgr::ProcHisDayKlineData(v380, v921);
            goto LABEL_1064;
          case 19:
            CDataMgr::ProcHisMinKlineData(v380, v921);
            goto LABEL_1064;
          case 20:
            CDataMgr::ProcGloabalHisStkTrend(v380, v921);
            goto LABEL_1064;
          case 21:
            v531 = v921;
            CDataMgr::ProcHisRtLineValidDays(
              v380,
              *((_BYTE *)v921 + 17),
              (LPCSTR)v921 + 18,
              (int *)((char *)v921 + 38),
              *(_DWORD *)((char *)v921 + 34),
              77,
              *(_DWORD *)((char *)v921 + 6));
            goto LABEL_1064;
          case 22:
            v533 = v921;
            if ( !v921 || !*((_BYTE *)v533 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            LOBYTE(v532) = 0;
            MultiByteStr = 0;
            v535 = 0;
            v536 = 0;
            v537 = 0;
            v538 = 0;
            v539 = 0;
            *(int *)((char *)&v532 + 1) = sub_103707B0(*(_DWORD *)((char *)v533 + 17), &MultiByteStr, (int)&v532);
            if ( *(int *)((char *)&v532 + 1) == -1 )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v283 = *(_DWORD *)((char *)v533 + 6);
            v282 = 77;
            CDataMgr::ProcHisRtLineValidDays(
              v380,
              v532,
              &MultiByteStr,
              (int *)((char *)v533 + 25),
              *(_DWORD *)((char *)v533 + 21),
              77,
              v283);
            goto LABEL_1064;
          case 25:
            v755 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v452 = mfc80xU_762(32);
            if ( v452 )
              v345 = sub_100A39A0(v452);
            else
              v345 = 0;
            v453 = v345;
            sub_100D75D0(v345);
            LOBYTE(v925) = 53;
            v127 = unknown_libname_100(&v757);
            v128 = (_BYTE *)unknown_libname_96(v127);
            *v128 = *((_BYTE *)v755 + 17);
            v283 = (int)v755 + 18;
            v129 = unknown_libname_100(&v757);
            v130 = unknown_libname_96(v129);
            strcpy_s((char *)(v130 + 1), 0x10u, (const char *)v283);
            CGlobalEnv::GetGlobalEnv(&v753);
            LOBYTE(v925) = 54;
            v450 = mfc80xU_762(28);
            if ( v450 )
              v344 = sub_1006A4F0(v450);
            else
              v344 = 0;
            v451 = v344;
            sub_100D75D0(v344);
            LOBYTE(v925) = 55;
            v131 = unknown_libname_100(&v756);
            *(_DWORD *)unknown_libname_96(v131) = 41;
            v132 = unknown_libname_100(&v756);
            unknown_libname_96(v132);
            sub_10119EF0(&v757);
            v758 = CDataMgr::ChangeCycleNetToUI(v380, *((unsigned __int8 *)v755 + 41));
            if ( *(_DWORD *)((char *)v755 + 42) <= 0 || v758 < 0 )
            {
              v134 = unknown_libname_100(&v756);
              *(_DWORD *)(unknown_libname_96(v134) + 4) = 6;
            }
            else
            {
              QDataEngine::Add_HisData(
                *((_BYTE *)v755 + 17),
                (char *)v755 + 18,
                v758,
                *(_DWORD *)((char *)v755 + 42),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v755 + 46));
              v133 = unknown_libname_100(&v756);
              *(_DWORD *)(unknown_libname_96(v133) + 4) = 0;
            }
            v343 = unknown_libname_100(&v753);
            v135 = unknown_libname_100(&v756);
            v754 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v343 + 36))(v343, v135);
            sub_102AD840(*(HWND *)((char *)v755 + 6), 0x501u, 0x29u, v754);
            LOBYTE(v925) = 54;
            sub_100D5E60(&v756);
            LOBYTE(v925) = 53;
            sub_100D5E60(&v753);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v757);
            goto LABEL_1064;
          case 26:
LABEL_488:
            v738 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v440 = mfc80xU_762(32);
            if ( v440 )
              v336 = sub_100A39A0(v440);
            else
              v336 = 0;
            v441 = v336;
            sub_100D75D0(v336);
            LOBYTE(v925) = 62;
            v154 = unknown_libname_100(&v740);
            v155 = (_BYTE *)unknown_libname_96(v154);
            *v155 = *((_BYTE *)v738 + 17);
            v283 = (int)v738 + 18;
            v156 = unknown_libname_100(&v740);
            v157 = unknown_libname_96(v156);
            strcpy_s((char *)(v157 + 1), 0x10u, (const char *)v283);
            CGlobalEnv::GetGlobalEnv(&v736);
            LOBYTE(v925) = 63;
            v438 = mfc80xU_762(28);
            if ( v438 )
              v335 = sub_1006A4F0(v438);
            else
              v335 = 0;
            v439 = v335;
            sub_100D75D0(v335);
            LOBYTE(v925) = 64;
            v158 = unknown_libname_100(&v739);
            *(_DWORD *)unknown_libname_96(v158) = 41;
            v159 = unknown_libname_100(&v739);
            unknown_libname_96(v159);
            sub_10119EF0(&v740);
            sub_100348F0(&v735);
            LOBYTE(v925) = 65;
            v742 = CDataMgr::ChangeCycleNetToUI(v380, *((unsigned __int8 *)v738 + 41));
            if ( *(_DWORD *)((char *)v738 + 42) <= 0 || v742 < 0 )
            {
              v162 = unknown_libname_100(&v739);
              *(_DWORD *)(unknown_libname_96(v162) + 4) = 6;
            }
            else
            {
              for ( i11 = 0; i11 < *(_DWORD *)((char *)v738 + 42); ++i11 )
              {
                memcpy(&v741, (char *)v738 + 52 * i11 + 46, 0x20u);
                sub_100F5A20(&v741);
              }
              v160 = (struct DAYDATA *)sub_100F59F0(0);
              QDataEngine::Add_HisData(
                *((_BYTE *)v738 + 17),
                (char *)v738 + 18,
                v742,
                *(_DWORD *)((char *)v738 + 42),
                v160);
              QDataEngine::Add_GZQHHisData(
                *((_BYTE *)v738 + 17),
                (char *)v738 + 18,
                v742,
                *(_DWORD *)((char *)v738 + 42),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v738 + 46));
              v161 = unknown_libname_100(&v739);
              *(_DWORD *)(unknown_libname_96(v161) + 4) = 0;
            }
            v334 = unknown_libname_100(&v736);
            v163 = unknown_libname_100(&v739);
            v737 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v334 + 36))(v334, v163);
            v283 = v737;
            v282 = 41;
            v281 = (char *)1281;
            v280 = *(int **)((char *)v738 + 6);
            v164 = CDataMgr::GetReceiverSafeHandle(v380);
            CViewManager::PostExDataMessage(v164, (unsigned int)v280, 0x501u, 0x29u, v283);
            LOBYTE(v925) = 64;
            sub_10034960(&v735);
            LOBYTE(v925) = 63;
            sub_100D5E60(&v739);
            LOBYTE(v925) = 62;
            sub_100D5E60(&v736);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v740);
            goto LABEL_1064;
          case 27:
            CGlobalEnv::GetGlobalEnv(&v596);
            LOBYTE(v925) = 82;
            v409 = mfc80xU_762(28);
            if ( v409 )
              v308 = sub_1006A4F0(v409);
            else
              v308 = 0;
            v410 = v308;
            sub_100D75D0(v308);
            LOBYTE(v925) = 83;
            v407 = mfc80xU_762(32);
            if ( v407 )
              v307 = sub_100A39A0(v407);
            else
              v307 = 0;
            v408 = v307;
            sub_100D75D0(v307);
            LOBYTE(v925) = 84;
            v600 = v921;
            if ( !v921 || !*(_DWORD *)((char *)v921 + 6) )
            {
              LOBYTE(v925) = 83;
              sub_100D5E60(&v599);
              LOBYTE(v925) = 82;
              sub_100D5E60(&v598);
              LOBYTE(v925) = 1;
              sub_100D5E60(&v596);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            if ( strlen((const char *)v600 + 18) < 1 )
            {
              LOBYTE(v925) = 83;
              sub_100D5E60(&v599);
              LOBYTE(v925) = 82;
              sub_100D5E60(&v598);
              LOBYTE(v925) = 1;
              sub_100D5E60(&v596);
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v227 = unknown_libname_100(&v599);
            v228 = (_BYTE *)unknown_libname_96(v227);
            *v228 = *((_BYTE *)v600 + 17);
            v283 = (int)v600 + 18;
            v229 = unknown_libname_100(&v599);
            v230 = unknown_libname_96(v229);
            strcpy_s((char *)(v230 + 1), 0x10u, (const char *)v283);
            v231 = unknown_libname_100(&v598);
            unknown_libname_96(v231);
            sub_10119EF0(&v599);
            v232 = unknown_libname_100(&v598);
            *(_DWORD *)unknown_libname_96(v232) = 52;
            if ( *(_DWORD *)((char *)v600 + 42) <= 0 )
            {
              v234 = unknown_libname_100(&v598);
              *(_DWORD *)(unknown_libname_96(v234) + 4) = 6;
            }
            else
            {
              v590 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v600 + 46);
              if ( v600 == (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)-46 )
              {
                LOBYTE(v925) = 83;
                sub_100D5E60(&v599);
                LOBYTE(v925) = 82;
                sub_100D5E60(&v598);
                LOBYTE(v925) = 1;
                sub_100D5E60(&v596);
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              v406 = (void *)mfc80xU_265(168 * *(_DWORD *)((char *)v600 + 42) | -(168
                                                                                * (unsigned __int64)*(unsigned int *)((char *)v600 + 42) >> 32 != 0));
              v592 = v406;
              memset(v406, 0, 168 * *(_DWORD *)((char *)v600 + 42));
              mfc80xU_293(&v588);
              LOBYTE(v925) = 85;
              sub_1036D2D0((LPCSTR)v600 + 18, (int)&v588);
              v593 = CDataMgr::ChangeCycleNetToUI(v380, *((unsigned __int8 *)v600 + 41));
              v595 = 0;
              v587 = 0;
              for ( i12 = 0.0; SLODWORD(i12) < *(_DWORD *)((char *)v600 + 42); ++LODWORD(i12) )
              {
                *((_DWORD *)v592 + 42 * LODWORD(i12)) = *((_DWORD *)v590 + 41 * LODWORD(i12));
                if ( v593 < 9 )
                {
                  v283 = (int)&v587;
                  v282 = (int)&v595;
                  v281 = (char *)v592;
                  v280 = *(int **)((char *)v600 + 42);
                  v279 = i12;
                  v278 = COERCE_DOUBLE(__PAIR__(v593, (unsigned int)v280));
                  v405 = &v278;
                  v306 = mfc80xU_280(&v278, &v588);
                  sub_10371510(
                    *((char *)v600 + 17),
                    SLOBYTE(v278),
                    HIDWORD(v278),
                    LODWORD(v279),
                    v280,
                    v281,
                    v282,
                    v283);
                  *((_DWORD *)v592 + 42 * LODWORD(i12) + 1) = 0;
                }
                *((_DWORD *)v592 + 42 * LODWORD(i12) + 1) = 100 * (v587 + 100 * v595);
                memcpy((char *)v592 + 168 * LODWORD(i12) + 8, (char *)v590 + 164 * LODWORD(i12) + 4, 0xA0u);
              }
              v589 = -1;
              std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v594);
              LOBYTE(v925) = 86;
              sub_1036D210((LPCSTR)v600 + 18, (int)&v594);
              v283 = (int)&v589;
              v282 = *(_DWORD *)((char *)v600 + 42);
              v281 = (char *)v592;
              v280 = &v594;
              v279 = *(float *)&v593;
              v591 = QDataEngine::WriteCapitalFlowKLineData(
                       *((_BYTE *)v600 + 17),
                       v593,
                       (int)&v594,
                       v592,
                       v282,
                       (int)&v589);
              if ( v592 )
              {
                v404 = v592;
                mfc80xU_266(v592);
                v592 = 0;
              }
              if ( v591 < 1 )
              {
                LOBYTE(v925) = 85;
                std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v594);
                LOBYTE(v925) = 84;
                mfc80xU_577(&v588);
                LOBYTE(v925) = 83;
                sub_100D5E60(&v599);
                LOBYTE(v925) = 82;
                sub_100D5E60(&v598);
                LOBYTE(v925) = 1;
                sub_100D5E60(&v596);
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              v233 = unknown_libname_100(&v598);
              *(_DWORD *)(unknown_libname_96(v233) + 4) = 0;
              LOBYTE(v925) = 85;
              std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::~basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&v594);
              LOBYTE(v925) = 84;
              mfc80xU_577(&v588);
            }
            v305 = unknown_libname_100(&v596);
            v283 = unknown_libname_100(&v598);
            v597 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v305 + 36))(v305, v283);
            v283 = v597;
            v282 = 52;
            v281 = (char *)1281;
            sub_102AD840(*(HWND *)((char *)v921 + 6), 0x501u, 0x34u, v597);
            LOBYTE(v925) = 83;
            sub_100D5E60(&v599);
            LOBYTE(v925) = 82;
            sub_100D5E60(&v598);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v596);
            goto LABEL_1064;
          case 29:
            v750 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v448 = mfc80xU_762(32);
            if ( v448 )
              v342 = sub_100A39A0(v448);
            else
              v342 = 0;
            v449 = v342;
            sub_100D75D0(v342);
            LOBYTE(v925) = 56;
            v136 = unknown_libname_100(&v752);
            v137 = (_BYTE *)unknown_libname_96(v136);
            *v137 = *((_BYTE *)v750 + 17);
            v283 = (int)v750 + 18;
            v138 = unknown_libname_100(&v752);
            v139 = unknown_libname_96(v138);
            strcpy_s((char *)(v139 + 1), 0x10u, (const char *)v283);
            CGlobalEnv::GetGlobalEnv(&v748);
            LOBYTE(v925) = 57;
            v446 = mfc80xU_762(28);
            if ( v446 )
              v341 = sub_1006A4F0(v446);
            else
              v341 = 0;
            v447 = v341;
            sub_100D75D0(v341);
            LOBYTE(v925) = 58;
            v140 = unknown_libname_100(&v751);
            *(_DWORD *)unknown_libname_96(v140) = 118;
            v141 = unknown_libname_100(&v751);
            unknown_libname_96(v141);
            sub_10119EF0(&v752);
            if ( *(_DWORD *)((char *)v750 + 26) )
            {
              QDataEngine::WriteMarginTradeHisData(
                (LPCSTR)v750 + 18,
                *((char *)v750 + 17),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v750 + 30),
                *(_DWORD *)((char *)v750 + 26));
              v142 = unknown_libname_100(&v751);
              *(_DWORD *)(unknown_libname_96(v142) + 4) = 0;
            }
            else
            {
              v143 = unknown_libname_100(&v751);
              *(_DWORD *)(unknown_libname_96(v143) + 4) = 6;
            }
            v340 = unknown_libname_100(&v748);
            v144 = unknown_libname_100(&v751);
            v749 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v340 + 36))(v340, v144);
            sub_102AD840(*(HWND *)((char *)v750 + 6), 0x501u, 0x76u, v749);
            LOBYTE(v925) = 57;
            sub_100D5E60(&v751);
            LOBYTE(v925) = 56;
            sub_100D5E60(&v748);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v752);
            goto LABEL_1064;
          case 30:
            v729 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v436 = mfc80xU_762(32);
            if ( v436 )
              v333 = sub_100A39A0(v436);
            else
              v333 = 0;
            v437 = v333;
            sub_100D75D0(v333);
            LOBYTE(v925) = 66;
            v283 = (int)v729 + 17;
            v165 = unknown_libname_100(&v731);
            v166 = unknown_libname_96(v165);
            strcpy_s((char *)(v166 + 1), 0x10u, (const char *)v283);
            CGlobalEnv::GetGlobalEnv(&v727);
            LOBYTE(v925) = 67;
            v434 = mfc80xU_762(28);
            if ( v434 )
              v332 = sub_1006A4F0(v434);
            else
              v332 = 0;
            v435 = v332;
            sub_100D75D0(v332);
            LOBYTE(v925) = 68;
            v167 = unknown_libname_100(&v730);
            *(_DWORD *)unknown_libname_96(v167) = 116;
            v168 = unknown_libname_100(&v730);
            unknown_libname_96(v168);
            sub_10119EF0(&v731);
            v732 = CDataMgr::ChangeCycleNetToUI(v380, *((unsigned __int8 *)v729 + 24));
            v733 = strcmp((const char *)v729 + 17, "HGT") != 0 ? 116 : 1;
            if ( *(_DWORD *)((char *)v729 + 25) <= 0 )
            {
              v170 = unknown_libname_100(&v730);
              *(_DWORD *)(unknown_libname_96(v170) + 4) = 6;
            }
            else
            {
              QDataEngine::WriteHgtLimitHisData(
                (char *)v729 + 17,
                v733,
                (char *)v729 + 29,
                *(_DWORD *)((char *)v729 + 25),
                v732);
              v169 = unknown_libname_100(&v730);
              *(_DWORD *)(unknown_libname_96(v169) + 4) = 0;
            }
            v331 = unknown_libname_100(&v727);
            v171 = unknown_libname_100(&v730);
            v728 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v331 + 36))(v331, v171);
            sub_102AD840(*(HWND *)((char *)v729 + 6), 0x501u, 0x74u, v728);
            LOBYTE(v925) = 67;
            sub_100D5E60(&v730);
            LOBYTE(v925) = 66;
            sub_100D5E60(&v727);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v731);
            goto LABEL_1064;
          case 33:
            v745 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v444 = mfc80xU_762(32);
            if ( v444 )
              v339 = sub_100A39A0(v444);
            else
              v339 = 0;
            v445 = v339;
            sub_100D75D0(v339);
            LOBYTE(v925) = 59;
            v145 = unknown_libname_100(&v747);
            v146 = (_BYTE *)unknown_libname_96(v145);
            *v146 = *((_BYTE *)v745 + 17);
            v283 = (int)v745 + 18;
            v147 = unknown_libname_100(&v747);
            v148 = unknown_libname_96(v147);
            strcpy_s((char *)(v148 + 1), 0x10u, (const char *)v283);
            CGlobalEnv::GetGlobalEnv(&v743);
            LOBYTE(v925) = 60;
            v442 = mfc80xU_762(28);
            if ( v442 )
              v338 = sub_1006A4F0(v442);
            else
              v338 = 0;
            v443 = v338;
            sub_100D75D0(v338);
            LOBYTE(v925) = 61;
            v149 = unknown_libname_100(&v746);
            *(_DWORD *)unknown_libname_96(v149) = 119;
            v150 = unknown_libname_100(&v746);
            unknown_libname_96(v150);
            sub_10119EF0(&v747);
            if ( *(_DWORD *)((char *)v745 + 42) <= 0 )
            {
              v152 = unknown_libname_100(&v746);
              *(_DWORD *)(unknown_libname_96(v152) + 4) = 6;
            }
            else
            {
              QDataEngine::WriteIndexStatHisData(
                (LPCSTR)v745 + 18,
                *((char *)v745 + 17),
                (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v745 + 46),
                *(_DWORD *)((char *)v745 + 42));
              v151 = unknown_libname_100(&v746);
              *(_DWORD *)(unknown_libname_96(v151) + 4) = 0;
            }
            v337 = unknown_libname_100(&v743);
            v153 = unknown_libname_100(&v746);
            v744 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v337 + 36))(v337, v153);
            sub_102AD840(*(HWND *)((char *)v745 + 6), 0x501u, 0x77u, v744);
            LOBYTE(v925) = 60;
            sub_100D5E60(&v746);
            LOBYTE(v925) = 59;
            sub_100D5E60(&v743);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v747);
            goto LABEL_1064;
          case 38:
            v724 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            v432 = mfc80xU_762(76);
            if ( v432 )
              v330 = sub_100F5A90(v432);
            else
              v330 = 0;
            v433 = v330;
            sub_100D75D0(v330);
            LOBYTE(v925) = 69;
            v283 = (int)v724 + 25;
            v172 = unknown_libname_100(&v726);
            v173 = unknown_libname_96(v172);
            strcpy_s((char *)(v173 + 1), 0x10u, (const char *)v283);
            v174 = unknown_libname_100(&v726);
            v175 = (_BYTE *)unknown_libname_96(v174);
            *v175 = *((_BYTE *)v724 + 19);
            v176 = unknown_libname_100(&v726);
            v177 = unknown_libname_96(v176);
            *(_BYTE *)(v177 + 17) = *((_BYTE *)v724 + 18);
            v178 = unknown_libname_100(&v726);
            v179 = unknown_libname_96(v178);
            *(_DWORD *)(v179 + 18) = *(_DWORD *)((char *)v724 + 41);
            v180 = unknown_libname_100(&v726);
            v181 = unknown_libname_96(v180);
            *(_DWORD *)(v181 + 22) = *(_DWORD *)((char *)v724 + 45);
            v182 = unknown_libname_100(&v726);
            v183 = unknown_libname_96(v182);
            *(_DWORD *)(v183 + 26) = *(_DWORD *)((char *)v724 + 49);
            v184 = unknown_libname_100(&v726);
            v185 = unknown_libname_96(v184);
            *(_DWORD *)(v185 + 30) = *(_DWORD *)((char *)v724 + 53);
            v186 = unknown_libname_100(&v726);
            v187 = unknown_libname_96(v186);
            *(_DWORD *)(v187 + 34) = *(_DWORD *)((char *)v724 + 57);
            v188 = unknown_libname_100(&v726);
            v189 = unknown_libname_96(v188);
            *(_DWORD *)(v189 + 38) = *(_DWORD *)((char *)v724 + 61);
            v190 = unknown_libname_100(&v726);
            v191 = unknown_libname_96(v190);
            *(_DWORD *)(v191 + 42) = *(_DWORD *)((char *)v724 + 65);
            v192 = unknown_libname_100(&v726);
            v193 = unknown_libname_96(v192);
            *(_DWORD *)(v193 + 46) = *(_DWORD *)((char *)v724 + 69);
            v194 = unknown_libname_100(&v726);
            v195 = unknown_libname_96(v194);
            *(_DWORD *)(v195 + 50) = *(_DWORD *)((char *)v724 + 73);
            v196 = unknown_libname_100(&v726);
            v197 = unknown_libname_96(v196);
            v198 = v724;
            *(_DWORD *)(v197 + 54) = *(_DWORD *)((char *)v724 + 77);
            *(_DWORD *)(v197 + 58) = *(_DWORD *)((char *)v198 + 81);
            CGlobalEnv::GetGlobalEnv(&v722);
            LOBYTE(v925) = 70;
            v430 = mfc80xU_762(28);
            if ( v430 )
              v329 = sub_1006A4F0(v430);
            else
              v329 = 0;
            v431 = v329;
            sub_100D75D0(v329);
            LOBYTE(v925) = 71;
            v199 = unknown_libname_100(&v725);
            *(_DWORD *)unknown_libname_96(v199) = 131;
            v200 = unknown_libname_100(&v725);
            unknown_libname_96(v200);
            sub_10119EF0(&v726);
            v201 = unknown_libname_100(&v725);
            *(_DWORD *)(unknown_libname_96(v201) + 4) = 0;
            v328 = unknown_libname_100(&v722);
            v202 = unknown_libname_100(&v725);
            v723 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v328 + 36))(v328, v202);
            sub_102AD840(*(HWND *)((char *)v724 + 6), 0x501u, 0x83u, v723);
            LOBYTE(v925) = 70;
            sub_100D5E60(&v725);
            LOBYTE(v925) = 69;
            sub_100D5E60(&v722);
            LOBYTE(v925) = 1;
            sub_100D5E60(&v726);
            break;
          default:
            goto LABEL_1063;
        }
      }
      goto LABEL_1064;
    }
    if ( v378 > 8001 )
    {
      v378 -= 8002;
      switch ( v378 )
      {
        case 0:
LABEL_1029:
          if ( v921 )
          {
            v488 = v921;
            if ( *((_WORD *)v921 + 2) == 753 )
              QDataEngine::SetAppServerCurDate(*(_DWORD *)((char *)v488 + 17), *(_DWORD *)((char *)v488 + 21));
            if ( *((_BYTE *)v488 + 25) & 1 )
            {
              wsprintfW(
                &v484,
                L"server alive type = %d, %d",
                *((signed __int16 *)v921 + 2),
                *((unsigned __int8 *)v488 + 25));
              LightLogger::CLogger::GetLogger(&v485, L"ProcServerList");
              LOBYTE(v925) = 101;
              v275 = (LightLogger::CLogger *)unknown_libname_100(&v485);
              LightLogger::CLogger::WriteLogLine(v275, &v484, 20000);
              sub_10086F30(&v486);
              v486 = 1;
              if ( !strcmp(QDataEngine::m_LogonInfo, "guest") && !strcmp(byte_10479458, "guest") )
              {
                strcpy_s(&Dst, 0x20u, "guest");
              }
              else
              {
                v483 = sub_102DBC20();
                v289 = sub_10032460(&v381);
                v288 = v289;
                LOBYTE(v925) = 102;
                v276 = (const char *)std::basic_string<char,std::char_traits<char>,std::allocator<char>>::c_str(v289);
                strcpy_s(&Dst, 0x20u, v276);
                LOBYTE(v925) = 101;
                std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v381);
              }
              CDataMgr::RequestCmd(v380, 0, 125, 1, &v486, 0);
              LOBYTE(v925) = 1;
              sub_100D5E60(&v485);
            }
          }
          goto LABEL_1064;
        case 98:
          v527 = v921;
          CDataMgr::ProcGssStkListData(v380, v921);
          goto LABEL_1064;
        case 101:
          v526 = v921;
          if ( !v921 || !*((_BYTE *)v526 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcGlobalStkTrend(v380, v526);
          goto LABEL_1064;
        case 102:
          v525 = v921;
          if ( !v921 || !*((_BYTE *)v525 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcGlobalStkKLine(v380, v525);
          goto LABEL_1064;
        case 103:
          v523 = v921;
          CDataMgr::ProcGssStkDetailData(v380, v921);
          goto LABEL_1064;
        case 106:
          CDataMgr::ProcGssMarketInfo(v380, v921);
          goto LABEL_1064;
        case 107:
          CDataMgr::ProcGssBufferListData(v380, v921);
          goto LABEL_1064;
        case 108:
          v521 = v921;
          v294 = *((_BYTE *)v921 + 18);
          switch ( v294 )
          {
            case 5:
              v283 = *((unsigned __int8 *)v521 + 19) != 201 ? 1817 : 1811;
              v256 = *(_DWORD *)((char *)v380 + 1106);
              v520 = sub_10395350(v283);
              if ( !v520 )
              {
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              (*(void (__thiscall **)(int, struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *))(*(_DWORD *)v520 + 4))(v520, v521);
              break;
            case 6:
              CDataMgr::ProcFavGssBkIndexQuoteTable(v380, v521);
              break;
            case 7:
              v283 = *((unsigned __int8 *)v521 + 19) != 201 ? 1824 : 1812;
              v257 = *(_DWORD *)((char *)v380 + 1106);
              v519 = sub_10395350(v283);
              if ( !v519 )
              {
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              (*(void (__thiscall **)(int, struct MSG_RET_FAV_GSS_BK_INDEX_TABLE *))(*(_DWORD *)v519 + 4))(v519, v521);
              break;
            default:
              CDataMgr::ProcGssQuoteTable(v380, v521);
              goto LABEL_1064;
          }
          goto LABEL_1064;
        case 109:
          v524 = v921;
          if ( !v921 || !*((_BYTE *)v524 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcGlobalStkHQRecord(v380, v524);
          goto LABEL_1064;
        case 112:
          CDataMgr::ProcGssBkStkQuoteTable(v380, v921);
          goto LABEL_1064;
        case 114:
          v518 = v921;
          if ( *((_BYTE *)v921 + 18) != 6 )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcFavGssBkIndexQuoteTable(v380, v518);
          goto LABEL_1064;
        case 115:
          v522 = v921;
          if ( !v921 || !*((_BYTE *)v522 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcGlobalStkHQEx(v380, v522);
          break;
        case 126:
          CDataMgr::ProcGssMarketBkStkQuoteTable(v380, v921);
          goto LABEL_1064;
        default:
          goto LABEL_1063;
      }
      goto LABEL_1064;
    }
    if ( v378 != 8001 )
    {
      if ( v378 > 4005 )
      {
        if ( v378 >= 4006 )
        {
          if ( v378 <= 4007 )
          {
            v908 = v921;
            if ( !*((_BYTE *)v921 + 10) )
            {
              LOBYTE(v925) = 0;
              sub_100D5E60(&v923);
              v925 = -1;
              sub_100D5E60(&v924);
              return;
            }
            *(_DWORD *)((char *)v380 + 62) = *(_DWORD *)((char *)v908 + 51);
            QDataEngine::SetMineLoginInStatus(1);
            *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 5) = 1;
            *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 6) = 1;
            *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 7) = 1;
            goto LABEL_1064;
          }
          if ( v378 == 4180 )
          {
            QDataEngine::ReceiveMineInfo(v921);
            goto LABEL_1064;
          }
        }
        goto LABEL_1063;
      }
      switch ( v378 )
      {
        case 4005:
          goto LABEL_1064;
        case 3020:
          v543 = v921;
          if ( !v921 || !*((_BYTE *)v543 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcStkTrend(v380, v543);
          goto LABEL_1064;
        case 3021:
          v542 = v921;
          if ( !v921 || !*((_BYTE *)v542 + 10) )
          {
            LOBYTE(v925) = 0;
            sub_100D5E60(&v923);
            v925 = -1;
            sub_100D5E60(&v924);
            return;
          }
          CDataMgr::ProcStkTrendCfs(v380, v542);
          goto LABEL_1064;
      }
      if ( v378 != 4002 )
      {
LABEL_1063:
        v283 = (int)v921;
        v282 = *((signed __int16 *)v921 + 2);
        v277 = *(_DWORD *)((char *)v380 + 1106);
        sub_103953C0(v282, v921);
        goto LABEL_1064;
      }
    }
    v919 = v921;
    if ( !*((_BYTE *)v921 + 10) )
    {
      LOBYTE(v925) = 0;
      sub_100D5E60(&v923);
      v925 = -1;
      sub_100D5E60(&v924);
      return;
    }
    *(_DWORD *)((char *)v380 + 66) = *(_DWORD *)((char *)v919 + 51);
    QDataEngine::SetGssLoginInStatus(1);
    *(_BYTE *)(*(_DWORD *)((char *)v380 + 37) + 4) = 1;
    QDataEngine::SetMcmVersion(*((_DWORD *)v919 + 5));
    if ( *((_BYTE *)v380 + 1053) )
    {
      CDataMgr::RequestCmd(v380, 0, 90, 1, 0, 0);
      *((_BYTE *)v380 + 1053) = 0;
    }
    CDataMgr::DoSomethingAfterLoginTest(v380);
    if ( QDataEngine::GetLoginInStatus() )
      CDataMgr::DoSomethingAfterGssLogin(v380);
    CDataMgr::ClearDataOfGss(v380);
    goto LABEL_1064;
  }
  if ( v378 != 601 )
  {
    v378 -= 323;
    switch ( v378 )
    {
      case 0:
        v855 = v921;
        if ( !*((_BYTE *)v921 + 10) || !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        for ( i13 = 0; i13 < *((signed __int16 *)v855 + 9); ++i13 )
          QDataEngine::Add_DynamicDataStockEx(
            *((_BYTE *)v855 + 93 * i13 + 20),
            (LPCSTR)v855 + 93 * i13 + 21,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v855 + 93 * i13 + 20));
        CDataMgr::SendMsgToUI(v380, *(HWND *)((char *)v921 + 6), 0x701u);
        goto LABEL_1064;
      case 2:
        v835 = v921;
        if ( !*((_BYTE *)v921 + 10) || !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        for ( i14 = 0; i14 < *((signed __int16 *)v835 + 9); ++i14 )
          QDataEngine::Add_MoneyFlowDetailDataStockPaid(
            *((_BYTE *)v835 + 193 * i14 + 36),
            (char *)v835 + 193 * i14 + 20,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v835 + 193 * i14 + 20),
            1);
        CDataMgr::SendDataArriveInfoToUI(v380, *(HWND *)((char *)v921 + 6), 0x201u);
        goto LABEL_1064;
      case 3:
        goto LABEL_199;
      case 7:
        goto LABEL_317;
      case 8:
        v789 = v921;
        for ( i15 = 0; i15 < *(_DWORD *)((char *)v789 + 21); ++i15 )
          QDataEngine::Add_MoneyFlowDetailDataStockPaid(
            *((_BYTE *)v789 + 193 * i15 + 41),
            (char *)v789 + 193 * i15 + 25,
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v789 + 193 * i15 + 25),
            1);
        if ( *(_DWORD *)((char *)v921 + 6) )
          CDataMgr::SendDataArriveInfoToUI(v380, *(HWND *)((char *)v921 + 6), 0x205u);
        goto LABEL_1064;
      case 12:
        v609 = v921;
        if ( !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        v608 = 0;
        for ( i16 = 0; i16 < *((signed __int16 *)v609 + 9); ++i16 )
        {
          v606 = (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v609 + v608 + 20);
          v608 += 20 * *(unsigned __int16 *)((char *)v609 + v608 + 36) + 18;
          QDataEngine::AddAllBKMoneyFlow(v606, 1, *((unsigned __int8 *)v609 + 17));
        }
        v283 = *((signed __int16 *)v609 + 9);
        v414 = &v283;
        v312 = sub_1006A2B0(0);
        sub_102B3660(*(HWND *)((char *)v921 + 6), 0x209u, v283);
        goto LABEL_1064;
      case 13:
        v605 = v921;
        if ( !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        v283 = (int)v605 + 36;
        v282 = *((unsigned __int8 *)v605 + 17);
        HIWORD(v226) = HIWORD(v605);
        v281 = *(char **)((char *)v605 + 18);
        LOWORD(v226) = *((_WORD *)v605 + 17);
        v280 = (int *)LODWORD(v226);
        v279 = v226;
        QDataEngine::AddSBKMoneyFlow(
          *(double *)((char *)v605 + 22),
          *(float *)((char *)v605 + 30),
          LOWORD(v226),
          (int)v281,
          v282,
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v605 + 36));
        v413 = &v283;
        v311 = sub_1006A2B0(0);
        v282 = 8208;
        sub_102B3660(*(HWND *)((char *)v921 + 6), 0x2010u, v283);
        goto LABEL_1064;
      case 31:
        v604 = v921;
        if ( !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        QDataEngine::SetBKCapRankSimple(
          *((_BYTE *)v604 + 17),
          *((_BYTE *)v604 + 18),
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v604 + 19));
        v412 = &v283;
        v310 = sub_1006A2B0(0);
        sub_102B3660(*(HWND *)((char *)v921 + 6), 0x31u, v283);
        goto LABEL_1064;
      case 32:
        v603 = v921;
        if ( !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        QDataEngine::SetZCBankSimple(
          *((_BYTE *)v603 + 17),
          *((_BYTE *)v603 + 18),
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v603 + 19));
        v411 = &v283;
        v309 = sub_1006A2B0(0);
        sub_102B3660(*(HWND *)((char *)v921 + 6), 0x32u, v283);
        goto LABEL_1064;
      case 33:
        v718 = v921;
        QDataEngine::AddContributionData(
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v921 + 22),
          *(_DWORD *)((char *)v921 + 18),
          *((signed __int16 *)v921 + 2),
          *((char *)v921 + 17));
        CDataMgr::SendContriDataToUI(
          v380,
          *(HWND *)((char *)v718 + 6),
          *((signed __int16 *)v921 + 2),
          *((char *)v718 + 17),
          16);
        goto LABEL_1064;
      case 34:
        v717 = v921;
        QDataEngine::AddContributionData(
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v921 + 22),
          *(_DWORD *)((char *)v921 + 18),
          *((signed __int16 *)v921 + 2),
          *((char *)v921 + 17));
        CDataMgr::SendContriDataToUI(
          v380,
          *(HWND *)((char *)v717 + 6),
          *((signed __int16 *)v921 + 2),
          *((char *)v717 + 17),
          17);
        goto LABEL_1064;
      case 47:
        v785 = v921;
        if ( !*((_BYTE *)v921 + 10) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        if ( !CDataMgr::AddMultiBkData(
                v380,
                *(_DWORD *)((char *)v785 + 17),
                *((_BYTE *)v785 + 21),
                (char *)v785 + 27,
                *(_DWORD *)((char *)v785 + 23)) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        if ( *(_DWORD *)((char *)v785 + 6) )
          CDataMgr::SendDataArriveInfoToUI(v380, *(HWND *)((char *)v785 + 6), 0x708u);
        else
          CDataMgr::OnTimeSendBKIndexZJLToUI(v380, *((char *)v785 + 22), 1800);
        goto LABEL_1064;
      case 48:
        CGlobalEnv::GetGlobalEnv(&v601);
        LOBYTE(v925) = 81;
        v602 = v921;
        if ( !*(_DWORD *)((char *)v921 + 6) )
        {
          LOBYTE(v925) = 1;
          sub_100D5E60(&v601);
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        if ( !CDataMgr::AddMultiBkData(
                v380,
                *(_DWORD *)((char *)v602 + 17),
                *((_BYTE *)v602 + 21),
                (char *)v602 + 26,
                *(_DWORD *)((char *)v602 + 22)) )
        {
          LOBYTE(v925) = 1;
          sub_100D5E60(&v601);
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        sub_102AD840(*(HWND *)((char *)v921 + 6), 0x501u, 0x33u, 0);
        LOBYTE(v925) = 1;
        sub_100D5E60(&v601);
        goto LABEL_1064;
      case 78:
        v677 = sub_1000ED70();
        v680 = v921;
        if ( *(signed __int16 *)((char *)v921 + 17) <= 0 )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        v678 = 0;
        v679 = 0;
        v676 = 0;
        break;
      case 82:
        *(_DWORD *)&v698[1] = v921;
        v699 = 0;
        v700 = 0;
        v701 = 0;
        v702 = 0;
        v703 = 0;
        v704 = 0;
        v698[0] = 0;
        for ( i17 = 0; i17 < *(char *)(*(_DWORD *)&v698[1] + 17); ++i17 )
        {
          sub_103707B0(*(_DWORD *)(*(_DWORD *)&v698[1] + 34 * i17 + 26), &v699, (int)v698);
          QDataEngine::AddIndex_Data(v698[0], &v699, (struct _MAIJOR_INDEX2 *)(*(_DWORD *)&v698[1] + 34 * i17 + 18));
        }
        CDataMgr::SendMsgToUIs((int)v380 + 708, 0x1Au);
        goto LABEL_1064;
      case 189:
        v766 = v921;
        if ( !*((_BYTE *)v921 + 10) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        v765 = 0;
        if ( *(_DWORD *)((char *)v766 + 25) >= 0 )
          v765 = *(_DWORD *)((char *)v766 + 25);
        if ( !CDataMgr::m_bIsF1DetailPush )
        {
          v283 = QDataEngine::GetCurDateByMarket(*((char *)v766 + 17), 0);
          v282 = (int)v766 + 33;
          QDataEngine::Add_DetailData(
            (char *)v766 + 18,
            *((_BYTE *)v766 + 17),
            v765,
            *(_DWORD *)((char *)v766 + 29),
            (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v766 + 33),
            v283);
          v126 = QDataEngine::GetCurDateByMarket(*((char *)v766 + 17), 0);
          CDataMgr::PushDataSendDetailL1ToUI(v380, (char *)v766 + 18, *((_BYTE *)v766 + 17), v126);
        }
        goto LABEL_1064;
      case 195:
        v764 = v921;
        if ( !*((_BYTE *)v921 + 10) )
        {
          LOBYTE(v925) = 0;
          sub_100D5E60(&v923);
          v925 = -1;
          sub_100D5E60(&v924);
          return;
        }
        v762 = QDataEngine::GetCurDateByMarket(*((char *)v764 + 17), 0);
        v763 = QDataEngine::App_TickDataCount((char *)v764 + 18, *((_BYTE *)v764 + 17), v762);
        v283 = v762;
        v282 = (int)v764 + 45;
        QDataEngine::Add_DetailData(
          (char *)v764 + 18,
          *((_BYTE *)v764 + 17),
          v763,
          *(_DWORD *)((char *)v764 + 41),
          (struct MSG_RET_GLOBAL_HIS_TRENDLINE *)((char *)v764 + 45),
          v762);
        CDataMgr::PushDataSendDetailL1ToUI(v380, (char *)v764 + 18, *((_BYTE *)v764 + 17), v762);
        goto LABEL_1064;
      default:
        goto LABEL_1063;
    }
    while ( 1 )
    {
      if ( v676 >= *(signed __int16 *)((char *)v680 + 17) )
        goto LABEL_1064;
      v678 = (LPARAM)v921 + v679 + 19;
      v679 += *(_DWORD *)v678 + 17;
      if ( !*(_BYTE *)(v678 + 10) )
      {
        v673 = 0;
        memset(&v674, 0, 0x3FEu);
        v671 = v678;
        mfc80xU_293(&v672);
        LOBYTE(v925) = 77;
        sub_1036D2D0((LPCSTR)(v671 + 19), (int)&v672);
        LightLogger::CLogger::GetLogger(&v675, L"MultiplePkg");
        LOBYTE(v925) = 78;
        v283 = v672;
        sub_1000EBE0(&v673, L"Recv Error Package,MsgId = %d,ErrorMsg=%s", *(_WORD *)(v678 + 4));
        v206 = (LightLogger::CLogger *)unknown_libname_100(&v675);
        LightLogger::CLogger::WriteLogLine(v206, &v673, 10000);
        LOBYTE(v925) = 77;
        sub_100D5E60(&v675);
        LOBYTE(v925) = 1;
        mfc80xU_577(&v672);
        goto LABEL_586;
      }
      if ( *(_WORD *)(v678 + 4) == 3020
        || *(_WORD *)(v678 + 4) == 3021
        || *(_WORD *)(v678 + 4) == 808
        || *(_WORD *)(v678 + 4) == 804
        || *(_WORD *)(v678 + 4) == 802
        || *(_WORD *)(v678 + 4) == 819
        || *(_WORD *)(v678 + 4) == 817
        || *(_WORD *)(v678 + 4) == 8103 )
      {
        CGlobalEnv::GetGlobalEnv(&v670);
        if ( unknown_libname_100(&v670) && *(_DWORD *)(unknown_libname_100(&v670) + 140) )
        {
          v283 = v678;
          v282 = 0;
          v281 = (char *)6026;
          v207 = *(_DWORD *)(unknown_libname_100(&v670) + 140);
          sub_1000E960(0x178Au, 0, v283);
        }
        sub_100D5E60(&v670);
      }
      v317 = *(signed __int16 *)(v678 + 4);
      if ( v317 > 718 )
      {
        if ( v317 > 3020 )
        {
          switch ( v317 )
          {
            case 3021:
              v616 = (struct MSG_RET_TRENDLINE *)v678;
              if ( v678 && *((_BYTE *)v616 + 10) )
                CDataMgr::ProcStkTrendCfs(v380, v616);
              break;
            case 8103:
              v613 = (struct _MSG_RET_QUOTE_RT_GLOBAL_MARKET *)v678;
              if ( v678 && *((_BYTE *)v613 + 10) )
                CDataMgr::ProcGlobalStkTrend(v380, v613);
              break;
            case 8104:
              v612 = (struct _MSG_RET_QUOTE_MINKLINE_GLOBAL_MARKET *)v678;
              if ( v678 && *((_BYTE *)v612 + 10) )
                CDataMgr::ProcGlobalStkKLine(v380, v612);
              break;
            default:
LABEL_759:
              v283 = v678;
              v282 = *(signed __int16 *)(v678 + 4);
              v224 = *(_DWORD *)((char *)v380 + 1106);
              sub_103953C0(v282, v678);
              break;
          }
        }
        else if ( v317 == 3020 )
        {
          v617 = (struct MSG_RET_TRENDLINE *)v678;
          if ( v678 && *((_BYTE *)v617 + 10) )
            CDataMgr::ProcStkTrend(v380, v617);
        }
        else
        {
          v317 -= 725;
          switch ( v317 )
          {
            case 0:
              CDataMgr::ProcPushOptionQuote(v380, (struct MSG_RET_PUSH_OPTION_QUOTE *)v678);
              break;
            case 6:
              CDataMgr::ProcStkOptionQuoteTable(
                v380,
                (struct MSG_RET_PUSH_STK_OPTION_QUOTE_TABLE *)v678,
                *(signed __int16 *)(v678 + 4));
              goto LABEL_757;
            case 12:
              v669 = v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                for ( i18 = 0; i18 < *(char *)(v669 + 17); ++i18 )
                  sub_10105700(*(HWND *)(v669 + 6), v669 + 210 * i18 + 18, 0);
              }
              break;
            case 77:
              v634 = (struct MSG_RET_L2QUOTE_PRICEORDER *)v678;
              if ( *(_DWORD *)v678 > 0 && *((_BYTE *)v634 + 10) )
                CDataMgr::ProcWeiTuoAndSendToUI(v380, v634);
              break;
            case 78:
              *(_DWORD *)&v626[1] = v678;
              if ( v678 )
              {
                if ( *(_BYTE *)(*(_DWORD *)&v626[1] + 10) )
                {
                  v627 = 0;
                  v628 = 0;
                  v629 = 0;
                  v630 = 0;
                  v631 = 0;
                  v632 = 0;
                  v626[0] = 0;
                  sub_1036FDF0(*(_DWORD *)(*(_DWORD *)&v626[1] + 17), &v627, (int)v626);
                  if ( QDataEngine::AddOrderQueueData(
                         v626[0],
                         &v627,
                         (struct RET_ITEM_ORDER_QUEUE *)(*(_DWORD *)&v626[1] + 22),
                         *(_BYTE *)(*(_DWORD *)&v626[1] + 21)) )
                  {
                    if ( *((_BYTE *)v380 + 706) )
                      CDataMgr::SendOrderListToUI(v380, *(HWND *)((char *)v380 + 702));
                  }
                }
              }
              break;
            case 79:
              v633 = (struct MSG_RET_L2QUOTE_TRANSACTION *)v678;
              if ( *(_BYTE *)(v678 + 10) && *(_DWORD *)v633 >= 1 )
                CDataMgr::ProcTradeDetailAndSendToUI(v380, v633);
              break;
            case 83:
              v625 = v678;
              if ( v678 && *(_BYTE *)(v625 + 10) )
              {
                CGlobalEnv::GetGlobalEnv(&v624);
                LOBYTE(v925) = 79;
                v416 = mfc80xU_762(28);
                if ( v416 )
                  v316 = sub_1006A4F0(v416);
                else
                  v316 = 0;
                v417 = v316;
                sub_100D75D0(v316);
                LOBYTE(v925) = 80;
                if ( (unsigned __int8)CDataMgr::ProcT0MoneyFlowData(v625, &v623) )
                {
                  EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 242));
                  for ( i19 = 0; ; ++i19 )
                  {
                    v218 = sub_1003EF10((char *)v380 + 649);
                    if ( i19 >= v218 )
                      break;
                    v315 = unknown_libname_100(&v624);
                    v219 = unknown_libname_100(&v623);
                    v621 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v315 + 36))(v315, v219);
                    v283 = v621;
                    v220 = (HWND *)sub_1010DCD0(i19);
                    sub_102AD840(*v220, 0x501u, 0x2011u, v283);
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 242));
                  EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 266));
                  for ( i20 = 0; ; ++i20 )
                  {
                    v221 = sub_1003EF10((char *)v380 + 665);
                    if ( i20 >= v221 )
                      break;
                    v314 = unknown_libname_100(&v624);
                    v222 = unknown_libname_100(&v623);
                    v619 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v314 + 36))(v314, v222);
                    v283 = v619;
                    v223 = (HWND *)sub_1010DCD0(i20);
                    sub_102AD840(*v223, 0x501u, 0xEu, v283);
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 266));
                  LOBYTE(v925) = 79;
                  sub_100D5E60(&v623);
                  LOBYTE(v925) = 1;
                  sub_100D5E60(&v624);
                }
                else
                {
                  LOBYTE(v925) = 79;
                  sub_100D5E60(&v623);
                  LOBYTE(v925) = 1;
                  sub_100D5E60(&v624);
                }
              }
              break;
            case 87:
              v667 = v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                v661 = 0;
                v662 = 0;
                v663 = 0;
                v664 = 0;
                v665 = 0;
                v666 = 0;
                LOBYTE(v660) = 0;
                sub_10086E10((char *)&v660 + 1);
                if ( *(_DWORD *)(v667 + 6) )
                {
                  for ( i21 = 0; i21 < *(char *)(v667 + 17); ++i21 )
                  {
                    sub_1036FDF0(*(_DWORD *)(v667 + 178 * i21 + 18), &v661, (int)&v660);
                    memcpy((char *)&v660 + 1, (const void *)(v667 + 178 * i21 + 18), 0xB2u);
                    QDataEngine::AddSpGZQH_Dyn(v660, &v661, (struct SNAPSHOT_GZQH *)((char *)&v660 + 1));
                  }
                  CDataMgr::SendMsgToUI(v380, *(HWND *)(v667 + 6), 0x25u);
                }
                else
                {
                  EnterCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 122));
                  if ( (unsigned int)unknown_libname_95((char *)v380 + 756) >= 1 )
                  {
                    for ( i22 = 0; i22 < *(char *)(v667 + 17); ++i22 )
                    {
                      sub_1036FDF0(*(_DWORD *)(v667 + 178 * i22 + 18), &v661, (int)&v660);
                      v656 = 178;
                      memcpy((char *)&v660 + 1, (const void *)(v667 + 178 * i22 + 18), 0xB2u);
                      QDataEngine::AddSpGZQH_Dyn(v660, &v661, (struct SNAPSHOT_GZQH *)((char *)&v660 + 1));
                      v657 = sub_1036FDD0(&v661, v660);
                      if ( v657 != -1 )
                      {
                        sub_100F4EF0(&v655, &v657);
                        v208 = (_DWORD *)sub_101298A0(&v423);
                        if ( !sub_100D2530(&v655, v208) )
                        {
                          v209 = sub_100F5BE0(&v655);
                          sub_1012BF80((_DWORD *)(v209 + 4), (int)&v654);
                          while ( 1 )
                          {
                            sub_100F5BE0(&v655);
                            v210 = sub_101489C0(&v421);
                            if ( !(unsigned __int8)sub_100D23C0(&v654, v210) )
                              break;
                            v211 = (HWND *)sub_10035540(&v654);
                            CDataMgr::SendMsgToUI(v380, *v211, 0x25u);
                            sub_10081D50(&v422, 0);
                          }
                        }
                      }
                    }
                    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 122));
                  }
                  else
                  {
                    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)v380 + 122));
                  }
                }
              }
              break;
            case 91:
              v618 = (struct MSG_RET_L2QUOTE_RATIOPRICE *)v678;
              CDataMgr::SendRatioPriceToUI(v380, *(HWND *)(v678 + 6), (struct MSG_RET_L2QUOTE_RATIOPRICE *)v678);
              break;
            case 92:
              v614 = (struct MSG_RET_MULTI_L2_QUOTE *)v678;
              if ( !v678 || *((char *)v614 + 10) < 1 )
              {
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              CDataMgr::ProcHundredsL2Quote(v380, v614);
              break;
            case 94:
              v615 = (struct MSG_RET_MULTI_L2_QUOTE *)v678;
              if ( !v678 || *((char *)v615 + 10) < 1 )
              {
                LOBYTE(v925) = 0;
                sub_100D5E60(&v923);
                v925 = -1;
                sub_100D5E60(&v924);
                return;
              }
              CDataMgr::ProcStkMultiL2Quote(v380, v615);
              break;
            case 95:
              CDataMgr::ProcProbUpData(v380, (struct MSG_RET_QUOTE_PROBABILITY_UP *)v678);
              break;
            case 96:
              CDataMgr::ProcProbUpDaysData(v380, (struct MSG_RET_QUOTE_PROB_UP_DAYS *)v678);
              break;
            case 97:
              CDataMgr::ProcHisProbUpData(v380, (struct MSG_RET_QUOTE_PROB_UP_HIS *)v678);
              break;
            default:
              goto LABEL_759;
          }
        }
      }
      else
      {
        if ( v317 == 718 )
        {
LABEL_757:
          CDataMgr::ProcBkStkQuoteTable(
            v380,
            (struct MSG_RET_PUSH_BK_STK_QUOTE_TABLE *)v678,
            *(signed __int16 *)(v678 + 4));
          goto LABEL_586;
        }
        if ( v317 > 30 )
        {
          switch ( v317 )
          {
            case 370:
              v635 = (struct MSG_RET_BK_BASIC_INFO *)v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                QDataEngine::AddBKIndexZJLInfo(v635);
                if ( *(_DWORD *)((char *)v635 + 6) )
                  CDataMgr::SendDataArriveInfoToUI(v380, *(HWND *)((char *)v635 + 6), 0x708u);
                else
                  CDataMgr::OnTimeSendBKIndexZJLToUI(v380, *(_DWORD *)((char *)v635 + 17), 1800);
              }
              break;
            case 512:
              v653 = v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                v652 = 0;
                if ( *(_DWORD *)(v653 + 25) >= 0 )
                  v652 = *(_DWORD *)(v653 + 25);
                if ( !CDataMgr::m_bIsF1DetailPush )
                {
                  v212 = QDataEngine::GetCurDateByMarket(*(char *)(v653 + 17), 0);
                  v282 = v653 + 33;
                  QDataEngine::Add_DetailData(
                    (char *)(v653 + 18),
                    *(_BYTE *)(v653 + 17),
                    v652,
                    *(_DWORD *)(v653 + 29),
                    (struct DETAILREC *)(v653 + 33),
                    v212);
                  v213 = QDataEngine::GetCurDateByMarket(*(char *)(v653 + 17), 0);
                  CDataMgr::PushDataSendDetailL1ToUI(v380, (char *)(v653 + 18), *(_BYTE *)(v653 + 17), v213);
                }
              }
              break;
            case 518:
              v651 = v678;
              if ( !*(_BYTE *)(v678 + 10) )
                break;
              v214 = QDataEngine::GetCurDateByMarket(*(char *)(v651 + 17), 0);
              v649 = QDataEngine::App_TickDataCount((char *)(v651 + 18), *(_BYTE *)(v651 + 17), v214);
              v650 = 0;
              v648 = 0;
              if ( (signed int)v649 <= 0 )
              {
                v648 = 0;
LABEL_672:
                v283 = QDataEngine::GetCurDateByMarket(*(char *)(v651 + 17), 0);
                QDataEngine::Add_DetailData(
                  (char *)(v651 + 18),
                  *(_BYTE *)(v651 + 17),
                  v648,
                  *(_DWORD *)(v651 + 41) - v650,
                  (struct DETAILREC *)(v651 + 14 * v650 + 45),
                  v283);
                v217 = QDataEngine::GetCurDateByMarket(*(char *)(v651 + 17), 0);
                CDataMgr::PushDataSendDetailL1ToUI(v380, (char *)(v651 + 18), *(_BYTE *)(v651 + 17), v217);
                break;
              }
              v648 = v649;
              v420 = (struct DETAILREC *)mfc80xU_265(14 * v649 | -(14 * (unsigned __int64)v649 >> 32 != 0));
              v647 = v420;
              if ( !v420 )
                break;
              v215 = QDataEngine::GetCurDateByMarket(*(char *)(v651 + 17), 0);
              QDataEngine::App_TickData((char *)(v651 + 18), *(_BYTE *)(v651 + 17), v647, v649, v215);
              v646 = *((char *)v647 + 14 * (v649 - 1) + 2)
                   + 100 * *((char *)v647 + 14 * (v649 - 1) + 1)
                   + 10000 * *((char *)v647 + 14 * (v649 - 1));
              for ( i23 = 0; i23 < *(_DWORD *)(v651 + 41); ++i23 )
              {
                v644 = *(char *)(v651 + 14 * i23 + 47)
                     + 100 * *(char *)(v651 + 14 * i23 + 46)
                     + 10000 * *(char *)(v651 + 14 * i23 + 45);
                if ( v644 == v646 )
                {
                  --v648;
                  for ( i24 = v649 - 2;
                        i24 >= 0
                     && (v648 & 0x80000000) == 0
                     && *((char *)v647 + 14 * i24 + 2)
                      + 100 * *((char *)v647 + 14 * i24 + 1)
                      + 10000 * *((char *)v647 + 14 * i24) == v646;
                        --i24 )
                  {
                    --v648;
                  }
                }
                if ( v644 >= v646 )
                  break;
                ++v650;
              }
              if ( *(_DWORD *)(v651 + 41) - v650 > 0 )
              {
                if ( v647 )
                {
                  v418 = v647;
                  mfc80xU_266(v647);
                  v647 = 0;
                }
                goto LABEL_672;
              }
              v216 = QDataEngine::GetCurDateByMarket(*(char *)(v651 + 17), 0);
              CDataMgr::PushDataSendDetailL1ToUI(v380, (char *)(v651 + 18), *(_BYTE *)(v651 + 17), v216);
              if ( v647 )
              {
                v419 = v647;
                mfc80xU_266(v647);
                v647 = 0;
              }
              break;
            default:
              goto LABEL_759;
          }
        }
        else
        {
          switch ( v317 )
          {
            case 30:
              v639 = v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                if ( *(_BYTE *)(v639 + 17) )
                {
                  QDataEngine::SetRankList(2, 1, (struct RANK_FLOAT *)(v639 + 19));
                  QDataEngine::SetRankList(2, 4, (struct RANK_FLOAT *)(v639 + 659));
                  QDataEngine::SetRankList(17, 1, (struct RANK_FLOAT *)(v639 + 1299));
                  QDataEngine::SetRankList(17, 4, (struct RANK_FLOAT *)(v639 + 1939));
                }
                else
                {
                  QDataEngine::SetRankList(2, 0, (struct RANK_FLOAT *)(v639 + 19));
                  QDataEngine::SetRankList(2, 3, (struct RANK_FLOAT *)(v639 + 659));
                  QDataEngine::SetRankList(17, 0, (struct RANK_FLOAT *)(v639 + 1299));
                  QDataEngine::SetRankList(17, 3, (struct RANK_FLOAT *)(v639 + 1939));
                }
                QDataEngine::SaveRankList();
                if ( *(_DWORD *)(v639 + 6) )
                  CDataMgr::SendRankUpDownToUI(v380, *(HWND *)(v639 + 6), *(_BYTE *)(v639 + 17));
                else
                  CDataMgr::OnTimeSendRankUpDownToUI(v380, *(_BYTE *)(v639 + 17));
              }
              break;
            case 11:
              v642 = v678;
              v641 = *(_DWORD *)(v678 + 13) == 1;
              if ( *(_BYTE *)(v678 + 10) )
                sub_10105FE0(*(HWND *)(v642 + 6), v642 + 17, v641);
              break;
            case 13:
              v638 = v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                sub_10086DB0(&v637);
                for ( i25 = 0; i25 < *(signed __int16 *)(v638 + 17); ++i25 )
                {
                  sub_10105F60(&v637, v638 + 194 * i25 + 19);
                  QDataEngine::Add_DynamicDataStock(
                    *(_BYTE *)(v638 + 194 * i25 + 19),
                    (char *)(v638 + 194 * i25 + 24),
                    (struct _QUOTEREC *)&v637);
                }
                CDataMgr::SendRecordDataToUI(v380, *(HWND *)(v638 + 6), 0x702u);
              }
              break;
            case 22:
              v640 = v678;
              if ( *(_BYTE *)(v678 + 10) )
              {
                QDataEngine::SetRankList(*(char *)(v640 + 17), 0, (struct RANK_FLOAT *)(v640 + 18));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 1, (struct RANK_FLOAT *)(v640 + 1298));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 3, (struct RANK_FLOAT *)(v640 + 658));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 4, (struct RANK_FLOAT *)(v640 + 1938));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 5, (struct RANK_FLOAT *)(v640 + 5138));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 6, (struct RANK_FLOAT *)(v640 + 2578));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 7, (struct RANK_FLOAT *)(v640 + 3858));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 2, (struct RANK_FLOAT *)(v640 + 4498));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 9, (struct RANK_FLOAT *)(v640 + 3218));
                QDataEngine::SetRankList(*(char *)(v640 + 17), 8, (struct RANK_FLOAT *)(v640 + 5778));
                QDataEngine::SaveRankList();
                CDataMgr::SendRankToUI(v380, *(HWND *)(v640 + 6), *(char *)(v640 + 17));
              }
              break;
            default:
              goto LABEL_759;
          }
        }
      }
LABEL_586:
      ++v676;
    }
  }
LABEL_199:
  v853 = v921;
  if ( !*((_BYTE *)v921 + 10) || *(_DWORD *)v853 < 1 || !*(_DWORD *)((char *)v921 + 6) )
  {
    LOBYTE(v925) = 0;
    sub_100D5E60(&v923);
    v925 = -1;
    sub_100D5E60(&v924);
    return;
  }
  if ( *((_BYTE *)v853 + 21) == 2 )
    sub_10128E30((char *)v380 + 569);
  v852 = 0;
  v283 = (int)&v852;
  if ( !CDataMgr::PreProcMoneyRankData(
          v380,
          *(_DWORD *)((char *)v853 + 17),
          *((_BYTE *)v853 + 21),
          (char *)v853 + 27,
          *(_DWORD *)((char *)v853 + 23),
          &v852) )
  {
    LOBYTE(v925) = 0;
    sub_100D5E60(&v923);
    v925 = -1;
    sub_100D5E60(&v924);
    return;
  }
  v283 = v852;
  v282 = 512;
  v281 = (char *)1281;
  v280 = *(int **)((char *)v921 + 6);
  v79 = CDataMgr::GetReceiverSafeHandle(v380);
  CViewManager::PostExDataMessage(v79, (unsigned int)v280, 0x501u, 0x200u, v283);
LABEL_1064:
  LOBYTE(v925) = 0;
  sub_100D5E60(&v923);
  v925 = -1;
  sub_100D5E60(&v924);
}