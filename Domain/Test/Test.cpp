#include "Test.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Test::Test()
{
	testEnded = false;
}

Test::~Test()
{
	testEnded = false;
}

// WHICH TEST TO IMPLEMENT 
void Test::beginTest(string input)
{
	string title;
	if (input == "1") {
		title = "Alice1.txt";
	}
    else if (input == "2") {
		title = "Alice2.txt";
	}
	else if (input == "3") {
		title = "Alice3.txt";
	}
	else if (input == "4") {
		title = "Py.txt";
	}
	else if (input == "5") {
		title = "CSS.txt";
	}
	else if (input == "6") {
		title = "CPP.txt";
	}
	else if (input == "7") {
		title = "TS.txt";
	}
	else
		title = "Alice1.txt";
  
	string line;
	string lineNext;
	ifstream myfile(title);
	string currInput;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (getline(myfile, lineNext)) {
					cout << line << '\n';
					cout << lineNext << '\n';
				}
			else {
				cout << line << '\n';
			}
			cin >> currInput;
		}
	}
}

