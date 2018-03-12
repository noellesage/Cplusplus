/****************************************
** Program name: menu_validate.h
** Author: Amy Sage
** Date: 3/7/2018
** Description:
****************************************
***************************/
#ifndef MENU_VALIDATE_H
#define MENU_VALIDATE_H
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include <random>
#include <iterator>
using std::endl;
using std::cout;
using std::cin;

class menu_validate
{
  public:
    menu_validate();
    template <typename T>
    T validate(T &a)
    {
      while(cin.fail())
      {
        cout << "Invalid Entry. Must be a number. Try again: ";
        cin.clear();
        cin.ignore();
        cin >> a;
      }
      return a;
    }
    void validate_percentage(double&);
    void menu();
    ~menu_validate();
};

#endif
