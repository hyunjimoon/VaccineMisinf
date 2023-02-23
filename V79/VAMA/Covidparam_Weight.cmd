SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79-Updated.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf,GDP_Vensim.vdfx"
SIMULATE>SETVAL|VaxInc=1.01
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Maine]=0.22894175
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Illinois]=2.1146168e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Tennessee]=0.45840971
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Maryland]=2.6593098e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Connecticut]=0.91644471
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Texas]=0.65136112
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Massachusetts]=0.8828208
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Mississippi]=0.7430125599999999
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Minnesota]=0.8075859000000001
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Oklahoma]=0.53802902
SIMULATE>SETVAL|Weight on Reported Probability of Infection[New Mexico]=0.5291935400000001
SIMULATE>SETVAL|Weight on Reported Probability of Infection[South Dakota]=0.16327761
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Indiana]=0.43843797
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Montana]=0.91600233
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Georgia]=0.85079774
SIMULATE>SETVAL|Weight on Reported Probability of Infection[District of Columbia]=0.80871205
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Missouri]=0.7604380900000001
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Pennsylvania]=1.6097279e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Arizona]=0.33107901
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Colorado]=0.90961004
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Oregon]=2.4783683e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[North Carolina]=0.38937721999999997
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Hawaii]=1.1691255000000001e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Rhode Island]=0.59758367
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Alaska]=0.38270718
SIMULATE>SETVAL|Weight on Reported Probability of Infection[California]=0.9594212200000001
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Washington]=2.36845e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Michigan]=0.8857144499999999
SIMULATE>SETVAL|Weight on Reported Probability of Infection[North Dakota]=0.24247474000000002
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Delaware]=0.5262382800000001
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Wyoming]=0.89953529
SIMULATE>SETVAL|Weight on Reported Probability of Infection[New York]=0.99986061
SIMULATE>SETVAL|Weight on Reported Probability of Infection[South Carolina]=0.61359217
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Nebraska]=0.58104593
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Louisiana]=0.89289757
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Virginia]=0.0032422111
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Alabama]=0.32227181
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Utah]=0.096356323
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Arkansas]=0.6832145
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Idaho]=0.0041847633
SIMULATE>SETVAL|Weight on Reported Probability of Infection[New Hampshire]=0.8738196800000001
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Wisconsin]=0.49844106
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Kansas]=2.9012956999999997e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Kentucky]=0.11516424
SIMULATE>SETVAL|Weight on Reported Probability of Infection[West Virginia]=4.6730983e-05
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Florida]=1.7689039e-06
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Iowa]=0.8162315
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Vermont]=0.45085289
SIMULATE>SETVAL|Weight on Reported Probability of Infection[New Jersey]=0.91664772
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Nevada]=0.19286253
SIMULATE>SETVAL|Weight on Reported Probability of Infection[Ohio]=0.11833261

SIMULATE>RUNNAME|Covidparam_Weight
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
