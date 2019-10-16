#pragma once
#include <string>
using namespace std;
class Test
{
public:
  Test();
  ~Test();
  Test getTest(string);
private:
  std::string difficulty;
  std::string content;
  std::string id;
  std::string title;
};
