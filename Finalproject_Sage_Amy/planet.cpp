/****************************************
** Program name: planet.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Planet class
*****************************************/

#include "planet.h"
#include "rock.h"
#include <iostream>

using std::cout;
using std::endl;

// Planet creates and places items in planet.
Planet::Planet(Player *p) : Space(p)
{
  rock = new Rock();

  // Place right door.
  display[9][1] = boundary;
  display[11][1] = boundary;

  // Place planet.
  for (int i = 4; i < 27; i++)
    display[19][i] = rock;
  for (int i = 5; i < 26; i++)
    display[18][i] = rock;
  for (int i = 8; i < 23; i++)
    display[17][i] = rock;
  for (int i = 12; i < 19; i++)
    display[16][i] = rock;
}

// ~Planet destroys items in planet.
Planet::~Planet()
{
  delete rock;
}

// update_space removes a chunk of the planet when the Spacesuit is obtained.
void Planet::update_space()
{
  if (player->check_for_item("Spacesuit"))
  {
    // Clear a path.
    display[16][17] = NULL;
    display[17][17] = NULL;
    display[18][17] = NULL;
    display[19][17] = NULL;
  }
}

// print_prompt prints instructions for navigating planet.
void Planet::print_prompt()
{
  cout << "YOU ARE NEAR THE ALIEN PLANET" << endl;
  if (player->check_for_item("Spacesuit"))
  {
    cout << "A path has opened into the planet. Enter." << endl;
  }
  else
  {
    cout << "You must collect all items before entering the alien planet." << endl;
  }
}

// player_at_left allows the player to leave through the left door.
bool Planet::player_at_left()
{
  if (player->at(10,1))
  {
    display[10][1] = NULL;
    return true;
  }
  return false;
}

// set_player_at_left sets the player at the left of planet.
void Planet::set_player_at_left()
{
  set_player_at_pos(10, 2);
  update_space();
}

// player_at_bottom allows the player to leave through the bottom door
// if they have the Spacesuit.
bool Planet::player_at_bottom()
{
  if (player->at(19,17) && player->check_for_item("Spacesuit"))
  {
    display[19][17] = NULL;
    return true;
  }
  return false;
}

// set_player_at_bottom sets the player at the bottom of planet.
void Planet::set_player_at_bottom()
{
  set_player_at_pos(18, 17);
}
