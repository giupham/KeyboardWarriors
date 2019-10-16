#pragma once

#include <map>
#include <string>
#include "Result.hpp"
using namespace std;
class Progress
{
public:
  Progress();
  ~Progress();
private:
	map<string,Result> Results;
};