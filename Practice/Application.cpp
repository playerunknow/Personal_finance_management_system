#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

#include "Application.h"
#include "Bank.h"

#include "NamespaceShowMenu.h"

using namespace std;

Application::Application() : MenuItem{ new string[size] }
{
	MenuItem[0] = "Mannge Wallets and cards";
	MenuItem[1] = "Replenishment wallets and cards";
	MenuItem[2] = "input of costs";
	MenuItem[3] = "Show reports";
	MenuItem[4] = "Show ratings";
	MenuItem[5] = "Exit";
}

void Application::Run(Bank& bank)
{
	Intro();

	SwitchMenuItem(bank);
}

void Application::SwitchMenuItem(Bank& bank)
{
	bool Switch = true;

	string case_1_mas[2]
	{
		"1 - Create Wallets",
	    "2 - Manege your Wallets"
	};

	while (Switch)
	{
		int choose{0};
		ShowMenu::print_menu(MenuItem, 6, 45, 17, choose);
		system("cls");

		switch (choose)
		{
		case 1:
		{
			ShowMenu::print_menu(case_1_mas, 2, 50, 20, choose);

			switch (choose)
			{
			case 1:
			{
				system("cls");
				bank.CreateWallet();
				break;
			}
			case 2:
			{
				system("cls");
				bank.ManageWallet();
				break;
			}
			}
			break;
		}
		case 2:
		{
			bank.Replenishment();
			break;
		}
		case 3:
		{
			bank.InputOfCost();
			break;
		}
		case 4:
		{
			bank.ShowReport();
			break;
		}
		case 5:
		{
			bank.ShowRatings();
			break;
		}
		case 6:
		{
			bank.SaveAllMultimapsIntoFile();
			Switch = false;
			break;
		}
		default:
			cout << "Invali data" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Application::Intro()
{
	ShowMenu::gotoXY(42, 20);
	ShowMenu::setColor(4);
	cout << "Welcome to personal finance management system" << endl;
	ShowMenu::gotoXY(45, 21);
	system("pause");
	ShowMenu::setColor(7);
	system("cls");
}