/****************************************
** Program name: Medusa.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Describes Medusa class
****************************************
***************************/
#include "Medusa.h"

Medusa::Medusa(string name, string team) : Character("Medusa", 3, 8){
  this->name = name;
  this->team = team;
}
Medusa::Medusa(int armor, int strength) : Character("Medusa", armor, strength)
{
  this->armor = armor;
  this->strength = strength;
}

int Medusa::attack()
{
  int num_dice = 2,
  dice_sides = 6,
  total = 0;
  for (int i = 0; i < num_dice; ++i)
  {
    total += rand() % dice_sides + 1;
  }

  //Use glare
  if(total == 12)
  {
    return 99;
    cout << "Medusa used her glare charm. Her opponent has been turned to stone." << endl;
  }
  return total;
}
int Medusa::defense(int attack)
{
  int num_dice = 1,
  dice_sides = 6,
  total = 0;
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

Medusa::~Medusa(){}
