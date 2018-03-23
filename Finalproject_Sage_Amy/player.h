/****************************************
** Program name: player.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Player class
*****************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include <string>

using std::string;

class Player : public Item
{
  private:
    int fuel;
    int inventory_size;
    string inventory[20];
  public:
    Player();
    void add_item(string);
    bool check_for_item(string);
    void print_inventory();
    void increment_fuel();
    void decrement_fuel();
    int get_fuel();
    void print_fuel();
};

#endif
