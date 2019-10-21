#include "Progress.hpp"

Progress::Progress()
{

}

Progress::Progress(string _id):id(_id){}

Progress::~Progress()
{

}

Result Progress::locateResult(string res)
{
    ifstream test(res);
    if (!test.is_open())
    {
        cerr << "Unable to locate " << res << endl;
    }
    else
    {
        
    }
}

double Progress::getAverageWPM()
{

}