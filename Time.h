#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Time
{
private:
	byte hours;
	byte minutes;
public:
	Time();
	Time(byte h, byte m);
	Time(const Time& k);

	void plusM(int x);
	friend ostream& operator<<(ostream& os, const Time& t);

	Time operator++(int);

	Time& operator--();

	explicit operator short int() const;

	operator bool() const;

	Time operator+(const Time& other);

	Time operator-(const Time& other);
};


