/****************************************
** Program name: LineupQueue.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines LineupQueue class
****************************************
***************************/
#ifndef LINEUPQUEUE_H
#define LINEUPQUEUE_H
#include <iostream>
#include "Character.h"

class LineupQueue
{
  protected:
  struct Lineup
  {
    Character* c;
    Lineup *next;
    Lineup *prev;
    Lineup(Character* c1, Lineup* n1 = NULL, Lineup* p1 = NULL)
    {
      c = c1;
      next = n1;
      prev = p1;
    }
  };
    Lineup *head;
    Lineup *tail;
  public:
    LineupQueue();
    ~LineupQueue();
    void addNode(Character*);
    bool isEmpty();
    Character* deleteNode();
    void print();
};
#endif
