import names_lib
import vensim_lib
import pandas

UNEMPLOYMENT_DATA_FILENAME  = "bbg_unemployment_data"
GDP_DATA_FILENAME           = "bbg_gdp_data"
GDP_OUTPUT_FILENAME         = "GDP_Vensim"
VENSIM_GDP_VAR_NAME         = "Real World GDP Data (Gt)"
GDP_STATE_NAME              = "State"

QUARTER_MIDPOINT = 45   #if data value is less engative than this then we count the observation as relevant
                        #(it's before the simulation but the start time is closer to this entry then the next one)

bbg_unemployment_dict = {
    "AL" : "USUSALA Index",
    "AK" : "USUSAL Index",
    "AZ" : "USUSAZ Index",
    "AR" : "USUSAR Index",
    "CA" : "USUSCALI Index",
    "CO" : "USUSCO Index",
    "CT" : "USUSCONN Index",
    "DE" : "USUSDE Index",
    "FL" : "USUSFLA Index",
    "GA" : "USUSGA Index",
    "HI" : "USUSHA Index",
    "ID" : "USUSID Index",
    "IL" : "USUSILL Index",
    "IN" : "USUSIND Index",
    "IA" : "USUSIA Index",
    "KS" : "USUSKA Index",
    "KY" : "USUSKY Index",
    "LA" : "USUSLA Index",
    "ME" : "USUSME Index",
    "MD" : "USUSMD Index",
    "MA" : "USUSMASS Index",
    "MI" : "USUSMICH Index",
    "MN" : "USUSMINN Index",
    "MS" : "USUSMISS Index",
    "MO" : "USUSMO Index",
    "MT" : "USUSMT Index",
    "NE" : "USUSNC Index",
    "NV" : "USUSND Index",
    "NH" : "USUSNEB Index",
    "NJ" : "USUSNV Index",
    "NM" : "USUSNH Index",
    "NY" : "USUSNJ Index",
    "NC" : "USUSNM Index",
    "ND" : "USUSNY Index",
    "OH" : "USUSOHIO Index",
    "OK" : "USUSOK Index",
    "OR" : "USUSOREG Index",
    "PA" : "USUSPENN Index",
    "PR" : "USUSPR Index",
    "RI" : "USUSRI Index",
    "SC" : "USUSSC Index",
    "SD" : "USUSSD Index",
    "TN" : "USUSTENN Index",
    "TX" : "USUSTX Index",
    "UT" : "USUSUTAH Index",
    "VT" : "USUSVT Index",
    "VA" : "USUSVI Index",
    "WA" : "USUSWV Index",
    "WV" : "USUSWASH Index",
    "DC" : "USUSDC Index",
    "WI" : "USUSWI Index",
    "WY" : "USUSWY Index"
}
bbg_gdp_dict = {
    "AL" : "RGDPREAL",
    "AK" : "RGDPREAA",
    "AZ" : "RGDPREAZ",
    "AR" : "RGDPREAK",
    "CA" : "RGDPRECA",
    "CO" : "RGDPRECO",
    "CT" : "RGDPRECN",
    "DE" : "RGDPREDE",
    "FL" : "RGDPREFL",
    "GA" : "RGDPREGA",
    "HI" : "RGDPREHA",
    "ID" : "RGDPREID",
    "IL" : "RGDPREIL",
    "IN" : "RGDPREIN",
    "IA" : "RGDPREIW",
    "KS" : "RGDPREKA",
    "KY" : "RGDPREKY",
    "LA" : "RGDPRELA",
    "ME" : "RGDPREMA",
    "MD" : "RGDPREMD",
    "MA" : "RGDPREMT",
    "MI" : "RGDPREMI",
    "MN" : "RGDPREMN",
    "MS" : "RGDPREMS",
    "MO" : "RGDPREMO",
    "MT" : "RGDPREMR",
    "NE" : "RGDPRENB",
    "NV" : "RGDPRENV",
    "NH" : "RGDPRENH",
    "NJ" : "RGDPRENJ",
    "NM" : "RGDPRENM",
    "NY" : "RGDPRENY",
    "NC" : "RGDPRENC",
    "ND" : "RGDPREND",
    "OH" : "RGDPREOH",
    "OK" : "RGDPREOK",
    "OR" : "RGDPREOR",
    "PA" : "RGDPREPN",
    "RI" : "RGDPRERI",
    "SC" : "RGDPRESC",
    "SD" : "RGDPRESD",
    "TN" : "RGDPRETN",
    "TX" : "RGDPRETX",
    "UT" : "RGDPREUT",
    "VT" : "RGDPREVM",
    "VA" : "RGDPREVI",
    "WA" : "RGDPREWA",
    "WV" : "RGDPREWV",
    "WI" : "RGDPREWI",
    "WY" : "RGDPREWY",
    "DC" : "RGDPREDC"
}

def read_and_format_bbg_data(filename, name_dict):
    dataframe = pandas.read_csv(filename+'.csv')
    dataframe.rename(columns={v : k for (k, v) in name_dict.items()}, inplace=True)
    dataframe.rename(columns=names_lib.code_to_state_dict, inplace=True)
    dataframe.rename(columns={'Date' : 'Time'}, inplace=True)
    dataframe['Time'] = vensim_lib.normalize_date(dataframe['Time'])
    dataframe.set_index('Time', inplace=True)
    return dataframe

def clean_gdp_data(gdp_dataframe, post_pandemic=True):
    gdp_dataframe = gdp_dataframe[gdp_dataframe.index.notnull()]
    if(post_pandemic): #get data only after pandemic start
        gdp_dataframe = gdp_dataframe[gdp_dataframe.index> -QUARTER_MIDPOINT]
        gdp_dataframe.sort_index(inplace=True)
        temp_index=gdp_dataframe.index.to_list()
        if temp_index[0] < 0: #make initial entry 0 instead of negative
            temp_index[0] = 0
        gdp_dataframe.index = temp_index
    else: #get data before pandemic
        gdp_dataframe = gdp_dataframe[gdp_dataframe.index < QUARTER_MIDPOINT]
        gdp_dataframe.sort_index(inplace=True)
        gdp_dataframe.index=gdp_dataframe.index-gdp_dataframe.index[0]
    gdp_dataframe = gdp_dataframe.unstack(1)
    gdp_dataframe.index.names=[GDP_STATE_NAME, vensim_lib.VENSIM_TIME_PARAM]
    gdp_dataframe.name = VENSIM_GDP_VAR_NAME
    gdp_dataframe = pandas.DataFrame(gdp_dataframe)
    gdp_dataframe = gdp_dataframe.reset_index().set_index('Time')
    return gdp_dataframe


def main(post_pandemic_analysis = True):
    #unemployment_data = read_and_format_bbg_data(UNEMPLOYMENT_DATA_FILENAME, bbg_unemployment_dict)
    gdp_data = read_and_format_bbg_data(GDP_DATA_FILENAME, bbg_gdp_dict)
    gdp_data = clean_gdp_data(gdp_data, post_pandemic=post_pandemic_analysis)
    if post_pandemic_analysis:
        filename = GDP_OUTPUT_FILENAME
    else:
        filename = GDP_OUTPUT_FILENAME+'_2'
    vensim_lib.send_to_vensim_csv(
        dataframe       =   gdp_data,
        output_filename =   vensim_lib.VENSIM_DATA_LOC+filename+'.csv',
        vensim_vars     =   [VENSIM_GDP_VAR_NAME],
        var_cols        =   [GDP_STATE_NAME]
    )
    vensim_lib.create_vdf_from_csv(filename)
    vensim_lib.copy_csv_to_model(filename)

if __name__ =="__main__":
    main()