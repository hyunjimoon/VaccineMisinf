from cProfile import label
import names_lib
from state_demo import DATASET_TOTAL_DEATHS_NAME
import vensim_lib
import pandas

GOOGLE_DATA_CSV     =   "https://www.gstatic.com/covid19/mobility/Global_Mobility_Report.csv"
LOCAL_DATA_CSV      =   "google_mobility_data.csv"
VENSIM_DATA_FILE    =   "states_workplace_mobility"

DATA_COUNTRY_CODE   =   "country_region_code"
DATA_COUNTRY        =   "country_region"
DATA_RGN_1          =   "sub_region_1"
DATA_RGN_2          =   "sub_region_2"
DATA_METRO          =   "metro_area"
DATA_ISO_CODE       =   "iso_3166_2_code"
DATA_FIPS_CODE      =   "census_fips_code"
DATA_PLACE_ID       =   "place_id"
DATA_DATE           =   "date"

RESIDENTIAL_VAR =   "residential_percent_change_from_baseline"
WORKPLACE_VAR   =   "workplaces_percent_change_from_baseline"
TRANSIT_VAR     =   "transit_stations_percent_change_from_baseline"
PARKS_VAR       =   "parks_percent_change_from_baseline"
STORE_VAR       =   "grocery_and_pharmacy_percent_change_from_baseline"

VENSIM_WORK_VAR =   "Impact of Covid Fears on Workplace Abesnce"

def update_mobility_data(source, dest):
    mobility_df = pandas.read_csv(source,low_memory=False)
    mobility_df = mobility_df[mobility_df[DATA_COUNTRY] == 'United States']
    mobility_df = mobility_df[mobility_df[DATA_RGN_1].notna()]
    mobility_df = mobility_df[mobility_df[DATA_RGN_2].isna()]
    mobility_df.to_csv(dest, index=False)
    return mobility_df

def clean_mobility_data(mobility_data_src):
    mobility_data_src.drop(columns=[DATA_COUNTRY_CODE, DATA_COUNTRY, DATA_RGN_2, DATA_METRO, DATA_ISO_CODE, DATA_FIPS_CODE,DATA_PLACE_ID], inplace=True)
    mobility_data_src.rename(
        columns={
            DATA_DATE       :   vensim_lib.VENSIM_TIME_PARAM,
            WORKPLACE_VAR   :   VENSIM_WORK_VAR
        },
    inplace=True)
    mobility_data_src[vensim_lib.VENSIM_TIME_PARAM] = vensim_lib.normalize_date(mobility_data_src[vensim_lib.VENSIM_TIME_PARAM])
    mobility_data_src.set_index(vensim_lib.VENSIM_TIME_PARAM, inplace=True)
    return mobility_data_src

def scale_mobility_data(dataframe, scaling_factor):
    working_dataframe = dataframe.copy()
    for column in working_dataframe.columns:
        if column != 'sub_region_1':
            working_dataframe[column] = working_dataframe[column]/scaling_factor
    return working_dataframe
    


def main(update_data=False):
    if update_data:
        mobility_df = update_mobility_data(GOOGLE_DATA_CSV, LOCAL_DATA_CSV)
    mobility_df = pandas.read_csv(LOCAL_DATA_CSV)
    mobility_df = clean_mobility_data(mobility_df)
    mobility_df = scale_mobility_data(mobility_df, 100)
    vensim_lib.send_to_vensim_csv(
        dataframe       =   mobility_df,
        output_filename =   vensim_lib.VENSIM_DATA_LOC+VENSIM_DATA_FILE+'.csv',
        vensim_vars     =   [VENSIM_WORK_VAR],
        var_cols        =   [DATA_RGN_1]
    )
    vensim_lib.create_vdf_from_csv(VENSIM_DATA_FILE)


if __name__ == "__main__":
    #main(update_data=True)
    main()