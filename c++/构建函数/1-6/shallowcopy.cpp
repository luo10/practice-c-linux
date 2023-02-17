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

private:
  char *str;
};

String::String(const char *str)
{
  cout << "String(const char *str);" << endl;
  if (str)
  {
    // 分配大小
    int len = strlen(str) + 1;
    this->str = new char[len];
    strcpy(this->str, str);
  }
  else
  {
    this->str = NULL;
  }
}

String::String(const String &obj)
{
  cout << "String(const String &obj);" << endl;
  this->str = obj.str;
}

String::~String()
{
  cout << "~String()" << str << endl;
  if (str)
  {
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

int main(int argc, const char *argv[])
{
  String str1("hello");
  String str2 = str1;

  str1.show();

  cout << "--------------------" << endl;

  str2.show();

  return 0;
}