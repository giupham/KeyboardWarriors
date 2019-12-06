#include "MemTest.hpp"

MemTest::~MemTest()
{

}

char MemTest::displayOptions()
{
  system("CLS");
  char input;
  bool loop = true;
  do
  {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Please select test type:" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "1) EASY \n2) MEDIUM \n3) HARD \n4) PYTHON \n5) CSS \n6) CPP \n";
    cin >> input;
    if(input == '1' || input == '2' || input == '3' || input == '4' || input == '5' || input == '6')
		loop = false;
	system("CLS");
  }while(loop);

  return input;
}

string MemTest::selectTest()
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
    case '4':
      type = "PYTHON";
      break;
    case '5':
      type = "CSS";
      break;
    case '6':
      type = "CPP";
      break;
  }
  
  vector<string> test_list = test_types[type];

  srand(time(NULL));  
  int random = rand() % test_list.size();

  

  return test_list[random];
}
