#pragma once
#include "Result.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>
#include <ctime>
#include <list>
#include <Windows.h>
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
