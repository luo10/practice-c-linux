#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
  String(const char *str = NULL); // 普通构造函数
  String(const String &obj);      // 拷贝构造函数
  void show(void);                // 显示字符串
  ~String();                      // 析构函数

  String &String::operator=(const String &other);
  String operator+(const String &op2);                             // 重载+运算符
  String &String::operator<<(const char *str);                     // 重载<<运算符
  friend String operator+(const String &str1, const String &str2); // 重载+运算符

  String operator++();    // 前置++
  String operator++(int); // 后置++

private:
  char *str; // 字符串
};

String &String::operator<<(const char *str)
{
  int len = 0;
  char *old = NULL;

  if (!str)
  {
    return *this;
  }

  if (this->str)
  {
    len = strlen(this->str) + 1;
    old = this->str;
  }

  len += strlen(str);
  this->str = new char[len];

  if (old)
  {
    strcpy(this->str, old);
    delete[] old;
  }
  else
  {
    this->str[0] = '\0';
  }

  strcat(this->str, str);
  return *this;
}

// 重载=运算符
String &String::operator=(const String &other)
{
  cout << "String &operator=(const String &other)" << endl;
  // a = a => a.operator=(a)
  if (this == &other)
  {
    return *this;
  }

  // a: "123"
  // b: "123456"
  // a = b
  if (this->str)
  {
    delete[] this->str;
  }

  if (other.str)
  {
    int len = strlen(other.str) + 1;
    this->str = new char[len];
    strcpy(this->str, other.str);
  }
  else
  {
    this->str = NULL;
  }

  return *this;
}

String::String(const String &obj)
{
  cout << "String(const String &obj)" << endl;
  if (obj.str)
  {
    int len = strlen(obj.str) + 1;
    this->str = new char[len];
    strcpy(this->str, obj.str);
  }
  else
  {
    this->str = NULL;
  }
}

String::String(const char *str)
{
  cout << "String(const char *str)" << endl;
  if (str)
  {
    int len = strlen(str) + 1;
    this->str = new char[len];
    strcpy(this->str, str);
  }
  else
  {
    this->str = NULL;
  }
}

String::~String()
{
  cout << "~String(): " << str << endl;
  if (str)
  {
    int len = strlen(str) + 1;
    delete[] str;
  }
}

void String::show(void)
{
  for (char *p = str; p && *p; p++)
  {
    cout << *p << ",ascii:" << (int)*p << endl;
  }
}

String String::operator+(const String &op2)
{

  cout << "String operator+(const string &op2)" << endl;
  String newStr;
  int len = strlen(this->str) + strlen(op2.str) + 1;
  newStr.str = new char[len];
  strcpy(newStr.str, this->str);
  strcat(newStr.str, op2.str);

  return newStr;
}

String operator+(const String &str1, const String &str2)
{
  String newStr;
  int len = strlen(str1.str) + strlen(str2.str) + 1;
  newStr.str = new char[len];
  strcpy(newStr.str, str1.str);
  strcat(newStr.str, str2.str);
  return newStr;
}

int main(int argc, const char *argv[])
{
  String str1("hello");
  String str2("world");
  String str3 = str1 + str2;
  str3.show();
  return 0;
}