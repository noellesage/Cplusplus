/****************************************
** Program name: Vampire.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines Vampire class
****************************************
***************************/
#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Character.h"
#include <string>
class Vampire : public Character
{
  public:
    Vampire(string, string);
    Vampire(int, int);
    ~Vampire();
    int attack();
    int defense(int);
};
#endif
