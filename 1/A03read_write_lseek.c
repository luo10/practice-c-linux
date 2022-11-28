#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int fd;
  ssize_t rbytes = 0; // ssize_t 对应 int/long
  ssize_t wbytes = 0;

  char buffer[64] = {0};
  char wbuffer[] = "ABCDE12345";

  // 必须有第二个参数
  if (argc != 2)
  {
    fprintf(stderr, "Usage: <%s> <pathname>\n", argv[0]);
    return -1;
  }

  fd = open(argv[1], O_RDONLY);         // 打开文件
  fd = open(argv[1], O_RDWR | O_CREAT); // 读写权限

  if (fd == -1)
  {
    perror("open(): ");
    return -1;
  }

  wbytes = write(fd, wbuffer, strlen(wbuffer));
  if (wbytes == -1)
  {
    perror("write(): ");
    return -1;
  }

  lseek(fd, 0, SEEK_SET);

  rbytes = read(fd, buffer, 10); // 从文件中读取10个字节

  if (rbytes == -1)
  {
    perror("read(): ");
    return -1;
  }

  printf("buffer, %s\n", buffer);

  close(fd);
  return 0;
}