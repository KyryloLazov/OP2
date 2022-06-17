#include"Classes.h"
using namespace std;

Numeral_8::Numeral_8(int b) {
    int i = 1;
    int octal = 0;
    while (b != 0) {      
        octal += (b % 8) * i;
        b /=  8;
        i *= 10;
    }
    a = octal;
};

Numeral_8::Numeral_8(string line) {
    int b = stoi(line);
    int octal = 0;
    int i = 1;
    while (b != 0) {
        octal += (b % 8) * i;
        b /= 8;
        i *= 10;
    }
    a = octal;
}

Numeral_8::Numeral_8(const Numeral_8& obj) {
    a = obj.a;
}

Numeral_8& Numeral_8::operator++() {
    a++;
    if (a % 10 > 7) {
        a += 2;
    }
    if (a / 10 > 7 and a/10 < 10) {
        a += 20;
    }
    return *this;
}

Numeral_8& Numeral_8::operator+=(int b) {
    a += b;
    if (a % 10 > 7) {
        a += 2;
    }
    if (a / 10 > 7 and a / 10 < 10) {
        a += 20;
    }
    return *this;
}

Numeral_8 operator+(Numeral_8 x, Numeral_8 y) {
    Numeral_8 tmp(0);
    int a = x.getA();
    int b = y.getA();
    int carry = 0, digit = 0, mult = 1;
    while (a != 0 or b != 0 or carry != 0) {
        digit = a % 10 + b % 10 + carry;

        if (digit > 7)
        {
            carry = 1;
            digit %= 8;
        }
        else
            carry = 0;

        tmp.a += digit * mult;
        mult *= 10;

        a /= 10;
        b /= 10;
    }
    return tmp;
}

int Numeral_8::getA() {
    return a;
}

int Numeral_8::octal2binary() {
    int octal = a;
    int decimalNum = 0, binaryNum = 0, count = 0;

    while (octal != 0) {
        decimalNum += (octal % 10) * pow(8, count);
        ++count;
        octal /= 10;
    }

    count = 1;
    while (decimalNum != 0) {
        binaryNum += (decimalNum % 2) * count;
        decimalNum /= 2;
        count *= 10;
    }
    return binaryNum;
}

string Numeral_8::octal2binary2() {
    int octal = a;
    int decimalNum = 0, binaryNum = 0, count = 0;
    while (octal != 0) {
        decimalNum += (octal % 10) * pow(8, count);
        ++count;
        octal /= 10;
    }

    int num = 0, digit = decimalNum;
    while (digit != 0) {
        digit /= 2;
        num++;
    }

    int* array = new int[num];
    for (int i = 0; i < num; i++) {
        array[i] = pow(2, i);
    }

    string binary;
    for (int j = num - 1; j >= 0; j--) {
        if (decimalNum >= array[j]) {
            decimalNum -= array[j];
            binary += "1";
        }
        else {
            binary += "0";
        }
    }
    return binary;
}