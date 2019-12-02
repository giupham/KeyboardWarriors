#include "Session.hpp"

Session::Session()
{
	authenticated = false;
	SessionUser = User();
	date = "";
	SessionID = "";
	TypingTest = NULL;
	/*
	TypingTest.setPath("../../TypingTests/CSS.txt");
	TypingTest.reformatFileContentForWindowsChars(TypingTest.getPath());
	*/
}

Session::~Session()
{
	delete TypingTest;
}

void Session::StartSession() {
	//cout << "running\n";
	if(SessionUser.getMembership())
		TypingTest = new MemTest();
	else
		TypingTest = new FreeTest();
		
	TypingTest->beginTest();
	updateProgress(SessionUser.history, TypingTest->testResult);
}

Result Session::getTestResults()
{
	return TypingTest->testResult;
}


void Session::updateProgress(Progress &newProgress, Result res) {
	newProgress.updateResults(to_string(newProgress.get_sess_num() + 1), res);
}
