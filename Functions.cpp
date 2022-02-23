#include "Header.h"

string get_text() {
    cout << "Enter your text. Enter to go to the next line. Ctrl + D - end writing" << endl;
    string text;
    string line;
    int ascii_code = 4;
    while (int(line[0]) != ascii_code) {
        getline(cin, line);
        text += line + '\n';
    }
    text = text.substr(0, text.size() - 3);
    return text;
}

void write_empty_file(const string& file_name, const string& text) {
    ofstream write_file(file_name);
    write_file << text;
    write_file.close();
}

string read_input(const string& file_name) {
    ifstream read_file(file_name);
    string text;
    string line;
    while (getline(read_file, line)) {
        text += line + '\n';
    }
    read_file.close();
    text = text.substr(0, text.size() - 1);
    return text;
}

vector<string> split_sentences(const string& text) {
    vector<string> sentences;
    int prev_pos = 0;
    int counter = 0;

    while (counter <= text.size()) {
        if (text[counter] == '\n' || counter == text.size()) {
            string sentence = text.substr(prev_pos, counter - prev_pos);
            sentences.push_back(sentence);
            prev_pos = counter + 1;
        }
        counter++;
    }

    return sentences;
}

vector<string> split_words(const vector<string>& sentences, int i) {
    vector<string> words;
    int prev_pos = 0;
    int counter = 0;

    while (counter <= sentences[i].size()) {
        if (sentences[i][counter] == ' ' || counter == sentences[i].size()) {
            string word = sentences[i].substr(prev_pos, counter - prev_pos);
            words.push_back(word);
            prev_pos = counter + 1;
        }
        counter++;
    }


    return words;
}

string ChangeText(const vector<string>& sentences) {
    string NewText;
    int counter = 0;
    for (int i = 0; i < sentences.size(); i++) {
        vector<string> words = split_words(sentences, i);
        for (int j = 0; j < words.size(); j++) {
            if (words[j].size() != 2) {
                NewText += words[j] + " ";               
            }
            else {
                counter++;
            }
        }
       NewText += "\n";
    }

    NewText += to_string(counter) + " words was deleted";

    return NewText;
}

void write_file(const string& file_name, const string& NewText, vector<string>& sentences) {
    ofstream write_file(file_name);
    write_file << NewText + "\n";
    write_file.close();
}

void read_output(const string& file_name) {
    ifstream read_output_file(file_name);
    cout << read_output_file.rdbuf() << "\n";
    read_output_file.close();
}