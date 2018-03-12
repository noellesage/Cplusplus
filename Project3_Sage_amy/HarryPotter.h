/****************************************
** Program name: HarryPotter.h
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H
#include "Character.h"

class HarryPotter : public Character
{
  private:
    int lives;
  public:
    HarryPotter();
    HarryPotter(int, int, int);
    ~HarryPotter();
    int attack();
    int defense(int);
};
#endif
