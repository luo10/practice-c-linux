#include <iostream>

using namespace std;

void my_swap(int a, int b)
{
  int tmp;

  cout << "before_swap: " << a << "," << b << endl;

  tmp = a;
  a = b;
  b = tmp;

  cout << "after swap: " << a << "," << b << endl;
}

void my_swap_pointer(int *pa, int *pb)
{
  int tmp;

  tmp = *pa;
  *pa = *pb;
  *pb = tmp;

  return;
}

int main(int argc, const char *argv[])
{
  int data1 = 100;
  int data2 = 200;

  my_swap(data1, data2);

  cout << "data1 : " << data1 << endl;
  cout << "data2 ： " << data2 << endl;

  cout << "---------------------" << endl;

  my_swap_pointer(&data1, &data2);

  cout << "data1 : " << data1 << endl;
  cout << "data2 : " << data2 << endl;

  return 0;
}