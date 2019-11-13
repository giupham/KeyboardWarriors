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
	//cout << "running\n";
	TypingTest.title = selectTest(input);
	TypingTest.beginTest(TypingTest.title);
	updateProgress(SessionUser.history, TypingTest.testResult);
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
	return TypingTest.testResult;
}


void TypingSession::updateProgress(Progress &newProgress, Result res) {
	newProgress.updateResults(to_string(newProgress.get_sess_num() + 1), res);
}