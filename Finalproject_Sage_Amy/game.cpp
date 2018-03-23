/****************************************
** Program name: game.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Game class
*****************************************/

#include "game.h"
#include "space.h"
#include "outerspace.h"
#include "starspace.h"
#include "blackhole.h"
#include "rocketship.h"
#include "planet.h"
#include "alienspace.h"
#include "player.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// Game constructs a new game world.
Game::Game() {
  cout << "Player" << endl;
  player = new Player();
  cout << "Outerspace" << endl;
  outerspace = new Outerspace(player);
  cout << "Starspace" << endl;
  starspace = new Starspace(player);
  cout << "Blackhole" << endl;
  blackhole = new Blackhole(player);
  cout << "Rocketship" << endl;
  rocketship = new Rocketship(player);
  cout << "Planet" << endl;
  planet = new Planet(player);
  cout << "Alienspace" << endl;
  alienspace = new Alienspace(player);
  cout << "Done constructing" << endl;

  // Construct the game map
  // outerspace <--> starspace
  outerspace->set_top(starspace);
  starspace->set_bottom(outerspace);

  // starspace <--> blackhole
  starspace->set_top(blackhole);
  blackhole->set_bottom(starspace);
  // blackhole <--> rocketship
  blackhole->set_top(rocketship);
  rocketship->set_bottom(blackhole);
  // outerspace <--> planet
  outerspace->set_right(planet);
  planet->set_left(outerspace);
  // planet <--> alienspace
  planet->set_bottom(alienspace);
  alienspace->set_top(planet);

  // Set intial player position
  current_space = outerspace;
  current_space->set_player_at_pos(5, 5);
  cout << "Done" << endl;
}

// ~Game deletes the player and spaces constituing the game world.
Game::~Game()
{
  delete player;
  delete planet;
  delete outerspace;
  delete starspace;
  delete blackhole;
  delete rocketship;
  delete alienspace;
}

// print_intro displays the intro message for the game.
void Game::print_intro()
{
  draw_blank_screen();
  cout << "^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
  cout << "**** -> COSMOS -- By Amy Sage <- ****\n";
  cout << "^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n\n";
  cout << "You are hurtling through outerspace!\n";
  cout << "In order for you to get home to your planet,\n";
  cout << "you must please the aliens from another planet.\n";
  cout << "Only they hold the secret for you to return home.\n";
  cout << "You must collect their secret and return it to them so they will\n";
  cout << "teleport you home.\n\n";
  cout << "Follow the instructions for each room for guidance.\n";
  cout << "You only have 300 fuel. Each action will take one fuel.\n";
  cout << "You can pick up fuel cans (#) that will replinish 100 fuel each.\n\n";
}

// Run initiates a new game and enters a game loop.
void Game::run()
{
  //Draw Intro.
  print_intro();
  cout << "Press any key to continue..." << endl;
  cin.sync();
  cin.ignore();
  cin.clear();
  cin.get();

  // Game loop.
  while(true) {

    // Draw a blank screen.
    draw_blank_screen();

    // Check if player has run out of fuel.
    if (player->get_fuel() <= 0)
    {
      cout << "*** GAME OVER ***" << endl << endl;
      cout << "You've run out of fuel! Game over." << endl << endl;
      cout << "Press any key to return to the main menu..." << endl;
      cin.sync();
      cin.ignore();
      cin.clear();
      cin.get();
      break;
    }

    // Check if the player won the game.
    if (player->check_for_item("Alien Thanks"))
    {
      cout << "*** YOU WIN ***" << endl << endl;
      cout << "You give the aliens their secrets and receive their thanks!" << endl;
      cout << "The aliens teleport you home. You win!" << endl << endl;
      cout << "Press any key to return to the main menu..." << endl;
      cin.sync();
      cin.ignore();
      cin.clear();
      cin.get();
      break;
    }

    // Update game.
    current_space->print_space();
    current_space->move_player();

    // Check for space transition.
    if (current_space->player_at_top())
    {
      current_space = current_space->get_top();
      current_space->set_player_at_bottom();
    }
    else if (current_space->player_at_bottom())
    {
      current_space = current_space->get_bottom();
      current_space->set_player_at_top();
    }
    else if (current_space->player_at_left())
    {
      current_space = current_space->get_left();
      current_space->set_player_at_right();
    }
    else if (current_space->player_at_right())
    {
      current_space = current_space->get_right();
      current_space->set_player_at_left();
    }

    // Decrement player's fuel.
    player->decrement_fuel();
  }
}

// draw_blank_screen clears the screen with newlines.
void Game::draw_blank_screen() {
  for (int i=0; i<1000; i++) {
    cout << endl;
  }
}

