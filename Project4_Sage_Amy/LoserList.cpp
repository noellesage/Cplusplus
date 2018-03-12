/****************************************
** Program name: LoserList.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Implements LoserList class
****************************************
**************************/
#include <iostream>
#include "LoserList.h"
#include "Character.h"
using std::endl;
using std::cout;
using std::cin;

LoserList::LoserList()//constructor
{
  head = NULL;
}

void LoserList::add_loser(Character *_c)
{
  if(head == NULL)
  {
    Loser *temp = new Loser;
    temp->c = _c;
    head = temp;
    temp = NULL;
  }
  else
  {
    Loser *temp = new Loser;
    temp->c = _c;
    temp->next = head;
    head = temp;
  }
}

void LoserList::delete_loser() {

	if (head == NULL)
  {
		cout << "Loser list is empty" << endl;
	}

	else if (head->next == NULL)
  {
		string remove_char = (head->c)->get_name();
		cout << remove_char << " ";
		string remove_char_type = (head->c)->get_type();
		cout << remove_char_type << " " << endl;
		delete (head->c);
		delete head;
		head = NULL;
	}

	else
  {
		Loser *removePtr = head;
		string remove_char = (head->c)->get_name();
		cout << remove_char	<< " ";
		string remove_char_type = (head->c)->get_type();
		cout << remove_char_type << " " << endl;
		delete (head->c);
		head = head->next;
		removePtr->next = NULL;
		delete removePtr;
		removePtr = NULL;
	}
}
void LoserList::print() {

	if (head == NULL)
  {
		cout << "Sorry, there's nothing here." << endl;
	}

	Loser * cPtr = head;
	while (cPtr != NULL)
  {
		cout << (cPtr->c)->get_name() << " ";
		cout << (cPtr->c)->get_type() << " " << endl;
		cPtr = cPtr->next;
	}

	delete (cPtr);
	cPtr = NULL;
}

bool LoserList::isEmpty()
{
	if(head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

LoserList::~LoserList() {
	if (head != NULL)
  {
		while (head->next != NULL)
    {
			Loser *temp = head;
			delete (head->c);
			head = head->next;
			temp->next = NULL;
			delete temp;
			temp = NULL;
		}
	delete (head->c);
	delete head;
	head = NULL;
	}
}
