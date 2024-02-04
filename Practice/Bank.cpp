#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include<fstream>

#include "Bank.h"
#include "Wallet.h"

#include "BankSource.h"
#include "WalletSource.h"

#include "NamespaceShowMenu.h"

using namespace std;

template<typename K, typename V>
multimap<V, K> invertMap(multimap<K, V> const& map)
{
	multimap<V, K> multimap;

	for (auto const& pair : map)
	{
		multimap.insert(make_pair(pair.second, pair.first));
	}

	return multimap;
}

void Bank::CreateWallet()
{
	string new_name = "Default";

	ShowMenu::print_menu(mass, 2, 50, 20, Bankchoice);
	system("cls");

	if (Bankchoice == 1)
	{
		ShowMenu::gotoXY(50, 18);
		ShowMenu::setColor(4);
		cout << "Enter new name ->";
		getline(cin, new_name);
		system("cls");
	}
	else
	{
		system("cls");
	}

	Wallets.push_back(Wallet(new_name));

	ShowMenu::gotoXY(50, 18);
	ShowMenu::setColor(4);
	cout << "your wallet was created!" << endl;
	ShowMenu::gotoXY(50, 19);
	cout << "Now you have " << Wallets.size() << "  Wallets\n";
	ShowMenu::gotoXY(46, 20);
	system("pause");
	ShowMenu::setColor(7);
	ShowMenu::gotoXY(50, 20);
}

void Bank::ManageWallet() 
{
	if (Wallets.size() == 0)
	{
		ShowMenu::gotoXY(50, 18);
		ShowMenu::setColor(4);
		cout << "You have " << Wallets.size() << " Wallets" << endl;
		ShowMenu::gotoXY(50, 19);
		system("pause");
		system("cls");
	}
	else
	{
		ShowMenu::print_menu_wallet(Wallets, 50, 18, walletchoice);

		ShowMenu::print_menu(wallet_choice, 2, 50, 18, Bankchoice);
		system("cls");

		switch (Bankchoice)
		{
		case 1:
		{
			Wallets[walletchoice - 1].showWalletCards();
			break;
		}
		case 2:
		{
			Wallets[walletchoice - 1].AddCards();
			break;
		}
		default:
			break;
		}
		system("cls");
	}
}

void Bank::Replenishment()
{
	if(Wallets.size() == 0)
	{
		ShowMenu::setColor(4);
		ShowMenu::gotoXY(50, 19);
		cout << "You have't any wallet :( " << endl;
		ShowMenu::gotoXY(46, 20);
		system("pause");
	}
	else
	{
		ShowMenu::print_menu_wallet(Wallets, 50, 18, Bankchoice);

		Wallets[Bankchoice - 1].ReplenishmentWallet();

		system("cls");
	}
}

void Bank::InputOfCost()
{
	if (Wallets.size() == 0)
	{
		ShowMenu::setColor(4);
		ShowMenu::gotoXY(50, 19);
		cout << "You have't any wallet :( " << endl;
		ShowMenu::gotoXY(46, 20);
		system("pause");
	}
	else
	{
		ShowMenu::print_menu_wallet(Wallets, 50, 18, Bankchoice);

		Wallets[Bankchoice - 1].inputOfCost();
		system("cls");
	}
}

void Bank::print_map(multimap<string, double> multimap) const
{
	int gotoy = 19;
	if (multimap.size() == 0)
	{
		ShowMenu::setColor(4);
		ShowMenu::gotoXY(50, 19);
		cout << "there is empty" << endl;
		ShowMenu::gotoXY(50, 20);
		system("pause");
	}
	else
	{
		for (auto it = multimap.begin(); it != multimap.end(); ++it)
		{
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, gotoy++);
			cout << (*it).first << " : " << (*it).second << endl;
		}
		ShowMenu::gotoXY(50, 39);
		system("pause");
	}
}

void Bank::print_map_top3(multimap<double, string> multimap)
{
	system("cls");

	int i = 0;

	int gotoy = 19;

	if (multimap.size() == 0)
	{
		ShowMenu::setColor(4);
		ShowMenu::gotoXY(50, 19);
		cout << "there is empty" << endl;
		ShowMenu::gotoXY(50, 20);
		system("pause");
	}
	else
	{
		for (auto it = multimap.rbegin(); it != multimap.rend(); ++it)
		{
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, gotoy++);
			cout << it->first << " | " << it->second << "\n";
			i++;
			if (i == 3)
				break;
		}
		ShowMenu::gotoXY(50, 39);
		system("pause");
	}
}

void Bank::ShowReport() 
{
	ShowMenu::print_menu(report_menu, 3, 50, 20, Bankchoice);
	system("cls");

	switch (Bankchoice)
	{
		system("cls");
		ShowMenu::setColor(4);
		ShowMenu::gotoXY(50, 10);
	case 1:
	{
		print_map(Day);
		break;
	}
	case 2:
	{
		print_map(Week);
		break;
	}
	case 3:
	{
		print_map(Month);
		break;
	}
	default:
		break;
	}
}

void Bank::ShowRatings()
{
	MakeReportTOP3WeekByMoney(Week);
	MakeReportTOP3MonthByMoney(Month);
	MakeReportTOP3WeekByCategory(Week);
	MakeReportTOP3MonthByCategory(Month);

	ShowMenu::print_menu(top_3, 4, 50, 20, Bankchoice);

	switch (Bankchoice)
	{
	case 1:
	{
		print_map_top3(Top3WeekbyMoney);
		break;
	}
	case 2:
	{
		print_map_top3(Top3MonthByMoney);
		break;
	}
	case 3:
	{
		print_map_top3(Top3WeekbyCategory);
		break;
	}
	case 4:
	{
		print_map_top3(Top3MonthbyCategory);
		break;
	}
	default:
		break;
	}
}

void Bank::WriteIntoFile(multimap<string, double> multimap, string WhenItWas)
{
	ofstream out;
	out.open("reports.txt", ios::app);

	out << WhenItWas << "\n\n";

	for (auto it = multimap.begin(); it != multimap.end(); ++it)
		out << it->first << " | " << it->second << "\n";
	out << "=======================================================" << "\n\n";

	out.close();
}

void Bank::WriteIntoFile(multimap<double, string> multimap, string WhenItWas)
{
	ofstream out;
	out.open("reports.txt", ios::app);

	out << WhenItWas << "\n\n";

	int i = 0;

	for (auto it = multimap.rbegin(); it != multimap.rend(); ++it)
	{
		out << it->first << " | " << it->second << "\n";
		i++;
		if (i == 3)
			break;
	}

	out << "=======================================================" << "\n\n";

	out.close();
}

void Bank::MakeReportTOP3WeekByMoney(multimap<string, double> map)
{
	Top3WeekbyMoney = invertMap(map);
}

void Bank::MakeReportTOP3MonthByMoney(multimap<string, double> map)
{
	Top3MonthByMoney = invertMap(map);
}

void Bank::MakeReportTOP3WeekByCategory(multimap<string, double> multimap)
{
	map<string, double> temp;

	for (auto it = multimap.begin(); it != multimap.end(); ++it)
	{
		bool already_exist = false;

		if (temp.size() == 0)
		{
			temp.insert(make_pair(it->first, it->second));
		}
		else
		{
			for (auto itt = temp.begin(); itt != temp.end(); ++itt)
			{
				if (itt->first == it->first)
				{
					itt->second += it->second;
					already_exist = true;
				}
			}	
			if (already_exist == false)
			{
				temp.insert(make_pair(it->first, it->second));
			}
		}
	}

	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		Top3WeekbyCategory.insert(make_pair(it->second, it->first));
	}

}

void Bank::MakeReportTOP3MonthByCategory(multimap<string, double> multimap)
{
	map<string, double> temp;

	for (auto it = multimap.begin(); it != multimap.end(); ++it)
	{
		bool already_exist = false;

		if (temp.size() == 0)
		{
			temp.insert(make_pair(it->first, it->second));
		}
		else
		{
			for (auto itt = temp.begin(); itt != temp.end(); ++itt)
			{
				if (itt->first == it->first)
				{
					itt->second += it->second;
					already_exist = true;
				}
			}
			if (already_exist == false)
			{
				temp.insert(make_pair(it->first, it->second));
			}
		}
	}

	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		Top3MonthbyCategory.insert(make_pair(it->second, it->first));
	}
}

void Bank::SaveAllMultimapsIntoFile()
{
	remove("reports.txt");

	if (Day.size() > 0)
		WriteIntoFile(Day, "Day");

	if (Week.size() > 0)
		WriteIntoFile(Week, "Week");

	if (Month.size() > 0)
		WriteIntoFile(Month, "Month");

	MakeReportTOP3WeekByMoney(Week);
	if (Top3WeekbyMoney.size() > 0)
		WriteIntoFile(Top3WeekbyMoney, "Top 3 Week by money");

	MakeReportTOP3MonthByMoney(Month);
	if (Top3MonthByMoney.size() > 0)
		WriteIntoFile(Top3MonthByMoney, "Top 3 Month by money");

	MakeReportTOP3WeekByCategory(Week);
	if (Top3WeekbyCategory.size() > 0)
		WriteIntoFile(Top3WeekbyCategory, "Top 3 Week by Category");

	MakeReportTOP3MonthByCategory(Month);
	if (Top3MonthbyCategory.size() > 0)
		WriteIntoFile(Top3MonthbyCategory, "Top 3 Month by Category");
}