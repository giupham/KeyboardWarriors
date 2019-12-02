#include "Test.hpp"

class FreeTest: public Test
{
  public:
    FreeTest() : Test() {};
    string selectTest();
    string displayOptions();
};
