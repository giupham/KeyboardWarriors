#pragma once
#include <string>
#include "Difficulty.hpp"
using namespace std;

class Test
{
private:
	double WPM;
public:
  Test();
  ~Test();
  void beginTest(string input);
  double calculateWPM(string filename, double duration);
};
