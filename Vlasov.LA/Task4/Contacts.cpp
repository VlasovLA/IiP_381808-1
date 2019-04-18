#include <iostream>
#include <string>
#include "Contacts.h"
#include "OneContact.h"
#include <cstdlib>

using namespace std;
Contacts::Contacts()
{
	size = 0;
	length = 0;
	contacts = new OneContact[size];
}

Contacts::~Contacts()
{
	size = 0;
	length = 0;
	delete[] contacts;
}

void Contacts::newcontact() {
	if (length == size)
	{
		OneContact* tmp;
		tmp = new OneContact[size];
		for (int i = 0; i < size - 1; i++)
			tmp[i] = contacts[i];		
		delete[] contacts;
		size += 5;
		contacts = new OneContact[size];
		for (int i = 0; i < length; i++)
			contacts[i] = tmp[i];
		delete[] tmp;
	}
	string f;
	cout << "Vvedite imya novogo kontakta: ";
	cin >> f;
	cout << endl;
	length++;
	contacts[length] = OneContact(f);
	
	int ans = 0;
	while (ans != 1 && ans != 2)
	{
		cout << "Izmenit' dannie kontakta?" << endl
			<< "1 - Da" << endl
			<< "2 - Net" << endl;
		cin >> ans;
		cout << endl;
		if (ans == 1)
			contacts[length].edit();
		if (ans == 2)
			break;
	}

	cout << "Kontakt sozdan" << endl;
}

void Contacts::findcontactbyfio()
{
	string f;
	cout << "Poisk kontakta po imeni: ";
	cin >> f;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getname() == f)
			break;
	}
	if (i == length)
		cout << "Kontakta s takim imenem ne naideno";
	else
		cout << contacts[i] << endl;
}

void Contacts::findcontactbytel()
{
	string ph;
	cout << "Poisk kontakta po nomeru telefona: ";
	cin >> ph;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getphone() == ph)
			break;
	}
	if (i == length)
		cout << "Kontakta s takim nomerom telefona ne naideno";
	else
		cout << contacts[i] << endl;
}

void Contacts::findcontactsbychar()
{
	char b;
	bool voed = true;
	cout << "Poisk kontaktov, imya kotorih nachinaetsa na bukvu: ";
	cin >> b;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getname()[0] == b)
		{
			cout << contacts[i] << endl;
			voed = false;
		}
	}
	if (voed)
		cout << "Ne naideno ni odnogo takogo kontakta" << endl;
	else
		cout << contacts[i] << endl;
}

void Contacts::editcontact()
{
	string f;
	cout << "Izmenit' kontakt po imeni: ";
	cin >> f;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getname() == f)
			break;
	}
	if (i == length)
		cout << "Kontakta s takim imenem ne naideno";
	else
		contacts[i].edit();
}

int Contacts::getnumbofcontacts()
{
	return length;
}

void Contacts::setfavourite()
{
	string f;
	cout << "Vvedite imya kontakta, kotoriy vi hotite dobavit' v izbrannoe: ";
	cin >> f;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getname() == f)
			break;
	}
	if (i == length)
		cout << "Kontakta s takim imenem ne naideno";
	else
	{
		contacts[i].tofavour();
	}
}

void Contacts::setnofavourite()
{
	string f;
	cout << "Vvedite imya kontakta, kotoriy vi hotite ubrat' iz izbrannogo: ";
	cin >> f;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getname() == f)
			break;
	}
	if (i == length)
		cout << "Kontakta s takim imenem ne naideno";
	else
	{
		contacts[i].fromfavour();
	}
}

void Contacts::showfavourcontacts()
{
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].isfavour())
			cout << contacts[i] << endl;
	}
}

void Contacts::deletecontactbytel()
{
	string ph;
	cout << "Udalit' kontakt s nomerom telefona: ";
	cin >> ph;
	cout << endl;
	int i = 0;
	for (; i < length; i++)
	{
		if (contacts[i].getphone() == ph)
		{
			for (int k = i; k < length - 1; k++)
				contacts[k] = contacts[k + 1];
			contacts[length-1].nullcontact();
			length--;
		}
	}
	if (i == length)
		cout << "Kontakta s takim nomerom telefona ne naideno" << endl;
	else
		cout << "Kontakt udalen" << endl;
}
