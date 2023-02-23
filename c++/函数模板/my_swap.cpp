#include <iostream>

using namespace std;

template <typename T>
void my_swap(T &a, T &b)
{
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, const char *argv[])
{
  int a = 10;
  int b = 20;

  my_swap(a, b);

  cout << "a : " << a << ",b : " << b << endl;

  string str1 = "AA";
  string str2 = "BB";

  my_swap<string>(str1, str2);

  cout << "str1:" << str1 << endl;
  cout << "str2:" << str2 << endl;

  return 0;
}