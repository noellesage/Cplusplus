/****************************************
** Program name: space.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Space class
*****************************************/

#ifndef SPACE_H
#define SPACE_H

#include "item.h"
#include "player.h"
#include "boundary.h"

class Space
{
  public:
    Space(Player*);
    virtual ~Space()=0;
    void print_space();
    void move_player();
    void pick_up_item(int, int);
    void set_player_at_pos(int, int);
    void move_player_pos(int, int);
    virtual void print_prompt()=0;
    virtual void update_space();
    virtual void set_player_at_top();
    virtual void set_player_at_bottom();
    virtual void set_player_at_left();
    virtual void set_player_at_right();
    virtual void set_top(Space *t);
    virtual Space* get_top();
    virtual void set_bottom(Space *t);
    virtual Space* get_bottom();
    virtual void set_left(Space *t);
    virtual Space* get_left();
    virtual void set_right(Space *t);
    virtual Space* get_right();
    virtual bool player_at_top();
    virtual bool player_at_bottom();
    virtual bool player_at_left();
    virtual bool player_at_right();
  protected:
    Space *top, *bottom, *right, *left;
    int rows, columns;
    Item ***display;
    Player *player;
    Boundary *boundary;
    char floor;
};

#endif
