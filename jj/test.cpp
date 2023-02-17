#include <iostream>
using namespace std;
int main()
{
  // int *pointerB{nullptr};
  // cout << pointerB << endl; // 0000000000000000
  int a = 1;
  int *pointerA{&a};

  cout << pointerA << endl;
  cout << *pointerA << endl; // 0000008A45BEFBC4
  // cout << *pointerA << endl; // 1
  // *pointerA = *pointerA + 1;
  // cout << *pointerA << endl; // 2
  // cout << a << endl;         // 2
  // auto c = getchar();
}