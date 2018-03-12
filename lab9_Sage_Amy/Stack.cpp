/****************************************
** Program name: Stack.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description:
****************************************
***************************/
#include "Stack.h"

Stack::Stack(){};
void Stack::game_stack()
{
  std::string my_string;
  int str_length = 0;

  cout << "Please enter a string:";
  cin.ignore();
  std::getline(cin, my_string, '\n');
  //get string length
  str_length = my_string.length();
  //put string into vector of characters
  std::vector<char> my_vector;
  for(int i=0; i<str_length; i++) my_vector.push_back(my_string.at(i));

  //create stack of a vector of characters from vector above^^^
  std::stack<char, std::vector<char> > my_stack (my_vector); //create stack of char
  //do palindrome thing
  //add characters to stack
  for(int i=0; i<str_length; i++)
  {
    my_stack.push(my_vector[i]); //push characters onto stack
    cout << my_stack.top();
  }
  for(int i=0; i<str_length; i++)
  {
    cout << my_stack.top(); //print top
    my_stack.pop(); //pop top
  }
	std::cout << std::endl;
}
Stack::~Stack(){};
