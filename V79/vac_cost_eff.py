import numpy as np
import pandas as pd
from VST.vst import vst_text, vst
import matplotlib.pyplot, matplotlib.dates
import os
import xarray as xr

def gen_param_names():
# spatial subscript
    state_names = ['Alabama', 'Alaska', 'Arizona', 'Arkansas', 'California', 'Colorado', 'Connecticut', 'Delaware',
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
    for name in state_names:
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
    return state_names, t_sharing_sbatched_params, ts_sharing_params

def store4testing(state_names, param_lst):
    # function
    # 1. marginal, 2. avg vaccine value 3. sensitivity of mvv, avv w.r.t each parameter 4.
    f_stat = ["vi_1dot1", "vi_base", "vi_zero", "m_vv", "a_vv", "m_vv_sens", "a_vv_sens"]  # better if functional form
    vi_1dot1 = "1.01"
    vi_base = "1"
    vi_zero = "0"

    # param_scal
    t_sharing_sbatched_params, ts_sharing_params = gen_param_names()[1:]
    param_lst = t_sharing_sbatched_params + ts_sharing_params + ["baseline"]

    # component_time_vec
    costcomp_tvec = ['death', 'gdp', 'hospitalization']
    noncost_tvec = ['population']
    # space
    state_names = gen_param_names()[0]

    # time
    hparam_time = pd.date_range(start='10/15/2019', periods=1071)
    hparam_vax_time = [range(-50, 60, 10)]
    dv = {
        "dims": {"f_stat", "param_scal", "costcomp_tvec", "noncost_tvec", "space", "time", "hparam_vax_time"},
        # action as hparam
        "coords": {  # pcstvh
            'f_stat': {"dims": ("f_stat"), "data": f_stat},  # value

            'param_scal': {"dims": ("param_scal"), "data": param_lst},

            'costcomp_tvec': {"dims": ("costcomp_tvec"), "data": costcomp_tvec},
            'noncost_tvec': {"dims": ("noncost_tvec"), "data": noncost_tvec},

            'space': {"dims": ("space"), "data": state_names},
            'time': {"dims": ("time"), "data": hparam_time},
            'hparam_vax_time': {"dims": ("hparam_vax_time"), "data": [str(vt) for vt in hparam_vax_time]}
        },
        "data_vars": {  # 5+3
            "f_pcst": {"dims": ("f_stat", "param_scal", "costcomp_tvec", "space", "time",), "data": np.zeros(
                shape=(len(f_stat), len(param_lst), len(costcomp_tvec), len(state_names), len(hparam_time)))},
            "f_pnst": {"dims": ("f_stat", "param_scal", "noncost_tvec", "space", "time",), "data": np.zeros(
                shape=(len(f_stat), len(param_lst), len(noncost_tvec), len(state_names), len(hparam_time)))},

            "f_pct": {"dims": ("f_stat", "param_scal", "costcomp_tvec", "time",),
                      "data": np.zeros(shape=(len(f_stat), len(param_lst), len(costcomp_tvec), len(hparam_time)))},
            "f_pnt": {"dims": ("f_stat", "param_scal", "noncost_tvec", "time",),
                      "data": np.zeros(shape=(len(f_stat), len(param_lst), len(noncost_tvec), len(hparam_time)))},
            "f_pst": {"dims": ("f_stat", "param_scal", "space", "time",),
                      "data": np.zeros(shape=(len(f_stat), len(param_lst), len(state_names), len(hparam_time)))},

            "f_pt": {"dims": ("f_stat", "param_scal", "time",),
                     "data": np.zeros(shape=(len(f_stat), len(param_lst), len(hparam_time)))},
        },
        "attrs": {
            "title": "1.vaccine value disaggregated by parameter, time, space, component, 2.counterfactual by parameter for validity, 3.counterfactual by datahp for summary stat."}
        # 1 and 2 are descriptive, 3 is prescriptive
    }
    vv = xr.Dataset.from_dict(dv)

    # 51 states * 4 (efficacy of  death, gdp, health, population)
    # row 0, 4-54 (csv's 6-56) -> 1 set, death
    # row 1,55 -105 (csv's 57-107)-> 2 set, gdp
    # row 2, 106-156(csv's 108-158) -> 3 set, hosp

    # BASELINE HAPPENS ONCE
    # TODO do we need to generate two csv files? (how to compute average and marginal in python)
    avg = pd.read_csv("avg_cost_per_person_base.tsv", sep="\t", index_col=0)
    marg = pd.read_csv("marg_cost_per_person_base.tsv", sep="\t", index_col=0)
    vv['VV_csv'].loc[dict(component='death', value='average')] = avg.loc[4:54].values.flatten()
    vv['VV_csv'].loc[dict(component='gdp', value='average')] = avg.loc[55:105].values.flatten()
    vv['VV_csv'].loc[dict(component='hospitalization', value='average')] = avg.loc[106:156].values.flatten()

    vv['VV_csv'].loc[dict(component='death', value='marginal')] = marg.loc[4:54].values.flatten()
    vv['VV_csv'].loc[dict(component='gdp', value='marginal')] = marg.loc[55:105].values.flatten()
    vv['VV_csv'].loc[dict(component='hospitalization', value='marginal')] = marg.loc[106:156].values.flatten()

    vv['VV_cv'].loc[dict(component='death', value='average')] = avg.loc[0].values.item()
    vv['VV_cv'].loc[dict(component='gdp', value='average')] = avg.loc[1].values.item()
    vv['VV_cv'].loc[dict(component='hospitalization', value='average')] = avg.loc[2].values.item()

    vv['VV_cv'].loc[dict(component='death', value='marginal')] = marg.loc[0].values.item()
    vv['VV_cv'].loc[dict(component='gdp', value='marginal')] = marg.loc[1].values.item()
    vv['VV_cv'].loc[dict(component='hospitalization', value='marginal')] = marg.loc[2].values.item()

    vv['VV_sv'] = vv['VV_csv'].sum(dim='component')
    vv['VV_v'] = vv['VV_cv'].sum(dim='component')

    # COUNTERFACTUAL HAPPENS 22 times
    for file_param, param in zip(param_lst, param_lst):
        file = file_param.replace(" ", "_")
        avg = pd.read_csv(file + '_avg.tsv', sep='\t', index_col=0)
        marg = pd.read_csv(file + '_marg.tsv', sep='\t', index_col=0)

        vv['VV_1_pcsv'].loc[dict(params=param, component='death', value='average')] = avg.loc[4:54].values.flatten()
        vv['VV_1_pcsv'].loc[dict(params=param, component='gdp', value='average')] = avg.loc[55:105].values.flatten()
        vv['VV_1_pcsv'].loc[dict(params=param, component='hospitalization', value='average')] = avg.loc[
                                                                                                 106:156].values.flatten()

        vv['VV_1_pcsv'].loc[dict(params=param, component='death', value='marginal')] = marg.loc[4:54].values.flatten()
        vv['VV_1_pcsv'].loc[dict(params=param, component='gdp', value='marginal')] = marg.loc[55:105].values.flatten()
        vv['VV_1_pcsv'].loc[dict(params=param, component='hospitalization', value='marginal')] = marg.loc[
                                                                                                  106:156].values.flatten()

        vv['VV_1_pcv'].loc[dict(params=param, component='death', value='average')] = avg.loc[0].values.item()
        vv['VV_1_pcv'].loc[dict(params=param, component='gdp', value='average')] = avg.loc[1].values.item()
        vv['VV_1_pcv'].loc[dict(params=param, component='hospitalization', value='average')] = avg.loc[2].values.item()

        vv['VV_1_pcv'].loc[dict(params=param, component='death', value='marginal')] = marg.loc[0].values.item()
        vv['VV_1_pcv'].loc[dict(params=param, component='gdp', value='marginal')] = marg.loc[1].values.item()
        vv['VV_1_pcv'].loc[dict(params=param, component='hospitalization', value='marginal')] = marg.loc[2].values.item()

        vv['VV_1_pv'] = vv['VV_1_pcv'].sum(dim='component')

    for param_lst in param_lst:
        print(param_lst)
        calc_param_impact_on_cost(param_lst, 1.01, vv, use_vengine=True)
        vv["epsilon_ptv"] = ((vv["VV_1_ptv"].loc[{"params": param_lst[0]}] - vv["VV_1_ptv"].loc[
            {"params": "baseline"}]) / vv["VV_1_ptv"].loc[{"params": "baseline"}]) / 0.01
    vv.to_netcdf("nc_data/vv_pcstvh.nc")
    return vv


def f_stat_given_hparam(param_name_list, percent_change, vv, use_vengine=False,
                              param_name=None):  # list of str or list of list (local variables), # real
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

    def calc_vvdiff_by_pop(raw_values: pd.DataFrame) -> pd.DataFrame:
        values_normalized_by_pop = pd.DataFrame()
        columns_to_adjust = [
            "Cost of Deaths Cumulative",
            "Cost of GDP Cumulative",
            "Cost of Hospitalizations Cumulative"
        ]
        population_column = "Vaccine Taking Population"
        locations = [f"[{state}]" for state in state_names]
        locations += [" All"]
        for location in locations:
            for column in columns_to_adjust:
                values_normalized_by_pop[column + location] = raw_values[column + location] / raw_values[
                    population_column + location]
        return values_normalized_by_pop

    if not param_name:
        param_name = param_name_list[0]
    hparam_vi = [vi_1dot1, vi_base, vi_zero]
    hparam_vax_time = [range(-50, 60, 10)]

    for VaxInc_val in hparam_vi: #[0]:#, 1, 1.01]:
        if use_vengine:
            param_new_val_list = []
            for item in log_file:
                try:
                    param_base = vst_text.get_value(f'{posterior_out}', item)
                except TypeError:  # if we can't find param in optimization output, pull it out of model directly, should be done form mdl but is currently from .tab generated from vensim
                    param_base = vst_text.get_value(f'{datahp_mdl}', item)
                    # df = pd.read_csv(f"{test_file}", sep="\t",
                    #                      index_col=0)  # raw values (all params outside .out, manually generated from .mdl/ can read from .mdl)
                    # param_base = df.loc[item][0]
                param_new_val_list.append(param_base * percent_change)  # TODO: make this function with list param for rgn
            setval_lst = [("VaxInc", VaxInc_val)] + [(param_name, param_new_val) for param_name, param_new_val in zip(param_name_list, param_new_val_list)]
            run = vst.Script(cf, f"param_{param_name}", log_file, setvals=setval_lst, simtype='r')
            run.compile_script(vgpath, log_file, subdir="VAMA", check_funcs=[lambda a, b: True])
            os.replace(f"VAMA/Covidparam_{param_name}.csv", f"CSV/Covidparam_{param_name}_{VaxInc_val}.csv")

    for vax_time in hparam_vax_time:
        if use_vengine:
            param_new_val_list = []
            for item in log_file:
                try:
                    param_base = vst_text.get_value(f'{posterior_out}', item)
                except TypeError:  # if we can't find param in optimization output, pull it out of model directly, should be done form mdl but is currently from .tab generated from vensim
                    param_base = vst_text.get_value(f'{datahp_mdl}', item)
                    # df = pd.read_csv(f"{test_file}", sep="\t",
                    #                      index_col=0)  # raw values (all params outside .out, manually generated from .mdl/ can read from .mdl)
                    # param_base = df.loc[item][0]
                param_new_val_list.append(
                    param_base * percent_change)  # TODO: make this function with list param for rgn
            setval_lst = [("VaccinationShift", hparam_vax_time)]
            run = vst.Script(cf, f"vax_time_{vax_time}", log_file, setvals=setval_lst, simtype='r')
            run.compile_script(vgpath, log_file, subdir="VAMA", check_funcs=[lambda a, b: True])
            os.replace(f"VAMA/m_vv_{param_name}.csv", f"CSV/m_vv_{vax_time}.csv")
        param_vv_raw = pd.read_csv(f"CSV/Covidparam_{param_name}_{VaxInc_val}.csv", index_col=0).T
        vi_r2s = {1.01: 'vi_1dot1', 1: 'vi_base', 0: 'vi_zero', }

        def calc_vvdiff_by_pop(raw_values: pd.DataFrame) -> pd.DataFrame:
            values_normalized_by_pop = pd.DataFrame()
            columns_to_adjust = [
                "Cost of Deaths Cumulative",
                "Cost of GDP Cumulative",
                "Cost of Hospitalizations Cumulative"
            ]
            population_column = "Vaccine Taking Population"
            locations = [f"[{state}]" for state in state_names]
            locations += [" All"]
            for location in locations:
                for column in columns_to_adjust:
                    values_normalized_by_pop[column + location] = raw_values[column + location] / raw_values[
                        population_column + location]
            return values_normalized_by_pop

        param_vv = calc_vvdiff_by_pop(param_vv_raw)

        vv["f_pct"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "death"}] = \
        param_vv_raw["Cost of Deaths Cumulative All"].values.flatten()
        vv["f_pct"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "gdp"}] = \
        param_vv_raw["Cost of GDP Cumulative All"].values.flatten()
        vv["f_pct"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "hospitalization"}] = \
        param_vv_raw["Cost of Hospitalizations Cumulative All"].values.flatten()

        vv["f_pnt"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "noncost_tvec": "population"}] = \
        param_vv_raw["Vaccine Taking Population All"].values.flatten()

        for state in state_names:
            vv["f_pcst"].loc[
                {"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "death", "space": state}] = \
            param_vv[f"Cost of Deaths Cumulative[{state}]"].values.flatten()
            vv["f_pcst"].loc[
                {"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "gdp", "space": state}] = \
            param_vv[f"Cost of GDP Cumulative[{state}]"].values.flatten()
            vv["f_pcst"].loc[
                {"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "hospitalization",
                 "space": state}] = param_vv[f"Cost of Hospitalizations Cumulative[{state}]"].values.flatten()

            vv["f_pnst"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "noncost_tvec": "population",
                              "space": state}] = param_vv_raw[f"Vaccine Taking Population[{state}]"].values.flatten()

        vv["f_pcst"].loc[{"f_stat": "a_vv"}] = (vv["f_pcst"].loc[{"f_stat": "vi_base"}] - vv["f_pcst"].loc[
            {"f_stat": "vi_zero"}]) / (vv["f_pnst"].loc[{"f_stat": "vi_base", "noncost_tvec": "population"}] -
                                       vv["f_pnst"].loc[{"f_stat": "vi_zero", "noncost_tvec": "population"}])
        vv["f_pcst"].loc[{"f_stat": "m_vv"}] = (vv["f_pcst"].loc[{"f_stat": "vi_1dot1"}] - vv["f_pcst"].loc[
            {"f_stat": "vi_base"}]) / (vv["f_pnst"].loc[{"f_stat": "vi_1dot1", "noncost_tvec": "population"}] -
                                       vv["f_pnst"].loc[{"f_stat": "vi_base", "noncost_tvec": "population"}])

        vv["f_pct"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "death"}] = param_vv[
            "Cost of Deaths Cumulative All"].values.flatten()
        vv["f_pct"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "gdp"}] = param_vv[
            "Cost of GDP Cumulative All"].values.flatten()
        vv["f_pct"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "costcomp_tvec": "hospitalization"}] = \
        param_vv["Cost of Hospitalizations Cumulative All"].values.flatten()

        vv["f_pnt"].loc[{"f_stat": vi_r2s[VaxInc_val], "param_scal": param_name, "noncost_tvec": "population"}] = \
        param_vv_raw["Vaccine Taking Population All"].values.flatten()

        vv["f_pst"] = vv["f_pcst"].sum(dim="costcomp_tvec")
        vv["f_pt"] = vv["f_pct"].sum(dim="costcomp_tvec")


def tf5_mavv_by_t(vv):
    """
    validating calibration via comparing real and simulated (i.e. posterior retrodictive check)
    input: vv
    output: three timeseirs plots for `costcomp_tvec` death and hospitalization (overall) + gdp (new york, california, texas)
    """
    df=pd.read_csv("Sim_DataAgg.csv", index_col=[0,1]).transpose()
    df.columns.set_levels(['Sim', 'Data'], level = 0, inplace = True)
    df.set_index(pd.date_range(start = '10/15/2019', periods = 1071), inplace=True)
    df.columns.set_names(["sim_data", "component"], inplace=True)

    test_fit_dict = {
        "coords": {
            'sim_data': {"dims": ("sim_data"), "data": ["sim", "data"]},
            'component': {"dims": ("component"),  "data": ['infection', 'death', 'hospitalization']},
            'time': {"dims": ("time"), "data": df.index},
            #'space': {"dims" : ("space"), "data": state_names} didn't implement space disaggregation for sim_data comparison yet
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

def tf6_mavv_by_cs(vv):
    """
    marginal vaccine value of the last day for each state
    """
    plottable=vv.drop_sel(space="District of Columbia").sortby("space")
    plt.figure(figsize=(12, 10))  # width:10, height:8
    death_zip = list(zip(plottable["space"].values,
        -plottable["f_pcst"].loc[
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1], "costcomp_tvec": "death"}
            ].values,
        plottable["f_pst"].loc[
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1]}
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
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1], "costcomp_tvec": "gdp"}
            ].values,
        plottable["f_pst"].loc[
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1]}
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
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1], "costcomp_tvec": "hospitalization"}
            ].values,
        plottable["f_pst"].loc[
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1]}
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
    plt.title("Per State Marginal Vaccine f_stat")
    plt.legend()
    plt.xlabel("Marginal Vaccine Value ($)")
    plt.ylabel("State")
    plottable["f_pst"].loc[
                {"f_stat": "m_vv", "param_scal": "baseline", "time": vv["time"][-1], "space": "Alabama"}
            ].values
    return

def tf7_mavv_by_p(vv):
    matplotlib.pyplot.rcdefaults()
    fig_avg, ax_avg = matplotlib.pyplot.subplots()
    fig_marg, ax_marg = matplotlib.pyplot.subplots()

    x_avg = [avg for marg, avg in vv["f_p"].values]
    x_marg = [marg for marg, avg in vv['f_p'].values]
    x_label = [val for val in vv.params.values]
    y_vars = [x for x in range(len(vv['f_p']))]
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
def tf8_vv_by_h(vv):
    matplotlib.pyplot.rcdefaults()
    death_vals = vv["f_cth"].loc[{"time": hparam_time[-1], "costcomp_tvec": "death"}].values/10 ** 12
    death_vals = np.subtract(death_vals, vv["f_cth"].loc[
        {"f_stat": "vi_base", "time": hparam_time[-1], "costcomp_tvec": "death", "hparam": 0}].values.tolist() / 10 ** 12)
    gdp_vals = vv["f_cth"].loc[{"time": hparam_time[-1], "costcomp_tvec": "gdp"}].values/ 10 ** 12
    gdp_vals = np.subtract(gdp_vals, vv["f_cth"].loc[
        {"time": hparam_time[-1], "costcomp_tvec": "gdp", "hparam": 0}].values.tolist() / 10 ** 12)
    hosp_vals = np.divide(vv["VV_1_cth"].loc[{"time": hparam_time[-1], "component": "hospitalization"}].values, 10 ** 12)
    hosp_vals = np.subtract(hosp_vals, vv["f_cth"].loc[
        {"time": hparam_time[-1], "costcomp_tvec": "hospitalization", "hparam": 0}].values.tolist() / 10 ** 12)
    plot_d = matplotlib.pyplot.bar(vv.coords["hparam"].values, death_vals, width=2)
    plot_d.set_label("Deaths")
    plot_g = matplotlib.pyplot.bar(vv.coords["hparam"].values, gdp_vals, bottom=death_vals, width=2)
    plot_g.set_label("GDP")
    plot_h = matplotlib.pyplot.bar(vv.coords["hparam"].values, hosp_vals, bottom=death_vals + gdp_vals, width=2)
    plot_h.set_label("Hospitalization")
    matplotlib.pyplot.legend()
    matplotlib.pyplot.xlabel("Vaccine start time offset (days)")
    matplotlib.pyplot.ylabel("Total vaccine value (Trillion USD)")
    matplotlib.pyplot.axhline(y=0, color='k', linestyle='-')
    matplotlib.pyplot.show()
    return


vgpath = "./vendss64MC.exe"
log_file = "log.txt"
posterior_out = "OptimV81-Base.out"
datahp_mdl = "CovidUSA-Econ-V81.mdl" #previously generated via test.tab with vensim manually

vi_1dot1 = 1.01
vi_base = 1
vi_zero = 0
FINAL_TIME = 1100
hparam_time = pd.date_range(start='10/15/2019', periods= 1071)

state_names, t_sharing_sbatched_params, ts_sharing_params  = gen_param_names()
param_lst = t_sharing_sbatched_params + ts_sharing_params
vv = store4testing(state_names, param_lst)

results = calc_param_impact_on_cost(["Sensitivity to Weather"], 1, vv, use_vengine=True, param_name="baseline")  # baseline

# convert_timeshift_csv_to_nc("/Users/hyunjimoon/Dropbox (MIT)/WINcode/VaccineMisinf/nc_data/timeshift/timeshift")

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
