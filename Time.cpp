#include "Time.h"
#include <iostream>
#include <windows.h>
using namespace std;


Time::Time() : hours(0), minutes(0) {}
Time::Time(byte h, byte m) : hours(h), minutes(m) {}
Time::Time(const Time& k) : hours(k.hours), minutes(k.minutes) {}
void Time::plusM(int x)
{
	int c;
	minutes += x;
	if (minutes >= 60)
	{
		c = minutes / 60;
		minutes -= (c * 60);
		hours += c;
	}
}

ostream& operator<<(ostream& os, const Time& t)
{		os << (int)t.hours << "ч " << (int)t.minutes << "мин" << endl;
	return os;
}
	Time Time::operator++(int)
{
	Time temp = *this;
	*this = Time(hours, minutes += 1);
	int c;
	if (minutes >= 60)
	{
		c = minutes / 60;
		minutes -= (c * 60);
		hours += c;
	}
	return temp;
}
Time& Time::operator--()
{
	Time temp(hours, minutes -= 1);
	*this = temp;
	if (minutes >= 60)
	{
		minutes = 59;
		hours -= 1;
	}
	return *this;
}
Time::operator short int() const
{		
	return hours;
}
Time::operator bool() const
{
	return (hours != 0 || minutes != 0);
}

Time Time::operator+(const Time& other)
{
	int c;
	Time temp;
	temp.hours = this->hours;
	temp.minutes = this->minutes + other.minutes;
	if (temp.minutes >= 60)
	{
		c = temp.minutes / 60;
		temp.minutes -= (c * 60);
		temp.hours += c;
	}
	*this = temp;
	return temp;
}

Time Time::operator-(const Time& other)
{
	Time temp;
	temp.hours = this->hours;
	temp.minutes = this->minutes - other.minutes;
	if (temp.minutes > 60)
	{
		temp.minutes = 296 - temp.minutes;
		temp.hours -= 1;
	}
	*this = temp;
	return temp;
}