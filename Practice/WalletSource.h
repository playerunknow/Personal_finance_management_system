#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

extern int choice;

// input of cost
extern string category;
extern double cost;

extern string add_cards[2];
extern string cards[2];
extern string set_name_card[2];
extern string replenishment[2];
extern string put_money_from[2];
extern string type_of_card[3];

//input of cost
extern string DayWeekMonth[3];
extern string InputOfCost[3];
extern string TypeOfCost[3];
extern string PettyExpenses[4];
extern string AverageCosts[3];
extern string MajorExpenses[4];


extern multimap<string, double> Day;
extern multimap<string, double> Week;
extern multimap<string, double> Month;

extern multimap<double, string> Top3WeekbyCategory;
extern multimap<double, string> Top3MonthbyCategory;
extern multimap<double, string> Top3WeekbyMoney;
extern multimap<double, string> Top3MonthByMoney;