SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79-Updated.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf,GDP_Vensim.vdfx"
SIMULATE>SETVAL|VaxInc=1.01
SIMULATE>SETVAL|Strength of Adherence Fatigue[Alabama]=0.5119114300000001
SIMULATE>SETVAL|Strength of Adherence Fatigue[Alaska]=0.34856716
SIMULATE>SETVAL|Strength of Adherence Fatigue[Arizona]=1.6827105
SIMULATE>SETVAL|Strength of Adherence Fatigue[Arkansas]=0.83115425
SIMULATE>SETVAL|Strength of Adherence Fatigue[California]=2.7415541
SIMULATE>SETVAL|Strength of Adherence Fatigue[Colorado]=0.31548763999999996
SIMULATE>SETVAL|Strength of Adherence Fatigue[Connecticut]=2.2087488
SIMULATE>SETVAL|Strength of Adherence Fatigue[Delaware]=0.40501404
SIMULATE>SETVAL|Strength of Adherence Fatigue[Florida]=0.54551009
SIMULATE>SETVAL|Strength of Adherence Fatigue[Georgia]=0.8045377199999999
SIMULATE>SETVAL|Strength of Adherence Fatigue[Hawaii]=0.37697341
SIMULATE>SETVAL|Strength of Adherence Fatigue[Idaho]=0.5113539100000001
SIMULATE>SETVAL|Strength of Adherence Fatigue[Illinois]=1.0292102
SIMULATE>SETVAL|Strength of Adherence Fatigue[Indiana]=0.0054603832
SIMULATE>SETVAL|Strength of Adherence Fatigue[Iowa]=1.3651766
SIMULATE>SETVAL|Strength of Adherence Fatigue[Kansas]=1.2581974
SIMULATE>SETVAL|Strength of Adherence Fatigue[Kentucky]=0.022773076
SIMULATE>SETVAL|Strength of Adherence Fatigue[Louisiana]=1.2672672
SIMULATE>SETVAL|Strength of Adherence Fatigue[Maine]=0.33678652000000003
SIMULATE>SETVAL|Strength of Adherence Fatigue[Maryland]=2.0970731
SIMULATE>SETVAL|Strength of Adherence Fatigue[Massachusetts]=1.7342205
SIMULATE>SETVAL|Strength of Adherence Fatigue[Michigan]=0.42954592999999996
SIMULATE>SETVAL|Strength of Adherence Fatigue[Minnesota]=0.62981883
SIMULATE>SETVAL|Strength of Adherence Fatigue[Mississippi]=0.5249293199999999
SIMULATE>SETVAL|Strength of Adherence Fatigue[Missouri]=0.076210358
SIMULATE>SETVAL|Strength of Adherence Fatigue[Montana]=2.2901952000000003
SIMULATE>SETVAL|Strength of Adherence Fatigue[Nebraska]=0.9681385299999999
SIMULATE>SETVAL|Strength of Adherence Fatigue[Nevada]=0.1602668
SIMULATE>SETVAL|Strength of Adherence Fatigue[New Hampshire]=0.99327541
SIMULATE>SETVAL|Strength of Adherence Fatigue[New Jersey]=1.9425531999999999
SIMULATE>SETVAL|Strength of Adherence Fatigue[New Mexico]=2.2283831999999997
SIMULATE>SETVAL|Strength of Adherence Fatigue[New York]=2.4365845999999998
SIMULATE>SETVAL|Strength of Adherence Fatigue[North Carolina]=0.59552125
SIMULATE>SETVAL|Strength of Adherence Fatigue[North Dakota]=0.093969895
SIMULATE>SETVAL|Strength of Adherence Fatigue[Ohio]=7.6651425e-06
SIMULATE>SETVAL|Strength of Adherence Fatigue[Oklahoma]=0.85298237
SIMULATE>SETVAL|Strength of Adherence Fatigue[Oregon]=0.098131802
SIMULATE>SETVAL|Strength of Adherence Fatigue[Pennsylvania]=0.014875482
SIMULATE>SETVAL|Strength of Adherence Fatigue[Rhode Island]=2.0594202999999998
SIMULATE>SETVAL|Strength of Adherence Fatigue[South Carolina]=0.67615965
SIMULATE>SETVAL|Strength of Adherence Fatigue[South Dakota]=0.71880084
SIMULATE>SETVAL|Strength of Adherence Fatigue[Tennessee]=0.47603218999999997
SIMULATE>SETVAL|Strength of Adherence Fatigue[Texas]=0.020250499999999998
SIMULATE>SETVAL|Strength of Adherence Fatigue[Utah]=0.36417873
SIMULATE>SETVAL|Strength of Adherence Fatigue[Vermont]=0.9945055899999999
SIMULATE>SETVAL|Strength of Adherence Fatigue[Virginia]=1.5294834
SIMULATE>SETVAL|Strength of Adherence Fatigue[Washington]=9.5967877e-06
SIMULATE>SETVAL|Strength of Adherence Fatigue[West Virginia]=7.8834035e-06
SIMULATE>SETVAL|Strength of Adherence Fatigue[Wisconsin]=0.13320284
SIMULATE>SETVAL|Strength of Adherence Fatigue[Wyoming]=1.5918710999999999
SIMULATE>SETVAL|Strength of Adherence Fatigue[District of Columbia]=1.9068396

SIMULATE>RUNNAME|Covidparam_Strength
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
