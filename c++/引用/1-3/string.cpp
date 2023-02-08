#include <iostream>

using namespace std;

string &function(void)
{
  string str = "hello world";
  return str;
}

int main(int argc, const char *argv[])
{
  string str = function();
  cout << str << endl;
  return 0;
}