/****************************************
** Program name: rocketship.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Rocketship class
*****************************************/

#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

#include "space.h"
#include "player.h"

class Rocketship : public Space
{
  public:
    Rocketship(Player*);
    ~Rocketship();
    void print_prompt();
    bool player_at_bottom();
    void set_player_at_bottom();
  private:
    Item *ship, *suit, *can, *field;
};

#endif
