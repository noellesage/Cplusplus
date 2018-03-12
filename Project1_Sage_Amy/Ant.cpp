/********************************************************************** Program name: Ant.cpp
** Author: Amy Sage
** Date: 1/18/2018
** Description: implements the ant class
********************************************************************/

#include "Ant.hpp"
#include <iostream>

Ant::Ant()
{}
Ant::Ant(int r, int c)
{
	set_direction(up);
	set_color(' ');
	set_curr_row(r);
	set_curr_col(c);
	set_prev_col(c);
	set_prev_row(r);	
}	
void Ant::set_direction(Direction di)
{
	d = di;
}
void Ant::set_color(char c)
{
	color = c;
}
Direction Ant::get_direction()
{
	return d;
}
char Ant::get_color()
{
	return color;
}
void Ant::set_curr_row(int curr_r)
{
	current_row = curr_r;
}
void Ant::set_curr_col(int curr_col)
{
	current_col = curr_col;
}
void Ant::set_prev_row(int prev_r)
{
	prev_row = prev_r;
}
void Ant::set_prev_col(int prev_c)
{
	prev_col = prev_c;
}
int Ant::get_curr_row()
{
	return current_row;
}
int Ant::get_curr_col()
{
	return current_col;
}
int Ant::get_prev_row()
{
	return prev_row;
}
int Ant::get_prev_col()
{
	return prev_col;
}
