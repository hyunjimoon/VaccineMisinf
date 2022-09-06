from numpy import full
import pandas
import names_lib
import vensim_lib

GITHUB_URL = 'https://raw.githubusercontent.com/TheEconomist/covid-19-excess-deaths-tracker/master/output-data/excess-deaths/united_states_excess_deaths.csv'

DATASET_EXCESS_DEATHS_NAME  =       'excess_deaths'
DATASET_COVID_DEATHS_NAME   =       'covid_deaths'

VENSIM_DEATHS_DATA          =       'DeathDataStates'
VENSIM_COVID_DEATHS_NAME    =       'Data Cumulative Deaths of Confirmed'




def accumulate_excess_deaths(in_dataframe):
    state_cum_data = pandas.DataFrame()
    for state in names_lib.state_names.values():
        state_data = in_dataframe.loc[in_dataframe['region'] == state].copy()
        state_data.reset_index(inplace=True)
        tot_excess_deaths = sum(state_data[DATASET_EXCESS_DEATHS_NAME])
        tot_covid_deaths = sum(state_data[DATASET_COVID_DEATHS_NAME])
        state_data.loc[0, 'start_date'] = vensim_lib.normalize_date(state_data.loc[0, 'start_date'])
        state_data.loc[0, 'end_date'] = pandas.to_datetime(state_data.iloc[-1, state_data.columns.get_loc('end_date')])
        state_data.loc[0, 'end_date'] = vensim_lib.normalize_date(state_data.loc[0, 'end_date'])
        state_data.loc[0, DATASET_EXCESS_DEATHS_NAME] = tot_excess_deaths
        state_data.loc[0, DATASET_COVID_DEATHS_NAME] = tot_covid_deaths
        state_cum_data = state_cum_data.append(state_data.iloc[0])
    return state_cum_data


def process_covid_deaths(in_dataframe):
    full_state_data = pandas.DataFrame()
    for state in names_lib.state_names.values():
        full_state_data = pandas.concat([full_state_data, in_dataframe.loc[in_dataframe['region'] == state].copy()])
    full_state_data['start_date'] = vensim_lib.normalize_date(full_state_data['start_date'])
    full_state_data.rename(columns={'start_date' : 'Time', DATASET_COVID_DEATHS_NAME : VENSIM_COVID_DEATHS_NAME}, inplace=True)
    full_state_data.set_index('Time')
    return full_state_data

                 
def main():
    excess_deaths_data = pandas.read_csv(GITHUB_URL)
    cum_ed_data = accumulate_excess_deaths(excess_deaths_data)
    death_data = process_covid_deaths(excess_deaths_data)
    cum_ed_data.set_index('region', inplace=True)
    target_series = cum_ed_data[DATASET_EXCESS_DEATHS_NAME]
    target_series.name = vensim_lib.VENSIM_CONSTANTS_DICT['Excess Deaths']
    vensim_lib.send_to_constants_file(target_series)
    vensim_lib.send_to_vensim_csv(death_data, vensim_lib.VENSIM_DATA_LOC+vensim_lib.VENSIM_DATA_INPUT_PREFIX+VENSIM_DEATHS_DATA,
        [VENSIM_COVID_DEATHS_NAME, DATASET_EXCESS_DEATHS_NAME],['region'])
    vensim_lib.create_vdf_from_csv(vensim_lib.VENSIM_DATA_INPUT_PREFIX+VENSIM_DEATHS_DATA)

            
if __name__ == "__main__":
    main()  