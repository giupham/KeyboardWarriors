#include "MemTest.hpp.hpp"

string FreeTest::displayOptions()
{
  system("CLS");
  char input;
  bool loop;
  do
  {
    cout << "Please select test type: \n 1) EASY \n 2) MEDIUM \n 3) HARD \n 4) PYTHON \n 5) CSS \n 6) CPP \n";
    cin >> input;
    if(input == '1' || input == '2' || input == '3' || input == '4' || input == '5' || input == '6')
      loop = false;
  }while(loop);

  return input;
}

void FreeTest::selectTest()
{
  string opt = displayOptions();
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

  vector<string> test_list(test_types[type]);
  random = rand() % test_list.size() ;

  return test_list[random];
}
