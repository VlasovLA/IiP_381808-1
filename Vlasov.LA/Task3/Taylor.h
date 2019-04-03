#pragma once
using namespace std;

string IntToStr(int i);
double F(double a, int n);
string DoubToStr(double Val);

class Taylor 
{
	int length;
	double a;
	string *items;
public:

	Taylor(double a, int len);
	~Taylor();
	int getlength();
	double calculate(double x);
	string* getrow();
	double deviation(double x);
	string operator[](int i);
	friend ostream& operator<<(ostream& stream, const Taylor& T);
	int factorial(int i);
};