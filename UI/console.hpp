#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "../Domain/Sessions/Session.hpp"
using namespace std;
class ConsoleView
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