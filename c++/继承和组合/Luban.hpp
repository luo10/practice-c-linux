#ifndef _LUBAN_HEAD_H_
#define _LUBAN_HEAD_H_

#include <iostream>
#include "Hero.h"
#include "Shooter.hpp"
#include "Skin.hpp"

using namespace std;

class Luban : public Shooter, public Hero // 继承Shooter和Hero
{
public:
  Luban(const string &name, int distance, int legLen) : Hero(name), Shooter(distance), skin("red")
  {
    cout << "Luban(const string &name, int distance, int legLen)" << endl;
    this->legLen = legLen;
  }

  void show(void) const
  {
    cout << "Luban name : " << getName() << endl;
    cout << "Luban distance : " << getDistance() << endl;
    cout << "Luban leglen" << legLen << endl;
    cout << "Luban skin color:" << skin.getColor() << endl;
  }

  ~Luban()
  {
    cout << "~Luban()" << endl;
  }

private:
  int legLen;
  Skin skin;
};

#endif