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
	title = "";
}

Test::~Test()
{
}

// WHICH TEST TO IMPLEMENT 
void Test::beginTest(string selectedTest)
{
	clock_t start;
	double duration = 0;

	string inputContent;
	string line;
	string lineNext;
	path = "../../TypingTests/" + selectedTest;
	ifstream myfile(path);
	string currInput;
	if (myfile.is_open()) {
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



