/*(Sun Dec 11 18:26:47 2022) From CovidUSA-Econ-V79.mdl - C equations for the model */

#define _VDFX
#define VDFX

#include "simext.c"
static COMPREAL temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8
,temp9,temp10,temp11,temp12,temp13,temp14,temp15,temp16,temp17,temp18
,temp19,temp20,temp21,temp22,temp23,temp24,temp25,temp26,temp27,temp28
,temp29,temp30,temp31,temp32,temp33,temp34,temp35,temp36,temp37,temp38
,temp39,temp40,temp41,temp42,temp43,temp44,temp45,temp46,temp47,temp48
,temp49,temp50,temp51,temp52,temp53,temp54,temp55,temp56,temp57,temp58
,temp59,temp60,temp61,temp62,temp63,temp64,temp65,temp66,temp67,temp68
,temp69,temp70,temp71,temp72,temp73,temp74,temp75,temp76,temp77,temp78
,temp79,temp80,temp81,temp82,temp83,temp84,temp85,temp86,temp87,temp88
,temp89,temp90,temp91,temp92,temp93,temp94,temp95,temp96,temp97,temp98
,temp99,temp100,temp101,temp102,temp103,temp104,temp105,temp106,temp107
,temp108,temp109,temp110,temp111,temp112,temp113,temp114,temp115,temp116
,temp117,temp118,temp119,temp120,temp121,temp122,temp123,temp124,temp125
,temp126,temp127,temp128,temp129,temp130,temp131 ;
static int sumind0,forind0 ; 
static int sumind1,forind1 ; 
static int sumind2,forind2 ; 
static int sumind3,forind3 ; 
static int sumind4,forind4 ; 
static int sumind5,forind5 ; 
static int sumind6,forind6 ; 
static int sumind7,forind7 ; 
static int simultid ;
static int sub0[]  /* expnt */ = {0,1,2,-1} ;
static int sub1[]  /* InitVrnts */ = {0,1,-1} ;
static int sub2[]  /* IrD */ = {0,1,-1} ;
static int sub3[]  /* pdim */ = {0,1,2,3,-1} ;
static int sub4[]  /* PG1 */ = {0,-1} ;
static int sub5[]  /* PND */ = {0,1,2,3,4,-1} ;
static int sub6[]  /* Priod */ = {0,1,2,-1} ;
static int sub7[]  /* PriorEndoAve */ = {0,1,2,4,5,6,7,8,9,10,11,12,
13,14,15,16,17,18,19,20,21,22,23,24,-1} ;
static int sub8[]  /* PriorGen */ = {14,15,16,17,18,19,20,21,22,-1} ;
static int sub9[]  /* PriorLog */ = {0,1,12,-1} ;
static int sub10[]  /* PriorNonLog */ = {2,3,4,5,6,7,8,9,10,11,13,
14,15,16,17,18,19,20,21,22,23,24,-1} ;
static int sub11[]  /* PriorRgn */ = {0,1,2,4,5,6,7,8,9,10,11,12,13,
14,16,17,18,22,23,24,-1} ;
static int sub12[]  /* Priors */ = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,
14,15,16,17,18,19,20,21,22,23,24,-1} ;
static int sub13[]  /* Rgn */ = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,
37,38,39,40,41,42,43,44,45,46,47,48,49,50,-1} ;
static int sub14[]  /* Rgn1 */ = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,
14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,-1} ;
static int sub15[]  /* Series */ = {0,1,2,-1} ;
static int sub16[]  /* TstSts */ = {0,1,-1} ;
static int sub17[]  /* UsedSeries */ = {0,1,-1} ;
static int sub18[]  /* Vrnts */ = {0,1,2,-1} ;
static int sub19[]  /* VS */ = {0,1,2,-1} ;
static int sub20[]  /* VS2 */ = {0,1,2,-1} ;
static int sub21[]  /* VS3 */ = {0,1,-1} ;
#ifndef LINKEXTERN
#endif
unsigned char *mdl_desc()
{
return("(Sun Dec 11 18:26:47 2022) From CovidUSA-Econ-V79.mdl") ;
}

/* compute the model rates */
void mdl_func0()
{
double temp[10];
VGV->RATE[0] = 1.0 ;/* this is time */
/* #Allocated Fration NonCOVID Hospitalized>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 1+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[1+sub13[forind0]*3+sub19[forind1]*1] = ((POWER(VGV->LEVEL[14851
+sub13[forind0]*3+sub19[forind1]*1],2.000000))-VGV->LEVEL[1+sub13[forind0]
*3+sub19[forind1]*1])/VGV->LEVEL[30438] ;
} /* #Allocated Fration NonCOVID Hospitalized>SMOOTHI# */

/* #DataAggregateSmooth>SMOOTH# */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 154+sub15[forind0]*1 ;
  VGV->RATE[154+sub15[forind0]*1] = (VGV->LEVEL[22958+sub15[forind0]
*1]-VGV->LEVEL[154+sub15[forind0]*1])/VGV->LEVEL[30436] ;
} /* #DataAggregateSmooth>SMOOTH# */

/* #DelayedMeanFlowOT>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 157+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->RATE[157+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[38689
+sub13[forind0]*3+sub15[forind1]*1]-VGV->LEVEL[9751+sub13[forind0]
*3+sub15[forind1]*1] ;
} /* #DelayedMeanFlowOT>DELAY3>LV1# */

/* #DelayedMeanFlowOT>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 310+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->RATE[310+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[9751
+sub13[forind0]*3+sub15[forind1]*1]-VGV->LEVEL[9904+sub13[forind0]
*3+sub15[forind1]*1] ;
} /* #DelayedMeanFlowOT>DELAY3>LV2# */

/* #DelayedMeanFlowOT>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 463+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->RATE[463+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[9904
+sub13[forind0]*3+sub15[forind1]*1]-VGV->LEVEL[9445+sub13[forind0]
*3+sub15[forind1]*1] ;
} /* #DelayedMeanFlowOT>DELAY3>LV3# */

/* #Frac Post Mortem from Untreated>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 616+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[616+sub13[forind0]*3+sub19[forind1]*1] = ((ZIDZ(0,VGV->LEVEL[24495
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[24495+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]
*2+1*1]))-VGV->LEVEL[616+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[44738
] ;
} /* #Frac Post Mortem from Untreated>SMOOTHI# */

/* #Fractional Acuity Change>Delay1>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 769+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[769+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[20505
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[10057+sub13[forind0]
*3+sub19[forind1]*1] ;
} /* #Fractional Acuity Change>Delay1>LV1# */

/* #Infected Individuals (I)>SMOOTH# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 922+sub13[forind0]*1 ;
  VGV->RATE[922+sub13[forind0]*1] = (VGV->LEVEL[60683+sub13[forind0]
*1]-VGV->LEVEL[922+sub13[forind0]*1])/VGV->LEVEL[35342] ;
} /* #Infected Individuals (I)>SMOOTH# */

/* #Losing Immunity Confirmed>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 973+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[973+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[51100
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[19226+sub13[forind0]
*3+sub19[forind1]*1])-VGV->LEVEL[10516+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* #Losing Immunity Confirmed>DELAY3>LV1# */

/* #Losing Immunity Confirmed>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 1126+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[1126+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[10516
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[10669+sub13[forind0]
*3+sub19[forind1]*1] ;
} /* #Losing Immunity Confirmed>DELAY3>LV2# */

/* #Losing Immunity Confirmed>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 1279+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[1279+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[10669
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[10210+sub13[forind0]
*3+sub19[forind1]*1] ;
} /* #Losing Immunity Confirmed>DELAY3>LV3# */

/* #Losing Immunity Hospitalized>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 1432+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[1432+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = (VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1])-VGV->LEVEL[11434+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* #Losing Immunity Hospitalized>DELAY3>LV1# */

/* #Losing Immunity Hospitalized>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 1738+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[1738+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = VGV->LEVEL[11434+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[11740+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* #Losing Immunity Hospitalized>DELAY3>LV2# */

/* #Losing Immunity Hospitalized>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = VGV->LEVEL[11740+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[10822+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* #Losing Immunity Hospitalized>DELAY3>LV3# */

/* #Losing Immunity Unconfirmed>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2350+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[2350+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[51253
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[62776+sub13[forind0]
*3+sub19[forind1]*1])-VGV->LEVEL[12352+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* #Losing Immunity Unconfirmed>DELAY3>LV1# */

/* #Losing Immunity Unconfirmed>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2503+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[2503+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[12352
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[12505+sub13[forind0]
*3+sub19[forind1]*1] ;
} /* #Losing Immunity Unconfirmed>DELAY3>LV2# */

/* #Losing Immunity Unconfirmed>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2656+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[2656+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[12505
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[12046+sub13[forind0]
*3+sub19[forind1]*1] ;
} /* #Losing Immunity Unconfirmed>DELAY3>LV3# */

/* #Post Mortem Testing Need>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2809+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[2809+sub13[forind0]*3+sub19[forind1]*1] = (((VGV->LEVEL[24495
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[32581+sub13[forind0]
*6+sub19[forind1]*2+1*1])*VGV->LEVEL[29360+sub13[forind0]*3+sub19[forind1]
*1])-VGV->LEVEL[2809+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[44738
] ;
} /* #Post Mortem Testing Need>SMOOTHI# */

/* #Recent Detected Infections>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2962+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[2962+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[44585
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[2962+sub13[forind0]
*3+sub19[forind1]*1])/VGV->LEVEL[59813] ;
} /* #Recent Detected Infections>SMOOTHI# */

/* #Recent Relative Contacts>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 3115+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[3115+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[19532
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[3115+sub13[forind0]
*3+sub19[forind1]*1])/VGV->LEVEL[14187] ;
} /* #Recent Relative Contacts>SMOOTHI# */

/* #SimAggregateSmooth>SMOOTH# */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 3268+sub15[forind0]*1 ;
  VGV->RATE[3268+sub15[forind0]*1] = (VGV->LEVEL[55097+sub15[forind0]
*1]-VGV->LEVEL[3268+sub15[forind0]*1])/VGV->LEVEL[30436] ;
} /* #SimAggregateSmooth>SMOOTH# */

/* #Vx S ImmunityLoss>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3271+sub13[forind0]*1 ;
  VGV->RATE[3271+sub13[forind0]*1] = (VGV->LEVEL[63594+sub13[forind0]
*3+2*1]-VGV->LEVEL[35394+sub13[forind0]*3+2*1])-VGV->LEVEL[12760+sub13[forind0]
*1] ;
} /* #Vx S ImmunityLoss>DELAY3>LV1# */

/* #Vx S ImmunityLoss>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3322+sub13[forind0]*1 ;
  VGV->RATE[3322+sub13[forind0]*1] = VGV->LEVEL[12760+sub13[forind0]
*1]-VGV->LEVEL[12811+sub13[forind0]*1] ;
} /* #Vx S ImmunityLoss>DELAY3>LV2# */

/* #Vx S ImmunityLoss>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3373+sub13[forind0]*1 ;
  VGV->RATE[3373+sub13[forind0]*1] = VGV->LEVEL[12811+sub13[forind0]
*1]-VGV->LEVEL[12658+sub13[forind0]*1] ;
} /* #Vx S ImmunityLoss>DELAY3>LV3# */

/* Accumulated GDP Losses */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3424+sub13[forind0]*1 ;
  VGV->RATE[3424+sub13[forind0]*1] = VGV->LEVEL[22290+sub13[forind0]
*1] ;
} /* Accumulated GDP Losses */

/* All Cumulative Recovered at Hospitals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 3475+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[3475+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* All Cumulative Recovered at Hospitals */

/* Confirmed Recovered */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 3781+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[3781+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[51100
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[19226+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[37611+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* Confirmed Recovered */

/* Cost of Deaths Cumulative */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3934+sub13[forind0]*1 ;
  VGV->RATE[3934+sub13[forind0]*1] = VGV->LEVEL[19838+sub13[forind0]
*1] ;
} /* Cost of Deaths Cumulative */

/* Cost of Deaths Cumulative All */
 {
  VGV->lastpos = 3985 ;
  VGV->RATE[3985] = VGV->LEVEL[19889] ;
} /* Cost of Deaths Cumulative All */

/* Cost of GDP Cumulative */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3986+sub13[forind0]*1 ;
  VGV->RATE[3986+sub13[forind0]*1] = VGV->LEVEL[19944+sub13[forind0]
*1] ;
} /* Cost of GDP Cumulative */

/* Cost of GDP Cumulative All */
 {
  VGV->lastpos = 4037 ;
  VGV->RATE[4037] = VGV->LEVEL[19890] ;
} /* Cost of GDP Cumulative All */

/* Cost of Hospitalizations Cumulative */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 4038+sub13[forind0]*1 ;
  VGV->RATE[4038+sub13[forind0]*1] = VGV->LEVEL[19891+sub13[forind0]
*1] ;
} /* Cost of Hospitalizations Cumulative */

/* Cost of Hospitalizations Cumulative All */
 {
  VGV->lastpos = 4089 ;
  VGV->RATE[4089] = VGV->LEVEL[19942] ;
} /* Cost of Hospitalizations Cumulative All */

/* Cumulative APE */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 4090+sub13[forind0]*1 ;
  VGV->RATE[4090+sub13[forind0]*1] = VGV->LEVEL[22137+sub13[forind0]
*1] ;
} /* Cumulative APE */

/* Cumulative Cases VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4141+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[4141+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[41157
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Cases VS */

/* Cumulative Confirmed Cases */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4294+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[4294+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[18711
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Confirmed Cases */

/* Cumulative Deaths at Hospital */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 4447+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = VGV->LEVEL[18252+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* Cumulative Deaths at Hospital */

/* Cumulative Deaths of Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4753+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[4753+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[18864
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Deaths of Confirmed */

/* Cumulative Deaths of Confirmed Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4906+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[4906+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[24342
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[44892+sub13[forind0]
*3+sub19[forind1]*1] ;
} /* Cumulative Deaths of Confirmed Untreated */

/* Cumulative Deaths Untested Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5059+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[5059+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[18047
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Deaths Untested Untreated */

/* Cumulative Deaths VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5212+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[5212+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[24086
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Deaths VS */

/* Cumulative Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 5365+sub13[forind0]*1 ;
  VGV->RATE[5365+sub13[forind0]*1] = VGV->LEVEL[22188+sub13[forind0]
*1] ;
} /* Cumulative Error */

/* Cumulative Excess Death */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 5416+sub13[forind0]*1 ;
  VGV->RATE[5416+sub13[forind0]*1] = VGV->LEVEL[19017+sub13[forind0]
*1] ;
} /* Cumulative Excess Death */

/* Cumulative Missed Death */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 5467+sub13[forind0]*1 ;
  VGV->RATE[5467+sub13[forind0]*1] = VGV->LEVEL[19995+sub13[forind0]
*1] ;
} /* Cumulative Missed Death */

/* Cumulative Negative Tests */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5518+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[5518+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[40953
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Negative Tests */

/* Cumulative Recovered at Hospitals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 5671+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[5671+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[37764+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* Cumulative Recovered at Hospitals */

/* Cumulative Recoveries */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5977+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[5977+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[14647
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Recoveries */

/* Cumulative Tests Conducted */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 6130+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[6130+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[54944
+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Cumulative Tests Conducted */

/* Cumulative Tests Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6283+sub13[forind0]*1 ;
  VGV->RATE[6283+sub13[forind0]*1] = VGV->LEVEL[62725+sub13[forind0]
*1] ;
} /* Cumulative Tests Data */

/* Cumulative Vaccination */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6334+sub13[forind0]*1 ;
  VGV->RATE[6334+sub13[forind0]*1] = VGV->LEVEL[14800+sub13[forind0]
*1] ;
} /* Cumulative Vaccination */

/* CumulativeOutcomes */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 6385+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]
*1 ;
  VGV->RATE[6385+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]*1
] = VGV->LEVEL[41571+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]
*1] ;
} /* CumulativeOutcomes */

/* Current GDP Output Gap (y) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6844+sub13[forind0]*1 ;
  VGV->RATE[6844+sub13[forind0]*1] = VGV->LEVEL[25160+sub13[forind0]
*1]+VGV->LEVEL[50327+sub13[forind0]*1]-VGV->LEVEL[42030+sub13[forind0]
*1] ;
} /* Current GDP Output Gap (y) */

/* Data Count */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6895+sub13[forind0]*1 ;
  VGV->RATE[6895+sub13[forind0]*1] = VGV->LEVEL[20046+sub13[forind0]
*1] ;
} /* Data Count */

/* Economist Exess Death Err */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6946+sub13[forind0]*1 ;
  VGV->RATE[6946+sub13[forind0]*1] = VGV->LEVEL[25522+sub13[forind0]
*1] ;
} /* Economist Exess Death Err */

/* First Hospital Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6997+sub13[forind0]*1 ;
  VGV->RATE[6997+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[6997+sub13[forind0]
*1]==VGV->LEVEL[35907]&&VGV->LEVEL[23369+sub13[forind0]*1]>0,(VGV->LEVEL[0
]-1.000000-VGV->LEVEL[6997+sub13[forind0]*1])/VGV->LEVEL[59349],0)
 ;
} /* First Hospital Data */

/* Hospitalized Infectious */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 7048+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->RATE[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1
] = VGV->LEVEL[30439+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
} /* Hospitalized Infectious */

/* Infected pre Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7354+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[7354+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[8170
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[19685+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[58019+sub13[forind0]*3+sub19[forind1]
*1]-VGV->LEVEL[63235+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Infected pre Detection */

/* Infected Unconfirmed Post-Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7507+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[7507+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[19685
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[24495+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[51253+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* Infected Unconfirmed Post-Detection */

/* Infection Deviation */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 7660+sub13[forind0]*1 ;
  VGV->RATE[7660+sub13[forind0]*1] = VGV->LEVEL[14239+sub13[forind0]
*1]+VGV->LEVEL[14290+sub13[forind0]*1] ;
} /* Infection Deviation */

/* Infectious Confirmed Not Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7711+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[7711+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44432
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[24342+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[51100+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* Infectious Confirmed Not Hospitalized */

/* MaxRcntVacRt */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 7864+sub13[forind0]*1 ;
  VGV->RATE[7864+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[8680+sub13[forind0]
*1]>VGV->LEVEL[7864+sub13[forind0]*1],(VGV->LEVEL[8680+sub13[forind0]
*1]-VGV->LEVEL[7864+sub13[forind0]*1])/VGV->LEVEL[59349],0) ;
} /* MaxRcntVacRt */

/* MuStock */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7915+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->RATE[7915+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[39869
+sub13[forind0]*3+sub15[forind1]*1]-VGV->LEVEL[39716+sub13[forind0]
*3+sub15[forind1]*1] ;
} /* MuStock */

/* Non Economic Mitigation (lt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8068+sub13[forind0]*1 ;
  VGV->RATE[8068+sub13[forind0]*1] = VGV->LEVEL[39461+sub13[forind0]
*1]-VGV->LEVEL[36590+sub13[forind0]*1] ;
} /* Non Economic Mitigation (lt) */

/* Non Pandemic GDP (xt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8119+sub13[forind0]*1 ;
  VGV->RATE[8119+sub13[forind0]*1] = VGV->LEVEL[30279+sub13[forind0]
*1] ;
} /* Non Pandemic GDP (xt) */

/* Perceived Risk of Life Loss */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8323+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[8323+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[34985
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[8323+sub13[forind0]
*3+sub19[forind1]*1])/IF_THEN_ELSE(VGV->LEVEL[34985+sub13[forind0]
*3+sub19[forind1]*1]>VGV->LEVEL[8323+sub13[forind0]*3+sub19[forind1]
*1],VGV->LEVEL[59866+sub13[forind0]*1],VGV->LEVEL[59455+sub13[forind0]
*3+sub19[forind1]*1]) ;
} /* Perceived Risk of Life Loss */

/* Pre-Symptomatic Infected */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8476+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[8476+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[35394
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[42286+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[8170+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* Pre-Symptomatic Infected */

/* RecentTestRate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8629+sub13[forind0]*1 ;
  VGV->RATE[8629+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]>VGV->LEVEL[36437
+sub13[forind0]*1],0,1.000000)*(MAX(VGV->LEVEL[39410+sub13[forind0]
*1],VGV->LEVEL[23828+sub13[forind0]*1])-VGV->LEVEL[8629+sub13[forind0]
*1])/VGV->LEVEL[59297] ;
} /* RecentTestRate */

/* RecentVaccineRate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8680+sub13[forind0]*1 ;
  VGV->RATE[8680+sub13[forind0]*1] = VGV->LEVEL[53298+sub13[forind0]
*1] ;
} /* RecentVaccineRate */

/* Recovered Unconfirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8884+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[8884+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[51253
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[38121+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[62776+sub13[forind0]*3+sub19[forind1]
*1] ;
} /* Recovered Unconfirmed */

/* simData */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9037+sub13[forind0]*1 ;
  VGV->RATE[9037+sub13[forind0]*1] = VGV->LEVEL[14188+sub13[forind0]
*1]+VGV->LEVEL[17996+sub13[forind0]*1]+VGV->LEVEL[53041+sub13[forind0]
*1]+VGV->LEVEL[53041+sub13[forind0]*1] ;
} /* simData */

/* Susceptible */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9088+sub13[forind0]*3+1*1 ;
  VGV->RATE[9088+sub13[forind0]*3+1*1] = (-VGV->LEVEL[35394+sub13[forind0]
*3+1*1])-VGV->LEVEL[63594+sub13[forind0]*3+1*1]+VGV->LEVEL[33808+sub13[forind0]
*3+1*1]+VGV->LEVEL[38070+sub13[forind0]*1] ;
} /* Susceptible */

/* Susceptible */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9088+sub13[forind0]*3+2*1 ;
  VGV->RATE[9088+sub13[forind0]*3+2*1] = (-VGV->LEVEL[35394+sub13[forind0]
*3+2*1])+VGV->LEVEL[63594+sub13[forind0]*3+1*1]-VGV->LEVEL[38070+sub13[forind0]
*1]+VGV->LEVEL[63594+sub13[forind0]*3+0*1] ;
} /* Susceptible */

/* Susceptible */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9088+sub13[forind0]*3+0*1 ;
  VGV->RATE[9088+sub13[forind0]*3+0*1] = (-VGV->LEVEL[35394+sub13[forind0]
*3+0*1])-VGV->LEVEL[63594+sub13[forind0]*3+0*1] ;
} /* Susceptible */

/* Sympthoms in Susceptible */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9241+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[9241+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[57457
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[56794+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[56947+sub13[forind0]*3+sub19[forind1]
*1]-VGV->LEVEL[57304+sub13[forind0]*3+sub19[forind1]*1] ;
} /* Sympthoms in Susceptible */

/* Total Sympthoms lost to Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9394+sub13[forind0]*1 ;
  VGV->RATE[9394+sub13[forind0]*1] = VGV->LEVEL[57253+sub13[forind0]
*1] ;
} /* Total Sympthoms lost to Deaths */

} /* comp_rate */

/* compute the delays */
void mdl_func1()
{
double temp[10];
/* Onset of Symptoms */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8170+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[8170+sub13[forind0]*3+sub19[forind1]*1] = DELAY_N_a(0+sub13[forind0]
*3+sub19[forind1]*1,VGV->LEVEL[35394+sub13[forind0]*3+sub19[forind1]
*1],VGV->LEVEL[34525]) ;
} /* Onset of Symptoms */

/* Recorded Deaths */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8731+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->RATE[8731+sub13[forind0]*3+sub19[forind1]*1] = DELAY_N_a(153+sub13[forind0]
*3+sub19[forind1]*1,VGV->LEVEL[44739+sub13[forind0]*3+sub19[forind1]
*1]+VGV->LEVEL[24342+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[32581
+sub13[forind0]*6+sub19[forind1]*2+0*1],VGV->LEVEL[24290+sub13[forind0]
*1]) ;
} /* Recorded Deaths */

} /* comp_delay */

/* initialize time */
void mdl_func2()
{
double temp[10];
vec_arglist_init();
VGV->LEVEL[0] = VGV->LEVEL[36010] ;
} /* init_time */

/* initialize time step */
void mdl_func3()
{
double temp[10];
/* a constant no need to do anything */
} /* init_tstep */

/* State variable initial value computation*/
void mdl_func4()
{
double temp[10];
/* #Allocated Fration NonCOVID Hospitalized>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 1+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[1+sub13[forind0]*3+sub19[forind1]*1] = (1.000000) ;
}
/* DataFlowAggregate */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 22958+sub15[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[23063+sub13[sumind0]*3+sub15[forind0]*1] ;
  VGV->LEVEL[22958+sub15[forind0]*1] = MAX(0,temp0) ;
}
/* #DataAggregateSmooth>SMOOTH# */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 154+sub15[forind0]*1 ;
  VGV->LEVEL[154+sub15[forind0]*1] = VGV->LEVEL[22958+sub15[forind0]
*1] ;
}
/* #DelayedMeanFlowOT>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9598+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[9598+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[65263
]/3.000000 ;
}
/* #Post Mortem Testing Need>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2809+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[2809+sub13[forind0]*3+sub19[forind1]*1] = (0) ;
}
/* Post Mortem Testing Need */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45045+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[45045+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2809
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Time */
 {
  VGV->lastpos = 0 ;
  VGV->LEVEL[0] = VGV->LEVEL[36010] ;
}
/* LastTestDate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36437+sub13[forind0]*1 ;
  VGV->LEVEL[36437+sub13[forind0]*1] = GET_DATA_LAST_TIME(vecarg_assign(0,&
VGV->LEVEL[23828+sub13[forind0]*1])) ;
}
/* First Hospital Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6997+sub13[forind0]*1 ;
  VGV->LEVEL[6997+sub13[forind0]*1] = VGV->LEVEL[35907] ;
}
/* First Data Date */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27263+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[27263+sub13[forind0]*3+0*1] = GET_DATA_FIRST_TIME(vecarg_assign(1,&
VGV->LEVEL[23012+sub13[forind0]*1])) ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27263+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[27263+sub13[forind0]*3+1*1] = GET_DATA_FIRST_TIME(vecarg_assign(2,&
VGV->LEVEL[22652+sub13[forind0]*1])) ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27263+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[27263+sub13[forind0]*3+2*1] = VGV->LEVEL[6997+sub13[forind0]
*1] ;
}
/* MinTestRateFromCases */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 39410+sub13[forind0]*1 ;
  VGV->LEVEL[39410+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[27263+sub13[forind0]*3+0*1],0,VGV->LEVEL[23012+sub13[forind0]
*1]*VGV->LEVEL[39409]) ;
}
/* RecentTestRate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8629+sub13[forind0]*1 ;
  VGV->LEVEL[8629+sub13[forind0]*1] = 0 ;
}
/* Infected pre Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7354+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[7354+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Infected Unconfirmed Post-Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7507+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[7507+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Susceptible */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9088+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[9088+sub13[forind0]*3+1*1] = 0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9088+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[9088+sub13[forind0]*3+2*1] = 0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9088+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[9088+sub13[forind0]*3+0*1] = VGV->LEVEL[35959+sub13[forind0]
*1] ;
}
/* Recovered Unconfirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8884+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[8884+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Confirmed Recovered */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 3781+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[3781+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Infectious Confirmed Not Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7711+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[7711+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Pre-Symptomatic Infected */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8476+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[8476+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
}
void mdl_func5(void) ;
void mdl_func5(){
double temp[10];
/* Hospitalized Infectious */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 7048+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = 0 ;
}
/* Cumulative Recovered at Hospitals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 5671+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = 0 ;
}
/* Population VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43973+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp1 += VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[43973+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7354
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7507+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[9088+sub13[forind0]*3+sub19[forind1]
*1]+VGV->LEVEL[8884+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[3781
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7711+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[8476+sub13[forind0]*3+sub19[forind1]
*1]+temp0+temp1 ;
}
/* Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 43718+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[43973+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[43718+sub13[forind0]*1] = temp0 ;
}
/* DataLastTestRate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 23624+sub13[forind0]*1 ;
  VGV->LEVEL[23624+sub13[forind0]*1] = GET_DATA_AT_TIME(vecarg_assign(3,&
VGV->LEVEL[23828+sub13[forind0]*1]),MIN(VGV->LEVEL[36437+sub13[forind0]
*1],VGV->LEVEL[41310])) ;
}
/* Current Test Rate per Capita */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22239+sub13[forind0]*1 ;
  VGV->LEVEL[22239+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[23624
+sub13[forind0]*1]==NA,0,VGV->LEVEL[23624+sub13[forind0]*1]/VGV->LEVEL[43718
+sub13[forind0]*1]) ;
}
/* Final Test Rate Per Capita */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27211+sub13[forind0]*1 ;
  VGV->LEVEL[27211+sub13[forind0]*1] = VGV->LEVEL[22239+sub13[forind0]
*1]+VGV->LEVEL[65264]*MAX(0,(VGV->LEVEL[38529]-VGV->LEVEL[22239+sub13[forind0]
*1])) ;
}
/* Policy Test Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 43667+sub13[forind0]*1 ;
  VGV->LEVEL[43667+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[41310],VGV->LEVEL[22239+sub13[forind0]*1],VGV->LEVEL[27211
+sub13[forind0]*1]) ;
}
/* External Test Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 26341+sub13[forind0]*1 ;
  VGV->LEVEL[26341+sub13[forind0]*1] = VGV->LEVEL[43718+sub13[forind0]
*1]*VGV->LEVEL[43667+sub13[forind0]*1] ;
}
/* Active Test Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 13193+sub13[forind0]*1 ;
  VGV->LEVEL[13193+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[41310],IF_THEN_ELSE(VGV->LEVEL[0]<VGV->LEVEL[36437+sub13[forind0]
*1],MAX(VGV->LEVEL[23828+sub13[forind0]*1],VGV->LEVEL[39410+sub13[forind0]
*1]),VGV->LEVEL[8629+sub13[forind0]*1]),VGV->LEVEL[26341+sub13[forind0]
*1]) ;
}
/* Post Mortem Tests Total */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 45198+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[45045+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[45198+sub13[forind0]*1] = MIN(temp0,VGV->LEVEL[13193+sub13[forind0]
*1]) ;
}
/* Frac PM Need VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 27981+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[45045+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[27981+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[45045
+sub13[forind0]*3+sub19[forind1]*1],temp0) ;
}
/* Post Mortem Test Rate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44739+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44739+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[45198
+sub13[forind0]*1]*VGV->LEVEL[27981+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[53611] ;
}
/* Reaching Testing Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50583+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50583+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7354
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[41570] ;
}
/* Sensitivity Post Mortem Testing to Capacity */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53714+sub13[forind0]*1 ;
  VGV->LEVEL[53714+sub13[forind0]*1] = VGV->LEVEL[53816] ;
}
/* RegionalInputs */
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+0*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+0*51+sub13[forind1]*1] = LOG(VGV->LEVEL[59815+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+1*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+1*51+sub13[forind1]*1] = LOG(VGV->LEVEL[59353+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+2*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+2*51+sub13[forind1]*1] = VGV->LEVEL[51508+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+3*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+3*51+sub13[forind1]*1] = VGV->LEVEL[53714+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+4*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+4*51+sub13[forind1]*1] = VGV->LEVEL[17097+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+5*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+5*51+sub13[forind1]*1] = VGV->LEVEL[65268+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+6*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+6*51+sub13[forind1]*1] = VGV->LEVEL[40022+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+7*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+7*51+sub13[forind1]*1] = VGV->LEVEL[39301+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+8*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+8*51+sub13[forind1]*1] = VGV->LEVEL[53508+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+9*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+9*51+sub13[forind1]*1] = VGV->LEVEL[19379+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+10*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+10*51+sub13[forind1]*1] = VGV->LEVEL[34321+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+11*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+11*51+sub13[forind1]*1] = VGV->LEVEL[34423+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+12*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+12*51+sub13[forind1]*1] = LOG(VGV->LEVEL[25266+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+13*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+13*51+sub13[forind1]*1] = VGV->LEVEL[51406+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+14*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+14*51+sub13[forind1]*1] = VGV->LEVEL[16993+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+15*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+15*51+sub13[forind1]*1] = VGV->LEVEL[53817] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+16*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+16*51+sub13[forind1]*1] = VGV->LEVEL[20250+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+17*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+17*51+sub13[forind1]*1] = VGV->LEVEL[53612+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+18*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+18*51+sub13[forind1]*1] = VGV->LEVEL[60019+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+19*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+19*51+sub13[forind1]*1] = VGV->LEVEL[53455] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+20*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+20*51+sub13[forind1]*1] = VGV->LEVEL[53351] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+21*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+21*51+sub13[forind1]*1] = VGV->LEVEL[53403] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+22*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+22*51+sub13[forind1]*1] = VGV->LEVEL[40124+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+23*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+23*51+sub13[forind1]*1] = VGV->LEVEL[36488+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+24*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+24*51+sub13[forind1]*1] = VGV->LEVEL[55714+sub13[forind1]
*1] ;
}
/* CalcAve */
for(forind0=0;forind0<25;forind0++)
 {
  VGV->lastpos = 17512+sub12[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[51611+sub12[forind0]*51+sub13[sumind0]*1] ;
  VGV->LEVEL[17512+sub12[forind0]*1] = temp0/(COMPREAL)51 ;
}
/* PValRaw */
for(forind0=0;forind0<25;forind0++)
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 49052+sub12[forind0]*51+sub13[forind1]*1 ;
  VGV->LEVEL[49052+sub12[forind0]*51+sub13[forind1]*1] = VGV->LEVEL[17512
+sub12[forind0]*1]*(1.000000+VGV->LEVEL[47674+sub12[forind0]*1])+(
VGV->LEVEL[51611+sub12[forind0]*51+sub13[forind1]*1]-VGV->LEVEL[17512
+sub12[forind0]*1])*VGV->LEVEL[47699+sub12[forind0]*1] ;
}
/* PVal */
for(forind0=0;forind0<3;forind0++)
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 47777+sub9[forind0]*51+sub13[forind1]*1 ;
  VGV->LEVEL[47777+sub9[forind0]*51+sub13[forind1]*1] = POWER(10.000000
,VGV->LEVEL[49052+sub9[forind0]*51+sub13[forind1]*1]) ;
}
for(forind0=0;forind0<22;forind0++)
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 47777+sub10[forind0]*51+sub13[forind1]*1 ;
  VGV->LEVEL[47777+sub10[forind0]*51+sub13[forind1]*1] = VGV->LEVEL[49052
+sub10[forind0]*51+sub13[forind1]*1] ;
}
/* Total Asymptomatic Fraction Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60070+sub13[forind0]*1 ;
  VGV->LEVEL[60070+sub13[forind0]*1] = VGV->LEVEL[47777+18*51+sub13[forind0]
*1] ;
}
/* Total Asymptomatic Fraction Nt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 60121+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[60121+sub13[forind0]*3+sub19[forind1]*1] = MIN(1.000000
,VGV->LEVEL[60070+sub13[forind0]*1]*VGV->LEVEL[40232+sub19[forind1]
*1]) ;
}
/* Covid Acuity Relative to Flu Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 20454+sub13[forind0]*1 ;
  VGV->LEVEL[20454+sub13[forind0]*1] = VGV->LEVEL[47777+16*51+sub13[forind0]
*1] ;
}
/* Sensitivity of Fatality Rate to Acuity Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53663+sub13[forind0]*1 ;
  VGV->LEVEL[53663+sub13[forind0]*1] = VGV->LEVEL[47777+17*51+sub13[forind0]
*1] ;
}
/* Multiplier Vx Acuity */
 {
  VGV->lastpos = 40226+2*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[53663+sub13[sumind0]*1] ;
  VGV->LEVEL[40226+2*1] = POWER(VGV->LEVEL[22597],((COMPREAL)51/temp0
)) ;
}
/* Multiplier Vx Acuity Net */
 {
  VGV->lastpos = 40229+0*1 ;
  VGV->LEVEL[40229+0*1] = VGV->LEVEL[40226+0*1] ;
}
 {
  VGV->lastpos = 40229+1*1 ;
  VGV->LEVEL[40229+1*1] = VGV->LEVEL[40226+1*1] ;
}
 {
  VGV->lastpos = 40229+2*1 ;
  VGV->LEVEL[40229+2*1] = VGV->LEVEL[40226+0*1]*VGV->LEVEL[40226+2
*1] ;
}
/* Variant Intro Start Time All */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64379+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[64379+sub13[forind0]*3+0*1] = VGV->LEVEL[64328+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64379+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[64379+sub13[forind0]*3+1*1] = VGV->LEVEL[64532+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64379+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[64379+sub13[forind0]*3+2*1] = VGV->LEVEL[64583] ;
}
/* Multiplier Vx Variant */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 40235+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP((VGV->LEVEL[64160+sub18[sumind0]*1]-1.000000)/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[40235+sub13[forind0]*1] = 1.000000+temp0 ;
}
/* Covid Acuity Relative to Flu Nt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20505+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20505+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[20454
+sub13[forind0]*1]*VGV->LEVEL[40229+sub19[forind1]*1]*VGV->LEVEL[40235
+sub13[forind0]*1] ;
}
/* Additional Asymptomatic Relative to Symptomatic Init */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 14034+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[14034+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[60121
+sub13[forind0]*3+sub19[forind1]*1]-EXP((-VGV->LEVEL[20505+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[27674]),1.000000-VGV->LEVEL[60121
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* Additional Asymptomatic Fraction Init */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13575+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[13575+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[14034
+sub13[forind0]*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[14034+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Sympthoms in Susceptible */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9241+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[9241+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[9088
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[13575+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[20505+sub13[forind0]*3+sub19[forind1]
*1] ;
}
/* Total Sympthoms lost to Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9394+sub13[forind0]*1 ;
  VGV->LEVEL[9394+sub13[forind0]*1] = 0 ;
}
/* Cumulative Deaths VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5212+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[5212+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 21423+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[5212+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[21423+sub13[forind0]*1] = temp0 ;
}
/* Total Sympthoms in Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60785+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[43973+sub13[forind0]*3+sub19[sumind0]*1]*(
1.000000-VGV->LEVEL[13575+sub13[forind0]*3+sub19[sumind0]*1])*VGV->LEVEL[20505
+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[60785+sub13[forind0]*1] = temp0+VGV->LEVEL[57712]*VGV->LEVEL[21423
+sub13[forind0]*1] ;
}
/* Acuity Multiplier due to Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 13524+sub13[forind0]*1 ;
  VGV->LEVEL[13524+sub13[forind0]*1] = 1.000000-VGV->LEVEL[9394+sub13[forind0]
*1]/(VGV->LEVEL[60785+sub13[forind0]*1]) ;
}
/* Average Acuity in Susceptible */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15769+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[15769+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[9241
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[9088+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[13524+sub13[forind0]*1] ;
}
/* Covid Acuity Relative to Flu Final */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20301+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[15769+sub13[forind0]*3+sub19[forind1]*1]==0,VGV->LEVEL[20505
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[15769+sub13[forind0]
*3+sub19[forind1]*1]/(1.000000-VGV->LEVEL[13575+sub13[forind0]*3+sub19[forind1]
*1])) ;
}
/* Covid Acuity */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20097+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[27674
]*VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Total Asymptomatic Fraction Transformed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 60274+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[13575
+sub13[forind0]*3+sub19[forind1]*1]+EXP((-VGV->LEVEL[20097+sub13[forind0]
*3+sub19[forind1]*1]))*(1.000000-VGV->LEVEL[13575+sub13[forind0]*3
+sub19[forind1]*1]) ;
}
/* Additional Asymptomatic Relative to Symptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13881+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[13881+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[60274
+sub13[forind0]*3+sub19[forind1]*1]-EXP((-VGV->LEVEL[20097+sub13[forind0]
*3+sub19[forind1]*1])),1.000000-VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Poisson Subset Reaching Test Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43514+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43514+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[50583
+sub13[forind0]*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[13881+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Fraction Covered by Test */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 28391+sub13[forind0]*1 ;
  VGV->LEVEL[28391+sub13[forind0]*1] = MIN(1.000000,POWER((VGV->LEVEL[58480
]*VGV->LEVEL[8629+sub13[forind0]*1]/VGV->LEVEL[43718+sub13[forind0]
*1]),VGV->LEVEL[58479])) ;
}
/* Positive Candidates Interested in Testing Poisson Subset */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44126+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43514
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28391+sub13[forind0]
*1] ;
}
/* Symptomatic Fraction in Poisson */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 57713+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[57713+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-EXP(
(-VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]*1])) ;
}
/* Baseline Daily Fraction Susceptible Seeking Tests Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 17148+sub13[forind0]*1 ;
  VGV->LEVEL[17148+sub13[forind0]*1] = VGV->LEVEL[47777+4*51+sub13[forind0]
*1] ;
}
/* Multiplier Recent Infections to Test Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 40073+sub13[forind0]*1 ;
  VGV->LEVEL[40073+sub13[forind0]*1] = VGV->LEVEL[47777+6*51+sub13[forind0]
*1] ;
}
/* #Recent Detected Infections>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2962+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[2962+sub13[forind0]*3+sub19[forind1]*1] = (0) ;
}
/* Recent Detected Infections */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50788+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50788+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2962
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Potential Test Demand from Susceptible Population */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45709+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]*1] = ((VGV->LEVEL[9088
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[8884+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]
*2+1*1])*(VGV->LEVEL[17148+sub13[forind0]*1]+VGV->LEVEL[40073+sub13[forind0]
*1]/VGV->LEVEL[43718+sub13[forind0]*1]*VGV->LEVEL[50788+sub13[forind0]
*3+sub19[forind1]*1]))*VGV->LEVEL[28391+sub13[forind0]*1] ;
}
/* Symptomatic Fraction Negative */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 57866+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[57866+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-EXP(
(-VGV->LEVEL[27674])) ;
}
/* Testing Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58787+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58787+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44126
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[57713+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[57866+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Test Demand Fraction */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58326+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[58787+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[58326+sub13[forind0]*3+sub19[forind1]*1] = XIDZ(0,VGV->LEVEL[58787
+sub13[forind0]*3+sub19[forind1]*1],temp0,1.000000/3.000000) ;
}
/* Testing Capacity Net of Post Mortem Tests */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58634+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58634+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[13193
+sub13[forind0]*1]-VGV->LEVEL[45198+sub13[forind0]*1])*VGV->LEVEL[58326
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Testing on Living */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58940+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58940+sub13[forind0]*3+sub19[forind1]*1] = MIN(VGV->LEVEL[58634
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[58787+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Positive Candidates Interested in Testing Poisson Subset Adj */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44279+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44279+sub13[forind0]*3+sub19[forind1]*1] = MAX(0.001000
*VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[44126
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* b */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16840+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[44279+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]
*1],VGV->LEVEL[44279+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* a */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12862+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]*1] = XIDZ(0,VGV->LEVEL[45709
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[44279+sub13[forind0]
*3+sub19[forind1]*1],1.000000) ;
}
/* t3 */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58172+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58172+sub13[forind0]*3+sub19[forind1]*1] = POWER(((-9.000000)
*VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]*1]+1.732100*SQRT(
MAX(0,4.000000*POWER(VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]
*1],3.000000)+27.000000*POWER(VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]
*1],2.000000)))),(1.000000/3.000000)) ;
}
/* Ymix */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65730+sub13[forind0]*9+sub19[forind1]*3+0*1 ;
  VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]*3+0*1] = (-VGV->LEVEL[16840
+sub13[forind0]*3+sub19[forind1]*1])/(1.000000+VGV->LEVEL[12862+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65730+sub13[forind0]*9+sub19[forind1]*3+1*1 ;
  VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]*3+1*1] = (SQRT(
POWER(VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]*1],2.000000
)-4.000000*VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]*1])-VGV->LEVEL[12862
+sub13[forind0]*3+sub19[forind1]*1])/2.000000 ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65730+sub13[forind0]*9+sub19[forind1]*3+2*1 ;
  VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]*3+2*1] = ((-0.873580)
*VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[58172
+sub13[forind0]*3+sub19[forind1]*1]+0.381570*VGV->LEVEL[58172+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* lnymix */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 36693+sub13[forind0]*9+sub19[forind1]*3+sub0[forind2]
*1 ;
  VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]*3+sub0[forind2]
*1] = (-LN(MAX(1e-06,1.000000-VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]
*3+sub0[forind2]*1]))) ;
}
/* cft */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17537+sub13[forind0]*9+sub19[forind1]*3+0*1 ;
  VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+0*1] = VGV->LEVEL[36693
+sub13[forind0]*9+sub19[forind1]*3+0*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17537+sub13[forind0]*9+sub19[forind1]*3+1*1 ;
  VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+1*1] = VGV->LEVEL[36693
+sub13[forind0]*9+sub19[forind1]*3+1*1]-VGV->LEVEL[36693+sub13[forind0]
*9+sub19[forind1]*3+0*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17537+sub13[forind0]*9+sub19[forind1]*3+2*1 ;
  VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+2*1] = (LN(MIN(
100.000000,MAX(1e-06,ZIDZ(0,VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]
*3+2*1]-VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]*3+0*1],VGV->LEVEL[36693
+sub13[forind0]*9+sub19[forind1]*3+1*1]-VGV->LEVEL[36693+sub13[forind0]
*9+sub19[forind1]*3+0*1])/LN(2.000000))))) ;
}
/* Extrapolated Estimator */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 26395+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[26395+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]*1]>1.000000,VGV->LEVEL[17537
+sub13[forind0]*9+sub19[forind1]*3+0*1]+VGV->LEVEL[17537+sub13[forind0]
*9+sub19[forind1]*3+1*1]*POWER((VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]
*1]-1.000000),VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+2
*1]),VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]*3+0*1]) ;
}
/* Y */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65577+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[65577+sub13[forind0]*3+sub19[forind1]*1] = MIN(1.000000
,MAX(1e-06,1.000000-EXP((-VGV->LEVEL[26395+sub13[forind0]*3+sub19[forind1]
*1])))) ;
}
/* Prob Missing Symptom */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 47214+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[47214+sub13[forind0]*3+sub19[forind1]*1] = MAX(0,LN(VGV->LEVEL[65577
+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[27674]+1.000000) ;
}
/* Indicated fraction negative demand tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34526+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34526+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-EXP(
VGV->LEVEL[27674]*(VGV->LEVEL[47214+sub13[forind0]*3+sub19[forind1]
*1]-1.000000)) ;
}
/* Indicated fraction positive demand tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34679+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34679+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-EXP(
VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]*1]*(VGV->LEVEL[47214
+sub13[forind0]*3+sub19[forind1]*1]-1.000000)) ;
}
/* Tests on Negative Patients */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 59093+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[59093+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]*ZIDZ(0,VGV->LEVEL[34526+sub13[forind0]
*3+sub19[forind1]*1]*VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]
*1],VGV->LEVEL[34526+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[45709
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[34679+sub13[forind0]
*3+sub19[forind1]*1]*VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
}
void mdl_func6(void) ;
void mdl_func6(){
double temp[10];
/* Total Test on Covid Patients */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 60836+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[60836+sub13[forind0]*3+sub19[forind1]*1] = MAX(0,MIN(
VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[59093+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Fraction Interested not Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 28901+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-IF_THEN_ELSE(
VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1]<1e-20,0,VGV->LEVEL[60836
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[44126+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Fraction Interseted not Correctly Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29054+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[29054+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-(
1.000000-VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[53611
] ;
}
/* Positive Tests of Infected */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44585+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44585+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44126
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[29054+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Recorded Deaths */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8731+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[8731+sub13[forind0]*3+sub19[forind1]*1] = DELAY_N_i(135,8731
+sub13[forind0]*3+sub19[forind1]*1,153+sub13[forind0]*3+sub19[forind1]
*1,0,VGV->LEVEL[24341]) ;
}
/* Average Acuity of Positively Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16534+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[16534+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1]==0,VGV->LEVEL[20097
+sub13[forind0]*3+0*1],VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]
*1]*MAX(1.000000,(XIDZ(0,(1.000000-VGV->LEVEL[47214+sub13[forind0]
*3+sub19[forind1]*1]*POWER(VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]
*1],2.000000)),1.000000-VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]
*1],2.000000*VGV->LEVEL[47214+sub13[forind0]*3+sub19[forind1]*1]))
)) ;
}
/* Reference COVID Hospitalization Fraction Confirmed Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 51457+sub13[forind0]*1 ;
  VGV->LEVEL[51457+sub13[forind0]*1] = VGV->LEVEL[47777+13*51+sub13[forind0]
*1] ;
}
/* PMAS Confirmed for Hospital Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42647+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42647+sub13[forind0]*3+sub19[forind1]*1] = POWER((1.000000
-VGV->LEVEL[51457+sub13[forind0]*1]),(1.000000/VGV->LEVEL[16534+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Hospital Demand from Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31510+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[31510+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44585
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-EXP((-VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[42647+sub13[forind0]
*3+sub19[forind1]*1]))) ;
}
/* Poisson Subset Not Tested Passing Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43361+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43361+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43514
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[44585+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Average Acuity of Untested Poisson Subset */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16687+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[16687+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[43514
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[20097+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[44585+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[16534+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[43361
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* Allocated Fration NonCOVID Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15004+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[15004+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[1
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Untested PMAS Gap with Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63082+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63082+sub13[forind0]*3+sub19[forind1]*1] = POWER((1.000000
-VGV->LEVEL[15004+sub13[forind0]*3+sub19[forind1]*1]),VGV->LEVEL[53507
]) ;
}
/* PMAS Unconfirmed for Hospital Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42800+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42800+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[42647
+sub13[forind0]*3+sub19[forind1]*1]+(1.000000-VGV->LEVEL[42647+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[63082+sub13[forind0]*3+sub19[forind1]
*1] ;
}
/* Hospital Demand from Not Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31357+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[31357+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43361
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-EXP((-VGV->LEVEL[16687
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[42800+sub13[forind0]
*3+sub19[forind1]*1]))) ;
}
/* Potential Hospital Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45403+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+1*1] = VGV->LEVEL[31357
+sub13[forind0]*3+sub19[forind1]*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45403+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[31510
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Expected Positive Poisson Covid Patients */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 26188+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[26188+sub13[forind0]*3+sub19[forind1]*1] = temp0*VGV->LEVEL[45249
] ;
}
/* Nominal Hospital Capacity */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 41312+sub13[forind0]*1 ;
  VGV->LEVEL[41312+sub13[forind0]*1] = VGV->LEVEL[35959+sub13[forind0]
*1]*VGV->LEVEL[17461+sub13[forind0]*1]/1000.000000 ;
}
/* Bed per Square Kilometer */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 17410+sub13[forind0]*1 ;
  VGV->LEVEL[17410+sub13[forind0]*1] = VGV->LEVEL[41312+sub13[forind0]
*1]/VGV->LEVEL[15412+sub13[forind0]*1] ;
}
/* Normalized Hospital density */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 41363+sub13[forind0]*1 ;
  VGV->LEVEL[41363+sub13[forind0]*1] = VGV->LEVEL[17410+sub13[forind0]
*1]/VGV->LEVEL[51610] ;
}
/* Impact of Population Density on Hospital Availability Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 34372+sub13[forind0]*1 ;
  VGV->LEVEL[34372+sub13[forind0]*1] = VGV->LEVEL[47777+10*51+sub13[forind0]
*1] ;
}
/* COVID Hospital Demand frac */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20658+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[26188+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[20658+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[26188
+sub13[forind0]*3+sub19[forind1]*1],temp0) ;
}
/* Effective Hospital Capacity */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 25726+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[25726+sub13[forind0]*3+sub19[forind1]*1] = MAX(0.100000
,VGV->LEVEL[41312+sub13[forind0]*1]*POWER(VGV->LEVEL[41363+sub13[forind0]
*1],VGV->LEVEL[34372+sub13[forind0]*1])*VGV->LEVEL[20658+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Allocated Fraction COVID Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 14851+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[14851+sub13[forind0]*3+sub19[forind1]*1] = MIN(1.000000
,((-VGV->LEVEL[26188+sub13[forind0]*3+sub19[forind1]*1])+SQRT(POWER(
VGV->LEVEL[26188+sub13[forind0]*3+sub19[forind1]*1],2.000000)+4.000000
*VGV->LEVEL[25726+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[25726
+sub13[forind0]*3+sub19[forind1]*1]))/(2.000000*VGV->LEVEL[25726+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Hospital Admits All */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31051+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[31510
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[14851+sub13[forind0]
*3+sub19[forind1]*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31051+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+1*1] = VGV->LEVEL[31357
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[14851+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Hospital Admission Infectious */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 30439+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[30439+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* MeanFlowOverTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38689+sub13[forind0]*3+0*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[44739+sub13[forind0]*3+sub19[sumind0]*1]+VGV->LEVEL[44585
+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[38689+sub13[forind0]*3+0*1] = temp0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38689+sub13[forind0]*3+1*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[8731+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[38689+sub13[forind0]*3+1*1] = temp0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38689+sub13[forind0]*3+2*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[30439+sub13[forind0]*6+sub19[sumind0]*2+0*1
] ;
  VGV->LEVEL[38689+sub13[forind0]*3+2*1] = temp0 ;
}
/* #DelayedMeanFlowOT>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 463+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[463+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[9598
+sub13[forind0]*3+sub15[forind1]*1]*VGV->LEVEL[38689+sub13[forind0]
*3+sub15[forind1]*1] ;
}
/* #DelayedMeanFlowOT>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 157+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[157+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[463
+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* #DelayedMeanFlowOT>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 310+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[310+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[463
+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* #Frac Post Mortem from Untreated>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 616+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[616+sub13[forind0]*3+sub19[forind1]*1] = (1.000000) ;
}
/* #Fractional Acuity Change>Delay1>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 769+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[769+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[20505
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[59349] ;
}
/* Total Potential Hospital Demand */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60683+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp0 += VGV->LEVEL[45403+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
  VGV->LEVEL[60683+sub13[forind0]*1] = temp0 ;
}
/* #Infected Individuals (I)>SMOOTH# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 922+sub13[forind0]*1 ;
  VGV->LEVEL[922+sub13[forind0]*1] = VGV->LEVEL[60683+sub13[forind0]
*1] ;
}
/* Variant Impact on Immunity Loss Time[BA5] */
 {
  VGV->lastpos = 64322 ;
  VGV->LEVEL[64322+2*1] = VGV->LEVEL[64322+1*1] ;
}
/* Variant Effect on Immunity Loss Time */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64163+sub13[forind0]*1 ;
    temp0 = 1.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 *= 1.000000-RAMP((1.000000-VGV->LEVEL[64322+sub18[sumind0]
*1])/VGV->LEVEL[64584+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]
*3+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1]+VGV->LEVEL[64584+sub18[sumind0]*1]) ;
  VGV->LEVEL[64163+sub13[forind0]*1] = temp0 ;
}
/* Immunity Loss Time Modified */
for(forind0=0;forind0<3;forind0++)
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 33964+sub19[forind0]*51+sub13[forind1]*1 ;
  VGV->LEVEL[33964+sub19[forind0]*51+sub13[forind1]*1] = VGV->LEVEL[33961
+1*1]*VGV->LEVEL[64163+sub13[forind1]*1]*VGV->LEVEL[36064+sub19[forind0]
*1]+VGV->LEVEL[33961+2*1]*VGV->LEVEL[64163+sub13[forind1]*1]*VGV->LEVEL[36075
+sub19[forind0]*1] ;
}
/* #Losing Immunity Confirmed>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 10363+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[10363+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[33964
+sub19[forind1]*51+sub13[forind0]*1]/3.000000 ;
}
/* Tested Untreated Resolution */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58481+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58481+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7711
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[45249] ;
}
/* Base Fatality Rate for Unit Acuity Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 17044+sub13[forind0]*1 ;
  VGV->LEVEL[17044+sub13[forind0]*1] = VGV->LEVEL[47777+14*51+sub13[forind0]
*1] ;
}
/* Baseline Fatality Multiplier */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 17199+sub13[forind0]*1 ;
  VGV->LEVEL[17199+sub13[forind0]*1] = VGV->LEVEL[24802+sub13[forind0]
*1]*VGV->LEVEL[17044+sub13[forind0]*1]*IF_THEN_ELSE(VGV->LEVEL[0]>
VGV->LEVEL[41311],VGV->LEVEL[33807],1.000000) ;
}
/* Probability of Missing Acuity Signal at Hospitals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 47367+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+0*1] = ZIDZ(0,
LN(MAX(1e-06,1.000000-ZIDZ(1,VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]
*2+0*1],VGV->LEVEL[44585+sub13[forind0]*3+sub19[forind1]*1]))),VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1])+1.000000 ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 47367+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+1*1] = ZIDZ(0,
LN(MAX(1e-06,1.000000-ZIDZ(1,VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]
*2+1*1],VGV->LEVEL[43361+sub13[forind0]*3+sub19[forind1]*1]))),VGV->LEVEL[16687
+sub13[forind0]*3+sub19[forind1]*1])+1.000000 ;
}
/* Fraction Poisson not Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29564+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[29564+sub13[forind0]*6+sub19[forind1]*2+0*1] = EXP((-
VGV->LEVEL[16534+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+0*1])) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29564+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[29564+sub13[forind0]*6+sub19[forind1]*2+1*1] = EXP((-
VGV->LEVEL[16687+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+1*1])) ;
}
/* Average Acuity Not Hospitalized Poisson */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16228+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[16228+sub13[forind0]*6+sub19[forind1]*2+0*1] = MAX(0,
VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+0*1]*VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16228+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[16228+sub13[forind0]*6+sub19[forind1]*2+1*1] = MAX(0,
VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+1*1]*VGV->LEVEL[16687
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+1*1]) ;
}
/* Cumulative Cases VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4141+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[4141+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Learning and Death Reduction Rate Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36539+sub13[forind0]*1 ;
  VGV->LEVEL[36539+sub13[forind0]*1] = VGV->LEVEL[47777+23*51+sub13[forind0]
*1] ;
}
/* Time variant change in fatality */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59917+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[59917+sub13[forind0]*1] = MAX(VGV->LEVEL[39404],POWER(
(MAX(VGV->LEVEL[17096],temp0/VGV->LEVEL[43718+sub13[forind0]*1])/VGV->LEVEL[17096
]),((-VGV->LEVEL[36539+sub13[forind0]*1])))) ;
}
/* Fatality Rate Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 26854+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[26854+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = MIN(1.000000,VGV->LEVEL[17199+sub13[forind0]*1]*POWER(VGV->LEVEL[16228
+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1],VGV->LEVEL[53663
+sub13[forind0]*1])*VGV->LEVEL[59917+sub13[forind0]*1]) ;
}
/* Recovery of Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 51100+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[51100+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[58481
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[26854+sub13[forind0]
*6+sub19[forind1]*2+0*1]) ;
}
/* MaxVaxFrac */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38638+sub13[forind0]*1 ;
  VGV->LEVEL[38638+sub13[forind0]*1] = MIN(1.000000,MAX(0.300000,VGV->LEVEL[13473
+sub13[forind0]*1]/VGV->LEVEL[43718+sub13[forind0]*1])) ;
}
/* AntiVaxxerFracOp */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15361+sub13[forind0]*1 ;
  VGV->LEVEL[15361+sub13[forind0]*1] = MIN(0.990000,MAX(0.010000,1.000000
-VGV->LEVEL[64800]*VGV->LEVEL[38638+sub13[forind0]*1])) ;
}
/* Vax Hesitant Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64749+sub13[forind0]*1 ;
  VGV->LEVEL[64749+sub13[forind0]*1] = VGV->LEVEL[15361+sub13[forind0]
*1]*VGV->LEVEL[43718+sub13[forind0]*1] ;
}
/* Frac Unvaccinated Willing */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 28288+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[43973+sub13[forind0]*3+sub21[sumind0]*1] ;
  VGV->LEVEL[28288+sub13[forind0]*1] = MAX(0,1.000000-VGV->LEVEL[64749
+sub13[forind0]*1]/temp0) ;
}
/* Cnf R Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19073+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19073+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[3781
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28288+sub13[forind0]
*1]/VGV->LEVEL[24853]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* First vaccine Date */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27416+sub13[forind0]*1 ;
  VGV->LEVEL[27416+sub13[forind0]*1] = GET_DATA_FIRST_TIME(vecarg_assign(4,&
VGV->LEVEL[23981+sub13[forind0]*1])) ;
}
/* Last vaccine date */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36284+sub13[forind0]*1 ;
  VGV->LEVEL[36284+sub13[forind0]*1] = GET_DATA_LAST_TIME(vecarg_assign(5,&
VGV->LEVEL[23981+sub13[forind0]*1])) ;
}
/* Susceptible Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56278+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56278+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[9088
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[24853]*VGV->LEVEL[28288
+sub13[forind0]*1]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Unconfrimed R Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 62929+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[62929+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[8884
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28288+sub13[forind0]
*1]/VGV->LEVEL[24853]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Hsp R Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 33194+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[33194+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]*VGV->LEVEL[28288+sub13[forind0]*1]/VGV->LEVEL[24853]*VGV->LEVEL[36064
+sub19[forind1]*1] ;
}
/* Total Vax Demand */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 61144+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[56278+sub13[forind0]*3+sub19[sumind0]*1]+VGV->LEVEL[19073
+sub13[forind0]*3+sub19[sumind0]*1]+VGV->LEVEL[62929+sub13[forind0]
*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp1 += VGV->LEVEL[33194+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
  VGV->LEVEL[61144+sub13[forind0]*1] = temp0+temp1 ;
}
/* MaxRcntVacRt */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 7864+sub13[forind0]*1 ;
  VGV->LEVEL[7864+sub13[forind0]*1] = 0 ;
}
/* RecentVaccineRate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8680+sub13[forind0]*1 ;
  VGV->LEVEL[8680+sub13[forind0]*1] = 0 ;
}
/* Feasible Vaccination Supply */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27160+sub13[forind0]*1 ;
  VGV->LEVEL[27160+sub13[forind0]*1] = MIN(VGV->LEVEL[61144+sub13[forind0]
*1],VGV->LEVEL[7864+sub13[forind0]*1]*VGV->LEVEL[65524]+(1.000000-
VGV->LEVEL[65524])*VGV->LEVEL[8680+sub13[forind0]*1]) ;
}
/* MaxVacRate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38587+sub13[forind0]*1 ;
  VGV->LEVEL[38587+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[63541
]<10.000000,0,VGV->LEVEL[43718+sub13[forind0]*1]*(1.000000-VGV->LEVEL[15361
+sub13[forind0]*1])/(VGV->LEVEL[63541]-VGV->LEVEL[28287]*VGV->LEVEL[63541
]/2.000000)) ;
}
/* Total Vaccination Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 61093+sub13[forind0]*1 ;
  VGV->LEVEL[61093+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[63541
]<10.000000,0,VGV->LEVEL[38587+sub13[forind0]*1]*(1.000000-MIN(1.000000
,MAX(0,(VGV->LEVEL[28287]*VGV->LEVEL[63541]-(VGV->LEVEL[0]-VGV->LEVEL[64056
]))/(VGV->LEVEL[63541]*VGV->LEVEL[28287]))))) ;
}
/* Upcoming Vaccination Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 63439+sub13[forind0]*1 ;
  VGV->LEVEL[63439+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[63541
]==0,VGV->LEVEL[27160+sub13[forind0]*1],VGV->LEVEL[61093+sub13[forind0]
*1]) ;
}
/* Active Vaccination Supply */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 13244+sub13[forind0]*1 ;
  VGV->LEVEL[13244+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[27416+sub13[forind0]*1],0,IF_THEN_ELSE(VGV->LEVEL[0]<VGV->LEVEL[36284
+sub13[forind0]*1],VGV->LEVEL[23981+sub13[forind0]*1]*VGV->LEVEL[64800
],VGV->LEVEL[63439+sub13[forind0]*1])) ;
}
/* Frac Vax Demand Fulfilled */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 28339+sub13[forind0]*1 ;
  VGV->LEVEL[28339+sub13[forind0]*1] = MIN(1.000000,XIDZ(0,VGV->LEVEL[13244
+sub13[forind0]*1],VGV->LEVEL[61144+sub13[forind0]*1],1.000000)) ;
}
/* Cnfr R Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19226+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19226+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[19073
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36064+sub19[forind1]*1]-(VGV->LEVEL[19073+sub13[forind0]
*3+0*1]+VGV->LEVEL[19073+sub13[forind0]*3+1*1])*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* #Losing Immunity Confirmed>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 1279+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[1279+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[10363
+sub13[forind0]*3+sub19[forind1]*1]*(VGV->LEVEL[51100+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[19226+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* #Losing Immunity Confirmed>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 973+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[973+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[1279
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Confirmed>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 1126+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[1126+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[1279
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Hospitalized>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[33964+sub19[forind1]*51+sub13[forind0]*1]/3.000000
 ;
}
/* Impact of Treatment on Fatality Rate Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 34474+sub13[forind0]*1 ;
  VGV->LEVEL[34474+sub13[forind0]*1] = VGV->LEVEL[47777+11*51+sub13[forind0]
*1] ;
}
/* TimeVar Impact of Treatment on Fatality */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59968+sub13[forind0]*1 ;
  VGV->LEVEL[59968+sub13[forind0]*1] = VGV->LEVEL[34474+sub13[forind0]
*1]*VGV->LEVEL[59917+sub13[forind0]*1] ;
}
/* Average Acuity Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15463+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1]*XIDZ(0,(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+0*1]*POWER(VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1],2.000000)),1.000000-VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1],2.000000*VGV->LEVEL[47367+sub13[forind0]*6
+sub19[forind1]*2+0*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15463+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]*2+1*1] = ZIDZ(0,
VGV->LEVEL[16687+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+1*1]*POWER(VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+1*1],2.000000)),1.000000-VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+1*1]) ;
}
/* Fatality Rate Treated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 26548+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[26548+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = MIN(1.000000,VGV->LEVEL[17199+sub13[forind0]*1]*VGV->LEVEL[59968
+sub13[forind0]*1]*POWER(VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]
*2+sub16[forind2]*1],VGV->LEVEL[53663+sub13[forind0]*1])) ;
}
/* Hospital Outflow Covid Positive */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 31969+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[31969+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]/VGV->LEVEL[32887] ;
}
/* Hospital Discharges */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = (1.000000-VGV->LEVEL[26548+sub13[forind0]*6+sub19[forind1]*2
+sub16[forind2]*1])*VGV->LEVEL[31969+sub13[forind0]*6+sub19[forind1]
*2+sub16[forind2]*1] ;
}
/* Hsp R Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[33194+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]*VGV->LEVEL[28339+sub13[forind0]*1]*VGV->LEVEL[36064+sub19[forind1]
*1]-(VGV->LEVEL[33194+sub13[forind0]*6+0*2+sub16[forind2]*1]+VGV->LEVEL[33194
+sub13[forind0]*6+1*2+sub16[forind2]*1])*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* #Losing Immunity Hospitalized>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]*(VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]-VGV->LEVEL[33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]) ;
}
/* #Losing Immunity Hospitalized>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 1432+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[1432+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* #Losing Immunity Hospitalized>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 1738+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[1738+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* #Losing Immunity Unconfirmed>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12199+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12199+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[33964
+sub19[forind1]*51+sub13[forind0]*1]/3.000000 ;
}
/* Weighted Infected Post Detection Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65371+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[65371+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7507
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7711+sub13[forind0]
*3+sub19[forind1]*1]+temp0*VGV->LEVEL[45249]/VGV->LEVEL[32887] ;
}
/* Additional Asymptomatic Post Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13728+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[13728+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[65371
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[13881+sub13[forind0]
*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[13881+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Infectious not Tested or in Hospitals Poisson */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 35751+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[35751+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7507
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[13728+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Deaths of Symptomatic Untested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24495+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[24495+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[35751
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[45249]*VGV->LEVEL[26854
+sub13[forind0]*6+sub19[forind1]*2+1*1] ;
}
/* Recovery of Untested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 51253+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[51253+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[7507
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[45249])-VGV->LEVEL[24495
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Unconfirmed Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 62776+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[62776+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[62929
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36064+sub19[forind1]*1]-(VGV->LEVEL[62929+sub13[forind0]
*3+0*1]+VGV->LEVEL[62929+sub13[forind0]*3+1*1])*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* #Losing Immunity Unconfirmed>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2656+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[2656+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[12199
+sub13[forind0]*3+sub19[forind1]*1]*(VGV->LEVEL[51253+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[62776+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* #Losing Immunity Unconfirmed>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2350+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[2350+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2656
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Unconfirmed>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 2503+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[2503+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2656
+sub13[forind0]*3+sub19[forind1]*1] ;
}
}
void mdl_func7(void) ;
void mdl_func7(){
double temp[10];
/* #Recent Relative Contacts>SMOOTHI# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 3115+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[3115+sub13[forind0]*3+sub19[forind1]*1] = (1.000000) ;
}
/* #DelayedMeanFlowOT>DELAY3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9445+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[9445+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[463
+sub13[forind0]*3+sub15[forind1]*1]/VGV->LEVEL[9598+sub13[forind0]
*3+sub15[forind1]*1] ;
}
/* DelayedMeanFlowOT */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24649+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[24649+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[9445
+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* SimulatedFlowAggregate */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 55097+sub15[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[24649+sub13[sumind0]*3+sub15[forind0]*1] ;
  VGV->LEVEL[55097+sub15[forind0]*1] = temp0 ;
}
/* #SimAggregateSmooth>SMOOTH# */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 3268+sub15[forind0]*1 ;
  VGV->LEVEL[3268+sub15[forind0]*1] = VGV->LEVEL[55097+sub15[forind0]
*1] ;
}
/* #Vx S ImmunityLoss>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 12709+sub13[forind0]*1 ;
  VGV->LEVEL[12709+sub13[forind0]*1] = VGV->LEVEL[33964+2*51+sub13[forind0]
*1]/3.000000 ;
}
/* Susceptible Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56431+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56431+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[56278
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Vaccinations */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63594+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63594+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[56431
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Multiplier Transmission Risk for Asymptomatic Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 40175+sub13[forind0]*1 ;
  VGV->LEVEL[40175+sub13[forind0]*1] = VGV->LEVEL[47777+22*51+sub13[forind0]
*1] ;
}
/* Baseline Risk of Transmission by Asymptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17250+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[17250+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17403
]*VGV->LEVEL[40175+sub13[forind0]*1] ;
}
/* Transmission Multiplier Presymptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 61960+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[61960+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[17403
]*VGV->LEVEL[52887])*(1.000000-VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]
*1])+VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[17250
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[52887] ;
}
/* Transmission Multiplier Pre Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 61807+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[61807+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17403
]*(1.000000-VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]*1])+VGV->LEVEL[60274
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[17250+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Poisson Not-tested Asymptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43208+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43208+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[35751
+sub13[forind0]*3+sub19[forind1]*1]*EXP((-VGV->LEVEL[16228+sub13[forind0]
*6+sub19[forind1]*2+1*1])) ;
}
/* Confirmation Impact on Contact Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19430+sub13[forind0]*1 ;
  VGV->LEVEL[19430+sub13[forind0]*1] = VGV->LEVEL[47777+9*51+sub13[forind0]
*1] ;
}
/* Transmission Multiplier for Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 61348+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[61348+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17403
]*VGV->LEVEL[19430+sub13[forind0]*1] ;
}
/* Transmission Multiplier for Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 61501+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[61501+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[17403]*VGV->LEVEL[52886]*IF_THEN_ELSE((COMPREAL)(1+sub16[forind2])
==1.000000,VGV->LEVEL[19430+sub13[forind0]*1],1.000000) ;
}
/* Reference Force of Infection Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 51559+sub13[forind0]*1 ;
  VGV->LEVEL[51559+sub13[forind0]*1] = VGV->LEVEL[47777+2*51+sub13[forind0]
*1] ;
}
/* Dread Factor in Risk Perception Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25317+sub13[forind0]*1 ;
  VGV->LEVEL[25317+sub13[forind0]*1] = VGV->LEVEL[47777+12*51+sub13[forind0]
*1] ;
}
/* Recent Relative Contacts */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50941+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50941+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[3115
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Strength of Adherence Fatigue Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 55765+sub13[forind0]*1 ;
  VGV->LEVEL[55765+sub13[forind0]*1] = VGV->LEVEL[47777+24*51+sub13[forind0]
*1] ;
}
/* Impact of Adherence Fatigue VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34168+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34168+sub13[forind0]*3+sub19[forind1]*1] = POWER(VGV->LEVEL[50941
+sub13[forind0]*3+sub19[forind1]*1],(VGV->LEVEL[55765+sub13[forind0]
*1]*IF_THEN_ELSE(VGV->LEVEL[59814]>VGV->LEVEL[0],1.000000,VGV->LEVEL[56740
]))) ;
}
/* Dread Factor in Risk Perception Nt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 25368+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[25368+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[53092]<VGV->LEVEL[0],(1.000000+VGV->LEVEL[53093]/100.000000
)*VGV->LEVEL[25317+sub13[forind0]*1],VGV->LEVEL[25317+sub13[forind0]
*1])*VGV->LEVEL[34168+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[26392
+sub19[forind1]*1] ;
}
/* Perceived Risk of Life Loss */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8323+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[8323+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Sensitivity of Contact Reduction to Utility Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53559+sub13[forind0]*1 ;
  VGV->LEVEL[53559+sub13[forind0]*1] = VGV->LEVEL[47777+8*51+sub13[forind0]
*1] ;
}
/* Risk threshold for response */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 53094+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[53094+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[53092]<VGV->LEVEL[0],(1.000000-VGV->LEVEL[53093]/100.000000
)*VGV->LEVEL[53559+sub13[forind0]*1],VGV->LEVEL[53559+sub13[forind0]
*1])/VGV->LEVEL[34168+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[26392
+sub19[forind1]*1] ;
}
/* Min Contact Fraction Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 39352+sub13[forind0]*1 ;
  VGV->LEVEL[39352+sub13[forind0]*1] = VGV->LEVEL[47777+7*51+sub13[forind0]
*1] ;
}
/* Voluntary Reduction in Contacts */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 64801+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[64801+sub13[forind0]*3+sub19[forind1]*1] = EXP((-MAX(
0,VGV->LEVEL[25368+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[8323
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[53094+sub13[forind0]
*3+sub19[forind1]*1])))*(1.000000-VGV->LEVEL[39352+sub13[forind0]*1
])+VGV->LEVEL[39352+sub13[forind0]*1] ;
}
/* Contacts Relative to Normal VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19532+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19532+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]<VGV->LEVEL[41311],MIN(VGV->LEVEL[64801+sub13[forind0]
*3+sub19[forind1]*1],VGV->LEVEL[13320+sub13[forind0]*3+sub19[forind1]
*1]),MIN(VGV->LEVEL[64801+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[13320
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[54022])+
VGV->LEVEL[54022]) ;
}
/* Variant Effect on Vx Infectiousness */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64265+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP(VGV->LEVEL[64593+sub18[sumind0]*1]/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[64265+sub13[forind0]*1] = temp0 ;
}
/* Vaccine Effect on Infectiousness */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63747+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63747+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17404
+sub19[forind1]*1]*VGV->LEVEL[36064+sub19[forind1]*1]+(VGV->LEVEL[17404
+2*1]+(1.000000-VGV->LEVEL[17404+2*1])*VGV->LEVEL[64265+sub13[forind0]
*1])*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* Variant Transmission Multiplier[BA5] */
 {
  VGV->lastpos = 64587 ;
  VGV->LEVEL[64587+2*1] = VGV->LEVEL[64587+1*1] ;
}
/* Variants Effect on Transmission */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 64596+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP((VGV->LEVEL[64587+sub18[sumind0]*1]-1.000000)/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[64596+sub13[forind0]*3+sub19[forind1]*1] = 1.000000+temp0
 ;
}
/* Infectious Contacts */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 35598+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1]*VGV->LEVEL[61501+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[35598+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[8476
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[61960+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[7354+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[61807+sub13[forind0]*3+sub19[forind1]*1]+(VGV->LEVEL[13728
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[43208+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[17250+sub13[forind0]*3+sub19[forind1]
*1]+(VGV->LEVEL[35751+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[43208
+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[17403]+VGV->LEVEL[7711
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[61348+sub13[forind0]
*3+sub19[forind1]*1]+temp0)*VGV->LEVEL[51559+sub13[forind0]*1]*SQRT(
VGV->LEVEL[19532+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[63747
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[64596+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Variant Vaccine Effectiveness Reduction[BA5] */
 {
  VGV->lastpos = 64590 ;
  VGV->LEVEL[64590+2*1] = VGV->LEVEL[64590+1*1] ;
}
/* Variant Effect on Vaccine Effectiveness */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64214+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP(VGV->LEVEL[64590+sub18[sumind0]*1]/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[64214+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]>
VGV->LEVEL[41311]&&VGV->LEVEL[56738]==1.000000,1.000000,1.000000+temp0
) ;
}
/* Vaccine Effect on Transmission */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63900+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63900+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17407
+sub19[forind1]*1]*VGV->LEVEL[36064+sub19[forind1]*1]+(1.000000-(1.000000
-VGV->LEVEL[17407+2*1])*VGV->LEVEL[64214+sub13[forind0]*1])*VGV->LEVEL[36075
+sub19[forind1]*1] ;
}
/* Transmissions */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 62113+sub13[forind0]*9+sub19[forind1]*3+sub20[forind2]
*1 ;
  VGV->LEVEL[62113+sub13[forind0]*9+sub19[forind1]*3+sub20[forind2]
*1] = VGV->LEVEL[35598+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[9088
+sub13[forind0]*3+sub20[forind2]*1]*SQRT(VGV->LEVEL[19532+sub13[forind0]
*3+sub20[forind2]*1])/VGV->LEVEL[43718+sub13[forind0]*1]*VGV->LEVEL[63900
+sub13[forind0]*3+sub20[forind2]*1] ;
}
/* Sensitivity to Weather Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53818+sub13[forind0]*1 ;
  VGV->LEVEL[53818+sub13[forind0]*1] = VGV->LEVEL[47777+15*51+sub13[forind0]
*1] ;
}
/* Weather Effect on Transmission */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 65212+sub13[forind0]*1 ;
  VGV->LEVEL[65212+sub13[forind0]*1] = POWER(VGV->LEVEL[20964+sub13[forind0]
*1],VGV->LEVEL[53818+sub13[forind0]*1]) ;
}
/* Infection Deviation */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 7660+sub13[forind0]*1 ;
  VGV->LEVEL[7660+sub13[forind0]*1] = 1.000000 ;
}
/* Infection Adjustment based on Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35240+sub13[forind0]*1 ;
  VGV->LEVEL[35240+sub13[forind0]*1] = VGV->LEVEL[7660+sub13[forind0]
*1]*VGV->LEVEL[56739]+(1.000000-VGV->LEVEL[56739]) ;
}
/* Infection Rate VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 35394+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[62113+sub13[forind0]*9+sub20[sumind0]*3+sub19[forind1]
*1] ;
  VGV->LEVEL[35394+sub13[forind0]*3+sub19[forind1]*1] = temp0*VGV->LEVEL[65212
+sub13[forind0]*1]*VGV->LEVEL[35240+sub13[forind0]*1] ;
}
/* #Vx S ImmunityLoss>DELAY3>LV3# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3373+sub13[forind0]*1 ;
  VGV->LEVEL[3373+sub13[forind0]*1] = VGV->LEVEL[12709+sub13[forind0]
*1]*(VGV->LEVEL[63594+sub13[forind0]*3+2*1]-VGV->LEVEL[35394+sub13[forind0]
*3+2*1]) ;
}
/* #Vx S ImmunityLoss>DELAY3>LV1# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3271+sub13[forind0]*1 ;
  VGV->LEVEL[3271+sub13[forind0]*1] = VGV->LEVEL[3373+sub13[forind0]
*1] ;
}
/* #Vx S ImmunityLoss>DELAY3>LV2# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3322+sub13[forind0]*1 ;
  VGV->LEVEL[3322+sub13[forind0]*1] = VGV->LEVEL[3373+sub13[forind0]
*1] ;
}
/* Accumulated GDP Losses */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3424+sub13[forind0]*1 ;
  VGV->LEVEL[3424+sub13[forind0]*1] = 0 ;
}
/* SW EndoAve */
 {
  VGV->lastpos = 56737 ;
  VGV->LEVEL[56737] = IF_THEN_ELSE((COMPREAL)51>1.000000,1.000000,
0) ;
}
/* ActiveAve */
for(forind0=0;forind0<24;forind0++)
 {
  VGV->lastpos = 13295+sub7[forind0]*1 ;
  VGV->LEVEL[13295+sub7[forind0]*1] = VGV->LEVEL[36155+sub7[forind0]
*1]*(1.000000-VGV->LEVEL[56737])+VGV->LEVEL[56737]*VGV->LEVEL[17512
+sub7[forind0]*1] ;
}
 {
  VGV->lastpos = 13295+3*1 ;
  VGV->LEVEL[13295+3*1] = VGV->LEVEL[36155+3*1] ;
}
/* All Cumulative Recovered at Hospitals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 3475+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[3475+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = 0 ;
}
/* Cost of Deaths Cumulative */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3934+sub13[forind0]*1 ;
  VGV->LEVEL[3934+sub13[forind0]*1] = 0 ;
}
/* Cost of Deaths Cumulative All */
 {
  VGV->lastpos = 3985 ;
  VGV->LEVEL[3985] = 0 ;
}
/* Cost of GDP Cumulative */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 3986+sub13[forind0]*1 ;
  VGV->LEVEL[3986+sub13[forind0]*1] = 0 ;
}
/* Cost of GDP Cumulative All */
 {
  VGV->lastpos = 4037 ;
  VGV->LEVEL[4037] = 0 ;
}
/* Cost of Hospitalizations Cumulative */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 4038+sub13[forind0]*1 ;
  VGV->LEVEL[4038+sub13[forind0]*1] = 0 ;
}
/* Cost of Hospitalizations Cumulative All */
 {
  VGV->lastpos = 4089 ;
  VGV->LEVEL[4089] = 0 ;
}
/* Cumulative APE */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 4090+sub13[forind0]*1 ;
  VGV->LEVEL[4090+sub13[forind0]*1] = 0 ;
}
/* Cumulative Confirmed Cases */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4294+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[4294+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Deaths at Hospital */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 4447+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = 0 ;
}
/* Cumulative Deaths of Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4753+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[4753+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Deaths of Confirmed Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 4906+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[4906+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Deaths Untested Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5059+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[5059+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 5365+sub13[forind0]*1 ;
  VGV->LEVEL[5365+sub13[forind0]*1] = 0 ;
}
/* Cumulative Excess Death */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 5416+sub13[forind0]*1 ;
  VGV->LEVEL[5416+sub13[forind0]*1] = 0 ;
}
/* Cumulative Missed Death */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 5467+sub13[forind0]*1 ;
  VGV->LEVEL[5467+sub13[forind0]*1] = 0 ;
}
/* Cumulative Negative Tests */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5518+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[5518+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Recoveries */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 5977+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[5977+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Tests Conducted */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 6130+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[6130+sub13[forind0]*3+sub19[forind1]*1] = 0 ;
}
/* Cumulative Tests Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6283+sub13[forind0]*1 ;
  VGV->LEVEL[6283+sub13[forind0]*1] = 0 ;
}
/* Cumulative Vaccination */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6334+sub13[forind0]*1 ;
  VGV->LEVEL[6334+sub13[forind0]*1] = 0 ;
}
/* CumulativeOutcomes */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 6385+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]
*1 ;
  VGV->LEVEL[6385+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]*1
] = 0 ;
}
/* Current GDP Output Gap (y) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6844+sub13[forind0]*1 ;
  VGV->LEVEL[6844+sub13[forind0]*1] = VGV->LEVEL[35908+sub13[forind0]
*1] ;
}
/* Data Count */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6895+sub13[forind0]*1 ;
  VGV->LEVEL[6895+sub13[forind0]*1] = 0 ;
}
/* Discount Rate per Day */
 {
  VGV->lastpos = 25264 ;
  VGV->LEVEL[25264] = VGV->LEVEL[25263]/VGV->LEVEL[24033] ;
}
/* Economist Exess Death Err */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 6946+sub13[forind0]*1 ;
  VGV->LEVEL[6946+sub13[forind0]*1] = 0 ;
}
/* Life Expectancy */
 {
  VGV->lastpos = 36692 ;
  VGV->LEVEL[36692] = 80.000000*365.000000 ;
}
/* Expected Death */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 26137+sub13[forind0]*1 ;
  VGV->LEVEL[26137+sub13[forind0]*1] = (VGV->LEVEL[25931+sub13[forind0]
*1]-VGV->LEVEL[26086+sub13[forind0]*1])*VGV->LEVEL[35959+sub13[forind0]
*1]/VGV->LEVEL[36692] ;
}
/* Excess Death Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25982+sub13[forind0]*1 ;
  VGV->LEVEL[25982+sub13[forind0]*1] = VGV->LEVEL[26137+sub13[forind0]
*1]*VGV->LEVEL[30278] ;
}
/* Government Response Start Time */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 30384+sub13[forind0]*1 ;
  VGV->LEVEL[30384+sub13[forind0]*1] = VGV->LEVEL[22601+sub13[forind0]
*1]+VGV->LEVEL[24032] ;
}
/* InpAveErrCmp */
for(forind0=0;forind0<24;forind0++)
 {
  VGV->lastpos = 36079+sub7[forind0]*1 ;
  VGV->LEVEL[36079+sub7[forind0]*1] = (ABS(VGV->LEVEL[17512+sub7[forind0]
*1]-VGV->LEVEL[36155+sub7[forind0]*1])/MAX(1e-06,VGV->LEVEL[17512+sub7[forind0]
*1])*VGV->LEVEL[56737]) ;
}
/* PriorCounts */
for(forind0=0;forind0<24;forind0++)
 {
  VGV->lastpos = 45913+sub7[forind0]*1 ;
  VGV->LEVEL[45913+sub7[forind0]*1] = IF_THEN_ELSE((COMPREAL)(1+sub7[forind0])
<26.000000,1.000000,0) ;
}
/* InpAveErr */
 {
  VGV->lastpos = 36078 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<24;sumind0++)
    temp0 += VGV->LEVEL[36079+sub7[sumind0]*1]*VGV->LEVEL[45913+sub7[sumind0]
*1] ;
  VGV->LEVEL[36078] = temp0 ;
}
/* LastInfDataTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36335+sub13[forind0]*1 ;
  VGV->LEVEL[36335+sub13[forind0]*1] = GET_DATA_LAST_TIME(vecarg_assign(6,&
VGV->LEVEL[23216+sub13[forind0]*3+0*1])) ;
}
/* lastTestData */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36386+sub13[forind0]*1 ;
  VGV->LEVEL[36386+sub13[forind0]*1] = GET_DATA_LAST_TIME(vecarg_assign(7,&
VGV->LEVEL[23828+sub13[forind0]*1])) ;
}
/* Max Infections Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38325+sub13[forind0]*1 ;
  VGV->LEVEL[38325+sub13[forind0]*1] = GET_DATA_ATTRIBUTE(164,vecarg_assign(8,&
VGV->LEVEL[23012+sub13[forind0]*1]),VGV->LEVEL[36010],VGV->LEVEL[27262
]) ;
}
/* DataCmltOverTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22754+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[22754+sub13[forind0]*3+0*1] = VGV->LEVEL[22703+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22754+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[22754+sub13[forind0]*3+1*1] = VGV->LEVEL[22652+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22754+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[22754+sub13[forind0]*3+2*1] = VGV->LEVEL[22907+sub13[forind0]
*1] ;
}
/* MaxData */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38533+sub13[forind0]*1 ;
  VGV->LEVEL[38533+sub13[forind0]*1] = GET_DATA_ATTRIBUTE(164,vecarg_assign(9,&
VGV->LEVEL[22754+sub13[forind0]*3+0*1]),0,500.000000) ;
}
/* MuStock */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 7915+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[7915+sub13[forind0]*3+sub15[forind1]*1] = 0 ;
}
/* Non Economic Mitigation (lt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8068+sub13[forind0]*1 ;
  VGV->LEVEL[8068+sub13[forind0]*1] = 0 ;
}
/* Non Pandemic GDP (xt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 8119+sub13[forind0]*1 ;
  VGV->LEVEL[8119+sub13[forind0]*1] = VGV->LEVEL[50736+sub13[forind0]
*1] ;
}
/* alp */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15157+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[15157+sub13[forind0]*3+0*1] = MIN(VGV->LEVEL[38532],VGV->LEVEL[33806
]*VGV->LEVEL[15310+sub13[forind0]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15157+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[15157+sub13[forind0]*3+1*1] = MIN(1.000000,VGV->LEVEL[22392
]*VGV->LEVEL[15310+sub13[forind0]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15157+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[15157+sub13[forind0]*3+2*1] = MIN(1.000000,VGV->LEVEL[58325
]*VGV->LEVEL[15310+sub13[forind0]*1]) ;
}
/* numTrial */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<2;forind1++)
 {
  VGV->lastpos = 41416+sub13[forind0]*3+sub17[forind1]*1 ;
  VGV->LEVEL[41416+sub13[forind0]*3+sub17[forind1]*1] = MAX(1.010000
,1.000000/VGV->LEVEL[15157+sub13[forind0]*3+sub17[forind1]*1]) ;
}
/* Onset of Symptoms */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 8170+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[8170+sub13[forind0]*3+sub19[forind1]*1] = DELAY_N_i(135,8170
+sub13[forind0]*3+sub19[forind1]*1,0+sub13[forind0]*3+sub19[forind1]
*1,0,VGV->LEVEL[24648]) ;
}
/* PriorErrs */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<25;forind1++)
 {
  VGV->lastpos = 45938+sub13[forind0]*25+sub12[forind1]*1 ;
  VGV->LEVEL[45938+sub13[forind0]*25+sub12[forind1]*1] = POWER(ZIDZ(
0,VGV->LEVEL[13295+sub12[forind1]*1]-VGV->LEVEL[51611+sub12[forind1]
*51+sub13[forind0]*1],(VGV->LEVEL[13168+sub12[forind1]*1]*VGV->LEVEL[55662
])),2.000000)/2.000000 ;
}
/* Sens Chronic Impact Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53352+sub13[forind0]*1 ;
  VGV->LEVEL[53352+sub13[forind0]*1] = VGV->LEVEL[47777+20*51+sub13[forind0]
*1] ;
}
/* Sens Liver Impact Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53404+sub13[forind0]*1 ;
  VGV->LEVEL[53404+sub13[forind0]*1] = VGV->LEVEL[47777+21*51+sub13[forind0]
*1] ;
}
/* Sens Obesity Impact Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53456+sub13[forind0]*1 ;
  VGV->LEVEL[53456+sub13[forind0]*1] = VGV->LEVEL[47777+19*51+sub13[forind0]
*1] ;
}
}
void mdl_func8(void) ;
void mdl_func8(){
double temp[10];
/* simData */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 9037+sub13[forind0]*1 ;
  VGV->LEVEL[9037+sub13[forind0]*1] = 0.001000 ;
}
/* StopDataUseTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 55663+sub13[forind0]*1 ;
  VGV->LEVEL[55663+sub13[forind0]*1] = MAX(VGV->LEVEL[36386+sub13[forind0]
*1],VGV->LEVEL[38531]) ;
}
/* Time to Downgrade Risk Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59404+sub13[forind0]*1 ;
  VGV->LEVEL[59404+sub13[forind0]*1] = VGV->LEVEL[47777+1*51+sub13[forind0]
*1] ;
}
/* Time to Upgrade Risk Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59866+sub13[forind0]*1 ;
  VGV->LEVEL[59866+sub13[forind0]*1] = VGV->LEVEL[47777+0*51+sub13[forind0]
*1] ;
}
/* Variant IFR Multiplier */
for(forind0=0;forind0<2;forind0++)
 {
  VGV->lastpos = 64316+sub1[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[53663+sub13[sumind0]*1] ;
  VGV->LEVEL[64316+sub1[forind0]*1] = POWER(VGV->LEVEL[64160+sub1[forind0]
*1],(temp0/(COMPREAL)51)) ;
}
 {
  VGV->lastpos = 64316+2*1 ;
    temp0 = 1.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 *= VGV->LEVEL[64160+sub18[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp1 += VGV->LEVEL[53663+sub13[sumind0]*1] ;
  VGV->LEVEL[64316+2*1] = POWER(temp0,(temp1/(COMPREAL)51)) ;
}
/* Variant Impact on Transmission */
 {
  VGV->lastpos = 64325+0*1 ;
  VGV->LEVEL[64325+0*1] = VGV->LEVEL[64587+0*1] ;
}
 {
  VGV->lastpos = 64325+1*1 ;
  VGV->LEVEL[64325+1*1] = VGV->LEVEL[64587+1*1]+VGV->LEVEL[64587+0
*1]-1.000000 ;
}
/* Vx IFR Multiplier */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 65005+sub19[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[53663+sub13[sumind0]*1] ;
  VGV->LEVEL[65005+sub19[forind0]*1] = POWER(VGV->LEVEL[40229+sub19[forind0]
*1],(temp0/(COMPREAL)51)) ;
}
/* Weight on Reported Probability of Infection Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 65319+sub13[forind0]*1 ;
  VGV->LEVEL[65319+sub13[forind0]*1] = VGV->LEVEL[47777+5*51+sub13[forind0]
*1] ;
}
} /* comp_init */

/* State variable re-initial value computation*/
void mdl_func9()
{
double temp[10];
/* ActiveAve */
 {
  VGV->lastpos = 13295+3*1 ;
  VGV->LEVEL[13295+3*1] = VGV->LEVEL[36155+3*1] ;
}
/* First Data Date */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27263+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[27263+sub13[forind0]*3+2*1] = VGV->LEVEL[6997+sub13[forind0]
*1] ;
}
/* Sensitivity Post Mortem Testing to Capacity */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53714+sub13[forind0]*1 ;
  VGV->LEVEL[53714+sub13[forind0]*1] = VGV->LEVEL[53816] ;
}
/* RegionalInputs */
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+1*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+1*51+sub13[forind1]*1] = LOG(VGV->LEVEL[59353+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+2*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+2*51+sub13[forind1]*1] = VGV->LEVEL[51508+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+3*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+3*51+sub13[forind1]*1] = VGV->LEVEL[53714+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+4*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+4*51+sub13[forind1]*1] = VGV->LEVEL[17097+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+5*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+5*51+sub13[forind1]*1] = VGV->LEVEL[65268+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+6*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+6*51+sub13[forind1]*1] = VGV->LEVEL[40022+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+7*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+7*51+sub13[forind1]*1] = VGV->LEVEL[39301+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+8*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+8*51+sub13[forind1]*1] = VGV->LEVEL[53508+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+9*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+9*51+sub13[forind1]*1] = VGV->LEVEL[19379+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+10*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+10*51+sub13[forind1]*1] = VGV->LEVEL[34321+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+11*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+11*51+sub13[forind1]*1] = VGV->LEVEL[34423+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+12*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+12*51+sub13[forind1]*1] = LOG(VGV->LEVEL[25266+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+13*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+13*51+sub13[forind1]*1] = VGV->LEVEL[51406+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+15*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+15*51+sub13[forind1]*1] = VGV->LEVEL[53817] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+16*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+16*51+sub13[forind1]*1] = VGV->LEVEL[20250+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+17*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+17*51+sub13[forind1]*1] = VGV->LEVEL[53612+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+19*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+19*51+sub13[forind1]*1] = VGV->LEVEL[53455] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+20*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+20*51+sub13[forind1]*1] = VGV->LEVEL[53351] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+21*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+21*51+sub13[forind1]*1] = VGV->LEVEL[53403] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+22*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+22*51+sub13[forind1]*1] = VGV->LEVEL[40124+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+23*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+23*51+sub13[forind1]*1] = VGV->LEVEL[36488+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+24*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+24*51+sub13[forind1]*1] = VGV->LEVEL[55714+sub13[forind1]
*1] ;
}
/* Variant IFR Multiplier */
 {
  VGV->lastpos = 64316+2*1 ;
    temp0 = 1.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 *= VGV->LEVEL[64160+sub18[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp1 += VGV->LEVEL[53663+sub13[sumind0]*1] ;
  VGV->LEVEL[64316+2*1] = POWER(temp0,(temp1/(COMPREAL)51)) ;
}
/* Variant Impact on Transmission */
 {
  VGV->lastpos = 64325+1*1 ;
  VGV->LEVEL[64325+1*1] = VGV->LEVEL[64587+1*1]+VGV->LEVEL[64587+0
*1]-1.000000 ;
}
} /* comp_reinit */

/*  Active Time Step Equation */
void mdl_func10()
{
double temp[10];
} /* comp_tstep */
/*  Auxiliary variable equations*/
void mdl_func11()
{
double temp[10];
/* #DelayedMeanFlowOT>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9598+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[9598+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[65263
]/3.000000 ;
}
/* #DelayedMeanFlowOT>DELAY3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9445+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[9445+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[463
+sub13[forind0]*3+sub15[forind1]*1]/VGV->LEVEL[9598+sub13[forind0]
*3+sub15[forind1]*1] ;
}
/* #DelayedMeanFlowOT>DELAY3>RT1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9751+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[9751+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[157
+sub13[forind0]*3+sub15[forind1]*1]/VGV->LEVEL[9598+sub13[forind0]
*3+sub15[forind1]*1] ;
}
/* #DelayedMeanFlowOT>DELAY3>RT2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 9904+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[9904+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[310
+sub13[forind0]*3+sub15[forind1]*1]/VGV->LEVEL[9598+sub13[forind0]
*3+sub15[forind1]*1] ;
}
/* #Fractional Acuity Change>Delay1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 10057+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[10057+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[769
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[59349] ;
}
/* Variant Impact on Immunity Loss Time[BA5] */
 {
  VGV->lastpos = 64322 ;
  VGV->LEVEL[64322+2*1] = VGV->LEVEL[64322+1*1] ;
}
/* Variant Intro Start Time All */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64379+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[64379+sub13[forind0]*3+0*1] = VGV->LEVEL[64328+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64379+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[64379+sub13[forind0]*3+1*1] = VGV->LEVEL[64532+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64379+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[64379+sub13[forind0]*3+2*1] = VGV->LEVEL[64583] ;
}
/* Variant Effect on Immunity Loss Time */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64163+sub13[forind0]*1 ;
    temp0 = 1.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 *= 1.000000-RAMP((1.000000-VGV->LEVEL[64322+sub18[sumind0]
*1])/VGV->LEVEL[64584+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]
*3+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1]+VGV->LEVEL[64584+sub18[sumind0]*1]) ;
  VGV->LEVEL[64163+sub13[forind0]*1] = temp0 ;
}
/* Immunity Loss Time Modified */
for(forind0=0;forind0<3;forind0++)
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 33964+sub19[forind0]*51+sub13[forind1]*1 ;
  VGV->LEVEL[33964+sub19[forind0]*51+sub13[forind1]*1] = VGV->LEVEL[33961
+1*1]*VGV->LEVEL[64163+sub13[forind1]*1]*VGV->LEVEL[36064+sub19[forind0]
*1]+VGV->LEVEL[33961+2*1]*VGV->LEVEL[64163+sub13[forind1]*1]*VGV->LEVEL[36075
+sub19[forind0]*1] ;
}
/* #Losing Immunity Confirmed>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 10363+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[10363+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[33964
+sub19[forind1]*51+sub13[forind0]*1]/3.000000 ;
}
/* #Losing Immunity Confirmed>DELAY3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 10210+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[10210+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[1279
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[10363+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Confirmed>DELAY3>RT1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 10516+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[10516+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[973
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[10363+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Confirmed>DELAY3>RT2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 10669+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[10669+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[1126
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[10363+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Hospitalized>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[33964+sub19[forind1]*51+sub13[forind0]*1]/3.000000
 ;
}
/* #Losing Immunity Hospitalized>DELAY3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 10822+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[10822+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[2044+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]/VGV->LEVEL[11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* #Losing Immunity Hospitalized>DELAY3>RT1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 11434+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[11434+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[1432+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]/VGV->LEVEL[11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* #Losing Immunity Hospitalized>DELAY3>RT2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 11740+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[11740+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[1738+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]/VGV->LEVEL[11128+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* #Losing Immunity Unconfirmed>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12199+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12199+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[33964
+sub19[forind1]*51+sub13[forind0]*1]/3.000000 ;
}
/* #Losing Immunity Unconfirmed>DELAY3# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12046+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12046+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2656
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[12199+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Unconfirmed>DELAY3>RT1# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12352+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12352+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2350
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[12199+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* #Losing Immunity Unconfirmed>DELAY3>RT2# */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12505+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12505+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2503
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[12199+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* #Vx S ImmunityLoss>DELAY3>DL# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 12709+sub13[forind0]*1 ;
  VGV->LEVEL[12709+sub13[forind0]*1] = VGV->LEVEL[33964+2*51+sub13[forind0]
*1]/3.000000 ;
}
/* #Vx S ImmunityLoss>DELAY3# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 12658+sub13[forind0]*1 ;
  VGV->LEVEL[12658+sub13[forind0]*1] = VGV->LEVEL[3373+sub13[forind0]
*1]/VGV->LEVEL[12709+sub13[forind0]*1] ;
}
/* #Vx S ImmunityLoss>DELAY3>RT1# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 12760+sub13[forind0]*1 ;
  VGV->LEVEL[12760+sub13[forind0]*1] = VGV->LEVEL[3271+sub13[forind0]
*1]/VGV->LEVEL[12709+sub13[forind0]*1] ;
}
/* #Vx S ImmunityLoss>DELAY3>RT2# */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 12811+sub13[forind0]*1 ;
  VGV->LEVEL[12811+sub13[forind0]*1] = VGV->LEVEL[3322+sub13[forind0]
*1]/VGV->LEVEL[12709+sub13[forind0]*1] ;
}
/* Population VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43973+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp1 += VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[43973+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7354
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7507+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[9088+sub13[forind0]*3+sub19[forind1]
*1]+VGV->LEVEL[8884+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[3781
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7711+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[8476+sub13[forind0]*3+sub19[forind1]
*1]+temp0+temp1 ;
}
/* Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 43718+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[43973+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[43718+sub13[forind0]*1] = temp0 ;
}
/* Recent Detected Infections */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50788+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50788+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2962
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Fraction Covered by Test */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 28391+sub13[forind0]*1 ;
  VGV->LEVEL[28391+sub13[forind0]*1] = MIN(1.000000,POWER((VGV->LEVEL[58480
]*VGV->LEVEL[8629+sub13[forind0]*1]/VGV->LEVEL[43718+sub13[forind0]
*1]),VGV->LEVEL[58479])) ;
}
/* Potential Test Demand from Susceptible Population */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45709+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]*1] = ((VGV->LEVEL[9088
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[8884+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]
*2+1*1])*(VGV->LEVEL[17148+sub13[forind0]*1]+VGV->LEVEL[40073+sub13[forind0]
*1]/VGV->LEVEL[43718+sub13[forind0]*1]*VGV->LEVEL[50788+sub13[forind0]
*3+sub19[forind1]*1]))*VGV->LEVEL[28391+sub13[forind0]*1] ;
}
/* Reaching Testing Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50583+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50583+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7354
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[41570] ;
}
/* Multiplier Vx Acuity Net */
 {
  VGV->lastpos = 40229+0*1 ;
  VGV->LEVEL[40229+0*1] = VGV->LEVEL[40226+0*1] ;
}
 {
  VGV->lastpos = 40229+1*1 ;
  VGV->LEVEL[40229+1*1] = VGV->LEVEL[40226+1*1] ;
}
 {
  VGV->lastpos = 40229+2*1 ;
  VGV->LEVEL[40229+2*1] = VGV->LEVEL[40226+0*1]*VGV->LEVEL[40226+2
*1] ;
}
/* Multiplier Vx Variant */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 40235+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP((VGV->LEVEL[64160+sub18[sumind0]*1]-1.000000)/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[40235+sub13[forind0]*1] = 1.000000+temp0 ;
}
/* Covid Acuity Relative to Flu Nt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20505+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20505+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[20454
+sub13[forind0]*1]*VGV->LEVEL[40229+sub19[forind1]*1]*VGV->LEVEL[40235
+sub13[forind0]*1] ;
}
/* Additional Asymptomatic Relative to Symptomatic Init */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 14034+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[14034+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[60121
+sub13[forind0]*3+sub19[forind1]*1]-EXP((-VGV->LEVEL[20505+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[27674]),1.000000-VGV->LEVEL[60121
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* Additional Asymptomatic Fraction Init */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13575+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[13575+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[14034
+sub13[forind0]*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[14034+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Cumulative Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 21423+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[5212+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[21423+sub13[forind0]*1] = temp0 ;
}
/* Total Sympthoms in Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60785+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[43973+sub13[forind0]*3+sub19[sumind0]*1]*(
1.000000-VGV->LEVEL[13575+sub13[forind0]*3+sub19[sumind0]*1])*VGV->LEVEL[20505
+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[60785+sub13[forind0]*1] = temp0+VGV->LEVEL[57712]*VGV->LEVEL[21423
+sub13[forind0]*1] ;
}
/* Acuity Multiplier due to Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 13524+sub13[forind0]*1 ;
  VGV->LEVEL[13524+sub13[forind0]*1] = 1.000000-VGV->LEVEL[9394+sub13[forind0]
*1]/(VGV->LEVEL[60785+sub13[forind0]*1]) ;
}
/* Average Acuity in Susceptible */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15769+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[15769+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[9241
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[9088+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[13524+sub13[forind0]*1] ;
}
/* Covid Acuity Relative to Flu Final */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20301+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[15769+sub13[forind0]*3+sub19[forind1]*1]==0,VGV->LEVEL[20505
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[15769+sub13[forind0]
*3+sub19[forind1]*1]/(1.000000-VGV->LEVEL[13575+sub13[forind0]*3+sub19[forind1]
*1])) ;
}
/* Covid Acuity */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20097+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[27674
]*VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Total Asymptomatic Fraction Transformed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 60274+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[13575
+sub13[forind0]*3+sub19[forind1]*1]+EXP((-VGV->LEVEL[20097+sub13[forind0]
*3+sub19[forind1]*1]))*(1.000000-VGV->LEVEL[13575+sub13[forind0]*3
+sub19[forind1]*1]) ;
}
/* Additional Asymptomatic Relative to Symptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13881+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[13881+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[60274
+sub13[forind0]*3+sub19[forind1]*1]-EXP((-VGV->LEVEL[20097+sub13[forind0]
*3+sub19[forind1]*1])),1.000000-VGV->LEVEL[60274+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Poisson Subset Reaching Test Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43514+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43514+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[50583
+sub13[forind0]*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[13881+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Positive Candidates Interested in Testing Poisson Subset */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44126+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43514
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28391+sub13[forind0]
*1] ;
}
/* Positive Candidates Interested in Testing Poisson Subset Adj */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44279+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44279+sub13[forind0]*3+sub19[forind1]*1] = MAX(0.001000
*VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[44126
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* a */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 12862+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]*1] = XIDZ(0,VGV->LEVEL[45709
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[44279+sub13[forind0]
*3+sub19[forind1]*1],1.000000) ;
}
/* DataCmltOverTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22754+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[22754+sub13[forind0]*3+0*1] = VGV->LEVEL[22703+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22754+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[22754+sub13[forind0]*3+1*1] = VGV->LEVEL[22652+sub13[forind0]
*1] ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22754+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[22754+sub13[forind0]*3+2*1] = VGV->LEVEL[22907+sub13[forind0]
*1] ;
}
/* ThrsInc */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59298+sub13[forind0]*1 ;
  VGV->LEVEL[59298+sub13[forind0]*1] = MAX(VGV->LEVEL[28390]*VGV->LEVEL[38533
+sub13[forind0]*1],50.000000) ;
}
/* First Data Date */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27263+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[27263+sub13[forind0]*3+2*1] = VGV->LEVEL[6997+sub13[forind0]
*1] ;
}
/* DataLimitFromTime */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 23675+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[23675+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]>VGV->LEVEL[55663+sub13[forind0]*1]||VGV->LEVEL[0]<=VGV->LEVEL[27263
+sub13[forind0]*3+sub15[forind1]*1],0,1.000000) ;
}
/* DataIncluded */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 23471+sub13[forind0]*3+sub15[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[5212+sub13[forind0]*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[4294+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[23471+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
MAX(temp0,MAX(temp1,VGV->LEVEL[22754+sub13[forind0]*3+0*1]))>VGV->LEVEL[59298
+sub13[forind0]*1],1.000000,0)*VGV->LEVEL[23675+sub13[forind0]*3+sub15[forind1]
*1] ;
}
/* Post Mortem Testing Need */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45045+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[45045+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[2809
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* MinTestRateFromCases */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 39410+sub13[forind0]*1 ;
  VGV->LEVEL[39410+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[27263+sub13[forind0]*3+0*1],0,VGV->LEVEL[23012+sub13[forind0]
*1]*VGV->LEVEL[39409]) ;
}
/* Policy Test Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 43667+sub13[forind0]*1 ;
  VGV->LEVEL[43667+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[41310],VGV->LEVEL[22239+sub13[forind0]*1],VGV->LEVEL[27211
+sub13[forind0]*1]) ;
}
/* External Test Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 26341+sub13[forind0]*1 ;
  VGV->LEVEL[26341+sub13[forind0]*1] = VGV->LEVEL[43718+sub13[forind0]
*1]*VGV->LEVEL[43667+sub13[forind0]*1] ;
}
/* Active Test Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 13193+sub13[forind0]*1 ;
  VGV->LEVEL[13193+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[41310],IF_THEN_ELSE(VGV->LEVEL[0]<VGV->LEVEL[36437+sub13[forind0]
*1],MAX(VGV->LEVEL[23828+sub13[forind0]*1],VGV->LEVEL[39410+sub13[forind0]
*1]),VGV->LEVEL[8629+sub13[forind0]*1]),VGV->LEVEL[26341+sub13[forind0]
*1]) ;
}
}
void mdl_func12(void) ;
void mdl_func12(){
double temp[10];
/* Post Mortem Tests Total */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 45198+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[45045+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[45198+sub13[forind0]*1] = MIN(temp0,VGV->LEVEL[13193+sub13[forind0]
*1]) ;
}
/* Frac PM Need VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 27981+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[45045+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[27981+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[45045
+sub13[forind0]*3+sub19[forind1]*1],temp0) ;
}
/* Post Mortem Test Rate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44739+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44739+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[45198
+sub13[forind0]*1]*VGV->LEVEL[27981+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[53611] ;
}
/* Testing Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58787+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58787+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44126
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[57713+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[57866+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Test Demand Fraction */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58326+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[58787+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[58326+sub13[forind0]*3+sub19[forind1]*1] = XIDZ(0,VGV->LEVEL[58787
+sub13[forind0]*3+sub19[forind1]*1],temp0,1.000000/3.000000) ;
}
/* Testing Capacity Net of Post Mortem Tests */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58634+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58634+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[13193
+sub13[forind0]*1]-VGV->LEVEL[45198+sub13[forind0]*1])*VGV->LEVEL[58326
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Testing on Living */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58940+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58940+sub13[forind0]*3+sub19[forind1]*1] = MIN(VGV->LEVEL[58634
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[58787+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* b */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16840+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[44279+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]
*1],VGV->LEVEL[44279+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* t3 */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58172+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58172+sub13[forind0]*3+sub19[forind1]*1] = POWER(((-9.000000)
*VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]*1]+1.732100*SQRT(
MAX(0,4.000000*POWER(VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]
*1],3.000000)+27.000000*POWER(VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]
*1],2.000000)))),(1.000000/3.000000)) ;
}
/* Ymix */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65730+sub13[forind0]*9+sub19[forind1]*3+0*1 ;
  VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]*3+0*1] = (-VGV->LEVEL[16840
+sub13[forind0]*3+sub19[forind1]*1])/(1.000000+VGV->LEVEL[12862+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65730+sub13[forind0]*9+sub19[forind1]*3+1*1 ;
  VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]*3+1*1] = (SQRT(
POWER(VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]*1],2.000000
)-4.000000*VGV->LEVEL[16840+sub13[forind0]*3+sub19[forind1]*1])-VGV->LEVEL[12862
+sub13[forind0]*3+sub19[forind1]*1])/2.000000 ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65730+sub13[forind0]*9+sub19[forind1]*3+2*1 ;
  VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]*3+2*1] = ((-0.873580)
*VGV->LEVEL[12862+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[58172
+sub13[forind0]*3+sub19[forind1]*1]+0.381570*VGV->LEVEL[58172+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* lnymix */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 36693+sub13[forind0]*9+sub19[forind1]*3+sub0[forind2]
*1 ;
  VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]*3+sub0[forind2]
*1] = (-LN(MAX(1e-06,1.000000-VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]
*3+sub0[forind2]*1]))) ;
}
/* cft */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17537+sub13[forind0]*9+sub19[forind1]*3+0*1 ;
  VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+0*1] = VGV->LEVEL[36693
+sub13[forind0]*9+sub19[forind1]*3+0*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17537+sub13[forind0]*9+sub19[forind1]*3+1*1 ;
  VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+1*1] = VGV->LEVEL[36693
+sub13[forind0]*9+sub19[forind1]*3+1*1]-VGV->LEVEL[36693+sub13[forind0]
*9+sub19[forind1]*3+0*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 17537+sub13[forind0]*9+sub19[forind1]*3+2*1 ;
  VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+2*1] = (LN(MIN(
100.000000,MAX(1e-06,ZIDZ(0,VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]
*3+2*1]-VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]*3+0*1],VGV->LEVEL[36693
+sub13[forind0]*9+sub19[forind1]*3+1*1]-VGV->LEVEL[36693+sub13[forind0]
*9+sub19[forind1]*3+0*1])/LN(2.000000))))) ;
}
/* Extrapolated Estimator */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 26395+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[26395+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]*1]>1.000000,VGV->LEVEL[17537
+sub13[forind0]*9+sub19[forind1]*3+0*1]+VGV->LEVEL[17537+sub13[forind0]
*9+sub19[forind1]*3+1*1]*POWER((VGV->LEVEL[20301+sub13[forind0]*3+sub19[forind1]
*1]-1.000000),VGV->LEVEL[17537+sub13[forind0]*9+sub19[forind1]*3+2
*1]),VGV->LEVEL[36693+sub13[forind0]*9+sub19[forind1]*3+0*1]) ;
}
/* Y */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65577+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[65577+sub13[forind0]*3+sub19[forind1]*1] = MIN(1.000000
,MAX(1e-06,1.000000-EXP((-VGV->LEVEL[26395+sub13[forind0]*3+sub19[forind1]
*1])))) ;
}
/* Prob Missing Symptom */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 47214+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[47214+sub13[forind0]*3+sub19[forind1]*1] = MAX(0,LN(VGV->LEVEL[65577
+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[27674]+1.000000) ;
}
/* Indicated fraction negative demand tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34526+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34526+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-EXP(
VGV->LEVEL[27674]*(VGV->LEVEL[47214+sub13[forind0]*3+sub19[forind1]
*1]-1.000000)) ;
}
/* Indicated fraction positive demand tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34679+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34679+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-EXP(
VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]*1]*(VGV->LEVEL[47214
+sub13[forind0]*3+sub19[forind1]*1]-1.000000)) ;
}
/* Tests on Negative Patients */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 59093+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[59093+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]*ZIDZ(0,VGV->LEVEL[34526+sub13[forind0]
*3+sub19[forind1]*1]*VGV->LEVEL[45709+sub13[forind0]*3+sub19[forind1]
*1],VGV->LEVEL[34526+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[45709
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[34679+sub13[forind0]
*3+sub19[forind1]*1]*VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Total Test on Covid Patients */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 60836+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[60836+sub13[forind0]*3+sub19[forind1]*1] = MAX(0,MIN(
VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[59093+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Fraction Interested not Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 28901+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-IF_THEN_ELSE(
VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1]<1e-20,0,VGV->LEVEL[60836
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[44126+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Fraction Interseted not Correctly Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29054+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[29054+sub13[forind0]*3+sub19[forind1]*1] = 1.000000-(
1.000000-VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[53611
] ;
}
/* Positive Tests of Infected */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44585+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44585+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44126
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[29054+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Average Acuity of Positively Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16534+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[16534+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[44126+sub13[forind0]*3+sub19[forind1]*1]==0,VGV->LEVEL[20097
+sub13[forind0]*3+0*1],VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]
*1]*MAX(1.000000,(XIDZ(0,(1.000000-VGV->LEVEL[47214+sub13[forind0]
*3+sub19[forind1]*1]*POWER(VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]
*1],2.000000)),1.000000-VGV->LEVEL[28901+sub13[forind0]*3+sub19[forind1]
*1],2.000000*VGV->LEVEL[47214+sub13[forind0]*3+sub19[forind1]*1]))
)) ;
}
/* PMAS Confirmed for Hospital Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42647+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42647+sub13[forind0]*3+sub19[forind1]*1] = POWER((1.000000
-VGV->LEVEL[51457+sub13[forind0]*1]),(1.000000/VGV->LEVEL[16534+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Hospital Demand from Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31510+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[31510+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44585
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-EXP((-VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[42647+sub13[forind0]
*3+sub19[forind1]*1]))) ;
}
/* Poisson Subset Not Tested Passing Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43361+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43361+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43514
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[44585+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Average Acuity of Untested Poisson Subset */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16687+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[16687+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[43514
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[20097+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[44585+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[16534+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[43361
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* Allocated Fration NonCOVID Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15004+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[15004+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[1
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Untested PMAS Gap with Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63082+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63082+sub13[forind0]*3+sub19[forind1]*1] = POWER((1.000000
-VGV->LEVEL[15004+sub13[forind0]*3+sub19[forind1]*1]),VGV->LEVEL[53507
]) ;
}
/* PMAS Unconfirmed for Hospital Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42800+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42800+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[42647
+sub13[forind0]*3+sub19[forind1]*1]+(1.000000-VGV->LEVEL[42647+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[63082+sub13[forind0]*3+sub19[forind1]
*1] ;
}
/* Hospital Demand from Not Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31357+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[31357+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43361
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-EXP((-VGV->LEVEL[16687
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[42800+sub13[forind0]
*3+sub19[forind1]*1]))) ;
}
/* Potential Hospital Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45403+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+1*1] = VGV->LEVEL[31357
+sub13[forind0]*3+sub19[forind1]*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45403+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[31510
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Expected Positive Poisson Covid Patients */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 26188+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[26188+sub13[forind0]*3+sub19[forind1]*1] = temp0*VGV->LEVEL[45249
] ;
}
/* COVID Hospital Demand frac */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20658+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[26188+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[20658+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[26188
+sub13[forind0]*3+sub19[forind1]*1],temp0) ;
}
/* Effective Hospital Capacity */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 25726+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[25726+sub13[forind0]*3+sub19[forind1]*1] = MAX(0.100000
,VGV->LEVEL[41312+sub13[forind0]*1]*POWER(VGV->LEVEL[41363+sub13[forind0]
*1],VGV->LEVEL[34372+sub13[forind0]*1])*VGV->LEVEL[20658+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Allocated Fraction COVID Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 14851+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[14851+sub13[forind0]*3+sub19[forind1]*1] = MIN(1.000000
,((-VGV->LEVEL[26188+sub13[forind0]*3+sub19[forind1]*1])+SQRT(POWER(
VGV->LEVEL[26188+sub13[forind0]*3+sub19[forind1]*1],2.000000)+4.000000
*VGV->LEVEL[25726+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[25726
+sub13[forind0]*3+sub19[forind1]*1]))/(2.000000*VGV->LEVEL[25726+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Hospital Admits All */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31051+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[31510
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[14851+sub13[forind0]
*3+sub19[forind1]*1] ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 31051+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+1*1] = VGV->LEVEL[31357
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[14851+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Hospital Admission Infectious */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 30439+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[30439+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* MeanFlowOverTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38689+sub13[forind0]*3+0*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[44739+sub13[forind0]*3+sub19[sumind0]*1]+VGV->LEVEL[44585
+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[38689+sub13[forind0]*3+0*1] = temp0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38689+sub13[forind0]*3+1*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[8731+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[38689+sub13[forind0]*3+1*1] = temp0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38689+sub13[forind0]*3+2*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[30439+sub13[forind0]*6+sub19[sumind0]*2+0*1
] ;
  VGV->LEVEL[38689+sub13[forind0]*3+2*1] = temp0 ;
}
/* FlowResiduals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 27518+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[27518+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[23216+sub13[forind0]*3+sub15[forind1]*1]==NA,NA,VGV->LEVEL[23216
+sub13[forind0]*3+sub15[forind1]*1]-VGV->LEVEL[38689+sub13[forind0]
*3+sub15[forind1]*1]) ;
}
/* AbsPrcErr */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13015+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[13015+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[23471+sub13[forind0]*3+sub15[forind1]*1]==0,NA,ZIDZ(0,ABS(
VGV->LEVEL[27518+sub13[forind0]*3+sub15[forind1]*1]),VGV->LEVEL[23216
+sub13[forind0]*3+sub15[forind1]*1])) ;
}
/* MaxVaxFrac */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38638+sub13[forind0]*1 ;
  VGV->LEVEL[38638+sub13[forind0]*1] = MIN(1.000000,MAX(0.300000,VGV->LEVEL[13473
+sub13[forind0]*1]/VGV->LEVEL[43718+sub13[forind0]*1])) ;
}
/* AntiVaxxerFracOp */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15361+sub13[forind0]*1 ;
  VGV->LEVEL[15361+sub13[forind0]*1] = MIN(0.990000,MAX(0.010000,1.000000
-VGV->LEVEL[64800]*VGV->LEVEL[38638+sub13[forind0]*1])) ;
}
/* Vax Hesitant Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64749+sub13[forind0]*1 ;
  VGV->LEVEL[64749+sub13[forind0]*1] = VGV->LEVEL[15361+sub13[forind0]
*1]*VGV->LEVEL[43718+sub13[forind0]*1] ;
}
/* Frac Unvaccinated Willing */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 28288+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[43973+sub13[forind0]*3+sub21[sumind0]*1] ;
  VGV->LEVEL[28288+sub13[forind0]*1] = MAX(0,1.000000-VGV->LEVEL[64749
+sub13[forind0]*1]/temp0) ;
}
/* Susceptible Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56278+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56278+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[9088
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[24853]*VGV->LEVEL[28288
+sub13[forind0]*1]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Cnf R Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19073+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19073+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[3781
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28288+sub13[forind0]
*1]/VGV->LEVEL[24853]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Unconfrimed R Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 62929+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[62929+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[8884
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28288+sub13[forind0]
*1]/VGV->LEVEL[24853]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Hsp R Demand */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 33194+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[33194+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]*VGV->LEVEL[28288+sub13[forind0]*1]/VGV->LEVEL[24853]*VGV->LEVEL[36064
+sub19[forind1]*1] ;
}
/* Total Vax Demand */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 61144+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[56278+sub13[forind0]*3+sub19[sumind0]*1]+VGV->LEVEL[19073
+sub13[forind0]*3+sub19[sumind0]*1]+VGV->LEVEL[62929+sub13[forind0]
*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp1 += VGV->LEVEL[33194+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
  VGV->LEVEL[61144+sub13[forind0]*1] = temp0+temp1 ;
}
/* Feasible Vaccination Supply */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27160+sub13[forind0]*1 ;
  VGV->LEVEL[27160+sub13[forind0]*1] = MIN(VGV->LEVEL[61144+sub13[forind0]
*1],VGV->LEVEL[7864+sub13[forind0]*1]*VGV->LEVEL[65524]+(1.000000-
VGV->LEVEL[65524])*VGV->LEVEL[8680+sub13[forind0]*1]) ;
}
/* Total Vaccination Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 61093+sub13[forind0]*1 ;
  VGV->LEVEL[61093+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[63541
]<10.000000,0,VGV->LEVEL[38587+sub13[forind0]*1]*(1.000000-MIN(1.000000
,MAX(0,(VGV->LEVEL[28287]*VGV->LEVEL[63541]-(VGV->LEVEL[0]-VGV->LEVEL[64056
]))/(VGV->LEVEL[63541]*VGV->LEVEL[28287]))))) ;
}
/* Upcoming Vaccination Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 63439+sub13[forind0]*1 ;
  VGV->LEVEL[63439+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[63541
]==0,VGV->LEVEL[27160+sub13[forind0]*1],VGV->LEVEL[61093+sub13[forind0]
*1]) ;
}
/* Active Vaccination Supply */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 13244+sub13[forind0]*1 ;
  VGV->LEVEL[13244+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[27416+sub13[forind0]*1],0,IF_THEN_ELSE(VGV->LEVEL[0]<VGV->LEVEL[36284
+sub13[forind0]*1],VGV->LEVEL[23981+sub13[forind0]*1]*VGV->LEVEL[64800
],VGV->LEVEL[63439+sub13[forind0]*1])) ;
}
/* ActiveAve */
 {
  VGV->lastpos = 13295+3*1 ;
  VGV->LEVEL[13295+3*1] = VGV->LEVEL[36155+3*1] ;
}
/* Weighted Infected Post Detection Gate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65371+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[65371+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7507
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7711+sub13[forind0]
*3+sub19[forind1]*1]+temp0*VGV->LEVEL[45249]/VGV->LEVEL[32887] ;
}
/* Additional Asymptomatic Post Detection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 13728+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[13728+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[65371
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[13881+sub13[forind0]
*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[13881+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Adj */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14188+sub13[forind0]*1 ;
  VGV->LEVEL[14188+sub13[forind0]*1] = (VGV->LEVEL[42953+sub13[forind0]
*5+0*1]-VGV->LEVEL[9037+sub13[forind0]*1])/VGV->LEVEL[42953+sub13[forind0]
*5+4*1] ;
}
/* Adj to Baseline */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14239+sub13[forind0]*1 ;
  VGV->LEVEL[14239+sub13[forind0]*1] = (1.000000-VGV->LEVEL[7660+sub13[forind0]
*1])/VGV->LEVEL[59350] ;
}
/* Time to Adj to Data */
 {
  VGV->lastpos = 59351 ;
  VGV->LEVEL[59351] = VGV->LEVEL[59349] ;
}
/* Data to Model Ratio of Infection */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22495+sub13[forind0]*1 ;
  VGV->LEVEL[22495+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[23216
+sub13[forind0]*3+0*1]==NA,NA,MAX(1.000000/VGV->LEVEL[38584],MIN(VGV->LEVEL[38584
],XIDZ(0,VGV->LEVEL[23216+sub13[forind0]*3+0*1],VGV->LEVEL[38689+sub13[forind0]
*3+0*1],1.000000)))) ;
}
/* Adj to Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14290+sub13[forind0]*1 ;
  VGV->LEVEL[14290+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]>
VGV->LEVEL[36335+sub13[forind0]*1],(EXP(VGV->LEVEL[9037+sub13[forind0]
*1])-VGV->LEVEL[7660+sub13[forind0]*1])/VGV->LEVEL[59351]*IF_THEN_ELSE(
VGV->LEVEL[41415]==1000000.000000,0,1.000000),IF_THEN_ELSE(VGV->LEVEL[22495
+sub13[forind0]*1]==NA,0,(VGV->LEVEL[22495+sub13[forind0]*1]-VGV->LEVEL[7660
+sub13[forind0]*1])/VGV->LEVEL[59351])) ;
}
/* adjSp */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14341+sub13[forind0]*1 ;
  VGV->LEVEL[14341+sub13[forind0]*1] = MIN(1.000000,1.000000/EXP(VGV->LEVEL[42953
+sub13[forind0]*5+2*1]+ABS(VGV->LEVEL[9037+sub13[forind0]*1])*VGV->LEVEL[42953
+sub13[forind0]*5+3*1])) ;
}
/* SwitchRandFlowTime */
 {
  VGV->lastpos = 56793 ;
  VGV->LEVEL[56793] = IF_THEN_ELSE(VGV->LEVEL[56792]==1.000000,MIN(
VGV->LEVEL[38531],VGV->LEVEL[50582]),10000.000000) ;
}
/* alp */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15157+sub13[forind0]*3+0*1 ;
  VGV->LEVEL[15157+sub13[forind0]*3+0*1] = MIN(VGV->LEVEL[38532],VGV->LEVEL[33806
]*VGV->LEVEL[15310+sub13[forind0]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15157+sub13[forind0]*3+1*1 ;
  VGV->LEVEL[15157+sub13[forind0]*3+1*1] = MIN(1.000000,VGV->LEVEL[22392
]*VGV->LEVEL[15310+sub13[forind0]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 15157+sub13[forind0]*3+2*1 ;
  VGV->LEVEL[15157+sub13[forind0]*3+2*1] = MIN(1.000000,VGV->LEVEL[58325
]*VGV->LEVEL[15310+sub13[forind0]*1]) ;
}
/* MeanFlowOverTimeVS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 38842+sub13[forind0]*9+sub19[forind1]*3+0*1 ;
  VGV->LEVEL[38842+sub13[forind0]*9+sub19[forind1]*3+0*1] = (VGV->LEVEL[44739
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[44585+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 38842+sub13[forind0]*9+sub19[forind1]*3+1*1 ;
  VGV->LEVEL[38842+sub13[forind0]*9+sub19[forind1]*3+1*1] = (VGV->LEVEL[8731
+sub13[forind0]*3+sub19[forind1]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 38842+sub13[forind0]*9+sub19[forind1]*3+2*1 ;
  VGV->LEVEL[38842+sub13[forind0]*9+sub19[forind1]*3+2*1] = VGV->LEVEL[30439
+sub13[forind0]*6+sub19[forind1]*2+0*1] ;
}
/* successP */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 55816+sub13[forind0]*9+sub19[forind1]*3+sub17[forind2]
*1 ;
  VGV->LEVEL[55816+sub13[forind0]*9+sub19[forind1]*3+sub17[forind2]
*1] = 1.000000/(1.000000+VGV->LEVEL[15157+sub13[forind0]*3+sub17[forind2]
*1]*VGV->LEVEL[38842+sub13[forind0]*9+sub19[forind1]*3+sub17[forind2]
*1]) ;
}
/* SimFlowOverTime VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 54485+sub13[forind0]*9+sub19[forind1]*3+sub17[forind2]
*1 ;
  VGV->LEVEL[54485+sub13[forind0]*9+sub19[forind1]*3+sub17[forind2]
*1] = IF_THEN_ELSE(VGV->LEVEL[56793]<VGV->LEVEL[0],RANDOM_NEGATIVE_BINOMIAL(
(-1.000000),1000000.000000,VGV->LEVEL[55816+sub13[forind0]*9+sub19[forind1]
*3+sub17[forind2]*1],VGV->LEVEL[41416+sub13[forind0]*3+sub17[forind2]
*1],0,1.000000,VGV->LEVEL[41415]),VGV->LEVEL[38842+sub13[forind0]*9
+sub19[forind1]*3+sub17[forind2]*1]) ;
}
/* Tested Untreated Resolution */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58481+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58481+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7711
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[45249] ;
}
/* Baseline Fatality Multiplier */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 17199+sub13[forind0]*1 ;
  VGV->LEVEL[17199+sub13[forind0]*1] = VGV->LEVEL[24802+sub13[forind0]
*1]*VGV->LEVEL[17044+sub13[forind0]*1]*IF_THEN_ELSE(VGV->LEVEL[0]>
VGV->LEVEL[41311],VGV->LEVEL[33807],1.000000) ;
}
/* Probability of Missing Acuity Signal at Hospitals */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 47367+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+0*1] = ZIDZ(0,
LN(MAX(1e-06,1.000000-ZIDZ(1,VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]
*2+0*1],VGV->LEVEL[44585+sub13[forind0]*3+sub19[forind1]*1]))),VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1])+1.000000 ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 47367+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+1*1] = ZIDZ(0,
LN(MAX(1e-06,1.000000-ZIDZ(1,VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]
*2+1*1],VGV->LEVEL[43361+sub13[forind0]*3+sub19[forind1]*1]))),VGV->LEVEL[16687
+sub13[forind0]*3+sub19[forind1]*1])+1.000000 ;
}
/* Fraction Poisson not Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29564+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[29564+sub13[forind0]*6+sub19[forind1]*2+0*1] = EXP((-
VGV->LEVEL[16534+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+0*1])) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29564+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[29564+sub13[forind0]*6+sub19[forind1]*2+1*1] = EXP((-
VGV->LEVEL[16687+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+1*1])) ;
}
/* Average Acuity Not Hospitalized Poisson */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16228+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[16228+sub13[forind0]*6+sub19[forind1]*2+0*1] = MAX(0,
VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+0*1]*VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 16228+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[16228+sub13[forind0]*6+sub19[forind1]*2+1*1] = MAX(0,
VGV->LEVEL[47367+sub13[forind0]*6+sub19[forind1]*2+1*1]*VGV->LEVEL[16687
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+1*1]) ;
}
/* Time variant change in fatality */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59917+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[59917+sub13[forind0]*1] = MAX(VGV->LEVEL[39404],POWER(
(MAX(VGV->LEVEL[17096],temp0/VGV->LEVEL[43718+sub13[forind0]*1])/VGV->LEVEL[17096
]),((-VGV->LEVEL[36539+sub13[forind0]*1])))) ;
}
/* Fatality Rate Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 26854+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[26854+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = MIN(1.000000,VGV->LEVEL[17199+sub13[forind0]*1]*POWER(VGV->LEVEL[16228
+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]*1],VGV->LEVEL[53663
+sub13[forind0]*1])*VGV->LEVEL[59917+sub13[forind0]*1]) ;
}
/* Deaths of Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24342+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[24342+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[58481
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[26854+sub13[forind0]
*6+sub19[forind1]*2+0*1] ;
}
/* Infectious not Tested or in Hospitals Poisson */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 35751+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[35751+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7507
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[13728+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Deaths of Symptomatic Untested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24495+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[24495+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[35751
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[45249]*VGV->LEVEL[26854
+sub13[forind0]*6+sub19[forind1]*2+1*1] ;
}
/* TimeVar Impact of Treatment on Fatality */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59968+sub13[forind0]*1 ;
  VGV->LEVEL[59968+sub13[forind0]*1] = VGV->LEVEL[34474+sub13[forind0]
*1]*VGV->LEVEL[59917+sub13[forind0]*1] ;
}
/* Average Acuity Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15463+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[16534
+sub13[forind0]*3+sub19[forind1]*1]*XIDZ(0,(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+0*1]*POWER(VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1],2.000000)),1.000000-VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1],2.000000*VGV->LEVEL[47367+sub13[forind0]*6
+sub19[forind1]*2+0*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15463+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]*2+1*1] = ZIDZ(0,
VGV->LEVEL[16687+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[47367
+sub13[forind0]*6+sub19[forind1]*2+1*1]*POWER(VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+1*1],2.000000)),1.000000-VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+1*1]) ;
}
/* Fatality Rate Treated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 26548+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[26548+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = MIN(1.000000,VGV->LEVEL[17199+sub13[forind0]*1]*VGV->LEVEL[59968
+sub13[forind0]*1]*POWER(VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]
*2+sub16[forind2]*1],VGV->LEVEL[53663+sub13[forind0]*1])) ;
}
/* Hospital Outflow Covid Positive */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 31969+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[31969+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]/VGV->LEVEL[32887] ;
}
/* Hospitalized Infectious Deaths */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 32581+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[26548+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]*VGV->LEVEL[31969+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] ;
}
/* Death Rate VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24086+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[24086+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[24342
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[24495+sub13[forind0]
*3+sub19[forind1]*1]+temp0 ;
}
/* Aggregate Death Hazard */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14545+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[54485+sub13[forind0]*9+sub19[sumind0]*3+1*1
] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[24086+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[14545+sub13[forind0]*1] = (VGV->LEVEL[65319+sub13[forind0]
*1]*temp0+(1.000000-VGV->LEVEL[65319+sub13[forind0]*1])*temp1)/VGV->LEVEL[43718
+sub13[forind0]*1] ;
}
}
void mdl_func13(void) ;
void mdl_func13(){
double temp[10];
/* Recovery of Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 51100+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[51100+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[58481
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[26854+sub13[forind0]
*6+sub19[forind1]*2+0*1]) ;
}
/* Recovery of Untested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 51253+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[51253+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[7507
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[45249])-VGV->LEVEL[24495
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Hospital Discharges */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = (1.000000-VGV->LEVEL[26548+sub13[forind0]*6+sub19[forind1]*2
+sub16[forind2]*1])*VGV->LEVEL[31969+sub13[forind0]*6+sub19[forind1]
*2+sub16[forind2]*1] ;
}
/* All Recovery */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 14647+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[31663+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[14647+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[51100
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[51253+sub13[forind0]
*3+sub19[forind1]*1]+temp0 ;
}
/* All Recoveries */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14596+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[14647+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[14596+sub13[forind0]*1] = temp0 ;
}
/* Frac Vax Demand Fulfilled */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 28339+sub13[forind0]*1 ;
  VGV->LEVEL[28339+sub13[forind0]*1] = MIN(1.000000,XIDZ(0,VGV->LEVEL[13244
+sub13[forind0]*1],VGV->LEVEL[61144+sub13[forind0]*1],1.000000)) ;
}
/* All Vaccinations */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 14800+sub13[forind0]*1 ;
  VGV->LEVEL[14800+sub13[forind0]*1] = VGV->LEVEL[61144+sub13[forind0]
*1]*VGV->LEVEL[28339+sub13[forind0]*1] ;
}
/* Average Acuity Not Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15922+sub13[forind0]*6+sub19[forind1]*2+1*1 ;
  VGV->LEVEL[15922+sub13[forind0]*6+sub19[forind1]*2+1*1] = ZIDZ(0,
VGV->LEVEL[16228+sub13[forind0]*6+sub19[forind1]*2+1*1]*VGV->LEVEL[35751
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[7507+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 15922+sub13[forind0]*6+sub19[forind1]*2+0*1 ;
  VGV->LEVEL[15922+sub13[forind0]*6+sub19[forind1]*2+0*1] = VGV->LEVEL[16228
+sub13[forind0]*6+sub19[forind1]*2+0*1] ;
}
/* WRand */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 65526+sub13[forind0]*1 ;
  VGV->LEVEL[65526+sub13[forind0]*1] = RANDOM_NORMAL((-10.000000),
10.000000,0,VGV->LEVEL[42953+sub13[forind0]*5+1*1],VGV->LEVEL[41415
]) ;
}
/* Chng */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 17996+sub13[forind0]*1 ;
  VGV->LEVEL[17996+sub13[forind0]*1] = VGV->LEVEL[14341+sub13[forind0]
*1]*VGV->LEVEL[65526+sub13[forind0]*1] ;
}
/* Frac Post Mortem from Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 28134+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[28134+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[616
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Chng Cml Dth Untst Untrt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 18047+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[18047+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[24495
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[44739+sub13[forind0]
*3+sub19[forind1]*1]*VGV->LEVEL[28134+sub13[forind0]*3+sub19[forind1]
*1] ;
}
/* Cml Death Frac In Hosp */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 18200+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4447+sub13[forind0]*6+sub19[sumind0]*2+0*1
]+VGV->LEVEL[4447+sub13[forind0]*6+sub19[sumind0]*2+1*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[5212+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[18200+sub13[forind0]*1] = XIDZ(0,temp0,temp1,1.000000
) ;
}
/* Cml Death fraction in hospitals large enough */
 {
  VGV->lastpos = 18251 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += IF_THEN_ELSE(VGV->LEVEL[18200+sub13[sumind0]*1]<VGV->LEVEL[39406
],1.000000,0) ;
  VGV->LEVEL[18251] = temp0 ;
}
/* PostMortemCorrection */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 45250+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[45250+sub13[forind0]*3+sub19[forind1]*1] = MIN(VGV->LEVEL[7048
+sub13[forind0]*6+sub19[forind1]*2+1*1]/VGV->LEVEL[39405],VGV->LEVEL[44739
+sub13[forind0]*3+sub19[forind1]*1]*(1.000000-VGV->LEVEL[28134+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Cml Death Hsp Inc */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 18252+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[18252+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = (VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]*2+0*1]+VGV->LEVEL[45250
+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[36073+sub16[forind2]
*1]+(1.000000-VGV->LEVEL[36073+sub16[forind2]*1])*(VGV->LEVEL[32581
+sub13[forind0]*6+sub19[forind1]*2+1*1]-VGV->LEVEL[45250+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Cml Known Death Frac Hosp */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 18558+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[18558+sub13[forind0]*3+sub19[forind1]*1] = XIDZ(0,VGV->LEVEL[4447
+sub13[forind0]*6+sub19[forind1]*2+0*1],VGV->LEVEL[5212+sub13[forind0]
*3+sub19[forind1]*1],1.000000) ;
}
/* CmlCaseInc */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 18711+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[18711+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[54485
+sub13[forind0]*9+sub19[forind1]*3+0*1] ;
}
/* CmlDeathInc */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 18864+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[18864+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[54485
+sub13[forind0]*9+sub19[forind1]*3+1*1] ;
}
/* Death Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 24035+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[24086+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[24035+sub13[forind0]*1] = temp0 ;
}
/* CmlDeatInc */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19017+sub13[forind0]*1 ;
  VGV->LEVEL[19017+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[26086
+sub13[forind0]*1]==NA,0,IF_THEN_ELSE(VGV->LEVEL[0]>=VGV->LEVEL[26086
+sub13[forind0]*1]&&VGV->LEVEL[0]<=VGV->LEVEL[25931+sub13[forind0]
*1],VGV->LEVEL[24035+sub13[forind0]*1],0)) ;
}
/* Cnfr R Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19226+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19226+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[19073
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36064+sub19[forind1]*1]-(VGV->LEVEL[19073+sub13[forind0]
*3+0*1]+VGV->LEVEL[19073+sub13[forind0]*3+1*1])*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* Recent Relative Contacts */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50941+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50941+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[3115
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Impact of Adherence Fatigue VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34168+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34168+sub13[forind0]*3+sub19[forind1]*1] = POWER(VGV->LEVEL[50941
+sub13[forind0]*3+sub19[forind1]*1],(VGV->LEVEL[55765+sub13[forind0]
*1]*IF_THEN_ELSE(VGV->LEVEL[59814]>VGV->LEVEL[0],1.000000,VGV->LEVEL[56740
]))) ;
}
/* Dread Factor in Risk Perception Nt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 25368+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[25368+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[53092]<VGV->LEVEL[0],(1.000000+VGV->LEVEL[53093]/100.000000
)*VGV->LEVEL[25317+sub13[forind0]*1],VGV->LEVEL[25317+sub13[forind0]
*1])*VGV->LEVEL[34168+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[26392
+sub19[forind1]*1] ;
}
/* Risk threshold for response */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 53094+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[53094+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[53092]<VGV->LEVEL[0],(1.000000-VGV->LEVEL[53093]/100.000000
)*VGV->LEVEL[53559+sub13[forind0]*1],VGV->LEVEL[53559+sub13[forind0]
*1])/VGV->LEVEL[34168+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[26392
+sub19[forind1]*1] ;
}
/* Voluntary Reduction in Contacts */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 64801+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[64801+sub13[forind0]*3+sub19[forind1]*1] = EXP((-MAX(
0,VGV->LEVEL[25368+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[8323
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[53094+sub13[forind0]
*3+sub19[forind1]*1])))*(1.000000-VGV->LEVEL[39352+sub13[forind0]*1
])+VGV->LEVEL[39352+sub13[forind0]*1] ;
}
/* Contacts Relative to Normal VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19532+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19532+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]<VGV->LEVEL[41311],MIN(VGV->LEVEL[64801+sub13[forind0]
*3+sub19[forind1]*1],VGV->LEVEL[13320+sub13[forind0]*3+sub19[forind1]
*1]),MIN(VGV->LEVEL[64801+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[13320
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[54022])+
VGV->LEVEL[54022]) ;
}
/* Population Fraction */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43820+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43820+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[43973
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[43718+sub13[forind0]
*1] ;
}
/* Contacts Relative to Normal */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19481+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[19532+sub13[forind0]*3+sub19[sumind0]*1]*VGV->LEVEL[43820
+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[19481+sub13[forind0]*1] = temp0 ;
}
/* Positive Testing of Infected Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44432+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44432+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44585
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[29564+sub13[forind0]
*6+sub19[forind1]*2+0*1] ;
}
/* Symptomatic Infected to Testing */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 58019+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[58019+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44432
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[30439+sub13[forind0]
*6+sub19[forind1]*2+0*1] ;
}
/* Untested symptomatic Infected to Hospital */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63235+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63235+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[30439
+sub13[forind0]*6+sub19[forind1]*2+1*1] ;
}
/* Continue without Testing */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 19685+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[19685+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[50583
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[58019+sub13[forind0]
*3+sub19[forind1]*1]-VGV->LEVEL[63235+sub13[forind0]*3+sub19[forind1]
*1] ;
}
/* Cost of Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19838+sub13[forind0]*1 ;
  VGV->LEVEL[19838+sub13[forind0]*1] = VGV->LEVEL[24035+sub13[forind0]
*1]*VGV->LEVEL[55661] ;
}
/* Cost of Deaths All */
 {
  VGV->lastpos = 19889 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[19838+sub13[sumind0]*1] ;
  VGV->LEVEL[19889] = temp0 ;
}
/* DollarDayConversation */
 {
  VGV->lastpos = 25265 ;
  VGV->LEVEL[25265] = 1000000.000000/360.000000 ;
}
/* Cost to GDP */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19944+sub13[forind0]*1 ;
  VGV->LEVEL[19944+sub13[forind0]*1] = VGV->LEVEL[6844+sub13[forind0]
*1]*VGV->LEVEL[25265] ;
}
/* Cost of GDP All */
 {
  VGV->lastpos = 19890 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[19944+sub13[sumind0]*1] ;
  VGV->LEVEL[19890] = temp0 ;
}
/* Cost of Hospitalizations */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19891+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp0 += VGV->LEVEL[30439+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
  VGV->LEVEL[19891+sub13[forind0]*1] = VGV->LEVEL[19943]*temp0 ;
}
/* Cost of Hospitalizations All */
 {
  VGV->lastpos = 19942 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[19891+sub13[sumind0]*1] ;
  VGV->LEVEL[19942] = temp0 ;
}
/* Count Missed Death */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 19995+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[18252+sub13[forind0]*6+sub19[sumind0]*2+1*1
]+VGV->LEVEL[18047+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[19995+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[26086
+sub13[forind0]*1]==NA,0,IF_THEN_ELSE(VGV->LEVEL[0]>=VGV->LEVEL[26086
+sub13[forind0]*1]&&VGV->LEVEL[0]<=VGV->LEVEL[25931+sub13[forind0]
*1],temp0,0)) ;
}
/* Predicted GDP */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 45862+sub13[forind0]*1 ;
  VGV->LEVEL[45862+sub13[forind0]*1] = VGV->LEVEL[8119+sub13[forind0]
*1]-VGV->LEVEL[6844+sub13[forind0]*1] ;
}
/* Error (E) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25880+sub13[forind0]*1 ;
  VGV->LEVEL[25880+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[50736
+sub13[forind0]*1]!=NA,VGV->LEVEL[45862+sub13[forind0]*1]-VGV->LEVEL[50736
+sub13[forind0]*1],0) ;
}
/* Counter */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 20046+sub13[forind0]*1 ;
  VGV->LEVEL[20046+sub13[forind0]*1] = ZIDZ(0,VGV->LEVEL[25880+sub13[forind0]
*1],VGV->LEVEL[25880+sub13[forind0]*1])/VGV->LEVEL[59349] ;
}
/* Total Covid Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 60427+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[60427+sub13[forind0]*3+sub19[forind1]*1] = temp0 ;
}
/* Covid Poisson Fraction in Hospital */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 20811+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[20811+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[60427
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[35751+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[7711+sub13[forind0]*3+sub19[forind1]
*1]+VGV->LEVEL[60427+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* Cumulative Cases */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 21015+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[21015+sub13[forind0]*1] = temp0 ;
}
/* Cumulative Confirmed Recovered */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 21066+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[21066+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[3781
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[5671+sub13[forind0]
*6+sub19[forind1]*2+0*1] ;
}
/* Cumulative Death Fraction */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 21219+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[5977+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[21219+sub13[forind0]*1] = ZIDZ(0,VGV->LEVEL[21423+sub13[forind0]
*1],VGV->LEVEL[21423+sub13[forind0]*1]+temp0) ;
}
/* Cumulative Death Fraction VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 21270+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[21270+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[5212
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[5212+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[5977+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Cumulative Fraction Total Cases Hospitalized */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 21474+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp0 += VGV->LEVEL[4447+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1]+VGV->LEVEL[3475+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1]+VGV->LEVEL[7048+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[21474+sub13[forind0]*1] = ZIDZ(0,temp0,temp1) ;
}
/* Cumulative Fraction Total Cases Hospitalized VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 21525+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1]+VGV->LEVEL[3475+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1]+VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[21525+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,temp0
,VGV->LEVEL[4141+sub13[forind0]*3+sub19[forind1]*1]) ;
}
/* CumulativeOutcomeRatios */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 21678+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]
*1 ;
  VGV->LEVEL[21678+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]
*1] = ZIDZ(0,VGV->LEVEL[6385+sub13[forind0]*9+sub15[forind1]*3+sub6[forind2]
*1],VGV->LEVEL[6385+sub13[forind0]*9+sub15[forind1]*3+0*1]) ;
}
/* Current APE */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22137+sub13[forind0]*1 ;
  VGV->LEVEL[22137+sub13[forind0]*1] = ABS(VGV->LEVEL[25880+sub13[forind0]
*1])/VGV->LEVEL[50736+sub13[forind0]*1]*100.000000/VGV->LEVEL[59349
] ;
}
/* Current Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22188+sub13[forind0]*1 ;
  VGV->LEVEL[22188+sub13[forind0]*1] = VGV->LEVEL[25880+sub13[forind0]
*1]/VGV->LEVEL[59349] ;
}
/* Daily GDP Gap */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22290+sub13[forind0]*1 ;
  VGV->LEVEL[22290+sub13[forind0]*1] = VGV->LEVEL[6844+sub13[forind0]
*1]/VGV->LEVEL[24033] ;
}
/* Daily Growth Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 22341+sub13[forind0]*1 ;
  VGV->LEVEL[22341+sub13[forind0]*1] = POWER((1.000000+VGV->LEVEL[30330
+sub13[forind0]*1]),(1.000000/365.000000))/VGV->LEVEL[41569]-1.000000
 ;
}
/* DataAggregateSmooth */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 22598+sub15[forind0]*1 ;
  VGV->LEVEL[22598+sub15[forind0]*1] = VGV->LEVEL[154+sub15[forind0]
*1] ;
}
/* DataFlowAggregate */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 22958+sub15[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[23063+sub13[sumind0]*3+sub15[forind0]*1] ;
  VGV->LEVEL[22958+sub15[forind0]*1] = MAX(0,temp0) ;
}
/* DeathFractionCounted */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 24239+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[5212+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[24239+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[22754
+sub13[forind0]*3+1*1]==NA,0,ZIDZ(0,VGV->LEVEL[22754+sub13[forind0]
*3+1*1],temp0)) ;
}
/* DelayedMeanFlowOT */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24649+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[24649+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[9445
+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* Di */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 24854+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[24854+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[23216
+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* Poisson Not-tested Asymptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 43208+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[43208+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[35751
+sub13[forind0]*3+sub19[forind1]*1]*EXP((-VGV->LEVEL[16228+sub13[forind0]
*6+sub19[forind1]*2+1*1])) ;
}
/* Different Infectious Counted */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 25007+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[25007+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[8476
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[7354+sub13[forind0]
*3+sub19[forind1]*1]+(VGV->LEVEL[13728+sub13[forind0]*3+sub19[forind1]
*1]+VGV->LEVEL[43208+sub13[forind0]*3+sub19[forind1]*1])+(VGV->LEVEL[35751
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[43208+sub13[forind0]
*3+sub19[forind1]*1])+VGV->LEVEL[7711+sub13[forind0]*3+sub19[forind1]
*1]+temp0 ;
}
/* Infected Individuals (I) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35138+sub13[forind0]*1 ;
  VGV->LEVEL[35138+sub13[forind0]*1] = VGV->LEVEL[35342]*VGV->LEVEL[922
+sub13[forind0]*1] ;
}
/* Infected Proportion */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35189+sub13[forind0]*1 ;
  VGV->LEVEL[35189+sub13[forind0]*1] = VGV->LEVEL[35138+sub13[forind0]
*1]/VGV->LEVEL[43718+sub13[forind0]*1] ;
}
/* Direct Infection Impact (st) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25211+sub13[forind0]*1 ;
  VGV->LEVEL[25211+sub13[forind0]*1] = VGV->LEVEL[25262]*VGV->LEVEL[35189
+sub13[forind0]*1]*VGV->LEVEL[45862+sub13[forind0]*1] ;
}
/* Direct Covid Impact on Output Gap (st) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25160+sub13[forind0]*1 ;
  VGV->LEVEL[25160+sub13[forind0]*1] = VGV->LEVEL[25211+sub13[forind0]
*1]*VGV->LEVEL[36104+sub13[forind0]*1] ;
}
/* Economist Covid Death Stdev */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25624+sub13[forind0]*1 ;
  VGV->LEVEL[25624+sub13[forind0]*1] = VGV->LEVEL[25675+sub13[forind0]
*1]*VGV->LEVEL[47673] ;
}
/* EcnDErrFlow */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25522+sub13[forind0]*1 ;
  VGV->LEVEL[25522+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[25624
+sub13[forind0]*1]==VGV->LEVEL[25675+sub13[forind0]*1],0,POWER(((VGV->LEVEL[21423
+sub13[forind0]*1]-VGV->LEVEL[25675+sub13[forind0]*1])/VGV->LEVEL[25624
+sub13[forind0]*1]),2.000000))*IF_THEN_ELSE(VGV->LEVEL[36233+sub13[forind0]
*1]==VGV->LEVEL[0],1.000000,0)/VGV->LEVEL[59349] ;
}
/* National Population */
 {
  VGV->lastpos = 40337 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[43718+sub13[sumind0]*1] ;
  VGV->LEVEL[40337] = temp0 ;
}
/* National CRN */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 40286+sub13[forind0]*1 ;
  VGV->LEVEL[40286+sub13[forind0]*1] = VGV->LEVEL[43718+sub13[forind0]
*1]*VGV->LEVEL[19481+sub13[forind0]*1]/VGV->LEVEL[40337] ;
}
/* Summed National CRN (bt) */
 {
  VGV->lastpos = 56276 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[40286+sub13[sumind0]*1] ;
  VGV->LEVEL[56276] = temp0 ;
}
/* State CRN */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 55559+sub13[forind0]*1 ;
  VGV->LEVEL[55559+sub13[forind0]*1] = VGV->LEVEL[56276]*(1.000000
-VGV->LEVEL[55610+sub13[forind0]*1])+VGV->LEVEL[55610+sub13[forind0]
*1]*VGV->LEVEL[19481+sub13[forind0]*1] ;
}
/* Inverse Contacts */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36181+sub13[forind0]*1 ;
  VGV->LEVEL[36181+sub13[forind0]*1] = 1.000000-VGV->LEVEL[55559+sub13[forind0]
*1] ;
}
/* Psychological Infectivity Economic Drop (kt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 47725+sub13[forind0]*1 ;
  VGV->LEVEL[47725+sub13[forind0]*1] = VGV->LEVEL[47776]*POWER(VGV->LEVEL[36181
+sub13[forind0]*1],VGV->LEVEL[47724])/VGV->LEVEL[41569] ;
}
/* Economic Learning Potential */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 25573+sub13[forind0]*1 ;
  VGV->LEVEL[25573+sub13[forind0]*1] = VGV->LEVEL[47725+sub13[forind0]
*1]-VGV->LEVEL[8068+sub13[forind0]*1] ;
}
/* Excess Death Rate Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 26035+sub13[forind0]*1 ;
  VGV->LEVEL[26035+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[22444
+sub13[forind0]*1]<50.000000,0,POWER(ZIDZ(0,VGV->LEVEL[5467+sub13[forind0]
*1]-VGV->LEVEL[26033]*VGV->LEVEL[22444+sub13[forind0]*1],VGV->LEVEL[26034
]*VGV->LEVEL[22444+sub13[forind0]*1]),4.000000)) ;
}
/* FirstInfectedFraction */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 27467+sub13[forind0]*1 ;
  VGV->LEVEL[27467+sub13[forind0]*1] = VGV->LEVEL[5977+sub13[forind0]
*3+0*1]/VGV->LEVEL[35959+sub13[forind0]*1] ;
}
/* Flu Acuity Relative to Covid */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 27675+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[27675+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[27674
]/VGV->LEVEL[20097+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* flush */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 27828+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[27828+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[23216+sub13[forind0]*3+sub15[forind1]*1]>0,1.000000,0) ;
}
/* Fraction Covid Death In Hospitals Previously Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 28442+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[28442+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[32581
+sub13[forind0]*6+sub19[forind1]*2+0*1],temp0) ;
}
/* Fraction Covid Hospitalized Positively Tested */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 28595+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[28595+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[7048
+sub13[forind0]*6+sub19[forind1]*2+0*1],VGV->LEVEL[60427+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Fraction Infected */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 28748+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[28748+sub13[forind0]*3+sub19[forind1]*1] = temp0/VGV->LEVEL[43718
+sub13[forind0]*1] ;
}
/* Fraction of Additional Symptomatic */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29207+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[29207+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[13881
+sub13[forind0]*3+sub19[forind1]*1]/(1.000000+VGV->LEVEL[13881+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Sensitivity Post Mortem Testing to Capacity Net */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53765+sub13[forind0]*1 ;
  VGV->LEVEL[53765+sub13[forind0]*1] = VGV->LEVEL[53816] ;
}
/* Indicated Fraction Post Mortem Testing */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34832+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34832+sub13[forind0]*3+sub19[forind1]*1] = POWER(MAX(
0,MIN(VGV->LEVEL[28442+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[15004
+sub13[forind0]*3+sub19[forind1]*1])),VGV->LEVEL[53765+sub13[forind0]
*1]) ;
}
/* Switch for Government Response */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 56741+sub13[forind0]*1 ;
  VGV->LEVEL[56741+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]>
VGV->LEVEL[30384+sub13[forind0]*1],1.000000,0) ;
}
/* Fraction of Fatalities Screened Post Mortem */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29360+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[29360+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[34832
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[56741+sub13[forind0]
*1]*VGV->LEVEL[28391+sub13[forind0]*1] ;
}
/* Fraction of Population Hospitalized for Covid */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 29513+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[60427+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[29513+sub13[forind0]*1] = temp0/VGV->LEVEL[43718+sub13[forind0]
*1] ;
}
/* Fraction Tests Positive */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 29870+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[44585+sub13[forind0]*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[58940+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[29870+sub13[forind0]*1] = ZIDZ(0,temp0,temp1) ;
}
/* Fraction Tests Positive Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 29921+sub13[forind0]*1 ;
  VGV->LEVEL[29921+sub13[forind0]*1] = MIN(1.000000,ZIDZ(0,VGV->LEVEL[23012
+sub13[forind0]*1],VGV->LEVEL[13193+sub13[forind0]*1])) ;
}
/* Fraction Tests Positive VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 29972+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[29972+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[44585
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[58940+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* Fractional Acuity Change */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 30125+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[30125+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[20505
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[10057+sub13[forind0]
*3+sub19[forind1]*1])/(VGV->LEVEL[20505+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[59349]) ;
}
/* GDP Growth */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 30279+sub13[forind0]*1 ;
  VGV->LEVEL[30279+sub13[forind0]*1] = VGV->LEVEL[8119+sub13[forind0]
*1]*VGV->LEVEL[22341+sub13[forind0]*1] ;
}
/* Global Cases */
 {
  VGV->lastpos = 30381 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += VGV->LEVEL[4141+sub13[sumind0]*3+sub19[sumind1]*1] ;
  VGV->LEVEL[30381] = temp0 ;
}
/* Global Deaths */
 {
  VGV->lastpos = 30382 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += VGV->LEVEL[5212+sub13[sumind0]*3+sub19[sumind1]*1] ;
  VGV->LEVEL[30382] = temp0 ;
}
/* Global IFR */
 {
  VGV->lastpos = 30383 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += VGV->LEVEL[25007+sub13[sumind0]*3+sub19[sumind1]*1] ;
  VGV->LEVEL[30383] = ZIDZ(0,VGV->LEVEL[30382],VGV->LEVEL[30381]-temp0
) ;
}
/* GraphMarker */
 {
  VGV->lastpos = 30435 ;
  VGV->LEVEL[30435] = IF_THEN_ELSE(VGV->LEVEL[38531]>VGV->LEVEL[0]
,2.000000,(-1.000000)) ;
}
}
void mdl_func14(void) ;
void mdl_func14(){
double temp[10];
/* Hospital Admit Ratio */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 30745+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[30745+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = XIDZ(0,VGV->LEVEL[31051+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1],VGV->LEVEL[45403+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1],1.000000) ;
}
/* Hospitalized CFR Cumulative */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 32275+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[32275+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = ZIDZ(0,VGV->LEVEL[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1],VGV->LEVEL[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]+VGV->LEVEL[3475+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]) ;
}
/* Hospitalized True CFR */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 32888+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[32581+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp1 += VGV->LEVEL[31969+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[32888+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,temp0
,temp1) ;
}
/* Hospitalized True CFR Cumulative */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 33041+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp1 += VGV->LEVEL[4447+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1]+VGV->LEVEL[3475+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[33041+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,temp0
,temp1) ;
}
/* Hsp R Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[33500+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = VGV->LEVEL[33194+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1]*VGV->LEVEL[28339+sub13[forind0]*1]*VGV->LEVEL[36064+sub19[forind1]
*1]-(VGV->LEVEL[33194+sub13[forind0]*6+0*2+sub16[forind2]*1]+VGV->LEVEL[33194
+sub13[forind0]*6+1*2+sub16[forind2]*1])*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* Losing Immunity Unconfirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 38121+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[38121+sub13[forind0]*3+sub19[forind1]*1] = MAX(0,MIN(
5.000000*VGV->LEVEL[8884+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[33964
+sub19[forind1]*51+sub13[forind0]*1],VGV->LEVEL[12046+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Losing Immunity Confirmed */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 37611+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[37611+sub13[forind0]*3+sub19[forind1]*1] = MAX(0,MIN(
5.000000*VGV->LEVEL[3781+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[33964
+sub19[forind1]*51+sub13[forind0]*1],VGV->LEVEL[10210+sub13[forind0]
*3+sub19[forind1]*1])) ;
}
/* Losing Immunity Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<2;forind2++)
 {
  VGV->lastpos = 37764+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1 ;
  VGV->LEVEL[37764+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1] = MAX(0,MIN(5.000000*VGV->LEVEL[5671+sub13[forind0]*6+sub19[forind1]
*2+sub16[forind2]*1]/VGV->LEVEL[33964+sub19[forind1]*51+sub13[forind0]
*1],VGV->LEVEL[10822+sub13[forind0]*6+sub19[forind1]*2+sub16[forind2]
*1])) ;
}
/* Immunity Loss */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 33808+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[38121+sub13[forind0]*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[37611+sub13[forind0]*3+sub19[sumind0]*1] ;
    temp2 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp2 += VGV->LEVEL[37764+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
  VGV->LEVEL[33808+sub13[forind0]*3+sub19[forind1]*1] = (temp0+temp1
+temp2)*VGV->LEVEL[36070+sub19[forind1]*1] ;
}
/* Impact of Adherence Fatigue */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 34117+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[34168+sub13[forind0]*3+sub19[sumind0]*1]*VGV->LEVEL[43820
+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[34117+sub13[forind0]*1] = temp0 ;
}
/* Max Perceivable Risk */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 38376+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[38376+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[38585
]+VGV->LEVEL[53094+sub13[forind0]*3+sub19[forind1]*1])/VGV->LEVEL[25368
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Reported Hazard of Death */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 52888+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[52888+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[54485
+sub13[forind0]*9+sub19[forind1]*3+1*1]/VGV->LEVEL[43718+sub13[forind0]
*1] ;
}
/* True Hazard of death */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 62572+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[62572+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[24086
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[43718+sub13[forind0]
*1] ;
}
/* Perceived Hazard of Death */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42494+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42494+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[65319
+sub13[forind0]*1]*VGV->LEVEL[52888+sub13[forind0]*3+sub19[forind1]
*1]+(1.000000-VGV->LEVEL[65319+sub13[forind0]*1])*VGV->LEVEL[62572
+sub13[forind0]*3+sub19[forind1]*1])*(1.000000-VGV->LEVEL[65265+sub19[forind1]
*1])+VGV->LEVEL[65265+sub19[forind1]*1]*VGV->LEVEL[14545+sub13[forind0]
*1] ;
}
/* Indicated Risk of Life Loss */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 34985+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[34985+sub13[forind0]*3+sub19[forind1]*1] = MIN(VGV->LEVEL[38376
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[42494+sub13[forind0]
*3+sub19[forind1]*1]/VGV->LEVEL[25264]) ;
}
/* Infection Adjustment based on Data */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35240+sub13[forind0]*1 ;
  VGV->LEVEL[35240+sub13[forind0]*1] = VGV->LEVEL[7660+sub13[forind0]
*1]*VGV->LEVEL[56739]+(1.000000-VGV->LEVEL[56739]) ;
}
/* Infection Deviation Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35291+sub13[forind0]*1 ;
  VGV->LEVEL[35291+sub13[forind0]*1] = VGV->LEVEL[65525]*POWER((VGV->LEVEL[7660
+sub13[forind0]*1]-1.000000),2.000000) ;
}
/* Variant Effect on Vx Infectiousness */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64265+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP(VGV->LEVEL[64593+sub18[sumind0]*1]/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[64265+sub13[forind0]*1] = temp0 ;
}
/* Vaccine Effect on Infectiousness */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63747+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63747+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17404
+sub19[forind1]*1]*VGV->LEVEL[36064+sub19[forind1]*1]+(VGV->LEVEL[17404
+2*1]+(1.000000-VGV->LEVEL[17404+2*1])*VGV->LEVEL[64265+sub13[forind0]
*1])*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* Variant Transmission Multiplier[BA5] */
 {
  VGV->lastpos = 64587 ;
  VGV->LEVEL[64587+2*1] = VGV->LEVEL[64587+1*1] ;
}
/* Variants Effect on Transmission */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 64596+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP((VGV->LEVEL[64587+sub18[sumind0]*1]-1.000000)/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[64596+sub13[forind0]*3+sub19[forind1]*1] = 1.000000+temp0
 ;
}
/* Infectious Contacts */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 35598+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1]*VGV->LEVEL[61501+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[35598+sub13[forind0]*3+sub19[forind1]*1] = (VGV->LEVEL[8476
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[61960+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[7354+sub13[forind0]*3+sub19[forind1]
*1]*VGV->LEVEL[61807+sub13[forind0]*3+sub19[forind1]*1]+(VGV->LEVEL[13728
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[43208+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[17250+sub13[forind0]*3+sub19[forind1]
*1]+(VGV->LEVEL[35751+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[43208
+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[17403]+VGV->LEVEL[7711
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[61348+sub13[forind0]
*3+sub19[forind1]*1]+temp0)*VGV->LEVEL[51559+sub13[forind0]*1]*SQRT(
VGV->LEVEL[19532+sub13[forind0]*3+sub19[forind1]*1])*VGV->LEVEL[63747
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[64596+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Variant Vaccine Effectiveness Reduction[BA5] */
 {
  VGV->lastpos = 64590 ;
  VGV->LEVEL[64590+2*1] = VGV->LEVEL[64590+1*1] ;
}
/* Variant Effect on Vaccine Effectiveness */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64214+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += RAMP(VGV->LEVEL[64590+sub18[sumind0]*1]/VGV->LEVEL[64584
+sub18[sumind0]*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]
*1],VGV->LEVEL[64379+sub13[forind0]*3+sub18[sumind0]*1]+VGV->LEVEL[64584
+sub18[sumind0]*1]) ;
  VGV->LEVEL[64214+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]>
VGV->LEVEL[41311]&&VGV->LEVEL[56738]==1.000000,1.000000,1.000000+temp0
) ;
}
/* Vaccine Effect on Transmission */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63900+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63900+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[17407
+sub19[forind1]*1]*VGV->LEVEL[36064+sub19[forind1]*1]+(1.000000-(1.000000
-VGV->LEVEL[17407+2*1])*VGV->LEVEL[64214+sub13[forind0]*1])*VGV->LEVEL[36075
+sub19[forind1]*1] ;
}
/* Transmissions */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 62113+sub13[forind0]*9+sub19[forind1]*3+sub20[forind2]
*1 ;
  VGV->LEVEL[62113+sub13[forind0]*9+sub19[forind1]*3+sub20[forind2]
*1] = VGV->LEVEL[35598+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[9088
+sub13[forind0]*3+sub20[forind2]*1]*SQRT(VGV->LEVEL[19532+sub13[forind0]
*3+sub20[forind2]*1])/VGV->LEVEL[43718+sub13[forind0]*1]*VGV->LEVEL[63900
+sub13[forind0]*3+sub20[forind2]*1] ;
}
/* Weather Effect on Transmission */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 65212+sub13[forind0]*1 ;
  VGV->LEVEL[65212+sub13[forind0]*1] = POWER(VGV->LEVEL[20964+sub13[forind0]
*1],VGV->LEVEL[53818+sub13[forind0]*1]) ;
}
/* Infection Rate VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 35394+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[62113+sub13[forind0]*9+sub20[sumind0]*3+sub19[forind1]
*1] ;
  VGV->LEVEL[35394+sub13[forind0]*3+sub19[forind1]*1] = temp0*VGV->LEVEL[65212
+sub13[forind0]*1]*VGV->LEVEL[35240+sub13[forind0]*1] ;
}
/* Infection Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35343+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[35394+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[35343+sub13[forind0]*1] = temp0 ;
}
/* InfectionUFractionCounted */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 35547+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[35547+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[22754
+sub13[forind0]*3+0*1]==NA,0,ZIDZ(0,VGV->LEVEL[22754+sub13[forind0]
*3+0*1],temp0)) ;
}
/* Infectivity of Breakthrough Cases */
 {
  VGV->lastpos = 35904+0*1 ;
  VGV->LEVEL[35904+0*1] = VGV->LEVEL[17404+2*1]+(1.000000-VGV->LEVEL[17404
+2*1])*VGV->LEVEL[64593+0*1] ;
}
 {
  VGV->lastpos = 35904+1*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[64593+sub18[sumind0]*1] ;
  VGV->LEVEL[35904+1*1] = VGV->LEVEL[17404+2*1]+(1.000000-VGV->LEVEL[17404
+2*1])*temp0 ;
}
/* Initial Vaccine Effectiveness */
 {
  VGV->lastpos = 36011 ;
  VGV->LEVEL[36011] = 1.000000-VGV->LEVEL[17407+2*1] ;
}
/* InitialOutbreakPenalty */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36013+sub13[forind0]*1 ;
  VGV->LEVEL[36013+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[27263+sub13[forind0]*3+0*1]+VGV->LEVEL[36012],MAX(0,VGV->LEVEL[27467
+sub13[forind0]*1]-VGV->LEVEL[42493])*VGV->LEVEL[42492],0) ;
}
/* Instantaneous IFR Global */
 {
  VGV->lastpos = 36180 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[24035+sub13[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp1 += VGV->LEVEL[14596+sub13[sumind0]*1] ;
  VGV->LEVEL[36180] = ZIDZ(0,temp0,temp1) ;
}
/* Known death fraction in hospitals large enough */
 {
  VGV->lastpos = 36232 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += IF_THEN_ELSE(VGV->LEVEL[18558+sub13[sumind0]*3+sub19[sumind1]
*1]<VGV->LEVEL[39407],1.000000,0)*VGV->LEVEL[14392+sub13[sumind0]*3
+sub19[sumind1]*1] ;
  VGV->LEVEL[36232] = temp0 ;
}
/* Learning Decay */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 36590+sub13[forind0]*1 ;
  VGV->LEVEL[36590+sub13[forind0]*1] = VGV->LEVEL[8068+sub13[forind0]
*1]/VGV->LEVEL[39512+sub13[forind0]*1] ;
}
/* Life Expectancy */
 {
  VGV->lastpos = 36692 ;
  VGV->LEVEL[36692] = 80.000000*365.000000 ;
}
/* lnymix 0 */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 37152+sub13[forind0]*9+sub19[forind1]*3+sub0[forind2]
*1 ;
  VGV->LEVEL[37152+sub13[forind0]*9+sub19[forind1]*3+sub0[forind2]
*1] = (-LN(MAX(1e-06,1.000000-VGV->LEVEL[65730+sub13[forind0]*9+sub19[forind1]
*3+sub0[forind2]*1]))) ;
}
/* Vx S ImmunityLoss */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 65008+sub13[forind0]*1 ;
  VGV->LEVEL[65008+sub13[forind0]*1] = MAX(0,MIN(5.000000*VGV->LEVEL[9088
+sub13[forind0]*3+2*1]/VGV->LEVEL[33964+2*51+sub13[forind0]*1],VGV->LEVEL[12658
+sub13[forind0]*1])) ;
}
/* Losing Immunity Susceptible */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38070+sub13[forind0]*1 ;
  VGV->LEVEL[38070+sub13[forind0]*1] = VGV->LEVEL[65008+sub13[forind0]
*1] ;
}
/* MAPE */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 38274+sub13[forind0]*1 ;
  VGV->LEVEL[38274+sub13[forind0]*1] = ZIDZ(0,VGV->LEVEL[4090+sub13[forind0]
*1],VGV->LEVEL[6895+sub13[forind0]*1]) ;
}
/* Mitigation Learning */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 39461+sub13[forind0]*1 ;
  VGV->LEVEL[39461+sub13[forind0]*1] = VGV->LEVEL[25573+sub13[forind0]
*1]/VGV->LEVEL[36641+sub13[forind0]*1] ;
}
/* Mu */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 39563+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[39563+sub13[forind0]*3+sub15[forind1]*1] = MAX(VGV->LEVEL[25879
],VGV->LEVEL[7915+sub13[forind0]*3+sub15[forind1]*1]) ;
}
/* MuFlsh */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 39716+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[39716+sub13[forind0]*3+sub15[forind1]*1] = VGV->LEVEL[7915
+sub13[forind0]*3+sub15[forind1]*1]/VGV->LEVEL[59349]*VGV->LEVEL[27828
+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* MuInc */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 39869+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[39869+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[27263+sub13[forind0]*3+sub15[forind1]*1]>VGV->LEVEL[0]||
VGV->LEVEL[38531]<VGV->LEVEL[0],0,VGV->LEVEL[24649+sub13[forind0]*3
+sub15[forind1]*1]) ;
}
/* NBL1 */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 40338+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[40338+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[23216+sub13[forind0]*3+sub15[forind1]*1]==0,(-LN(1.000000
+VGV->LEVEL[15157+sub13[forind0]*3+sub15[forind1]*1]*VGV->LEVEL[39563
+sub13[forind0]*3+sub15[forind1]*1]))/VGV->LEVEL[15157+sub13[forind0]
*3+sub15[forind1]*1],0) ;
}
/* NBL2 */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 40491+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[40491+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[23216+sub13[forind0]*3+sub15[forind1]*1]>0,GAMMA_LN(VGV->LEVEL[24854
+sub13[forind0]*3+sub15[forind1]*1]+1.000000/VGV->LEVEL[15157+sub13[forind0]
*3+sub15[forind1]*1])-GAMMA_LN(1.000000/VGV->LEVEL[15157+sub13[forind0]
*3+sub15[forind1]*1])-GAMMA_LN(VGV->LEVEL[24854+sub13[forind0]*3+sub15[forind1]
*1]+1.000000)-(VGV->LEVEL[24854+sub13[forind0]*3+sub15[forind1]*1]
+1.000000/VGV->LEVEL[15157+sub13[forind0]*3+sub15[forind1]*1])*LN(
1.000000+VGV->LEVEL[15157+sub13[forind0]*3+sub15[forind1]*1]*VGV->LEVEL[39563
+sub13[forind0]*3+sub15[forind1]*1])+VGV->LEVEL[24854+sub13[forind0]
*3+sub15[forind1]*1]*(LN(VGV->LEVEL[15157+sub13[forind0]*3+sub15[forind1]
*1])+LN(VGV->LEVEL[39563+sub13[forind0]*3+sub15[forind1]*1])),0) ;
}
/* NBL3 */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 40644+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[40644+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[24854+sub13[forind0]*3+sub15[forind1]*1]>0,(-GAMMA_LN(VGV->LEVEL[24854
+sub13[forind0]*3+sub15[forind1]*1]+1.000000))-(VGV->LEVEL[24854+sub13[forind0]
*3+sub15[forind1]*1]+1.000000/VGV->LEVEL[15157+sub13[forind0]*3+sub15[forind1]
*1])*LN(1.000000+VGV->LEVEL[15157+sub13[forind0]*3+sub15[forind1]*1
]*VGV->LEVEL[39563+sub13[forind0]*3+sub15[forind1]*1])+VGV->LEVEL[24854
+sub13[forind0]*3+sub15[forind1]*1]*(LN(VGV->LEVEL[15157+sub13[forind0]
*3+sub15[forind1]*1])+LN(VGV->LEVEL[39563+sub13[forind0]*3+sub15[forind1]
*1])),0) ;
}
/* NBLLFlow */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 40800+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[40800+sub13[forind0]*3+sub15[forind1]*1] = (VGV->LEVEL[40491
+sub13[forind0]*3+sub15[forind1]*1])*VGV->LEVEL[27671+sub15[forind1]
*1]*VGV->LEVEL[23471+sub13[forind0]*3+sub15[forind1]*1] ;
}
/* NBLLAggregate */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 40797+sub15[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[40800+sub13[sumind0]*3+sub15[forind0]*1] ;
  VGV->LEVEL[40797+sub15[forind0]*1] = temp0 ;
}
/* Negative Test Results */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 40953+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[40953+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[58940
+sub13[forind0]*3+sub19[forind1]*1]-VGV->LEVEL[44585+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Net Economic Psychological Drop (kt-lt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 41106+sub13[forind0]*1 ;
  VGV->LEVEL[41106+sub13[forind0]*1] = MAX(VGV->LEVEL[47725+sub13[forind0]
*1]-VGV->LEVEL[8068+sub13[forind0]*1],0) ;
}
/* Patient Zero Arrival */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42286+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42286+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]<VGV->LEVEL[42439+sub13[forind0]*1]&&VGV->LEVEL[0]+VGV->LEVEL[59349
]>=VGV->LEVEL[42439+sub13[forind0]*1],VGV->LEVEL[42490]/VGV->LEVEL[59349
],0)*VGV->LEVEL[36067+sub19[forind1]*1] ;
}
/* New Cases */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 41157+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[42286+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[41157+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[35394
+sub13[forind0]*3+sub19[forind1]*1]+temp0 ;
}
/* SuscFrac */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56584+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56584+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[9088
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[43718+sub13[forind0]
*1] ;
}
/* Not too few susceptibles */
 {
  VGV->lastpos = 41414 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += IF_THEN_ELSE(VGV->LEVEL[56584+sub13[sumind0]*3+sub19[sumind1]
*1]<VGV->LEVEL[39408],1.000000,0) ;
  VGV->LEVEL[41414] = temp0 ;
}
/* OutcomeAdd */
for(forind0=0;forind0<51;forind0++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 41571+sub13[forind0]*9+0*3+sub6[forind2]*1 ;
  VGV->LEVEL[41571+sub13[forind0]*9+0*3+sub6[forind2]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]>=VGV->LEVEL[51097+sub6[forind2]*1]&&VGV->LEVEL[0]<=VGV->LEVEL[51094
+sub6[forind2]*1],VGV->LEVEL[35343+sub13[forind0]*1],0) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 41571+sub13[forind0]*9+1*3+sub6[forind2]*1 ;
  VGV->LEVEL[41571+sub13[forind0]*9+1*3+sub6[forind2]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]>=VGV->LEVEL[51097+sub6[forind2]*1]&&VGV->LEVEL[0]<=VGV->LEVEL[51094
+sub6[forind2]*1],VGV->LEVEL[24035+sub13[forind0]*1],0) ;
}
for(forind0=0;forind0<51;forind0++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 41571+sub13[forind0]*9+2*3+sub6[forind2]*1 ;
  VGV->LEVEL[41571+sub13[forind0]*9+2*3+sub6[forind2]*1] = IF_THEN_ELSE(
VGV->LEVEL[0]>=VGV->LEVEL[51097+sub6[forind2]*1]&&VGV->LEVEL[0]<=VGV->LEVEL[51094
+sub6[forind2]*1],VGV->LEVEL[19481+sub13[forind0]*1],0) ;
}
/* Output Gap Decay */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 42030+sub13[forind0]*1 ;
  VGV->LEVEL[42030+sub13[forind0]*1] = VGV->LEVEL[6844+sub13[forind0]
*1]/VGV->LEVEL[42081] ;
}
/* Overall Death Fraction */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 42082+sub13[forind0]*1 ;
  VGV->LEVEL[42082+sub13[forind0]*1] = ZIDZ(0,VGV->LEVEL[24035+sub13[forind0]
*1],VGV->LEVEL[14596+sub13[forind0]*1]) ;
}
/* Overall Death Fraction VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 42133+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[42133+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[24086
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[14647+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[24086+sub13[forind0]*3+sub19[forind1]
*1]) ;
}
/* Population Check */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 43769+sub13[forind0]*1 ;
  VGV->LEVEL[43769+sub13[forind0]*1] = VGV->LEVEL[35959+sub13[forind0]
*1]-(VGV->LEVEL[21423+sub13[forind0]*1]+VGV->LEVEL[43718+sub13[forind0]
*1]) ;
}
/* Post Mortem Test Untreated */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 44892+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[44892+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[44739
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28134+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Pyschological Impact on Output Gap (kt) */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 50327+sub13[forind0]*1 ;
  VGV->LEVEL[50327+sub13[forind0]*1] = VGV->LEVEL[41106+sub13[forind0]
*1]*VGV->LEVEL[36104+sub13[forind0]*1] ;
}
/* Total Weighted Infected Population */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 61195+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[61195+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[7354
+sub13[forind0]*3+sub19[forind1]*1]+VGV->LEVEL[8476+sub13[forind0]
*3+sub19[forind1]*1]+VGV->LEVEL[65371+sub13[forind0]*3+sub19[forind1]
*1] ;
}
/* Total Disease Duration */
 {
  VGV->lastpos = 60580 ;
  VGV->LEVEL[60580] = VGV->LEVEL[41570]+VGV->LEVEL[45249]+VGV->LEVEL[34525
] ;
}
/* R Effective Reproduction Rate */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 50378+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[35394+sub13[forind0]*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[61195+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[50378+sub13[forind0]*1] = ZIDZ(0,temp0,temp1)*VGV->LEVEL[60580
] ;
}
/* R Effective Reproduction Rate VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 50429+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[50429+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[35394
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[61195+sub13[forind0]
*3+sub19[forind1]*1])*VGV->LEVEL[60580] ;
}
/* Realistic R0 */
 {
  VGV->lastpos = 50787 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += IF_THEN_ELSE(VGV->LEVEL[50429+sub13[sumind0]*3+sub19[sumind1]
*1]>VGV->LEVEL[38586],1.000000,0) ;
  VGV->LEVEL[50787] = temp0 ;
}
/* Sensitivity Post Mortem Testing to Capacity */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53714+sub13[forind0]*1 ;
  VGV->LEVEL[53714+sub13[forind0]*1] = VGV->LEVEL[53816] ;
}
/* RegionalInputs */
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+1*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+1*51+sub13[forind1]*1] = LOG(VGV->LEVEL[59353+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+2*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+2*51+sub13[forind1]*1] = VGV->LEVEL[51508+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+3*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+3*51+sub13[forind1]*1] = VGV->LEVEL[53714+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+4*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+4*51+sub13[forind1]*1] = VGV->LEVEL[17097+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+5*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+5*51+sub13[forind1]*1] = VGV->LEVEL[65268+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+6*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+6*51+sub13[forind1]*1] = VGV->LEVEL[40022+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+7*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+7*51+sub13[forind1]*1] = VGV->LEVEL[39301+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+8*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+8*51+sub13[forind1]*1] = VGV->LEVEL[53508+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+9*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+9*51+sub13[forind1]*1] = VGV->LEVEL[19379+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+10*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+10*51+sub13[forind1]*1] = VGV->LEVEL[34321+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+11*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+11*51+sub13[forind1]*1] = VGV->LEVEL[34423+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+12*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+12*51+sub13[forind1]*1] = LOG(VGV->LEVEL[25266+sub13[forind1]
*1],10.000000) ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+13*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+13*51+sub13[forind1]*1] = VGV->LEVEL[51406+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+15*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+15*51+sub13[forind1]*1] = VGV->LEVEL[53817] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+16*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+16*51+sub13[forind1]*1] = VGV->LEVEL[20250+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+17*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+17*51+sub13[forind1]*1] = VGV->LEVEL[53612+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+19*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+19*51+sub13[forind1]*1] = VGV->LEVEL[53455] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+20*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+20*51+sub13[forind1]*1] = VGV->LEVEL[53351] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+21*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+21*51+sub13[forind1]*1] = VGV->LEVEL[53403] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+22*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+22*51+sub13[forind1]*1] = VGV->LEVEL[40124+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+23*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+23*51+sub13[forind1]*1] = VGV->LEVEL[36488+sub13[forind1]
*1] ;
}
for(forind1=0;forind1<51;forind1++)
 {
  VGV->lastpos = 51611+24*51+sub13[forind1]*1 ;
  VGV->LEVEL[51611+24*51+sub13[forind1]*1] = VGV->LEVEL[55714+sub13[forind1]
*1] ;
}
/* ResetNoise */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53041+sub13[forind0]*1 ;
  VGV->LEVEL[53041+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]==
VGV->LEVEL[36335+sub13[forind0]*1],(LN(VGV->LEVEL[22495+sub13[forind0]
*1])-VGV->LEVEL[9037+sub13[forind0]*1])/VGV->LEVEL[59349],0) ;
}
/* RMSE */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53247+sub13[forind0]*1 ;
  VGV->LEVEL[53247+sub13[forind0]*1] = ZIDZ(0,SQRT(POWER(VGV->LEVEL[5365
+sub13[forind0]*1],2.000000)),VGV->LEVEL[6895+sub13[forind0]*1]) ;
}
/* RVRChng */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 53298+sub13[forind0]*1 ;
  VGV->LEVEL[53298+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[36284+sub13[forind0]*1],(VGV->LEVEL[23981+sub13[forind0]
*1]*VGV->LEVEL[64800]-VGV->LEVEL[8680+sub13[forind0]*1])/VGV->LEVEL[53349
],(VGV->LEVEL[14800+sub13[forind0]*1]-VGV->LEVEL[8680+sub13[forind0]
*1])/VGV->LEVEL[53349]) ;
}
/* SimCmltOverTime */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 54179+sub13[forind0]*3+0*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4294+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[54179+sub13[forind0]*3+0*1] = temp0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 54179+sub13[forind0]*3+1*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4753+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[54179+sub13[forind0]*3+1*1] = temp0 ;
}
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 54179+sub13[forind0]*3+2*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[6130+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[54179+sub13[forind0]*3+2*1] = temp0 ;
}
/* SeriesErrorTerm */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 53869+sub13[forind0]*3+sub15[forind1]*1 ;
  VGV->LEVEL[53869+sub13[forind0]*3+sub15[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[22754+sub13[forind0]*3+sub15[forind1]*1]==NA,0,POWER((ABS(
VGV->LEVEL[22754+sub13[forind0]*3+sub15[forind1]*1]-VGV->LEVEL[54179
+sub13[forind0]*3+sub15[forind1]*1])),VGV->LEVEL[19068]))/(VGV->LEVEL[17095
]+VGV->LEVEL[22754+sub13[forind0]*3+sub15[forind1]*1])*VGV->LEVEL[19069
]*VGV->LEVEL[19070+sub15[forind1]*1]*VGV->LEVEL[23471+sub13[forind0]
*3+sub15[forind1]*1] ;
}
}
void mdl_func15(void) ;
void mdl_func15(){
double temp[10];
/* Sim Pseudo Case Fatality */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 54023+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[54023+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,VGV->LEVEL[4753
+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[4294+sub13[forind0]
*3+sub19[forind1]*1]) ;
}
/* SimAggregateSmooth */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 54176+sub15[forind0]*1 ;
  VGV->LEVEL[54176+sub15[forind0]*1] = VGV->LEVEL[3268+sub15[forind0]
*1] ;
}
/* SimFlowOverTime */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<2;forind1++)
 {
  VGV->lastpos = 54332+sub13[forind0]*3+sub17[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[54485+sub13[forind0]*9+sub19[sumind0]*3+sub17[forind1]
*1] ;
  VGV->LEVEL[54332+sub13[forind0]*3+sub17[forind1]*1] = temp0 ;
}
/* Total Simulated Tests */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60734+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[58940+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[60734+sub13[forind0]*1] = VGV->LEVEL[45198+sub13[forind0]
*1]+temp0 ;
}
/* SimTestRate */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 54944+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[54944+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[60734
+sub13[forind0]*1] ;
}
/* SimulatedFlowAggregate */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 55097+sub15[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[24649+sub13[sumind0]*3+sub15[forind0]*1] ;
  VGV->LEVEL[55097+sub15[forind0]*1] = temp0 ;
}
/* SqrdErr */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
for(forind2=0;forind2<3;forind2++)
 {
  VGV->lastpos = 55100+sub13[forind0]*9+sub19[forind1]*3+sub15[forind2]
*1 ;
  VGV->LEVEL[55100+sub13[forind0]*9+sub19[forind1]*3+sub15[forind2]
*1] = IF_THEN_ELSE(VGV->LEVEL[27518+sub13[forind0]*3+sub15[forind2]
*1]==NA,NA,POWER(VGV->LEVEL[27518+sub13[forind0]*3+sub15[forind2]*1
],2.000000)) ;
}
/* SumExcessError */
 {
  VGV->lastpos = 56275 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[26035+sub13[sumind0]*1] ;
  VGV->LEVEL[56275] = temp0 ;
}
/* Total Excess Death Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60632+sub13[forind0]*1 ;
  VGV->LEVEL[60632+sub13[forind0]*1] = ZIDZ(0,POWER((VGV->LEVEL[5416
+sub13[forind0]*1]-VGV->LEVEL[22546+sub13[forind0]*1]),2.000000),POWER(
VGV->LEVEL[25982+sub13[forind0]*1],2.000000)) ;
}
/* SumTotalExcessError */
 {
  VGV->lastpos = 56277 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[60632+sub13[sumind0]*1] ;
  VGV->LEVEL[56277] = temp0 ;
}
/* Susceptible Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56431+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56431+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[56278
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36064+sub19[forind1]*1] ;
}
/* Sympthom Adj from Variant */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56794+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56794+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[9241
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[30125+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Vaccination Priority Multiplier */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 63542+sub13[forind0]*1 ;
  VGV->LEVEL[63542+sub13[forind0]*1] = MAX(1.000000,1.000000+(VGV->LEVEL[63593
]-1.000000)*(1.000000-VGV->LEVEL[47213]*VGV->LEVEL[43820+sub13[forind0]
*3+2*1])) ;
}
/* Sympthom Change by Vaccination Naive */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 57100+sub13[forind0]*1 ;
  VGV->LEVEL[57100+sub13[forind0]*1] = VGV->LEVEL[56431+sub13[forind0]
*3+0*1]*VGV->LEVEL[15769+sub13[forind0]*3+0*1]*VGV->LEVEL[63542+sub13[forind0]
*1] ;
}
/* Sympthom Change by Vaccination NVx */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 57151+sub13[forind0]*1 ;
  VGV->LEVEL[57151+sub13[forind0]*1] = VGV->LEVEL[56431+sub13[forind0]
*3+1*1]*VGV->LEVEL[15769+sub13[forind0]*3+1*1]*VGV->LEVEL[63542+sub13[forind0]
*1] ;
}
/* Sympthom Change by Vaccination Vx */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 57202+sub13[forind0]*1 ;
  VGV->LEVEL[57202+sub13[forind0]*1] = (-(VGV->LEVEL[56431+sub13[forind0]
*3+1*1]*VGV->LEVEL[15769+sub13[forind0]*3+1*1]*VGV->LEVEL[63542+sub13[forind0]
*1]*VGV->LEVEL[40229+2*1]/VGV->LEVEL[40229+1*1]+VGV->LEVEL[56431+sub13[forind0]
*3+0*1]*VGV->LEVEL[15769+sub13[forind0]*3+0*1]*VGV->LEVEL[63542+sub13[forind0]
*1]*VGV->LEVEL[40229+2*1]/VGV->LEVEL[40229+0*1])) ;
}
/* Sympthom Change by Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 56947+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[56947+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[57100
+sub13[forind0]*1]*VGV->LEVEL[36067+sub19[forind1]*1]+VGV->LEVEL[57151
+sub13[forind0]*1]*VGV->LEVEL[36070+sub19[forind1]*1]+VGV->LEVEL[57202
+sub13[forind0]*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* Sympthom Loss to Deaths */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 57253+sub13[forind0]*1 ;
  VGV->LEVEL[57253+sub13[forind0]*1] = VGV->LEVEL[24035+sub13[forind0]
*1]*VGV->LEVEL[57712] ;
}
/* Sympthom Reduction by Infectioun */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 57304+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[57304+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[15769
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[35394+sub13[forind0]
*3+sub19[forind1]*1] ;
}
/* Sympthoms from Immunity Loss NVx */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 57610+sub13[forind0]*1 ;
  VGV->LEVEL[57610+sub13[forind0]*1] = (1.000000-VGV->LEVEL[13575+sub13[forind0]
*3+1*1])*VGV->LEVEL[20505+sub13[forind0]*3+1*1]*(VGV->LEVEL[33808+sub13[forind0]
*3+1*1]+VGV->LEVEL[65008+sub13[forind0]*1]) ;
}
/* Sympthoms from Immunity Loss Vx */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 57661+sub13[forind0]*1 ;
  VGV->LEVEL[57661+sub13[forind0]*1] = (-VGV->LEVEL[15769+sub13[forind0]
*3+2*1])*VGV->LEVEL[65008+sub13[forind0]*1] ;
}
/* Sympthoms from Immunity Loss */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 57457+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[57457+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[57610
+sub13[forind0]*1]*VGV->LEVEL[36070+sub19[forind1]*1]+VGV->LEVEL[57661
+sub13[forind0]*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* Tests Per Million */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59246+sub13[forind0]*1 ;
  VGV->LEVEL[59246+sub13[forind0]*1] = VGV->LEVEL[6283+sub13[forind0]
*1]/VGV->LEVEL[43718+sub13[forind0]*1]*1000000.000000 ;
}
/* Time to Downgrade Risk Nt */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 59455+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[59455+sub13[forind0]*3+sub19[forind1]*1] = IF_THEN_ELSE(
VGV->LEVEL[53092]<VGV->LEVEL[0],(1.000000+VGV->LEVEL[53093]/100.000000
)*VGV->LEVEL[59404+sub13[forind0]*1],VGV->LEVEL[59404+sub13[forind0]
*1])*VGV->LEVEL[26392+sub19[forind1]*1] ;
}
/* Time to Herd Immunity */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 59609+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[9088+sub13[forind0]*3+sub19[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp1 += VGV->LEVEL[61195+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[59609+sub13[forind0]*1] = XIDZ(0,VGV->LEVEL[30437]*temp0
,temp1/VGV->LEVEL[60580],0) ;
}
/* Time to Herd Immunity VS */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 59660+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[59660+sub13[forind0]*3+sub19[forind1]*1] = XIDZ(0,VGV->LEVEL[30437
]*VGV->LEVEL[9088+sub13[forind0]*3+sub19[forind1]*1],VGV->LEVEL[61195
+sub13[forind0]*3+sub19[forind1]*1]/VGV->LEVEL[60580],0) ;
}
/* Total Economic Losses */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60581+sub13[forind0]*1 ;
  VGV->LEVEL[60581+sub13[forind0]*1] = VGV->LEVEL[3424+sub13[forind0]
*1]+VGV->LEVEL[24034]*VGV->LEVEL[21423+sub13[forind0]*1] ;
}
/* Total Potential Hospital Demand */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60683+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
for(sumind1=0;sumind1<2;sumind1++)
    temp0 += VGV->LEVEL[45403+sub13[forind0]*6+sub19[sumind0]*2+sub16[sumind1]
*1] ;
  VGV->LEVEL[60683+sub13[forind0]*1] = temp0 ;
}
/* Total to Offical Deaths Simulated Global */
 {
  VGV->lastpos = 60989 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += VGV->LEVEL[5212+sub13[sumind0]*3+sub19[sumind1]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp1 += VGV->LEVEL[54179+sub13[sumind0]*3+1*1] ;
  VGV->LEVEL[60989] = ZIDZ(0,temp0,temp1) ;
}
/* Total to Official Cases Simulated */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 60990+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[4141+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[60990+sub13[forind0]*1] = ZIDZ(0,temp0,VGV->LEVEL[54179
+sub13[forind0]*3+0*1]) ;
}
/* Total to Official Cases Simulated Global */
 {
  VGV->lastpos = 61041 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
for(sumind1=0;sumind1<3;sumind1++)
    temp0 += VGV->LEVEL[4141+sub13[sumind0]*3+sub19[sumind1]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp1 += VGV->LEVEL[54179+sub13[sumind0]*3+0*1] ;
  VGV->LEVEL[61041] = ZIDZ(0,temp0,temp1) ;
}
/* Total to Official Deaths Simulated */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 61042+sub13[forind0]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 += VGV->LEVEL[5212+sub13[forind0]*3+sub19[sumind0]*1] ;
  VGV->LEVEL[61042+sub13[forind0]*1] = ZIDZ(0,temp0,VGV->LEVEL[54179
+sub13[forind0]*3+1*1]) ;
}
/* TstInc */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 62725+sub13[forind0]*1 ;
  VGV->LEVEL[62725+sub13[forind0]*1] = VGV->LEVEL[13193+sub13[forind0]
*1] ;
}
/* Unconfirmed Vaccination */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 62776+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[62776+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[62929
+sub13[forind0]*3+sub19[forind1]*1]*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36064+sub19[forind1]*1]-(VGV->LEVEL[62929+sub13[forind0]
*3+0*1]+VGV->LEVEL[62929+sub13[forind0]*3+1*1])*VGV->LEVEL[28339+sub13[forind0]
*1]*VGV->LEVEL[36075+sub19[forind1]*1] ;
}
/* UnvaccinatedSusceptibles */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 63388+sub13[forind0]*1 ;
  VGV->LEVEL[63388+sub13[forind0]*1] = VGV->LEVEL[56584+sub13[forind0]
*3+0*1]+VGV->LEVEL[56584+sub13[forind0]*3+1*1] ;
}
/* Vaccination On */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 63490+sub13[forind0]*1 ;
  VGV->LEVEL[63490+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[0]<
VGV->LEVEL[64056],0,1.000000) ;
}
/* Vaccinations */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 63594+sub13[forind0]*3+sub19[forind1]*1 ;
  VGV->LEVEL[63594+sub13[forind0]*3+sub19[forind1]*1] = VGV->LEVEL[56431
+sub13[forind0]*3+sub19[forind1]*1] ;
}
/* Vaccine Effectiveness */
for(forind0=0;forind0<3;forind0++)
 {
  VGV->lastpos = 64053+sub18[forind0]*1 ;
  VGV->LEVEL[64053+sub18[forind0]*1] = (1.000000-VGV->LEVEL[17407+2
*1])*(1.000000+VGV->LEVEL[64590+sub18[forind0]*1]) ;
}
/* Vaccine Taking Population */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64057+sub13[forind0]*1 ;
  VGV->LEVEL[64057+sub13[forind0]*1] = VGV->LEVEL[43718+sub13[forind0]
*1]-VGV->LEVEL[64749+sub13[forind0]*1] ;
}
/* Vaccine Taking Population All */
 {
  VGV->lastpos = 64108 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp0 += VGV->LEVEL[64057+sub13[sumind0]*1] ;
  VGV->LEVEL[64108] = temp0 ;
}
/* VacWinStart */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64109+sub13[forind0]*1 ;
  VGV->LEVEL[64109+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[63541
]>1.000000,IF_THEN_ELSE(VGV->LEVEL[0]>VGV->LEVEL[64056],2.000000,(-1.000000)
),(-1.000000)) ;
}
/* Variant IFR Multiplier */
 {
  VGV->lastpos = 64316+2*1 ;
    temp0 = 1.0 ;
for(sumind0=0;sumind0<3;sumind0++)
    temp0 *= VGV->LEVEL[64160+sub18[sumind0]*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<51;sumind0++)
    temp1 += VGV->LEVEL[53663+sub13[sumind0]*1] ;
  VGV->LEVEL[64316+2*1] = POWER(temp0,(temp1/(COMPREAL)51)) ;
}
/* Variant Impact on Transmission */
 {
  VGV->lastpos = 64325+1*1 ;
  VGV->LEVEL[64325+1*1] = VGV->LEVEL[64587+1*1]+VGV->LEVEL[64587+0
*1]-1.000000 ;
}
/* Vx Cumulative Deaths Error */
for(forind0=0;forind0<51;forind0++)
 {
  VGV->lastpos = 64954+sub13[forind0]*1 ;
  VGV->LEVEL[64954+sub13[forind0]*1] = IF_THEN_ELSE(VGV->LEVEL[22393
+sub13[forind0]*1]>0,ABS(VGV->LEVEL[4753+sub13[forind0]*3+2*1]-VGV->LEVEL[22393
+sub13[forind0]*1])*VGV->LEVEL[65370],0) ;
}
/* W Ave Acuity Hospitalized */
for(forind0=0;forind0<51;forind0++)
for(forind1=0;forind1<3;forind1++)
 {
  VGV->lastpos = 65059+sub13[forind0]*3+sub19[forind1]*1 ;
    temp0 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp0 += VGV->LEVEL[15463+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1]*VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
    temp1 = 0.0 ;
for(sumind0=0;sumind0<2;sumind0++)
    temp1 += VGV->LEVEL[7048+sub13[forind0]*6+sub19[forind1]*2+sub16[sumind0]
*1] ;
  VGV->LEVEL[65059+sub13[forind0]*3+sub19[forind1]*1] = ZIDZ(0,temp0
,temp1) ;
}
} /* comp_aux */
int execute_curloop() {return(0);}
static void vec_arglist_init()
{
ST_INDEX stlist[10] = {3236,2026,2070,3236,728,728,5128,3236,2026,
2400};
add_vecarg_info(stlist,10);
}
void VEFCC comp_rate(void)
{
mdl_func0();
}

void VEFCC comp_delay(void)
{
mdl_func1();
}

void VEFCC init_time(void)
{
mdl_func2();
}

void VEFCC init_tstep(void)
{
mdl_func3();
}

void VEFCC comp_init(void)
{
mdl_func4();
mdl_func5();
mdl_func6();
mdl_func7();
mdl_func8();
}

void VEFCC comp_reinit(void)
{
mdl_func9();
}

void VEFCC comp_tstep(void)
{
mdl_func10();
}

void VEFCC comp_aux(void)
{
mdl_func11();
mdl_func12();
mdl_func13();
mdl_func14();
mdl_func15();
}

