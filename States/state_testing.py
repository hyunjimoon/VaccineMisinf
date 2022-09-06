from datetime import datetime
from os import name, stat
from tabnanny import verbose
import pandas
import names_lib
import vensim_lib
import data_lib

TESTING_DATA_URL="https://jhucoronavirus.azureedge.net/api/v1/testing/daily.json"
DATA_WEBSITE = 'healthdata.gov'
DATA_SOURCE='j8mb-icvb'

OUTPUT_FILENAME = 'CovidModelInputs - TestDataStates'
DATASET_STATE_NAME = 'state'
DATASET_DATE_NAME = 'date'
DATASET_TEST_RESULT_NAME = 'overall_outcome'
DATASET_RESULT_SUM_NAME = 'total'
DATASET_TEST_NAME = 'new_results_reported'
DATASET_TEST_CUM_NAME = 'total_results_reported'
DATASET_TEST_AVG = 'DataTestRate'
DATASET_AVG_WINDOW = 7
DATASET_CUM_NAME = 'DataCmltTest'
    
#deprecated and replaced by fast sum below
def simple_sum(dataset_to_sum):
    for date in dataset_to_sum[DATASET_DATE_NAME].drop_duplicates():
        tot_tests = dataset_to_sum.loc[dataset_to_sum[DATASET_DATE_NAME] == date].copy()
        data_to_add=tot_tests.iloc[0].copy()
        data_to_add[DATASET_TEST_NAME] = sum(tot_tests[DATASET_TEST_NAME])
        data_to_add[DATASET_TEST_CUM_NAME] = sum(tot_tests[DATASET_TEST_CUM_NAME])
        data_to_add[DATASET_TEST_RESULT_NAME] = DATASET_RESULT_SUM_NAME
        dataset_to_sum = dataset_to_sum.append(data_to_add)
        dataset_to_sum = dataset_to_sum.loc[dataset_to_sum[DATASET_TEST_RESULT_NAME] == DATASET_RESULT_SUM_NAME]
    return dataset_to_sum

def fast_sum(dataset_to_sum):
    dataset_to_sum.set_index(DATASET_DATE_NAME,inplace=True)
    dataset_to_sum[DATASET_TEST_NAME+'2']=0
    dataset_to_sum[DATASET_TEST_CUM_NAME+'2']=0
    for item in dataset_to_sum[DATASET_TEST_RESULT_NAME].drop_duplicates():
        curr_subset = dataset_to_sum.loc[dataset_to_sum[DATASET_TEST_RESULT_NAME] == item].copy(deep = True)
        dataset_to_sum[DATASET_TEST_NAME+'2'] = dataset_to_sum[DATASET_TEST_NAME+'2'].add(curr_subset[DATASET_TEST_NAME].astype(int), fill_value=0)
        dataset_to_sum[DATASET_TEST_CUM_NAME+'2'] = dataset_to_sum[DATASET_TEST_CUM_NAME+'2'].add(curr_subset[DATASET_TEST_CUM_NAME], fill_value=0)
    dataset_to_sum.drop(columns = [DATASET_TEST_NAME, DATASET_TEST_CUM_NAME], inplace=True)
    dataset_to_sum.rename(columns = {DATASET_TEST_NAME+'2' : DATASET_TEST_NAME, DATASET_TEST_CUM_NAME+'2' : DATASET_TEST_CUM_NAME}, inplace=True)
    dataset_to_sum = dataset_to_sum[~dataset_to_sum.index.duplicated()]
    dataset_to_sum.reset_index(inplace = True)
    return dataset_to_sum
    
    
    

def process_data(input_dataframe, debug_level=0):
    testing_data = input_dataframe
    testing_data[DATASET_DATE_NAME] = pandas.to_datetime(testing_data[DATASET_DATE_NAME])
    output_dataframe = pandas.DataFrame()
    for state in names_lib.states_abb:
        if debug_level>0:
            start_state = datetime.now()
        state_data = testing_data.loc[testing_data[DATASET_STATE_NAME] == state].copy(deep=False)
        state_data = fast_sum(state_data)
        #new dataset already has cumsum
        #state_data[DATASET_CUM_NAME] = state_data[DATASET_TEST_NAME].cumsum()
        state_data.rename(columns = {DATASET_TEST_CUM_NAME : DATASET_CUM_NAME}, inplace=True)
        state_data[DATASET_TEST_AVG] = state_data[DATASET_TEST_NAME].rolling(DATASET_AVG_WINDOW, min_periods=1).mean()
        state_data = state_data[[DATASET_DATE_NAME, DATASET_TEST_AVG, DATASET_CUM_NAME]]
        state_data[DATASET_DATE_NAME]=vensim_lib.normalize_date(state_data[DATASET_DATE_NAME])
        state_data.set_index(DATASET_DATE_NAME,inplace=True)
        state_data = state_data.transpose()
        state_data[DATASET_STATE_NAME] = names_lib.code_to_state_dict[state]
        state_data.reset_index(inplace=True)
        state_data.rename(columns={'index':0,DATASET_STATE_NAME:1}, inplace=True) #need to give a number here so it works right with numbers elsewhere
        output_dataframe = output_dataframe.append(state_data)
        output_dataframe.sort_index(axis='columns', inplace=True)
        if debug_level>0:
            print(f'time for {state}: {datetime.now()-start_state}')
    output_dataframe.rename(columns={0:vensim_lib.VENSIM_TIME_PARAM, 1:DATASET_STATE_NAME}, inplace=True)
    return output_dataframe

def send_data_to_csv(test_dataframe, out_file_name):
    dataframe_to_print = test_dataframe.loc[test_dataframe[vensim_lib.VENSIM_TIME_PARAM].isin([DATASET_TEST_AVG, DATASET_CUM_NAME])].copy()
    dataframe_to_print.sort_values([vensim_lib.VENSIM_TIME_PARAM, DATASET_STATE_NAME], axis='index', inplace=True)
    dataframe_to_print = dataframe_to_print.reset_index()
    dataframe_to_print.drop(labels='index', axis='columns', inplace=True)
    csv_header = pandas.DataFrame(dict(zip(dataframe_to_print.columns,dataframe_to_print.columns)),index=[-1])
    csv_header[DATASET_STATE_NAME] = None
    dataframe_to_print = dataframe_to_print.append(csv_header)
    dataframe_to_print.sort_index(inplace=True)
    dataframe_to_print.to_csv(out_file_name, index=False, header=False)

def main():
    covid_test_data = data_lib.get_soda_data(website = DATA_WEBSITE, source = DATA_SOURCE, update=False)
    covid_test_data = process_data(covid_test_data, debug_level=10)
    send_data_to_csv(covid_test_data,vensim_lib.VENSIM_DATA_LOC+OUTPUT_FILENAME+'.csv')
    vensim_lib.create_vdf_from_csv(OUTPUT_FILENAME)
    vensim_lib.copy_csv_to_model(OUTPUT_FILENAME)
    
            
if __name__ == "__main__":
    main()