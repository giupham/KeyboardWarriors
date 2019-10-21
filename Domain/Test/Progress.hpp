#pragma once

#include <map>
#include <string>
#include "Result.hpp"
using namespace std;
class Progress
{
	private:
		map<string, Result> Results;
	public:
	  Progress();
	  ~Progress();
	  Result locateResult(string);
	  double getAverageWPM();

};