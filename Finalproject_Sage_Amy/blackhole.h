/****************************************
** Program name: blackhole.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Blackhole class
*****************************************/

#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "space.h"
#include "player.h"

class Blackhole : public Space
{
  public:
    Blackhole(Player*);
    ~Blackhole();
    void print_prompt();
    bool player_at_top();
    void set_player_at_top();
    bool player_at_bottom();
    void set_player_at_bottom();
  private:
    Item *key, *can, *hole;
};

#endif
