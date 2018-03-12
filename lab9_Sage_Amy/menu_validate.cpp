/****************************************
** Program name: menu_validate.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description:
****************************************
***************************/
#include "menu_validate.h"
#include "Buffer.h"
#include "Stack.h"

menu_validate::menu_validate(){};

void menu_validate::validate_percentage(double &num)
{
  while(num < 1 || num > 100)
  {
    cout << "Sorry, the percentage must be between 1-100. Try again: ";
    cin.clear();
    cin.ignore();
    cin >> num;
  }
}

void menu_validate::menu()
{
  int input;
  cout << "Please choose from the menu:" << endl;
  cout << "1) Test the buffer" << endl;
  cout << "2) Create a palindrome" << endl;
  cin >> input;
  input = validate(input);

  while(input < 1 || input > 2)
  {
    cout << "Please enter either a 1 or a 2: ";
    cin.clear();
    cin.ignore();
    cin >> input;
  }
  if(input == 1)
  {
    Buffer my_buffer;
    my_buffer.game_queue();
  }
  if(input == 2)
  {
    Stack my_stack;
    my_stack.game_stack();
  }
}

menu_validate::~menu_validate(){};
