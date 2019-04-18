#pragma once
#include <string>
using namespace std;

class OneContact
{
	string fio; // imya kontakta
	string phone; // nomer telefona kontakta
	string birthday; // data rojdeniya
	bool favourite; // prinadlejnost' kontakta k izbrannim

public:
	OneContact(); // konstruktor po umolchaniu
	OneContact(string f); // konstruktor inicializacii
	~OneContact(); // destruktor
	string getname(); // vozvraschaet fio
	string getphone(); // vozvraschaet phone
	bool isfavour(); // vozvraschaet favourite
	void edit(); // izmenenie fio, phone, birthday
	void nullcontact(); // ustanovit' fio="0", phone="0", birthday="0", favourite=false
	void tofavour(); // ustanovit' favourite=true
	void fromfavour(); // ustanovit' favourite=false
	friend ostream&operator<<(ostream& stream, const OneContact&); // peregruzka operatora vivoda
};