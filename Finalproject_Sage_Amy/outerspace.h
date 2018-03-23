/****************************************
** Program name: outerspace.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Outerspace class
*****************************************/

#ifndef OUTERSPACE_H
#define OUTERSPACE_H

#include "space.h"
#include "player.h"

class Outerspace : public Space
{
  public:
    Outerspace(Player*);
    ~Outerspace();
    void update_space();
    void print_prompt();
    bool player_at_top();
    void set_player_at_top();
    bool player_at_right();
    void set_player_at_right();
  private:
    Item *box, *field, *fakebox, *can;
};

#endif
