#include "cmd_cp.h"

#define DEBUG
extern int cmd_cp_execute(cmd_t *pcmd)
{
  if (pcmd == NULL)
    return -1;

#ifdef DEBUG
  print_command_info(pcmd);
#endif

  int ret;
  cp_file_info_t fileinfo;

  // 解析路径并存储到 cp_file_info_t 结构体中
  ret = cmd_cp_parse_path(&fileinfo, pcmd);
  if (ret == -1)
    return -1;

  // 设置文件类型
  ret = cmd_cp_parse_type(&fileinfo);
  if (ret == -1)
    return -1;

  return 0;
}

// 复制路径
// cp 1.txt 2.txt cmd_arg_list[0]: "1.txt"    cmd_arg_list[1]: "2.txt"
int cmd_cp_parse_path(cp_file_info_t *pfileinfo, cmd_t *pcmd)
{
  if (pfileinfo == NULL || pcmd == NULL)
    return -1;
  // 拷贝到内存地址中
  stpcpy(pfileinfo->src_path, pcmd->cmd_arg_list[0]);
  stpcpy(pfileinfo->dest_path, pcmd->cmd_arg_list[1]);

#ifdef DEBUG
  printf("[DEBUG] src path < %s >\n", pfileinfo->src_path);
  printf("[DEBUG] dest path < %s >\n", pfileinfo->dest_path);
#endif
  return 0;
}

// 获取文件类型
enum file_type get_file_type(const char *path)
{
  int ret;               // 返回值
  struct stat stat_info; // 文件信息

  if (path == NULL)
    return FT_ERROR; // 返回错误

  ret = stat(path, &stat_info); // 读取文件信息, 保存到stat_info中
  if (ret == -1)
  {
    perror("stat(): ");
    return FT_ERROR;
  }
  if (S_ISDIR(stat_info.st_mode)) // 判断为目录
    return FT_DIR;
  else if (S_ISREG(stat_info.st_mode)) // 普通文件
    return FT_FILE;

  return FT_UNKNOWN;
}

// 保存信息到变量中
int cmd_cp_parse_type(cp_file_info_t *pfileinfo)
{
  int ret;
  enum file_type ftype;
  if (pfileinfo == NULL)
    return -1;

  // 获取源文件
  ftype = get_file_type(pfileinfo->src_path);
  if (ftype == FT_ERROR || ftype == FT_UNKNOWN)
    return -1;
  else
    pfileinfo->src_ftype = ftype; // 存储文件类型

#ifdef DEBUG
  if (pfileinfo->src_ftype == FT_FILE)
    printf("FILE.\n");
  else if (pfileinfo->src_ftype == FT_DIR)
    printf("Dir.\n");
#endif
  return 0;
}

// 分发
int cmd_cp_dispatch(cp_file_info_t *pfileinfo)
{
  if (pfileinfo->src_ftype == FT_FILE)
  {
    return cmd_cp_file(pfileinfo->src_path, pfileinfo->dest_path);
  }
  else if (pfileinfo->src_path == FT_DIR)
  {
    return cmd_cp_directory(pfileinfo->src_path, pfileinfo->dest_path);
  }
}

int cmd_cp_file(const char *src, const char *dest)
{
  FILE *fp_src = NULL, *fp_dest = NULL;
  size_t rbytes = 0, wbytes = 0;
  char buffer[SZ_BUFFER] = {0};

#ifdef DEBUG
  printf("[DEBUG] %s ----> %s\n", src, dest);
#endif

  if (src == NULL || dest == NULL)
    return -1;

  fp_src = fopen(src, "r");
  fp_dest = fopen(dest, "w+");

  if (fp_src == NULL || fp_dest == NULL)
    return -1;

  for (;;)
  {
    rbytes = fread(buffer, sizeof(char), SZ_BUFFER, fp_src); // 读取
    if (rbytes != 0)
    {
      wbytes = fwrite(buffer, sizeof(char), rbytes, fp_dest); // 写入
      if (wbytes != rbytes)
      {
        perror("fwrite():");
        return -1;
      }
    }
    else
      break;
  }
  fclose(fp_src);
  fclose(fp_dest);

  return 0;
}