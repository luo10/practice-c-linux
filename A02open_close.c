#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close

// ./a.out <pathname>
int main(int argc, char *argv[])
{

  int fd;
  // 判断是否有两个参数
  if (argc != 2)
  {
    fprintf(stderr, "Usage : <%s> <pathname>\n", argv[0]);
    return -1;
  }

  // fd = open(argv[1], O_RDONLY);
  fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644); // 只写 | 创建 | 截短

  // 如果 = -1 则报错了
  if (fd == -1)
  {
    perror("open(): ");
    return -1;
  }

  printf(" fd = %d\n", fd);

  close(fd);
  return 0;
}