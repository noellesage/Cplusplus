/****************************************
** Program name: hole.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Hole class
*****************************************/

#include "hole.h"
#include <iostream>

// Hole creates a new hole.
Hole::Hole()
{
  this->appearance = '@';
  this->obtainable = false;
}
