#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Result.hpp"
using namespace std;
class Progress
{
	private:
		map<string, Result> Results;
		string username;
		string profile_path;
		float WPM;
		int number_of_sessions;
		float total_WPM;
	public:
	  Progress();
	  Progress(string);
	  bool read_profile();
	  ~Progress();
	  Result locateResult(string);
	  float getAverageWPM();
	  int get_sess_num();
	  void updateResults(string, Result, int&, int&);
	  void print_results();

};