#include "Payment.hpp"
using namespace std;


Payment::Payment() {
	Token = "";
	time(&Date);
	UserID = "";
	orderID = "";
	purchaseItemID = "";

}

Payment::~Payment() {

}

bool Payment::setCreditInfo(string fname, string lname, string creditNum, string secureCode, string expDate) {
	creditInfo.FirstName = fname;
	creditInfo.LastName = lname;
	creditInfo.creditNum = creditNum;
	creditInfo.secureCode = secureCode;
	creditInfo.expDate = expDate;
	return true;
}

bool Payment::set_purchaseItemID(string pItemID) {
	purchaseItemID = pItemID;
	return true;
}

bool Payment::TryPurchaseMonth(string purchaseItemID, Credit cc) {
	return true;
}

bool Payment::TryPurchaseYear(string purchaseItemID, Credit cc) {
	return true;
}

bool Payment::CreatePayment() { return true; }
bool Payment::SetPaymentInfo() { return true; }
bool Payment::GetPaymentInfo() { return true; }
bool Payment::EditPaymentInfo() { return true; }
bool Payment::AuthorizePaymentInfo() { return true; }
string Payment::CreateOrder(string purchaseItemID) 
{ 
	CreatePayment();
	return "true";
}
bool Payment::UpdateOrder(string orderID) { return true; }
bool Payment::GetOrderInfo(string orderID) { return true; }
bool Payment::AuthorizePaymentForOrder(string orderID) { return true; }
bool Payment::CapturePaymentForOrder(string orderID) { return true; }