/****************************************
** Program name: character.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#include <iostream>
#include "Character.h"
#include <string>
using std::string;


Character::Character()
{
  name = "Character";
  armor = 0;
  strength = 1;
}

Character::Character(string name, int armor, int strength)
{
  this->name = name;
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

Character::~Character(){}
