from operator import truediv
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
bbg_gdp_dict_reverse = {v : k for k, v in bbg_gdp_dict.items()}

BBG_DATE = 'date'
BBG_SECURITY = 'security'
BBG_PRICE = 'Last_Price'


def read_and_format_bbg_data(filename, name_dict):
    dataframe = pandas.read_csv(filename+'.csv')
    dataframe=dataframe[[BBG_DATE, BBG_SECURITY, BBG_PRICE]]
    dataframe[BBG_SECURITY] = [x[:8] for x in dataframe[BBG_SECURITY]]
    dataframe[BBG_SECURITY] = [bbg_gdp_dict_reverse[x] for x in dataframe[BBG_SECURITY]]
    dataframe[BBG_DATE] = vensim_lib.normalize_date(dataframe[BBG_DATE])
    dataframe.rename(columns={BBG_DATE : vensim_lib.VENSIM_TIME_PARAM, BBG_PRICE : VENSIM_GDP_VAR_NAME}, inplace=True)
    dataframe.set_index([vensim_lib.VENSIM_TIME_PARAM, BBG_SECURITY], inplace=True)
    return dataframe

def clean_gdp_data(gdp_dataframe, post_pandemic=True):
    prev_index = gdp_dataframe.index.names
    gdp_dataframe.reset_index(inplace=True)
    gdp_dataframe.set_index(vensim_lib.VENSIM_TIME_PARAM, inplace=True)
    if(post_pandemic): #get data only after pandemic start
        gdp_dataframe = gdp_dataframe[gdp_dataframe.index > -QUARTER_MIDPOINT]
        gdp_dataframe.sort_index(inplace=True)
        temp_index=gdp_dataframe.index.to_list()
        temp_index = [0 if i < 0 else i for i in temp_index]
        gdp_dataframe.index = temp_index
        gdp_dataframe.index.name = vensim_lib.VENSIM_TIME_PARAM
    else: #get data before pandemic
        gdp_dataframe = gdp_dataframe[gdp_dataframe.index < QUARTER_MIDPOINT]
        gdp_dataframe.sort_index(inplace=True)
        gdp_dataframe.index=gdp_dataframe.index-gdp_dataframe.index[0]
    gdp_dataframe.reset_index(inplace=True)
    gdp_dataframe.set_index(prev_index, inplace=True)
    return gdp_dataframe


def main(post_pandemic_analysis = True):
    #unemployment_data = read_and_format_bbg_data(UNEMPLOYMENT_DATA_FILENAME, bbg_unemployment_dict)
    gdp_data = read_and_format_bbg_data(GDP_DATA_FILENAME, bbg_gdp_dict)
    gdp_data = clean_gdp_data(gdp_data)
    if post_pandemic_analysis:
        filename = GDP_OUTPUT_FILENAME
    else:
        filename = GDP_OUTPUT_FILENAME+'_2'
    vensim_lib.send_to_vensim_csv2(
        dataframe       =   gdp_data,
        output_filename =   filename,
        vensim_vars     =   [VENSIM_GDP_VAR_NAME]
    )
    vensim_lib.create_vdf_from_csv(filename)
    vensim_lib.copy_csv_to_model(filename)

if __name__ =="__main__":
    main()