#include "Session.hpp"

Session::Session()
{
	authenticated = false;
	SessionUser = User();
	date = "";
	SessionID = "";
	/*
	TypingTest.setPath("../../TypingTests/CSS.txt");
	TypingTest.reformatFileContentForWindowsChars(TypingTest.getPath());
	*/
}

Session::~Session()
{

}

void Session::StartSession() {
	//cout << "running\n";
	if(SessionUser.getMembership())
		TypingTest = MemTest();
	else
		TypingTest = RegTest();
		
	TypingTest.beginTest();
	updateProgress(SessionUser.history, TypingTest.testResult);
}

Result Session::getTestResults()
{
	return TypingTest.testResult;
}


void Session::updateProgress(Progress &newProgress, Result res) {
	newProgress.updateResults(to_string(newProgress.get_sess_num() + 1), res);
}
