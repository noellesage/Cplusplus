/****************************************
** Program name: Node.h
** Author: Amy Sage
** Date: 2/5/2018
** Description: Defines Node class
****************************************
***************************/
#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
  private:
    Node *next; //pointer to next node object
    Node *prev; //pointer to previous node object
    int val; //integer value node contains
  public:
    Node(); //constructor
    ~Node(); //destructor
    Node* get_next();
    void set_next(Node*);
    Node* get_prev();
    void set_prev(Node*);
    int get_val();
    void set_val(int);
};
#endif
