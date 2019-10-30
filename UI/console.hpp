#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "../Domain/Sessions/TypingSession.hpp"
#include "../Domain/Test/Result.hpp"
using namespace std;
class ConsoleView
{
private:
	TypingSession sess;
public:
	ConsoleView();
	~ConsoleView();
	void displayOptions();
	void displayTestStart();
	void displayLoginOptions();
	void captureUserLoginInfo(string& un, string& pw);
	void createNewUser();
	void authenticateUser();
	void displayChoices();
};