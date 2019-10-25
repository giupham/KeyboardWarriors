#include "TypingSession.hpp"

TypingSession::TypingSession()
{
	date = "";
	SessionID = "";
	TypingTest = Test();
}

TypingSession::~TypingSession()
{

}

void TypingSession::StartSession(string selectedTest)
{
	TypingTest.beginTest(selectedTest);
}

Result TypingSession::getTestResults()
{
	Result test = Result();
	return test;
}

////get time and date
//string TypingSession::getTimeStr()
//{
//    // time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
//
//    string s(30, '\0');
//    // strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", localtime_s(&now));
//    return s;
//}