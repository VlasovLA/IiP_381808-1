#include <iostream>
#include <cmath>
#include <sstream>
#include "Taylor.h"
#include <cstdlib>

using namespace std;


string IntToStr(int param)
{
	string str = "";
	for (str = ""; param; param /= 10)
		str += (char)('0' + param % 10);
	reverse(str.begin(), str.end());
	return str;
}

string DoubToStr(double Val)
{
	string result;
	std::ostringstream ost;
	ost << Val;
	result = ost.str();
	return result;
}

double F(double a, int n)
{
	switch (n % 4)
	{
	case 0:
		return sin(a);
		break;

	case 1:
		return cos(a);
		break;

	case 2:
		return -sin(a);
		break;

	case 3:
		return -cos(a);
		break;
	}
}

string SF(int n)
{
	switch (n % 4)
	{
	case 0:
		return "sin(a)";
		break;

	case 1:
		return "cos(a)";
		break;

	case 2:
		return "-sin(a)";
		break;

	case 3:
		return "-cos(a)";
		break;
	}
}

Taylor::Taylor(double a, int len) 
{
	length = len;
	items = new string[length];
	for (int i = 0; i < length; i++)
		items[i] = SF(i) + "/" + DoubToStr(i) + "!";
}

Taylor::~Taylor() 
{
	length = 0;
}

int Taylor::getlength() 
{
	return length;
}

double Taylor::calculate(double x)
{
	double res = 0;
	for (int i = 0; i < this->length; i++)
		res += F(this->a, i) / factorial(i) * pow((x - this->a), i);
	return res;
}

string Taylor::operator[] (int i) 
{
	if (i > 0 && i < length + 1)
		return items[i - 1];
	else
		return "Ne korrectnoe znachenie";
}

string* Taylor::getrow() 
{
	return items;
}

ostream& operator<<(ostream& stream, const Taylor& T) 
{
	string row = "koeffecienti: " + T.items[0];
	for (int i = 1; i < T.length; i++) 
	{
		row += " " + T.items[i];
	}
	stream << row;
	return stream;
}

int Taylor::factorial(int i) 
{
	if (i == 1 || i == 0) 
	{
		return 1;
	}
	else 
	{
		return i * factorial(i - 1);
	}
}

double Taylor::deviation(double x) 
{
	return abs(sin(x) - this->calculate(x));
}
