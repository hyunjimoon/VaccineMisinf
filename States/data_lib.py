from sodapy import Socrata
import pandas
#from census import Census

CENSUS_API_KEY = 'fddd2a794f5d2568070360906e0c1b297a4b7d91'

def get_soda_data(website, source, update=False):
    if update:
        client = Socrata(website, None)
        results =  client.get_all(source)
        results_frame = pandas.DataFrame.from_records(results)
        results_frame.to_csv(source+'.csv')
    else:
        try:
            results_frame = pandas.read_csv(source+'.csv')
        except FileNotFoundError:
            results_frame = get_soda_data(website, source, update=True)
    return results_frame

def get_census_data(census_call, update=False):
    CENSUS_DATAFILE_NAME = 'census_demo.csv'
    if update:
        c = Census(CENSUS_API_KEY)
        census_res = c.acs5.state(census_call, Census.ALL)
        return_dataframe = pandas.DataFrame(census_res)
        return_dataframe.to_csv(CENSUS_DATAFILE_NAME)
    else:
        try:
            return_dataframe = pandas.read_csv(CENSUS_DATAFILE_NAME)
        except FileNotFoundError:
            return_dataframe = get_census_data(census_call, update=True)
    return return_dataframe
