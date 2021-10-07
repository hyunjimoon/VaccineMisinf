#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 24 20:20:22 2021

@author: Hamed
"""


import pandas as pd
import requests
import os
from datetime import datetime

#os.chdir('/Users/Hamed/Desktop/Learn_PY/CDC_Data')

def get_covid_data_by_state(state):
    url = f'https://covid.cdc.gov/covid-data-tracker/COVIDData/getAjaxData?id=us_trend_by_{state}'
    r = requests.get(url)
    data = r.json()
    data = data['us_trend_by_Geography']
    df = pd.DataFrame(data[1:])
    return df


states_abb = ["AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DC", "DE", "FL", "GA", 
          "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", 
          "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", 
          "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", 
          "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"]

cross_section=pd.DataFrame(columns=['state','vaccine','Death_Case_Ratio'])

for state_code in states_abb:
    state_data = get_covid_data_by_state(state_code)
    state_data = state_data[ ['date'] + [ col for col in state_data.columns if col != 'date' ] ]
    state_data['date']=pd.to_datetime(state_data['date'])
    state_data['Death_Case_Ratio']= 100*state_data['seven_day_avg_new_deaths']/ state_data['seven_day_avg_new_cases']
    state_data=state_data.sort_values(by='date',ascending=False)
    state_data.to_excel(state_code + '.xlsx')
    

states = requests.get('https://covid.cdc.gov/covid-data-tracker/Content/CoronaViewJson_01/State_Territory_FluView1.json').json()
states = states['objects']['State_Territory_FluView1']['geometries']



for col in state_data:
    print(col)
    



