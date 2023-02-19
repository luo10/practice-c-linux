#ifndef _SHOOTER_HEAD_H_
#define _SHOOTER_HEAD_H_

#include <iostream>

using namespace std;

class Shooter
{

public:
  Shooter(int distance) : distance(distance)
  {
    cout << "Shooter(int distance)" << endl;
  }

  ~Shooter()
  {
    cout << "~Shooter()" << endl;
  }

  int getDistance(void) const
  {
    return distance;
  }

private:
  int distance;
};

#endif