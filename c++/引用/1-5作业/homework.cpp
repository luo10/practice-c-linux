#include <iostream>

using namespace std;

void my_swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

void my_swap_include(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
  return;
}

int main(int argc, const char *argv[])
{
  int d1 = 10;
  int d2 = 20;

  my_swap(&d1, &d2);

  cout << "d1: " << d1 << endl;
  cout << "d2: " << d2 << endl;

  my_swap_include(d1, d2);

  cout << "d1: " << d1 << endl;
  cout << "d2: " << d2 << endl;
  return 0;
}
