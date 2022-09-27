#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 24 20:20:22 2021

@author: Hamed
"""
DATA_FLOW_INFECTION = 'DataFlowInfection'
DATA_FLOW_DEATH = 'DataFlowDeath'
DATA_FLOW_VAX = 'DataVaccineRate'
DATA_FLOW_VAX2 = 'DataVaccineD1Rate'
DATA_FLOW_VAX3 = 'DataVaccineCmpRate'
DATA_FLOW_HSP = 'DataHospitalStock'
DATA_FLOW_HSP2 = 'DataHospitalPedAndAdlt'
DATA_FLOW_TEST = 'DataTestRate'
DATA_FLOW_RECOVERY = 'DataFlowRecovery'
DATA_CUM_INFECTION = 'DataCmltInfection'
DATA_CUM_DEATH = 'DataCmltDeath'
DATA_CUM_VAX = 'DataCmltVaccination'
DATA_CUM_TEST = 'DataCmltTest'

DATA_LOC =          'data\\'
DATA_CUM_NAME =     'CovidModelInputs - FormattedDataStates'
DATA_FLOW_NAME =    'CovidModelInputs - FlowDataStates'

DATA_RGN_NAME = 'state'

from numpy.core.numeric import full
import pandas as pd
import requests
import names_lib
import vensim_lib
from datetime import datetime

def get_covid_data_from_src(state):
    url = f'https://covid.cdc.gov/covid-data-tracker/COVIDData/getAjaxData?id=us_trend_by_{state}'
    r = requests.get(url)
    data = r.json()
    data = data['us_trend_by_Geography']
    df = pd.DataFrame(data[1:])
    return df


def check_state_for_errors(state_data):
    error_list = []
    for day in range(0,state_data.shape[0]-1):
        if state_data["tot_cases"][day] - state_data["tot_cases"][day+1]!= -state_data["New_case"][day+1] or \
            state_data["tot_deaths"][day] - state_data["tot_deaths"][day+1]!= -state_data["new_death"][day+1]:
            error_list.append(day)
    return error_list

def format_state_data_for_vensim(state_data):
    state_name = state_data["state"][0]
    row = state_data.shape[0]
    state_data.loc[row] = [state_name]*state_data.shape[1]
    state_data = state_data.drop("state", axis=1)
    return state_data.sort_index(ascending=True)

def update_indiv_state_data():
    error_list = {}
    for state_code in names_lib.states_abb:
        state_start = datetime.now()
        state_data = get_covid_data_from_src(state_code)
        state_data = state_data[ ['date'] + [ col for col in state_data.columns if col != 'date' ] ]
        state_data['date']=pd.to_datetime(state_data['date'])
        state_data['Death_Case_Ratio']= 100*state_data['seven_day_avg_new_deaths']/ state_data['seven_day_avg_new_cases']
        state_data=state_data.sort_values(by='date',ascending=True)
        error_list[state_code] = check_state_for_errors(state_data)
        state_data.to_excel(f'data\\{state_code}.xlsx',index=False)
        print(f'Time to get for {state_code}: {datetime.now()-state_start}')
    with open("data\\errors.txt",'w') as error_file:
        for key in error_list.keys():
            error_file.write(f'{key}')
            for value in error_list[key]:
                error_file.write(f',\t{value}')
            error_file.write('\n')


def remove_from_back(list, element):
    list.reverse()
    list.remove(element)
    list.reverse()
    return list

def create_full_dict(state_list):
    frame_list = {}
    for state_code in state_list:
        state_start = datetime.now()
        curr_state_dataframe = pd.read_excel(f'data\\{state_code}.xlsx')
        frame_list[state_code]=curr_state_dataframe
        print(f'Time to read for {state_code}: {datetime.now()-state_start}')
    return frame_list

def format_state_data_for_merge(state_dataframe, state_code):
    lines_to_add = {}
    state_name = state_dataframe['state'][0]
    state_dataframe = state_dataframe.drop("state", axis=1)
    for curr_col in state_dataframe.columns:
        if curr_col == 'date':
            lines_to_add['date'] = ['code','state']
            continue
        #entry specific formatting
        elif curr_col == 'tot_deaths':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_CUM_DEATH})
            curr_col = DATA_CUM_DEATH
        elif curr_col == 'tot_cases':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_CUM_INFECTION})
            curr_col = DATA_CUM_INFECTION
        elif curr_col == 'Administered_Cumulative':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_CUM_VAX})
            curr_col = DATA_CUM_VAX
        elif curr_col == 'New_case':
            state_dataframe[curr_col]=state_dataframe[curr_col].rolling(7).mean()
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_INFECTION})
            curr_col = DATA_FLOW_INFECTION
        elif curr_col == 'new_death':
            state_dataframe[curr_col]=state_dataframe[curr_col].rolling(7).mean()
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_DEATH})
            curr_col = DATA_FLOW_DEATH
        elif curr_col == 'Administered_7_Day_Rolling_Average':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_VAX})
            curr_col = DATA_FLOW_VAX
        elif curr_col == 'Admin_Dose_1_Day_Rolling_Average':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_VAX2})
            curr_col = DATA_FLOW_VAX2
        elif curr_col == 'Series_Complete_Day_Rolling_Average':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_VAX3})
            curr_col = DATA_FLOW_VAX3
        elif curr_col == 'sum_inpatient_beds_used_covid_7DayAvg':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_HSP})
            curr_col = DATA_FLOW_HSP
        elif curr_col == 'sum_previous_day_pediatric_and_adult_7DayAvg':
            state_dataframe = state_dataframe.rename(columns={curr_col: DATA_FLOW_HSP2})
            curr_col = DATA_FLOW_HSP2
        new_name = curr_col+"_"+state_code
        state_dataframe = state_dataframe.rename(columns={curr_col: new_name})
        lines_to_add[new_name] = [curr_col, state_name]
    state_dataframe = pd.concat([pd.DataFrame(lines_to_add), state_dataframe.sort_values(by='date',ascending=True)], join="outer",ignore_index=True)
    #new_col_order = state_dataframe.columns.insert(0, "date")
    #new_col_order = remove_from_back(new_col_order.tolist(), "date")
    #state_dataframe = state_dataframe.reindex(columns=new_col_order)
    state_dataframe = state_dataframe.set_index("date")
    return state_dataframe



#for pandas apply    
def get_days(pandas_timedelta):
    try:
        return pandas_timedelta.days
    except(AttributeError): #if doesn't have a days attribute its not a timedelta, just return it
        return pandas_timedelta

def main(update_data=False, short = False):
    if update_data:
        update_indiv_state_data()
    full_data_frame = pd.DataFrame()
    if short:
        all_data_frames = create_full_dict(['AL','AK'])
    else:
        all_data_frames = create_full_dict(names_lib.states_abb)
    flow_col_list = [DATA_FLOW_DEATH, DATA_FLOW_VAX, DATA_FLOW_VAX2, DATA_FLOW_VAX3, DATA_FLOW_HSP, DATA_FLOW_HSP2]
    cum_col_list = [DATA_CUM_INFECTION, DATA_CUM_DEATH, DATA_CUM_VAX]
    test_col_list = [DATA_FLOW_TEST]
    for state_code in all_data_frames.keys():
        state_start = datetime.now()
        curr_frame = all_data_frames[state_code].copy()
        curr_frame['date'] = vensim_lib.normalize_date(curr_frame['date'])
        curr_frame.rename(columns={
            'date' : vensim_lib.VENSIM_TIME_PARAM,
            'tot_deaths' : DATA_CUM_DEATH,
            'tot_cases' : DATA_CUM_INFECTION,
            'Administered_Cumulative' : DATA_CUM_VAX,
            'New_case' : DATA_FLOW_INFECTION,
            'new_death' : DATA_FLOW_DEATH,
            'Administered_7_Day_Rolling_Average': DATA_FLOW_VAX,
            'Admin_Dose_1_Day_Rolling_Average' : DATA_FLOW_VAX2,
            'Series_Complete_Day_Rolling_Average' : DATA_FLOW_VAX3,
            'sum_inpatient_beds_used_covid_7DayAvg' : DATA_FLOW_HSP,
            'sum_previous_day_pediatric_and_adult_7DayAvg' : DATA_FLOW_HSP2
        }, inplace=True)
        index_tuple = [vensim_lib.VENSIM_TIME_PARAM, DATA_RGN_NAME]
        curr_frame.set_index(index_tuple, inplace=True)
        if full_data_frame.empty:
            full_data_frame = curr_frame
        else:
            full_data_frame = pd.concat([full_data_frame, curr_frame])
        print(f'Time to proc for {state_code}: {datetime.now()-state_start}')
    vensim_lib.send_to_vensim_csv2(dataframe=full_data_frame, output_filename=DATA_FLOW_NAME, vensim_vars=flow_col_list)
    vensim_lib.send_to_vensim_csv2(dataframe=full_data_frame, output_filename=DATA_CUM_NAME, vensim_vars=cum_col_list)
    vensim_lib.create_vdf_from_csv(DATA_FLOW_NAME)
    vensim_lib.create_vdf_from_csv(DATA_CUM_NAME)
    #full_data_frame.to_csv("data\\test.csv", header=False, columns=test_col_list, index=False)


if __name__ == "__main__":
    main(short=True)
