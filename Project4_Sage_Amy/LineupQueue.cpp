/****************************************
** Program name: LineupQueue.cpp
** Author: Amy Sage
** Date: 2/19/2018
** Description: Describes LineupQueue class
****************************************
***************************/
#include "LineupQueue.h"
#include <iostream>
using std::cout;
using std::endl;

LineupQueue::LineupQueue()
{
  head = NULL;
  tail = NULL;
}

bool LineupQueue::isEmpty()
{
  if((head == NULL) && (tail == NULL))
  {
    return true;
  }
  else
  {
      return false;
  }
}

void LineupQueue::addNode(Character* _c)
{
  if(head == NULL && tail == NULL)
  {
    Lineup *lptr = new Lineup(_c);
    tail = lptr;
    head = lptr;
    lptr = NULL;
  }
  else
  {
    Lineup *lptr = new Lineup(_c, tail, NULL);
    tail->prev = lptr;
    tail = lptr;
    lptr = NULL;
  }
}

Character* LineupQueue::deleteNode()
{
  if(head == NULL)
  {
    return NULL;
  }
  else if(head == tail)
  {
    Lineup *temp = head;
    Character* del_char = (head->c);
    head = NULL;
    tail = NULL;
    delete temp;
    return del_char;
  }
  else
  {
    Lineup *temp = head;
    Character* del_char = (head->c);
    head = head->prev;
    head->next = NULL;
    temp->prev = NULL;
    delete temp;
    temp = NULL;
    return del_char;
  }
  return 0;
}

void LineupQueue::print()
{
  if(head == NULL)
  {
    cout << "All players are finished." << endl;
  }

  Lineup* lptr = tail;

  while(lptr != NULL)
  {
    cout << (lptr->c)->get_name() << " ";
    cout << (lptr->c)->get_type() << " " << endl;
    lptr = lptr->next;
  }

  lptr = NULL;
}

LineupQueue::~LineupQueue()
{
  if(head == NULL)
  {
    return;
  }
  while(head != NULL)
  {
    if(head == tail)
    {
      Lineup *temp = head;
      delete head->c;
      head = NULL;
      tail = NULL;
      delete temp;
      temp = NULL;
    }
    else
    {
      Lineup *temp = head;
      delete (head->c);
      head = head->prev;
      head->next = NULL;
      temp->prev = NULL;
      delete temp;
      temp = NULL;
    }
  }
}
