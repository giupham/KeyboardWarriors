#pragma once
#include <string>
#include "Difficulty.hpp"
using namespace std;

class Test
{
private:
	bool testEnded;
public:
  Test();
  ~Test();
  void beginTest(string input);
};
