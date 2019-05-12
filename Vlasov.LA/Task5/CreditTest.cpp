#include "Credit.h"
#include <iostream>
using namespace std;

int main()
{
	Credit ex;
	short ans;
	unsigned session = 0;
	bool prog = true;
	while (prog)
	{
		cout << "1 - Vhod" << endl
			<< "2 - Registraciya" << endl
			<< "0 - Vihod" << endl;
		cin >> ans;
		switch (ans)
		{
			case 1:
			{
				session = ex.userAuth();
				break;
			}
			case 2:
			{
				session = ex.userReg();
				break;
			}
			case 0:
			{
				prog = false;
				break;
			}
		}

		while (session)
		{
			cout << "1 - Pokazat' tekuschiy balans" << endl
				<< "2 - Pokazat' vse krediti" << endl
				<< "3 - Pokazat' dostupnie krediti" << endl
				<< "4 - Vzyat' kredit" << endl
				<< "5 - Pokazat' moi krediti" << endl
				<< "6 - Pogasit'chast' dolga" << endl
				<< "7 - Pogasit' ves' dolg" << endl
				<< "8 - Sleduyuschiy mesyac" << endl
				<< "0 - Vihod iz akkaunta" << endl;
			cin >> ans;
			switch (ans)
			{
			case 1:
			{
				ex.showBalance(session);
				break;
			}
			case 2:
			{
				ex.showCredInfo();
				break;
			}
			case 3:
			{
				ex.showPossibleCred(session);
				break;
			}
			case 4:
			{
				ex.takeCred(session);
				break;
			}
			case 5:
			{
				ex.showCredStatus(session);
				break;
			}
			case 6:
			{
				ex.payCharge(session);
				break;
			}
			case 7:
			{
				ex.payCred(session);
				break;
			}
			case 8:
			{
				ex.oneMonthLater(session);
				break;
			}
			case 0:
			{
				session = 0;
				break;
			}
			}
		}
	}
	system("PAUSE");
	return 0;
}
