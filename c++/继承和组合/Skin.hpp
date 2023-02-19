#ifndef _SKIN_HEAD_H_
#define _SKIN_HEAD_H_

#include <iostream>

using namespace std;

class Skin
{
public:
  Skin(const string &color) : color(color)
  {
    cout << "Skin(const string &color)" << endl;
  }

  ~Skin()
  {
    cout << "~Skin()" << endl;
  }

  string getColor(void) const
  {
    return color;
  }

private:
  string color;
};

#endif