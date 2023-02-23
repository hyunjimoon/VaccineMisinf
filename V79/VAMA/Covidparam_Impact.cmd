SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79-Updated.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf,GDP_Vensim.vdfx"
SIMULATE>SETVAL|VaxInc=1.01
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Alabama]=0.29633804
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Alaska]=0.7480342799999999
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Arizona]=0.63905427
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Arkansas]=0.6895189199999999
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[California]=0.74119961
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Colorado]=0.64233576
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Connecticut]=0.8079808100000001
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Delaware]=0.7942468300000001
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Florida]=0.80521947
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Georgia]=0.50046106
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Hawaii]=0.67804734
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Idaho]=0.74782925
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Illinois]=0.70845945
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Indiana]=0.10100101
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Iowa]=0.51447683
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Kansas]=0.6220994000000001
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Kentucky]=0.35236375
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Louisiana]=0.56747355
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Maine]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Maryland]=0.78559921
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Massachusetts]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Michigan]=0.66253374
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Minnesota]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Mississippi]=0.58301745
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Missouri]=0.51079033
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Montana]=0.35431102999999997
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Nebraska]=0.7398886299999999
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Nevada]=0.76067241
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[New Hampshire]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[New Jersey]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[New Mexico]=0.80798687
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[New York]=0.32159309
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[North Carolina]=0.71080669
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[North Dakota]=0.7723358899999999
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Ohio]=0.68139852
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Oklahoma]=0.63088943
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Oregon]=0.808
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Pennsylvania]=0.16322913
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Rhode Island]=0.59536773
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[South Carolina]=0.78044114
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[South Dakota]=0.51787346
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Tennessee]=0.43126394
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Texas]=0.4877593
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Utah]=0.6643981999999999
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Vermont]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Virginia]=0.808
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Washington]=0.80799899
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[West Virginia]=0.79034722
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Wisconsin]=0.15501985000000001
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[Wyoming]=0.37356264000000006
SIMULATE>SETVAL|Impact of Treatment on Fatality Rate[District of Columbia]=0.48918946

SIMULATE>RUNNAME|Covidparam_Impact
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
