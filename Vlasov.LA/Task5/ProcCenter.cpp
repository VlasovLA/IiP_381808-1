#include "ProcCenter.h"
#include <iostream>

ProcCenter::ProcCenter()
{
	accNumber = 0;
	fam = "";
	imya = "";
	otch = "";
	password = "";
	curBal = 0;
	curCred.first = curCred.second = -1;
	debt = 0;
	remTime = 0;
}
ProcCenter::~ProcCenter()
{
	accNumber = 0;
	fam = "";
	imya = "";
	otch = "";
	password = "";
	curBal = 0;
	curCred.first = curCred.second = -1;
	debt = 0;
	remTime = 0;
}

short ProcCenter::getAccN()
{
	return accNumber;
}
string ProcCenter::getFIO()
{
	return (this->fam+ this->imya+ this->otch);
}
string ProcCenter::getPW()
{
	return this->password;
}
unsigned ProcCenter::getBal()
{
	return this->curBal;
}

pair <short, short> ProcCenter::getCred()
{
	return this->curCred;
}

unsigned ProcCenter::getDebt()
{
	return this->debt;
}

short ProcCenter::getRTime()
{
	return this->remTime;
}

void ProcCenter::setFIO(string f, string i, string o)
{
	this->fam = f;
	this->imya = i;
	this->otch = o;
}

void ProcCenter::setBal(unsigned b)
{
	this->curBal = b;
}

void ProcCenter::setCred(short p1, short p2)
{
	this->curCred.first = p1;
	this->curCred.second = p2;
}

void ProcCenter::setDebt(unsigned d)
{
	this->debt = d;
}

void ProcCenter::setRTime(short t)
{
	this->remTime = t;
}

unsigned ProcCenter::newUser() 
{
	accNumber++;
	string a, b, c;
	cout << "Vvedite vashi dannie:" << endl << " - Familiya: ";
	cin >> a;
	cout << endl << " - Imya: ";
	cin >> b;
	cout << endl << " - Otchestvo: ";
	cin >> c;
	setFIO(a, b, c);
	cout << endl << endl << "Pridumayte parol', ";
	do
	{
		cout << "on doljen sostoyat' bolee chem iz treh simvolov" << endl;
		cin >> this->password;
		cout << endl;
	}
	while (this->password.length() < 4);
	srand(3);
	this->curBal = rand() * 10;

	cout << endl << "Registraciya zavershena" << endl;
	cout << "Vash nomer scheta - " << accNumber << endl;
	cout << "Vash tekuschiy balans - " << this->curBal << " rubley";
	return accNumber;
}

bool ProcCenter::dataCheck(unsigned numb, string pw)
{
	return (numb == accNumber && pw == this->password);
}