#include <stdio.h>
#include <iostream>

using namespace std;

struct student
{
  string name;
  int age;
  int score;

  void playGame(struct student *pstu, const char *game);
};

void student::playGame(struct student *pstu, const char *game)
{
  cout << pstu->name << " play" << game << endl;
  cout << "name: " << name << endl;
  cout << "score: " << score << endl;
}

int main(int argc, const char *argv[])
{
  student stu;
  stu.name = "xiaoming";
  stu.age = 10;
  stu.score = 90;

  stu.playGame(&stu, "King");

  return 0;
}
