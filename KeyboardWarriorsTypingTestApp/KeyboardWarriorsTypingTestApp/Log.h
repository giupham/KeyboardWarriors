#pragma once
#include "ILog.h"
#include <ctime>
#include <chrono>

using namespace std;

class Log : public ILog
{
public:
	Log(string path, string msg);
	string file_name();
};

