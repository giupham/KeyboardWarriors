#include "TypingSession.hpp"

TypingSession::TypingSession()
{
	authenticated = false;
	SessionUser = User();
	date = "";
	SessionID = "";
	TypingTest = Test();
	/*
	TypingTest.setPath("../../TypingTests/CSS.txt");
	TypingTest.reformatFileContentForWindowsChars(TypingTest.getPath());
	*/
}

TypingSession::~TypingSession()
{

}

void TypingSession::StartSession(string input) {
	TypingTest.title = selectTest(input);
}

string TypingSession::selectTest(string input)
{
	string title = "";
	if (input == "1")
		title = "Alice1.txt";
	else if (input == "2")
		title = "Alice2.txt";
	else if (input == "3")
		title = "Alice3.txt";
	else if (input == "4")
		title = "Py.txt";
	else if (input == "5")
		title = "CSS.txt";
	else if (input == "6")
		title = "CPP.txt";
	else
		title = "Alice1.txt";
	return title;
}

Result TypingSession::getTestResults()
{
	Result test = Result();
	return test;
	updateProgress(SessionUser.history);
}

void TypingSession::beginTest() {
	TypingTest.beginTest(TypingTest.title);
}

void TypingSession::updateProgress(Progress &newProgress) {

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