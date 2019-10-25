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
    WPM = float((words/sec)*(60/1)); 
}

Result::~Result()
{

}

float Result::getWPM()
{
	return WPM;
}


