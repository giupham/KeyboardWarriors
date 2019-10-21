#include "Session.hpp"

Session::Session()
{
    date = getTimeStr();
}

Session::~Session()
{

}

void Session::StartSession()
{
    ifstream test(TypingTest.getContent());
}

Result Session::getTestResults()
{

}

void Session::selectTest(Difficulty::Level difficulty)
{
    TypingTest = Test(difficulty);
}

//get time and date
string getTimeStr()
{
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    string s(30, '\0');
    strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return s;
}