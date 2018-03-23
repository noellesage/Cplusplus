/****************************************
** Program name: main.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the main class
*****************************************/

#include "game.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void clear_screen()
{
  for (int i = 0; i < 1000; i++)
    cout << endl;
}

int main()
{
  while(true)
  {
    clear_screen();
    cout << "^*^*^*^*^*^*^*^*^*^" << endl;
    cout << " WELCOME TO COSMOS " << endl;
    cout << "^*^*^*^*^*^*^*^*^*^" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Credits" << endl;
    cout << "^*^*^*^*^*^*^*^*^*^" << endl;
    cout << endl << "Enter a number between 1-3: ";
    int input = 0;
    cin >> input;
    while(input < 1 || input > 3 || cin.fail())
    {
      cout << endl << "Enter a number between 1-3: ";
      cin.clear();
      cin.ignore();
      cin >> input;
    }
    switch(input)
    {
      case 1:
        {
          Game *cosmos = new Game();
          cosmos->run();
          delete cosmos;
        }
        break;
      case 2:
        {
          clear_screen();
          cout << "<<<<<<<<<<<<<<<<<<<" << endl;
          cout << "COSMOS INSTRUCTIONS" << endl;
          cout << ">>>>>>>>>>>>>>>>>>>" << endl;
          cout << endl << "This is a text based game, anything in parentheses is a symbol you will see in the game." << endl;
          cout << "You are an astronaut (&) in space, trying to get home." << endl;
          cout << "Nearby aliens have teleportation technology, but you must find the alien secrets (?) to trade with them." << endl;
          cout << "Read the instructions for each part of space carefully." << endl;
          cout << "You only have a limited amount of fuel. If you run out, it's game over." << endl;
          cout << "You can find fuel cans (#) that restore some fuel." << endl;
          cout << "To win the game, you must reach the aliens and get their thanks (<), which will teleport you home." << endl;
          cout << endl << "Good luck!" << endl;
          cout << endl;
          cout << "Press any key to continue..." << endl;
	  cin.sync();
          cin.clear();  
          cin.ignore();
          cin.get();
        }
        break;
       case 3:
        {
          clear_screen();
          cout << "$$$$$$$$$" << endl;
          cout << " CREDITS " << endl;
          cout << "$$$$$$$$$" << endl << endl;
          cout << "Story: Amy Sage\nDesign: Amy Sage\nCoding: Amy Sage\nSpecial thanks: Amy Sage" << endl;
          cout << endl;
          cout << "Press any key to continue..." << endl;
          cin.sync();
          cin.clear();
          cin.ignore();
          cin.get();
        }
        break;
    }
  }
  return 0;
}


