/****************************************
** Program name: main_university.cpp
** Author: Amy Sage
** Date: 1/29/2018
** Description: main implementation of university
****************************************
***************************/
#include <iostream>
#include <stdlib.h>
#include "University.h"
#include "Building.h"
#include "Person.h"
#include "Student.h"
#include "Instructor.h"

int main()
{
   University my_u(2,2);
   Student s;
   Instructor i;
   Person *p;
   my_u.b[0].set_name((char*)"Kelley Engineering Center");
   my_u.b[0].set_size(134009);
   my_u.b[0].set_address((char*)"Corvallis");
   my_u.b[1].set_name((char*)"Milne Computer Center");
   my_u.b[1].set_size(21554);
   my_u.b[1].set_address((char*)"Corvallis");
   my_u.p[0].set_name((char*)"Amy");
   my_u.p[1].set_name((char*)"Noelle");
   my_u.p[0].set_age(27);
   my_u.p[1].set_age(30);
   my_u.b[0].print_info();
   my_u.b[1].print_info();
   my_u.p[0].set_gpa(3.0);
   my_u.p[1].set_rating(3.0);
   my_u.person_print();
return 0;
}
