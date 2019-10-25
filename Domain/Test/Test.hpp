#pragma once
#include "Difficulty.hpp"
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
	public:
	  Test();
	  ~Test();
	  void beginTest(string input);
	  int calculateWPM(string filename, double duration, string inputContent);
	  int getTestWordCount(string filename);
	private:
		double WPM;
		string path;
};
