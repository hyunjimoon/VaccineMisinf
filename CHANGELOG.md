# Change Log
## V0.x.x Unreleased yyyy-mm-dd
### New features
### Maintenance and fixes
### Deprecation
### Documentation

## V0.1.0 2023-07-14
[Code](https://github.com/hyunjimoon/VaccineMisinf/blob/main/V81/tf_fx_pcsth.py) with modularized functions:
- create (`create_f123x1_pcsth12`) xarray
- run vengine to create csv (output in [CSV folder](https://github.com/hyunjimoon/VaccineMisinf/tree/main/V81/CSV)) write csv into xarray (`tf112345_vgcsv2xr`)
- plot: `f5x_cst_h2`, `tf6_f2x_cs`, `tf7_f3x_p`, `tf8_x_ch2`, `tf9_f2x_dt`; output of each are in [PLOT folder](https://github.com/hyunjimoon/VaccineMisinf/tree/main/V81/PLOT)

Test:
- https://github.com/hyunjimoon/VaccineMisinf/issues/18
- willing to test with other consistency diagnostics

Need checking:
- estimated parameter values for MVV calculation: code line [here](https://github.com/hyunjimoon/VaccineMisinf/blob/86ec7037ef14fdf5a464a496e6512056ede28f41/V81/tf_fx_pcsth.py#L234)https://github.com/hyunjimoon/VaccineMisinf/blob/86ec7037ef14fdf5a464a496e6512056ede28f41/V81/tf_fx_pcsth.py#L234)
```
if "Variant Accuity Multiplier" in param_sbatched:
    if "[Delta]" in param_sbatched:
        param_base_scal = 1
    else:  # Omicron, BA5 read from .out
        param_base_scal = vst_text.get_value(f'{posterior_out}', param_sbatched)  # initial .90,.80 ; range .2~1.0-> estimated .80,.60
elif "Variant Impact on Immunity Loss Time" in param_sbatched:
    if "[Delta]" in param_sbatched:  # hyperparam [Delta]
        param_base_scal = 1
    else:  # estimated param [Omicron, BA5] as Variant Impact on Immunity Loss Time[BA5] = "Variant Impact on Immunity Loss Time[Omicron], though former is not in .out file
        param_base_scal = vst_text.get_value(f'{posterior_out}', "Variant Impact on Immunity Loss Time[Omicron]")

elif "Extra Vaccine Impact on Responsiveness" in param_sbatched:  # [Naive, Vx, NVx] encoded as [VS]
    param_base_scal = vst_text.get_value(f'{datahp_mdl}', "Extra Vaccine Impact on Responsiveness[VS]")
elif ("Immunity Loss Time" in param_sbatched) and ("Variant" not in param_sbatched):  # Extra Vaccine Impact on Responsiveness[Naive, Vx, NVx] VIRUS (attacker) SUBSCRIPT COMES AFTER PEOPLE (defender) SUBSCRIPT
    if "[Naive]" in param_sbatched:  # hyperparam [Naive]
        param_base_scal = 200
    else:  # estimated param[NVx, Vx]
        param_base_scal = vst_text.get_value(f'{posterior_out}', param_sbatched)

elif "Variant Transmission Multiplier" in param_sbatched:
    if "[Delta]" in param_sbatched:  # hyperparam [Delta]
        param_base_scal = vst_text.get_value(f'{posterior_out}', param_sbatched)  # initial 2.9; range 1~12-> estimated 2.72
    else:  # estimated param[NVx, Vx]Omicron, BA5 read from .out
        param_base_scal = vst_text.get_value(f'{posterior_out}', "Variant Transmission Multiplier[Omicron]")  # initial 2.8; range 1~12-> estimated 2.44
```
---
Here we write upgrading notes for brands. It's a team effort to make them as
straightforward as possible.
