#include <stdio.h>
#include <string.h>

struct student
{
  char name[20];
  int age;
  int score;
};

void playGame(struct student *pstu, const char *game)
{
  printf("%s play %s\n", pstu->name, game);
}

int main(int argc, const char *argv[])
{
  struct student stu;
  strcpy(stu.name, "xiaoming"); // 内存地址的设置内容
  stu.age = 10;
  stu.score = 90;

  playGame(&stu, "King");

  return 0;
}
