/********************************************************************** Program name: Ant.hpp
** Author: Amy Sage
** Date: 1/18/2018
** Description: defines the ant class
********************************************************************/
#include <iostream>
#include <string>
#ifndef ANT
#define ANT
enum Direction { left, right, up, down };

class Ant
{ private: 
	Direction d;	
	int current_row, current_col, prev_row, prev_col; 
	char color;
  public:
	Ant();
	Ant(int r, int c);
	void set_direction(Direction d);
	void set_color(char);
	Direction get_direction();
	char get_color();
	void set_curr_row(int);
	void set_curr_col(int);
	int get_curr_col();
	int get_prev_col();
	void set_prev_col(int);
	void set_prev_row(int);
	int get_curr_row();
	int get_prev_row();

};

#endif	
	
	
	
	 
		
