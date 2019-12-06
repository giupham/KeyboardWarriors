#include "User.hpp"
User::User()
{
	username = "";
	password = "";
	membership = false;
	pSess = NULL;
}

User::~User()
{
}

//existing user
User::User(string _username, string _password)
{
	username = _username;
	password = _password;
	membership = false;
	try {
		readProfile();
	}
	catch (exception& ex)
	{
		throw ex;
	}
	_profile = UserProfile(username);
	history = Progress(username);
}

// copy constructor
User::User(const User& obj)
{
	username = obj.username;
	password = obj.password;
	membership = obj.membership;
	history = Progress(username);
}

void User::readProfile()
{
	string profile_path = "../../TechServices/Persistence/User_Profiles/" + username + ".txt";
	ifstream file(profile_path);
	string _username = "";
	string _password = "";
	bool _membership = false;
	if (!file.is_open())
		throw invalid_argument("Invalid Username.\n");
	else
	{
		string line = "";
		//get USER NAME
		getline(file, line);
		size_t found = line.find("\\");
		if(found != string::npos)
		{
			found += 2;
			_username = line.substr(found, line.size() - 1);
		}
		//get password
		getline(file, line);
		found = line.find("\\");
		if (found!= string::npos)
		{
			found += 2;
			_password = line.substr(found, line.size() - 1);
		}
		//get membership
		getline(file, line);
		found = line.find("\\");
		if (found != string::npos)
		{
			found += 2;
			string is_member = line.substr(found, found + 1);
			if (is_member == "1")
				_membership = true;
			else if (is_member == "0")
				_membership = false;
			else
				throw invalid_argument("Can't determine member. Value -> " + is_member + "\n");
			//changes the membership if needed
			membership = _membership;
		}

		if (username != _username)
			throw invalid_argument("Username does not match argument in profile.\n");
		if (password != _password)
			throw invalid_argument("Password is not correct!\n");
		//Close file
		file.close();
	}
}
// New User
bool User::getMembership() {
	return membership;
}


void User::setUsername(string _username)
{
	username = _username;
}
void User::setPassword(string _password)
{
	password = _password;
}

string User::getUsername() {
	return username;
}

bool User::createOrder(string purchaseItemID) {

	//making payment
	pSess->setOrderID(pSess->CreateOrder(purchaseItemID));
	if (pSess->getOrderID() != "") {
		bool success = makePayment();
		if (success) {
			setMembership(1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			if (pSess->getOrderID() == "1")
				cout << "Monthly Subscription Purchased!" << endl;
			else if (pSess->getOrderID() == "2")
				cout << "Yearly Subscription Purchased!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Press 'Enter' to Continue...\n";
			cin.ignore();
			if (cin.get() == '\n') {
				return true;
			}
		}
	}
	return true;
}

bool User::makePayment()
{
	
	pSess->CreatePayment();
	pSess->SetPaymentInfo();
	pSess->AuthorizePaymentInfo();
	cout << "Confirm purchase by pressing 'Enter'. (Payment not yet completed.)\n";
	cin.ignore();
	if (cin.get() == '\n') {
		pSess->AuthorizePaymentForOrder(pSess->getOrderID());
		pSess->CapturePaymentForOrder(pSess->getOrderID());
		return true;
	}
	else
		return false;
}


void User::setMembership(bool isMember) {
	_profile.update_Membership(isMember);
	subscription.membershipActive = 1;
}

void User::changePassword(string new_pw)
{
	_profile.change_password(new_pw);
}

void User::viewProgress()
{
	try {
		history = Progress(username);
		history.print_results();
	}
	catch (exception& ex)
	{
		cerr << ex.what() << endl;
		cerr << "New Profile?\n" << endl;
	}
}

 vector<string> User::getOptions() {
 	vector<string> options;
	options.push_back("1) Request Typing Test");
 	options.push_back("2) View Personal Progress");
	options.push_back("3) Purchase Subscription");
	options.push_back("4) Change Password");
	options.push_back("5) Logout");
	return options;
 }

 void User::newProfile(string _username, string _password)
 {
	 _profile.new_profile(_username, _password);

	 //SETTING THE USERNAME, PASSWORD, AND INITIALIZING THE HISTORY
	 setUsername(_username);
	 setPassword(_password);
	 history = Progress(username);
 }

 bool User::setOrderID(string sub)
 {
	 system("CLS");
	 /*char input;
	 bool loop = true;
	 do {
		 cout << "Please select your Payment Program \n 1) Paypal \n 2) Visa \n";
		 cin >> input;
		 if (input == '1' || input == '2')
			 loop = false;
	 } while (loop);*/

	 if (IS_PAYPAL)
		 pSess = new Paypal();
	 else
		 pSess = new Visa();
	 //setting order id
	 pSess->setOrderID(sub);
	 //capture payment info
	 CapturePaymentInfo();
	 return true;
 }

 void User::CapturePaymentInfo()
 {
	 system("CLS");
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	 cout << "Please enter Payment Info: " << endl;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	 string fname, lname, creditNum, secureCode, expDate;
	 cout << "F Name: ";
	 cin >> fname;
	 cout << "L Name: ";
	 cin >> lname;
	 cout << "CC#: ";
	 cin >> creditNum;
	 cout << "CRV#: ";
	 cin >> secureCode;
	 cout << "Exp Date: ";
	 cin >> expDate;

	 if (pSess->setCreditInfo(fname, lname, creditNum, secureCode, expDate))
	 {
		 system("CLS");
		 pSess->CreateOrder(pSess->getOrderID());
		 cin.ignore();
		 if (cin.get() == '\n')
			 system("CLS");
	 }

 }

