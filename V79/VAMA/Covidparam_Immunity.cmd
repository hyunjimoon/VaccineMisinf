SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|COVID-V79-All.voc
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf"
SIMULATE>SETVAL|Immunity Loss Time[NVx]=170.1446
SIMULATE>SETVAL|VaxInc=1.01

SIMULATE>RUNNAME|Covidparam_Immunity
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|../SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
