#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;
class ConsoleView
{
	public:
		ConsoleView();
		~ConsoleView();
		string displayOptions();
		void displayTestRules(string selected);
	private:
		string selection;
};