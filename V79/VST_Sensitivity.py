import pandas as pd

from VST.vst import vst_text, vst

import pandas


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
        """
        with base parameter
        b1. calc the cost differece VaxInc: diff_cost_01, diff_cost_1_1dot1
        b2. calculate vaccinated people difference VaxInc: diff_ppl_01, diff_ppl_1_1dot1 
        b3. marginal cost: mc_01 = diff_cost_01 / diff_ppl_01, mc_1_1dot1 = diff_cost_1_1dot1/diff_ppl_1_1dot1

        with 1.01 * base parameter
        c1. calc the cost differece VaxInc: diff_cost_01_c, diff_cost_1_1dot1_c
        c2. calculate vaccinated people difference VaxInc: diff_ppl_01_c, diff_ppl_1_1dot1_c
        c3. marginal cost: mc_01_c = diff_cost_01_c / diff_ppl_01_c, mc_1_1dot1_c = diff_cost_1_1dot1_c/diff_ppl_1_1dot1_c

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
        output_vals = output_df
        output_vals.rename(VaxInc_val, inplace=True)
        full_output_df = full_output_df.append(
            output_vals)
    return full_output_df.T

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
