/****************************************
** Program name: main_die.cpp 
** Author: Amy Sage
** Date: 1/23/18
** Description: implements war game using game class and die/loaded die classes 
****************************************
***************************/
#include <iostream>
#include "Game.h"
#include "Die.h"
#include "Loaded_die.h"

int main()
{
	Game newgame;
	newgame.display_menu();
	newgame.play_game();
	newgame.display_results();
return 0;
}

