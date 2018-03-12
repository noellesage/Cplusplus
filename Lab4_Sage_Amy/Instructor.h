/****************************************
** Program name: Instructor.h
** Author: Amy Sage
** Date: 1/29/2018
** Description: declares Instructor class
****************************************
***************************/
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include "Person.h"
#include <cmath>

class Instructor: public Person
{
   private:
       float rating;
       int hours;
   public:
       virtual float get_rating();
       virtual void set_rating(float);
       virtual void do_work();
};

#endif
