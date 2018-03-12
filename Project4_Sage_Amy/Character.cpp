/****************************************
** Program name: Character.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Describes Character class
****************************************
***************************/
#include <iostream>
#include "Character.h"
#include <string>
using std::string;


Character::Character()
{
  type = "Character";
  armor = 0;
  strength = 1;
}

Character::Character(string type, int armor, int strength)
{
  this->type = type;
  this->armor = armor;
  this->strength = strength;
}

int Character::get_armor()
{
  return armor;
}

int Character::get_strength()
{
  return strength;
}

string Character::get_name()
{
  return name;
}

string Character::get_type()
{
  return type;
}

void set_strength(int strength)
{
  strength = strength;
}

int Character::recover()
{
  int recover_points;
  return recover_points = get_strength() + (((rand()%5 + 1)/10)*get_strength());

  //if no recovery points
  if(recover_points < 0)
  {
    return recover_points = recover_points*(-1);
  }

  //if > 0 set new strength
  set_strength(recover_points);
}

Character::~Character(){}
