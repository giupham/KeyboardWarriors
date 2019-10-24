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
		string id;
	public:
	  Progress();
	  Progress(string);
	  ~Progress();
	  Result locateResult(std::string);
	  double getAverageWPM();

};