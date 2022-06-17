#include"Classes.h"

using namespace std;

int main() {
	int a;
	cout << "Input N1: ";
	cin >> a;
	string b;
	cout << "Input N2: ";
	cin >> b;

	Numeral_8 N1(a);
	Numeral_8 N2(b);
	Numeral_8 N3(N2);

	cout << "N1.a = " << N1.getA() << endl;
	cout << "N2.a = " << N2.getA() << endl;
	cout << "N3.a = " << N3.getA() << endl;

	++N1;
	cout << "++N1.a = " << N1.getA() << endl;

	int num;
	cout << "Input a number to add to N2: ";
	cin >> num;
	N2 += num;
	cout << "N2.a += "<<num <<" = " << N2.getA() << endl;

	N3 = N1 + N2;
	cout << "N3.a = N1 +N2 = " << N3.getA() << endl;

	cout << "Binary first method: " << N3.octal2binary() << endl;
	cout << "Binary second method: " << N3.octal2binary2() << endl;
	
}