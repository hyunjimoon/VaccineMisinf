import numpy as np
import pandas as pd
#import VST
import matplotlib.pyplot, matplotlib.dates
from matplotlib import pyplot as plt
import os
import xarray as xr

def gen_param_names():
# spatial subscript
    states = ['Alabama', 'Alaska', 'Arizona', 'Arkansas', 'California', 'Colorado', 'Connecticut', 'Delaware',
                   'Florida', 'Georgia', 'Hawaii', 'Idaho', 'Illinois', 'Indiana', 'Iowa', 'Kansas', 'Kentucky',
                   'Louisiana', 'Maine', 'Maryland', 'Massachusetts', 'Michigan', 'Minnesota', 'Mississippi', 'Missouri',
                   'Montana', 'Nebraska', 'Nevada', 'New Hampshire', 'New Jersey', 'New Mexico', 'New York',
                   'North Carolina', 'North Dakota', 'Ohio', 'Oklahoma', 'Oregon', 'Pennsylvania', 'Rhode Island',
                   'South Carolina', 'South Dakota', 'Tennessee', 'Texas', 'Utah', 'Vermont', 'Virginia', 'Washington',
                   'West Virginia', 'Wisconsin', 'Wyoming', 'District of Columbia']
    variant_list = ["Delta", 'Omicron', "BA5"]
    vax_status_list = ['Vx', 'NVx']
    param_lst = []
    state_lst_1 = []
    state_lst_2 = []
    state_lst_3 = []
    state_lst_4 = []
    state_lst_5 = []
    state_lst_6 = []
    for name in states:
        state_lst_1.append(f"Impact of Treatment on Fatality Rate[{name}]")
        state_lst_2.append(f"Base Fatality Rate for Unit Acuity[{name}]")
        state_lst_3.append(f"Reference Force of Infection[{name}]")
        state_lst_4.append(f"Strength of Adherence Fatigue[{name}]")
        state_lst_5.append(f"Variant Intro Start Time[{name}]")
        state_lst_6.append(f"Variant Intro Start Time2[{name}]")
    t_sharing_params =  [
            state_lst_1,
            state_lst_2,
            state_lst_3,
            state_lst_4,
            state_lst_5,
            state_lst_6,
        ]
    t_sharing_sbatched_params = [param[0].replace("[Alabama]", "") for param in t_sharing_params]
    ts_sharing_params = ['Variant Impact on Immunity Loss Time[Omicron]',
                         'Variant Impact on Immunity Loss Time[Delta]',
                         'Variant Impact on Immunity Loss Time[BA5]',
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
    return states, t_sharing_sbatched_params, ts_sharing_params

def create_f123x1_pcsth12(vax_amt_lst, vax_time_lst):
    # x
    x1 = ["cost"]
    x2 = ["population"]

    # function
    f1x = ["mvv", "avv", "mvp", "avp"] #better if functional form
    f2x = ["mvvpp", "avvpp"]
    f3x = ["mvvpp_sens", "avvpp_sens"] 
    f4x = ["mvvpp_dt", "avvpp_dt"]

    # param
    t_sharing_sbatched_params, ts_sharing_params  = gen_param_names()[1:]
    param_lst = t_sharing_sbatched_params + ts_sharing_params + ["baseline"]

    # component_time_vec
    costcomp_tv = ['death', 'gdp', 'hospitalization']
    noncost_tv = ['population']
    # space
    states  = gen_param_names()[0]

    # time
    time = pd.date_range(start='10/15/2019', periods=1071)

    dv = {
        "dims": {"x1", "x2", "f1x", "f2x","f3x", "param", "costcomp_tv", "noncost_tv", "space", "time", "h1", "h2"}, #action as hparam
        "coords": { #pcstvh
            'x1': {"dims": ("x1"), "data": x1}, #COST ($) TODO: if I use ["cost"], should i change x1_pcsth1 as "x1" or "cost"?
            'x2': {"dims": ("x2"), "data": x2}, #POPULATION (person)
            # f1(x1), f1(x2), f2(x1x2), f3(x1x2)
            'f1x': {"dims": ("f1x"), "data": f1x}, #MARGINAL AVERAGE VACCINE VALUE, MARGINAL AVERAGE VACCINE TAKING POP
            'f2x': {"dims": ("f2x"), "data": f2x}, #MARGINAL AVERAGE VACCINE VALUE PER PERSON ($/person)
            'f3x': {"dims": ("f3x"), "data": f3x}, #MARGINAL AVERAGE VACCINE VALUE PER PERSON w.r.t. PARAMETER ($/person/punit)
            'f4x': {"dims": ("f4x"), "data": f4x}, #MARGINAL AVERAGE VACCINE VALUE PER PERSON w.r.t. PARAMETER ($/person/punit)

            'param': {"dims": ("param"), "data": param_lst},

            'costcomp_tv': {"dims": ("costcomp_tv"), "data": costcomp_tv},
            'noncost_tv': {"dims": ("noncost_tv"), "data": noncost_tv},

            'space': {"dims": ("space"), "data": states},
            'time': {"dims": ("time"), "data": time},
            "h1": {"dims": ("h1"), "data": [str(va) for va in vax_amt_lst]},
            "h2": {"dims": ("h2"), "data": [str(vt) for vt in vax_time_lst]}
        },
        "data_vars": {  # 5+3 three vdot_ coordinate is only needed for data variables with 'p' coordinate
            "x1_pcsth1": {"dims": ("x1", "param", "costcomp_tv", "space", "time", "h1"), "data": np.zeros(shape=(len(x1), len(param_lst), len(costcomp_tv), len(states), len(time), len(vax_amt_lst)))}, # vaccine value for each component, space, time, for vaxinc 0, 1, 1.01
            "x2_pnsth1": {"dims": ("x2", "param", "noncost_tv", "space", "time", "h1"), "data": np.zeros(shape=(len(x2), len(param_lst), len(noncost_tv), len(states), len(time), len(vax_amt_lst)))},
            "x1_csth2": {"dims": ("x1","costcomp_tv", "space", "time", "h2"), "data": np.zeros(shape=(len(x1),len(costcomp_tv), len(states),len(time), len(vax_time_lst)))},
            "x1_cth2": {"dims": ("x1","costcomp_tv", "time", "h2"), "data": np.zeros(shape=(len(x1),len(costcomp_tv), len(time), len(vax_time_lst)))},
            #add_center
            "f1x_pcst": {"dims": ("f1x", "param", "costcomp_tv", "space", "time"), "data": np.zeros(shape=(len(f1x), len(param_lst), len(costcomp_tv),  len(states), len(time)))}, #marginal average vv (delta cost)
            "f1x_pnst": {"dims": ("f1x", "param", "noncost_tv", "space", "time"), "data": np.zeros(shape=(len(f1x), len(param_lst), len(noncost_tv),  len(states), len(time)))}, #marginal average vp (delta person)
            #multi_center
            "f2x_pcst": {"dims": ("f2x", "param", "costcomp_tv", "space", "time"), "data": np.zeros(shape=(len(f2x), len(param_lst), len(costcomp_tv),  len(states), len(time)))}, #marginal average vaccine value per person (cost/person)
            #sens
            "f3x_pcst": {"dims": ("f3x", "param", "costcomp_tv", "space", "time",), "data": np.zeros(shape=(len(f3x), len(param_lst), len(costcomp_tv),  len(states), len(time)))}, #marginal vaccine value per person w.r.t. parameter (cost/person/param)
        },
        "attrs": {"title": "1.vaccine value disaggregated by parameter, time, space, component, 2.counterfactual by parameter for validity, 3.counterfactual by datahp for summary stat."}
        # 1 and 2 are descriptive, 3 is prescriptive
    }
    vv = xr.Dataset.from_dict(dv)
    return vv

def add_center(obj, ref):
    """
    additive centering for obj-ref (mean zero centering)
    """
    return np.subtract(obj, ref)

def multi_center(obj, ref):
    """
    multiplicative centering for obj/ref (mean one centering)
    """
    return np.divide(obj, ref)

def tf112345_vgcsv2xr(vax_amt_lst, vax_time_lst, param_lst, param_multiplier, vv, use_vengine = False) -> xr.Dataset:
    def f1234x_pcst_h1(param, vax_amt, vv):
        df = pd.read_csv(f"V79/CSV/Covidparam_{param}_{vax_amt}.csv", index_col=0).T
        vi_r2s = {1.01:'1.01', 1:'1', 0:'0',}

        # INPUT FROM CSV
        for state in gen_param_names()[0]:
            vv["x1_pcsth1"].loc[{"param": param,"costcomp_tv": "death", "space": state, "h1": vi_r2s[vax_amt]}] = df[f"Cost of Deaths Cumulative[{state}]"].values.flatten()
            vv["x1_pcsth1"].loc[{"param": param,"costcomp_tv": "gdp", "space": state, "h1": vi_r2s[vax_amt]}] = df[f"Cost of GDP Cumulative[{state}]"].values.flatten()
            vv["x1_pcsth1"].loc[{"param": param,"costcomp_tv": "hospitalization", "space": state, "h1": vi_r2s[vax_amt]}] = df[f"Cost of Hospitalizations Cumulative[{state}]"].values.flatten()

            vv["x2_pnsth1"].loc[{"param": param, "noncost_tv": "population", "space": state, "h1": vi_r2s[vax_amt]}] = df[f"Vaccine Taking Population[{state}]"].values.flatten()

        ####### SPACE, COSTCOMP AGG
        vv["x1_pcth1"] = vv["x1_pcsth1"].sum(dim="space") #https://github.com/hyunjimoon/VaccineMisinf/issues/17
        vv["x2_pnth1"] = vv["x2_pnsth1"].sum(dim="space")

        vv['x1_psth1'] = vv["x1_pcsth1"].sum(dim='costcomp_tv')

        # X TO F1(X): MARGINAL AVERAGE VACCINE VALUE  +  VACCINE TAKING POP 
        vv["f1x_pcst"].loc[{"f1x": "mvv"}] = add_center(vv["x1_pcsth1"].sel(h1="1.01"), vv["x1_pcsth1"].sel(h1="1")).squeeze('x1')
        vv["f1x_pcst"].loc[{"f1x": "avv"}] = add_center(vv["x1_pcsth1"].sel(h1="1"), vv["x1_pcsth1"].sel(h1="0")).squeeze('x1')

        vv["f1x_pnst"].loc[{"f1x": "mvp"}] = add_center(vv["x2_pnsth1"].sel(h1="1.01"), vv["x2_pnsth1"].sel(h1="1")).squeeze('x2')    
        vv["f1x_pnst"].loc[{"f1x": "avp"}] = add_center(vv["x2_pnsth1"].sel(h1="1"), vv["x2_pnsth1"].sel(h1="0")).squeeze('x2')

        # F1(X) TO F2(X): MARGINAL AVERAGE VACCINE VALUE PER PERSON
        np.seterr(divide='ignore', invalid='ignore')
        vv["f2x_pcst"].loc[{"f2x": "mvvpp"}] = multi_center(vv["f1x_pcst"].sel(f1x= "mvv"), vv["f1x_pnst"].sel(f1x= "mvp")).squeeze('noncost_tv')
        vv["f2x_pcst"].loc[{"f2x": "avvpp"}] = multi_center(vv["f1x_pcst"].sel(f1x= "avv"), vv["f1x_pnst"].sel(f1x= "avp")).squeeze('noncost_tv')

        # F2(X) TO F3(X): MARGINAL AVERAGE VACCINE VALUE PER PERSON PER PARAMETER
        for param in param_lst:
            vv["f3x_pcst"].loc[{"f3x": "mvvpp_sens", 'param':param}] = multi_center(add_center(vv["f2x_pcst"].sel(f2x="mvvpp", param= f"{param}"), vv["f2x_pcst"].sel(f2x="mvvpp", param= "baseline")), 0.01)
            vv["f3x_pcst"].loc[{"f3x": "avvpp_sens", 'param':param}] = multi_center(add_center(vv["f2x_pcst"].sel(f2x="avvpp", param= f"{param}"), vv["f2x_pcst"].sel(f2x="avvpp", param= "baseline")), 0.01)

        # F2(X) TO F4(X): MARGINAL AVERAGE VACCINE VALUE PER PERSON PER PARAMETER PER DAY
        # for t in range(len(time)+1):
        #     vv["f4x_cst"].loc[{"f4x": "mvvpp_t"}] = add_center(vv["f2x_pcst"].sel(time= f"{t}", param="baseline"), vv["f2x_pcst"].sel(time= f"{t-1}", param="baseline")).squeeze('f2x')

        return vv
    
    def f5x_cst_h2(vax_time, vv):
        df = pd.read_csv(f"V79/CSV/timeshift_{vax_time}.csv", header=None)
        vt_r2s = {-50: "-50", -40: "-40", -30: "-30", -20:"-20", -10: "-10", 0:"0", 10:"10", 20: "20", 30:"30", 40:"40", 50:"50"} 
    
        df['var'] = df.iloc[:, 0] + "[" + df.iloc[:, 1] + "]"
        df.drop(columns=[0,1], inplace = True)
        df.set_index('var', inplace=True)
        df.rename(columns={num: date for num, date in zip(df.columns, time)}, inplace=True)

        for state in gen_param_names()[0]:
            vv["x1_csth2"].loc[{"costcomp_tv": "death", "space": state, "h2": vt_r2s[vax_time]}] = df.loc[f"Cost of Deaths Cumulative[{state}]", :].values.flatten()
            vv["x1_csth2"].loc[{"costcomp_tv": "gdp", "space": state, "h2": vt_r2s[vax_time]}] = df.loc[f"Cost of GDP Cumulative[{state}]", :].values.flatten()
            vv["x1_csth2"].loc[{"costcomp_tv": "hospitalization", "space": state, "h2": vt_r2s[vax_time]}] = df.loc[f"Cost of Hospitalizations Cumulative[{state}]", :].values.flatten()

        # X TO F5(X): TOTAL VACCINE VALUE 
        vv["f5x_cst"] = add_center(vv["x1_csth2"].sel(h2=f'{vax_time}'), vv["x1_csth2"].sel(h2="0")).squeeze('x1')
        return vv

    if use_vengine:
        cf={
            "basename": "Covid",
            "simcontrol": {
                "model": "CovidUSA-Econ-V81.mdl",
                "data": [
                    "CovidModelInputs - ConstantDataStates.vdf",
                    "CovidModelInputs - CRWStates.vdf",
                    "CovidModelInputs - DeathDataStates.vdf",
                    "CovidModelInputs - FlowDataStates.vdf",
                    "CovidModelInputs - FormattedDataStates.vdf",
                    "CovidModelInputs - TestDataStates.vdf",
                    "GDP_Vensim.vdfx"
                    ],
                "payoff": "",
                "sensitivity": "",
                "optparm": "",
                "changes": [],
                "savelist": "",
                "senssavelist": ""
                },
            "venginepath": vgpath,
            "runcmd": "",
            "savecmd": "VDF2CSV|!|!|SAVEFILE.lst|||",
            "timelimit": 600,
            "mccores": 0
        }
        for param in param_lst:
            param_new_val_list = []
            for vax_amt in vax_amt_lst:
                try:
                    param_base = vst_text.get_value(f'{posterior_out}', param)
                except TypeError:  # if we can't find param in optimization output, pull it out of model directly, should be done form mdl but is currently from .tab generated from vensim
                    param_base = vst_text.get_value(f'{datahp_mdl}', param)
                    # df = pd.read_csv(f"{test_file}", sep="\t", index_col=0)  # raw values (all params outside .out, manually generated from .mdl/ can read from .mdl)
                    # param_base = df.loc[param][0]
                param_new_val_list.append(param_base * param_multiplier)  # TODO: make this function with list param for rgn
            setval_lst = [("VaxInc", vax_amt)] + [(param_name, param_new_val) for param_name, param_new_val in zip(param_lst, param_new_val_list)]
            run = vst.Script(cf, f"param_{param_name}", log_file, setvals=setval_lst, simtype='r')
            run.compile_script(vgpath, log_file, subdir="VAMA", check_funcs=[lambda a, b: True])
            os.replace(f"VAMA/Covidparam_{param_name}.csv", f"CSV/Covidparam_{param_name}_{vax_amt}.csv")

        for vax_time in vax_time_lst:
            setval_lst = [("VaccinationShift", vax_time)]
            run = vst.Script(cf, f"vax_time_{vax_time}", log_file, setvals=setval_lst, simtype='r')
            run.compile_script(vgpath, log_file, subdir="VAMA", check_funcs=[lambda a, b: True])
            os.replace(f"VAMA/timeshift_{vax_time}.csv", f"CSV/timeshift_{vax_time}.csv")

    # VAX_AMT
    for param in param_lst:
        for vax_amt in vax_amt_lst:
            vv = f1234x_pcst_h1(param, vax_amt, vv)

    # VAX_TIME
    for vax_time in vax_time_lst:
        vv = f5x_cst_h2(vax_time, vv)
    
    return vv

def tf5_x_ctnt(vv):
    """
    validating calibration via comparing real and simulated (i.e. posterior retrodictive check)
    input: vv
    output: three timeseirs plots for `costcomp_tv` death and hospitalization (overall) + gdp (new york, california, texas)
    """
    #tf5_x_ctnt
    vv['x1_ct']=vv["x1_pcth1"].loc[{'param':'baseline', "h1": "1"}]
    vv['x2_nt']=vv["x2_pnth1"].loc[{'param':'baseline', "h1": "1"}]
    
    df=pd.read_csv("Sim_DataAgg.csv", index_col=[0,1]).transpose()
    df.columns.set_levels(['Sim', 'Data'], level = 0, inplace = True)
    df.set_index(pd.date_range(start = '10/15/2019', periods = 1071), inplace=True)
    df.columns.set_names(["sim_data", "component"], inplace=True)

    test_fit_dict = {
        "coords": {
            'sim_data': {"dims": ("sim_data"), "data": ["sim", "data"]},
            'component': {"dims": ("component"),  "data": ['infection', 'death', 'hospitalization']},
            'time': {"dims": ("time"), "data": df.index},
            #'space': {"dims" : ("space"), "data": states} didn't implement space disaggregation for sim_data comparison yet
        },
        "dims": {"sim_data", "component", "time"},
        "data_vars":{ # 3 * 2
            'population': {"dims": ("sim_data","component", "time"), "data": np.zeros(shape = (2, 3, len(df.index)))},
        },
       "attrs": {"title": "population of infected, died, tested for data and simulated (conditional on estimated parameter)"}
        }
    test_fit_xr = xr.Dataset.from_dict(test_fit_dict)
    fig, axes = plt.subplots(1, 3, figsize=(20, 10))

    for comp, ax in zip(test_fit_xr.component, axes):
        test_fit_xr.sel(dict(component = comp, sim_data='data'))['population'].plot.line(ax = ax, x = 'time', marker ='.', markersize = 6, add_legend = True)
        test_fit_xr.sel(dict(component = comp, sim_data='sim'))['population'].plot.line(ax = ax, x = 'time', add_legend = True)

    gdp_data=results.loc['Real World GDP Data (Gt)""']
    gdp_data.dropna(inplace=True, how="all", axis=1)
    gdp_data.index.rename(inplace=True, names=["state", "empty"])
    gdp_data=gdp_data.droplevel("empty")
    gdp_sim=results.loc["Reported Cumulated GDP"]
    gdp_sim.dropna(inplace=True, how="all", axis=1)
    gdp_sim.index.rename(inplace=True, names=["state", "empty"])
    gdp_sim=gdp_sim.droplevel("empty")
    gdp_full=gdp_data.loc[["California", "New York", "Texas"]]
    gdp_full.rename(index={
        "California":"California (Data)",
        "Texas":"Texas (Data)",
        "New York":"New York (Data)"
    },inplace=True)
    gdp_full=pd.concat([gdp_full, gdp_sim.loc[["California", "New York", "Texas"]]])
    gdp_full.columns = [datetime.timedelta(days=int(x)) + df.index[0] for x in gdp_full.columns]
    gdp_full.rename(index={
        "California":"California (Sim)",
        "Texas":"Texas (Sim)",
        "New York":"New York (Sim)"
    },inplace=True)

    ax = (gdp_full * 10**6/10**12).T.plot()

    ax.yaxis.set_major_formatter('${x:1.2} T')
    plt.show()
    return

def tf6_f2x_cs(vv):
    """
    marginal vaccine value for each state
    """
    vv['f2x_cs'] = vv['f2x_pcst'].loc[{'param':'baseline', 'time':time[-1]}]

    plottable=vv.drop_sel(space="District of Columbia").sortby("space")
    plt.figure(figsize=(12, 10))  # width:10, height:8
    death_zip = list(zip(plottable["space"].values,
        -plottable["f1_pcst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1], "costcomp_tv": "death"}
            ].values,
        plottable["f_pst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1]}
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
        -plottable["f_pcst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1], "costcomp_tv": "gdp"}
            ].values,
        plottable["f_pst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1]}
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
        -plottable["f_pcst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1], "costcomp_tv": "hospitalization"}
            ].values,
        plottable["f1x_pst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1]}
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
    plt.title("Per State Marginal Vaccine f1x")
    plt.legend()
    plt.xlabel("Marginal Vaccine Value ($)")
    plt.ylabel("State")
    plottable["f_pst"].loc[
                {"f1x": "mvv", "param": "baseline", "time": vv["time"][-1], "space": "Alabama"}
            ].values
    plt.show()
    return 

def tf7_f2x_p(vv):
    # TRANSFORM F1(X) TO F2(X): 
    # aggregation rules: over space should be done in the level of x, not fx + component aggregation then s
    vv['x1_pth1']=vv["x1_cpth1"].sum(dim ='costcomp_tv') # space aggregated population???
    vv['x1_ph1'] = vv['x1_pth1'].loc[{'time':time[-1]}] 
    vv["f1x_p"].loc[{"f1x": "mvv", "param": param}] = (vv["x1_ph1"].loc[{"h1": "1.01"}] - vv["x1_ph1"].loc[{"h1": "1"}]) / (vv["x2_ph1"].loc[{"noncost_tv": "population", "h1":"1.01"}] - vv["x2_ph1"].loc[{"noncost_tv": "population", "h1":"1"}])
    vv['f2x_p'] = (vv['f1x_p'].loc[{"params": param}] - vv['f1x_p'].loc[{"params": "baseline"}]) / (param_multiplier - 1) 

    matplotlib.pyplot.rcdefaults()
    fig_avg, ax_avg = matplotlib.pyplot.subplots()
    fig_marg, ax_marg = matplotlib.pyplot.subplots()

    x_avg = [avg for marg, avg in vv["f2x_p"].values]
    x_marg = [marg for marg, avg in vv['f2x_p'].values]
    x_label = [val for val in vv.params.values]
    y_vars = [x for x in range(len(vv['f_p']))] ###
    x_avg_sorted = []
    x_marg_sorted = []
    x_label_sorted = []
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

def tf8_x_ch2(vv):
    vv["f5x_c"] = vv["f5x_cst"].sel(time=time[-1]).sum(dim='space')
    
    matplotlib.pyplot.rcdefaults()
    #ADDITIVE CENTERING
    death_vals = vv["f5x_c"].sel(costcomp_tv= 'death')/10 ** 12
    gdp_vals = vv["f5x_c"].sel(costcomp_tv= 'gdp')/ 10 ** 12
    gdp_vals = vv["f5x_c"].sel(costcomp_tv= 'hospitalization')/ 10 ** 12
  
    plot_d = matplotlib.pyplot.bar(vv.coords["h2"].values, death_vals, width=2)
    plot_d.set_label("Deaths")
    plot_g = matplotlib.pyplot.bar(vv.coords["h2"].values, gdp_vals, bottom=death_vals, width=2)
    plot_g.set_label("GDP")
    plot_h = matplotlib.pyplot.bar(vv.coords["h2"].values, hosp_vals, bottom=death_vals + gdp_vals, width=2)
    plot_h.set_label("Hospitalization")
    
    matplotlib.pyplot.legend()
    matplotlib.pyplot.xlabel("Vaccine start time offset (days)")
    matplotlib.pyplot.ylabel("Total vaccine value (Trillion USD)")
    matplotlib.pyplot.axhline(y=0, color='k', linestyle='-')
    matplotlib.pyplot.show()
    return

print(os.getcwd())
vgpath = "./vendss64MC.exe"
log_file = "log.txt"
posterior_out = "OptimV81-Base.out"
datahp_mdl = "CovidUSA-Econ-V81.mdl" #previously generated via test.tab with vensim manually
param_lst = ["Variant Intro Start Time", "Variant Impact on Immunity Loss Time[Omicron]", "baseline"]

#param_lst = [param.replace(" ", "_") for param in param_lst]
# hyperparameter/action/counterfactual
vax_amt_lst = [1.01, 1, 0]
vax_time_lst = [i for i in range(-50, 60, 10)]
time = pd.date_range(start='10/15/2019', periods=1071)

vv = create_f123x1_pcsth12(vax_amt_lst, vax_time_lst)
tf112345_vgcsv2xr(vax_amt_lst, vax_time_lst, param_lst, param_multiplier = 1.01, vv=vv)
# vv.to_netcdf("nc_data/fx_pcsth.nc")

tf6_f2x_cs(vv)
# tf7_f2x_p(vv)
# tf8_x_ch2(vv)
