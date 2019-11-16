#include "Session.hpp"

Session::Session()
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

Session::~Session()
{

}

void Session::StartSession(string input) {
	//cout << "running\n";
	TypingTest.title = selectTest(input);
	TypingTest.beginTest(TypingTest.title);
	updateProgress(SessionUser.history, TypingTest.testResult);
}

string Session::selectTest(string input)
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

Result Session::getTestResults()
{
	return TypingTest.testResult;
}


void Session::updateProgress(Progress &newProgress, Result res) {
	newProgress.updateResults(to_string(newProgress.get_sess_num() + 1), res);
}