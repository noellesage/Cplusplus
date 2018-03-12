/****************************************
** Program name: Person.cpp
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Person class
****************************************
***************************/
#include <iostream>
#include "Person.h"
using std::cout;
using std::endl;

void Person::set_name(char* n)
{
   name=n;
}
char* Person::get_name()
{
   return name;
}
void Person::set_age(int n)
{
   age=n%100;
}
int Person::get_age()
{
   return age;
}
float Person::get_gpa(){}
float Person::get_rating(){}
void Person::set_rating(float){}
void Person::set_gpa(float){}
void Person::do_work()
{
   cout<<"do work" << endl;
}
