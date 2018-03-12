/****************************************
** Program name: University.h
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Tiger class
****************************************
***************************/
#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include "Building.h"
#include "Person.h"
#include "Student.h"
#include "Instructor.h"

class University
{
  private:
      char *name = (char*)"OSU";
      int n, m;

  public:
     Building *b;
     Person *p;
     University(int, int);
     void building_print();
     void person_print();
};
#endif
