from blp import blp

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

START_DATE = '20170101'
END_DATE   = '20300101'

SECURITY_SUFFIX = ' Index'


query = blp.BlpQuery().start()

security_list = []
for state in bbg_gdp_dict.values():
    new_sec=state+SECURITY_SUFFIX
    print(new_sec)
    security_list.append(new_sec)

results = query.bdh(securities=security_list, fields=['Last_Price'], start_date=START_DATE, end_date=END_DATE)
results.to_csv('bbg_gdp_data.csv')