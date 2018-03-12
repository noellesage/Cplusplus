/****************************************
** Program name: Game.cpp
** Author: Amy Sage
** Date: 3/5/2018
** Description: Describes Game class
****************************************
***************************/
#include "Game.h"
#include <string>
using std::endl;
using std::cin;
using std::string;
using std::cout;

Game::Game()
{
	my_loser_list = &losers;
	c = NULL;
	lineup1 = &queue_lineup1;
	lineup2 = &queue_lineup2;
}

LineupQueue* Game::get_lineup1()
{
	return lineup1;
}

LineupQueue* Game::get_lineup2()
{
	return lineup2;
}

LoserList* Game::get_losers()
{

	return my_loser_list;
}

void Game::how_many_onteam()
{

	int fighters;
	cout << "How many fighters would you like on each team?: ";
	cin >> fighters;
	while (fighters < 1 ) {
		cout << "Sorry, invalid entry. Each team must have at least one fighter. Enter another number: ";
		cin.clear();
		cin.ignore();
		cin >> fighters;
		cout << endl;
	}
	
	//set fighters
	num_fighters = fighters;
}

void Game::initialize_teams(LineupQueue* team, string team_name) {

	string name;
	char type;
	cout << "Fighters for " << team_name << ": " << endl;

	for (int i = 0; i < num_fighters; i++)
	{
	
		Character* c = NULL;
		cout << "What would you like to name fighter #" << i + 1 << "?: ";
		cin >> name;
		type = menu();//call menu
		if (type == '1')
		{
			c = new Vampire(name, team_name);
			team->addNode(c);
		}
		else if (type == '2')
		{
			c = new BlueMen(name, team_name);
			team->addNode(c);
		}
		else if (type == '3')
		{
			c = new Medusa(name, team_name);
			team->addNode(c);
		}
		else if (type == '4')
		{
			c = new Barbarian(name, team_name);
			team->addNode(c);
		}
		else if (type == '5')
		{
			c = new HarryPotter(name, team_name);
			team->addNode(c);
		}
	}
}

char Game::menu() 
{
	char menu_choice;
	cout << "Choose fighter:" << endl;
	cout << "1) Vampire" << endl;
	cout << "2) Blue Men" << endl;
	cout << "3) Medusa" << endl;
	cout << "4) Barbarian" << endl;
	cout << "5) Harry Potter" << endl;
	cin >> menu_choice;
	
	while ((menu_choice < '1') || (menu_choice > '5') || cin.fail()) {

		cout << "Invalid entry. Enter a number 1-5: ";
		cin.clear();
		cin.ignore();
		cin >> menu_choice;
	}

	return menu_choice;
}

int Game::attack(Character *c)
	{
	    int attack = c->attack();
	    cout << "Character: " << c->get_type() << endl;
	    cout << "Name: " << c->get_name() << endl;
	    cout << "Strength: " << c->get_strength() << endl;
	    cout << "Armor: " << c->get_armor() << endl;
	    cout << "Attack: " << attack << endl;
	    cout << endl;
	    return attack;
	}

void Game::defense(Character *c, int attack)
	{
	    int d = c->defense(attack);
	    cout << "Character: " << c->get_type() << endl;
	    cout << "Name: " << c->get_name() << endl;
	    cout << "Strength: " << c->get_strength() << endl;
	    cout << "Armor: " << c->get_armor() << endl;
	    cout << "Defense: " << d << endl;
	    cout << endl;
	}
	
void Game::game() 
{
	int start = (rand() % 2) + 1;
	Character * fighter_1;
	Character * fighter_2;
    int flag = 0; //flag for which team

	//alternate who starts
	if (start == 1) 
	{
		fighter_1 = lineup1->deleteNode();
		fighter_2 = lineup2->deleteNode();
		flag = 1;
	}

	else 
	{
		fighter_1 = lineup2->deleteNode();
		fighter_2 = lineup1->deleteNode();
		flag = 2;
	}

	cout << fighter_1->get_name() << " " << fighter_1->get_type() << " vs. ";
	cout << fighter_2->get_name() << " " << fighter_2->get_type() << endl;

	int r = 0;

	//Both alive
	while((fighter_1->get_strength() > 0) && (fighter_2->get_strength() > 0))
	{
		r++;
		cout << "****ROUND " << r << "****" << endl;
		cout << endl;
		
		  //c1 attacks, c2 defends
            defense(fighter_2, attack(fighter_1));

	//if fighter 2 dies game is over
		if (fighter_2->get_strength() > 0)
		{
			//c2 attacks, c1 defends
			defense(fighter_1, attack(fighter_2));
		}
	}
	
	//if second fighter wins
	if (fighter_1->get_strength() <= 0)
	{
		cout << fighter_1->get_name() << " " << fighter_1->get_type() << " is the loser and ";
		cout << fighter_2->get_name() << " " <<fighter_2->get_type() << " is the winner in ";
		cout << r << " rounds." << endl;
		cout << endl;
        if(flag == 1)
        {
        	team_2_score++;
        }
        if(flag == 2)
        {
        	team_1_score++;
        }
        cout << "Team 1 score: " << team_1_score << endl;
        cout << "Team 2 score: " << team_2_score << endl;
        cout << endl;
		if (start == 1) 
		{
			my_loser_list->add_loser(fighter_1);
			cout << fighter_2->get_name() << " " << fighter_2->get_type();
			cout << " restores " << fighter_2->recover();
			cout << " damage before returning to the lineup." << endl;
			cout << endl;
			lineup2->addNode(fighter_2);
		}
		else 
		{
			my_loser_list->add_loser(fighter_1);
			cout << fighter_2->get_name() << " " << fighter_2->get_type();
			cout << " restores " << fighter_2->recover();
			cout << " damage before returning to the lineup." << endl;
			cout << endl;
			lineup1->addNode(fighter_2);
		}
	}

	//first fighter wins
	if (fighter_2->get_strength() <= 0) 
	{
		cout << fighter_2->get_name() << " " << fighter_2->get_type() << " is the loser and ";
		cout << fighter_1->get_name() << " " << fighter_1->get_type() << " is the winner in ";
		cout << r << " rounds." << endl;
		cout << endl;
		if(flag == 1)
        {
        	team_1_score++;
        }
        if(flag == 2)
        {
        	team_2_score++;
        }
        cout << "Team 1 score: " << team_1_score << endl;
        cout << "Team 2 score: " << team_2_score << endl;
        cout << endl;
		if (start == 1) 
		{
			cout << fighter_1->get_name() << " " << fighter_1->get_type();
			cout << " restores " << fighter_1->recover();
			cout << " damage before returning to the lineup." << endl;

			my_loser_list->add_loser(fighter_2);
			lineup1->addNode(fighter_1);
		}
		else 
		{
			cout << fighter_1->get_name() << " " << fighter_1->get_type();
			cout << " restores " << fighter_1->recover();
			cout << " damage before returning to the lineup." << endl;

			my_loser_list->add_loser(fighter_2);
			lineup2->addNode(fighter_1);
		}
	}
	//reset flag
	flag = 0;
}

void Game::end() 
{
	cout << "Fighters left in Team 1:  " << endl;
	lineup1->print();
	cout << endl;
	
	cout << "Fighters left in Team 2: " << endl;
	lineup2->print();
	cout << endl;

	cout << "The team who won is ";
	if (lineup1->isEmpty() == true)
	{
		cout << "team 2";
	}
	else if(lineup1->isEmpty() == true && lineup2->isEmpty() == true)
	{
		cout << "it was a tie";
	}
	else 
	{
		cout << "team 1";
	}
	cout << endl;
	
	cout << "The winning members are the fighters left on ";
	if (lineup1->isEmpty() == true) 
	{
		cout << "team 2: ";
		lineup2->print();
	}
	else if (lineup1->isEmpty() == true && lineup2->isEmpty() == true)
	{
		cout << "Neither team has survivors";
	}
	else 
	{
		cout << "team 1: ";
		lineup1->print();
	}
    cout << endl;
    
    cout << "Would you like to display the losers? Enter 1 for yes or 2 for no: ";
    int see_losers = 0;
    cin >> see_losers;
    cout << endl;
    while(cin.fail() && see_losers < 1 && see_losers > 2)
    {
    	cout << "Sorry, that's invalid. Enter a 1 or 2: ";
    	cin.ignore();
    	cin.clear();
    	cin >> see_losers;
    }
    if(see_losers == 1)
    {
    	cout << "The losers from last defeated to first defeated are: " << endl;
    	if(my_loser_list->isEmpty() == true)
    	{
    		cout << "No losers in the list" << endl;
    	}
    	while(my_loser_list->isEmpty() == false)
    	{
			my_loser_list->delete_loser(); //lasted longest
			cout << endl;
    	}
    }	
    else if(see_losers == 2)
    {
    	return;
    }
}

Game::~Game()
{
	c = NULL;
}
