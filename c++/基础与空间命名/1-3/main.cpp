#include <stdio.h>

namespace a_space
{
  extern int global;
  extern void function(void);
}

int main(int argc, const char *argv[])
{
  printf("a global: %d\n", a_space::global);
  a_space::function();

  return 0;
}