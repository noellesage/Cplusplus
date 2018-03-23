/****************************************
** Program name: outerspace.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Outerspace class
*****************************************/

#include "outerspace.h"
#include "alienbox.h"
#include "forcefield.h"
#include "fuelcan.h"
#include <iostream>

using std::cout;
using std::endl;

// Outerspace creates and places items in outerspace.
Outerspace::Outerspace(Player *p) : Space(p)
{
  box = new Alienbox();
  field = new Forcefield();
  fakebox = new Alienbox();
  can = new Fuelcan();

  // Place alien box.
  display[6][25] = box;

  // Place top door.
  display[1][14] = boundary;
  display[1][16] = boundary;
  display[1][15] = field;

  // Place right door.
  display[9][29] = boundary;
  display[11][29] = boundary;

  // Place fake alien boxs.
  fakebox->set_obtainable(false);
  display[10][24] = fakebox;
  display[17][4] = fakebox;
  display[15][20] = fakebox;
  display[6][15] = fakebox;
  display[8][27] = fakebox;
  display[3][10] = fakebox;
  display[18][18] = fakebox;
  display[19][27] = fakebox;
  display[16][3] = fakebox;

  // Place fuelcan.
  display[18][5] = can;
}

// ~Outerspace destroys items in outerspace.
Outerspace::~Outerspace()
{
  delete box;
  delete field;
  delete fakebox;
  delete can;
}

// update_space removes the force field when the Alien Box is obtained.
void Outerspace::update_space()
{
  if (player->check_for_item("Alien Box"))
  {
    Item *field = display[1][15];
    display[1][15] = NULL;
    if (field != NULL)
    {
      delete field;
    }
  }
}

// print_prompt prints instructions for navigating starspace.
void Outerspace::print_prompt()
{
  cout << "YOU ARE IN OUTERSPACE" << endl;
  if (player->check_for_item("Alien Box"))
  {
    cout << "You found the alien box. There's nothing more to do here." << endl;
  }
  else
  {
    cout << "A nearby freighter crash has left tons of empty boxes (=)." << endl;
    cout << "You'll need to find the alien box (=) with unbreakable cryptography" << endl;
    cout << "so that you can secure the secrets for the aliens." << endl;
    cout << "Remember, there are lot's of fake boxes (=) that you cannot pick up." << endl;
    cout << "Find the alien box to unlock the force field (X) to starspace." << endl;
  }
}

// player_at_top allows the player to leave through the top door
// if they have the Alien Box.
bool Outerspace::player_at_top()
{
  if (player->at(1,15) && player->check_for_item("Alien Box"))
  {
    display[1][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_top sets the player at the top of outerspace.
void Outerspace::set_player_at_top()
{
  set_player_at_pos(2, 15);
}

// player_at_right allows the player to leave through the right door.
bool Outerspace::player_at_right()
{
  if (player->at(10, 29))
  {
    display[10][29] = NULL;
    return true;
  }
  return false;
}

// set_player_at_right sets the player at the right of outerspace.
void Outerspace::set_player_at_right()
{
  set_player_at_pos(10,28);
}
