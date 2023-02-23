#include <iostream>

using namespace std;

class Test
{
  void function(void)
  {
    cout << "function()" << endl;
  }

  virtual void vir_function(void)
  {
    cout << "vir_function()" << endl;
  }

private:
  int a;
  static int b;
};

int main(int argc, char const *argv[])
{
  Test obj;
  cout << "sizeof(obj) : " << sizeof(obj) << endl;
  return 0;
}