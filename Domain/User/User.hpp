#pragma
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../Test/Progress.hpp"
#include "../../TechServices/Payment/Payment.hpp"
#include "../../TechServices/Payment/Subscription.hpp"
using namespace std;

class User
{
	private:
		std::string username;
		std::string password;
		bool membership;
		Payment pSess;
		Subscription subscription;

	public:
	  Progress history;

	  User();
	  //previous user
	  User(string, string);
	  ~User();
	  bool getMembership();
	  void setMembership(bool);
	  string getUsername();
	  void setUsername(string);
	  void setPassword(string);
	  Payment getPayment() { return pSess; };

	  //void encryptPassword(std::string);
	  void readProfile();
	  void newProfile(string username, string password);
	  void profileWrite();

	  vector<string> getOptions();
	  void viewProgress();
	  void changePassword(string newPassword);
	  bool makePayment(Payment pSess);
	  bool createOrder(string purchaseItemID);
};
