#include <iostream>
#include <string>

using namespace std;

int main()
{
  int data = 100;
  char const *str = "hello world";
  int a[] = {1, 2, 3, 4, 5, 6, 7};

  cout << "data: " << data << endl;
  cout << "str: " << str << endl;
  cout << "a: {";
  int i = 0;
  int end = 7;
  for (i = 0; i < end; i++)
  {
    cout << a[i];
    if (i < end - 1)
    {
      cout << ",";
    }
  }

  cout << "}" << endl;
  return 0;
}