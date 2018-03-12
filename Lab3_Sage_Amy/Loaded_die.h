/********************************************************************* 
** Program name: Loaded_die.h
** Author: Amy Sage
** Date: 1/23/18
** Description: defines loaded Die class
*********************************************************************/

#ifndef LOADED_H
#define LOADED_H
#include <iostream>
#include <string>
#include "Die.h"
 
class Loaded_die : public Die
{
	public:
		Loaded_die(int n) : Die(n){};
		int get_roll_die(); //override Die roll 
};

#endif	
