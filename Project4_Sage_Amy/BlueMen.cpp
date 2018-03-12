/****************************************
** Program name: BlueMen.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines BlueMen class
****************************************
***************************/
#include "BlueMen.h"
#include "Character.h"
BlueMen::BlueMen(string name, string team) : Character("Blue Men", 3, 12) {
  this->name = name;
  this->team = team;
}

BlueMen::BlueMen(int armor, int strength) : Character("Blue Men", armor, strength)
{
  this->armor = armor;
  this->strength = strength;
}

int BlueMen::attack()
{
  int num_dice = 2;
  int dice_sides = 10;
  int total = 0;

  for (int i = 0; i < num_dice; ++i)
  {
    total += rand() % dice_sides + 1;
  }
  return total;
}

int BlueMen::defense(int attack)
{
  int num_dice;
  int dice_sides = 6;
  int total = 0;

  //mob ability

  if (strength > 8)
  {
    num_dice = 3;
  }

  else if (strength < 5)
  {
    num_dice = 1;
  }

  else
  {
    num_dice = 2;
  }

  for (int i = 0; i < num_dice; ++i)
  {
    total += rand() % dice_sides + 1;
  }

  int lose_strength = attack - (total + armor);
  if (lose_strength > 0)
  {
    strength -= lose_strength;
  }

  if (strength < 0)
  {
    strength = 0;
  }
  return total;
}

BlueMen::~BlueMen(){}
