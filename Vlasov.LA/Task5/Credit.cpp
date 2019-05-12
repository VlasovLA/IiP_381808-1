#include "Credit.h"
#include <iostream>

short years[5] = {1, 2, 3, 5, 15 };
unsigned val[5] = {0, 100000, 300000, 1000000, 3000000 };
double kp[5][4] = // koefficient uvelicheniya kredita v god
//Srok kredita, let:		 1     2     3     5     15 
/*<100 000 rub.*/		   {0.20, 0.18, 0.16, 0.14, 0.12,
/*100000-300000 rub.*/		0.18, 0.16, 0.14, 0.12, 0.10,
/*300000-1000000 rub.*/		0.16, 0.14, 0.12, 0.10, 0.08,
/*1000000-3000000 rub.*/	0.14, 0.12, 0.10, 0.08, 0.06 };

Credit::Credit()
{
	usersNumb = 0;
	users = new ProcCenter[usersNumb];
}

Credit::~Credit()
{
	usersNumb = 0;
	delete[] users;
}

unsigned Credit::userAuth() 
{
	string p;
	unsigned n;

	while (1)
	{
		cout << endl << "Vvedite nomer vashego scheta: ";
		cin >> n;
		cout << endl << "Vvedite parol': ";
		cin >> p;
		if (users[n - 1].dataCheck(n, p) || n == 0 || p == "0")
		{
			cout << endl << "Avtorizaciya proshla uspeshno" << endl;
			return n;
		}
		else
			cout << endl << "Vveden neverniy nomer scheta ili parol'. Povtorite popitku ili vvedite '0' dlya vihoda" << endl;
	}
}

unsigned Credit::userReg()
{
	if (usersNumb != 0)
	{
		ProcCenter* tmp;
		tmp = new ProcCenter[usersNumb];
		for (int i = 0; i < usersNumb; i++)
			tmp[i] = users[i];
		delete[] users;
		users = new ProcCenter[usersNumb + 1];
		for (int i = 0; i < usersNumb; i++)
			users[i] = tmp[i];
		delete[] tmp;
	}
	else
	{
		delete[] users;
		users = new ProcCenter[1];
	}
	usersNumb++;
	return  users[usersNumb].newUser();
}
void Credit::showCredInfo()
{
	for (int k = 1; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Kredit " << val[k - 1] << " do " << val[k] << " rubley, s godovoy procentnoy stavkoy ";
			cout << kp[i][k] * 100 << "%, " << endl;
			cout << "srokom na " << years[i];
			if (i == 1) cout << " god, ";
			if (i == 2 || i == 3) cout << " goda, ";
			if (i > 3) cout << " let, ";
		}

	}

}
void Credit::showPossibleCred(unsigned n)
{
	for (int k = 1; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			if ((users[n - 1].getBal() >= kp[i][k] / 2 * (k-1)) && (users[n - 1].getBal() < kp[i][k] / 2 * k))
			{
				cout << endl << "Kredit ot " << val[k - 1] << " do " << users[n - 1].getBal() * 2 / kp[i][k];
				cout << " rubley, s godovoy procentnoy stavkoy " << kp[i][k] * 100 << "%, ";
				cout << "skorom na " << years[i];
				if (i == 1) cout << " god, ";
				if (i == 2 || i == 3) cout << " goda, ";
				if (i > 3) cout << " let, ";
			}
		}

	}
		
}

void Credit::takeCred(unsigned n)
{
	cout << "Vvedite nomer kredita, kotoriy hotite vzyat'. Vvedite '0' dlya vihoda" << endl;
	short c, count = 1;
	short p[20];
	for (int k = 1; k < 5; k++)
	{
		for (int i = 0; i < 5;i++)
		{
			if ((users[n - 1].getBal() >= kp[i][k] / 2 * (k - 1)) && (users[n - 1].getBal() < kp[i][k] / 2 * k))
			{
				cout << endl << count << "- Kredit ot " << val[k - 1] << " do " << users[n - 1].getBal()*2/kp[i][k] << " rubley, c godovoy procentnoy stavkoy ";
				cout << kp[i][k] * 100 << "%, ";
				cout << "srokom na " << years[i];
				if (i == 1) cout << " god, ";
				if (i == 2 || i == 3) cout << " goda, ";
				if (i > 3) cout << " let, ";

				p[count - 1] = i*4 + (k-1);
				count++;
			}
		}

	}
	cout << endl;
	cin >> c;
	if (c != 0)
	{
		users[n - 1].setCred(p[c - 1] / 4, p[c - 1] % 4);
		users[n - 1].setDebt(val[p[c - 1] % 4] * 12);
		users[n - 1].setRTime(years[p[c - 1] / 4] * 12);
	}

}
void Credit::showCredStatus(unsigned n)
{
	pair <short, short> p = users[n - 1].getCred();
	if (p.first == -1)
		cout << "U vas net zadoljennostey" << endl;
	else
	{
		cout << endl << "Vasha tekuschaya zadoljennost' sostavlyaet " << users[n - 1].getDebt();
		cout << " rubley. Srok pogasheniya: " << users[n - 1].getRTime() << " mesyacev, " << endl;
		cout << 100*kp[p.first][p.second] << "% godovih" << endl;
	}
}
void Credit::payCharge(unsigned n)
{
	unsigned p;
	cout << endl << "Vvedite summu, kotoruyu vi hotite vnesti v schet dolga ili vvedite '0' dlya vihoda: ";
	cin >> p;
	if (p != 0)
	{
		if (users[n - 1].getBal() < p)
			cout << endl << "Summi na vashem schete ne dostatochno dlya dannogo plateja" << endl;
		else
		{
			users[n - 1].setDebt(users[n - 1].getDebt() - p);
			users[n - 1].setBal(users[n - 1].getBal() - p);
			if (users[n - 1].getDebt() == 0)
				cout << endl << "Ves' dolg uspeshno pogashen" << endl;
			else
				cout << endl << "Chast' dolga uspeshno pogashena. Ostavshiysya dolg sostavlyaet " << users[n - 1].getDebt() << " rubley" << endl;
		}
	}
}
void Credit::payCred(unsigned n)
{
	if (users[n - 1].getBal() >= users[n - 1].getDebt())
	{
		users[n - 1].setBal(users[n - 1].getBal() - users[n - 1].getDebt());
		cout << endl << "Ves' dolg uspeshno pogashen" << endl;
	}
	else
		cout << endl << "Summi na vashem schete ne dostatochno dlya polnogo pogasheniya dolga" << endl;
}

void Credit::oneMonthLater(unsigned n)
{
	pair <short, short> p = users[n - 1].getCred();
	if (p.first > -1)
	{
		users[n-1].setRTime(users[n-1].getRTime() - 1);
		users[n-1].setDebt(users[n - 1].getDebt() + users[n - 1].getDebt() * (0.2 - 0.02 * (p.first + p.second)));// uvelichenie tekuschego dolga v konce mesyaca
	}
}

void Credit::showBalance(unsigned n)
{
	cout << endl << "Vash balans sostavlyaet " << users[n - 1].getBal() << " rubley" << endl;
}