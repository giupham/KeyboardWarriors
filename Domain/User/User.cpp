#include "User.hpp"
#include <filesystem>
//new user
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
			if (pSess->getOrderID() == "1")
				cout << "Monthly Subscription Purchased!" << endl;
			else if (pSess->getOrderID() == "2")
				cout << "Yearly Subscription Purchased!" << endl;
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
	membership = isMember;
	try {
		profileWrite();
		subscription.membershipActive = 1;
	}
	catch (exception& ex)
	{
		cerr << ex.what() << endl;
	}
}

void User::changePassword(string new_pw)
{
	password = new_pw;
	try {
		profileWrite();
	}
	catch (exception& ex) {
		cerr << ex.what() << endl;
	}

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
	options.push_back("3) Make Payment");
	options.push_back("4) Logout");
	return options;
 }

 void User::newProfile(string _username, string _password)
 {
	 string profile_path = "../../TechServices/Persistence/User_Profiles/" + _username + ".txt";
	 //CHECK IF PROFILE ALREADY EXISTS
	 if (ifstream(profile_path))
		 throw invalid_argument("Username already Exists\n");
	 //CREATING NEW PROFILE
	 ofstream file;
	 file.open(profile_path);
	 if (!file.is_open())
		 throw invalid_argument("Unable to open: " + profile_path + "\n");
	 file << "username\\\\" << _username << endl;
	 file << "password\\\\" << _password << endl;
	 file << "membership\\\\" << membership << endl;
	 file << "WPM\\\\0" << endl;
	 file << "history" << endl;
	 file.close();

	 //SETTING THE USERNAME, PASSWORD, AND INITIALIZING THE HISTORY
	 setUsername(_username);
	 setPassword(_password);
	 history = Progress(username);
 }

 void User::profileWrite()
 {
	 string profile_path = "../../TechServices/Persistence/User_Profiles/" + username + ".txt";
	 ifstream input_file(profile_path);
	 if (!input_file.is_open())
		 throw invalid_argument("Unable to locate Profile\n");
	 string input;
	 vector<string> lines;
	 while (getline(input_file, input))
		 lines.push_back(input);

	 for (auto& line : lines)
	 {
		 size_t found = line.find("password");
		 if (found != string::npos)
			 line = "password\\\\" + password;
		 found = line.find("membership");
		 if (found != string::npos)
		 {
			 string member = (membership)?"1":"0";
			 line = "membership\\\\" + member;

		 }

	 }
	 input_file.close();

	 ofstream output_file(profile_path);
	 for (auto const& line : lines)
		 output_file << line << endl;
	 output_file.close();

 }

 bool User::setOrderID(string sub)
 {
	 system("CLS");
	 char input;
	 bool loop = true;
	 do {
		 cout << "Please select your Payment Program \n 1) Paypal \n 2) Visa \n";
		 cin >> input;
		 if (input == '1' || input == '2')
			 loop = false;
	 } while (loop);

	 if (input == '1')
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
	 cout << "Please enter Payment Info: " << endl;
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

