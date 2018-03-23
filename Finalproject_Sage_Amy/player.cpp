/****************************************
** Program name: player.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Player class
*****************************************/

#include "player.h"
#include <iostream>

using std::cout;
using std::endl;

// Player creates a new player with max fuel and an empty inventory.
Player::Player() : Item()
{
  fuel = 300;
  appearance = '&';
  inventory_size = 20;
  for(int i=0; i < inventory_size; i++)
  {
    this->inventory[i] = "";
  }
}

// Add item adds an item to the player's inventory
void Player::add_item(std::string item_name)
{
  int i = 0;
  while(inventory[i] != "") {
    if (inventory[i] == item_name)
      return;
    i++;
  }
  inventory[i] = item_name;
}

// Check if the player has an item in their inventory
bool Player::check_for_item(std::string item_name)
{
  for(int i = 0; i < inventory_size; i++)
  {
    if (inventory[i] == item_name) {
      return true;
    } }
  return false;
}

// Print the inventory
void Player::print_inventory()
{
  cout << "|||||||||| Inventory ||||||||||" << endl;
  if (inventory_size == 0)
  {
    cout << "[No items]" << endl;
  }
  for(int i=0; i < inventory_size; i++)
  {
    if (inventory[i] != "")
    {
      if (i != 0)
      {
        cout << " | ";
      }
      cout << inventory[i];
    }
  }
  cout << endl;
}

void Player::increment_fuel()
{
  fuel += 100;
}

// Decrease the amount of remaining fuel
void Player::decrement_fuel()
{
  fuel--;
}

// Get the current level of fuel
int Player::get_fuel()
{
  return fuel;
}

void Player::print_fuel()
{

  cout << "|||||||||||||||||||||||||||||||" << endl;
  cout << "Fuel at: " << fuel << endl;
}
