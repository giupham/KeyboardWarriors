#include "Paypal.hpp"

Paypal::Paypal() :Payment()
{
}

Paypal::~Paypal()
{
}

bool Paypal::CreatePayment() {

	return true;
}

bool Paypal::SetPaymentInfo() {
	Log("Payment Info Set by Paypal!\n");
	return true;
}

bool Paypal::GetPaymentInfo() {
	Log("Payment Details gotten by Paypal!\n");
	return true;
}

bool Paypal::EditPaymentInfo() {
	Log("Go to Edit Payment Info by Paypal!\n");
	return true;
}

bool Paypal::AuthorizePaymentInfo() {
	Log("Authorized Payment Info by Paypal!\n");
	return true;
}

string Paypal::CreateOrder(string purchaseItemID) {
	Log(orderID + " Order Created by Paypal!\n");
	return orderID;
}

bool Paypal::UpdateOrder(string orderID) {
	Log("Updated Order by Paypal!\n");
	return true;
}

bool Paypal::GetOrderInfo(string orderID) {
	Log("Order Details gotten by Paypal!\n");
	return true;
}

bool Paypal::AuthorizePaymentForOrder(string orderID) {
	Log("Payment Authorized for Order by Paypal!\n");
	return true;
}

bool Paypal::CapturePaymentForOrder(string orderID) {
	Log("Payment Made, Order Submitted by Paypal!\n");
	return true;
}