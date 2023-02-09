#include <iostream>
#define SIZE 10
using namespace std;

void new_memory(int *&p)
{
  p = new int[SIZE];
}

void write_data(int *&p)
{

  for (int i = 0; i < SIZE; i++)
  {
    p[i] = 0x11 * i;
  }
}

void print_data(int *&p)
{
  for (int i = 0; i < SIZE; i++)
  {
    cout << "0x" << hex << p[i] << endl;
  }
  delete[] p;
}

int main(int argc, const char *argv[])
{
  int *arr;
  new_memory(arr);
  write_data(arr);
  print_data(arr);
  return 0;
}
