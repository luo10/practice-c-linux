#include <stdio.h>
#include <iostream>

using namespace std;

struct Student
{
  string name;
  int age;
  int score;

  void playGame(struct Student *pstu, const char *game);
};

void Student::playGame(struct Student *pstu, const char *game)
{
  cout << pstu->name << " play" << game << endl;
  cout << "name: " << name << endl;
  cout << "score: " << score << endl;
}

int main(int argc, const char *argv[])
{
  Student stu;
  stu.name = "xiaoming";
  stu.age = 10;
  stu.score = 90;

  stu.playGame(&stu, "King");

  return 0;
}
