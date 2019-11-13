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
#include <synchapi.h>
using namespace std;

class Test
{
	private:
		string path;
	public:
	  Test();
	  ~Test();
	  string title;
	  Result testResult;
	  void beginTest(string input);
	  bool calculateWPM(string filename, double duration, string inputContent);
	  void viewResults(Result);
	  int getTestWordCount(string filename);
	  void reformatFileContentForWindowsChars(string filepath);

	  string getPath() {
		  return path;
	  }

	  void setPath(string p) {
		  path = p;
	  }
};
