/****************************************
** Program name: starspace.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Starspace class
*****************************************/

#include "starspace.h"
#include "aliensecrets.h"
#include "star.h"
#include "fuelcan.h"
#include <iostream>

using std::cout;
using std::endl;

// Starspace creates and places items in starspace.
Starspace::Starspace(Player *p) : Space(p)
{
  secrets = new Aliensecrets();
  star = new Star();
  can = new Fuelcan();

  // Place aliens secrets.
  display[2][28] = secrets;

  // Place top door.
  display[1][14] = boundary;
  display[1][16] = boundary;

  // Place bottom door.
  display[19][14] = boundary;
  display[19][16] = boundary;

  // Place stars.
  display[3][28] = star;
  display[3][4] = star;
  display[3][6] = star;
  display[4][8] = star;
  display[4][14] = star;
  display[4][16] = star;
  display[5][5] = star;
  display[5][10] = star;
  display[5][22] = star;
  display[7][20] = star;
  display[8][3] = star;
  display[8][5] = star;
  display[8][7] = star;
  display[8][20] = star;
  display[8][21] = star;
  display[9][20] = star;
  display[9][21] = star;
  display[10][2] = star;
  display[10][4] = star;
  display[10][5] = star;
  display[10][8] = star;
  display[10][10] = star;
  display[10][12] = star;
  display[10][18] = star;
  display[10][24] = star;
  display[10][15] = star;
  display[10][10] = star;
  display[12][12] = star;
  display[12][20] = star;
  display[12][25] = star;
  display[15][25] = star;
  display[16][25] = star;
  display[15][24] = star;
  display[15][4] = star;
  display[15][9] = star;
  display[15][15] = star;
  display[15][18] = star;
  display[16][24] = star;
  display[17][3] = star;
  display[17][5] = star;
  display[17][8] = star;
  display[17][10] = star;
  display[17][17] = star;
  display[17][22] = star;
  display[18][2] = star;
  display[18][6] = star;
  display[18][14] = star;

  // Place fuelcan.
  display[12][3] = can;
}

// ~Starspace destroys items in starspace.
Starspace::~Starspace()
{
  delete secrets;
  delete star;
  delete can;
}

// print_prompt prints instructions for navigating starspace.
void Starspace::print_prompt()
{
  cout << "YOU ARE IN STARSPACE" << endl;
  if (player->check_for_item("Alien Secrets") && player->check_for_item("Spacesuit"))
  {
    cout << "There is nothing more to do here, head to the alien planet." << endl;
  }
  else if (player->check_for_item("Alien Secrets"))
  {
    cout << "You found the secrets! You put them in the box." << endl;
    cout << "A new path has opened up to you, but you must now go past a black hole." << endl;
    cout << "There is nothing more to do here." << endl;
  }
  else
  {
    cout << "The alien secrets (?) are somewhere in this star system." << endl;
    cout << "Navigate through the stars (*) and find the secrets." << endl;
  }
  if (player->at(1,15) && !player->check_for_item("Alien Secrets"))
  {
    cout << "Wait! You need the aliens secrets before continuing on!" << endl;
  }
}

// player_at_top allows the player to leave through the top door
// if they have the Alien Secrets.
bool Starspace::player_at_top()
{
  if (player->at(1,15) && player->check_for_item("Alien Secrets"))
  {
    display[1][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_top sets the player at the top of starspace.
void Starspace::set_player_at_top()
{
  set_player_at_pos(2, 15);
}

// player_at_bottom allows the player to leave through the bottom door.
bool Starspace::player_at_bottom()
{
  if (player->at(19,15))
  {
    display[19][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_bottom sets the player at the bottom of starspace.
void Starspace::set_player_at_bottom()
{
  set_player_at_pos(18, 15);
}
