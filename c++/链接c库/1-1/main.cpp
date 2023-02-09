#include <iostream>
#include "as.h"

using namespace std;

int main(int argc, const char *argv[])
{
  int result;

  result = add(10, 20);
  cout << "add(10, 20) = " << result << endl;

  result = sub(10, 20);
  cout << "sub(10, 20) = " << result << endl;

  return 0;
}