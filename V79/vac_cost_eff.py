import numpy as np
import pandas as pd
#from VST.vst import vst_text, vst
import matplotlib.pyplot, matplotlib.dates
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

param_lst_lst=[ # for testing parameter sensitivity, uncomment
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
vv_param_names=['Variant Impact on Immunity Loss Time[Omicron]',
 'Variant Impact on Immunity Loss Time[Delta]',
 'Variant Impact on Immunity Loss Time[BA5]',
 'Impact of Treatment on Fatality Rate',
 'Base Fatality Rate for Unit Acuity',
 'Reference Force of Infection',
 'Strength of Adherence Fatigue',
 'Variant Intro Start Time',
 'Variant Intro Start Time2',
 'Extra Vaccine Impact on Responsiveness[Vx]',
 'Extra Vaccine Impact on Responsiveness[NVx]',
 'Extra Vaccine Impact on Responsiveness[Naive]',
 'Immunity Loss Time[Vx]',
 'Immunity Loss Time[NVx]',
 'Immunity Loss Time[Naive]',
 'Variant Accuity Multiplier[Omicron]',
 'Variant Accuity Multiplier[Delta]',
 'Variant Accuity Multiplier[BA5]',
 'Variant Intro Start Time3',
 'Variant Transmission Multiplier[Omicron]',
 'Variant Transmission Multiplier[Delta]',
 'Variant Transmission Multiplier[BA5]']
vax_inc_1dot1=1.01
vax_inc_base=1
vax_inc_zero=0
TIME_PERIODS=1071
x=pd.date_range(start = '10/15/2019', periods = TIME_PERIODS)

## 1. Define xarray structure to store elasticity
# xarray is a labeled multidimensional data structure with `dims`,`coords` (value of `dims`), `data_vars`. 
# Greatest benefit for spatio-temportal sensitivity using this structure is a function `.sum()`. 
# With this command exemplified below, we can add along specificed axis (e.g. `component` (death, gdp, hospitalization), `space` (51 states)). 
dv = {
    "coords": {
        'value': {"dims": ("value"), "data": ["marginal", "average", str(vax_inc_1dot1), str(vax_inc_base), str(vax_inc_zero)]},
        'component': {"dims": ("component"),  "data": ['death', 'gdp', 'hospitalization', 'population']},
        'params': {"dims": ("params"), "data": [param[0] for param in param_lst_lst]+["baseline"]},
        'space': {"dims" : ("space"), "data": state_names},
        'time': {"dims" : ("time"), "data": pd.date_range(start = '10/15/2019', periods = TIME_PERIODS)},
        'shift': {"dims" : ("shift"), "data": list(range(-50, 60, 10))}
    },
    "dims": {"value", "component", "params"},
    "data_vars":{ #5+ 3
        'VV_1_pcstv': {"dims": ("params", "component", "space", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1,4,len(state_names), 5, TIME_PERIODS))},
        'VV_1_pctv': {"dims": ("params", "component", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1,4, 5, TIME_PERIODS))},
        'VV_1_ptv': {"dims": ("params", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 5, TIME_PERIODS))},
        'VV_1_csth': {"dims": ("component", "space", "time", "shift"), "data": np.zeros(shape = (4, len(state_names), TIME_PERIODS, 11))},
        'VV_1_cth': {"dims": ("component", "time", "shift"), "data": np.zeros(shape = (4, TIME_PERIODS, 11))},
        'VV_1_th': {"dims": ("time", "shift"), "data": np.zeros(shape = (TIME_PERIODS, 11))},

        'epsilon_ptv': {"dims": ("params", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 5, TIME_PERIODS))},
        'epsilon_pctv': {"dims": ("params", "component", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 4, 5, TIME_PERIODS))},
        'epsilon_pcstv': {"dims": ("params", "component", "space", "value", "time"), "data": np.zeros(shape = (len(param_lst_lst)+1, 4, len(state_names), 5, TIME_PERIODS))},
    },
   "attrs": {"title": "vaccine value disaggregated by parameter, time, space, component"}
    }
vds = xr.Dataset.from_dict(dv)

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
    return values_normalized_by_pop

def valid_by_p_csv2nc():
    dv = {
    "coords": {
        'value': {"dims": ("value"), "data": ["marginal", "average"]},
        'component': {"dims": ("component"),  "data": ['death', 'gdp', 'hospitalization']},
        'params': {"dims": ("params"), "data": [param for param in vv_param_names]},
        'space': {"dims" : ("space"), "data": state_names}
    },
    "dims": {"value", "component", "params"},
    "data_vars":{ #5+ 3
        'VV_csv': {"dims": ("component","space", "value"), "data": np.zeros(shape = (3, len(state_names), 2))},
        'VV_cv': {"dims": ("component", "value"), "data": np.zeros(shape = (3, 2))},
        'VV_sv': {"dims": ("space", "value"), "data": np.zeros(shape = (len(state_names), 2))},
        'VV_v': {"dims": ("value"), "data": np.zeros(shape = (2))},

        'VV_1_pcsv': {"dims": ("params", "component", "space", "value"), "data": np.zeros(shape = (len(vv_param_names),3,len(state_names), 2))},
        'VV_1_pcv': {"dims": ("params", "component", "value"), "data": np.zeros(shape = (len(vv_param_names),3, 2))},
        'VV_1_pv': {"dims": ("params", "value"), "data": np.zeros(shape = (len(vv_param_names), 2))},

        'epsilon_pv': {"dims": ("params", "value"), "data": np.zeros(shape = (len(vv_param_names), 2))},
        'epsilon_pcv': {"dims": ("params", "component", "value"), "data": np.zeros(shape = (len(vv_param_names), 3, 2))},
    },
   "attrs": {"title": "vaccine value disaggregated by parameter, time, space, component"}
    }
    vds = xr.Dataset.from_dict(dv)

    #51 states * 4 (efficacy of  death, gdp, health, population)
    # row 0, 4-54 (csv's 6-56) -> 1 set, death
    # row 1,55 -105 (csv's 57-107)-> 2 set, gdp
    # row 2, 106-156(csv's 108-158) -> 3 set, hosp

    # BASELINE HAPPENS ONCE
    avg = pd.read_csv("avg_cost_per_person_base.tsv", sep="\t", index_col=0)
    marg = pd.read_csv("marg_cost_per_person_base.tsv", sep="\t", index_col=0)
    vds['VV_csv'].loc[dict(component = 'death', value = 'average')] = avg.loc[4:54].values.flatten()
    vds['VV_csv'].loc[dict(component = 'gdp', value = 'average')] = avg.loc[55:105].values.flatten()
    vds['VV_csv'].loc[dict(component = 'hospitalization',value= 'average')] = avg.loc[106:156].values.flatten()

    vds['VV_csv'].loc[dict(component = 'death', value = 'marginal')] = marg.loc[4:54].values.flatten()
    vds['VV_csv'].loc[dict(component = 'gdp', value = 'marginal')] = marg.loc[55:105].values.flatten()
    vds['VV_csv'].loc[dict(component ='hospitalization', value ='marginal')] = marg.loc[106:156].values.flatten()


    vds['VV_cv'].loc[dict(component = 'death', value = 'average')] = avg.loc[0].values.item()
    vds['VV_cv'].loc[dict(component = 'gdp', value = 'average')] = avg.loc[1].values.item()
    vds['VV_cv'].loc[dict(component = 'hospitalization',value= 'average')] = avg.loc[2].values.item()

    vds['VV_cv'].loc[dict(component = 'death', value = 'marginal')] = marg.loc[0].values.item()
    vds['VV_cv'].loc[dict(component = 'gdp', value = 'marginal')] = marg.loc[1].values.item()
    vds['VV_cv'].loc[dict(component ='hospitalization', value ='marginal')] = marg.loc[2].values.item()

    vds['VV_sv'] = vds['VV_csv'].sum(dim = 'component')
    vds['VV_v'] = vds['VV_cv'].sum(dim = 'component')

    # COUNTERFACTUAL HAPPENS 22 times
    for file_param, param in zip(vv_param_names, vv_param_names):
        file = file_param.replace(" ", "_")
        avg=pd.read_csv(file +'_avg.tsv', sep='\t', index_col=0)
        marg=pd.read_csv(file+'_marg.tsv', sep='\t', index_col=0)

        vds['VV_1_pcsv'].loc[dict(params = param, component = 'death', value='average')] = avg.loc[4:54].values.flatten()
        vds['VV_1_pcsv'].loc[dict(params = param,component = 'gdp', value='average')] = avg.loc[55:105].values.flatten()
        vds['VV_1_pcsv'].loc[dict(params = param,component = 'hospitalization', value='average')] = avg.loc[106:156].values.flatten()

        vds['VV_1_pcsv'].loc[dict(params = param, component = 'death', value='marginal')] = marg.loc[4:54].values.flatten()
        vds['VV_1_pcsv'].loc[dict(params = param,component = 'gdp', value='marginal')] = marg.loc[55:105].values.flatten()
        vds['VV_1_pcsv'].loc[dict(params = param,component = 'hospitalization', value='marginal')] = marg.loc[106:156].values.flatten()

        vds['VV_1_pcv'].loc[dict(params = param, component = 'death', value='average')] = avg.loc[0].values.item()
        vds['VV_1_pcv'].loc[dict(params = param,component = 'gdp', value='average')] = avg.loc[1].values.item()
        vds['VV_1_pcv'].loc[dict(params = param,component = 'hospitalization', value='average')] = avg.loc[2].values.item()

        vds['VV_1_pcv'].loc[dict(params = param, component = 'death', value='marginal')] = marg.loc[0].values.item()
        vds['VV_1_pcv'].loc[dict(params = param,component = 'gdp', value='marginal')] = marg.loc[1].values.item()
        vds['VV_1_pcv'].loc[dict(params = param,component = 'hospitalization', value='marginal')] = marg.loc[2].values.item()

        vds['VV_1_pv'] = vds['VV_1_pcv'].sum(dim = 'component')
    return vds
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
        print(os.getcwd())
        param_vv = pandas.read_csv(f"nc_data/Covidparam_{param_name.split()[0]}_{VaxInc_val}.csv", index_col=0).T
        # param_vv = calc_change_with_respect_to_pop(param_vv)

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
        storage_xarr["VV_1_pctv"].loc[{
            "params":param_name,
            "component": "population",
            "value": str(VaxInc_val)
        }] = param_vv["Vaccine Taking Population All"].values.flatten()
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
                "params":param_name,
                "component": "population",
                "value": str(VaxInc_val),
                "space": state
            }] = param_vv[f"Vaccine Taking Population[{state}]"].values.flatten()

    storage_xarr["VV_1_pcstv"].loc[{
        "value": "average"
    }] = (storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_base)
    }] - storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_zero)
    }])/(storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_base),
        "component": "population"
    }] - storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_zero),
        "component": "population"
    }])
    
    storage_xarr["VV_1_pcstv"].loc[{
        "value": "marginal"
    }] = (storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_1dot1)
    }] - storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_base)
    }])/(storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_1dot1),
        "component": "population"
    }] - storage_xarr["VV_1_pcstv"].loc[{
        "value": str(vax_inc_base),
        "component": "population"
    }])

    storage_xarr["VV_1_pstv"] = storage_xarr["VV_1_pcstv"].sum(dim="component")
    storage_xarr["VV_1_ptv"] = storage_xarr["VV_1_pctv"].sum(dim="component")
# baseline run, the name sensitivity to weather is chosen arbritraily

results=calc_param_impact_on_cost(["Sensitivity to Weather"], 1, vds, use_vengine=False, param_name="baseline") # baseline
for param_lst in param_lst_lst:
    print(param_lst)
    calc_param_impact_on_cost(param_lst, 1.01, vds, use_vengine=False)
    vds["epsilon_ptv"]=((vds["VV_1_ptv"].loc[{"params":param_lst[0]}]-vds["VV_1_ptv"].loc[{"params":"baseline"}])/vds["VV_1_ptv"].loc[{"params":"baseline"}])/0.01

vds.to_netcdf("nc_data/vv_cstv2.nc")

def plot_sensitivity(vds):
    matplotlib.pyplot.rcdefaults()
    fig_avg, ax_avg = matplotlib.pyplot.subplots()
    fig_marg, ax_marg = matplotlib.pyplot.subplots()

    x_avg=[avg for marg, avg in vds['VV_1_pv'].values]
    x_marg=[marg for marg, avg in vds['VV_1_pv'].values]
    x_label=[val for val in vds.params.values]
    y_vars=[x for x in range(len(vds['VV_1_pv']))]
    x_avg_sorted=[]
    x_marg_sorted=[]
    x_label_sorted=[]
    for avg, marg, label in sorted(zip(x_avg, x_marg, x_label)):
        x_avg_sorted.append(avg)
        x_marg_sorted.append(marg)
        x_label_sorted.append(label)

    ax_avg.barh(x_label_sorted, x_avg_sorted, align='center')
    ax_avg.set_yticks(y_vars)
    ax_avg.invert_yaxis()  # labels read top-to-bottom
    ax_avg.set_xlabel('Average Vaccine Cost Efficacy')
    ax_avg.set_title('Elasticity of Average Vaccine Cost Efficacy')

    ax_marg.barh(x_label_sorted, x_marg_sorted, align='center')
    ax_marg.set_yticks(y_vars)
    ax_marg.invert_yaxis()  # labels read top-to-bottom
    ax_marg.set_xlabel('Marginal Vaccine Cost Efficacy')
    ax_marg.set_title('Elasticity of Marginal Vaccine Cost Efficacy')

    matplotlib.pyplot.show()
    return

#plot_sensitivity(vds)

def convert_timeshift_csv_to_nc(base_filename):
    suffix_list = ["n50", "n40", "n30", "n20", "n10", "0", "p10", "p20", "p30", "p40", "p50"]
    for suffix, offset in zip(suffix_list, range(-50, 60, 10)):
        df = pandas.read_csv(base_filename+"_"+suffix+".csv",header=None)
        df.set_index(keys=[0, 1], inplace=True)
        df.rename(columns={num: date for num, date in zip(df.columns, x)}, inplace=True)
        df.index.names=["Component", "Space"]
        df_state = df.loc[(["Cost of Deaths Cumulative", "Cost of GDP Cumulative", "Cost of Hospitalizations Cumulative"]),]
        df_state.rename(index={"Cost of Deaths Cumulative": "death", "Cost of GDP Cumulative": "gdp", "Cost of Hospitalizations Cumulative": "hospitalization"}, inplace=True)
        df_all= df.loc[(["Cost of Deaths Cumulative All", "Cost of GDP Cumulative All", "Cost of Hospitalizations Cumulative All"]),]
        df_all.rename(index={"Cost of Deaths Cumulative All": "death", "Cost of GDP Cumulative All": "gdp", "Cost of Hospitalizations Cumulative All": "hospitalization"}, inplace=True)
        df_all.index=df_all.index.droplevel(level=1)
        vds["VV_1_csth"].loc[{"shift": offset}] = df_state.unstack(level=1).T.reorder_levels(order=[1,0]).to_xarray().to_array()
        vds["VV_1_cth"].loc[{"shift": offset}] = df_all.unstack(level=1).T.reorder_levels(order=[1,0]).to_xarray()
    vds["VV_1_th"] = vds["VV_1_cth"].sum(dim="component")
    

# convert_timeshift_csv_to_nc("/Users/hyunjimoon/Dropbox (MIT)/WINcode/VaccineMisinf/nc_data/timeshift/timeshift")

# vds.to_netcdf("nc_data/vv_cstv_timeshift.nc")

def plot_timeshift_sens():
    matplotlib.pyplot.rcdefaults()
    death_vals = np.divide(vds["VV_1_cth"].loc[{"time": x[-1], "component": "death"}].values, 10**12)
    death_vals = np.subtract(death_vals, vds["VV_1_cth"].loc[{"time": x[-1], "component": "death", "shift": 0}].values.tolist()/10**12)
    gdp_vals = np.divide(vds["VV_1_cth"].loc[{"time": x[-1], "component": "gdp"}].values, 10**12)
    gdp_vals = np.subtract(gdp_vals, vds["VV_1_cth"].loc[{"time": x[-1], "component": "gdp", "shift": 0}].values.tolist()/10**12)
    hosp_vals = np.divide(vds["VV_1_cth"].loc[{"time": x[-1], "component": "hospitalization"}].values, 10**12)
    hosp_vals = np.subtract(hosp_vals, vds["VV_1_cth"].loc[{"time": x[-1], "component": "hospitalization", "shift": 0}].values.tolist()/10**12)
    plot_d = matplotlib.pyplot.bar(vds.coords["shift"].values, death_vals, width=2)
    plot_d.set_label("Deaths")
    plot_g = matplotlib.pyplot.bar(vds.coords["shift"].values, gdp_vals, bottom=death_vals, width=2)
    plot_g.set_label("GDP")
    plot_h = matplotlib.pyplot.bar(vds.coords["shift"].values, hosp_vals, bottom=death_vals+gdp_vals, width=2)
    plot_h.set_label("Hospitalization")
    matplotlib.pyplot.legend()
    matplotlib.pyplot.xlabel("Vaccine start time offset (days)")
    matplotlib.pyplot.ylabel("Total vaccine value (Trillion USD)")
    matplotlib.pyplot.axhline(y=0, color='k', linestyle='-')
    matplotlib.pyplot.show()

# plot_timeshift_sens()
def plot_by_st_vv():
    '''
    analysis for vaccine value disseminated to all previous periods was tricky so replaced with `plot_timeshift_sens`
    '''
    bigstate = ["New York", "California", "Massachusetts", "Texas"]
    fig, axes = plt.subplots(1, 4, figsize = (30,10))
    for i, space in enumerate(bigstate):
        vv_xr["VV_1_pcstv"].loc[{"value": "marginal", "params": "baseline", "space": f'{space}'}].plot.line(ax = axes[i], x="time")
        plt.title("Vaccination Value Over Time")
        axes[i].set_ylabel("Marginal Value of Vaccine (USD $)")
        axes[i].axes.set_xlabel(f"{space}")
    fig.tight_layout(pad=0.5)

def plot_by_c_vv_timeshift_sens():
    import matplotlib.pyplot as plt
    vv_xr = xr.open_dataset("nc_data/vv_cstv2.nc")
    plottable=vv_xr.drop_sel(space="District of Columbia").sortby("space")
    plt.figure(figsize=(12, 10))  # width:10, height:8
    death_zip = list(zip(plottable["space"].values,
        -plottable["VV_1_pcstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1], "component": "death"}
            ].values,
        plottable["VV_1_pstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1]}
            ].values
    ))
    death_zip.sort(key = lambda x: x[2], reverse=True)
    death_lab, death_val, _ = zip(*death_zip)
    death = plt.barh(
            death_lab,
            death_val,
        )
    death.set_label("Deaths")
    gdp_zip = list(zip(plottable["space"].values,
        -plottable["VV_1_pcstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1], "component": "gdp"}
            ].values,
        plottable["VV_1_pstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1]}
            ].values
    ))
    gdp_zip.sort(key = lambda x: x[2], reverse=True)
    gdp_lab, gdp_val, _ = zip(*gdp_zip)
    gdp = plt.barh(
            gdp_lab,
            gdp_val,
            left=death_val
        )
    hosp_zip = list(zip(plottable["space"].values,
        -plottable["VV_1_pcstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1], "component": "hospitalization"}
            ].values,
        plottable["VV_1_pstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1]}
            ].values
    ))
    hosp_zip.sort(key = lambda x: x[2], reverse=True)
    hosp_lab, hosp_val, _ = zip(*hosp_zip)
    hosp = plt.barh(
            hosp_lab,
            hosp_val,
            left=[d+g for d, g in zip(death_val, gdp_val)]
        )
    hosp.set_label("Hospitalization")
    gdp.set_label("GDP")
    plt.title("Per State Marginal Vaccine Value")
    plt.legend()
    plt.xlabel("Marginal Vaccine Value ($)")
    plt.ylabel("State")
    plottable["VV_1_pstv"].loc[
                {"value": "marginal", "params": "baseline", "time": vv_xr["time"][-1], "space": "Alabama"}
            ].values
    plt.show()

plot_by_c_vv_timeshift_sens()