#include "console.hpp"


ConsoleView::ConsoleView() {
	sess = Session();
	/*// run new test files through here
	sess.TypingTest.title = "CPP2.txt";
	sess.TypingTest.reformatFileContentForWindowsChars("../../TypingTests/" + sess.TypingTest.title);
	*/
}

ConsoleView::~ConsoleView(){

}

void ConsoleView::displayOptions() {
	bool loop = true;
	char input;
	do
	{
		sess.StartSession();
		cout << "\nPress q to Quit \nPress y to continue \n";
		cin >> input;
		if (input == 'q')
			loop = false;
	} while (loop);
}

void ConsoleView::displayLoginOptions() {
	string input;
	cout << "Welcome. Are you an existing user or new user?" << endl;
	cout << "1) Existing User" << endl;
	cout << "2) New User" << endl;
	cout << "3) Change Password" << endl;
	cin >> input;
	system("CLS");

	bool success = false;
	if (input == "1") {
		authenticateUser();
	}
	if (input == "2") {
		createNewUser();
	}
	if (input == "3") {
		changePassword();
	}
}

void ConsoleView::captureUserLoginInfo(string& un, string& pw) {
	cout << "Username: ";
	cin >> un;
	cout << "Password: ";
	cin >> pw;
	system("CLS");
}

void ConsoleView::changePassword() {
	string pw = "";
	string pw_copy = "";
	authenticateUser();
	cout << "New Password: ";
	cin >> pw;
	cout << "Confirm Password: ";
	cin >> pw_copy; 
	if (pw == pw_copy)
	{
		sess.SessionUser.changePassword(pw);
		system("CLS");
		cout << "Password Changed!" << endl;
		Sleep(2000);
		system("CLS");
	}
	else
	{
		cout << "New Password does not match Re-entered Password.\n"; 
	}
	
}

void ConsoleView::createNewUser() {
	string un = "";
	string pw = "";
	while (sess.authenticated == false) {
		captureUserLoginInfo(un, pw);
		try {
			sess.SessionUser.newProfile(un, pw);
			sess.authenticated = true;
		}
		catch (exception & ex) {
			cerr << ex.what() << endl;
			cerr << "Please try again.\n";
		}
	}
}

void ConsoleView::authenticateUser() {
	string un = "";
	string pw = "";
	while (sess.authenticated == false) {
		captureUserLoginInfo(un, pw);
		try {
			sess.SessionUser = User(un, pw);
			sess.authenticated = true;
		}
		catch (exception & ex) {
			cerr << ex.what() << endl;
			cerr << "Please try again.\n";
		}
	}
}

void ConsoleView::displayChoices()
{
	bool exit_system = false;
	do {
		vector<string> options = sess.SessionUser.getOptions();
		char input;
		for (const auto& line : options)
			cout << line << endl;
		cin >> input;
		system("CLS");
		if (input == '1')
			displayOptions();
		else if (input == '2')
			sess.SessionUser.viewProgress();
		else if (input == '3') {
			displayPurchaseOptions();
		}
		else if (input == '4')
			exit_system = true;
	} while (!exit_system);
}

void ConsoleView::displayPurchaseOptions() {
	string input = "";
	system("CLS");
	cout << "Select Purchase Item: Please type the Selection ID and press 'Enter'" << endl;
	cout << "1) Monthly Subscription " << endl;
	cout << "2) Yearly Subscription " << endl;
	cin >> input;
	if (input == "1")
		sess.SessionUser.setOrderID("Monthly");
	else if (input == "2")
		sess.SessionUser.setOrderID("Yearly");
	system("CLS");
}

