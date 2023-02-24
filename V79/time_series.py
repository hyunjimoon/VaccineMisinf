import matplotlib.pyplot as plt

from VST.vst import vst_text, vst
import json
import pandas
import matplotlib as plt

# vgpath = "C:/Program Files (x86)/Vengine2/Vensim - vengine.exe"
# log = "log.txt"
#
# controlfilename = 'Control_time.txt' #input("Enter control file name (with extension):")
# cf = json.load(open(controlfilename, 'r'))
# run = vst.Script(cf, "time_series", log, simtype='r')
# run.compile_script(vgpath, log, subdir="VAMA", check_funcs=[lambda a, b: True])

results=pandas.read_csv("Covidtime_series.csv", index_col=["Time", "Unnamed: 1", "Unnamed: 2"])
deaths_data=results.loc["Data Cumulative Deaths of Confirmed"]
deaths_data.dropna(inplace=True, how="all", axis=1)
deaths_sim=results.loc["Cumulative Deaths of Confirmed"]
deaths_sim.index.rename(inplace=True, names=["state", "empty"])
deaths_sim=deaths_sim.groupby(level=[0]).sum()

deaths_full=deaths_data.loc[["California", "New York", "Texas"]]
deaths_full.rename(index={
    "California":"California (Data)",
    "Texas":"Texas (Data)",
    "New York":"New York (Data)"
},inplace=True)
deaths_full=pandas.concat([deaths_full, deaths_sim.loc[["California", "New York", "Texas"], deaths_data.columns]])
deaths_full.rename(index={
    "California":"California (Sim)",
    "Texas":"Texas (Sim)",
    "New York":"New York (Sim)"
},inplace=True)
deaths_full.T.plot()
# plt.pyplot.show()

print(deaths_data)
print(deaths_sim.loc[:, deaths_data.columns])
# gdp_data=results.loc['Real World GDP Data (Gt)""']
# gdp_data.dropna(inplace=True, how="all", axis=1)
# gdp_data.index.rename(inplace=True, names=["state", "empty"])
# gdp_data=gdp_data.droplevel("empty")
# gdp_sim=results.loc["Reported Cumulated GDP"]
# gdp_sim.dropna(inplace=True, how="all", axis=1)
# gdp_sim.index.rename(inplace=True, names=["state", "empty"])
# gdp_sim=gdp_sim.droplevel("empty")
# gdp_full=gdp_data.loc[["California", "New York", "Texas"]]
# gdp_full.rename(index={
#     "California":"California (Data)",
#     "Texas":"Texas (Data)",
#     "New York":"New York (Data)"
# },inplace=True)
# gdp_full=pandas.concat([gdp_full, gdp_sim.loc[["California", "New York", "Texas"]]])
# gdp_full.rename(index={
#     "California":"California (Sim)",
#     "Texas":"Texas (Sim)",
#     "New York":"New York (Sim)"
# },inplace=True)
#
# print(gdp_full)
# gdp_full.T.plot()
plt.pyplot.show()