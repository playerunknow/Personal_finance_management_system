#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

using namespace std;

class Card
{
protected:
	string name;
	double balance;
	static const int numberOfCardSize = 16;
	static const int ValidityPeriodSize = 2;
	static const int CVVSize = 3;
	int* numberOfCard;
	int* ValidityPeriod;
	int* CVV;

public:
	Card(string name);
	Card() : Card("Default Card") {}

	string getName() const { return name; }
	double getBalance() const { return balance; }

	void setBalance(double b) { balance = b; }
	void setName(string n) { n = name; }

	virtual void show(int gotoY) const = 0;

	void CVVGenerate(int mas[], int size);
	void ValidityPeriodGenerate(int mas[]);
	void GenerateNumberOfCard(int mas[], int size);

	virtual ~Card() = 0;
};