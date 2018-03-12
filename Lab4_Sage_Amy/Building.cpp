/****************************************
** Program name: Building.cpp
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Building class
****************************************
***************************/
#include <iostream>
#include "Building.h"
using std::cout;

Building::Building()
{
    size=0;
}
Building::Building(char *n,float s,char * a)
{
   name=n;
   size=s;
   address=a;
}
void Building::set_name(char *c)
{
   name=c;
}
void Building::set_size(float s)
{
   size=s;
}
void Building::set_address(char *a)
{
   address=a;
}
void Building::print_info()
{
   cout<<"Name of building: "<<name<<"\n";
   cout<<"Size of building(sqft): "<<size<<"\n";
   cout<<"Address of building: "<<address<<"\n";
}
