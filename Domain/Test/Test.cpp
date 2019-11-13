#include "Test.hpp"
#include <sstream>

using namespace std;

#define CLOCKS_PER_SEC ((std::clock_t)1000);

Test::Test()
{
	path = "";
	title = "";
}

Test::~Test()
{
}

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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << line << '\n';
			getline(cin, currInput);
			inputContent += currInput + '\n';
		}
		duration = (clock() - (double)start) / (double)CLOCKS_PER_SEC;
		if (calculateWPM(path, duration, inputContent)) {
			calculateWPM(path, duration, inputContent);
			viewResults(testResult);
		}
	}
	myfile.close();
}

bool Test::calculateWPM(string path, double duration, string inputContent) {
	int wordsCorrect = 0;
	int wordsTotal = 0;
	int count = 0;
	int seeker = 0;
	//compare inputContent to file content
	string inputContentLine = "";
	string currFileLine = "";

	ifstream myfile(path);
	if (myfile.is_open()) {
		istringstream sstreamInput = istringstream();
		istringstream sstreamFile = istringstream();
		string word1 = "";
		string word2 = "";
		int charCountInputLine = 0;
		int charCountFileLine = 0;
		int wordCountInputLine = 0;
		int wordCountFileLine = 0;
		int indexEndl = 0;

		while (getline(myfile, currFileLine)) {
			//trim \n
			inputContentLine = inputContent.substr(seeker, inputContentLine.find('\n'));
			indexEndl = inputContentLine.find_last_of("\n", inputContentLine.length());
			inputContentLine = inputContent.substr(seeker, indexEndl);

			sstreamInput.str(inputContentLine);
			sstreamFile.str(currFileLine);
			charCountInputLine = sstreamInput.gcount();
			charCountFileLine = sstreamFile.gcount();

			while (sstreamInput >> word1) {
				sstreamFile >> word2;
				if (word1.compare(word2) == 0) {
					wordsCorrect++;
				}
				else if(charCountFileLine > charCountInputLine) {
					//User missed a space or character
					if (charCountFileLine > charCountInputLine - 1)
						continue;
					if (charCountFileLine > charCountInputLine - 2)
						wordsCorrect--;
					continue;
				}
				else {
					//(charCountFileLine < charCountInputLine)
					if (charCountFileLine < charCountInputLine - 1)
						continue;
					if (charCountFileLine < charCountInputLine - 2)
						wordsCorrect--;
					continue;
				}
			}

			//prep vars for parsing next line
			sstreamInput.clear();
			sstreamFile.clear();
			seeker = inputContentLine.length();
		}
	}
	wordsTotal = getTestWordCount(path);
	testResult = Result(wordsCorrect, duration);
	return true;
}

void Test::viewResults(Result r) {
	system("CLS");
	cout << "Your WPM: " << r.getWPM() << endl;
	cout << endl;
	Sleep(4000);
	system("CLS");
}

int Test::getTestWordCount(string path) {
	string word;
	int count = 0;
	ifstream myfile;
	myfile.open(path);
	if (myfile.is_open()) {
		while (myfile >> word) {
			count++;
		}
		//cout << "Number of words in file are " << count << endl;
	}
	myfile.close();
	return count;
}

void Test::reformatFileContentForWindowsChars(string path) {
	ifstream readFrom(path);
	ofstream writeTo("../../TypingTests/example.txt");
	string currLine = "";
	string content = "";
	if (readFrom.is_open()) {
		while (getline(readFrom, currLine)) {
			content += currLine + '\n';
		}
		writeTo << content;
	}
	readFrom.close();
	writeTo.close();
}



