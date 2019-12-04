#include "Payment.hpp"
using namespace std;


Payment::Payment() {
	Token = "";
	time(&Date);
	UserID = "";
	orderID = "";
	purchaseItemID = "";


	
	time_t rawtime;
	tm now;
	time(&rawtime);
	localtime_s(&now, &rawtime);


	/*time_t clock = time(0);
	tm* now = localtime(&clock);
	*/
	current_time = to_string(now.tm_mon+1) + "-" 
				+ to_string(now.tm_mday) + "-" 
				+ to_string(now.tm_year + 1900) + "__"
				+ to_string(now.tm_hour) + "-"
				+ to_string(now.tm_min) + "-"
				+ to_string(now.tm_sec);
	
	cout << current_time << endl;

	log_path = "../Logging/" + current_time + ".txt";


	cout << log_path << endl;

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