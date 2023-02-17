#include <iostream>

using namespace std;

class Test
{
public:
  Test(int a, int b) : b(b)
  {
    this->a = a;
  }

  void show(void)
  {
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
  }

  void function(void) const;
  void function(void);

private:
  int a;
  const int b;
};

void Test::function(void) const
{
  int c = 0;
  c++;
}

void Test::function(void)
{
  cout << "void function(void)" << endl;
}

int main(int argc, const char *argv[])
{
  Test obj(2, 3);

  obj.show();
  obj.function();

  const Test other(3, 5);
  other.function();

  return 0;
}