#include "Test.hpp"
#include <iostream>
#include <fstream>

Test::Test()
{
	Difficulty::Level difficulty;
	char* content;
	char* title;
}

Test::Test(Difficulty::Level d)
{
    //set difficulty level
    difficulty = d;
    //get test name
    content = getContent();
    //get the title of the test
    //title = content;
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
            title = "TheYellowWallpaper.txt";
            break;
        case Difficulty::Level::HARD:
			title = "TheBlueLight.txt";
            break;
        case Difficulty::Level::PYTHON:
			title = "Py.txt";
            break;
        case Difficulty::Level::CSS:
			title = "CSS.txt";
            break;
		case Difficulty::Level::CPLUSPLUS:
			title = "Cpp.txt";
            break;
		case Difficulty::Level::TYPESCRIPT:
			title = "TS.txt";
            break;
        //EASY
        default:
			title = "Anthem.txt";
            break;
    }
}

