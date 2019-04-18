#pragma once
#include "OneContact.h"

class Contacts
{
private:
	OneContact *contacts; // sozdanie massiva elementov klassa OneContact
	int size; // razmer massiva
	int length; // kol-vo elementov massiva

public:
	Contacts(); // konstruktor po umolchaniu
	~Contacts(); // destruktor

	void newcontact(); // sozdat' noviy kontakt
	void findcontactbyfio(); // naiti kontakt po fio
	void findcontactbytel(); // naiti kontakt po phone
	void findcontactsbychar(); // naiti vse kontakti, fio kotorih nachinaetsa na opredelenniy simvol
	void editcontact(); // izmenit' dannie kontakta
	int getnumbofcontacts(); // vivesti kol-vo kontaktov(length)
	void setfavourite(); // ustanovit' favourit kontakta = true
	void setnofavourite(); // ustanovit' favourit kontakta = false
	void showfavourcontacts(); // vivesti vse kontakti u kotorih favourite = true
	void deletecontactbytel(); // udalit' kontakt naidenniy po nomeru telefona
};