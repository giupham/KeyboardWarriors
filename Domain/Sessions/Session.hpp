#pragma once
#ifndef Session_H
#define Session_H
#include "../Test/Test.hpp"
#include "../Test/Result.hpp"
#include "../User/User.hpp"
#include <string>
#include <iostream>

using namespace std;
#pragma once
class Session
{
private:
	string date;
	string SessionID;
	double TimeTaken;

public:
	Test TypingTest;
	User SessionUser;
	bool authenticated = false;

	Session();
	~Session();

	void StartSession(string selectedTest);
	Result getTestResults();
	string selectTest(string input);
	void updateProgress(Progress&, Result);
};

#endif
