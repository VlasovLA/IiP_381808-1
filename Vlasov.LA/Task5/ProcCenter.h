#pragma once
#include <string>
#include <utility>
using namespace std;
class ProcCenter
{
private:
	short accNumber;//nomer scheta
	string fam;
	string imya;
	string otch;
	string password;//parol'
	unsigned curBal;//tekuschiy balans
	pair <short, short> curCred;//eto indeksi massivov 'Years' i 'Val'(Oni objavleni v "Credit.cpp")
								//pervaya peremennaya - vremya, na kotoroe vzyat kredit, 
								// vtoraya - summa kredita, esli nikakoy kredit ne vzyat, ravno -1, -1
	unsigned debt;//summa ostavshegosya dolga
	short remTime;//ostavsheesya vremya za kotoroe nado pogasit' kredit

public:
	ProcCenter();
	~ProcCenter();

	short getAccN();//vozvraschaet nmoer scheta
	string getFIO();//vozvraschaet FIO
	string getPW();//vozvraschaet parol'
	unsigned getBal();//vozvraschaet tekuschiy balans
	pair <short, short> getCred();//vozvraschaet nekotoruyu informaciu o kredite
	unsigned getDebt();//vozvraschaet summu ostavshegosya dolga
	short getRTime();//vozvraschaet ostavsheesya vremya za kotoroe nado pogasit' kredit
	void setFIO(string f, string i, string o);//ustanovit' FIO
	void setBal(unsigned b);//ustanovit' tekuschiy balans
	void setCred(short p1, short p2);//ustanovit'nekotoruyu informaciu o kredite
	void setDebt(unsigned d);//ustanovit' summu ostavshegosya dolga
	void setRTime(short t);//ustanovit' ostavsheesya vremya za kotoroe nado pogasit' kredit
	unsigned newUser();//sozdat' novogo pol'zovatelya
	bool dataCheck(unsigned numb, string pw);//proverka pravil'nosti vvedennih logina i parolya
};