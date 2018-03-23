/****************************************
** Program name: alienspace.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Alienspace class
*****************************************/

#include "alienspace.h"
#include "alienthanks.h"
#include <iostream>

using std::cout;
using std::endl;

// Alienspace creates and places items in alienspace.
Alienspace::Alienspace(Player *p) : Space(p)
{
  cout << "Making thanks" << endl;
  thanks = new Alienthanks();
  cout << "thanks" << endl;

  // Set the floor to be a token representing a planet surface.
  floor = '+';

  // Place alienthanks.
  display[10][13] = thanks;
  display[12][15] = thanks;
  display[15][17] = thanks;

  // Place top door.
  display[1][14] = boundary;
  display[1][16] = boundary;
}

// ~Alienspace  destroys items in alienspace.
Alienspace::~Alienspace()
{
  delete thanks;
}

// print_prompt prints instructions for navigating alienspace.
void Alienspace::print_prompt()
{
  cout << "YOU ARE IN THE ALIEN HOMEWORLD" << endl;
  cout << "Gather the alien thanks (>) to be teleported home." << endl;
}

// player_at_top allows the player to leave through the top door.
bool Alienspace::player_at_top()
{
  if (player->at(1,15))
  {
    display[1][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_top sets the player at the top of alienspace.
void Alienspace::set_player_at_top()
{
  set_player_at_pos(2, 15);
}
