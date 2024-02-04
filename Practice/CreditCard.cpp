#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

#include "CreditCard.h"

#include "NamespaceShowMenu.h"

using namespace std;

void CreditCard::show(int gotoY) const
{
	ShowMenu::gotoXY(60, gotoY);
	cout << "Your Credit card Name:  " << name << endl;
	ShowMenu::gotoXY(60, gotoY += 1);
	cout << "Your current Balance is: " << balance << endl;
	ShowMenu::gotoXY(60, gotoY += 1);
	cout << "Your number of Card is: " << endl;
	for (int i = 0; i < numberOfCardSize; i++)
	{
		ShowMenu::gotoXY(60 + i, gotoY + 1);
		cout << numberOfCard[i];
	}
	cout << endl;

	ShowMenu::gotoXY(60, gotoY += 2);
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

	ShowMenu::gotoXY(60, gotoY += 1);
	cout << "Your CVV is: " << endl;
	for (int i = 0; i < CVVSize; i++)
	{
		ShowMenu::gotoXY(60 + i, gotoY + 1);
		cout << CVV[i];
	}
	cout << endl << endl;
}