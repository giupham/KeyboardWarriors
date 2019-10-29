#include "console.hpp"


ConsoleView::ConsoleView() {
	sess = TypingSession();
}

ConsoleView::~ConsoleView(){

}

void ConsoleView::captureUserLoginInfo(string& un, string& pw) {
	cout << "Username: ";
	cin >> un;
	cout << "Password: ";
	cin >> pw;
	system("CLS");
}

void ConsoleView::displayOptions() {
	system("CLS");
	string input;
	cout << "Please select difficulty level: \n 1) EASY \n 2) MEDIUM \n 3) HARD \n 4) PYTHON \n 5) CSS \n 6) CPP \n 7) TYPESCRIPT \n";
	cin >> input;
	displayTestStart();
	sess.StartSession(input);
}

void ConsoleView::displayTestStart() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	system("CLS");
	cout << "This is a line by line typing test." << endl;
	cout << "Please press 'Enter' at the end of each line to move to the next line.\n" << endl;
	cout << "Please press 'Enter' to start the clock." << endl;
	cin.ignore();
	if (cin.get() == '\n') {
		system("CLS");
		//sess.beginTest();
	}
}

void ConsoleView::displayLoginOptions() {
	string input;
	cout << "Welcome. Are you an existing user or new user?" << endl;
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
		else if (input == '3')
			exit_system = false;
		else if (input == '4')
			exit_system = true;
	} while (!exit_system);
}