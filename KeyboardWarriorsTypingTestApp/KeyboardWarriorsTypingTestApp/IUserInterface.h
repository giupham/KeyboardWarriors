#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "../../Domain/Sessions/Session.hpp"
using namespace std;

class IUserInterface
{
private:
	Session sess;
public:
	virtual void displayOptions() = 0;
	virtual void displayLoginOptions() = 0;
	virtual void captureUserLoginInfo(string& un, string& pw) = 0;
	virtual void changePassword() = 0;
	virtual void createNewUser() = 0;
	virtual void authenticateUser() = 0;
	virtual void displayChoices() = 0;
	virtual void displayPurchaseOptions() = 0;
	virtual void displayCapturePaymentInfo() = 0;
}; 
