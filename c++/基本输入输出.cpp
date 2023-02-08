#include <iostream>
#include <string>
using namespace std;
int main()
{
  // 申明变量
  int oneInt1, oneInt2;
  char strArray[20];
  string str;
  double oneDouble;
  char oneChar = 'a';

  // 显示
  cout << "输入两个整型值，一个字符，一个字符串和一个浮点值";
  cout << "以空格、Tab键或<Enter>键分隔；" << endl;
  // 接收
  cin >> oneInt1 >> oneInt2 >> oneChar >> strArray >> oneDouble;
  str = strArray;
  cout << "输入的数据是: " << endl;       // endl作用是换行
  cout << "字符串是: \t\t" << str << endl // \t是制表符Tab
       << "两个整型值分别是: \t" << oneInt1 << " 和\t" << oneInt2 << endl
       << "字符是: \t\t" << oneChar << "\n"
       << "浮点值是: \t\t" << oneDouble << endl;
  return 0;
}