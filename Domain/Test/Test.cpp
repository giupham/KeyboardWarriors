#include "Test.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>
#include <ctime>
#include <list>
#include <Windows.h>

using namespace std;

#define CLOCKS_PER_SEC ((std::clock_t)1000);

Test::Test()
{
	WPM = 0;
	path = "";
}

Test::~Test()
{
}

// WHICH TEST TO IMPLEMENT 
void Test::beginTest(string input)
{
	string title;
	clock_t start;
	double duration = 0;
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

	string inputContent;
	string line;
	string lineNext;
	ifstream myfile("../../TypingTests/" + title);
	string currInput;
	string _pressToStart;
	if (myfile.is_open()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "This is a line by line typing test." << endl;
		cout << "Please press 'Enter' at the end of each line to move to the next line.\n" << endl;
		cout << "Please press 'Enter' to start the clock." << endl;
		cin.ignore();
		if (cin.get() == '\n') {
			system("CLS");
			start = clock();
			if (getline(myfile, line)) {
				while (getline(myfile, lineNext)) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << line << '\n';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					cout << lineNext << '\n';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					getline(cin, currInput);
					system("CLS");
					inputContent += currInput + '\n';
					line = lineNext;
				}
				cout << line << '\n';
				getline(cin, currInput);
				inputContent += currInput + '\n';
			}
			duration = (clock() - (double)start) / (double)CLOCKS_PER_SEC;
		}
		path = "../../TypingTests/" + title;
		WPM = calculateWPM(path, duration, inputContent);
		cout << "WPM: " << WPM << endl;
	}
	myfile.close();
}

int Test::calculateWPM(string path, double duration, string inputContent) {
	int wordsCorrect = 0;
	int wordsTotal = 1;
	int count = 0;
	int seeker = 0;
	count = getTestWordCount(path);
	//compare inputContent to file content
	string currInputContentLine = "";
	string currFileLine = "";

	ifstream myfile(path);
	if (myfile.is_open()) {
		while (getline(myfile, currFileLine)) {
			currInputContentLine = inputContent.substr(seeker, currInputContentLine.find('\n'));
			/*compare the inputLine to the fileContentLine
			if (currFileLine.compare(currInputContentLine)*/

			//move seeker to position for next line
			seeker = currInputContentLine.length();
		}
	}

	return wordsCorrect / wordsTotal;
}

int Test::getTestWordCount(string path) {
	string word;
	int count = 0;
	ifstream myfile;
	myfile.open(path);
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			myfile >> word;
			count++;
		}
		//cout << "Number of words in file are " << count << endl;
	}
	myfile.close();
	return count;
}



