SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79-Updated.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf,GDP_Vensim.vdfx"
SIMULATE>SETVAL|VaxInc=1.01
SIMULATE>SETVAL|Extra Vaccine Impact on Responsiveness[Naive]=1.01

SIMULATE>RUNNAME|Covidparam_Extra
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
