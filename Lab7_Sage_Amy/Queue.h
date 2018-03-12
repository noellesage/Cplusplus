/****************************************
** Program name: Queue.h
** Author: Amy Sage
** Date: 2/19/2018
** Description: Defines Queue class
****************************************
***************************/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

struct QueueNode
{
  int val;
  struct QueueNode *prev;
  struct QueueNode *next;
};

class Queue
{
  protected:
    struct QueueNode *head;
  public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
};
#endif
