#include"Header.h"
using namespace std;

vector<Function> CreateArray(int number) {
	vector<Function> functions;
	float a, b;
	for (int i = 0; i < number; i++) {
		cout << "Input a :";
		cin >> a;
		cout << "Input b :";
		cin >> b;
		Function obj(a, b);
		functions.push_back(obj);
	}
	return functions;
}

int GetBiggestValue(vector<Function> functions, int x) {
	int maxnumber = 0;
	float maxvalue = 0;
	for (int i = 0; i < functions.size(); i++) {
		if (functions[i].GetValue(x) > maxvalue) {
			cout << functions[i].GetValue(x) << endl;
			maxvalue = functions[i].GetValue(x);
			maxnumber = i;
		}
	}
	return maxnumber;
}