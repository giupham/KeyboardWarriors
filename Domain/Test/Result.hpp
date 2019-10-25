#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Result
{
private:
	float WPM;
public:
	Result();
	Result(float WPM);
	Result(int words, int secs);
	~Result();
	float getWPM();

};
