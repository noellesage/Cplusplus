/****************************************
** Program name: Barbarian.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines Barbarian class
****************************************
***************************/
#include "Character.h"
#include "Barbarian.h"
Barbarian::Barbarian(string name, string team) : Character("Barbarian", 0, 12)
{
  this->name = name;
  this->team = team;
}

Barbarian::Barbarian(int armor, int strength) : Character("Barbarian", armor, strength)
{
  this->armor = armor;
  this->strength = strength;
}

int Barbarian::attack()
{
  int num_dice = 2;
  int dice_sides = 6;
  int total = 0;
  for (int i = 0; i < num_dice; ++i)
  {
    total += rand() % dice_sides + 1;
  }
  return total;
}

int Barbarian::defense(int attack)
{
  int num_dice = 2;
  int dice_sides = 6;
  int total = 0;
  for (int i = 0; i < num_dice; ++i)
  {
    total += rand() % dice_sides + 1;
  }
  int lose_strength = attack - (total + armor);
  //deduct attack from strength
  if (lose_strength > 0)
  {
    //update strength
    strength -= lose_strength;
  }
  //if char has no strength
  if (strength < 0)
  {
    strength = 0;
  }
  return total;
}

Barbarian::~Barbarian() {}//destructor
