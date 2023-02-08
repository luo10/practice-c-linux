#include <stdio.h>

namespace a_space
{
  int global = 100;

  void function(void)
  {
    printf("a function %d", global);
    return;
  }
}