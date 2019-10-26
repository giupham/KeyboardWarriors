#pragma once
#ifndef TYPINGSESSION_H
#define TYPINGSESSION_H
#include "../Test/Test.hpp"
#include "../Test/Result.hpp"
//#include "../Test/Difficulty.hpp"
#include <string>
//#include <ctime>
//#include <chrono>
//#include <fstream>
#include "../User/User.hpp"
#include <iostream>

using namespace std;
#pragma once
class TypingSession
{
private:
	string date;
	string SessionID;
	Test TypingTest;
	double TimeTaken;

public:
	TypingSession();
	~TypingSession();
	User SessionUser;
	bool authenticated = false;
	void StartSession(string selectedTest);
	Result getTestResults();
	//string getTimeStr();
	string selectTest(string input);
	void beginTest();
};

#endif
