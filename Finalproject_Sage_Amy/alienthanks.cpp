/****************************************
** Program name: alienthanks.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Alienthanks class
*****************************************/

#include "alienthanks.h"
#include <iostream>

using std::cout;
using std::endl;

// Alienthanks creates a new alienthanks.
Alienthanks::Alienthanks() : Item()
{
  cout << "Making thanks in thanks class" << endl;
  appearance = '>';
  name = "Alien Thanks";
  cout << "Making thanks in thanks class done" << endl;
}
