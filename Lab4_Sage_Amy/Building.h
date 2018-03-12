/****************************************
** Program name: Building.h
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Tiger class
****************************************
***************************/
#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>

class Building
{
  private:
     char *name;
     char *address;
     float size;

  public:
       Building();
       Building(char*, float, char*);
       void set_name(char*);
       void set_size(float);
       void set_address(char*);
       void print_info();
};
#endif
