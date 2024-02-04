#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

#include "Card.h"
#include "DebitCard.h"

#include "NamespaceShowMenu.h"

using namespace std;

void DebitCard::show(int gotoY) const
{
	ShowMenu::gotoXY(10, gotoY);
	cout << "Your Debit card Name:  " << name << endl;
	ShowMenu::gotoXY(10, gotoY += 1);
	cout << "Your current Balance is: " << balance << endl;
	ShowMenu::gotoXY(10, gotoY += 1);
	cout << "Your number of Card is: " << endl;
	for (int i = 0; i < numberOfCardSize; i++)
	{
		ShowMenu::gotoXY(10 + i, gotoY + 1);
		cout << numberOfCard[i];
	}
	cout << endl;

	ShowMenu::gotoXY(10, gotoY += 2);
	cout << "Your Validity Perio is: ";
	for (int i = 0; i < ValidityPeriodSize; i++)
	{
		if (ValidityPeriod[i] < 10)
		{
			cout << "0" << ValidityPeriod[i] << "|";
		}
		else
		{
			cout << ValidityPeriod[i] << "|";
		}
	}
	cout << endl;

	ShowMenu::gotoXY(10, gotoY += 1);
	cout << "Your CVV is: ";
	for (int i = 0; i < CVVSize; i++)
	{
		ShowMenu::gotoXY(10 + i, gotoY + 1);
		cout << CVV[i];
	}
	cout << endl << endl;
}
