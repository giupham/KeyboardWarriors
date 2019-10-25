#include "Test.hpp"
#include <sstream>

using namespace std;

#define CLOCKS_PER_SEC ((std::clock_t)1000);

Test::Test()
{
	WPM = 0;
	path = "";
	testResult = Result();
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
	getTestWordCount(path);
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
		testResult = calculateWPM(path, duration, inputContent);
		cout << "WPM: " << WPM << endl;
	}
	myfile.close();
}

Result Test::calculateWPM(string path, double duration, string inputContent) {
	int wordsCorrect = 0;
	int wordsTotal = 1;
	int count = 0;
	int seeker = 0;
	count = getTestWordCount(path);
	//compare inputContent to file content
	string inputContentLine = "";
	string currFileLine = "";

	ifstream myfile(path);
	if (myfile.is_open()) {
		while (getline(myfile, currFileLine)) {
			inputContentLine = inputContent.substr(seeker, inputContentLine.find('\n'));
			//compare the inputLine to the fileContentLine
			if (currFileLine.compare(inputContentLine)) {
				//detect missed space by detecting inputContentLine.length() < fileContentLine.length()
				istringstream sstream = istringstream();
			}
			//move seeker to position for next line
			seeker = inputContentLine.length();
		}
	}

	testResult.putWPM(wordsCorrect/wordsTotal);
	return testResult;
}

int Test::getTestWordCount(string path) {
	string word;
	int count = 0;
	ifstream myfile;
	myfile.open(path);
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			myfile >> word;
			cout << word << endl;
			count++;
		}
		//cout << "Number of words in file are " << count << endl;
	}
	myfile.close();
	cin >> word;
	return count;
}



