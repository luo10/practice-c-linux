#include <iostream>

using namespace std;

void drawRect(int x, int y, int width = 10, int height = 20)
{
  cout << "x:" << x << ",y:" << y << endl;
  cout << "width:" << width << ",height" << height << endl;
  return;
}

int main(int argc, const char *argv[])
{
  drawRect(0, 0);
  cout << "---------------" << endl;
  drawRect(10, 5);
  cout << "---------------" << endl;
  drawRect(20, 10, 100, 200);

  return 0;
}