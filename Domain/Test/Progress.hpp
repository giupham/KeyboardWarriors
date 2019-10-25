#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
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
	  void updateResults(string, Result);
	  void updateUserProfile(string);
	  void print_results();

};