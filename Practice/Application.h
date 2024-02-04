#pragma once


#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include "Bank.h"

using namespace std;

class Application
{
private:
	static const int size = 6;
	string* MenuItem;

public:
	Application();

	void Run(Bank& bank);

	void SwitchMenuItem(Bank& bank);

	void Intro();

	~Application()
	{
		delete[] MenuItem; cout << "MenuItem was deleted ";
	}
};