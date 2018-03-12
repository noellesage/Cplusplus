/****************************************
** Program name: Vampire.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Describes Vampire class
****************************************
***************************/
#include "Vampire.h"

Vampire::Vampire(string name, string team) : Character("Vampire", 1, 18)
{
  this->name = name;
  this->team = team;
}
Vampire::Vampire(int armor, int strength) : Character("Vampire", armor, strength)
{
  this->armor = armor;
  this->strength = strength;
}

int Vampire::attack()
{
  int num_dice = 1;
  int dice_sides = 12;
  int total = 0;
  for(int i = 0; i < num_dice; i++)
  {
    total += rand() % dice_sides + 1;
  }
  return total;
}

int Vampire::defense(int attack)
{
  int num_dice = 1;
  int dice_sides = 6;
  int total = 0;
  for(int i = 0; i < num_dice; i++)
  {
    total += rand() % dice_sides + 1;
  }
  //charm is used
  if(rand() % 1)
  {
    attack = 0;
    cout << "The vampire used his charm. No damage." << endl;
  }
  //strength lost
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
Vampire::~Vampire(){}
