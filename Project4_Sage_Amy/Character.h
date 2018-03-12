/****************************************
** Program name: Character.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines character class
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
    string type, name, team;
    int armor, strength;
  public:
    Character();
    Character(string, int, int);
    virtual ~Character() = 0;
    virtual int attack() = 0;
    virtual int defense(int attack) = 0;
    int get_strength();
    void set_strength(int);
    int get_armor();
    string get_name();
    string get_type();
    int recover();
};
#endif
