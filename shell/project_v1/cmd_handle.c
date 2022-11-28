#include "cmd_handle.h"

#define DEBUG
int cmd_execute(char *cmd_str)
{
#ifdef DEBUG
  printf("[DEBUG]: cmd_str: < %s >\n", cmd_str);
#endif
  return 0;
}