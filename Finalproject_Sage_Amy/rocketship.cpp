/****************************************
** Program name: rocketship.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Rocketship class
*****************************************/

#include "rocketship.h"
#include "spacesuit.h"
#include "ship.h"
#include "fuelcan.h"
#include "forcefield.h"
#include <iostream>

using std::cout;
using std::endl;

// Rocketship creates and places items in rocketship.
Rocketship::Rocketship(Player *p) : Space(p)
{
  ship = new Ship();
  suit = new Spacesuit();
  can = new Fuelcan();
  field = new Forcefield();

  // Place ship.
  display[2][4] = ship;

  // Place spacesuit.
  display[2][2] = suit;

  // Place bottom door.
  display[19][14] = boundary;
  display[19][16] = boundary;

  // Place rocketship forcefields.
  for (int i = 0; i < 31; i++)
  {
    display[4][i] = field;
  }
  display[4][10] = NULL;
  for (int i = 0; i < 31; i++)
  {
    display[9][i] = field;
  }
  display[9][27] = NULL;
  for (int i = 0; i < 31; i++)
  {
    display[11][i] = field;
  }
  display[11][3] = NULL;
  for (int i = 0; i < 31; i++)
  {
    display[14][i] = field;
  }
  display[14][9] = NULL;

  // Place fuelcan.
  display[12][28] = can;
}

// ~Rocketship destroys items in rocketship.
Rocketship::~Rocketship()
{
  delete ship;
  delete suit;
  delete can;
  delete field;
}

// print_prompt prints instructions for navigating rocketship;
void Rocketship::print_prompt()
{
  cout << "YOU ARE AT THE ROCKETSHIP" << endl;
  if (player->check_for_item("Spacesuit"))
  {
    cout << "You found the suit. There is nothing more to do here." << endl;
    cout << "Return to the outerspace to find the entryway to the alien planet." << endl;
  }
  else
  {
    cout << "Your rocketship (^) is behind several forcefield (X) walls." << endl;
    cout << "Navigate through them to your ship, your spacesuit (8) is nearby." << endl;
    cout << "Collect the suit so you can survive on the alien planet." << endl;
  }
}

// player_at_bottom allows the player to leave through the bottom door.
bool Rocketship::player_at_bottom()
{
  if (player->at(19,15))
  {
    display[19][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_bottom sets the player at the bottom of the rocketship.
void Rocketship::set_player_at_bottom()
{
  set_player_at_pos(18, 15);
}
