/****************************************
** Program name: starspace.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Starspace class
*****************************************/

#ifndef STARSPACE_H
#define STARSPACE_H

#include "space.h"
#include "player.h"

class Starspace : public Space
{
  public:
    Starspace(Player*);
    ~Starspace();
    void print_prompt();
    bool player_at_top();
    void set_player_at_top();
    bool player_at_bottom();
    void set_player_at_bottom();
  private:
    Item *secrets, *star, *can;
};

#endif
