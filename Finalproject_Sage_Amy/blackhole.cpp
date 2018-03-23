/****************************************
** Program name: blackhole.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Blackhole class
*****************************************/

#include "blackhole.h"
#include "hole.h"
#include "rocketshipkey.h"
#include "fuelcan.h"
#include <iostream>

using std::cout;
using std::endl;

// Blackhole creates and places items in blackhole.
Blackhole::Blackhole(Player *p) : Space(p)
{
  key = new Rocketshipkey();
  can = new Fuelcan();
  hole = new Hole();

  // Set the floor to be the same token as the black hole.
  floor = '@';

  // Place rocketship key.
  display[1][1] = key;

  // Place fuelcan.
  display[1][29] = can;

  // Place top door.
  display[1][14] = boundary;
  display[1][16] = boundary;

  // Place bottom door.
  display[19][14] = boundary;
  display[19][16] = boundary;

  // Place blackhole.
  /*
  for (int i = 3; i < 18; i++)
    for (int j = 2; j < 29; j++)
      display[i][j] = hole;
  */
  display[3][28] = hole;
  display[3][4] = hole;
  display[3][6] = hole;
  display[4][8] = hole;
  display[4][14] = hole;
  display[4][16] = hole;
  display[5][5] = hole;
  display[5][10] = hole;
  display[5][22] = hole;
  display[7][20] = hole;
  display[8][3] = hole;
  display[8][5] = hole;
  display[8][7] = hole;
  display[8][20] = hole;
  display[8][21] = hole;
  display[9][20] = hole;
  display[9][21] = hole;
  display[10][2] = hole;
  display[10][4] = hole;
  display[10][5] = hole;
  display[10][8] = hole;
  display[10][10] = hole;
  display[10][12] = hole;
  display[10][18] = hole;
  display[10][24] = hole;
  display[10][15] = hole;
  display[10][10] = hole;
  display[12][12] = hole;
  display[12][20] = hole;
  display[12][25] = hole;
  display[15][25] = hole;
  display[16][25] = hole;
  display[15][24] = hole;
  display[15][4] = hole;
  display[15][9] = hole;
  display[15][15] = hole;
  display[15][18] = hole;
  display[16][24] = hole;
  display[17][3] = hole;
  display[17][5] = hole;
  display[17][8] = hole;
  display[17][10] = hole;
  display[17][17] = hole;
  display[17][22] = hole;
  display[18][2] = hole;
  display[18][6] = hole;
  display[18][14] = hole;
}

// ~Blackhole destroys items in blackhole.
Blackhole::~Blackhole()
{
  delete key;
  delete can;
  delete hole;
}

// print_prompt prints instructions for navigating blackhole.
void Blackhole::print_prompt()
{
  cout << "YOU ARE IN THE BLACKHOLE" << endl;
  if (player->check_for_item("Rocketship Key"))
  {
    cout << "You found the key. There is nothing more to do here." << endl;
  }
  else
  {
    cout << "Oh no! A blackhole! It's hard to see in here. There are invisible obstacles" << endl;
    cout << "blocking your path." << endl;
    cout << "Find your way around to the other side! (Hint: Let the stars guide you)." << endl;
    cout << "Find the rocketship key ($) to progress." << endl;
  }
  if (player->at(1,15) && !player->check_for_item("Rocketship Key"))
  {
    cout << "Wait! You need the Rocketship Key ($) before heading to your ship." << endl;
  }
}

// player_at_top allows the player to leave through the top door
// if they have the Rocketship Key."
bool Blackhole::player_at_top()
{
  if (player->at(1,15) && player->check_for_item("Rocketship Key"))
  {
    display[1][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_top sets the player at the top of blackhole.
void Blackhole::set_player_at_top()
{
  set_player_at_pos(2, 15);
}

// player_at_bottom allows the player to leave through the bottom door.
bool Blackhole::player_at_bottom()
{
  if (player->at(19, 15))
  {
    display[19][15] = NULL;
    return true;
  }
  return false;
}

// set_player_at_bottom sets the player at the bottom of blackhole.
void Blackhole::set_player_at_bottom()
{
  set_player_at_pos(18,15);
}
