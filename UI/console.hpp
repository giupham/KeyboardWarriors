#pragma once

#include <vector>
#include <string>
#include "../Domain/Sessions/TypingSession.hpp"
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
};