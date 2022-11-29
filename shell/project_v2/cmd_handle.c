#include "cmd_handle.h"

#define DEBUG
int cmd_execute(char *cmd_str)
{
  cmd_t command;
  int ret;

  if (cmd_str == NULL)
  {
    return -1;
  }

#ifdef DEBUG
  printf("[DEBUG]: cmd_str: < %s >\n", cmd_str);
#endif

  init_command_struct(&command); // 初始化结构体

#ifdef DEBUG
  print_command_info(&command); // 打印
#endif

  ret = cmd_parse(cmd_str, &command); // 解析命令字符串

  if (ret == -1)
  {
    return -1;
  }

#ifdef DEBUG
  print_command_info(&command);
#endif
  ret = cmd_dispatch(&command);
  if (ret == -1)
    return -1;
  return 0;
}

void init_command_struct(cmd_t *pcmd) // 初始化
{
  int i;
  // memset 对 pcmd上的cmd_name 填充8个b的0
  memset(pcmd->cmd_name, 0, SZ_NAME);

  for (i = 0; i < SZ_COUNT; i++)
  {
    memset(pcmd->cmd_arg_list[i], 0, SZ_ARG);
  }

  pcmd->cmd_arg_count = 0;
}
void print_command_info(cmd_t *pcmd) // 打印
{
  int i;

  printf("-------------------------\n");
  printf("[DEBUG] cmd name : < %s >\n", pcmd->cmd_name);
  printf("[DEBUG] cmd arg count : < %d >\n", pcmd->cmd_arg_count);
  printf("[DEBUG] cmd arg list :");

  for (i = 0; i < pcmd->cmd_arg_count; i++)
  {
    printf(" %s ", pcmd->cmd_arg_list[i]);
  }

  printf("\n-------------------------\n");
}

// "cp 1.txt 2.txt"
int cmd_parse(char *cmd_str, cmd_t *pcmd)
{
  if (cmd_str == NULL || pcmd == NULL)
    return -1;

  char *p_cmd_name = NULL;
  char *p_cmd_arg = NULL;
  int index = 0;

  // 拿到解析的输入
  p_cmd_name = strtok(cmd_str, " ");

#ifdef DEBUG
  printf("[DEBUG] cmd name : < %s \n >", p_cmd_name);
#endif
  // 拷贝到结构体中
  strcpy(pcmd->cmd_name, p_cmd_name);

  for (;;)
  {
    p_cmd_arg = strtok(NULL, " "); // 获取分割之后的字符串的地址
    if (p_cmd_arg == NULL)
      break;

    strcpy(pcmd->cmd_arg_list[index++], p_cmd_arg); // 将字符串拷贝到结构体中
  }

  pcmd->cmd_arg_count = index; // 存储命令参数的个数

#ifdef DEBUG
  print_command_info(pcmd);
#endif

  return 0;
}

// 命令分发
int cmd_dispatch(cmd_t *pcmd)
{
  if (pcmd == NULL)
    return -1;

  if (strcmp(pcmd->cmd_name, "ls") == 0)
  {
    // 调用 ls 命令处理模块
#ifdef DEBUG
    printf("ls command hanlde. \n");
#endif
  }
  else if (strcmp(pcmd->cmd_name, "cp") == 0)
  {
    // 调用cp命令处理模块
#ifdef DEBUG
    printf("cp command hanlde. \n");
#endif
  }
  return 0;
}