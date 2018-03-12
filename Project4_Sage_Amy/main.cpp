/****************************************
** Program name: main.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Implements the game flow,
* and 2 menus
****************************************
***************************/
#include "Game.h"
#include "Barbarian.h"
#include "Character.h"
#include "Medusa.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"
#include "LoserList.h"
#include "LineupQueue.h"
#include <iostream>

char play_or_exit()
{
	//play or exit
	char choice;
	cout << "Please select from the following menu:" << endl;
	cout << "1) Play " << endl;
	cout << "2) Exit " << endl;
	cin >> choice;
	while((choice < '1' || choice > '2'))
	{
		cout << "Sorry, the input must be a 1 or 2. Try again: ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}
	return choice;
}

char playAgain_or_exit()
{
	//play or exit
	char choice;
	cout << "Please select from the following menu:" << endl;
	cout << "1) Play Again" << endl;
	cout << "2) Exit " << endl;
	cin >> choice;
	while((choice< '1' || choice > '2'))
	{
		cout << "Sorry, the input must be a 1 or 2. Try again: ";
		cin.ignore();
		cin.clear();
		cin >> choice;
	}
	return choice;
}

void game_creation()
{
	//game play
	Game* my_game = new Game;
	my_game->how_many_onteam();
	my_game->initialize_teams((my_game->get_lineup1()), "Team 1");
	my_game->initialize_teams((my_game->get_lineup2()), "Team 2");
	cout << "Team 1: " << endl;
	(my_game->get_lineup1())->print();
	cout << endl;
	cout << "Team 2: " << endl;
	(my_game->get_lineup2())->print();

	bool is_team1_empty = false;
	bool is_team2_empty = false;
	//loop until none left on one team
	while ((is_team1_empty == false) && (is_team2_empty == false))
	{
		my_game->game();
		is_team1_empty = (my_game->get_lineup1())->isEmpty();
		is_team2_empty = (my_game->get_lineup2())->isEmpty();
	}
	my_game->end();
	
	//deallocate
	delete my_game;
	my_game = NULL;
}

int main()
{
    int choice = play_or_exit();
	if(choice == '1')
	{
		game_creation();
	}//end choice 1
	if(choice == '2')
	{
		cout << "Goodbye" << endl;
		exit(1);
	}

	//play again or exit
	char choice2 = playAgain_or_exit();
	if(choice2 == '1')
	{
		game_creation();
	}
	if(choice2 == '2')
	{
		cout << "Goodbye" << endl;
		exit(1);
	}
	return 0;
}
