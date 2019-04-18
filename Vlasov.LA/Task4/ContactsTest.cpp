#include <iostream>
#include <cmath>
#include "Contacts.h"
#include "OneContact.h"
using namespace std;
int main()
{
	Contacts ex;
	while (13)
	{
		int choose;
		cout << "1 - Sozdat' kontakt" << endl
		 	 << "2 - Naity kontakt" << endl
		 	 << "3 - Izmenit' kontakt" << endl
			 << "4 - Udalit' kontakt" << endl
			 << "5 - Vivesti kolichestvo kontaktov" << endl
			 << "0 - Vihod" << endl;
		cin >> choose;

		switch (choose)
		{
			case 1:
			{
				ex.newcontact();
				break;
			}
			case 2:
			{
				cout << "1 - Naity kontakt po imeni" << endl
					 << "2 - Naity kontakt po nomeru telefona" << endl
					 << "3 - Naity vse  kontakti na zadannuyu bukvu" << endl
					 << "4 - Naity vse izbrannie kontakti" << endl
					 << "0 - Nazad" << endl;
				cin >> choose;
				switch (choose)
				{
					case 1:
					{
						ex.findcontactbyfio();
						break;
					}
					case 2:
					{
						ex.findcontactbytel();
						break;
					}
					case 3:
					{
						ex.findcontactsbychar();
						break;
					}
					case 4:
					{
						ex.showfavourcontacts();
						break;
					}
					case 0:
					{
						break;
					}
				}
				break;
			}
			case 3:
			{
				cout << "1 - Izmenit' informaciyu o kontakte" << endl
					 << "2 - Vnesti kontakt v izbrannie" << endl
					 << "3 - Udalit' kontakt iz izbrannih" << endl
					 << "0 - Nazad" << endl;
				cin >> choose;
				switch (choose)
				{
					case 1:
					{
						ex.editcontact();
						break;
					}
					case 2:
					{
						ex.setfavourite();
						break;
					}
					case 3:
					{
						ex.setnofavourite();
						break;
					}
					case 0:
					{
						break;
					}
				}

				break;
			}
			case 4:
			{
				ex.deletecontactbytel();
				break;
			}
			case 5:
			{
				cout << ex.getnumbofcontacts() << endl;
				break;
			}
			case 0:
			{
				return 0;
				break;
			}
			default:
			{
				cout << "Nekorrektniy simvol" << endl;
			}
		}
		cout << endl << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << endl;
	}

	return 0;
}