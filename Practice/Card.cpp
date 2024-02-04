#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

#include "Card.h"

using namespace std;

Card::Card(string name) : name{ name }, balance{ 0 }, numberOfCard{ new int[numberOfCardSize] },
ValidityPeriod{ new int[ValidityPeriodSize] }, CVV{ new int[CVVSize] }
{
	GenerateNumberOfCard(numberOfCard, numberOfCardSize);
	ValidityPeriodGenerate(ValidityPeriod);
	CVVGenerate(CVV, CVVSize);
}

void Card::CVVGenerate(int mas[], int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 10;
}

void Card::ValidityPeriodGenerate(int mas[])
{
	mas[0] = rand() % 12 + 1;
	mas[1] = rand() % 31 + 1;
}

void Card::GenerateNumberOfCard(int mas[], int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 10;
}

Card::~Card() {}
