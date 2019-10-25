#include "Test.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>
#include <ctime>

using namespace std;

#define CLOCKS_PER_SEC ((std::clock_t)1000);

Test::Test()
{
	WPM = 0;
}

Test::~Test()
{
	WPM = 0;
}

// WHICH TEST TO IMPLEMENT 
void Test::beginTest(string input)
{
	string title;
	clock_t start;
	double duration;
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
  
	string line;
	string lineNext;
	ifstream myfile("../../TypingTests/" + title);
	string currInput;
	if (myfile.is_open()) {
		cout << "Please press Enter to start the clock." << endl;
		if (cin.get() == '\n') {
			start = clock();
			if (getline(myfile, line)) {
				while (getline(myfile, lineNext)) {
					cout << line << '\n';
					cout << lineNext << '\n';
					cin >> currInput;
					line = lineNext;
				}
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			}
		}
	}
	myfile.close();
}

double calculateWPM(string filename, double duration) {
	int wordsCorrect = 0;
	int wordsTotal = 0;

	return wordsCorrect / wordsTotal;
}





