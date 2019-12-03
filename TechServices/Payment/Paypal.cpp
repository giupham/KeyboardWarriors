#include "Paypal.hpp"
using namespace std;

Paypal::Paypal() {
	Token = "";
	time(&Date);
	UserID = "";
	orderID = "";
	purchaseItemID = "";
}

Paypal::~Paypal() {

}

bool Paypal::setCreditInfo(string fname, string lname, string creditNum, string secureCode, string expDate) {
	creditInfo.FirstName = fname;
	creditInfo.LastName = lname;
	creditInfo.creditNum = creditNum;
	creditInfo.secureCode = secureCode;
	creditInfo.expDate = expDate;
	return true;
}

bool Paypal::set_purchaseItemID(string pItemID) {
	purchaseItemID = pItemID;
	return true;
}

bool Paypal::TryPurchaseMonth(string purchaseItemID, Credit cc) {
	return true;
}

bool Paypal::TryPurchaseYear(string purchaseItemID, Credit cc) {
	return true;
}

