#include "User.hpp"


User::User()
{
	username = "";
	password = "";
	membership = false;
	
}

User::~User()
{

}

User::User(string _username, string _password)
{
	username = _username;
	password = _password;
	try {
		readProfile();
	}
	catch (exception& ex)
	{
		cerr << ex.what() << endl;
		username = "";
		password = "";
	}
}
void User::readProfile()
{
	string profile_path = "../../KeyboardWarriorsTypingTestApp/User_Profiles/" + username + ".txt";
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
void User::setMembership(bool isMember) {
	membership = isMember;
}

void User::setUsername(string _username)
{
	username = _username;
}

string User::getUsername() {
	return username;
}
void User::changePassword(string new_pw)
{
	password = new_pw;
}

bool User::makePayment()
{
	return true;
}

//wait til sessions is done
TypingSession User::requestTypingTest()
{
	TypingSession ts = TypingSession(username);
	ts.selectTest();
	return ts;
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
	options.push_back("1) Request Typing Test\n");
 	options.push_back("2) View Personal Progress\n");
	return options;
 }
