/****************************************
** Program name: List.h
** Author: Amy Sage
** Date: 2/5/2018
** Description: Defines List class
****************************************
**************************/
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Node.h"

class List
{
  private:
    Node *head; //head initialization
    Node *tail; //last node initialization
  public:
    List(); //constructor
    ~List(); //destructor
    void add_new_head(int);
    void add_new_tail(int);
    void delete_first_node();
    void delete_last_node();
    void traverse();
    void traverse_reverse();
    void print_head();
    void print_tail();
    int menu();
};
#endif
