/****************************************
** Program name: item.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Describes the Item class
*****************************************/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using std::string;

class Item
{
  protected:
    char appearance;
    int x_coord;
    int y_coord;
    bool direction;
    bool obtainable;
    string name;
  public:
    Item();
    ~Item();
    void set_x(int);
    void set_y(int);
    int get_x();
    int get_y();
    bool at(int, int);
    bool is_obtainable();
    void set_obtainable(bool);
    char get_appearance();
    void set_appearance(char);
    string get_name();
};

#endif
