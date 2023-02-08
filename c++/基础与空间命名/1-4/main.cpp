#include "space.h"

int main()
{
  int a = 1;
  int b = 1;

  int a_calc;
  int b_calc;
  a_calc = A_Space::calc(a, b);
  b_calc = B_Space::calc(a, b);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "A_Space--calc: " << a_calc << endl;
  cout << "B_Space--calc: " << b_calc << endl;

  return 0;
}