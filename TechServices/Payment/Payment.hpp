#pragma
#include <string>
#include <ctime>
using namespace std;

struct Credit {
	std::string FirstName;
	std::string LastName;
	std::string creditNum;
	std::string expDate;
	std::string secureCode;
};

class Payment
{
private:
	std::string Token;
	std::time_t Date;
	std::string UserID;
	Credit creditInfo;


public:
	Payment();
	~Payment();
	bool TryPurchaseMonth(Credit);
	bool TryPurchaseYear(Credit);
	void setCreditInfo(std::string fname, std::string lname, std::string creditNum, std::string secureCode, std::string expDate);
	



};
