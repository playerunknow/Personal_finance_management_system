#pragma once

#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>

#include "CreditCard.h"
#include "DebitCard.h"

class Bank;

using namespace std;

class Wallet
{

protected:
	string name;
	double AmountOfMoney;
	vector<DebitCard> DebitCardVector;
	vector<CreditCard> CreditCardVector;
	
public:
	Wallet(string name) : name{ name }, AmountOfMoney{ 0 }
	{}

	Wallet() : Wallet("Default")
	{}

	int getCountDebitCards() const { return DebitCardVector.size(); }
	int getCountCreditCards() const { return CreditCardVector.size(); }
	double getAmountOfMoney() const { return AmountOfMoney; }
	string getName() const { return name; }

	void setAmountOfMoney(double m) { AmountOfMoney = m; }

	void setName(string n) { name = n; }

	//void createNewWallet(Bank& bank);
	void AddCards();
	void ReplenishmentWallet();
	void showWalletCards();
	void inputOfCost();

	void show() const;

	~Wallet()
	{
	}
};