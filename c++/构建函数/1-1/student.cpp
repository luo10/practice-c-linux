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
  Student(const string &name, int age, int score);
  void setName(const string &_name);
  void setAge(int _age);
  void setScore(int _score)
  {
    score = _score;
  }
  void playGame(const char *game);
};

Student::Student(const string &name, int age, int score) : name(name), age(age), score(score) // 赋值写法
{
  cout << "Student(cont string &name, int age, int score)" << endl;
}

void Student::setName(const string &_name)
{
  name = _name;
}

void Student::setAge(int _age)
{
  age = _age;
}

void Student::playGame(const char *game)
{
  cout << name << " play" << game << endl;
  cout << "name: " << name << endl;
  cout << "score: " << score << endl;
  cout << "age: " << age << endl;
}

Student qstu; // 静态区对象

int main(int argc, const char *argv[])
{
  Student stu("xiaoming", 20, 100); // 栈区对象
  stu.playGame("King");

  // static Student stu1; // 静态区对象

  stu.setName("xiaoming");
  stu.setAge(10);
  stu.setScore(90);

  stu.playGame("King");

  cout << "-----------------" << endl;

  Student *pstu;

  pstu = new Student("tiechui", 0, 30); // 堆区对象
  // pstu->setName("tiechui");
  // pstu->setScore(0);
  // pstu->setAge(30);
  pstu->playGame("King");

  return 0;
}
