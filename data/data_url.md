final .nc file with the following info can be downloaded from [here](https://www.dropbox.com/s/zbq1pjc0b4hymt2/vv_pcstv_timeshift.nc?dl=0) (30mb) 

![image](https://github.com/hyunjimoon/VaccineMisinf/assets/30194633/ca19d215-636a-4077-bd96-770badedb64f)

data transformation workflow
### input
- final_tiem, vgpath, log_file, test_file, parameter_lst_lst
### output
- plots (counterfactuals, sensitivity, in order of hazhir's importance)

1. The reason parameter name of the xarray is defined as "param[0]" from "'params': {"dims": ("params"), "data": [param[0] for param in param_lst_lst] + ["baseline"]}," is because, we defined param_lst_lst as double lists and we need list of strings for the variable name for xarray variable definition.
`param_lst_lst`:
```
Treatment on Fatality Rate[Alabama]', 'Impact of Treatment on Fatality Rate[Alaska]', ..., 'Impact of Treatment on Fatality Rate[District of Columbia]'], ['Base Fatality Rate for Unit Acuity[Alabama]', 'Base Fatality Rate for Unit Acuity[Alaska]',.., 'Variant Intro Start Time2[District of Columbia]'], ['Variant Impact on Immunity Loss Time[Omicron]'], ['Variant Impact on Immunity Loss Time[Delta]'], ['Variant Impact on Immunity Loss Time[BA5]'], ['Extra Vaccine Impact on Responsiveness[Vx]'], ['Extra Vaccine Impact on Responsiveness[NVx]'], ['Extra Vaccine Impact on Responsiveness[Naive]'], ['Immunity Loss Time[Vx]'], ['Immunity Loss Time[NVx]'], ['Immunity Loss Time[Naive]'], ['Variant Accuity Multiplier[Omicron]'], ['Variant Accuity Multiplier[Delta]'], ['Variant Accuity Multiplier[BA5]'], ['Variant Intro Start Time3'], ['Variant Transmission Multiplier[Omicron]'], ['Variant Transmission Multiplier[Delta]'], ['Variant Transmission Multiplier[BA5]']]
```
`[param[0] for param in param_lst_lst]`
```
['Impact of Treatment on Fatality Rate[Alabama]', 'Base Fatality Rate for Unit Acuity[Alabama]', 'Reference Force of Infection[Alabama]', 'Strength of Adherence Fatigue[Alabama]', 'Variant Intro Start Time[Alabama]', 'Variant Intro Start Time2[Alabama]', 'Variant Impact on Immunity Loss Time[Omicron]', 'Variant Impact on Immunity Loss Time[Delta]', 'Variant Impact on Immunity Loss Time[BA5]', 'Extra Vaccine Impact on Responsiveness[Vx]', 'Extra Vaccine Impact on Responsiveness[NVx]', 'Extra Vaccine Impact on Responsiveness[Naive]', 'Immunity Loss Time[Vx]', 'Immunity Loss Time[NVx]', 'Immunity Loss Time[Naive]', 'Variant Accuity Multiplier[Omicron]', 'Variant Accuity Multiplier[Delta]', 'Variant Accuity Multiplier[BA5]', 'Variant Intro Start Time3', 'Variant Transmission Multiplier[Omicron]', 'Variant Transmission Multiplier[Delta]', 'Variant Transmission Multiplier[BA5]']
```

`[param for param in param_lst_lst]`
```
[['Variant Impact on Immunity Loss Time[Delta]'], ['Variant Impact on Immunity Loss Time[BA5]'], ['Extra Vaccine Impact on Responsiveness[Vx]'], ['Extra Vaccine Impact on Responsiveness[NVx]'], ['Extra Vaccine Impact on Responsiveness[Naive]'], ['Immunity Loss Time[Vx]'], ['Immunity Loss Time[NVx]'], ['Immunity Loss Time[Naive]'], ['Variant Accuity Multiplier[Omicron]'], ['Variant Accuity Multiplier[Delta]'], ['Variant Accuity Multiplier[BA5]'], ['Variant Intro Start Time3'], ['Variant Transmission Multiplier[Omicron]'], ['Variant Transmission Multiplier[Delta]'], ['Variant Transmission Multiplier[BA5]']]
```

`[param for param in vv_param_names]`
```
['Variant Impact on Immunity Loss Time[Omicron]', 'Variant Impact on Immunity Loss Time[Delta]', 'Variant Impact on Immunity Loss Time[BA5]', 'Impact of Treatment on Fatality Rate', 'Base Fatality Rate for Unit Acuity', 'Reference Force of Infection', 'Strength of Adherence Fatigue', 'Variant Intro Start Time', 'Variant Intro Start Time2', 'Extra Vaccine Impact on Responsiveness[Vx]', 'Extra Vaccine Impact on Responsiveness[NVx]', 'Extra Vaccine Impact on Responsiveness[Naive]', 'Immunity Loss Time[Vx]', 'Immunity Loss Time[NVx]', 'Immunity Loss Time[Naive]', 'Variant Accuity Multiplier[Omicron]', 'Variant Accuity Multiplier[Delta]', 'Variant Accuity Multiplier[BA5]', 'Variant Intro Start Time3', 'Variant Transmission Multiplier[Omicron]', 'Variant Transmission Multiplier[Delta]', 'Variant Transmission Multiplier[BA5]']
```
`[param[0].replace("[Alabama]", "") for param in param_lst_lst if "Alabama" in param[0]] + [param for param in param_lst_lst if "Alabama" not in param[0]]`
```
['Impact of Treatment on Fatality Rate', 'Base Fatality Rate for Unit Acuity', 'Reference Force of Infection', 'Strength of Adherence Fatigue', 'Variant Intro Start Time', 'Variant Intro Start Time2', ['Variant Impact on Immunity Loss Time[Omicron]'], ['Variant Impact on Immunity Loss Time[Delta]'], ['Variant Impact on Immunity Loss Time[BA5]'], ['Extra Vaccine Impact on Responsiveness[Vx]'], ['Extra Vaccine Impact on Responsiveness[NVx]'], ['Extra Vaccine Impact on Responsiveness[Naive]'], ['Immunity Loss Time[Vx]'], ['Immunity Loss Time[NVx]'], ['Immunity Loss Time[Naive]'], ['Variant Accuity Multiplier[Omicron]'], ['Variant Accuity Multiplier[Delta]'], ['Variant Accuity Multiplier[BA5]'], ['Variant Intro Start Time3'], ['Variant Transmission Multiplier[Omicron]'], ['Variant Transmission Multiplier[Delta]'], ['Variant Transmission Multiplier[BA5]']]
```

2. control files:
- savefile.lst
- control.txt

3. csv connecting vensim and xarray

1. tf5_validity_by_p
```
avg = pd.read_csv("avg_cost_per_person_base.tsv", sep="\t", index_col=0)
marg = pd.read_csv("marg_cost_per_person_base.tsv", sep="\t", index_col=0)
```
the above csv may not be needed as we vaccine value computing logic is embedded in creating store_xarr as below [here](https://github.com/hyunjimoon/VaccineMisinf/blob/6f28c1e5e645b6666edca0fde355f495de494f36/V79/vac_cost_eff.py#L298):
```
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
```
counterfactual reads 10 timeshifted values, store to `store_xarr`
```
        param_vv = pandas.read_csv(f"nc_data/Covidparam_{param_name.split()[0]}_{VaxInc_val}.csv", index_col=0).T
```
