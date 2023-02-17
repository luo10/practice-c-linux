#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
  String(const char *str = NULL);
  String(const String &obj);
  void show(void); // 输出字符串中的每个字符和对应的ASCII码
  ~String();

  static void showUseMemroy(void);

private:
  char *str;

private:
  static int memoryUseCount; // 所有对象共享这个成员变量
};

int String::memoryUseCount = 0;

void String::showUseMemroy(void)
{
  cout << "memory use: " << memoryUseCount << endl;
}

String::String(const char *str)
{
  cout << "String(const char *str);" << endl;
  if (str)
  {
    // 分配大小
    int len = strlen(str) + 1;
    this->str = new char[len];
    strcpy(this->str, str);
    memoryUseCount += len;
  }
  else
  {
    this->str = NULL;
  }
}

String::String(const String &obj)
{
  cout << "String(const String &obj);" << endl;
  if (obj.str)
  {
    int len = strlen(obj.str) + 1;
    this->str = new char[len];
    strcpy(this->str, obj.str);
    memoryUseCount += len;
  }
  else
  {
    this->str = NULL;
  }
}

String::~String()
{
  cout << "~String()" << str << endl;
  if (str)
  {
    int len = strlen(str) + 1;
    memoryUseCount -= len;
    delete[] str;
  }
  str = NULL;
}

void String::show(void)
{
  // '\0' -> ascii 0
  for (char *p = str; *p; p++)
  {
    cout << *p << ",ascii : " << (int)*p << endl;
  }
  return;
}

// void function(String obj)
// {
//   obj.show();
// }

String function(void)
{
  String str("world");
  return str;
}

int main(int argc, const char *argv[])
{
  String str1("hello");
  String::showUseMemroy();

  String str2 = str1;

  str1.showUseMemroy();
  str1.show();

  cout << "--------------------" << endl;

  str2.show();

  cout << "--------------------" << endl;
  str2.showUseMemroy();

  return 0;
}