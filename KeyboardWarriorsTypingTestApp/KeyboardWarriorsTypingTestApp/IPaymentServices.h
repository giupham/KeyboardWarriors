#pragma once
#include <string>
using namespace std;


struct Credit {
	string FirstName;
	string LastName;
	string creditNum;
	string expDate;
	string secureCode;
};

class IPaymentServices
{
public:
	virtual bool CreatePayment() = 0;
	virtual bool SetPaymentInfo() = 0;
	virtual bool GetPaymentInfo() = 0;
	virtual bool EditPaymentInfo() = 0;
	virtual bool AuthorizePaymentInfo() = 0;
	virtual string CreateOrder(string purchaseItemID) = 0;
	virtual bool UpdateOrder(string orderID) = 0;
	virtual bool GetOrderInfo(string orderID) = 0;
	virtual bool AuthorizePaymentForOrder(string orderID) = 0;
	virtual bool CapturePaymentForOrder(string orderID) = 0;
};

