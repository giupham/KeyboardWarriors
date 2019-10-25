#pragma
#include <string>
#include <vector>
#include "../Test/Progress.hpp"
#include "../Sessions/TypingSession.hpp"
using namespace std;

class User
{
	
	private:
		std::string username;
		std::string password;
		bool membership;
		Progress history;

	public:
	  User();
	  //previous user
	  User(string, string);
	  ~User();
	  bool getMembership();
	  void setMembership(bool);
	  string getUsername();
	  void setUsername(std::string);
	  void encryptPassword(std::string);
	  void readProfile();
	  


	  vector<string> getOptions();
	  void viewProgress();
	  void changePassword(string newPassword);
	  bool makePayment();
	  TypingSession requestTypingTest();

};
