#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../../Domain/Test/Progress.hpp"
#include "../../TechServices/Payment/Payment.hpp"
#include "../../TechServices/Payment/Paypal.hpp"
#include "../../TechServices/Payment/Visa.hpp"
#include "../../TechServices/Payment/Subscription.hpp"
using namespace std;

class IUser
{
private:
	string username;
	string password;
	bool membership;
	Payment* pSess;
	Subscription subscription;

public:
	Progress history;

	virtual bool getMembership() = 0;
	virtual void setMembership(bool) = 0;
	virtual string getUsername() = 0;
	virtual void setUsername(string) = 0;
	virtual void setPassword(string) = 0;
	virtual Payment getPayment() = 0;

	//void encryptPassword(std::string) = 0;
	virtual void readProfile() = 0;
	virtual void newProfile(string username, string password) = 0;
	virtual void profileWrite() = 0;

	virtual vector<string> getOptions() = 0;
	virtual void viewProgress() = 0;
	virtual void changePassword(string newPassword) = 0;
	virtual bool makePayment(Payment pSess) = 0;
	virtual bool createOrder(string purchaseItemID) = 0;
};
