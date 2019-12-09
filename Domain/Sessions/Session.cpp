#include "Session.hpp"

Session::Session()
{
	authenticated = false;
	SessionUser = User();
	date = "";
	SessionID = "";
	TypingTest = NULL;
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
	int avg_WPM = 0;
	int new_WPM = 0;
	newProgress.updateResults(to_string(newProgress.get_sess_num() + 1), res, avg_WPM, new_WPM);

	SessionUser.updateHistory(avg_WPM, new_WPM, to_string(newProgress.get_sess_num()));
}
