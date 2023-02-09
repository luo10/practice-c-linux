#include <stdio.h>
#include <iostream>

using namespace std;

class Student
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
  void playGame(struct Student *pstu, const char *game);
};

void Student::setName(const string &_name)
{
  name = _name;
}

void Student::setAge(int _age)
{
  age = _age;
}

void Student::playGame(struct Student *pstu, const char *game)
{
  cout << pstu->name << " play" << game << endl;
  cout << "name: " << name << endl;
  cout << "score: " << score << endl;
  cout << "age: " << age << endl;
}

int main(int argc, const char *argv[])
{
  Student stu;
  // stu.name = "xiaoming";
  // stu.age = 10;
  // stu.score = 90;
  stu.setName("xiaoming");
  stu.setAge(10);
  stu.setScore(90);

  stu.playGame(&stu, "King");

  return 0;
}
