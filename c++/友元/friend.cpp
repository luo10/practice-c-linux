#include <iostream>

using namespace std;

class B
{
public:
  void change_value(A &obj)
  {
    // obj.a = 100;
    obj.setA(100);
  }
};

class A
{
public:
  friend void change_value(A &obj);
  void show(void) const
  {
    cout << "a : " << a << endl;
  }
  int get()
  {
    return a;
  }

  int setA(int val)
  {
    a = val;
  }

private:
  friend void B::change_value(A &obj);
  int a;
};

void change_value(A &obj)
{
  obj.a = 100;
}

int main(int argc, int const *argv[])
{
  A a_obj;

  change_value(a_obj);

  a_obj.show();

  return 0;
}