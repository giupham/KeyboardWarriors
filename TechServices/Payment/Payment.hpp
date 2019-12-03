#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "../../KeyboardWarriorsTypingTestApp/KeyboardWarriorsTypingTestApp/IPaymentServices.h"
using namespace std;

class Payment: public IPaymentServices
{
protected:
	string Token;
	time_t Date;
	string UserID;
	Credit creditInfo;
	string purchaseItemID;
	string orderID;

public:
	Payment();
	~Payment();
	string getOrderID() { return orderID; };
	void setOrderID(string oID) { orderID = oID; };
	bool setCreditInfo(string fname, string lname, string creditNum, string secureCode, string expDate);
	bool TryPurchaseMonth(string purchaseItemID, Credit);
	bool TryPurchaseYear(string purchaseItemID, Credit);
	string get_purchaseItemID() { return purchaseItemID; };
	bool set_purchaseItemID(string);

	virtual bool CreatePayment();
	virtual bool SetPaymentInfo();
	virtual bool GetPaymentInfo();
	virtual bool EditPaymentInfo();
	virtual bool AuthorizePaymentInfo();
	virtual string CreateOrder(string purchaseItemID);
	virtual bool UpdateOrder(string orderID);
	virtual bool GetOrderInfo(string orderID);
	virtual bool AuthorizePaymentForOrder(string orderID);
	virtual bool CapturePaymentForOrder(string orderID);
};