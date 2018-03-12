#include <iostream>

#include "intVal.hpp" 
#include "Menu.hpp"
#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include <time.h>
#include <string> 

using namespace std;

int main()
{
	bool status = true; 
	srand(time(NULL)); //seed random numbers
	string menuOptions[2] = { "Continue running the simulation", "Exit" }; 
	int menuSelect; 
	int steps; 

	cout << "We did the extra credit!!!!!" << endl << endl;
  
	//prompt user for Board size
	cout << "Please enter number of rows in the grid: ";
	int rows = intVal('y', 999, 'y', 1);
	cout << "Please enter number of columns in the grid: ";
	int columns = intVal('y', 999, 'y', 1);
	Board b1(rows, columns);
	//print board
	b1.printBoard();
	Critter*** g1 = b1.getGrid();

	//pompt user for number of ants
	cout << "Please enter the starting number of Ants: ";
	int numAnts = intVal('y', rows * columns * 2 / 3, 'y', 1);
	for (int i = 0; i < numAnts; i++) {
		Critter* c1 = new Ant();
		int r, c;
		do {
			r = rand() % b1.getRows();
			c = rand() % b1.getColumns();
		} while (g1[r][c] != NULL);
			g1[r][c] = c1;
	}
	
	//prompt user for number of doodle bugs
	cout << "Please enter the starting number of doodlebugs: ";
	int numDoodle = intVal('y', rows * columns / 3, 'y', 1);
	for (int i = 0; i < numDoodle; i++) {
		Critter* c1 = new Doodlebug();
		int r, c;
		do {
			r = rand() % b1.getRows();
			c = rand() % b1.getColumns();
		} while (g1[r][c] != NULL);
			g1[r][c] = c1;
	}

	do {

		//prompt user for number steps
		cout << "Please enter the number of steps in the simuation: ";
		steps = intVal('y', 999999, 'y', 1);

		for (int i = 0; i < steps; i++)
		{
			//call the function needed for a turn in the game
			b1.advanceAge();
			b1.checkDoodleMove();
			b1.checkAntMove();
			b1.checkDoodleStarve();
			b1.checkDoodleBreed(); 
			b1.checkAntBreed();
			b1.printBoard();
		}

		//prompt user with menu to continue simulation or quit. 
		cout << "Would you like to:" << endl;
		menuSelect = menu(menuOptions, 2); 

		if (menuSelect == 2)
			status = false; 

	} while (status); 

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (g1[i][j] != nullptr)
				delete g1[i][j]; 
		}
	}

    return 0;
}

