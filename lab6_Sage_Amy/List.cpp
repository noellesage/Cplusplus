/****************************************
** Program name: List.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description: Implements List class
****************************************
**************************/
#include <iostream>
#include "List.h"
using std::endl;
using std::cout;
using std::cin;

List::List()//constructor
{
  head = nullptr;
  tail = nullptr;
}

void List::add_new_head(int v)
{
  //create new Node
  Node *nodePtr = new Node();
  //set value of new node to intake value
  nodePtr->set_val(v);
  //if there's only one node
  if (tail == NULL)
  {
    //set head and tail to new
    tail = nodePtr;
    head = nodePtr;
  }
  else
  {
    //assign previous head as next
    nodePtr->set_next(head);
    //assign current node as previous, head
    head->set_prev(nodePtr);
    //set head to current pointer
    head = nodePtr;
  }
}

void List::add_new_tail(int v)
{
  //create new node
  Node *nodePtr = new Node();
  //set value of new node to intake value
  nodePtr->set_val(v);
  //if empty
  if(head == NULL)
  {
    tail = nodePtr;
    head = nodePtr;
  }
  else
  {
    //assign previous tail to previous
    nodePtr->set_prev(tail);
    //assign current node as next, tail
    tail->set_next(nodePtr);
    //assign current node as tail
    tail = nodePtr;
  }
}

void List::delete_first_node()
{
  //if one node
   if (head == tail)
  {
    head = tail = NULL;
  }
  //if head is not null
  if(head != NULL)
  {
    Node *nextNode = new Node();
    nextNode = head->get_next();
    if(nextNode != NULL)
    {
      nextNode->set_prev(NULL);
    }
    head = NULL;
    head = nextNode;
  }
}

void List::delete_last_node()
{
   //if one node
  if (head == tail)
  {
    head = tail = NULL;
  }
  //if head is not null
  if(head != NULL)
  {
    if(tail != NULL)
    {
      Node *newTail = new Node();
      newTail = tail->get_prev();
      tail = NULL;
      newTail->set_next(NULL);
      tail = newTail;
    }
    else
    {
      head = NULL;
    }
  }
}

void List::traverse()
{
  Node *temp = head;
  //if empty
  if(temp == NULL)
  {
    cout << "The list is empty." << endl;
  }
  //while not empty
  if(temp != NULL)
  {
    cout << "Your linked list is: ";
  }
  while(temp != NULL)
  {
    //print values
    int value;
    value = temp->get_val();
    cout << value << " ";
    temp = temp->get_next();
  }
}

void List::traverse_reverse()
{
  Node *temp = tail;
  if(temp == NULL)
  {
    cout << "The list is empty." << endl;
  }
  if(temp != NULL)
  {
    cout << "Your linked list is: ";
  }
  //while not empty
  while(temp != NULL)
  {
    //print values
    int value;
    value = temp->get_val();
    cout << value << " ";
    temp = temp->get_prev();
  }
}

void List::print_head()
{
  if(head == NULL && tail == NULL)
  {
    cout << "Sorry the list is empty." << endl;
  }
  else
  {
  int node_val = head->get_val();
  cout << "The head is pointing to the value: " << node_val << endl;
  }
}

void List:: print_tail()
{
  if(head == NULL && tail == NULL)
  {
    cout << "Sorry the list is empty." << endl;
  }
  else
  {
  int node_val = tail->get_val();
  cout << "The tail is pointing to the value: " << node_val << endl;
  }
}

int List::menu()
{
  bool valid_menu = false;
  int menu_choice = 0;
  cout << "Menu" << endl;
  cout << "1) Add a new node to the head." << endl;
  cout << "2) Add a new node to the tail." << endl;
  cout << "3) Delete the first node in the list." << endl;
  cout << "4) Delete the last node in the list." << endl;
  cout << "5) Traverse the list reversely." << endl;
  cout << "6) Print the value of the Node the head is pointing to." << endl;
  cout << "7) Print the value of the Node the tail is point to." << endl;
  cout << "8) Exit" << endl;
  do
  {
      cin >> menu_choice;
      if(cin.fail())
      {
              cin.clear();
              cin.ignore();
              cout << "Invalid. Enter a 1, 2, 3, or 4" << endl;
      }
      else
      {
              valid_menu = true;
              return menu_choice;
      }
  }while(valid_menu = false);
}

List::~List(){}
