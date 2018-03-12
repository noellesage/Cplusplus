/****************************************
** Program name: Person.h
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Person class
****************************************
***************************/
#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person
{
  private:
    char *name;
    int age;

  public:
      int type_of_person;
      void set_name(char*);
      char* get_name();
      void set_age(int);
      int get_age();
      void do_work();
      float get_gpa();
      float get_rating();
      void set_gpa(float);
      void set_rating(float);
};
#endif
