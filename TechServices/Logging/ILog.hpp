#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

class ILog {
private:
	string log_path;
public:
	virtual string current_time() = 0;
};