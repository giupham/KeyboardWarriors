#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "../KeyboardWarriorsTypingTestApp/KeyboardWarriorsTypingTestApp/IUserInterface.h"
using namespace std;

class ConsoleView: public IUserInterface
{
private:
	Session sess;
public:
	ConsoleView();
	~ConsoleView();
	void displayOptions();
	void displayTestStart();
	void displayLoginOptions();
	void captureUserLoginInfo(string& un, string& pw);
	void changePassword();
	void createNewUser();
	void authenticateUser();
	void displayChoices();
	void displayPurchaseOptions();
	void displayCapturePaymentInfo();
};