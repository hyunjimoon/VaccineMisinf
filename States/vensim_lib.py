from numpy.core.numeric import NaN
import pandas
from pandas._libs.tslibs.timedeltas import ints_to_pytimedelta
from pandas.io.pytables import performance_doc
from os.path import exists

VENSIM_START_DATE = '10/15/2019'
VENSIM_TIME_PARAM = 'Time'

VENSIM_DATA_LOC           =         'data\\'

VENSIM_DATA_INPUT_PREFIX  =         VENSIM_DATA_LOC+'CovidModelInputs - '

VENSIM_CONSTANT_DATA_NAME =         'ConstantDataStates'
VENSIM_FLOW_DATA_NAME     =         'FlowDataStates'
VENSIM_CUM_DATA_NAME      =         'FormattedDataStates'
VENSIM_TEST_DATA_NAME     =         'TestDataStates'

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
    'Excess Deaths'     :                               '19'
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

def send_to_constants_file(data_series):
    CONSTANTS_FILENAME = VENSIM_DATA_INPUT_PREFIX+VENSIM_CONSTANT_DATA_NAME+'.csv'
    CONSTANT_STATES_NAME    = 'Unnamed: 1'
    CONSTANT_VAR_NAME       = 'DataConstants'
    constants_dataframe = pandas.read_csv(CONSTANTS_FILENAME)
    constants_dataframe.set_index([CONSTANT_STATES_NAME], inplace=True)
    constants_dataframe[data_series.name] = data_series
    constants_dataframe.reset_index(inplace=True)
    constants_dataframe.set_index([VENSIM_TIME_PARAM, CONSTANT_STATES_NAME], inplace=True)
    for key in VENSIM_CONSTANTS_MEAN_DICT:
        constants_dataframe.loc[key, '1'] = constants_dataframe[VENSIM_CONSTANTS_MEAN_DICT[key]].mean()
    constants_dataframe.to_csv(CONSTANTS_FILENAME)
    


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
    working_dataframe.to_csv(output_filename, sep='\t')
    

def unit_test_constants():
    test_ser = pandas.Series({'Alabama': 3.11, 'Alaska': 2.2 })
    test_ser.name = '9'
    send_to_constants_file(test_ser)

def main():
    unit_test_constants()

if __name__ == "__main__":
    main()
