#include "Bot.h"
#include <iostream>
using namespace std;

int main()
{
	Bot bastard;
	string ask;
	unsigned length;
	int ans;
	do
	{
		cout << "Vvedite kol-vo razryadov zagadivaemogo chisla (1-10): ";
		cin >> length;
		cout << endl;
	} while (length > 10 || length < 1);

	bastard.giveNumber(length);

	cout << endl << "Chislo zagadano " << bastard.getNumber() << endl;

	while (20)
	{
		
		cout << endl << "Poprobuyte otgadat' ego, vvedya " << length
			<< " razryadnoe chislo bez povtoryayuschihsya cifr: ";
		while (12)
		{
			cin >> ask;
			if (ask.length() == length)
				break;
			else
				cout << endl << "V chisle doljno bit' " << length << " razryadov. Povtorite popitku: ";
		}
		pair <int, int> p = bastard.suggest(ask);
		if (p.first == 15)
		{
			cout << endl << "Vi polnost'u otgadali chislo!" << endl;
			return 0;
		}
		else
		{
			cout << "Vash rezultat:  " << p.second << " - korov";
			if (p.second == 1)
				cout << "a";
			if (p.second > 1 && p.second < 5)
				cout << "i";

			cout << endl << "             " << p.first << " - bik";
			if (p.first > 1 && p.first < 5)
				cout << "a";
			if (p.first > 4 || p.first == 0)
				cout << "ov";

			cout << endl << endl << "Viberite deystvie" << endl
				<< "1: Poprobovat' snova" << endl
				<< "2: Zakonchit'" << endl;
			cin >> ans;
			if (ans == 2)
				return 0;
		}


	}

	system("PAUSE");
	return 0;
}