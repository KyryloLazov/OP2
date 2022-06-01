def capture_text():
    print('Enter breaks(H:mm-H:mm). shift + 6 - end writing')
    isCorrect = True
    isOverlap = False
    line = " "
    text = ""
    counter = 0
    while(ord(line[0]) != 94):
        line = input()
        isCorrect = check_Input(line)
        if(isCorrect):
            if(counter == 0):
                text = text + line + '\n'
                counter = counter + 1
            elif(counter > 0 and ord(line[0]) != 94):
                isOverlap = check_breakes(line, text)
                if(isOverlap):
                    print("This break overlaps with another!")
                else:
                    text = text + line + '\n'
        else:
            print("Wrong input")
    text = text[:len(text) - 1]

    return text

def check_Input(line: str):
    isCorrect = True
    if(ord(line[0]) != 94):
        brakes = split_breaks(line)
        if(int(brakes[0][0]) <= 8 and int(brakes[0][1]) == 0 or int(brakes[0][0]) >=18 or int(brakes[1][0]) >=18):
            isCorrect = False
        if(int(brakes[0][0]) > int(brakes[1][0])):
            isCorrect = False
    return isCorrect

def check_breakes(line:str, text:str):
    breaks = text.split('\n')
    isOverlap = False
    i = 0
    while(isOverlap == False and i < len(breaks) - 1):
        first_break = split_breaks(breaks[i])
        second_break = split_breaks(line)
        if(int(second_break[0][0]) < int(first_break[0][0]) and int(second_break[1][0]) > int(first_break[0][0]) or int(second_break[0][0]) > int(first_break[0][0]) and int(second_break[0][0]) < int(first_break[1][0])):
            isOverlap = True
        if(int(second_break[1][0]) == int(first_break[0][0]) and int(second_break[1][1]) >= int(first_break[0][1])):
            isOverlap = True
        if(int(second_break[1][0]) == int(first_break[1][0]) and int(second_break[1][1]) <= int(first_break[1][1])):
            isOverlap = True
        if (int(second_break[0][0]) == int(first_break[1][0]) and int(second_break[0][1]) <= int(first_break[1][1])):
            isOverlap = True
        i = i + 1
    return isOverlap

def split_breaks(line: str):
    brakes = []
    brake = line.split('-')
    for i in range(len(brake)):
        brake_array = brake[i].split(':')
        brakes.append(brake_array)
    return brakes

def write_empty_file(file_name: str, text: str):
    write_file = open(file_name, 'wt')
    write_file.write(text)
    write_file.close()

def read_file(file_name: str):
    read_input_file = open(file_name, 'rt')
    text = read_input_file.read()
    read_input_file.close()

    return text

def count_time(text: str, number: int):
    Overalltime = 600
    breaks = text.split('\n')
    minutes = 0
    hours = 0
    isEnough = False
    i = 0
    while( i < len(breaks)):
        brake = split_breaks(breaks[i])
        if(int(brake[1][1]) >= int(brake[0][1])):
            minutes += -(int(brake[0][1]) - int(brake[1][1]))
        elif(int(brake[0][1]) > int(brake[1][1])):
            hours = hours - 1
            minutes += 60 - (int(brake[0][1]) - int(brake[1][1]))
        hours += int(brake[1][0]) - int(brake[0][0])
        if(minutes >= 60):
            minutes -= 60
            hours += 1
        i += 1
    print("hours", hours)
    print("minutes", minutes)
    final_time = hours * 60 + minutes
    print("final time", final_time)
    Req_time = number * 15
    if(Overalltime - final_time >= Req_time):
        isEnough = True
    return isEnough