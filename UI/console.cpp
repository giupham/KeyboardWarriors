#include "console.hpp"
#include "../Domain/Sessions/TypingSession.hpp"

ConsoleView::ConsoleView() {
	selection = displayOptions();
	displayTestRules(selection);
}

ConsoleView::~ConsoleView() {

}

string ConsoleView::displayOptions() {
	string input = "";
	cout << "Please select difficulty level: \n 1) EASY \n 2) MEDIUM \n 3) HARD \n 4) PYTHON \n 5) CSS \n 6) CPP \n 7) TYPESCRIPT \n";
	cin >> input;

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

void ConsoleView::displayTestRules(string selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "This is a line by line typing test." << endl;
	cout << "Please press 'Enter' at the end of each line to move to the next line.\n" << endl;
	cout << "Please press 'Enter' to start the clock." << endl;
	cin.ignore();
	if (cin.get() == '\n') {
		system("CLS");
		TypingSession newSession = TypingSession();
		newSession.StartSession(selection);
	}
}