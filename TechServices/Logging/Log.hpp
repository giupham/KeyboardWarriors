#pragma once
#include "ILog.hpp"

using namespace std;

class Log : public ILog
{
private:
	string log_path = "../../TechServices/Logging/Logs/Log.txt";
public:
	Log();
	Log(string msg);
	string current_time();
};

