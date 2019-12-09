#include "Test.hpp"
#include <sstream>

using namespace std;

#define CLOCKS_PER_SEC ((std::clock_t)1000);

Test::Test()
{
	path = "";
	title = "";
	fillTestTypes();
}

Test::~Test()
{
}

string Test::selectTest()
{
	//can remove later
	return "false";
}

void Test::fillTestTypes()
{
	vector<string> easy, medium, hard, css, cpp, python;
	easy.push_back("Alice1.txt");
	easy.push_back("Alice4.txt");
	easy.push_back("Anthem1.txt");
	easy.push_back("GrimmsBlueLight1.txt");
	easy.push_back("GrimmsBlueLight4.txt");

	medium.push_back("Alice2.txt");
	medium.push_back("Alice5.txt");
	medium.push_back("Anthem2.txt");
	medium.push_back("GrimmsBlueLight2.txt");
	medium.push_back("GrimmsBlueLight5.txt");
	medium.push_back("YellowWallpaper2.txt");

	hard.push_back("Alice3.txt");
	hard.push_back("Alice6.txt");
	hard.push_back("Anthem3.txt");
	hard.push_back("GrimmsBlueLight3.txt");
	hard.push_back("GrimmsBlueLight6.txt");
	hard.push_back("YellowWallpaper3.txt");

	test_types["easy"] = easy;
	test_types["medium"] = medium;
	test_types["hard"] = hard;
	test_types["CSS"] = css;
	test_types["PYTHON"] = python;
	test_types["CPP"] = cpp;
}

void Test::displayTestStart() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	system("CLS");
	cout << "This is a line by line typing test." << endl;
	cout << "Please press 'Enter' at the end of each line to move to the next line.\n" << endl;
	cout << "Please press 'Enter' to start the clock." << endl;
	cin.ignore();
	if (cin.get() == '\n') {
		system("CLS");
	}
}

void Test::beginTest()
{
	string selectedTest = selectTest();

	cout << "\nSelected Test = " << selectedTest << endl;

	displayTestStart();

	clock_t start;
	double duration = 0;

	string inputContent;
	string line;
	string lineNext;
	path = "../../TechServices/Persistence/TypingTests/" + selectedTest;

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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Your WPM: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
	cout << r.getWPM() << endl;
	cout << endl;
	Sleep(1250);
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

