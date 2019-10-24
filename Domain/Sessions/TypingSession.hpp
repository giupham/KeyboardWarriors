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
#include <iostream>

using namespace std;
#pragma once
class TypingSession
{
private:
	string date;
	string SesssionID;
	Test TypingTest;
	double TimeTaken;

public:
	TypingSession();
	~TypingSession();
	void StartSession();
	Result getTestResults();
	//string getTimeStr();
	void selectTest();

};

#endif
