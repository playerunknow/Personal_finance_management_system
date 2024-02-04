#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <cstdlib>


#include "Bank.h"
#include "Card.h"
#include "CreditCard.h"
#include "DebitCard.h"
#include "Application.h"
#include "Wallet.h"

using namespace std;

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("mode con cols=120 lines=40");

	Application Application;

	Bank bank;

	Application.Run(bank);
}