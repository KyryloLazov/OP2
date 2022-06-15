#include"Classes.h"
#include<iostream>
#include<math.h>
using namespace std;

Function::Function(float c, float d) {
	this->a = c;
	this->b = d;
}

float Function::GetValue(float x) {
	float value = sin(a * x + b);
	return value;
}