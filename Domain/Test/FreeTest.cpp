#include "FreeTest.hpp"

string FreeTest::displayOptions()
{
  system("CLS");
  char input;
  bool loop;
  do
  {
    cout << "Please select test type: \n 1) EASY \n 2) MEDIUM \n 3) HARD \n";
    cin >> input;
    if(input == '1' || input == '2' || input == '3')
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
  }

  vector<string> test_list(test_types[type].begin(), test_types[type].end());
  random = rand() % test_list.size() ;

  return test_list[random];
}
