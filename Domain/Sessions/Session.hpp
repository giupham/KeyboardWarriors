#pragma once
#include <string>

class Session
{
public:
  Session();
  ~Session();
  StartSessions();

private:
  std::string date;
  std::string SesssionID;
  Test TypingTest;
  int TimeTaken
};
