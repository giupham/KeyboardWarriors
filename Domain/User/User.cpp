#include "User.hpp"

//new user       
User::User()
{
	username = "";
	password = "";
	membership = false;
	
}

User::~User()
{

}

//existing user
User::User(string _username, string _password)
{
	username = _username;
	password = _password;
	try {
		readProfile();
	}
	catch (exception& ex)
	{
		throw ex;
	}
	membership = false;
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

bool User::makePayment()
{
	return true;
}

//wait til sessions is done
//bool User::requestTypingTest()
//{
//	TypingSession ts = TypingSession(username);
//	ts.selectTest();
//	
//	return true;
//}

void User::setMembership(bool isMember) {
	membership = isMember;
	try {
		profileWrite();
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
	options.push_back("1) Request Typing Test\n");
 	options.push_back("2) View Personal Progress\n");
	return options;
 }

 void User::newProfile(string _username, string _password)
 {
	 string profile_path = "../../KeyboardWarriorsTypingTestApp/User_Profiles/" + _username + ".txt";
	 ofstream file(profile_path);
	 file << "username\\\\" << _username << endl;
	 file << "password\\\\" << _password << endl;
	 file << "membership\\\\" << membership << endl;
	 file << "WPM\\\\0" << endl;
	 file << "history" << endl;
	 file.close();

	 setUsername(_username);
	 setPassword(_password);
	 history = Progress(username);
 }

 void User::profileWrite()
 {
	 string profile_path = "../../KeyboardWarriorsTypingTestApp/User_Profiles/" + username + ".txt";
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