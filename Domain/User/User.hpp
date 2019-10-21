#pragma
#include <string>
#include <vector>
#include "../Test/Progress.hpp"
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
	  ~User();
	  bool getMembership();
	  void setMembership(bool);
	  std::string getUsername();
	  void setUsername(std::string);
	  void encryptPassword(std::string);


	  vector<string> getOptions();
	  Progress viewProgress();
	  void changePassword(string newPassword);
	  void makePayment();
	  Session requestTypingTest();

};
