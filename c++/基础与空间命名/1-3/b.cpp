
#include <stdio.h>

namespace b_space
{
  int global = 100;

  void function(void)
  {
    printf("b function %d", global);
    return;
  }
}