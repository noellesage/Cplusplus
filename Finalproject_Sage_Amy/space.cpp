/****************************************
** Program name: space.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description: Implements the Space class
*****************************************/

#include "space.h"
#include "boundary.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// Space constructs a new display for play.
Space::Space(Player *p)
{
  boundary = new Boundary();
  player = p;

  // Set adjacent space pointers to NULL.
  top = NULL;
  bottom = NULL;
  right = NULL;
  left = NULL;

  // Set dimensions of display.
  this->columns = 31;
  this->rows = 21;

  // Set a background character for the display.
  floor = ' ';

  // Create an empty display.
	display = new Item**[rows];
	for (int i = 0; i < rows; i++)
		display[i] = new Item*[columns];

	// Set all positions in the display to NULL.
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			display[i][j] = NULL;

	// Set boundries for the display.
	for (int i = 0; i < rows; i++)
	{
		display[i][0] = boundary;
		display[i][columns - 1] = boundary;
	}
	for (int j = 1; j < columns-1; j++)
	{
		display[0][j] = boundary;
		display[rows - 1][j] = boundary;
	}
}

// ~Space deletes all items used in the display.
Space::~Space()
{
  delete boundary;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (display[i][j] != NULL)
      {
        display[i][j] = NULL;
      } 
    }
    delete[] display[i];
  }
  delete[] display;
  display = NULL;
}

// print_space prints the display to the screen.
// It also prints the prompt for the space, and player status.
void Space::print_space()
{
  // Print the prompt for the space.
  print_prompt();

  // Print player status.
  this->player->print_inventory();
  this->player->print_fuel();

  // Print  the display.
  for (int i = 0; i < rows; i++)
  {
    for (int k = 0; k < columns; k++)
    {
      if (display[i][k] == NULL)
        cout << floor;
      else
        cout << display[i][k]->get_appearance();
    }
    cout << endl;
  }
}

// move_player prompts the user to perform an action.
void Space::move_player()
{
  // Print prompt.
  cout << "**** ACTIONS ****\n";
  cout << "1 = LEFT\n";
  cout << "2 = DOWN\n";
  cout << "3 = UP\n";
  cout << "4 = RIGHT\n";
  cout << "5 = INTERACT\n";

  // Get input from the user.
  int input = 0;
  cout << "Please enter an integer between 1-5: ";
  cin >> input;
  while(input < 1 || input > 5 || cin.fail())
  {
    cout << "Please enter an integer between 1-5: ";
    cin.clear();
    cin.ignore();
    cin >> input;
  }

  // Select the appropriate action.
  switch(input)
  {
    case 1: // Move left.
     move_player_pos(0, -1);
     break;
    case 2: // Move down.
     move_player_pos(1, 0);
      break;
    case 3: // Move up.
      move_player_pos(-1, 0);
      break;
    case 4: // Move right.
      move_player_pos(0, 1);
      break;
    case 5: // Pick up item.
      pick_up_item(1, 0);
      pick_up_item(-1, 0);
      pick_up_item(0, 1);
      pick_up_item(0, -1);
      break;
  }
}

// move_player_pos moves the player character by the given offsets.
void Space::move_player_pos(int x_off, int y_off)
{
  int x = player->get_x();
  int y = player->get_y();
  if (((0 < x+x_off) < rows) && ((0 < y+y_off) < columns))
  {
    if (display[x+x_off][y+y_off] == NULL)
    {
      display[x+x_off][y+y_off] = player;
      display[x][y] = NULL;
      player->set_x(x+x_off);
      player->set_y(y+y_off);
    }
  }
}

// pick_up_item picks up an obtainable item.
void Space::pick_up_item(int x_off, int y_off)
{
  int px, py;
  px = player->get_x() + x_off;
  py = player->get_y() + y_off;
  Item *item = display[px][py];
  if (item != NULL && item->is_obtainable())
  {
    if (item->get_name() == "Fuel Can") {
      player->increment_fuel();
    }
    else
    {
      player->add_item(item->get_name());
    }
    display[px][py] = NULL;
    update_space();
  }
}

// set_player_at_pos teleports the player to a position on the map.
void Space::set_player_at_pos(int x, int y) {
  display[x][y] = player;
  player->set_x(x);
  player->set_y(y);
}

void Space::update_space(){}

void Space::set_player_at_top(){}
void Space::set_player_at_bottom(){}
void Space::set_player_at_left(){}
void Space::set_player_at_right(){}

void Space::set_top(Space* t) { this->top = t; }
Space *Space::get_top() { return this->top; }

void Space::set_bottom(Space* t) { this->bottom = t; }
Space *Space::get_bottom() { return this->bottom; }

void Space::set_left(Space* t) { this->left = t; }
Space *Space::get_left() { return this->left; }

void Space::set_right(Space* t) { this->right = t; }
Space *Space::get_right() { return this->right; }

bool Space::player_at_top() { return false; }
bool Space::player_at_bottom() { return false; }
bool Space::player_at_left() { return false; }
bool Space::player_at_right() { return false; }
