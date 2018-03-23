/****************************************
** Program name: alienspace.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Alienspace class
*****************************************/

#ifndef ALIENSPACE_H
#define ALIENSPACE_H

#include "space.h"
#include "player.h"
#include "item.h" 

class Alienspace : public Space
{
  public:
    Alienspace(Player*);
    ~Alienspace();
    void print_prompt();
    bool player_at_top();
    void set_player_at_top();
  private:
    Item *thanks;
};

#endif
