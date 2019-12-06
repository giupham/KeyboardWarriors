#pragma once
#ifndef Session_H
#define Session_H
#include "../Sessions/ISession.h"
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
	Test* TypingTest;
	User SessionUser;
	bool authenticated = false;

	Session();
	~Session();

	void StartSession();
	Result getTestResults();
	void updateProgress(Progress&, Result);
};

#endif
