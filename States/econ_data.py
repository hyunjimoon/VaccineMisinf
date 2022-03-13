import names_lib
import vensim_lib
import pandas

UNEMPLOYMENT_DATA_FILENAME = "bbg_unemployment_data"
GDP_DATA_FILENAME = "bbg_gdp_data"

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
    "AL" : "RGDPREAL Index",
    "AK" : "RGDPREAA Index",
    "AZ" : "RGDPRECA Index",
    "AR" : "RGDPREAZ Index",
    "CA" : "RGDPRECO Index",
    "CO" : "RGDPREMA Index",
    "CT" : "RGDPREDC Index",
    "DC" : "RGDPREAK Index",
    "DE" : "RGDPRECN Index",
    "FL" : "RGDPREDE Index",
    "GA" : "RGDPREFL Index",
    "HI" : "RGDPREGA Index",
    "ID" : "RGDPREHA Index",
    "IL" : "RGDPREID Index",
    "IN" : "RGDPREIL Index",
    "IA" : "RGDPREIN Index",
    "KS" : "RGDPREIW Index",
    "KY" : "RGDPREKA Index",
    "LA" : "RGDPREKY Index",
    "ME" : "RGDPRELA Index",
    "MD" : "RGDPREMD Index",
    "MA" : "RGDPREMI Index",
    "MI" : "RGDPREMN Index",
    "MN" : "RGDPREMO Index",
    "MS" : "RGDPREMR Index",
    "MO" : "RGDPREMS Index",
    "MT" : "RGDPREMT Index",
    "NE" : "RGDPRENB Index",
    "NV" : "RGDPRENC Index",
    "NH" : "RGDPREND Index",
    "NJ" : "RGDPRENH Index",
    "NM" : "RGDPRENJ Index",
    "NY" : "RGDPRENM Index",
    "NC" : "RGDPRENV Index",
    "ND" : "RGDPRENY Index",
    "OH" : "RGDPREOH Index",
    "OK" : "RGDPREOK Index",
    "OR" : "RGDPREOR Index",
    "PA" : "RGDPREPN Index",
    "RI" : "RGDPRERI Index",
    "SC" : "RGDPRESC Index",
    "SD" : "RGDPRESD Index",
    "TN" : "RGDPRETN Index",
    "TX" : "RGDPRETX Index",
    "UT" : "RGDPREUT Index",
    "VT" : "RGDPREVI Index",
    "VA" : "RGDPREVM Index",
    "WA" : "RGDPREWA Index",
    "WV" : "RGDPREWI Index",
    "WI" : "RGDPREWV Index",
    "WY" : "RGDPREWY Index",
}

def read_and_format_bbg_data(filename, name_dict):
    dataframe = pandas.read_csv(filename+'.csv')
    dataframe.rename(columns={v : k for k, v in name_dict.items()}, inplace=True)
    dataframe.rename(columns={'Unnamed: 0' : 'Time'}, inplace=True)
    dataframe['Time'] = vensim_lib.normalize_date(dataframe['Time'])
    dataframe.set_index('Time', inplace=True)
    return dataframe


def main():
    unemployment_data = read_and_format_bbg_data(UNEMPLOYMENT_DATA_FILENAME, bbg_unemployment_dict)
    gdp_data = read_and_format_bbg_data(GDP_DATA_FILENAME, bbg_gdp_dict)
    print(gdp_data)

if __name__ =="__main__":
    main()