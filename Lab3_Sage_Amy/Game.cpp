/********************************************************************* 
** Program name: Game.cpp 
** Author: Amy Sage
** Date: 1/23/18
** Description: Defines game class 
*********************************************************************/
#include <iostream>
#include "Game.h"
#include "Die.h" 
#include "Loaded_die.h"
using std::cout;
using std::cin;
using std::endl;

Game::Game()
{
	player_1_die = player_2_die = NULL;
}
void Game::display_menu()
{
	int choice = 0; //play or exit
	bool valid_menu = false;
	bool valid_num_sides_1 = false;
	bool valid_num_sides_2 = false;
	bool valid_num_rounds = false;
	bool valid_die_type_1 = false; 
	bool valid_die_type_2 = false;
	cout << "Menu" << endl;
	cout << "1) Start" << endl;
	cout << "2) Exit" << endl;	
	do
	{
		cin >> choice;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid. Enter a 1 or 2" << endl;
		}
		else
		{
			valid_menu = true;
		}	
	} while(valid_menu == false);
	 switch(choice)
         { 
               case 1:
                        break;
               case 2:
                        cout << "Goodbye" << endl;
                        exit(1);
         }	
	do
        {
		cout <<  "How many rounds would you like to play?" << endl;
                cin >> num_rounds;

                if(cin.fail())
                {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid. Enter an integer. " << endl;
                }
                else
                {
                        valid_num_rounds = true;
                }
        } while(valid_num_rounds == false);
	
	//player 1
	do
        {
		cout << "Please enter Player 1 details" << endl;
		cout << "How many sides?" << endl;
                cin >> num_sides_1;

                if(cin.fail())
                {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid. Enter an integer." << endl;
                }
                else
                {
                        valid_num_sides_1 = true;
                }
        } while(valid_num_sides_1 == false);
	do
        {
		cout << "Type loaded for a loaded die or type die for a regular die" << endl;

                cin >> die_type_1;

                if(cin.fail())
                {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid. Enter loaded or die." << endl;
                }
                else
                {
                        valid_die_type_1 = true;
                }
        } while(valid_die_type_1 == false);
	if(die_type_1 == "loaded")
	{
		player_1_die = new Loaded_die(num_sides_1);
	}
	else if(die_type_1 == "die")
	{
		player_1_die = new Die(num_sides_1);
	} 
	
	//Player 2 details
        do
        {
		cout << "Please enter Player 2 details" << endl;
		cout << "How many sides?" << endl;
                cin >> num_sides_2;

                if(cin.fail())
                {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid. Enter an integer." << endl;
                }
                else
                {
                        valid_num_sides_2 = true;
                }
        } while(valid_num_sides_2 == false);  
          do
        {
		 cout << "Type loaded for a loaded die or type die for a regular die" << endl;
                cin >> die_type_2;

                if(cin.fail())
                {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid. Enter loaded or die." << endl;
                }
                else
                {
                        valid_die_type_2 = true;
                }
        } while(valid_die_type_2 == false); 
	if(die_type_2 == "loaded")                 
        {                                     
                player_2_die = new Loaded_die(num_sides_2);      
        }                                     
        else if(die_type_2 == "die")   
        {                                     
                player_2_die = new Die(num_sides_2);   
        }                                     
}

void Game::play_game()
{
	int p1_roll, p2_roll = 0;
	for(int i=0; i<num_rounds; i++)
	{
		p1_roll = player_1_die->get_roll_die();
		p2_roll = player_2_die->get_roll_die();
		num_sides_1 = player_1_die->get_num_sides();
		num_sides_2 = player_2_die->get_num_sides();		
        	cout << "Round " << i+1 << " Result:" << endl;
        	cout << "Player 1:" << endl;
        	cout << "Die type: "<< die_type_1 << endl;
        	cout << "Number of sides: " << num_sides_1 << endl;
        	cout << "Number rolled: " << p1_roll << endl;
        	cout << "Player 2:" << endl;
        	cout << "Die type: "<< die_type_2 << endl;
        	cout << "Number of sides: " << num_sides_2 << endl;
        	cout << "Number rolled: " << p2_roll << endl;
        	//calculate winner
        	if(p1_roll > p2_roll)
        	{
                	p1_score++;
                	cout << "Player 1 won this round. " << endl;
		}
		else if(p2_roll > p1_roll)
        	{
                	p2_score++;
                	cout << "Player 2 won this round. " << endl;
		}
        	else if(p1_roll == p2_roll)
        	{
                	cout << "There was a tie. No points awarded." << endl;
       		}
		cout << "Player 1 score: " << p1_score << endl;
		cout << "Player 2 score: " << p2_score << endl; 
	}
}	 

void Game::display_results()
{
	cout << "The final score is: " << endl;
	cout << "Player 1: " << p1_score << endl;
	cout << "Player 2: " << p2_score << endl;
	if(p1_score > p2_score)
	{	
        	cout << "Player 1 won the game." << endl;
	}
	else
	{
        	cout << "Player 2 won the game." << endl;
	}
}
	
	
	
