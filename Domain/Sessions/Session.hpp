#pragma once
#include "../Test/Test.hpp"
#include "../Test/Result.hpp"
#include "../Test/Difficulty.hpp"
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
class Session
{
private:
	std::string date;
	std::string SesssionID;
	Test TypingTest;
	double TimeTaken;

public:
  Session();
  ~Session();
  void StartSession();
  Result getTestResults();
  void selectTest(Difficulty::Level difficulty);

};
