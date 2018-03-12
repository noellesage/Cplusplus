/****************************************
** Program name: Instructor.cpp
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Instructor class
****************************************
***************************/
#include <iostream>
#include "Person.h"
#include "Instructor.h"
#include <cstdlib>
using std::cout;

void Instructor::set_rating(float r)
{
   rating=r;
   type_of_person=1;
}
float Instructor::get_rating()
{
   return rating;
}
void Instructor::do_work()
{
   hours = rand() % 20;
   cout << get_name()<<"graded papers for"<<hours<<"hours of homework\n";
}
