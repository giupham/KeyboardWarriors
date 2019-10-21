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
	  vector<string> getOptions();
	  Progress viewProgress();
	  void changePassword(string newPassword);
	  void makePayment();
	  Session requestTypingTest();

};
