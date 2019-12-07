#include "console.hpp"


ConsoleView::ConsoleView() {
	sess = Session();
	//// run new test files through here
	//sess.TypingTest.title = "CPP2.txt";
	//sess.TypingTest.reformatFileContentForWindowsChars("../../TypingTests/" + sess.TypingTest.title);
}

ConsoleView::~ConsoleView() {

}

void ConsoleView::displayOptions() {
	bool loop = true;
	char input;
	do
	{
		sess.StartSession();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "Press q to Return to Main Menu \nPress y to begin another test. \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> input;
		if (input == 'q')
			loop = false;
	} while (loop);
}

void ConsoleView::displayLoginOptions() {
	string input;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Welcome. Are you an existing user or new user?" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "1) Existing User" << endl;
	cout << "2) New User" << endl;
	cin >> input;
	system("CLS");

	bool success = false;
	if (input == "1") {
		authenticateUser();
	}
	if (input == "2") {
		createNewUser();
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "Password Changed!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Sleep(1000);
		system("CLS");
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "New Password does not match Re-entered Password.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Sleep(1500);
		system("CLS");
		changePassword();
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
			cerr << ex.what();
			cerr << "Please try again.\n\n";
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
		if (input == '1') {
			displayOptions();
		}
		else if (input == '2')
			sess.SessionUser.viewProgress();
		else if (input == '3') {
			displayPurchaseOptions();
		}
		else if (input == '4') {
			changePassword();
		}
		else if (input == '5')
			exit_system = true;
		system("CLS");
	} while (!exit_system);
}

void ConsoleView::displayPurchaseOptions() {
	string input = "";
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Please select subscription to purchase: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "1) Monthly Subscription " << endl;
	cout << "2) Yearly Subscription " << endl;
	cin >> input;
	if (input == "1")
		sess.SessionUser.setOrderID("Monthly");
	else if (input == "2")
		sess.SessionUser.setOrderID("Yearly");
	system("CLS");
}