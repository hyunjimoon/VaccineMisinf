import numpy as np
import pandas as pd
from VST.vst import vst_text, vst
import pandas
import os
import json
FINAL_TIME=1100
vgpath = "C:/Program Files (x86)/Vengine2/Vensim - vengine.exe"
log = "log.txt"

# spatial subscript
state_names = ['Alabama', 'Alaska', 'Arizona', 'Arkansas', 'California', 'Colorado', 'Connecticut', 'Delaware', 'Florida', 'Georgia', 'Hawaii', 'Idaho', 'Illinois', 'Indiana', 'Iowa', 'Kansas', 'Kentucky', 'Louisiana', 'Maine', 'Maryland', 'Massachusetts', 'Michigan', 'Minnesota', 'Mississippi', 'Missouri', 'Montana', 'Nebraska', 'Nevada', 'New Hampshire', 'New Jersey', 'New Mexico', 'New York', 'North Carolina', 'North Dakota', 'Ohio', 'Oklahoma', 'Oregon', 'Pennsylvania', 'Rhode Island', 'South Carolina', 'South Dakota', 'Tennessee', 'Texas', 'Utah', 'Vermont', 'Virginia', 'Washington', 'West Virginia', 'Wisconsin', 'Wyoming', 'District of Columbia']
variant_list = ["Delta", 'Omicron', "BA5"]
vax_status_list = ['Vx', 'NVx']
param_lst_lst =[]
state_lst_1=[]
state_lst_2=[]
state_lst_3=[]
state_lst_4=[]
state_lst_5=[]
state_lst_6=[]
for name in state_names:
    # state_lst_1.append(f"Impact of Treatment on Fatality Rate[{name}]")
    # state_lst_2.append(f"Base Fatality Rate for Unit Acuity[{name}]")
    # state_lst_3.append(f"Reference Force of Infection[{name}]")
    # state_lst_4.append(f"Strength of Adherence Fatigue[{name}]")
    state_lst_5.append(f"Variant Intro Start Time[{name}]")
    state_lst_6.append(f"Variant Intro Start Time2[{name}]")

param_lst_lst=[
    # state_lst_1,
    # state_lst_2,
    # state_lst_3,
    # state_lst_4,
    state_lst_5,
    state_lst_6,
    ['Variant Impact on Immunity Loss Time[Omicron]'],
    ['Variant Impact on Immunity Loss Time[Delta]'],
    ['Variant Impact on Immunity Loss Time[BA5]'],
    ['Extra Vaccine Impact on Responsiveness[Vx]'],
    ['Extra Vaccine Impact on Responsiveness[NVx]'],
    ['Extra Vaccine Impact on Responsiveness[Naive]'],
    ['Immunity Loss Time[Vx]'],
    ['Immunity Loss Time[NVx]'],
    ['Immunity Loss Time[Naive]'],
    ['Variant Accuity Multiplier[Omicron]'],
    ['Variant Accuity Multiplier[Delta]'],
    ['Variant Accuity Multiplier[BA5]'],
    ['Variant Intro Start Time3'],
 ['Variant Transmission Multiplier[Omicron]'], ['Variant Transmission Multiplier[Delta]'], ['Variant Transmission Multiplier[BA5]']]

controlfilename = 'Control.txt' #input("Enter control file name (with extension):")
cf = json.load(open(controlfilename, 'r'))
# Unpack controlfile into variables
for k,v in cf.items():
    exec(k + '=v')

vax_inc_1dot1=1.01
vax_inc_base=1
vax_inc_zero=0
def calc_change_with_respect_to_pop(change):
    cost_per_person=np.zeros(shape=change.shape)
    cost_per_person[0]=change[0]/change[3] #death
    cost_per_person[1]=change[1]/change[3]# gdp
    cost_per_person[2]=change[2]/change[3] #hospitalization
    cost_per_person[3]=(change[0]+change[1]+change[2])/change[3]
    for i in range(change.shape[0]-51, change.shape[0]):
        cost_per_person[i-51*3]=change[i-51*3]/change[i]#4
        cost_per_person[i-51*2]=change[i-51*2]/change[i]#55
        cost_per_person[i-51*1]=change[i-51*1]/change[i]#106
        cost_per_person[i]=(change[i-51*1]+change[i-51*2]+change[i-51*3])/change[i]#157
    print(cost_per_person)

    return cost_per_person
def calc_param_impact_on_cost(param_name_list, percent_change): #list of str or list of list (local variables), # real
    """Find the costs of the pandemic at vaxinc vals of 0, 1, 1.01 when the params passed in are changed by percent_change
        with base parameter
        b1. calc the cost difference VaxInc: diff_cost_01, diff_cost_1_1dot1
        b2. calculate vaccinated people difference VaxInc: diff_ppl_01, diff_ppl_1_1dot1
        b3. marginal cost: mc_01 = diff_cost_01 / diff_ppl_01, mc_1_1dot1 = diff_cost_1_1dot1/diff_ppl_1_1dot1
        with 1.01 * base parameter
        c1. calc the cost differece VaxInc: diff_cost_01_c, diff_cost_1_1dot1_c
        c2. calculate vaccinated people difference VaxInc: diff_ppl_01_c, diff_ppl_1_1dot1_c
        c3. marginal cost: mc_01_c = diff_cost_01_c / diff_ppl_01_c, mc_1_1dot1_c = diff_cost_1_1dot1_c/diff_ppl_1_1dot1_c
        ela_01 = ((mc_01_c - mc_01) / mc_01) / 0.01
        ela_1_1dot1 = ((mc_1_1dot1_c - mc_1_1dot1) / mc_1_1dot1) / 0.01 #not doing this right now"""
    full_output_df=pd.DataFrame()
    for VaxInc_val in [0, 1, 1.01]:
        param_new_val_list=[]
        for item in param_name_list:
            try:
                param_base = vst_text.get_value("V79-OptimTest.out", item)
            except TypeError: #if we can't find param in optimization output, pull it out of model directly, should be done form mdl but is currently from .tab generated from vensim
                df = pandas.read_csv("test.tab", sep="\t", index_col=0) #raw values (all params outside .out, manually generated from .mdl/ can read from .mdl)
                param_base=df.loc[item][0]
            param_new_val_list.append(param_base * percent_change)  # TODO: make this function with list param for rgn
        setval_lst = [("VaxInc", VaxInc_val)]+[(param_name, param_new_val) for param_name, param_new_val in zip(param_name_list, param_new_val_list)]
        run = vst.Script(cf, f"param_{param_name_list[0].split()[0]}", log, setvals=setval_lst, simtype='r')
        run.compile_script(vgpath, log, subdir="VAMA", check_funcs=[lambda a, b: True])
        output_df = pandas.read_csv(f"VAMA/Covidparam_{param_name_list[0].split()[0]}.csv")
        output_vals = output_df[output_df.columns[-1]] # removing time dims # multi-index
        output_vals.rename(VaxInc_val, inplace=True)
        full_output_df = full_output_df.append(
            output_vals)
    return full_output_df.T
# baseline run, the name sensitivity to weather is chosen arbritraily
results=calc_param_impact_on_cost(["Sensitivity to Weather"], 1) #dataframe
marg_delta_wrt_vaxinc=results[vax_inc_1dot1]-results[vax_inc_base] # $
marg_cost_per_person=calc_change_with_respect_to_pop(marg_delta_wrt_vaxinc) #$/person

avg_delta_wrt_vaxinc=results[vax_inc_base]-results[vax_inc_zero] # not df.iloc[1] but df.loc[1] as the col name is int (0,1,1.01)
avg_cost_per_person=calc_change_with_respect_to_pop(avg_delta_wrt_vaxinc)

pd.Series(marg_cost_per_person).to_csv("marg_cost_per_person_base.tsv", sep="\t")
pd.Series(avg_cost_per_person).to_csv("avg_cost_per_person_base.tsv", sep="\t")
marg_elasticity_dict={}
avg_elas_dict={}
for param_lst in param_lst_lst:
    print(param_lst)
    results_param = calc_param_impact_on_cost(param_lst, 1.01)# $

    marg_diff = results_param[vax_inc_1dot1] - results_param[vax_inc_base] #$
    marg_cost_per_person_param1dot1=calc_change_with_respect_to_pop(marg_diff) # $/person

    avg_diff = results_param[vax_inc_base] - results_param[vax_inc_zero]
    avg_cost_per_person_param1dot1=calc_change_with_respect_to_pop(avg_diff)

    marg_elasticity_dict[param_lst[0]]= ((marg_cost_per_person_param1dot1 - marg_cost_per_person) / marg_cost_per_person) / (0.01) # unitless
    avg_elas_dict[param_lst[0]]= ((avg_cost_per_person_param1dot1 - avg_cost_per_person) / avg_cost_per_person) / (0.01)

    print(marg_elasticity_dict[param_lst[0]]) # giving nan bc of division by zero
    print(avg_elas_dict[param_lst[0]])
    filename = filename.replace("[Alabama]", "")
    filename = f"{param_lst[0].replace(' ','_')}_marg.tsv"
    pd.Series(marg_elasticity_dict[param_lst[0]]).to_csv(filename, sep ="\t") # giving nan bc of division by zero
    filename = f"{param_lst[0].replace(' ', '_')}_avg.tsv"
    pd.Series(avg_elas_dict[param_lst[0]]).to_csv(filename, sep ="\t")

# stores the list of params in tsv file
params = [x[0].replace("[Alabama]", "") for x in param_lst_lst]
file = open('params.txt','w')
for item in params:
	file.write(item+"\n")
file.close()
