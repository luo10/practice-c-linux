#include <iostream>

using namespace std;

void change_value(int *pdata)
{
  *pdata = 500;
}

void change_value_quote(int &quote)
{
  cout << "change_value_quote, quote addr : " << &quote << endl;
  quote = 600;
}

int main(int argc, const char *argv[])
{
  int data = 100;
  int &quote = data;

  cout << "data addr : " << &data << endl;
  cout << "quote addr : " << &quote << endl;

  data = 200;

  cout << "data : " << data << ","
       << "quote : " << quote << endl;

  quote = 300;
  cout << "data : " << data << ","
       << "quote : " << quote << endl;

  change_value(&data);

  cout << "data : " << data << ","
       << "quote : " << quote << endl;

  cout << "------------------------" << endl;
  change_value_quote(data);

  return 0;
}
