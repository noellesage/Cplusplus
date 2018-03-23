/****************************************
** Program name: item.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Item class
*****************************************/

#include "item.h"
#include <iostream>

// Item constructs a new item.
Item::Item()
{
  appearance = 'i';
  obtainable = true;
  name = "Item";
}

Item::~Item()
{
}

void Item::set_x(int x)
{
  x_coord = x;
}

void Item::set_y(int y)
{
  y_coord = y;
}

int Item::get_x()
{
  return x_coord;
}

int Item::get_y()
{
  return y_coord;
}

bool Item::at(int x, int y)
{
  if (x_coord == x && y_coord == y)
    return true;
  return false;
}

bool Item::is_obtainable()
{
  return obtainable;
}

void Item::set_obtainable(bool a)
{
  obtainable = a;
}

char Item::get_appearance()
{
  return appearance;
}

void Item::set_appearance(char a)
{
  appearance = a;
}

std::string Item::get_name()
{
  return name;
}

