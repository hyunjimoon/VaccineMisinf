from numpy.core.numeric import NaN
import pandas
from pandas._libs.tslibs.timedeltas import ints_to_pytimedelta
from pandas.io.pytables import performance_doc
import os

#You must add vengine or vendss to your environment path for this library to work
VENDSS_PATH       = 'vendss64'
VENGINE_PATH      = '\"Vensim - vengine\"'

VENSIM_START_DATE = '10/15/2019'
VENSIM_TIME_PARAM = 'Time'

VENSIM_DATA_LOC             =       'data\\'
VENSIM_MODEL_VERSION        =       'V76\\'
VENSIM_MODEL_LOC            =       '..\\..\\Models\\'+VENSIM_MODEL_VERSION+'USA\\'
VENSIM_DATA_EXTENSION       =       '.vdf'

VENSIM_DATA_INPUT_PREFIX    =       'CovidModelInputs - '

VENSIM_CONSTANT_DATA_NAME   =       'ConstantDataStates'

VENSIM_EXCESS_DEATHS_NAME   =       '20'
VENSIM_END_TIME_NAME        =       '22'

VENSIM_CONSTANTS_DICT = {
    'Population'        :                               '1',
    'Area'              :                               '5',
    'Attention Time':                                   '9',
    'Beds'              :                               '11',
    'Demographics'      :                               '12',
    'ED Start'          :                               '13',
    'ED End'            :                               '14',
    'ED (minus Covid)'  :                               '15',
    'Obesity Rate'      :                               '16',
    'Chronic Death Rate':                               '17',
    'Liver Disease Rate':                               '18',
    'Excess Deaths'     :                               '20',

    'End Time'          :                               '22'
}



VENSIM_CONSTANTS_MEAN_DICT = {
    'MeanObesity'       :                               '16',
    'MeanChronic'       :                               '17',
    'MeanLiver'         :                               '18'
}

def normalize_date(date):
    try:
        result = (pandas.to_datetime(date) - pandas.to_datetime(VENSIM_START_DATE)).dt.days
    except AttributeError:
        result = (pandas.to_datetime(date) - pandas.to_datetime(VENSIM_START_DATE)).days
    except pandas.dateutil.parser._parser.ParserError:
        pass
    return result

def relocate_columns(output_data):
    try:
        while not output_data.columns.tolist()[-1].isnumeric():
            cols = output_data.columns.tolist()[:-1]
            cols.insert(1, output_data.columns.tolist()[-1])
            output_data = output_data[cols]
    except(AttributeError): #not a string
        pass
    return output_data

def send_to_constants_file(data_series, update_model_constants = True):
    CONSTANTS_FILENAME = VENSIM_DATA_INPUT_PREFIX+VENSIM_CONSTANT_DATA_NAME
    CONSTANT_STATES_NAME    = 'Unnamed: 1'
    CONSTANT_VAR_NAME       = 'DataConstants'
    constants_dataframe = pandas.read_csv(VENSIM_DATA_LOC+CONSTANTS_FILENAME+'.csv')
    constants_dataframe.set_index([CONSTANT_STATES_NAME], inplace=True)
    constants_dataframe[data_series.name] = data_series
    constants_dataframe.reset_index(inplace=True)
    constants_dataframe.set_index([VENSIM_TIME_PARAM, CONSTANT_STATES_NAME], inplace=True)
    for key in VENSIM_CONSTANTS_MEAN_DICT:
        constants_dataframe.loc[key, '1'] = constants_dataframe[VENSIM_CONSTANTS_MEAN_DICT[key]].mean()
    constants_dataframe.to_csv(VENSIM_DATA_LOC+CONSTANTS_FILENAME+'.csv')
    if update_model_constants:
        create_vdf_from_csv(CONSTANTS_FILENAME)


def send_to_vensim_csv(dataframe, output_filename, vensim_vars, var_cols=[]):
    working_dataframe = dataframe.copy()
    working_dataframe.reset_index(inplace=True)
    var_cols.extend([VENSIM_TIME_PARAM])
    working_dataframe.set_index(var_cols, inplace=True)
    working_dataframe = working_dataframe[vensim_vars]
    working_dataframe = working_dataframe.unstack(level = len(var_cols)-1)
    working_dataframe = working_dataframe.stack(level=-2)
    working_dataframe.reset_index(inplace=True)
    working_dataframe.rename(columns={'level_1':VENSIM_TIME_PARAM}, inplace=True)
    working_dataframe.set_index(VENSIM_TIME_PARAM, inplace=True)
    working_dataframe.sort_index(inplace=True)
    working_dataframe.rename(columns={key:'' for key in var_cols}, inplace=True)
    working_dataframe.to_csv(output_filename+'.csv')
    

def create_vdf_from_csv(input_filename):
    script_name = VENSIM_DATA_LOC+input_filename+'.cmd'
    with open(script_name, 'w') as vensim_script:
        vensim_script.write('MENU>CSV2VDF|'+input_filename+'.csv|'+input_filename+VENSIM_DATA_EXTENSION+'|1_var.frm\n')
        vensim_script.write('MENU>EXIT')
    os.system(VENGINE_PATH+' '+script_name)
    os.replace(VENSIM_DATA_LOC+input_filename+VENSIM_DATA_EXTENSION, VENSIM_MODEL_LOC+input_filename+VENSIM_DATA_EXTENSION)

def copy_csv_to_model(csv_name):
    os.replace(VENSIM_DATA_LOC+csv_name+'.csv', VENSIM_MODEL_LOC+csv_name+'.csv')


def unit_test_constants():
    test_ser = pandas.Series({'Alabama': 3.11, 'Alaska': 2.2 })
    test_ser.name = '9'
    send_to_constants_file(test_ser)

def main():
    unit_test_constants()

if __name__ == "__main__":
    main()
