/****************************************
** Program name: Student.h
** Author: Amy Sage
** Date: 1/29/2018
** Description: declares Student class
****************************************
***************************/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"
#include <cmath>

class Student: public Person
{
  private:
      float gpa;
      int hours;

   public:
      virtual float get_gpa();
      virtual void set_gpa(float);
      virtual void do_work();
};

#endif
