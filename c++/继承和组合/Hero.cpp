#include "Hero.h"

Hero::Hero(const string &name)
{
  cout << "Hero::Hero(const string &name)" << endl;
  this->name = name;
}

Hero::~Hero()
{
  cout << "Hero::~Hero()" << endl;
}

void Hero::skill(void)
{
  cout << "hero skill" << endl;
}