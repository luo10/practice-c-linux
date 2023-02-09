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

Student qstu; // 静态区对象

int main(int argc, const char *argv[])
{
  Student stu;         // 栈区对象
  static Student stu1; // 静态区对象

  stu.setName("xiaoming");
  stu.setAge(10);
  stu.setScore(90);

  stu.playGame(&stu, "King");

  cout << "-----------------" << endl;

  Student *pstu;

  pstu = new Student; // 堆区对象
  pstu->setName("tiechui");
  pstu->setScore(0);
  pstu->setAge(30);
  pstu->playGame(pstu, "King");

  return 0;
}
