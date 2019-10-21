#include "Result.hpp"


Result::Result()
{
    WPM = 0; 
    id = "";
    sessionID = "";
}

Result::Result(int words, int sec, string identification, string session_id)
{
    float mins = sec / 60;
    WPM = words/mins;
    id = identification;
    sessionID = session_id;
}

Result::~Result()
{

}


vector<string> Result::viewResults()
{
    
}
