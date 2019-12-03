#include "Visa.hpp"
using namespace std;

Visa::Visa() {
	Token = "";
	time(&Date);
	UserID = "";
	orderID = "";
	purchaseItemID = "";
}

Visa::~Visa() {

}

bool Visa::setCreditInfo(string fname, string lname, string creditNum, string secureCode, string expDate) {
	creditInfo.FirstName = fname;
	creditInfo.LastName = lname;
	creditInfo.creditNum = creditNum;
	creditInfo.secureCode = secureCode;
	creditInfo.expDate = expDate;
	return true;
}

bool Visa::set_purchaseItemID(string pItemID) {
	purchaseItemID = pItemID;
	return true;
}

bool Visa::TryPurchaseMonth(string purchaseItemID, Credit cc) {
	return true;
}

bool Visa::TryPurchaseYear(string purchaseItemID, Credit cc) {
	return true;
}