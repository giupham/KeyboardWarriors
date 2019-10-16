#pragma once
#include "../Test/Test.hpp"
#include <string>
using namespace std;
class Session
{
public:
  Session();
  ~Session();
  void StartSessions();

private:
  std::string date;
  std::string SesssionID;
  Test TypingTest;
  int TimeTaken
};
