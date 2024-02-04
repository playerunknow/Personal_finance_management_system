#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include<fstream>

#include "Wallet.h"

using namespace std;


class Bank
{
private:
	int CountOFWallets;
	vector<Wallet> Wallets;

public:

	Bank() : CountOFWallets{ 0 }, Wallets(CountOFWallets) {}

	void CreateWallet();
	int getCountOFWallets() const { return Wallets.size(); }
	void ManageWallet();
	void Replenishment();
	void InputOfCost();
	void ShowReport();
	void ShowRatings();
	void print_map(multimap<string, double> multimap) const;
	void print_map_top3(multimap<double, string> multimap);

	void MakeReportTOP3WeekByMoney(multimap<string, double> map);
	void MakeReportTOP3MonthByMoney(multimap<string, double> map);
	void MakeReportTOP3WeekByCategory(multimap<string, double> multimap);
	void MakeReportTOP3MonthByCategory(multimap<string, double> multimap);

	void WriteIntoFile(multimap<string, double> multimap, string WhenItWas);
	void WriteIntoFile(multimap<double, string> multimap, string WhenItWas);

	void SaveAllMultimapsIntoFile();

	~Bank() 
	{ 
	}
};