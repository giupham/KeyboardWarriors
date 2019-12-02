#include "Test.hpp"

class FreeTest: public Test
{
  public:
    FreeTest() : Test() {};
	virtual ~FreeTest();
    string selectTest();
    char displayOptions();
};
