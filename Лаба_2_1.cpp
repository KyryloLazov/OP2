#include "Header.h"
using namespace std;

int main() {

    string text_to_write = get_text();

    write_empty_file("input.txt", text_to_write);

    string text = read_input("input.txt");

    printf("\nEntered Text:\n%s\n\n", text.c_str());

    vector<string> sentences = split_sentences(text);

    string NewText = ChangeText(sentences);

    write_file("output.txt", NewText, sentences);

    read_output("output.txt");
}