#pragma once
#include<iostream>
#include<string>
using namespace std;

class Numeral_8 {
	int a;
public:
	Numeral_8(int);
	Numeral_8(string);
	Numeral_8(const Numeral_8& obj);
	Numeral_8& operator++();
	Numeral_8& operator+= (int);
	friend Numeral_8 operator+(Numeral_8, Numeral_8);

	int getA();
	int octal2binary();
	string octal2binary2();
};
