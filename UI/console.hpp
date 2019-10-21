#pragma once

#include <vector>
#include <string>
using namespace std;
class ConsoleView
{
private:
public:
	ConsoleView();
	~ConsoleView();
	void displayOptions(vector<string>);
	std::string getInput();
};