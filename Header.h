#include <iostream>
#include <fstream>
#include<string>
#include <vector>

using namespace std;

string get_text();

string read_input(const string& file_name);

vector<string> split_sentences(const string& text);

string ChangeText(const vector<string>& sentences);

void write_file(const string& file_name, const string& NewText, vector<string>& sentences);

void write_empty_file(const string& file_name, const string& text);

void read_output(const string& file_name);