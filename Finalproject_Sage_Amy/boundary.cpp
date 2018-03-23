/****************************************
** Program name: boundary.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Boundary class
*****************************************/

#include "boundary.h"
#include <iostream>

// Boundary creates a new boundary.
Boundary::Boundary()
{
  this->appearance = '|';
  this->obtainable = false;
}
