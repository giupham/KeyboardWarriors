#include "Visa.hpp"

bool Visa::CreatePayment() {
	cout << "Payment Created by Visa!" << endl;
	return true;
}

bool Visa::SetPaymentInfo() {
	cout << "Payment Info Set by Visa!" << endl;
	return true;
}

bool Visa::GetPaymentInfo() {
	cout << "Payment Details gotten by Visa!" << endl;
	return true;
}

bool Visa::EditPaymentInfo() {
	cout << "Go to Edit Payment Info by Visa!" << endl;
	return true;
}

bool Visa::AuthorizePaymentInfo() {
	cout << "Authorized Payment Info by Visa!" << endl;
	return true;
}

string Visa::CreateOrder(string purchaseItemID) {
	cout << "Order Created by Visa!" << endl;
	return "OrderIDTest";
}

bool Visa::UpdateOrder(string orderID) {
	cout << "Updated Order by Visa!" << endl;
	return true;
}

bool Visa::GetOrderInfo(string orderID) {
	cout << "Order Details gotten by Visa!" << endl;
	return true;
}

bool Visa::AuthorizePaymentForOrder(string orderID) {
	cout << "Payment Authorized for Order by Visa!" << endl;
	return true;
}

bool Visa::CapturePaymentForOrder(string orderID) {
	cout << "Payment Made, Order Submitted by Visa!" << endl;
	return true;
}