/****************************************
** Program name: Node.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description: Defines Node class
****************************************
***************************/
#include "Node.h"
#include <iostream>

Node::Node(){}
Node* Node::get_next()
{
  return next;
}
void Node::set_next(Node *n)
{
  next = n;
}
Node* Node::get_prev()
{
  return prev;
}
void Node::set_prev(Node *p)
{
  prev = p;
}
int Node::get_val()
{
  return val;
}
void Node::set_val(int v)
{
  val = v;
}
Node::~Node(){}
