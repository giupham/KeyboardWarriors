#pragma once
#include "../Sessions/Session.hpp"
#include <string>
#include <vector>
using namespace std;

class Result
{
private:
	int WPM;
	std::string id;
	std::string sessionID;
public:
	Result();
	Result(int, int, std::string, std::string);
	~Result();
	vector<string> viewResults();

};
