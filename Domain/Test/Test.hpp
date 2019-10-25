#pragma once
#include <string>
#include "Result.hpp"
using namespace std;

class Test
{
	private:
		double WPM;
		string path;
		Result testResult;
	public:
	  Test();
	  ~Test();
	  string title;
	  void beginTest(string input);
	  Result calculateWPM(string filename, double duration, string inputContent);
	  int getTestWordCount(string filename);
};
