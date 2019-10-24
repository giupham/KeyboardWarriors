#pragma once
#include <string>
#include <vector>
using namespace std;

class Result
{
private:
	float WPM;
	string id;
	string sessionID;
public:
	Result();
	Result(int, int, string, string);
	~Result();
	vector<string> viewResults();

};
