#pragma once
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
	void gotoXY(short column, short row);

	void setColor(int color);

	int print_menu(string mass[], int size, int gotoX, int gotoY, int& choice);
	
	int print_menu_wallet(vector<Wallet> vector, int gotoX, int gotoY, int& choice);

	int print_menu_debitcards(vector<DebitCard> vector, int gotoX, int gotoY, int& choice);

	int print_menu_creditcards(vector<CreditCard> vector, int gotoX, int gotoY, int& choice);
}