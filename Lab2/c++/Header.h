#pragma once
#include <iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

string capture_text();
bool check_Input(const string& line);
bool check_breaks(const string& line, const string& text);
vector<string> split_sentences(const string& text);
vector<string> split_breaks(const string& text);
void write_new_file(const string& file_name, const string& text);
string read_new_file(const string& file_name);
bool count_time(const string& text, int number);