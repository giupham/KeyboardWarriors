#include "Test.hpp"

class MemTest: public Test
{
  public:
    MemTest() : Test() {};
    string selectTest();
    string displayOptions();
};
