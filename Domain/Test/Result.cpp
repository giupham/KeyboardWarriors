#include "Result.hpp"


Result::Result()
{
    WPM = 0; 
}

Result::Result(int _WPM)
{
	WPM = _WPM;
}

Result::Result(float words, float sec)
{
	float test = (words / sec);
    WPM = int(test*60); 
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


