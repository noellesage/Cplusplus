/****************************************
** Program name: game.h
** Author: Amy Sage
** Date: 3/7/2018
** Description: Defines the Game class
*****************************************/

#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "player.h"

class Game
{
  public:
    Game();
    ~Game();
    void run();
   private:
    Space *current_space;
    Player *player;
    Space *outerspace;
    Space *starspace;
    Space *blackhole;
    Space *rocketship;
    Space *planet;
    Space *alienspace;
    void print_intro();
    void draw_blank_screen();
};

#endif
