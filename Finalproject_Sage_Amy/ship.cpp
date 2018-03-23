/****************************************
** Program name: ship.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Ship class
*****************************************/

#include "ship.h"

#include <iostream>

// Ship creates a new ship.
Ship::Ship()
{
  this->appearance = '^';
  this->obtainable = false;
}
