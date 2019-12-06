#include "FreeTest.hpp"

FreeTest::~FreeTest()
{

}

char FreeTest::displayOptions()
{
  system("CLS");
  char input;
  bool loop = true;
  do
  {
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	  cout << "Please select test type:" << endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	  cout << "1) EASY \n 2) MEDIUM \n 3) HARD \n" << endl;
	  cin >> input;
    if(input == '1' || input == '2' || input == '3')
		loop = false;
  }while(loop);

  return input;
}

string FreeTest::selectTest()
{
  char opt = displayOptions();
  string type;
  switch(opt){
    case '1':
      type = "easy";
      break;
    case '2':
      type = "medium";
      break;
    case '3':
      type = "hard";
      break;
  }

  vector<string> test_list = test_types[type];

  srand(time(NULL));
  int random = rand() % test_list.size() ;

  return test_list[random];
}
