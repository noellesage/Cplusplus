/****************************************
** Program name: LoserList.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines LoserList class
****************************************
**************************/
#ifndef LOSERLIST_H
#define LOSERLIST_H
#include <iostream>
#include "Character.h"

struct Loser
    {
      Character* c;
      Loser *next;
    };
class LoserList
{
  private:
    struct Loser *head; //head initialization
  public:
    LoserList(); //constructor
    ~LoserList(); //destructor
    void add_loser(Character*);
    void delete_loser();
    void print();
    bool isEmpty();
};
#endif
