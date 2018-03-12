/****************************************
** Program name: BlueMen.h
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#ifndef BLUEMEN_H
#define BLUEMEN_H
#include "Character.h"

class BlueMen : public Character
{
  public:
    BlueMen();
    BlueMen(int, int);
    ~BlueMen();
    int attack();
    int defense(int);
};
#endif
