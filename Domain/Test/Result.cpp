#include "Result.hpp"


Result::Result()
{
    WPM = 0; 
    id = "";
    sessionID = "";
}

Result::Result(int words, int sec, string identification, string session_id)
{
    WPM = float((words/sec)*(60/1)); 
    id = identification;
    sessionID = session_id;
}

Result::~Result()
{

}


vector<string> Result::viewResults()
{
    
}
