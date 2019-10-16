#pragma once
#include "../Sessions/Session.hpp"
#include <string>
using namespace std;

class Result
{
public:
	Result();
	~Result();
	Result getResult(string);
private:
	int WPM;
	std::string id;
	Session parentSession;

};
