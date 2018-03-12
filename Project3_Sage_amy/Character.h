/****************************************
** Program name: character.h
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::endl;
using std::cout;

class Character
{
  protected:
    string name;
    int armor, strength;
  public:
    Character();
    Character(string, int, int);
    virtual ~Character() = 0;
    virtual int attack() = 0;
    virtual int defense(int attack) = 0;
    int get_strength();
    int get_armor();
    string get_name();
};
#endif
