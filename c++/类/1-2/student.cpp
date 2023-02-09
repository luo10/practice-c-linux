#include <stdio.h>
#include <iostream>

using namespace std;

class student
{
private:
  string name;
  int age;
  int score;

public:
  void setName(const string &_name);
  void setAge(int _age);
  void setScore(int _score)
  {
    score = _score;
  }
  void playGame(struct student *pstu, const char *game);
};

void student::setName(const string &_name)
{
  name = _name;
}

void student::setAge(int _age)
{
  age = _age;
}

void student::playGame(struct student *pstu, const char *game)
{
  cout << pstu->name << " play" << game << endl;
  cout << "name: " << name << endl;
  cout << "score: " << score << endl;
  cout << "age: " << age << endl;
}

int main(int argc, const char *argv[])
{
  student stu;
  // stu.name = "xiaoming";
  // stu.age = 10;
  // stu.score = 90;
  stu.setName("xiaoming");
  stu.setAge(10);
  stu.setScore(90);

  stu.playGame(&stu, "King");

  return 0;
}
