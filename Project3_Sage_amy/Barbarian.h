/****************************************
** Program name: Barbarian.h
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#ifndef BARBARIAN_H
#define BARBARIAN_H
#include <iostream>
#include "Character.h"

class Barbarian : public Character
{
  public:
    Barbarian();
    Barbarian(int, int);
    ~Barbarian();
    int attack();
    int defense(int);
};
#endif
