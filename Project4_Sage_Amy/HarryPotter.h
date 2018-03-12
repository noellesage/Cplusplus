/****************************************
** Program name: HarryPotter.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines Harry Potter class
****************************************
***************************/
#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H
#include "Character.h"
#include <string>

class HarryPotter : public Character
{
  private:
    int lives;
  public:
    HarryPotter(string, string);
    HarryPotter(int, int, int);
    ~HarryPotter();
    int attack();
    int defense(int);
};
#endif
