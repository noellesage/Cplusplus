/****************************************
** Program name: Student.cpp
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Student class
****************************************
***************************/
#include <iostream>
#include "Student.h"
using std::cout;

void Student::set_gpa(float g)
{
   gpa=g;
   type_of_person=0;
}
float Student::get_gpa()
{
   return gpa;
}
void Student::do_work()
{
   hours=rand()%20;
   cout<<get_name()<<"did"<<hours<<"hours of homework\n";
}
