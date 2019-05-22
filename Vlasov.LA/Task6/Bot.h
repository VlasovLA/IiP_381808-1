#pragma once
#include <string>
#include <ctime>

using namespace std;

class Bot
{
private:
	unsigned length;
	string number;

public:
	Bot();
	~Bot();

	void giveNumber(unsigned n);
	pair <int, int> suggest(string s);
	unsigned getLen();
	string getNumber();
};