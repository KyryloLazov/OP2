#include"Header.h"

using namespace std;

string capture_text() {
	string text;
	string line;

	int acsii_code = 4;
	int counter = 0;

	bool isOverlap = false;
	bool isCorrect = true;

	cout << "Enter breaks(H:mm-H:mm). Ctrl + D - end writing"<<endl;
	while (int(line[0] != acsii_code)) {
		getline(cin, line);
		isCorrect = check_Input(line);
		if (isCorrect) {
			if (counter == 0) {
				text += line + '\n';
				counter++;
			}
			else if (counter > 0 and int(line[0]) != 4) {
				isOverlap = check_breaks(line, text);
				if (isOverlap) {
					cout << "This break overlaps with another!" << endl;
				}
				else {
					text += line + '\n';
				}
			}
		}
		else {
			cout << "Wrong Input!" << endl;
		}
	}
	text = text.substr(0, text.size() - 1);
	return text;
}

bool check_Input(const string& line) {
	bool isCorrect = true;
	if (int(line[0]) != 4) {
		vector<string> brake = split_breaks(line);	
		if (stoi(brake[0]) <= 8 && stoi(brake[1]) == 0 || stoi(brake[0]) >= 18 || stoi(brake[2]) >= 18) {
			isCorrect = false;
		}
		if (stoi(brake[0]) > stoi(brake[2])) {
			isCorrect = false;
		}
	}
	return isCorrect;
}

bool check_breaks(const string& line, const string& text) {
	vector<string> breaks = split_sentences(text);
	bool isOverlap = false;
	int i = 0;
	while (isOverlap == false and i < breaks.size() - 1) {
		vector<string> first_brake = split_breaks(breaks[i]);
		vector<string> second_brake = split_breaks(line);
		if (stoi(second_brake[0]) < stoi(first_brake[0]) and stoi(second_brake[2]) > stoi(first_brake[2]) || stoi(second_brake[0]) > stoi(first_brake[0]) and stoi(second_brake[0]) < stoi(first_brake[2])) {
			isOverlap = true;
		}
		if (stoi(second_brake[2]) == stoi(first_brake[0]) && stoi(second_brake[3]) >= stoi(first_brake[1])) {
			isOverlap = true;
		}
		if (stoi(second_brake[2]) == stoi(first_brake[2]) && stoi(second_brake[3]) <= stoi(first_brake[3])) {
			isOverlap = true;
		}
		if (stoi(second_brake[0]) == stoi(first_brake[2]) && stoi(second_brake[1]) <= stoi(first_brake[3])) {
			isOverlap = true;
		}
		i++;
	}
	return isOverlap;
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

vector<string> split_breaks(const string& text) {
	vector<string> breaks;
	int prev_pos = 0;
	int counter = 0;
	while (counter <= text.size()) {
		if (text[counter] == '\n' || text[counter] == ':' || text[counter] == '-' || counter == text.size()) {
			string time = text.substr(prev_pos, counter - prev_pos);
			breaks.push_back(time);
			prev_pos = counter + 1;
		}
		counter++;
	}
	return breaks;
}

void write_new_file(const string& file_name, const string& text) {
	ofstream write_file(file_name, ios::binary);
	write_file << text;
	write_file.close();
}

string read_new_file(const string& file_name) {
	ifstream open_file(file_name, ios::binary);
	string text;
	while (!open_file.eof()) {
		text += open_file.get();
	}
	open_file.close();
	text = text.substr(0, text.size() - 1);

	return text;
}


bool count_time(const string& text, int number) {
	int Overalltime = 600;
	vector<string> sentences = split_sentences(text);
	int minutes = 0;
	int hours = 0;
	int final_time;
	bool isEnough = false;

	for (int i = 0; i < sentences.size(); i++) {
		vector<string> brake = split_breaks(sentences[i]);
		if (stoi(brake[3]) >= stoi(brake[1])) {
			minutes += -(stoi(brake[1]) - stoi(brake[3]));
		}
		else if(stoi(brake[1]) > stoi(brake[3])) {
			hours--;
			minutes += 60 - (stoi(brake[1]) - stoi(brake[3]));;
		}
		hours += stoi(brake[2]) - stoi(brake[0]);
		
		if (minutes >= 60) {
			minutes -= 60;
			hours++;
		}
	}
	cout << "hours: " << hours << endl;
	cout << "minutes: " << minutes << endl;

	final_time = hours * 60 + minutes;
	cout << "Final time: " << final_time << endl;
	
	int Reqtime = number * 15;
	cout << "Required time: " << Reqtime << endl;

	if (Overalltime - final_time >= Reqtime) {
		isEnough = true;
	}
	return isEnough;
}