#pragma once

class Result
{
public:
  Result();
  ~Result();
  getResult(string);
private:
  int WPM;
  std::string id;
  Session parentSession;

};
