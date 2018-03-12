/****************************************
** Program name: HarryPotter.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#include "HarryPotter.h"

HarryPotter::HarryPotter() : Character("Harry Potter", 0, 10)
{
  lives = 2;
}

HarryPotter::HarryPotter(int armor, int strength, int lives)
{
  this->lives = lives;
}

int HarryPotter::attack()
{
  int num_dice = 2;
  int dice_sides = 6;
  int total = 0;
  for(int i = 0; i < num_dice; i++)
  {
    total += rand() % dice_sides + 1;
  }
  return total;
}

int HarryPotter::defense(int attack)
{
  int num_dice = 2;
  int dice_sides = 6;
  int total = 0;
  for(int i = 0; i < num_dice; i++)
  {
    total += rand() % dice_sides + 1;
  }

  int lose_strength = attack - (total + armor);
  if(lose_strength > 0)
  {
    strength -= lose_strength;
  }

  //Using Hogwarts charm
  if(strength < 1 && lives > 1)
  {
    strength = 20;
    lives--;
    cout << "Harry used the Hogwarts charm. He's come back to life and has 20 strength points" << endl;
  }
  //check strength value
  if(strength < 0)
  {
    strength = 0;
  }
  return total;
}
HarryPotter::~HarryPotter(){}
