#pragma
#include <string>
#include "../Test/Progress.hpp"
using namespace std;

class User
{
public:
  User();
  ~User();
  Progress viewProgress();
  void changePassword(string);
  void makePayment(string);
private:
  std::string username;
  std::string password;
  bool membership;
  Progress history;
};
