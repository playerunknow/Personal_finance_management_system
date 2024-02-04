#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "WalletSource.h"

using namespace std;

int choice = 0;

// input of cost
string category;
double cost;

string add_cards[2]
{
	"Add Debit Card ",
	"Add Credit card "
};

string cards[2]
{
	"Debit Card ",
	"Credit card "
};

string set_name_card[2]
{
	"Set name for this card",
	"leave by default"
};

string replenishment[2]
{
	"Replanish This Wallet",
	"Replanish Cards which has this wallet"
};

string put_money_from[2]
{
 "Put money from From wallet ",
 "Put money fromFrom IBOX "
};

string type_of_card[3]
{
	"Debit Card ",
	"Credit card ",
	"exit from this"
};

//input of cost

string DayWeekMonth[3]
{
	"Current Day",
	"Current Week",
	"Current Moth"
};

string InputOfCost[3]
{
	"Wallet",
	"Debit Card ",
	"Credit card "
};

string TypeOfCost[3]
{
	"petty expenses",
	"Average costs",
	"Major expenses"
};

string PettyExpenses[4]
{
	"products",
	"travel",
	"household expenses"
};

string AverageCosts[3]
{
	"clothes",
	"entertainment",
	"small household appliances"
};

string MajorExpenses[4]
{
	"furniture",
	"vacation",
	"repair",
	"Large home appliances"
};


multimap<string, double> Day;
multimap<string, double> Week;
multimap<string, double> Month;

multimap<double, string> Top3WeekbyCategory;
multimap<double, string> Top3MonthbyCategory;

multimap<double, string> Top3WeekbyMoney;
multimap<double, string> Top3MonthByMoney;