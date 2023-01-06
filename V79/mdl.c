/*(Wed Dec 21 11:09:17 2022) From Only-Econ.mdl - C equations for the model */

#define _VDFX
#define VDFX


#include "vensim.h"
typedef struct tag_workspace {COMPREAL temp0 ; COMPREAL temp1 ; COMPREAL temp2 ; 
COMPREAL temp3 ; COMPREAL temp4 ; COMPREAL temp5 ; COMPREAL temp6 ; 
COMPREAL temp7 ; COMPREAL temp8 ; COMPREAL temp9 ; COMPREAL temp10 ; 
COMPREAL temp11 ; COMPREAL temp12 ; COMPREAL temp13 ; COMPREAL temp14 ; 
COMPREAL temp15 ; COMPREAL temp16 ; COMPREAL temp17 ; COMPREAL temp18 ; 
COMPREAL temp19 ; COMPREAL temp20 ; COMPREAL temp21 ; COMPREAL temp22 ; 
COMPREAL temp23 ; COMPREAL temp24 ; COMPREAL temp25 ; COMPREAL temp26 ; 
COMPREAL temp27 ; COMPREAL temp28 ; COMPREAL temp29 ; COMPREAL temp30 ; 
COMPREAL temp31 ; COMPREAL temp32 ; COMPREAL temp33 ; COMPREAL temp34 ; 
COMPREAL temp35 ; COMPREAL temp36 ; COMPREAL temp37 ; COMPREAL temp38 ; 
COMPREAL temp39 ; COMPREAL temp40 ; COMPREAL temp41 ; COMPREAL temp42 ; 
COMPREAL temp43 ; COMPREAL temp44 ; COMPREAL temp45 ; COMPREAL temp46 ; 
COMPREAL temp47 ; COMPREAL temp48 ; COMPREAL temp49 ; COMPREAL temp50 ; 
COMPREAL temp51 ; COMPREAL temp52 ; COMPREAL temp53 ; COMPREAL temp54 ; 
COMPREAL temp55 ; COMPREAL temp56 ; COMPREAL temp57 ; COMPREAL temp58 ; 
COMPREAL temp59 ; COMPREAL temp60 ; COMPREAL temp61 ; COMPREAL temp62 ; 
COMPREAL temp63 ; COMPREAL temp64 ; COMPREAL temp65 ; COMPREAL temp66 ; 
COMPREAL temp67 ; COMPREAL temp68 ; COMPREAL temp69 ; COMPREAL temp70 ; 
COMPREAL temp71 ; COMPREAL temp72 ; COMPREAL temp73 ; COMPREAL temp74 ; 
COMPREAL temp75 ; COMPREAL temp76 ; COMPREAL temp77 ; COMPREAL temp78 ; 
COMPREAL temp79 ; COMPREAL temp80 ; COMPREAL temp81 ; COMPREAL temp82 ; 
COMPREAL temp83 ; COMPREAL temp84 ; COMPREAL temp85 ; COMPREAL temp86 ; 
COMPREAL temp87 ; COMPREAL temp88 ; COMPREAL temp89 ; COMPREAL temp90 ; 
COMPREAL temp91 ; COMPREAL temp92 ; COMPREAL temp93 ; COMPREAL temp94 ; 
COMPREAL temp95 ; COMPREAL temp96 ; COMPREAL temp97 ; COMPREAL temp98 ; 
COMPREAL temp99 ; COMPREAL temp100 ; COMPREAL temp101 ; COMPREAL temp102 ; 
COMPREAL temp103 ; COMPREAL temp104 ; COMPREAL temp105 ; COMPREAL temp106 ; 
COMPREAL temp107 ; COMPREAL temp108 ; COMPREAL temp109 ; COMPREAL temp110 ; 
COMPREAL temp111 ; COMPREAL temp112 ; COMPREAL temp113 ; COMPREAL temp114 ; 
COMPREAL temp115 ; COMPREAL temp116 ; COMPREAL temp117 ; COMPREAL temp118 ; 
COMPREAL temp119 ; COMPREAL temp120 ; COMPREAL temp121 ; COMPREAL temp122 ; 
COMPREAL temp123 ; COMPREAL temp124 ; COMPREAL temp125 ; COMPREAL temp126 ; 
COMPREAL temp127 ; COMPREAL temp128 ; COMPREAL temp129 ; COMPREAL temp130 ; 
COMPREAL temp131 ; 
int sumind0 ; int forind0 ; 
int sumind1 ; int forind1 ; 

int sumind2 ; int forind2 ; 
int sumind3 ; int forind3 ; 
int sumind4 ; 
int forind4 ; 
int sumind5 ; int forind5 ; 
int sumind6 ; int forind6 ; 

int sumind7 ; int forind7 ; 
int simultid ; 
} WORKSPACE;
#define wrk ((WORKSPACE*)(VGV->workspace))

#define temp0 wrk->temp0
#define temp1 wrk->temp1
#define temp2 wrk->temp2
#define temp3 wrk->temp3
#define temp4 wrk->temp4
#define temp5 wrk->temp5
#define temp6 wrk->temp6
#define temp7 wrk->temp7
#define temp8 wrk->temp8
#define temp9 wrk->temp9
#define temp10 wrk->temp10
#define temp11 wrk->temp11
#define temp12 wrk->temp12
#define temp13 wrk->temp13
#define temp14 wrk->temp14
#define temp15 wrk->temp15
#define temp16 wrk->temp16
#define temp17 wrk->temp17
#define temp18 wrk->temp18
#define temp19 wrk->temp19
#define temp20 wrk->temp20
#define temp21 wrk->temp21
#define temp22 wrk->temp22
#define temp23 wrk->temp23
#define temp24 wrk->temp24
#define temp25 wrk->temp25
#define temp26 wrk->temp26
#define temp27 wrk->temp27
#define temp28 wrk->temp28
#define temp29 wrk->temp29
#define temp30 wrk->temp30
#define temp31 wrk->temp31
#define temp32 wrk->temp32
#define temp33 wrk->temp33
#define temp34 wrk->temp34
#define temp35 wrk->temp35
#define temp36 wrk->temp36
#define temp37 wrk->temp37
#define temp38 wrk->temp38
#define temp39 wrk->temp39
#define temp40 wrk->temp40
#define temp41 wrk->temp41
#define temp42 wrk->temp42
#define temp43 wrk->temp43
#define temp44 wrk->temp44
#define temp45 wrk->temp45
#define temp46 wrk->temp46
#define temp47 wrk->temp47
#define temp48 wrk->temp48
#define temp49 wrk->temp49
#define temp50 wrk->temp50
#define temp51 wrk->temp51
#define temp52 wrk->temp52
#define temp53 wrk->temp53
#define temp54 wrk->temp54
#define temp55 wrk->temp55
#define temp56 wrk->temp56
#define temp57 wrk->temp57
#define temp58 wrk->temp58
#define temp59 wrk->temp59
#define temp60 wrk->temp60
#define temp61 wrk->temp61
#define temp62 wrk->temp62
#define temp63 wrk->temp63
#define temp64 wrk->temp64
#define temp65 wrk->temp65
#define temp66 wrk->temp66
#define temp67 wrk->temp67
#define temp68 wrk->temp68
#define temp69 wrk->temp69
#define temp70 wrk->temp70
#define temp71 wrk->temp71
#define temp72 wrk->temp72
#define temp73 wrk->temp73
#define temp74 wrk->temp74
#define temp75 wrk->temp75
#define temp76 wrk->temp76
#define temp77 wrk->temp77
#define temp78 wrk->temp78
#define temp79 wrk->temp79
#define temp80 wrk->temp80
#define temp81 wrk->temp81
#define temp82 wrk->temp82
#define temp83 wrk->temp83
#define temp84 wrk->temp84
#define temp85 wrk->temp85
#define temp86 wrk->temp86
#define temp87 wrk->temp87
#define temp88 wrk->temp88
#define temp89 wrk->temp89
#define temp90 wrk->temp90
#define temp91 wrk->temp91
#define temp92 wrk->temp92
#define temp93 wrk->temp93
#define temp94 wrk->temp94
#define temp95 wrk->temp95
#define temp96 wrk->temp96
#define temp97 wrk->temp97
#define temp98 wrk->temp98
#define temp99 wrk->temp99
#define temp100 wrk->temp100
#define temp101 wrk->temp101
#define temp102 wrk->temp102
#define temp103 wrk->temp103
#define temp104 wrk->temp104
#define temp105 wrk->temp105
#define temp106 wrk->temp106
#define temp107 wrk->temp107
#define temp108 wrk->temp108
#define temp109 wrk->temp109
#define temp110 wrk->temp110
#define temp111 wrk->temp111
#define temp112 wrk->temp112
#define temp113 wrk->temp113
#define temp114 wrk->temp114
#define temp115 wrk->temp115
#define temp116 wrk->temp116
#define temp117 wrk->temp117
#define temp118 wrk->temp118
#define temp119 wrk->temp119
#define temp120 wrk->temp120
#define temp121 wrk->temp121
#define temp122 wrk->temp122
#define temp123 wrk->temp123
#define temp124 wrk->temp124
#define temp125 wrk->temp125
#define temp126 wrk->temp126
#define temp127 wrk->temp127
#define temp128 wrk->temp128
#define temp129 wrk->temp129
#define temp130 wrk->temp130
#define temp131 wrk->temp131
#define sumind0 wrk->sumind0
#define forind0 wrk->forind0
#define sumind1 wrk->sumind1
#define forind1 wrk->forind1
#define sumind2 wrk->sumind2
#define forind2 wrk->forind2
#define sumind3 wrk->sumind3
#define forind3 wrk->forind3
#define sumind4 wrk->sumind4
#define forind4 wrk->forind4
#define sumind5 wrk->sumind5
#define forind5 wrk->forind5
#define sumind6 wrk->sumind6
#define forind6 wrk->forind6
#define sumind7 wrk->sumind7
#define forind7 wrk->forind7
#define simultid wrk->simultid


#include "simext.c"
static int sub0[]  /* Rgn */ = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,
37,38,39,40,41,42,43,44,45,46,47,48,49,50,-1} ;
static int sub1[]  /* Vs */ = {0,1,2,-1} ;
#ifndef LINKEXTERN
#endif
unsigned char *mdl_desc()
{
return("(Wed Dec 21 11:09:17 2022) From Only-Econ.mdl") ;
}

/* compute the model rates */
void mdl_func0(GLOB_VARS *VGV)
{double temp[10];
VGV->RATE[0] = 1.0 ;/* this is time */
/* #Infected Individuals (I)>SMOOTH# */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1+sub0[forind0]*1) ;
  VGV->RATE[1+sub0[forind0]*1] = (VGV->LEVEL[2772+sub0[forind0]*1]
-VGV->LEVEL[1+sub0[forind0]*1])/VGV->LEVEL[1434] ;
} /* #Infected Individuals (I)>SMOOTH# */

/* Accumulated GDP Losses */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 52+sub0[forind0]*1) ;
  VGV->RATE[52+sub0[forind0]*1] = VGV->LEVEL[818+sub0[forind0]*1] ;
} /* Accumulated GDP Losses */

/* Cumulated NPGDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 103+sub0[forind0]*1) ;
  VGV->RATE[103+sub0[forind0]*1] = VGV->LEVEL[1796+sub0[forind0]*1
]-VGV->LEVEL[1128+sub0[forind0]*1] ;
} /* Cumulated NPGDP */

/* Cumulative APE */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 154+sub0[forind0]*1) ;
  VGV->RATE[154+sub0[forind0]*1] = VGV->LEVEL[716+sub0[forind0]*1]
 ;
} /* Cumulative APE */

/* Cumulative Error */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 205+sub0[forind0]*1) ;
  VGV->RATE[205+sub0[forind0]*1] = VGV->LEVEL[767+sub0[forind0]*1]
 ;
} /* Cumulative Error */

/* Current GDP Output Gap (y) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 256+sub0[forind0]*1) ;
  VGV->RATE[256+sub0[forind0]*1] = VGV->LEVEL[922+sub0[forind0]*1]
+VGV->LEVEL[2310+sub0[forind0]*1]-VGV->LEVEL[1848+sub0[forind0]*1]
 ;
} /* Current GDP Output Gap (y) */

/* Data Count */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 307+sub0[forind0]*1) ;
  VGV->RATE[307+sub0[forind0]*1] = VGV->LEVEL[665+sub0[forind0]*1]
 ;
} /* Data Count */

/* Non Economic Mitigation (lt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 358+sub0[forind0]*1) ;
  VGV->RATE[358+sub0[forind0]*1] = VGV->LEVEL[1641+sub0[forind0]*1
]-VGV->LEVEL[1538+sub0[forind0]*1] ;
} /* Non Economic Mitigation (lt) */

/* Non Pandemic GDP (xt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 409+sub0[forind0]*1) ;
  VGV->RATE[409+sub0[forind0]*1] = VGV->LEVEL[1230+sub0[forind0]*1
] ;
} /* Non Pandemic GDP (xt) */

/* Quarter Length */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 460+sub0[forind0]*1) ;
  VGV->RATE[460+sub0[forind0]*1] = VGV->LEVEL[511+sub0[forind0]*1]
-VGV->LEVEL[1179+sub0[forind0]*1] ;
} /* Quarter Length */

} /* comp_rate */

/* compute the delays */
void mdl_func1(GLOB_VARS *VGV)
{double temp[10];
} /* comp_delay */

/* initialize time */
void mdl_func2(GLOB_VARS *VGV)
{ double temp[10]; 
 if (!VGV->workspace) VGV->workspace = (*VGV->alloc_simmem)(0,0,sizeof(WORKSPACE)); 
 vec_arglist_init(VGV);
VGV->LEVEL[0] = VGV->LEVEL[1486] ;
} /* init_time */

/* initialize time step */
void mdl_func3(GLOB_VARS *VGV)
{double temp[10];
/* a constant no need to do anything */
} /* init_tstep */

/* State variable initial value computation*/
void mdl_func4(GLOB_VARS *VGV)
{double temp[10];
/* #Infected Individuals (I)>SMOOTH# */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1+sub0[forind0]*1) ;
  VGV->LEVEL[1+sub0[forind0]*1] = VGV->LEVEL[2772+sub0[forind0]*1]
 ;
}
/* Accumulated GDP Losses */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 52+sub0[forind0]*1) ;
  VGV->LEVEL[52+sub0[forind0]*1] = 0 ;
}
/* Non Pandemic GDP (xt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 409+sub0[forind0]*1) ;
  VGV->LEVEL[409+sub0[forind0]*1] = VGV->LEVEL[2361+sub0[forind0]*1
] ;
}
/* Current GDP Output Gap (y) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 256+sub0[forind0]*1) ;
  VGV->LEVEL[256+sub0[forind0]*1] = VGV->LEVEL[1435+sub0[forind0]*1
] ;
}
/* Predicted GDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2206+sub0[forind0]*1) ;
  VGV->LEVEL[2206+sub0[forind0]*1] = VGV->LEVEL[409+sub0[forind0]*1
]-VGV->LEVEL[256+sub0[forind0]*1] ;
}
/* Cumulated NPGDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 103+sub0[forind0]*1) ;
  VGV->LEVEL[103+sub0[forind0]*1] = VGV->LEVEL[2206+sub0[forind0]*1
] ;
}
/* Cumulative APE */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 154+sub0[forind0]*1) ;
  VGV->LEVEL[154+sub0[forind0]*1] = 0 ;
}
/* Cumulative Error */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 205+sub0[forind0]*1) ;
  VGV->LEVEL[205+sub0[forind0]*1] = 0 ;
}
/* Data Count */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 307+sub0[forind0]*1) ;
  VGV->LEVEL[307+sub0[forind0]*1] = 0 ;
}
/* Non Economic Mitigation (lt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 358+sub0[forind0]*1) ;
  VGV->LEVEL[358+sub0[forind0]*1] = 0 ;
}
/* Quarter Length */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 460+sub0[forind0]*1) ;
  VGV->LEVEL[460+sub0[forind0]*1] = 1.000000 ;
}
} /* comp_init */

/* State variable re-initial value computation*/
void mdl_func5(GLOB_VARS *VGV)
{double temp[10];
} /* comp_reinit */

/*  Active Time Step Equation */
void mdl_func6(GLOB_VARS *VGV)
{double temp[10];
} /* comp_tstep */
/*  Auxiliary variable equations*/
void mdl_func7(GLOB_VARS *VGV)
{double temp[10];
/* Reported Cumulated GDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2412+sub0[forind0]*1) ;
  VGV->LEVEL[2412+sub0[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[2361+sub0[forind0]
*1]!=NA,VGV->LEVEL[103+sub0[forind0]*1]/VGV->LEVEL[460+sub0[forind0]
*1],NA) ;
}
/* Error (E) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1076+sub0[forind0]*1) ;
  VGV->LEVEL[1076+sub0[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[2361+sub0[forind0]
*1]!=NA,VGV->LEVEL[2412+sub0[forind0]*1]-VGV->LEVEL[2361+sub0[forind0]
*1],0) ;
}
/* Absolute Error */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 562+sub0[forind0]*1) ;
  VGV->LEVEL[562+sub0[forind0]*1] = ABS(VGV->LEVEL[1076+sub0[forind0]
*1]) ;
}
/* Counter */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 665+sub0[forind0]*1) ;
  VGV->LEVEL[665+sub0[forind0]*1] = ZIDZ(0,VGV->LEVEL[1076+sub0[forind0]
*1],VGV->LEVEL[1076+sub0[forind0]*1])/VGV->LEVEL[2618] ;
}
/* Current APE */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 716+sub0[forind0]*1) ;
  VGV->LEVEL[716+sub0[forind0]*1] = ABS(VGV->LEVEL[1076+sub0[forind0]
*1])/VGV->LEVEL[2361+sub0[forind0]*1]*100.000000/VGV->LEVEL[2618] ;
}
/* Current Error */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 767+sub0[forind0]*1) ;
  VGV->LEVEL[767+sub0[forind0]*1] = VGV->LEVEL[1076+sub0[forind0]*1
]/VGV->LEVEL[2618] ;
}
/* Daily GDP Gap */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 818+sub0[forind0]*1) ;
  VGV->LEVEL[818+sub0[forind0]*1] = VGV->LEVEL[256+sub0[forind0]*1
]/VGV->LEVEL[920] ;
}
/* Daily Growth Rate */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 869+sub0[forind0]*1) ;
  VGV->LEVEL[869+sub0[forind0]*1] = POWER((1.000000+VGV->LEVEL[1281
+sub0[forind0]*1]),(1.000000/365.000000))/VGV->LEVEL[1847]-1.000000
 ;
}
/* Infected Individuals (I) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1332+sub0[forind0]*1) ;
  VGV->LEVEL[1332+sub0[forind0]*1] = VGV->LEVEL[1434]*VGV->LEVEL[1
+sub0[forind0]*1] ;
}
/* Infected Proportion */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1383+sub0[forind0]*1) ;
  VGV->LEVEL[1383+sub0[forind0]*1] = VGV->LEVEL[1332+sub0[forind0]
*1]/VGV->LEVEL[2721+sub0[forind0]*1] ;
}
/* Predicted GDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2206+sub0[forind0]*1) ;
  VGV->LEVEL[2206+sub0[forind0]*1] = VGV->LEVEL[409+sub0[forind0]*1
]-VGV->LEVEL[256+sub0[forind0]*1] ;
}
/* Direct Infection Impact (st) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 973+sub0[forind0]*1) ;
  VGV->LEVEL[973+sub0[forind0]*1] = VGV->LEVEL[1024]*VGV->LEVEL[1383
+sub0[forind0]*1]*VGV->LEVEL[2206+sub0[forind0]*1] ;
}
/* Direct Covid Impact on Output Gap (st) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 922+sub0[forind0]*1) ;
  VGV->LEVEL[922+sub0[forind0]*1] = VGV->LEVEL[973+sub0[forind0]*1
] ;
}
/* National Population */
 {
  setpos( 1744) ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[2721+sub0[sumind0]*1] ;
  VGV->LEVEL[1744] = temp0 ;
}
/* National CRN */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1693+sub0[forind0]*1) ;
  VGV->LEVEL[1693+sub0[forind0]*1] = VGV->LEVEL[2721+sub0[forind0]
*1]*VGV->LEVEL[614+sub0[forind0]*1]/VGV->LEVEL[1744] ;
}
/* Summed National CRN (bt) */
 {
  setpos( 2617) ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[1693+sub0[sumind0]*1] ;
  VGV->LEVEL[2617] = temp0 ;
}
/* State CRN */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2515+sub0[forind0]*1) ;
  VGV->LEVEL[2515+sub0[forind0]*1] = VGV->LEVEL[2617]*(1.000000-VGV->LEVEL[2566
+sub0[forind0]*1])+VGV->LEVEL[2566+sub0[forind0]*1]*VGV->LEVEL[614
+sub0[forind0]*1] ;
}
/* Inverse Contacts */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1487+sub0[forind0]*1) ;
  VGV->LEVEL[1487+sub0[forind0]*1] = 1.000000-VGV->LEVEL[2515+sub0[forind0]
*1] ;
}
/* Psychological Infectivity Economic Drop (kt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2258+sub0[forind0]*1) ;
  VGV->LEVEL[2258+sub0[forind0]*1] = VGV->LEVEL[2309]*POWER(VGV->LEVEL[1487
+sub0[forind0]*1],VGV->LEVEL[2257])/VGV->LEVEL[1847] ;
}
/* Economic Learning Potential */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1025+sub0[forind0]*1) ;
  VGV->LEVEL[1025+sub0[forind0]*1] = MAX(0,VGV->LEVEL[2258+sub0[forind0]
*1]-VGV->LEVEL[358+sub0[forind0]*1]) ;
}
/* Flush Cumulated NPGDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1128+sub0[forind0]*1) ;
  VGV->LEVEL[1128+sub0[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[2361+sub0[forind0]
*1]!=NA,VGV->LEVEL[103+sub0[forind0]*1]/VGV->LEVEL[2618],0) ;
}
/* Flush Q Length */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1179+sub0[forind0]*1) ;
  VGV->LEVEL[1179+sub0[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[2361+sub0[forind0]
*1]!=NA,VGV->LEVEL[460+sub0[forind0]*1]/VGV->LEVEL[2618],0) ;
}
/* GDP Growth */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1230+sub0[forind0]*1) ;
  VGV->LEVEL[1230+sub0[forind0]*1] = VGV->LEVEL[409+sub0[forind0]*1
]*VGV->LEVEL[869+sub0[forind0]*1] ;
}
/* Learning Decay */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1538+sub0[forind0]*1) ;
  VGV->LEVEL[1538+sub0[forind0]*1] = VGV->LEVEL[358+sub0[forind0]*1
]/VGV->LEVEL[1692] ;
}
/* MAPE */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1590+sub0[forind0]*1) ;
  VGV->LEVEL[1590+sub0[forind0]*1] = ZIDZ(0,VGV->LEVEL[154+sub0[forind0]
*1],VGV->LEVEL[307+sub0[forind0]*1]) ;
}
/* Mitigation Learning */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1641+sub0[forind0]*1) ;
  VGV->LEVEL[1641+sub0[forind0]*1] = VGV->LEVEL[1025+sub0[forind0]
*1]/VGV->LEVEL[1589] ;
}
/* Net Economic Psychological Drop (kt-lt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1745+sub0[forind0]*1) ;
  VGV->LEVEL[1745+sub0[forind0]*1] = MAX(VGV->LEVEL[2258+sub0[forind0]
*1]-VGV->LEVEL[358+sub0[forind0]*1],0) ;
}
/* NPGDP */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1796+sub0[forind0]*1) ;
  VGV->LEVEL[1796+sub0[forind0]*1] = VGV->LEVEL[2206+sub0[forind0]
*1] ;
}
/* Output Gap Decay */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 1848+sub0[forind0]*1) ;
  VGV->LEVEL[1848+sub0[forind0]*1] = VGV->LEVEL[256+sub0[forind0]*1
]/VGV->LEVEL[1899] ;
}
/* Pyschological Impact on Output Gap (kt) */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2310+sub0[forind0]*1) ;
  VGV->LEVEL[2310+sub0[forind0]*1] = VGV->LEVEL[1745+sub0[forind0]
*1]*VGV->LEVEL[2206+sub0[forind0]*1]*VGV->LEVEL[613] ;
}
/* RMSE */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2463+sub0[forind0]*1) ;
  VGV->LEVEL[2463+sub0[forind0]*1] = ZIDZ(0,SQRT(POWER(VGV->LEVEL[205
+sub0[forind0]*1],2.000000)),VGV->LEVEL[307+sub0[forind0]*1]) ;
}
/* SAVEPER */
 {
  setpos( 2514) ;
  VGV->LEVEL[2514] = VGV->LEVEL[2618] ;
}
/* Total Economic Losses */
for(forind0=0;forind0<51;forind0++)
 {
  setpos( 2670+sub0[forind0]*1) ;
  VGV->LEVEL[2670+sub0[forind0]*1] = VGV->LEVEL[52+sub0[forind0]*1
]+VGV->LEVEL[921]*VGV->LEVEL[2619+sub0[forind0]*1] ;
}
} /* comp_aux */
int execute_curloop(GLOB_VARS *VGV) {return(0);}
static void vec_arglist_init(GLOB_VARS *VGV)
{
}
void VEFCC comp_rate(GLOB_VARS *VGV)
{
mdl_func0(VGV);
}

void VEFCC comp_delay(GLOB_VARS *VGV)
{
mdl_func1(VGV);
}

void VEFCC init_time(GLOB_VARS *VGV)
{
mdl_func2(VGV);
}

void VEFCC init_tstep(GLOB_VARS *VGV)
{
mdl_func3(VGV);
}

void VEFCC comp_init(GLOB_VARS *VGV)
{
mdl_func4(VGV);
}

void VEFCC comp_reinit(GLOB_VARS *VGV)
{
mdl_func5(VGV);
}

void VEFCC comp_tstep(GLOB_VARS *VGV)
{
mdl_func6(VGV);
}

void VEFCC comp_aux(GLOB_VARS *VGV)
{
mdl_func7(VGV);
}

