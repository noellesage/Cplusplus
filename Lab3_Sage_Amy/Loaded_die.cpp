/********************************************************************* 
** Program name: Loaded_die.cpp
** Author: Amy Sage
** Date: 1/23/18
** Description: describes loaded die class 
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include "Loaded_die.h"
#include "Die.h"

int Loaded_die::get_roll_die()
{
	int x = rand()%get_num_sides() + 1;
	x += 2;
	return x;
}



