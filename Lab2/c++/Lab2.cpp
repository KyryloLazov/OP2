#include"Header.h"

using namespace std;

int main()
{
    cout << "Work shift starts at 8:00 and end at 18:00" << endl;
    string text_write = capture_text();

    write_new_file("input.txt", text_write);
    string text = read_new_file("input.txt");

    printf("\nText on input:\n%s\n\n", text.c_str());

    int number;
    cout << "Enter number of customers: ";
    cin >> number;

    bool isEnough = count_time(text, number);

    if (isEnough) {
        cout << "There is enough time for " << number << " customers";
    }
    else {
        cout << "There is not enough time for " << number << " customers";
    }
}
