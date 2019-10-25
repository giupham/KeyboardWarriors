#pragma once
#include <string>
#include "Difficulty.hpp"
using namespace std;

class Test
{
	private:
		double WPM;
		string path;
	public:
	  Test();
	  ~Test();
	  string title;
	  void beginTest(string input);
	  int calculateWPM(string filename, double duration, string inputContent);
	  int getTestWordCount(string filename);
};
