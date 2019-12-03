#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "../../KeyboardWarriorsTypingTestApp/KeyboardWarriorsTypingTestApp/IPaymentServices.h"
using namespace std;

class Paypal: public IPaymentServices
{
private:
	string Token;
	time_t Date;
	string UserID;
	Credit creditInfo;
	string purchaseItemID;
	string orderID;

public:
	Paypal();
	~Paypal();
	string getOrderID() { return orderID; };
	void setOrderID(string oID) { orderID = oID; };
	bool setCreditInfo(string fname, string lname, string creditNum, string secureCode, string expDate);
	bool TryPurchaseMonth(string purchaseItemID, Credit);
	bool TryPurchaseYear(string purchaseItemID, Credit);
	string get_purchaseItemID() { return purchaseItemID; };
	bool set_purchaseItemID(string);

	bool CreatePayment() {
		cout << "Payment Created by Paypal!" << endl;
		return true;
	}

	bool SetPaymentInfo() {
		cout << "Payment Info Set by Paypal!" << endl;
		return true;
	}

	bool GetPaymentInfo() {
		cout << "Payment Details gotten by Paypal!" << endl;
		return true;
	}

	bool EditPaymentInfo() {
		cout << "Go to Edit Payment Info by Paypal!" << endl;
		return true;
	}

	bool AuthorizePaymentInfo() {
		cout << "Authorized Payment Info by Paypal!" << endl;
		return true;
	}

	string CreateOrder(string purchaseItemID) {
		cout << "Order Created by Paypal!" << endl;
		return "OrderIDTest";
	}

	bool UpdateOrder(string orderID) {
		cout << "Updated Order by Paypal!" << endl;
		return true;
	}

	bool GetOrderInfo(string orderID) {
		cout << "Order Details gotten by Paypal!" << endl;
		return true;
	}

	bool AuthorizePaymentForOrder(string orderID) {
		cout << "Payment Authorized for Order by Paypal!" << endl;
		return true;
	}

	bool CapturePaymentForOrder(string orderID) {
		cout << "Payment Made, Order Submitted by Paypal!" << endl;
		return true;
	}
};
