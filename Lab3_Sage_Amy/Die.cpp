/********************************************************************* 
** Program name: Die.cpp
** Author: Amy Sage
** Date: 1/23/18
** Description: describes Die class 
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include "Die.h"

//constructor
Die::Die(int n)
{
	N = n;
} 

int Die::get_num_sides()
{
	return N;
}
//random roll:w
int Die::get_roll_die()
{
	return rand()%N+1; 
}
