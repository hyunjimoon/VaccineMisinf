import pandas
import names_lib
import vensim_lib

DATA_LOC = 'data\\'
IMPORT_FILE_NAME = '2021_US_Region_Mobility_Report.csv'

ROW_SELECT_COLUMN = 'iso_3166_2_code'
DATA_STATE_NAME = 'sub_region_1'
DATA_TIME_NAME = 'date'

DATA_RETAIL_NAME = 'retail_and_recreation_percent_change_from_baseline'
DATA_STORE_NAME = 'grocery_and_pharmacy_percent_change_from_baseline'
DATA_PARKS_NAME = 'parks_percent_change_from_baseline'
DATA_TRANSIT_NAME = 'transit_stations_percent_change_from_baseline'
DATA_WORK_NAME = 'workplaces_percent_change_from_baseline'
DATA_HOME_NAME = 'residential_percent_change_from_baseline'


def process_data(input_dataframe):
    input_dataframe.dropna(subset = [ROW_SELECT_COLUMN], inplace=True)
    input_dataframe[DATA_TIME_NAME] = vensim_lib.normalize_date(input_dataframe[DATA_TIME_NAME])
    input_dataframe.rename(columns = {DATA_TIME_NAME:vensim_lib.VENSIM_TIME_PARAM}, inplace=True)
    input_dataframe.set_index(vensim_lib.VENSIM_TIME_PARAM, inplace=True)
    return input_dataframe[[DATA_STATE_NAME, DATA_RETAIL_NAME, DATA_STORE_NAME, DATA_PARKS_NAME, DATA_TRANSIT_NAME, DATA_WORK_NAME, DATA_HOME_NAME]]

def main():
    mobility_data = pandas.read_csv(DATA_LOC+IMPORT_FILE_NAME)
    mobility_data = process_data(mobility_data)
    vensim_lib.send_to_vensim_csv(dataframe = mobility_data,
        output_filename='google_mobility_data.csv',
        vensim_vars=[DATA_RETAIL_NAME, DATA_STORE_NAME, DATA_PARKS_NAME, DATA_TRANSIT_NAME, DATA_WORK_NAME, DATA_HOME_NAME],
        var_cols=[DATA_STATE_NAME])

if __name__ == "__main__":
    main()