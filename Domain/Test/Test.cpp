#include "Test.hpp"

Test::Test()
{

}

Test::Test(Difficulty::Level d)
{
    //set difficulty level
    difficulty = d;
    //get test name
    content = getContent();
    //get the title of the test
    title = content.substr(0, content.find('.'));
    //id = ??
}

Test::~Test()
{

}

// WHICH TEST TO IMPLEMENT 
std::string Test::getContent()
{
    switch(difficulty)
    {
        case Difficulty::Level::MEDIUM:
            return "The Yellow Wallpaper.txt";
            break;
        case Difficulty::Level::HARD:
            return "ayn_rand.txt";
            break;
        case Difficulty::Level::PYTHON:
            return "Py.txt";
            break;
        case Difficulty::Level::CSS:
            return "CSS.txt";
            break;
		case Difficulty::Level::CPLUSPLUS:
            return "Cpp.txt";
            break;
		case Difficulty::Level::TYPESCRIPT:
            return "TS.txt";
            break;
        //EASY
        default:
            return "Alice.txt";
            break;
    }
}

