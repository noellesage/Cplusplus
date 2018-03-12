/********************************************************************* 
** Program name: Game.h 
** Author: Amy Sage
** Date: 1/23/18
** Description: Defines game class 
*********************************************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Die.h"
using std::string;

class Game
{
        protected:
                Die *player_1_die, *player_2_die;
                int num_sides_1, num_sides_2 = 0;
                int num_rounds = 0;
                int p1_score, p2_score = 0;
                string die_type_1, die_type_2;
        public:
                Game();
                void display_menu();
                void play_game();
                void display_results();

};
#endif
