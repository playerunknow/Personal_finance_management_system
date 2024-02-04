#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

using namespace std;

class DebitCard : public Card
{
public:
	DebitCard(string name) : Card(name) {}
	DebitCard() : Card("Defaul Debit Card") {}

	DebitCard(const DebitCard& DebitCard)
	{
		name = DebitCard.name;
		balance = DebitCard.balance;
		numberOfCard = new int[DebitCard.numberOfCardSize];
		ValidityPeriod = new int[DebitCard.ValidityPeriodSize];
		CVV = new int[DebitCard.CVVSize];

		for (int i = 0; i < numberOfCardSize; i++)
			numberOfCard[i] = DebitCard.numberOfCard[i];

		for (int i = 0; i < ValidityPeriodSize; i++)
			ValidityPeriod[i] = DebitCard.ValidityPeriod[i];

		for (int i = 0; i < CVVSize; i++)
			CVV[i] = DebitCard.CVV[i];
	}

	virtual void show(int gotoY) const override;

	virtual ~DebitCard() override
	{
		delete[] numberOfCard; 
		delete[] ValidityPeriod;  
		delete[] CVV;
	}
};