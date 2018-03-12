/****************************************
** Program name: Queue.cpp
** Author: Amy Sage
** Date: 2/19/2018
** Description: Describes Queue class
****************************************
***************************/
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

Queue::Queue()
{
  head = NULL;
}

bool Queue::isEmpty()
{
  if(head == NULL)
  {
    return true;
  }
  return false;
}
void Queue::addBack(int val)
{
  if(isEmpty() == true)//if empty
  {
    head = new QueueNode; //if empty dynamically allocate new head
    head->val = val;
    head->next = head->prev = head;
  }
  else
  {
  //if not empty
    QueueNode *end = head->prev;
    QueueNode *tail = new QueueNode; //new node - set prev/next
    tail->val = val;
    tail->next = head;
    tail->prev = end;
    
    head->prev = tail;
    end->next = tail;
  }  
}
int Queue::getFront()
{
  return head->val;
}

void Queue::removeFront()
{
  if(isEmpty() == true)//if empty
  {
    return;
  }
  else if(head == head->next)//only one
  {
    delete head;
    head = NULL;
  }
  else
  {
    QueueNode *tail = head;
    head = head->next;
    head->prev = tail->prev;
    head->prev->next = head;
    //deallocate
    delete tail;
  }  
}

void Queue::printQueue()
{
 if(isEmpty() == false)
 {
   QueueNode* temp = head;
   while(temp->next != head)
   {
     cout << temp->val << " ";
     temp = temp->next;
   }
   cout << temp->val << endl;
 }
 cout << endl;
}

Queue::~Queue()
{
  while(isEmpty() == false)
  {
    removeFront();
  }
}