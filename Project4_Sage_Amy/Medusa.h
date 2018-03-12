/****************************************
** Program name: Medusa.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines Medusa class
****************************************
***************************/
#ifndef MEDUSA_H
#define MEDUSA_H
#include "Character.h"
#include <string>

class Medusa : public Character
{
  public:
    Medusa(string, string);
    Medusa(int, int);
    ~Medusa();
    int attack();
    int defense(int);
};
#endif
