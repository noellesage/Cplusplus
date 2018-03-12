/****************************************
** Program name: Vampire.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Character.h"

class Vampire : public Character
{
  public:
    Vampire();
    Vampire(int, int);
    ~Vampire();
    int attack();
    int defense(int);
};
#endif
