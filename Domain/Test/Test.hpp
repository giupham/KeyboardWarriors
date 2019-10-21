#pragma once
#include <string>
#include "Difficulty.hpp"
using namespace std;

class Test
{
private:
	Difficulty::Level difficulty;
	std::string content;
	std::string id;
	std::string title;
public:
  Test();
  ~Test();
  std::string getContent();


};
