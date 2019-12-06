#pragma once
#include "ILog.h"

using namespace std;

class Log : public ILog
{
public:
	Log(string path, string msg);
};

