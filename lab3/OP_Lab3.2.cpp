#include"Header.h"
using namespace std;

int main()
{
	int number, x;
	cout << "Function sin(ax + b)" << endl;
	cout << "Input amount of functions: ";
	cin >> number;
	vector<Function> functions;
	functions = CreateArray(number);

	cout << "Input x: ";
	cin >> x;
	int maxnumber = GetBiggestValue(functions, x);
	cout << "The function number " << maxnumber << " has the biggest value in point x";
}
