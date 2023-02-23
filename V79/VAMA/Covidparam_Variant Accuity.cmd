SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|COVID-V79-All.voc
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf"
SIMULATE>SETVAL|Variant Accuity Multiplier[Delta]=1.01
SIMULATE>SETVAL|VaxInc=0
SIMULATE>SETVAL|Variant Accuity Multiplier[Omicron]=0.5428063200000001
SIMULATE>SETVAL|VaxInc=0

SIMULATE>RUNNAME|Covidparam_Variant Accuity
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|../SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
