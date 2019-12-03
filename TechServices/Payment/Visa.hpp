#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "../../KeyboardWarriorsTypingTestApp/KeyboardWarriorsTypingTestApp/IPaymentServices.h"
using namespace std;

class Visa: public IPaymentServices
{
private:
	string Token;
	time_t Date;
	string UserID;
	Credit creditInfo;
	string purchaseItemID;
	string orderID;

public:
	Visa();
	~Visa();
	string getOrderID() { return orderID; };
	void setOrderID(string oID) { orderID = oID; };
	bool setCreditInfo(string fname, string lname, string creditNum, string secureCode, string expDate);
	bool TryPurchaseMonth(string purchaseItemID, Credit);
	bool TryPurchaseYear(string purchaseItemID, Credit);
	string get_purchaseItemID() { return purchaseItemID; };
	bool set_purchaseItemID(string);

	bool CreatePayment() {
		cout << "Payment Created by Visa!" << endl;
		return true;
	}

	bool SetPaymentInfo() {
		cout << "Payment Info Set by Visa!" << endl;
		return true;
	}

	bool GetPaymentInfo() {
		cout << "Payment Details gotten by Visa!" << endl;
		return true;
	}

	bool EditPaymentInfo() {
		cout << "Go to Edit Payment Info by Visa!" << endl;
		return true;
	}

	bool AuthorizePaymentInfo() {
		cout << "Authorized Payment Info by Visa!" << endl;
		return true;
	}

	string CreateOrder(string purchaseItemID) {
		cout << "Order Created by Visa!" << endl;
		return "OrderIDTest";
	}

	bool UpdateOrder(string orderID) {
		cout << "Updated Order by Visa!" << endl;
		return true;
	}

	bool GetOrderInfo(string orderID) {
		cout << "Order Details gotten by Visa!" << endl;
		return true;
	}

	bool AuthorizePaymentForOrder(string orderID) {
		cout << "Payment Authorized for Order by Visa!" << endl;
		return true;
	}

	bool CapturePaymentForOrder(string orderID) {
		cout << "Payment Made, Order Submitted by Visa!" << endl;
		return true;
	}
};