#ifndef __CMD_HANDLE_H_
#define __CMD_HANDLE_H_

#include <stdio.h>
#include <string.h>

#define SZ_NAME 8
#define SZ_ARG 32
#define SZ_COUNT 2

typedef struct command
{
  char cmd_name[SZ_NAME];              // 命令名称
  char cmd_arg_list[SZ_COUNT][SZ_ARG]; // 命令参数列表
  char cmd_arg_count;                  // 命令参数个数
} cmd_t;

void init_command_struct(cmd_t *pcmd);  // 初始化
void print_command_struct(cmd_t *pcmd); // 打印

int cmd_parse(char *cmd_str, cmd_t *pcmd); // 解析字符串

extern int cmd_execute(char *cmd_str); // 命令执行入口

#endif