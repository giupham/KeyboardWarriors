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
	Result(float WPM);
	Result(int words, int secs);
	~Result();
	int getWPM();
	bool putWPM(int testWPM);
};
