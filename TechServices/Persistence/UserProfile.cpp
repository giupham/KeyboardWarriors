#include "UserProfile.hpp"

UserProfile::UserProfile()
{
}

UserProfile::UserProfile(string username)
{
	profile_path = "../../TechServices/Persistence/User_Profiles/" + username + ".txt";
}

UserProfile::~UserProfile()
{

}

bool UserProfile::new_profile(string username, string password)
{
	if (ifstream(profile_path))
	{
		cout << "Username, " << username << ", Already exists\n";
		return false;
	}

	write_profile.open(profile_path);
	if (!write_profile.is_open())
	{
		cout << "Unable to open " << profile_path << endl;
		return false;
	}
	write_profile << "username\\\\" << username << endl;
	write_profile << "password\\\\" << password << endl;
	write_profile << "membership\\\\0" << endl;
	write_profile << "WPM\\\\0" << endl;
	write_profile << "history" << endl;
	write_profile.close();

	cout << "Successfully created new profile for " << username << endl;
	return true;
}

bool UserProfile::change_password(string password)
{
	read_profile.open(profile_path);
	//CHECK IF YOU CAN OPEN
	if (!read_profile.is_open())
	{
		cout << "Unable to open " << profile_path << endl;
		return false;
	}
	string input;
	vector<string> lines;
	//PUSHING FILE INTO VECTOR
	while (getline(read_profile, input))
		lines.push_back(input);
	//CHANGING PASSWORD
	for (auto& line : lines)
	{
		size_t found = line.find("password");
		if (found != string::npos)
			line = "password\\\\" + password;
	}
	read_profile.close();
	//WRITE CHANGES INTO PROFILE
	write_profile.open(profile_path);
	for (auto const& line : lines)
		write_profile << line << endl;
	write_profile.close();

	cout << "Successfully changed the password\n";
	return true;
}

bool UserProfile::update_Membership(bool membership)
{
	read_profile.open(profile_path);
	//CHECK IF YOU CAN OPEN
	if (!read_profile.is_open())
	{
		cout << "Unable to open " << profile_path << endl;
		return false;
	}
	string input;
	vector<string> lines;

	//PUSHING FILE INTO VECTOR
	while (getline(read_profile, input))
		lines.push_back(input);

	//CHANGING MEMBERSHIP
	for (auto& line : lines)
	{
		size_t found = line.find("membership");
		if (found != string::npos)
		{
			string member = (membership) ? "1" : "0";
			line = "membership\\\\" + membership;
		}
	}
	read_profile.close();

	//WRITE CHANGES INTO PROFILE
	write_profile.open(profile_path);
	for (auto const& line : lines)
		write_profile << line << endl;
	write_profile.close();

	cout << "Successfully change membership\n";
	return true;
}

bool UserProfile::update_History(int avg_WPM, int new_WPM, int session_ID)
{
	read_profile.open(profile_path);
	if (!read_profile.is_open())
	{
		cout << "Unable to open " << profile_path << endl;
		return false;
	}
	string input;
	vector<string> lines;
	while (getline(read_profile, input))
		lines.push_back(input);

	for (auto& line : lines)
	{

		size_t found = line.find("WPM");
		if (found != string::npos)
		{
			line = "WPM\\\\" + to_string(avg_WPM);
		}
	}
	read_profile.close();
	//ADDING NEW RESULT INTO PROFILE
	string new_session = session_ID + "\\\\" + to_string(new_WPM);
	lines.push_back(new_session);

	//PUTTING CHANGES BACK INTO THE PROFILE TXT
	write_profile.open(profile_path);
	for (auto const& line : lines)
		write_profile << line << endl;
	write_profile.close();

	cout << "Successfully updated the History\n";
	return true;
}