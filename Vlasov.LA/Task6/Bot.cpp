#include "Bot.h"

Bot::Bot()
{
	length = 0;
	number = "";
}

Bot::~Bot()
{
	length = 0;
	number = "";
}

void Bot::giveNumber(unsigned n)
{
	this->length = n;
	srand(time(0));
	char repeat[10] = { -1 };
	char r;
	string s = "";
	repeat[0] = rand() % 9 + 1;
	s += '0' + repeat[0];
	for (int i = 1; i < n; i++)
	{
		bool right = false;
		while (right == false)
		{
			right = true;
			r = rand() % 10;
			for (int k = 0; k < i; k++)
				if (repeat[k] == r)
					right = false;
		}
		s += '0' + r;
		repeat[i] = r;
		
	}
	number = s;
}

pair <int, int> Bot::suggest(string s)
{
	pair <int, int> bk;
	bk.first = bk.second = 0;
	for (int i = 0; i < length; i++)
	{
		for (int t = 0; t < length; t++)
		{
			if ((s[i] == number[t]) && (i == t))
				bk.first++;
			if ((s[i] == number[t]) && (i != t))
				bk.second++;
		}
	}
	if (bk.first == length)
		bk.first = 15;
	return bk;
}

unsigned Bot::getLen()
{
	return this->length;
}

string Bot::getNumber()
{
	return this->number;
}