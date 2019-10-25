#include "TypingSession.hpp"

TypingSession::TypingSession()
{
	username = "";
	date = "";
	SessionID = "";
	TypingTest = Test();
}

TypingSession::TypingSession(string _username)
{
	username = _username;
	TypingTest = Test();
	date = "";
	SessionID = "";
}
TypingSession::~TypingSession()
{

}

void TypingSession::StartSession()
{
	selectTest();
}

Result TypingSession::getTestResults()
{
	Result test = Result();
	return test;
}

void TypingSession::selectTest()
{
	string input;
	cout << "Please select difficulty level: \n 1) EASY \n 2) MEDIUM \n 3) HARD \n 4) PYTHON \n 5) CSS \n 6) CPP \n 7) TYPESCRIPT \n";
	cin >> input;
	TypingTest.beginTest(input);
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