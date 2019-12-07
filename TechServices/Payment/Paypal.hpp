#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "../../TechServices/Logging/Log.hpp"
#include "Payment.hpp"
using namespace std;

class Paypal : public Payment
{
public:
	//constructor
	Paypal();
	virtual ~Paypal();

	//functions
	bool CreatePayment();
	bool SetPaymentInfo();
	bool GetPaymentInfo();
	bool EditPaymentInfo();
	bool AuthorizePaymentInfo();
	string CreateOrder(string purchaseItemID);
	bool UpdateOrder(string orderID);
	bool GetOrderInfo(string orderID);
	bool AuthorizePaymentForOrder(string orderID);
	bool CapturePaymentForOrder(string orderID);
	void LogErr(string msg);
};