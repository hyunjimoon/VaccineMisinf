import names_lib

min_list = [
    180000,
    47000,
    300000,
    100000,
    2400000,
    320000,
    220000,
    58000,
    880000,
    500000,
    66000,
    69000,
    690000,
    300000,
    160000,
    140000,
    170000,
    200000,
    55000,
    330000,
    460000,
    400000,
    300000,
    92000,
    260000,
    43000,
    110000,
    120000,
    69000,
    490000,
    88000,
    1300000,
    460000,
    52000,
    540000,
    180000,
    200000,
    630000,
    47000,
    190000,
    44000,
    280000,
    1600000,
    160000,
    26000,
    440000,
    500000,
    65000,
    270000,
    34000,
    110000
]
max_list = [
    210000,
    54000,
    350000,
    130000,
    3000000,
    380000,
    260000,
    66000,
    1100000,
    590000,
    80000,
    80000,
    790000,
    360000,
    190000,
    170000,
    200000,
    240000,
    63000,
    380000,
    550000,
    490000,
    360000,
    110000,
    300000,
    50000,
    130000,
    160000,
    84000,
    580000,
    97000,
    1600000,
    550000,
    58000,
    630000,
    210000,
    230000,
    730000,
    56000,
    230000,
    50000,
    360000,
    1900000,
    190000,
    31000,
    510000,
    590000,
    73000,
    310000,
    40000,
    130000
]

with open('graphs', 'w') as graph_file:
    counter=0
    for abbr, name in names_lib.code_to_state_dict.items():
        graph_file.write(":GRAPH GDP_"+abbr+"\n")
        graph_file.write(":TITLE "+name+"\n")
        graph_file.write(":X-AXIS Time\n")
        graph_file.write(":Y-DIV 5\n")
        graph_file.write(":SCALE\n")
        graph_file.write(":VAR Predicted GDP\n")
        graph_file.write(":VAR Predicted GDP["+name+"]|Model GDP\n")
        graph_file.write(":VAR \"Real World GDP Data (Gt)\"["+name+"]|Actual GDP\n")
        graph_file.write(":Y-MIN "+str(min_list[counter])+"\n")
        graph_file.write(":Y-MAX "+str(max_list[counter])+"\n\n")
        counter+=1
        if counter>len(min_list)-1 or counter>len(max_list)-1:
            break