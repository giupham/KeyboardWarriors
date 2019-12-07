#pragma once
#include <string>
#include "Log.h"
using namespace std;

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

