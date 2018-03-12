/****************************************
** Program name: Barbarian.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Describes Barbarian class
****************************************
***************************/
#ifndef BARBARIAN_H
#define BARBARIAN_H
#include <iostream>
#include <string>
#include "Character.h"

class Barbarian : public Character
{
  public:
    Barbarian(string, string);
    Barbarian(int, int);
    ~Barbarian();
    int attack();
    int defense(int);
};
#endif
