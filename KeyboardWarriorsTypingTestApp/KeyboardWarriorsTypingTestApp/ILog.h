#pragma once
#include <string>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

class ILog {
public:
	//virtual string log_path() = 0;
	virtual string file_name() = 0;
};