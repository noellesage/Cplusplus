/****************************************
** Program name: Medusa.h
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#ifndef MEDUSA_H
#define MEDUSA_H
#include "Character.h"

class Medusa : public Character
{
  public:
    Medusa();
    Medusa(int, int);
    ~Medusa();
    int attack();
    int defense(int);
};
#endif
