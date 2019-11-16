#pragma once
#include "../../Domain/Test/Test.hpp"
#include "../../Domain/User/User.hpp"
#include <string>
#include <iostream>

using namespace std;
#pragma once
class ISession
{
private:
	string date;
	string SessionID;
	double TimeTaken;

public:
	Test TypingTest;
	User SessionUser;
	bool authenticated = false;

	virtual void StartSession(string selectedTest) = 0;
	virtual Result getTestResults() = 0;
	virtual string selectTest(string) = 0;
	virtual void updateProgress(Progress&, Result) = 0;
};
