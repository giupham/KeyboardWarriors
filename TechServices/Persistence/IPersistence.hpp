#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class IPersistenceHandler {
protected:
	string profile_path;

public:
	virtual bool new_profile(string username, string password) = 0;
	virtual bool change_password(string password) = 0;
	virtual bool update_Membership(bool membership) = 0;
	virtual bool update_History(int avg_WPM, int new_WPM, string session_ID) = 0;
};