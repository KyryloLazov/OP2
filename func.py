def get_text():
    print('Enter your text. Enter to go to the next line. Ctrl + D - end writing')

    import sys
    text = sys.stdin.read()

    text = text[:len(text) - 1]

    return text


def write_empty_file(file_name: str, text: str):

    write_file = open(file_name, 'wt')
    write_file.write(text)
    write_file.close()


def ChangeText(text: str):
    NewText = ""
    count = 0
    sentences = text.split("\n")
    for i in range(len(sentences)):
        sentence = sentences[i]
        words = sentence.split(" ")
        for j in range(len(words)):
            if len(words[j]) != 2:
                NewText += words[j] + " "
            else:
                count += 1
        NewText += "\n"
    NewText += str(count) + " words was removed"
    return NewText

def write_to_file(file_name: str, NewText):
    write_file = open(file_name, 'wt')

    write_file.write(NewText)

    write_file.close()


def read_file(file_name: str):
    read_input_file = open(file_name, 'rt')
    text = read_input_file.read()
    read_input_file.close()

    return text