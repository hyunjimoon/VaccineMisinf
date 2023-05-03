import numpy as np
import pandas as pd
from VST.vst import vst_text, vst
import pandas
import os
import json
import xarray as xr
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
    state_lst_1.append(f"Impact of Treatment on Fatality Rate[{name}]")
    state_lst_2.append(f"Base Fatality Rate for Unit Acuity[{name}]")
    state_lst_3.append(f"Reference Force of Infection[{name}]")
    state_lst_4.append(f"Strength of Adherence Fatigue[{name}]")
    state_lst_5.append(f"Variant Intro Start Time[{name}]")
    state_lst_6.append(f"Variant Intro Start Time2[{name}]")

param_lst_lst=[
    # state_lst_1,
    # state_lst_2,
    # state_lst_3,
    # state_lst_4,
    # state_lst_5,
    # state_lst_6,
    # ['Variant Impact on Immunity Loss Time[Omicron]'],
    # ['Variant Impact on Immunity Loss Time[Delta]'],
    # ['Variant Impact on Immunity Loss Time[BA5]'],
    # ['Extra Vaccine Impact on Responsiveness[Vx]'],
    # ['Extra Vaccine Impact on Responsiveness[NVx]'],
    # ['Extra Vaccine Impact on Responsiveness[Naive]'],
    # ['Immunity Loss Time[Vx]'],
    # ['Immunity Loss Time[NVx]'],
    # ['Immunity Loss Time[Naive]'],
    # ['Variant Accuity Multiplier[Omicron]'],
    # ['Variant Accuity Multiplier[Delta]'],
    # ['Variant Accuity Multiplier[BA5]'],
    # ['Variant Intro Start Time3'],
    # ['Variant Transmission Multiplier[Omicron]'],
    # ['Variant Transmission Multiplier[Delta]'],
    # ['Variant Transmission Multiplier[BA5]']
]
vax_inc_1dot1=1.01
vax_inc_base=1
vax_inc_zero=0
TIME_PERIODS=1071
x=pd.date_range(start = '10/15/2019', periods = TIME_PERIODS)
dv = {
    "coords": {
        'value': {"dims": ("value"), "data": ["marginal", "average", str(vax_inc_1dot1), str(vax_inc_base), str(vax_inc_zero)]},
        'component': {"dims": ("component"),  "data": ['death', 'gdp', 'hospitalization']},
        'params': {"dims": ("params"), "data": [param[0] for param in param_lst_lst]+["baseline"]},
        'space': {"dims" : ("space"), "data": state_names},
        'time': {"dims" : ("time"), "data": pd.date_range(start = '10/15/2019', periods = TIME_PERIODS)}
    },
    "dims": {"value", "component", "params"},
    "data_vars":{ #5+ 3
        'VV_1_pcstv': {"dims": ("params", "component", "space", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1,3,len(state_names), 5, TIME_PERIODS))},
        'VV_1_pctv': {"dims": ("params", "component", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1,3, 5, TIME_PERIODS))},
        'VV_1_ptv': {"dims": ("params", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 5, TIME_PERIODS))},

        'epsilon_ptv': {"dims": ("params", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 5, TIME_PERIODS))},
        'epsilon_pctv': {"dims": ("params", "component", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 3, 5, TIME_PERIODS))},
        'epsilon_pcstv': {"dims": ("params", "component", "space", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 3, len(state_names), 5, TIME_PERIODS))},
    },
   "attrs": {"title": "vaccine value disaggregated by parameter, time, space, component"}
    }
vds = xr.Dataset.from_dict(dv)

controlfilename = 'Control.txt' #input("Enter control file name (with extension):")
cf = json.load(open(controlfilename, 'r'))
# Unpack controlfile into variables
for k,v in cf.items():
    exec(k + '=v')

def calc_change_with_respect_to_pop(raw_values: pandas.DataFrame) -> pandas.DataFrame:
    values_normalized_by_pop=pandas.DataFrame()
    columns_to_adjust=[
        "Cost of Deaths Cumulative",
        "Cost of GDP Cumulative",
        "Cost of Hospitalizations Cumulative"
    ]
    population_column = "Vaccine Taking Population"
    locations = [f"[{state}]" for state in state_names]
    locations+=[" All"]
    for location in locations:
        for column in columns_to_adjust:
            values_normalized_by_pop[column+location]=raw_values[column+location]/raw_values[population_column+location]
    print(values_normalized_by_pop)
    return values_normalized_by_pop
def calc_param_impact_on_cost(param_name_list, percent_change, storage_xarr, use_vengine=False, param_name=None): #list of str or list of list (local variables), # real
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
    if not param_name:
        param_name=param_name_list[0]
    for VaxInc_val in [0, 1, 1.01]:
        if use_vengine:
            param_new_val_list=[]
            for item in param_name_list:
                try:
                    param_base = vst_text.get_value("V79-OptimTest.out", item)
                except TypeError: #if we can't find param in optimization output, pull it out of model directly, should be done form mdl but is currently from .tab generated from vensim
                    df = pandas.read_csv("test.tab", sep="\t", index_col=0) #raw values (all params outside .out, manually generated from .mdl/ can read from .mdl)
                    param_base=df.loc[item][0]
                param_new_val_list.append(param_base * percent_change)  # TODO: make this function with list param for rgn
            setval_lst = [("VaxInc", VaxInc_val)]+[(param_name, param_new_val) for param_name, param_new_val in zip(param_name_list, param_new_val_list)]
            run = vst.Script(cf, f"param_{param_name.split()[0]}", log, setvals=setval_lst, simtype='r')
            run.compile_script(vgpath, log, subdir="VAMA", check_funcs=[lambda a, b: True])
        param_vv = pandas.read_csv(f"VAMA/Covidparam_{param_name.split()[0]}.csv", index_col=0).T
        param_vv = calc_change_with_respect_to_pop(param_vv)

        storage_xarr["VV_1_pctv"].loc[{
            "params":param_name,
            "component": "death",
            "value": str(VaxInc_val)
        }] = param_vv["Cost of Deaths Cumulative All"].values.flatten()
        storage_xarr["VV_1_pctv"].loc[{
            "params":param_name,
            "component": "gdp",
            "value": str(VaxInc_val)
        }] = param_vv["Cost of GDP Cumulative All"].values.flatten()
        storage_xarr["VV_1_pctv"].loc[{
            "params":param_name,
            "component": "hospitalization",
            "value": str(VaxInc_val)
        }] = param_vv["Cost of Hospitalizations Cumulative All"].values.flatten()
        for state in state_names:
            storage_xarr["VV_1_pcstv"].loc[{
                "params":param_name,
                "component": "death",
                "value": str(VaxInc_val),
                "space": state
            }] = param_vv[f"Cost of Deaths Cumulative[{state}]"].values.flatten()
            storage_xarr["VV_1_pcstv"].loc[{
                "params":param_name,
                "component": "gdp",
                "value": str(VaxInc_val),
                "space": state
            }] = param_vv[f"Cost of GDP Cumulative[{state}]"].values.flatten()
            storage_xarr["VV_1_pcstv"].loc[{
                "params":param_name,
                "component": "hospitalization",
                "value": str(VaxInc_val),
                "space": state
            }] = param_vv[f"Cost of Hospitalizations Cumulative[{state}]"].values.flatten()

    storage_xarr["VV_1_pcstv"].loc[{
        "value": "average"
    }] = storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_base)
    }] - storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_zero)
    }]
    
    storage_xarr["VV_1_pcstv"].loc[{
        "value": "marginal"
    }] = storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_1dot1)
    }] - storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_base)
    }]

    storage_xarr["VV_1_pstv"] = storage_xarr["VV_1_pcstv"].sum(dim="component")
    storage_xarr["VV_1_ptv"] = storage_xarr["VV_1_pctv"].sum(dim="component")
# baseline run, the name sensitivity to weather is chosen arbritraily
results=calc_param_impact_on_cost(["Sensitivity to Weather"], 1, vds, use_vengine=False, param_name="baseline") # baseline
for param_lst in param_lst_lst:
    print(param_lst)
    calc_param_impact_on_cost(param_lst, 1.01, vds, use_vengine=False)
    vds["epsilon_ptv"]=((vds["VV_1_ptv"].loc[{"params":param_lst[0]}]-vds["VV_1_ptv"].loc[{"params":"baseline"}])/vds["VV_1_ptv"].loc[{"params":"baseline"}])/0.01

print(vds)
vds.to_netcdf("data.nc")

import matplotlib.pyplot, matplotlib.dates

def plot_sensitivity(vds):
    matplotlib.pyplot.rcdefaults()
    #ax_marg = matplotlib.pyplot.subplot()
    # fig, axes = matplotlib.pyplot.subplots(2, sharex=True)
    fig, axes = matplotlib.pyplot.subplots(1, sharex=True)
    axes.plot(vds.time, vds['VV_1_pctv'].loc[{"value":"marginal","params":"baseline","component":"death"}])
    axes.plot(vds.time, vds['VV_1_pctv'].loc[{"value":"marginal","params":"baseline","component":"gdp"}])
    axes.plot(vds.time, vds['VV_1_pctv'].loc[{"value":"marginal","params":"baseline","component":"hospitalization"}])
    axes.set_title('Marginal Vaccine Value')
    # axes[1].plot(vds.time, vds['VV_1_pctv'].loc[{"value":"average","params":"baseline"}])
    # axes[1].plot(vds.time, vds['VV_1_pctv'].loc[{"value":"average","params":"baseline"}])
    # axes[1].plot(vds.time, vds['VV_1_pctv'].loc[{"value":"average","params":"baseline"}])
    # axes[1].set_title('Average Vaccine Value')
    fig.suptitle('Vaccine Value Over Time')
    fig.legend(vds.component.values)
    matplotlib.pyplot.gcf().autofmt_xdate()
    matplotlib.pyplot.show()

plot_sensitivity(vds)
