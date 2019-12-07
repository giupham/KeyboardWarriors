#include "Log.hpp"
using namespace std;

Log::Log() {

}

Log::Log(string msg) {
	ofstream _log;
	_log.open(log_path, ofstream::app);
	if (_log.is_open()) {
		_log << current_time() << "\t" << msg << endl;
		_log.close();
	}
	else {
		string error = "Log failed.";
	}
}

string Log::current_time() {

	time_t rawtime;
	tm now;
	time(&rawtime);
	localtime_s(&now, &rawtime);


	/*time_t clock = time(0);
	tm* now = localtime(&clock);
	*/
	string current_time = to_string(now.tm_mon + 1) + "-"
		+ to_string(now.tm_mday) + "-"
		+ to_string(now.tm_year + 1900) + "__"
		+ to_string(now.tm_hour) + "-"
		+ to_string(now.tm_min) + "-"
		+ to_string(now.tm_sec);

	return current_time;
}