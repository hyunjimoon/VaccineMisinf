SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79-Updated.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf,GDP_Vensim.vdfx"
SIMULATE>SETVAL|VaxInc=1.01
SIMULATE>SETVAL|Reference Force of Infection[Alabama]=0.37887322
SIMULATE>SETVAL|Reference Force of Infection[Alaska]=0.40621392
SIMULATE>SETVAL|Reference Force of Infection[Arizona]=0.63682318
SIMULATE>SETVAL|Reference Force of Infection[Arkansas]=0.32103859999999995
SIMULATE>SETVAL|Reference Force of Infection[California]=0.34469785000000003
SIMULATE>SETVAL|Reference Force of Infection[Colorado]=0.42411617
SIMULATE>SETVAL|Reference Force of Infection[Connecticut]=0.34325153
SIMULATE>SETVAL|Reference Force of Infection[Delaware]=0.2897387
SIMULATE>SETVAL|Reference Force of Infection[Florida]=0.35028214
SIMULATE>SETVAL|Reference Force of Infection[Georgia]=0.43317789
SIMULATE>SETVAL|Reference Force of Infection[Hawaii]=0.24745505
SIMULATE>SETVAL|Reference Force of Infection[Idaho]=0.3815881
SIMULATE>SETVAL|Reference Force of Infection[Illinois]=0.26706521
SIMULATE>SETVAL|Reference Force of Infection[Indiana]=0.42612910000000004
SIMULATE>SETVAL|Reference Force of Infection[Iowa]=0.22761865
SIMULATE>SETVAL|Reference Force of Infection[Kansas]=0.34825406000000003
SIMULATE>SETVAL|Reference Force of Infection[Kentucky]=0.50877437
SIMULATE>SETVAL|Reference Force of Infection[Louisiana]=0.39923785
SIMULATE>SETVAL|Reference Force of Infection[Maine]=0.6177432700000001
SIMULATE>SETVAL|Reference Force of Infection[Maryland]=0.32781065
SIMULATE>SETVAL|Reference Force of Infection[Massachusetts]=0.24840344
SIMULATE>SETVAL|Reference Force of Infection[Michigan]=0.25011438
SIMULATE>SETVAL|Reference Force of Infection[Minnesota]=0.1994447
SIMULATE>SETVAL|Reference Force of Infection[Mississippi]=0.40256176
SIMULATE>SETVAL|Reference Force of Infection[Missouri]=0.31249602
SIMULATE>SETVAL|Reference Force of Infection[Montana]=0.81681932
SIMULATE>SETVAL|Reference Force of Infection[Nebraska]=0.62877752
SIMULATE>SETVAL|Reference Force of Infection[Nevada]=0.40569175
SIMULATE>SETVAL|Reference Force of Infection[New Hampshire]=0.30546339
SIMULATE>SETVAL|Reference Force of Infection[New Jersey]=0.27358274
SIMULATE>SETVAL|Reference Force of Infection[New Mexico]=0.98085342
SIMULATE>SETVAL|Reference Force of Infection[New York]=0.30104464
SIMULATE>SETVAL|Reference Force of Infection[North Carolina]=0.37118914000000003
SIMULATE>SETVAL|Reference Force of Infection[North Dakota]=0.2249169
SIMULATE>SETVAL|Reference Force of Infection[Ohio]=0.31716525
SIMULATE>SETVAL|Reference Force of Infection[Oklahoma]=0.35853485
SIMULATE>SETVAL|Reference Force of Infection[Oregon]=0.45183865
SIMULATE>SETVAL|Reference Force of Infection[Pennsylvania]=0.33491700999999996
SIMULATE>SETVAL|Reference Force of Infection[Rhode Island]=0.27309087
SIMULATE>SETVAL|Reference Force of Infection[South Carolina]=0.51315979
SIMULATE>SETVAL|Reference Force of Infection[South Dakota]=0.22319485
SIMULATE>SETVAL|Reference Force of Infection[Tennessee]=0.409454
SIMULATE>SETVAL|Reference Force of Infection[Texas]=0.5279936599999999
SIMULATE>SETVAL|Reference Force of Infection[Utah]=0.4232001
SIMULATE>SETVAL|Reference Force of Infection[Vermont]=0.3766896
SIMULATE>SETVAL|Reference Force of Infection[Virginia]=0.38453629
SIMULATE>SETVAL|Reference Force of Infection[Washington]=0.38451003
SIMULATE>SETVAL|Reference Force of Infection[West Virginia]=0.35428173999999996
SIMULATE>SETVAL|Reference Force of Infection[Wisconsin]=0.40240622
SIMULATE>SETVAL|Reference Force of Infection[Wyoming]=0.5672917500000001
SIMULATE>SETVAL|Reference Force of Infection[District of Columbia]=0.41086194

SIMULATE>RUNNAME|Covidparam_Reference
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
