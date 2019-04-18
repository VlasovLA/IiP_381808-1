#include "OneContact.h"
#include <string>
#include <iostream>

using namespace std;

OneContact::OneContact() {
	fio = "";
	phone = "";
	birthday = "";
	favourite = false;
}

OneContact::OneContact(string f) {
	fio = f;
	phone = "";
	birthday = "";
	favourite = false;
}

OneContact::~OneContact() {
	fio = "";
	phone = "";
	birthday = "";
	favourite = false;
}

void OneContact::edit() {
	for (bool e = false; !e;) {
		cout << "Izmenit':" << endl
			 << "1 - Imya" << endl
			 << "2 - Nomer telefona" << endl
			 << "3 - Data rojdeniya" << endl
			 << "0 - Vihod" << endl;
		int choose = -1;
		while (choose < 0 || choose > 3)
		{
			cin >> choose;
			switch (choose)
			{
			case 1:
			{
				cout << "Vvedite novoe imya: ";
				cin >> this->fio;
				cout << endl;
				break;
			}
			case 2:
			{
				cout << "Vvedite noviy nomer telephona: ";
				cin >> this->phone;
				cout << endl;
				break;
			}
			case 3:
			{
				cout << "Vvedite novuu datu rojdeniya: ";
				cin >> this->birthday;
				cout << endl;
				break;
			}
			case 0:
			{
				cout << "Izmeneniya sohraneni" << endl;
				e = true;
				break;
			}
			default:
			{
				cout << "Nekorrektniy simvol" << endl;
			}
			}
		}
	}
}

string OneContact::getname() {
	return fio;
}

string OneContact::getphone() {
	return phone;
}

bool OneContact::isfavour()
{
	return favourite;
}

void OneContact::nullcontact()
{
	fio = "";
	phone = "";
	birthday = "";
	favourite = false;
}

void OneContact::tofavour() {
	if (favourite) {
		cout << "Kontakt uje bil dobavlen v izbrannoe" << endl;
	}
	else {
		favourite = true;
		cout << "Kontakt dobavlen v izbrannoe" << endl;
	}
}

void OneContact::fromfavour() {
	if (!favourite) {
		cout << "Kontakt ne yavlyaetsa izbrannim";
	}
	else {
		favourite = false;
		cout << "Kontakt bol'she ne yavlyaetsa izbrannim";
	}
}

ostream &operator<<(ostream& stream, const OneContact& C) {
	stream << "Imya: " << C.fio << endl
		<< "Telefon: " << C.phone << endl 
		<< "Data rojdeniya: " << C.birthday << endl 
		<< "Izbranniy: " << C.favourite;
	return stream;
}