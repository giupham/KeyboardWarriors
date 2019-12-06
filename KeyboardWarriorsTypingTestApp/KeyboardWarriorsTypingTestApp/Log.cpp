#include "Log.h"

Log::Log(string path, string msg) {
	ofstream _log;
	_log.open(path);
	_log << msg << endl;
	_log.close();
}