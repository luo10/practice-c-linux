#include <iostream>

using namespace std;

void change(int &a)
{
  a++;
}

void printf_string(string str)
{
  cout << "str:" << str << endl;
}

int main(void)
{
  int a = 10;

  change(a);
  cout << "a = " << a << endl;
  string str = "hello";
  printf_string(str);
  printf_string("world");

  return 0;
}
