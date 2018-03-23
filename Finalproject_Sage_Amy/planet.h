/****************************************
** Program name: planet.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Planet class
*****************************************/

#ifndef PLANET_H
#define PLANET_H

#include "space.h"
#include "player.h"

class Planet : public Space
{
  public:
    Planet(Player*);
    ~Planet();
    void update_space();
    void print_prompt();
    bool player_at_left();
    void set_player_at_left();
    bool player_at_bottom();
    void set_player_at_bottom();
  private:
    Item *rock;
};

#endif
