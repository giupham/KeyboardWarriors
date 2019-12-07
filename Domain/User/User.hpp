#pragma once
#include "../../KeyboardWarriorsTypingTestApp/KeyboardWarriorsTypingTestApp/IUser.h"
using namespace std;

#define IS_PAYPAL true

class User : public IUser
{
	private:
		std::string username;
		std::string password;
		bool membership;
		Subscription subscription;
		Payment* pSess;
		UserProfile _profile;

	public:
	  Progress history;

	  User();
	  //previous user
	  User(string, string);
	  //User(const User&);
	  ~User();
	  bool getMembership();
	  void setMembership(bool);
	  string getUsername();
	  void setUsername(string);
	  void setPassword(string);

	  //void encryptPassword(std::string);
	  void readProfile();
	  void newProfile(string username, string password);
	  //void profileWrite();

	  vector<string> getOptions();
	  void viewProgress();
	  void changePassword(string newPassword);
	  bool makePayment();
	  bool createOrder(string purchaseItemID);
	  bool setOrderID(string);
	  void CapturePaymentInfo();

	  bool updateHistory(int, int, string);
};
