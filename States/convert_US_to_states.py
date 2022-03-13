from os import name
import names_lib
import re
import pandas
import os
import vensim_lib

IN_FILE_NAME_INITIALS = "base68-OptimVacPrior.out"
OUT_FILE_NAME_INITIALS = "base69-OptimVacPrior.out"
IN_FILE_NAME_TESTS = "CovidModelInputs - TestData.csv"
OUT_FILE_NAME_TESTS = "CovidModelInputs - TestDataStates.csv"
IN_FILE_NAME_VAX_DEATH = "USVaccinatedDeathData.csv"
OUT_FILE_NAME_VAX_DEATH = "USVaccinatedDeathDataStates.csv"
COUNTRY_NAME = 'USA'

def process_line(line):
    line_parts = re.split('\[|\]', line)
    if 1==len(line_parts): #if there was no split
        return[line]
    else:
        if COUNTRY_NAME == line_parts[1]: #if subscript is of interest
            state_lines = []
            for state in names_lib.state_names.values():
                state_lines.append(f'{line_parts[0]}[{state}]{line_parts[2]}')#assumes line is of type '___ [ var] ____'
            return state_lines
        elif line_parts[1] in names_lib.country_list:
            return None
        else:
            return[line]

def convert_text_file(in_name, out_name):
    with open(in_name, 'r') as in_file:
        with open(out_name, 'w+') as out_file:
            for line in in_file:
                try:
                    out_file.writelines(process_line(line))
                except(TypeError):#not iterable = returned None
                    continue

def pre_process_csv_file(file_name):
    with open(file_name, 'r') as in_file:
        with open('temp', 'w') as out_file:
            for line in in_file:
                line_parts = re.split('\[|\]', line)
                if 1==len(line_parts): #if there was no split
                    pass
                else:
                    line_parts[1] = line_parts[1].split(',')
                    line_parts[1] = ';'.join(line_parts[1])
                    line = f'{line_parts[0]}[{line_parts[1]}]{line_parts[2]}'
                out_file.write(line)
    os.remove(file_name)
    os.rename('temp',file_name)

                

def parse_row_name(row_name):
    parts = row_name.split('[')
    parts[-1]=parts[-1][:-1] #removes ]
    parts[-1]=parts[-1].split(';')
    return parts

def convert_csv(in_name, out_name): #removes all non USA countries from csv file and breaks USA into states with identical data
    pre_process_csv_file(in_name)
    input_data = pandas.read_csv(in_name)
    output_data = pandas.DataFrame(dict(zip(input_data.columns,input_data.columns)),index=[0])
    for index, row in input_data.iterrows():
        name_parts=parse_row_name(row['Time'])
        row['Time'] = name_parts[0]
        if 1==len(name_parts[1]):#only state data
            row['State'] = name_parts[1][0]
        elif 2==len(name_parts[1]):#state data + vx
            row['State'] = name_parts[1][0]
            row['Vx'] = name_parts[1][1]
        else:
            Exception(ValueError)
        if COUNTRY_NAME == row['State']:
            state_list = pandas.DataFrame()
            for state in names_lib.state_names.values():
                row['State'] = state
                state_list = state_list.append(row)
        elif row['State'] in names_lib.country_list:
            continue
        output_data = pandas.concat([output_data, state_list])
    vensim_lib.relocate_columns(output_data)
    output_data.to_csv(out_name, header=False, index=False)


def main():
    convert_text_file(IN_FILE_NAME_INITIALS, OUT_FILE_NAME_INITIALS)
    convert_csv(IN_FILE_NAME_TESTS, OUT_FILE_NAME_TESTS)
    convert_csv(IN_FILE_NAME_VAX_DEATH, OUT_FILE_NAME_VAX_DEATH)
    
if __name__ == "__main__":
    main()