from os import name
import pandas
import data_lib
import vensim_lib
import names_lib

DATA_SOURCE     ='9bhg-hcku'
DATA_WEBSITE    ='data.cdc.gov'

COVID_DEATH_RATE_NAME = 'covid_death_rate'
DATSET_COVID_DEATHS_NAME = 'covid_19_deaths'
DATASET_TOTAL_DEATHS_NAME = 'total_deaths'
DATASET_AGE_GROUP_NAME = 'age_group'
DATASET_STATE_KEY = 'state'

SEX_BY_AGE_KEY = 'B01001_'
CENSUS_STATE_KEY = 'state'
ESTIMATE_KEY = 'E'

SHARED_DEMOGRAPHIC_KEY = [
    'Under 5 years',
    '5-14 years',
    '15-24 years',
    '25-34 years',
    '35-44 years',
    '45-54 years',
    '55-64 years',
    '65-74 years',
    '75-84 years',
    '85 years and over'
]

def gen_census_key_list(key_prefix, start, end, key_suffix):
    census_key_list = []
    for index in range(start, end+1):
        census_key_list.append(f'{key_prefix}{index:03}{key_suffix}')
    return census_key_list

def census_age_key(val):
    return f'{SEX_BY_AGE_KEY}{val:03}{ESTIMATE_KEY}'

def sum_census_pop_fields(dataset, keys, prefix=SEX_BY_AGE_KEY, suffix=ESTIMATE_KEY, mf_offset=(27-3)):
    new_series = pandas.Series([0]*dataset.shape[0])
    for key in keys:
        new_series+=(dataset[f'{SEX_BY_AGE_KEY}{key:03}{ESTIMATE_KEY}']+
        dataset[f'{SEX_BY_AGE_KEY}{key+mf_offset:03}{ESTIMATE_KEY}'])
    return new_series

def process_pop_data(pop_dataframe):
    pop_dataframe[CENSUS_STATE_KEY].replace(names_lib.fips_int_to_code_dict, inplace=True)
    # 3 = male under 5
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[0]] = sum_census_pop_fields(pop_dataframe, [3])
    # 4 = male 5 - 9; 5 = male 10 to 14
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[1]] = sum_census_pop_fields(pop_dataframe, [4, 5])
    # 6 = male 15 - 17; 7 = male 18 to 19, 8 = 20, 9 = 21, 10 = 22 to 24
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[2]] = sum_census_pop_fields(pop_dataframe, [6, 7, 8, 9, 10])
    # 11 = male 25 - 29; 12 = male 30 to 34
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[3]] = sum_census_pop_fields(pop_dataframe, [11, 12])
    # 13 = male 35 - 39; 14 = male 40 to 44
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[4]] = sum_census_pop_fields(pop_dataframe, [13, 14])
    # 15 = male 45 - 49; 16 = male 50 to 54
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[5]] = sum_census_pop_fields(pop_dataframe, [15, 16])
    # 17 = male 55 - 59; 18 = male 60 to 61, 19 = 62 to 64
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[6]] = sum_census_pop_fields(pop_dataframe, [17, 18, 19])
    # 20 = male 65 - 66; 21 = male 67 to 69, 22 = 70 to 74
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[7]] = sum_census_pop_fields(pop_dataframe, [20, 21, 22])
    # 23 = male 75 - 79; 24 = 80 to 84
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[8]] = sum_census_pop_fields(pop_dataframe, [23, 24])
    # 25 = male 85 and over
    pop_dataframe[SHARED_DEMOGRAPHIC_KEY[9]] = sum_census_pop_fields(pop_dataframe, [25])
    #pop_dataframe.to_csv('test.csv')
    for item in SHARED_DEMOGRAPHIC_KEY:
        #f'{SEX_BY_AGE_KEY}{1:03}{ESTIMATE_KEY}' = total pops entry
        pop_dataframe[item] = pop_dataframe[item]/pop_dataframe[f'{SEX_BY_AGE_KEY}{1:03}{ESTIMATE_KEY}']
    pop_dataframe = pop_dataframe[pop_dataframe[CENSUS_STATE_KEY].isin(names_lib.states_abb)]
    ret_dataframe = pop_dataframe[SHARED_DEMOGRAPHIC_KEY].copy()
    ret_dataframe[CENSUS_STATE_KEY] = pop_dataframe[CENSUS_STATE_KEY]
    #ret_dataframe.to_csv('test.csv')
    return ret_dataframe

def match_age_demographics(cdc_data):
    new_dataset = pandas.DataFrame()
    #under 5 years
    new_data = cdc_data.loc[cdc_data[DATASET_AGE_GROUP_NAME].isin(['Under 1 year', '1-4 years'])].sum(numeric_only=True)
    new_data[DATASET_AGE_GROUP_NAME] = SHARED_DEMOGRAPHIC_KEY[0]
    new_dataset = new_dataset.append(new_data, ignore_index=True)
    for key in SHARED_DEMOGRAPHIC_KEY:
        if 'Under 5 years' == key:
            pass
        new_dataset = new_dataset.append(cdc_data[cdc_data[DATASET_AGE_GROUP_NAME]==key], ignore_index=True)
    return new_dataset

def process_demo_death_data(demo_dataset):
    demo_dataset = demo_dataset[demo_dataset['sex']=='All Sexes']
    demo_dataset = demo_dataset[demo_dataset[DATASET_STATE_KEY] == 'United States']
    demo_dataset = demo_dataset[demo_dataset['group'] == 'By Total']
    #ugly hand rework to make CDC and census data match
    demo_dataset = match_age_demographics(demo_dataset)
    demo_dataset[COVID_DEATH_RATE_NAME] = demo_dataset[DATSET_COVID_DEATHS_NAME].divide(demo_dataset[DATASET_TOTAL_DEATHS_NAME], fill_value = 0)
    demo_dataset.set_index(DATASET_AGE_GROUP_NAME, inplace=True)
    ret_ser=demo_dataset[COVID_DEATH_RATE_NAME]
    return ret_ser

def main():
    census_calls = gen_census_key_list(key_prefix=SEX_BY_AGE_KEY, start=1, end=49, key_suffix=ESTIMATE_KEY)
    pop_data = data_lib.get_census_data(census_calls)
    pop_data = process_pop_data(pop_data)
    covid_demo_deaths = data_lib.get_soda_data(website=DATA_WEBSITE, source=DATA_SOURCE)
    demo_death_rates = process_demo_death_data(covid_demo_deaths)
    state_demo_impact = pop_data.multiply(demo_death_rates)
    state_demo_impact[DATASET_STATE_KEY] = pop_data[DATASET_STATE_KEY]
    state_demo_impact[DATASET_STATE_KEY].replace(names_lib.code_to_state_dict, inplace=True)
    state_demo_impact.set_index(DATASET_STATE_KEY, inplace=True)
    state_demo_impact.sort_index(inplace=True)
    state_demo_impact['overall']=state_demo_impact.sum(axis=1)
    state_demo_impact['overall']=state_demo_impact['overall'].divide(max(state_demo_impact['overall']))
    state_demo_impact.to_csv('demographics.csv')

if __name__ == "__main__":
    main()  