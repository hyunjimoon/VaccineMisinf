<<<<<<< HEAD
import numpy as np
import pandas as pd
from VST.vst import vst_text, vst
import pandas

=======
import pandas as pd

from VST.vst import vst_text, vst

import pandas


>>>>>>> fb4fdedee8ae083cc8e85a6343b8ecd4d52c19de
state_to_code_dict = {
    "Alabama": "AL",
    "Alaska": "AK",
    "Arizona": "AZ",
    "Arkansas": "AR",
    "California": "CA",
    "Colorado": "CO",
    "Connecticut": "CT",
    "Delaware": "DE",
    "Florida": "FL",
    "Georgia": "GA",
    "Hawaii": "HI",
    "Idaho": "ID",
    "Illinois": "IL",
    "Indiana": "IN",
    "Iowa": "IA",
    "Kansas": "KS",
    "Kentucky": "KY",
    "Louisiana": "LA",
    "Maine": "ME",
    "Maryland": "MD",
    "Massachusetts": "MA",
    "Michigan": "MI",
    "Minnesota": "MN",
    "Mississippi": "MS",
    "Missouri": "MO",
    "Montana": "MT",
    "Nebraska": "NE",
    "Nevada": "NV",
    "New Hampshire": "NH",
    "New Jersey": "NJ",
    "New Mexico": "NM",
    "New York": "NY",
    "North Carolina": "NC",
    "North Dakota": "ND",
    "Ohio": "OH",
    "Oklahoma": "OK",
    "Oregon": "OR",
    "Pennsylvania": "PA",
    "Rhode Island": "RI",
    "South Carolina": "SC",
    "South Dakota": "SD",
    "Tennessee": "TN",
    "Texas": "TX",
    "Utah": "UT",
    "Vermont": "VT",
    "Virginia": "VA",
    "Washington": "WA",
    "West Virginia": "WV",
    "Wisconsin": "WI",
    "Wyoming": "WY",
    "District of Columbia": "DC",
<<<<<<< HEAD
}
state_names = [key for key, value in state_to_code_dict.items()]
import os
import json
FINAL_TIME=1100
vgpath = "C:/Program Files (x86)/Vengine2/Vensim - vengine.exe"
log = "log.txt"
variant_list = ["Delta", 'Omicron', "BA5"]
vax_status_list = ['Vx', 'NVx']
param_lst =[] #['Sensitivity to Weather']
state_lst_1=[]
state_lst_2=[]
state_lst_3=[]
state_lst_4=[]
state_lst_5=[]
state_lst_6=[]
for name in state_names:
    state_lst_1.append(f"Impact of Treatment on Fatality Rate[{name}]")
    state_lst_2.append(f"Base Fatality Rate for Unit Acuity[{name}]")
    state_lst_3.append(f"Reference Force of Infection[{name}]")
    state_lst_4.append(f"Strength of Adherence Fatigue[{name}]")
    state_lst_5.append(f"Variant Intro Start Time[{name}]")
    state_lst_6.append(f"Variant Intro Start Time2[{name}]")

param_lst=[
    # state_lst_1,
    # state_lst_2,
    # state_lst_3,
    # state_lst_4,
    # state_lst_5,
    # state_lst_6,
    # ['Extra Vaccine Impact on Responsiveness[Vx]'],
    # ['Extra Vaccine Impact on Responsiveness[NVx]'],
    # ['Extra Vaccine Impact on Responsiveness[Naive]'],
    # ['Immunity Loss Time[Vx]'],
    # ['Immunity Loss Time[NVx]'],
    # ['Immunity Loss Time[Naive]'],
    # ['Variant Accuity Multiplier[Omicron]'],
    # ['Variant Accuity Multiplier[Delta]'],
    # ['Variant Accuity Multiplier[BA5]'],
    # ['Variant Impact on Immunity Loss Time[Omicron]'],
    # ['Variant Impact on Immunity Loss Time[Delta]'],
    # ['Variant Impact on Immunity Loss Time[BA5]'],
    # ['Variant Intro Start Time3'],
 ['Variant Transmission Multiplier[Omicron]'], ['Variant Transmission Multiplier[Delta]'], ['Variant Transmission Multiplier[BA5]']]
controlfilename = 'Control.txt' #input("Enter control file name (with extension):")
cf = json.load(open(controlfilename, 'r'
                                     ''))
# Unpack controlfile into variables
for k,v in cf.items():
    exec(k + '=v')
vax_inc_marg=1.01
vax_inc_base=1
vax_inc_avg=0
def calc_change_with_respect_to_pop(change):
    new=np.zeros(shape=change.shape)
    new[0]=change[0]/change[3]
    new[1]=change[1]/change[3]
    new[2]=change[2]/change[3]
    new[3]=(change[0]+change[1]+change[2])/change[3]
    for i in range(change.shape[0]-51, change.shape[0]):
        #start from 208
        new[i-51*3]=change[i-51*3]/change[i]#4
        new[i-51*2]=change[i-51*2]/change[i]#55
        new[i-51*1]=change[i-51*1]/change[i]#106
        new[i]=(change[i-51*1]+change[i-51*2]+change[i-51*3])/change[i]#157
    return new
def find_marginal_vax_eff(param_name_list, percent_change): #list of str or list of list (local variables), # real
    full_output_df=pd.DataFrame()
    for VaxInc_val in [0, 1, 1.01]:
=======
    "American Samoa": "AS",
    "Guam": "GU",
    "Northern Mariana Islands": "MP",
    "Puerto Rico": "PR",
    "United States Minor Outlying Islands": "UM",
    "U.S. Virgin Islands": "VI",
}

state_names = {key for key, value in state_to_code_dict.items()}

import os
import json

FINAL_TIME=1100

vgpath = "C:/Program Files (x86)/Vengine2/Vensim - vengine.exe"
log = "log.txt"

variant_list = ["Delta", 'Omicron', "BA5"]
vax_status_list = ['Vx', 'NVx']

param_lst =[] #['Sensitivity to Weather']

for name in variant_list:
    param_lst.append(f'Variant Accuity Multiplier[{name}]')
for name in vax_status_list:
    param_lst.append(f'Immunity Loss Time[{name}]')
curr_param_list = []
for name in state_names:
    curr_param_list.append(f"Weight on Reported Probability of Infection[{name}]")
param_lst.append(curr_param_list)

param_lst_cf = list()

controlfilename = 'Control.txt' #input("Enter control file name (with extension):")
cf = json.load(open(controlfilename, 'r'))
# Unpack controlfile into variables
for k,v in cf.items():
    exec(k + '=v')


def calc_change_with_respect_to_pop(change):
    new=change
    new[0]=change[0]/change[3]
    new[1]=change[1]/change[3]
    new[2]=change[2]/change[3]
    for i in range(change.shape[0]-51, change.shape[0]):
        new[i-51*3]=change[i-51*3]/change[i]
        new[i-51*2]=change[i-51*2]/change[i]
        new[i-51*1]=change[i-51*1]/change[i]

def find_marginal_vax_eff(param_name, percent_change):
    full_output_df=pd.DataFrame()
    for VaxInc_val in [1, 1.01]:
>>>>>>> fb4fdedee8ae083cc8e85a6343b8ecd4d52c19de
        """
        with base parameter
        b1. calc the cost differece VaxInc: diff_cost_01, diff_cost_1_1dot1
        b2. calculate vaccinated people difference VaxInc: diff_ppl_01, diff_ppl_1_1dot1 
        b3. marginal cost: mc_01 = diff_cost_01 / diff_ppl_01, mc_1_1dot1 = diff_cost_1_1dot1/diff_ppl_1_1dot1
<<<<<<< HEAD
=======

>>>>>>> fb4fdedee8ae083cc8e85a6343b8ecd4d52c19de
        with 1.01 * base parameter
        c1. calc the cost differece VaxInc: diff_cost_01_c, diff_cost_1_1dot1_c
        c2. calculate vaccinated people difference VaxInc: diff_ppl_01_c, diff_ppl_1_1dot1_c
        c3. marginal cost: mc_01_c = diff_cost_01_c / diff_ppl_01_c, mc_1_1dot1_c = diff_cost_1_1dot1_c/diff_ppl_1_1dot1_c
<<<<<<< HEAD
        ela_01 = ((mc_01_c - mc_01) / mc_01) / 0.01
        ela_1_1dot1 = ((mc_1_1dot1_c - mc_1_1dot1) / mc_1_1dot1) / 0.01 #not doing this right now
        """
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
=======

        ela_01 = ((mc_01_c - mc_01) / mc_01) / 0.01
        ela_1_1dot1 = ((mc_1_1dot1_c - mc_1_1dot1) / mc_1_1dot1) / 0.01 #not doing this right now
        """
        try:
            param_base = vst_text.get_value("V79-OptimTest.out", param_name)
        except TypeError: #if we can't find param in optimization output, pull it out of model directly, should be done form mdl but is currently from .tab generated from vensim
            df = pandas.read_csv("test.tab", sep="\t", index_col=0) #raw values (all params outside .out, manually generated from .mdl/ can read from .mdl)
            print(df)

            param_base = df.loc[param_name][0]
        param_new_val = param_base * percent_change  # TODO: make this function with list param for rgn
        run = vst.Script(cf, f"param_{param_name.split()[0]}", log, setvals=[(param_name, param_new_val), ("VaxInc", VaxInc_val)], simtype='r')
        run.compile_script(vgpath, log, subdir="VAMA", check_funcs=[lambda a, b: True])
        output_df = pandas.read_csv(f"VAMA/Covidparam_{param_name.split()[0]}.csv")
        output_vals = output_df[output_df.columns[-1]]
>>>>>>> fb4fdedee8ae083cc8e85a6343b8ecd4d52c19de
        output_vals.rename(VaxInc_val, inplace=True)
        full_output_df = full_output_df.append(
            output_vals)
    return full_output_df.T
<<<<<<< HEAD
# baseline run, the name sensitivity to weather is chosen arbritraily
results=find_marginal_vax_eff(["Sensitivity to Weather"], 1) #dataframe
base_elas_diff=results[vax_inc_marg]-results[vax_inc_base]
base_elas_cost=calc_change_with_respect_to_pop(base_elas_diff)
base_avg_diff=results[vax_inc_base]-results[vax_inc_avg] # not df.iloc[1] but df.loc[1] as the col name is int (0,1,1.01)
base_avg_cost=calc_change_with_respect_to_pop(base_avg_diff)
pd.Series(base_elas_cost).to_csv("base_elas_cost.csv", sep="\t")
pd.Series(base_avg_cost).to_csv("base_avg_cost.csv", sep="\t")
elasticity_dict={}
avg_dict={}
for param in param_lst:
    print(param)
    results_param = find_marginal_vax_eff(param, 1.01)
    marg_diff = results_param[vax_inc_marg] - results_param[vax_inc_base]
    avg_diff = results_param[vax_inc_base] - results_param[vax_inc_avg]
    param_elas_cost=calc_change_with_respect_to_pop(marg_diff)
    param_avg_cost=calc_change_with_respect_to_pop(avg_diff)
    elasticity_dict[param[0]]=((param_elas_cost-base_elas_cost)/base_elas_cost)/(vax_inc_marg-vax_inc_base)
    avg_dict[param[0]]= ((param_avg_cost - base_avg_cost) / base_avg_cost) / (vax_inc_base - vax_inc_avg)
    print(elasticity_dict[param[0]]) # giving nan bc of division by zero
    print(avg_dict[param[0]])
    filename = f"{param[0].replace(' ','_')}_ela.tsv"
    pd.Series(elasticity_dict[param[0]]).to_csv(filename, sep = "\t") # giving nan bc of division by zero
    filename = f"{param[0].replace(' ', '_')}_avg.tsv"
    pd.Series(avg_dict[param[0]]).to_csv(filename, sep = "\t")


=======

results=find_marginal_vax_eff("Sensitivity to Weather", 1)
base_diff=results[1.01]-results[1]
base_cost=calc_change_with_respect_to_pop(base_diff)

elasticity_dict={}

for param in param_lst:
    results = find_marginal_vax_eff(param, 1.01)
    param_diff = results[1.01] - results[1]
    param_cost=calc_change_with_respect_to_pop(base_diff)
    elasticity_dict[param]=((param_cost-base_cost)/base_cost)/(1.01-1)
    print(elasticity_dict[param])
>>>>>>> fb4fdedee8ae083cc8e85a6343b8ecd4d52c19de
