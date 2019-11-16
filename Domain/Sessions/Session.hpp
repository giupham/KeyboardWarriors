#pragma once
#ifndef Session_H
#define Session_H
#include "../../KeyboardWarriorsTypingTestApp/KeyboardWarriorsTypingTestApp/ISession.h"
#include <string>
#include <iostream>

using namespace std;
#pragma once
class Session : public ISession
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
