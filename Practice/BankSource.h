#pragma once

#include <iostream>
#include <string>

using namespace std;

int Bankchoice = 0;

int walletchoice = 0;

string wallet_choice[2]
{
	"show information about the cards inside this wallet",
	"Manage current wallet"
};

string mass[2]
{
	"Set name for this wallet",
	"leave as default"
};

string report_menu[3]
{
	"Day",
	"Week",
	"Month"
};

string top_3[4]
{
	"TOP 3 Week by Money",
	"TOP 3 Month by Money",
	"TOP 3 Week by Category",
	"TOP 3 Month by Category"
};