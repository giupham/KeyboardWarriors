#pragma once
#include "../../Domain/Test/Test.hpp"
#include "../../Domain/Test/MemTest.hpp"
#include "../../Domain/Test/FreeTest.hpp"
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

	virtual void StartSession() = 0;
	virtual Result getTestResults() = 0;
	virtual void updateProgress(Progress&, Result) = 0;
};
