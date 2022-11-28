#include <stdio.h>

int main(void)
{
  fprintf(stdout, "Linux std io .\n");   //使用 stdout 输出
  fprintf(stderr, "can't open file.\n"); //使用 stderr 输出

  while (1)
  {
  }
  return 0;
}
