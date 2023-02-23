SPECIAL>NOINTERACTION
SPECIAL>LOADMODEL|CovidUSA-Econ-V79-Updated.mdl
SIMULATE>payoff|PayoffFlowV77-Policy.vpd
SIMULATE>sensitivity|
SIMULATE>optparm|
SIMULATE>savelist|
SIMULATE>senssavelist|
SIMULATE>DATA|"CovidModelInputs - ConstantDataStates.vdf,CovidModelInputs - CRWStates.vdf,CovidModelInputs - DeathDataStates.vdf,CovidModelInputs - FlowDataStates.vdf,CovidModelInputs - FormattedDataStates.vdf,CovidModelInputs - TestDataStates.vdf,GDP_Vensim.vdfx"
SIMULATE>SETVAL|VaxInc=1.01
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Alabama]=0.00050787749
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Alaska]=9.6065746e-05
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Arizona]=0.00014496934000000002
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Arkansas]=0.00014310589
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[California]=0.00014518043
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Colorado]=0.00031745007
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Connecticut]=0.00048232954
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Delaware]=0.00098026661
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Florida]=0.00100999798
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Georgia]=0.00045401722
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Hawaii]=0.00012729333
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Idaho]=0.0007351991999999999
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Illinois]=9.615977700000001e-05
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Indiana]=0.0004778613
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Iowa]=9.6886472e-05
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Kansas]=0.00010194738
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Kentucky]=0.00023022848999999999
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Louisiana]=0.00032423525
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Maine]=0.00100999798
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Maryland]=0.00016083745
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Massachusetts]=0.00013692671
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Michigan]=0.00016990018000000002
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Minnesota]=0.00011266146
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Mississippi]=0.00034666634
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Missouri]=9.4316931e-05
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Montana]=0.00013782662
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Nebraska]=0.00089237338
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Nevada]=0.00011041522
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[New Hampshire]=0.00086487512
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[New Jersey]=0.00072540422
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[New Mexico]=0.00022218485
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[New York]=0.00093654674
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[North Carolina]=0.00028062547
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[North Dakota]=9.3413082e-05
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Ohio]=0.00014883865
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Oklahoma]=0.00019069305000000002
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Oregon]=0.00100999899
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Pennsylvania]=0.00015418862
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Rhode Island]=0.00055442839
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[South Carolina]=0.00024693793
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[South Dakota]=0.0006187320600000001
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Tennessee]=0.00012672368999999998
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Texas]=0.00029644307999999997
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Utah]=0.00066528902
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Vermont]=0.0010099697
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Virginia]=0.00011673276999999999
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Washington]=0.00089577001
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[West Virginia]=0.0001625696
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Wisconsin]=0.00033073864
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[Wyoming]=0.00014457544
SIMULATE>SETVAL|Base Fatality Rate for Unit Acuity[District of Columbia]=0.0007995927599999999

SIMULATE>RUNNAME|Covidparam_Base
SIMULATE>REPORT|1
MENU>RUN|o
MENU>VDF2CSV|!|!|SAVEFILE.txt||||
SPECIAL>CLEARRUNS
MENU>EXIT
