#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

#include "Card.h"


using namespace std;


class CreditCard : public Card
{
public:
	CreditCard(string n) : Card(n) {}
	CreditCard() : Card("Defaul Credit Card") {}

	CreditCard(const CreditCard& CreditCard)
	{
		name = CreditCard.name;
		balance = CreditCard.balance;
		numberOfCard = new int[CreditCard.numberOfCardSize];
		ValidityPeriod = new int[CreditCard.ValidityPeriodSize];
		CVV = new int[CreditCard.CVVSize];

		for (int i = 0; i < numberOfCardSize; i++)
			numberOfCard[i] = CreditCard.numberOfCard[i];

		for (int i = 0; i < ValidityPeriodSize; i++)
			ValidityPeriod[i] = CreditCard.ValidityPeriod[i];

		for (int i = 0; i < CVVSize; i++)
			CVV[i] = CreditCard.CVV[i];
	}

	virtual void show(int gotoY) const override;

	virtual ~CreditCard() override
	{
		delete[] numberOfCard;
		delete[] ValidityPeriod;
		delete[] CVV;
	}
};