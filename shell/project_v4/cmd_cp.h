#ifndef __CMD_CP_H_
#define __CMD_CP_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cmd_handle.h"
#define SZ_PATH 128
#define SZ_BUFFER 128

enum file_type
{
  FT_DIR = 0,     // 是目录
  FT_FILE = 1,    // 是普通文件
  FT_ERROR = 2,   // 出错
  FT_UNKNOWN = 3, // 文件类型未知
};

typedef struct cp_file_info
{
  enum file_type src_ftype; // 源文件类型
  char src_path[SZ_PATH];   // 源文件路径名
  char dest_path[SZ_PATH];  // 目标文件路径名
} cp_file_info_t;

extern int cmd_cp_execute(cmd_t *pcmd);
int cmd_cp_parse_path(cp_file_info_t *pfileinfo, cmd_t *pcmd);

enum file_type get_file_type(const char *path);
int cmd_cp_parse_type(cp_file_info_t *pfileinfo);

// 分发
int cmd_cp_dispatch(cp_file_info_t *pfileinfo);

// 复制文件
int cmd_cp_file(const char *src, const char *dest);
// 复制文件夹
int cmd_cp_directroy(const char *src, const char *dest);

#endif