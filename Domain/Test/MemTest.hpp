#include "Test.hpp"

class MemTest: public Test
{
  public:
    MemTest() : Test() {};
	virtual ~MemTest();
    string selectTest();
    char displayOptions();

};
