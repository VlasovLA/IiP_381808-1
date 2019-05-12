#pragma once
#include <string>
#include "ProcCenter.h"
using namespace std;

class Credit
{
	ProcCenter *users;//dinamicheskiy massiv tipa ProcCenter
	unsigned usersNumb;//kol-vo zaregestrirovannih pol'zovateley

public:
	Credit();
	~Credit();

	unsigned userAuth();//avtorizaciya pol'zovatelya
	unsigned userReg();//registraciya pol'zovatelya
	void showCredInfo();//Pokazat' vse krediti
	void showPossibleCred(unsigned n);//Pokazat' dostupnie krediti
	void takeCred(unsigned n);//Vzyat' kredit
	void showCredStatus(unsigned n);//Pokazat' vzyatie krediti
	void payCharge(unsigned n);//Pogasit'chast' dolga
	void payCred(unsigned n);//Pogasit' ves' dolg
	void oneMonthLater(unsigned n);//Sleduyuschiy mesyac
	void showBalance(unsigned n);//Pokazat' tekuschiy balans
};
