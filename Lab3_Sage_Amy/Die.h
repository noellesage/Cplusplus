/********************************************************************* 
** Program name: Die.h
** Author: Amy Sage
** Date: 1/23/18
** Description: defines Die class
*********************************************************************/

#ifndef DIE_H
#define DIE_H
#include <iostream>

class Die
{
	protected:
		int N; //numsides on die
	public:
		Die(int); //constructor
		int get_num_sides();
		int get_roll_die(); //randomizes roll b/n 1-N 
};

#endif
