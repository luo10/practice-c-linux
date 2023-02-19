#ifndef _HEARO_HEAD_H_
#define _HEARO_HEAD_H_

#include <iostream>

using namespace std;

class Hero
{
public:
  Hero(const string &name = "hero");
  ~Hero();
  void skill(void);

  string getName(void) const
  {
    return name;
  }

private:
  string name;
};

#endif