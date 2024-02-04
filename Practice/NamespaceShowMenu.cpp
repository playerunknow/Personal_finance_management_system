#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "Wallet.h"
#include "CreditCard.h"
#include "DebitCard.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

namespace ShowMenu
{
	void gotoXY(short column, short row)
	{
		COORD coord{ column, row };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void setColor(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	int print_menu(string mass[], int size, int gotoX, int gotoY, int& choice)
	{
		choice = 0;
		char button;
		while (true)
		{
			system("cls");

			for (int i = 0; i < size; i++)
			{
				if (i == choice)
				{
					gotoXY(gotoX, gotoY + i);
					cout << "> ";

					setColor(4); 
					cout << mass[i] << endl;
				}
				else
				{
					gotoXY(gotoX + 2, gotoY + i);
					setColor(7);
					cout << mass[i] << endl;
				}
			}

			button = _getch();

			PlaySound(TEXT("updown.wav"), NULL, SND_ASYNC);

			switch (button)
			{
			case 'w':
				if (choice > 0) choice--;
				break;
			case 's':
				if (choice < (size - 1)) choice++;
				break;

			default:
				break;
			}

			if (button == VK_RETURN)
			{
				PlaySound(TEXT("select.wav"), NULL, SND_ASYNC);
				return choice++;
				Sleep(1000);
				break;
			}
		}
	}

	int print_menu_wallet(vector<Wallet> vector, int gotoX, int gotoY, int& choice)
	{
		choice = 0;
		char button;
		while (true)
		{
			system("cls");

			for (int i = 0; i < vector.size(); i++)
			{
				if (i == choice)
				{
					gotoXY(gotoX, gotoY + i);
					cout << "> ";

					setColor(4);
					cout << "Name: " << vector[i].getName(); cout << "Balance: " << vector[i].getAmountOfMoney();
				}
				else
				{
					gotoXY(gotoX + 2, gotoY + i);
					setColor(7);
					cout << "Name: " << vector[i].getName(); cout << "Balance: " << vector[i].getAmountOfMoney();
				}
			}

			button = _getch();

			PlaySound(TEXT("updown.wav"), NULL, SND_ASYNC);

			switch (button)
			{
			case 'w':
				if (choice > 0) choice--;
				break;
			case 's':
				if (choice < (vector.size() - 1)) choice++;
				break;

			default:
				break;
			}

			if (button == VK_RETURN)
			{
				PlaySound(TEXT("select.wav"), NULL, SND_ASYNC);
				return choice++; //deleted++
				Sleep(1000);
				break;
			}
		}
	}
	
	int print_menu_debitcards(vector<DebitCard> vector, int gotoX, int gotoY, int& choice)
	{
		choice = 0;
		char button;
		while (true)
		{
			system("cls");

			for (int i = 0; i < vector.size(); i++)
			{
				if (i == choice)
				{
					gotoXY(gotoX, gotoY + i);
					cout << "> ";

					setColor(4); 
					cout << "Name: " << vector[i].getName(); cout << "Balance: " << vector[i].getBalance();
				}
				else
				{
					gotoXY(gotoX + 2, gotoY + i);
					setColor(7);
					cout << "Name: " << vector[i].getName(); cout << "Balance: " << vector[i].getBalance();
				}
			}

			button = _getch();

			PlaySound(TEXT("updown.wav"), NULL, SND_ASYNC);

			switch (button)
			{
			case 'w':
				if (choice > 0) choice--;
				break;
			case 's':
				if (choice < (vector.size() - 1)) choice++;
				break;

			default:
				break;
			}

			if (button == VK_RETURN)
			{
				PlaySound(TEXT("select.wav"), NULL, SND_ASYNC);
				return choice++; // deleetd ++
				Sleep(1000);
				break;
			}
		}
	}

	int print_menu_creditcards(vector<CreditCard> vector, int gotoX, int gotoY, int& choice)
	{
		choice = 0;
		char button;
		while (true)
		{
			system("cls");

			for (int i = 0; i < vector.size(); i++)
			{
				if (i == choice)
				{
					gotoXY(gotoX, gotoY + i);
					cout << "> ";

					setColor(4);
					cout << "Name: " << vector[i].getName(); cout << "Balance: " << vector[i].getBalance();
				}
				else
				{
					gotoXY(gotoX + 2, gotoY + i);
					setColor(7);
					cout << "Name: " << vector[i].getName(); cout << "Balance: " << vector[i].getBalance();
				}
			}

			button = _getch();

			PlaySound(TEXT("updown.wav"), NULL, SND_ASYNC);

			switch (button)
			{
			case 'w':
				if (choice > 0) choice--;
				break;
			case 's':
				if (choice < (vector.size() - 1)) choice++;
				break;

			default:
				break;
			}

			if (button == VK_RETURN)
			{
				PlaySound(TEXT("select.wav"), NULL, SND_ASYNC);
				return choice++;
				Sleep(1000);
				break;
			}
		}
	}
}