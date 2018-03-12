/****************************************
** Program name: Game.h
** Author: Amy Sage
** Date: 3/5/2018
** Description: Defines Game class
****************************************
***************************/

#include "Barbarian.h"
#include "Character.h"
#include "Medusa.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "HarryPotter.h"
#include "LoserList.h"
#include "LineupQueue.h"

class Game
{
private:
	int num_fighters;
	Character* c;
	LoserList losers;
	LineupQueue queue_lineup1;
	LineupQueue queue_lineup2;
	LineupQueue* lineup1;
	LineupQueue* lineup2;
	LoserList* my_loser_list;
    int team_1_score;
    int team_2_score;

public:
	Game();
	~Game();
	LineupQueue* get_lineup1();
	LineupQueue* get_lineup2();
	LoserList* get_losers();
	void how_many_onteam();
	void defense(Character*, int);
	int attack(Character*);
	void initialize_teams(LineupQueue*, string);
	char menu();
	void game();
	void end();
};
