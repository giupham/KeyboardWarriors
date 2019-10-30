#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Result
{
private:
	int WPM;
public:
	Result();
	Result(int WPM);
	Result(float words, float secs);
	~Result();
	int getWPM();
	bool putWPM(int testWPM);
};
