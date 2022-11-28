#include <stdio.h>
#include <string.h>

#include "cmd_handle.h"
#define SZ_CMD 64 // 缓存大小

int main(void)
{
  char command[SZ_CMD] = {0}; // 申请空间

  for (;;)
  {
    printf("TinyShell >");
    // 获取键盘输入, stdin标准输入
    // "ls -l"  ===> "ls -l\n"
    fgets(command, SZ_CMD, stdin);

    command[strlen(command) - 1] = '\0'; // 去掉\n

    // "quit": 退出标识 strncmp: 比较两个字符串
    if (strncmp(command, "quit", 4) == 0)
    {
      printf("GoodBye\n");
      break; // 退出
    }

    cmd_execute(command); // 调用 cmd_handle 模块中的函数， 用于执行命令
  }
  return 0;
}