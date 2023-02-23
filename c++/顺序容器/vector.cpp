#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<string> v1;

  v1.push_back("hello");
  v1.push_back("world");
  v1.push_back("vector");

  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << endl;
  }

  cout << "front:" << v1.front() << endl;
  cout << "back:" << v1.back() << endl;

  v1.pop_back(); // 删除最后一个元素

  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << endl;
  }

  return 0;
}