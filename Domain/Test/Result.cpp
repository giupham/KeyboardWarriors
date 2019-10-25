#include "Result.hpp"


Result::Result()
{
    WPM = 0; 
}

Result::Result(float _WPM)
{
	WPM = _WPM;
}

Result::Result(int words, int sec)
{
    WPM = int((words/sec)*(60/1)); 
}

Result::~Result()
{

}

int Result::getWPM()
{
	return WPM;
}

bool Result::putWPM(int testWPM) {
	WPM = testWPM;
	return true;
}


