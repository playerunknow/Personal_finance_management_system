
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <map>

#include "Wallet.h"
#include "CreditCard.h"
#include "DebitCard.h"
#include "Bank.h"

#include "WalletSource.h"
#include "NamespaceShowMenu.h"

using namespace std;

bool CheckWalletMoney(bool& checkpoint, double& money, double amountofmoneywallet)
{
	checkpoint = false;
	if (money > amountofmoneywallet)
	{
		ShowMenu::gotoXY(50, 19);
		cout << "you haven't this money inside your wallet\n enter new sum";
		ShowMenu::gotoXY(50, 20);
		cin >> money;
		system("cls");
	}
	else if (money < 0)
	{
		ShowMenu::gotoXY(45, 19);
		cout << "Stop kidding me!\n enter new sum";
		ShowMenu::gotoXY(45, 20);
		cin >> money;
		system("cls");
	}
	else
	{
		checkpoint = true;
		return money;
	}
}

void NoticedNotification()
{
	ShowMenu::setColor(4);
	ShowMenu::gotoXY(50, 19);
	cout << "Noticed successfully" << endl;
	ShowMenu::gotoXY(50, 20);
	system("pause");
	system("cls");
}

void dayWeekMonth(string category, double cost)
{
	system("cls");
	ShowMenu::setColor(4);
	ShowMenu::gotoXY(50, 19);
	cout << "when did you spend it" << endl;
	Sleep(1000);

	ShowMenu::print_menu(DayWeekMonth, 3, 50, 19, choice);
	system("cls");

	switch (choice)
	{
	case 1:
	{
		Day.insert(make_pair(category, cost));
		NoticedNotification();
		break;
	}
	case 2:
	{
		Week.insert(make_pair(category, cost));
		NoticedNotification();
		break;
	}
	case 3:
	{
		Month.insert(make_pair(category, cost));
		NoticedNotification();
		break;
	}
	default:
		break;
	}
}

void TypeOfExpenses(double cost)
{
	ShowMenu::print_menu(TypeOfCost, 3, 50, 19, choice);

	switch (choice)
	{
	case 1:
	{
		ShowMenu::print_menu(PettyExpenses, 4, 50, 19, choice);
		system("cls");
		category = PettyExpenses[choice];
		dayWeekMonth(category, cost);
		break;
	}
	case 2:
	{
		ShowMenu::print_menu(AverageCosts, 3, 50, 19, choice);
		system("cls");
		category = AverageCosts[choice];
		dayWeekMonth(category, cost);
		break;
	}
	case 3:
	{
		ShowMenu::print_menu(MajorExpenses, 4, 50, 19, choice);
		system("cls");
		category = MajorExpenses[choice];
		dayWeekMonth(category, cost);
		break;
	}
	default:
		break;
	}
}

void Wallet::AddCards()
{
	string new_name = "Default";

	ShowMenu::print_menu(add_cards, 2, 50, 18, choice);
	system("cls");

	switch (choice)
	{
	case 1:
	{
		ShowMenu::print_menu(set_name_card, 2, 50, 18, choice);
		system("cls");

		if (choice == 1)
		{
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 18);
			cout << "Enter the name->";
			getline(cin, new_name);
		}
		else
			system("cls");

		DebitCardVector.push_back(DebitCard(new_name));

		ShowMenu::gotoXY(50, 19);
		cout << "Your debit card was created: " << endl;

		ShowMenu::gotoXY(50, 20);
		system("pause");
		ShowMenu::setColor(7);
		break;
	}
	case 2:
	{
		ShowMenu::print_menu(set_name_card, 2, 50, 18, choice);
		system("cls");

		if (choice == 1)
		{
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 18);
			cout << "Enter the name->";
			getline(cin, new_name);
		}
		else
			system("cls");

		CreditCardVector.push_back(CreditCard(new_name));

		ShowMenu::gotoXY(50, 19);
		cout << "Your debit card was created: " << endl;

		ShowMenu::gotoXY(50, 20);
		system("pause");
		ShowMenu::setColor(7);

		break;
	}
	default:
		break;
	}
	show();
	system("cls");
}

void Wallet::ReplenishmentWallet()
{
	double money;

	ShowMenu::print_menu(replenishment, 2, 50, 18, choice);
	system("cls");

	switch (choice)
	{
	case 1:
	{
		system("cls");
		ShowMenu::gotoXY(50, 19);
		ShowMenu::setColor(4);
		cout << "how much you want to put?" << endl;
		cin.clear();
		ShowMenu::gotoXY(50, 20);
		cin >> money;
		money += getAmountOfMoney();
		setAmountOfMoney(money);
		system("cls");
		ShowMenu::gotoXY(50, 19);
		cout << "Now your current balance is->" << getAmountOfMoney();
		ShowMenu::gotoXY(50, 20);
		system("pause");
		ShowMenu::setColor(7);
		break;
	}
	case 2:
	{
		ShowMenu::print_menu(put_money_from, 2, 50, 18, choice);

		switch (choice)
		{
		case 1:
		{
			ShowMenu::setColor(4);
			if (getAmountOfMoney() == 0)
			{
				choice = 0;
				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "you haven't money on your wallet" << endl;
				ShowMenu::gotoXY(50, 20);
				system("pause");
			}

			ShowMenu::print_menu(type_of_card, 3, 50, 18, choice);

			if (choice == 1)
			{
				if (DebitCardVector.size() == 0)
				{
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "You haven't any debit card";
					ShowMenu::gotoXY(50, 20);
					system("pause");
					break;
				}
				ShowMenu::print_menu_debitcards(DebitCardVector, 50, 18, choice);
				system("cls");
				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "enter how many money you want to put to this card from your wallet" << endl;
				cin >> money;
				system("cls");
				bool checkpoint = false;

				do
				{
					double MoneyWallet = getAmountOfMoney();
					CheckWalletMoney(checkpoint, money, MoneyWallet);
				} while (checkpoint == false);

				money += DebitCardVector[choice - 1].getBalance();
				DebitCardVector[choice - 1].setBalance(money);
				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "Your current balance is " << DebitCardVector[choice - 1].getBalance();
				double new_balance_of_wallet = getAmountOfMoney() - money;
				setAmountOfMoney(new_balance_of_wallet);
				ShowMenu::gotoXY(50, 20);
				system("pause");
			}
			else if (choice == 2)
			{
				if (DebitCardVector.size() == 0)
				{
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "You haven't any credit card";
					ShowMenu::gotoXY(50, 20);
					system("pause");
					break;
				}
				ShowMenu::print_menu_creditcards(CreditCardVector, 50, 18, choice);
				system("cls");

				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "enter how many money you want to put to this card from your wallet" << endl;
				cin >> money;
				system("cls");
				bool checkpoint = false;
				do
				{
					if (money > getAmountOfMoney())
					{
						ShowMenu::gotoXY(50, 19);
						cout << "you haven't this money inside your wallet\n enter new sum";
						ShowMenu::gotoXY(50, 20);
						cin >> money;
						system("cls");
					}
					else if (money < 0)
					{
						ShowMenu::gotoXY(45, 19);
						cout << "Stop kidding me!\n enter new sum";
						ShowMenu::gotoXY(45, 20);
						cin >> money;
						system("cls");
					}
					else
					{
						checkpoint = true;
					}
				} while (checkpoint == false);

				money += CreditCardVector[choice - 1].getBalance();
				CreditCardVector[choice - 1].setBalance(money);
				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "Your current balance is " << CreditCardVector[choice - 1].getBalance();
				double new_balance_of_wallet = getAmountOfMoney() - money;
				setAmountOfMoney(new_balance_of_wallet);
				ShowMenu::gotoXY(50, 20);
				system("pause");
			}
			break;
		}
		case 2:
		{
			ShowMenu::print_menu(type_of_card, 3, 50, 18, choice);

			if (choice == 1)
			{
				if (DebitCardVector.size() == 0)
				{
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "your have't any cants with this type \n (you can create if you want to at the main menu)" << endl;
					ShowMenu::gotoXY(50, 20);
					system("pause");
					ShowMenu::setColor(7);
				}
				else
				{
					ShowMenu::print_menu_debitcards(DebitCardVector, 50, 18, choice);

					system("cls");
					double money;
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "enter the money->";
					ShowMenu::gotoXY(50, 20);
					cin >> money;
					money += DebitCardVector[choice - 1].getBalance();
					DebitCardVector[choice - 1].setBalance(money);
					system("cls");
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "Your curent balance is" << endl;
					ShowMenu::gotoXY(50, 20);
					cout << DebitCardVector[choice - 1].getBalance();
					ShowMenu::gotoXY(50, 20);
					system("pause");
					ShowMenu::setColor(7);
					system("cls");
				}
			}
			else if (choice == 2)
			{
				if (CreditCardVector.size() == 0)
				{
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "your have't any cants with this type \n (you can create if you want to at the main menu)" << endl;
					ShowMenu::gotoXY(50, 20);
					system("pause");
					ShowMenu::setColor(7);
				}
				else
				{
					ShowMenu::print_menu_creditcards(CreditCardVector, 50, 18, choice);
					system("cls");

					double money;
					ShowMenu::setColor(4);
					ShowMenu::gotoXY(50, 19);
					cout << "enter the money->";
					ShowMenu::gotoXY(50, 20);
					cin >> money;
					money += CreditCardVector[choice - 1].getBalance();
					CreditCardVector[choice - 1].setBalance(money);
					system("cls");
					ShowMenu::gotoXY(50, 19);
					cout << "Your curent balance is" << endl;
					ShowMenu::gotoXY(50, 20);
					cout << CreditCardVector[choice - 1].getBalance();
					system("pause");
					system("cls");
				}
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		cout << "invalid data " << endl;
		system("pause");
		system("cls");
		break;
	}

}

void Wallet::show() const
{
	ShowMenu::gotoXY(50, 19);
	cout << "Amount of Debit Cards " << getCountDebitCards() << endl;
	ShowMenu::gotoXY(50, 20);
	cout << "Amount of Credit Cards " << getCountCreditCards() << endl;
	ShowMenu::gotoXY(50, 21);
	cout << "Money inside Wallet" << getAmountOfMoney() << endl;
	ShowMenu::gotoXY(50, 22);
	cout << "Name " << getName() << endl;
}

void Wallet::showWalletCards()
{
	int gotoyDebitCard = 0;
	int gotoyCreditCard = 0;
	if (DebitCardVector.size() == 0)
	{
		ShowMenu::gotoXY(10, 9);
		ShowMenu::setColor(4);
		cout << "You haven't any debit cards" << endl;
		ShowMenu::setColor(7);
	}
	else
	{
		for (auto i : DebitCardVector)
		{
			ShowMenu::setColor(4);
			i.show(gotoyDebitCard += 9);
		}
		ShowMenu::setColor(7);
	}

	if (CreditCardVector.size() == 0)
	{
		ShowMenu::gotoXY(60, 9);
		ShowMenu::setColor(4);
		cout << "You haven't any credit cards" << endl;
		ShowMenu::setColor(7);
	}
	else
	{
		for (auto i : CreditCardVector)
		{
			ShowMenu::setColor(4);
			i.show(gotoyCreditCard += 9);
		}
		ShowMenu::setColor(7);
	}
	ShowMenu::setColor(4);
	ShowMenu::gotoXY(35, 27);
	system("pause");
}

void Wallet::inputOfCost()
{
	double NewAmountOfMoney;
	double MoneyWallet;
	double MoneyCard;
	bool checkpoint = false;
	ShowMenu::print_menu(InputOfCost, 3, 50, 19, choice);

	if (choice == 1)
	{
		ShowMenu::setColor(4);
		if (getAmountOfMoney() == 0)
		{
			choice = 0;
			system("cls");
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 19);
			cout << "you haven't money on your wallet" << endl;
			ShowMenu::gotoXY(50, 20);
			system("pause");
		}
		else
		{
			system("cls");
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 19);
			cout << "enter how much is this->";
			cin >> cost;
			system("cls");
			do
			{
				MoneyWallet = getAmountOfMoney();
				CheckWalletMoney(checkpoint, cost, MoneyWallet);
				NewAmountOfMoney = MoneyWallet - cost;
				setAmountOfMoney(NewAmountOfMoney);
					
			} while (checkpoint == false);
			TypeOfExpenses(cost);
		}
	}
	else if (choice == 2)
	{
		if (DebitCardVector.size() == 0)
		{
			choice = 0;
			system("cls");
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 19);
			cout << "you haven't any Debit card" << endl;
			ShowMenu::gotoXY(50, 20);
			system("pause");
		}
		else
		{
			ShowMenu::print_menu_debitcards(DebitCardVector, 50, 19, choice);
			system("cls");

			if (DebitCardVector[choice - 1].getBalance() == 0)
			{
				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "you haven't money" << endl;
				ShowMenu::gotoXY(50, 20);
				system("pause");
			}

			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 19);
			cout << "enter how much is this->";
			cin >> cost;
			do
			{
				MoneyCard = DebitCardVector[choice - 1].getBalance();
				CheckWalletMoney(checkpoint, cost, MoneyCard);
				NewAmountOfMoney = MoneyCard - cost;
				DebitCardVector[choice - 1].setBalance(NewAmountOfMoney);

			} while (checkpoint == false);
			TypeOfExpenses(cost);
		}
	}
	else if (choice == 3)
	{
		if (CreditCardVector.size() == 0)
		{
			choice = 0;
			system("cls");
			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 19);
			cout << "you haven't any Credit card" << endl;
			ShowMenu::gotoXY(50, 20);
			system("pause");
		}
		else
		{
			ShowMenu::print_menu_creditcards(CreditCardVector, 50, 19, choice);
			system("cls");

			if (CreditCardVector[choice - 1].getBalance() == 0)
			{
				ShowMenu::setColor(4);
				ShowMenu::gotoXY(50, 19);
				cout << "you haven't money" << endl;
				ShowMenu::gotoXY(50, 20);
				system("pause");
			}

			ShowMenu::setColor(4);
			ShowMenu::gotoXY(50, 19);
			cout << "enter how much is this->";
			cin >> cost;
			do
			{
				MoneyCard = CreditCardVector[choice - 1].getBalance();
				CheckWalletMoney(checkpoint, cost, MoneyCard);
				NewAmountOfMoney = MoneyCard - cost;
				CreditCardVector[choice - 1].setBalance(NewAmountOfMoney);

			} while (checkpoint == false);
			TypeOfExpenses(cost);
		}
	}
}
