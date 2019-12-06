#pragma once
#include "Result.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <list>
#include <Windows.h>
#include <synchapi.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
using namespace std;

class Test
{
	private:
		string path;
	protected:
		map<string, vector<string>> test_types;
	public:
	  Test();
	  virtual ~Test();
	  string title;
	  Result testResult;

	  virtual string selectTest();
	  void displayTestStart();
	  void fillTestTypes();
	  void beginTest();
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
