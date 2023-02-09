#include <iostream>

using namespace std;

int my_swap(int a, int b)
{
  return a + b;
}

float my_swap(float a, float b)
{
  return a + b;
}

string my_swap(string a, string b)
{
  return a + b;
}

int main(int argc, const char *argv[])
{
  int re_int = my_swap(1, 1);
  cout << "int类型:" << re_int << endl;

  float re_float = my_swap((float)1.1, (float)1.1);
  cout << "float类型:" << re_float << endl;

  string re_string = my_swap("a", "a");
  cout << "string类型:" << re_string << endl;
  return 0;
}