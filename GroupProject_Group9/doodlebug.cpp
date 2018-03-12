#include "doodlebug.hpp"
#include "critter.hpp"

#include <time.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

Doodlebug::Doodlebug()
{
    id = 'X'; 
	lastFed = 0; //hold a seperate counter for how long its been since the doodle bug successfully ate an ant. 
}

int Doodlebug::getLastFed() {
	return lastFed; 
}

void Doodlebug::move(Critter*** c, int row, int col, int rows, int columns)
{
	bool ateAnt = false;

	while (moveHistory == false) { //move history will be true if the ant has already moved this turn
		if (row != rows-1 && col != 0 && c[row + 1][col - 1] != nullptr) {  
			//check to see if the space is empty and not past an edge.
			if (c[row + 1][col - 1]->getID() == 'O') { //if its not empty and contains an ant
				delete c[row + 1][col - 1]; //delete the ant
				c[row + 1][col - 1] = c[row][col]; //move the doodlebug into that position
				c[row][col] = nullptr; //clear the space the doodlebug was in previously
				ateAnt = true;
				lastFed = 0; //reset the counter for when the doodlebug last ate
				moveHistory = true; //indicate the doodlebug has moved this turn
			}
		}
		
		//check to see if the space is empty, the doodlebug has not eaten already, and the space is not past an edge
		//(for other notes see above) 
		if (row != rows-1 && col != columns-1 && !ateAnt && c[row + 1][col + 1] != nullptr) { 
			if (c[row + 1][col + 1]->getID() == 'O') {
				delete c[row + 1][col + 1];
				c[row + 1][col + 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
				lastFed = 0;
				moveHistory = true; 
			}
		}
		
		//check to see if the space is empty, the doodlebug has not eaten already, and the space is not past an edge
		//(for other notes see above)
		if (row != 0 && col != columns - 1 && !ateAnt && c[row - 1][col + 1] != nullptr) {
			if (c[row - 1][col + 1]->getID() == 'O') {
				delete c[row - 1][col + 1];
				c[row - 1][col + 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
				lastFed = 0;
				moveHistory = true; 
			}
		}
		
		//check to see if the space is empty, the doodlebug has not eaten already, and the space is not past an edge
		//(for other notes see above)
		if (row != 0 && col != 0 && !ateAnt && c[row - 1][col - 1] != nullptr) {
			if (c[row - 1][col - 1]->getID() == 'O') {
				delete c[row - 1][col - 1];
				c[row - 1][col - 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
				lastFed = 0;
				moveHistory = true; 
			}
		}

		if (!ateAnt) {

			int starter = rand() % 4 + 1;
			int counter = 0;

			while (moveHistory == false)
			{
				//move up
				if (starter == 1)
				{
					if (counter == 4){ //check to see if all 4 directions have been tired already 
						moveHistory = true;
					}
					else if (row == 0) //check for edge cases
					{
						starter = 2;
					}
					else if (c[row - 1][col] == nullptr) //check if the space above is empty
					{
						c[row - 1][col] = c[row][col]; //move the doodlebug to the space
						c[row][col] = nullptr; //clear the space the doodlebug was in previously
						moveHistory = true; //indicate the doodlebug has moved this turn
						lastFed += 1; // move the counter to indicate that the doodlebug did not eat this turn
					}
					else
					{
						//if the doodlebug can't move to that space try the next direction
						starter = 2;
						counter += 1; 
					}
				}
				//move down (for notes see move up)
				if (starter == 2)
				{
					if (counter == 4) {
						moveHistory = true;
					}
					else if (row == rows-1)
					{
						starter = 3;
					}
					else if (c[row + 1][col] == nullptr)
					{
						c[row + 1][col] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
						lastFed += 1;
					}
					else
					{
						starter = 3;
						counter += 1;
					}
				}
				//move left (for notes see move up)
				if (starter == 3)
				{
					if (counter == 4) {
						moveHistory = true;
					}
					else if (col == 0)
					{
						starter = 4;
					}
					else if (c[row][col - 1] == nullptr)
					{
						c[row][col - 1] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
						lastFed += 1;
					}
					else
					{
						starter = 4;
						counter += 1;
					}
				}
				//move right (for notes see move up) 
				if (starter == 4)
				{
					if (counter == 4) {
						moveHistory = true;
					}
					else if (col == columns - 1)
					{
						starter = 1;
					}
					else if (c[row][col + 1] == nullptr)
					{
						c[row][col + 1] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
						lastFed += 1;
					}
					else
					{
						starter = 1;
						counter += 1;
					}
				}
			}


		}
	}

}

void Doodlebug::breed(Critter*** c, int row, int col, int rows, int columns)
{
	int counter = 0;//counter tracks how many directions have been tried. if it reaches 4 the ant cannot move any direction. 
	int starter = rand() % 4 + 1; //represents a random direction in the loop below

	//check if the doodlebugs age is both greater than 8, and a multiple of 8
	if (c[row][col]->getAge() >= 8 && c[row][col]->getAge() % 8 == 0)
	{
		while (counter < 4) //while all 4 directions have not been tried
		{
			//breed in the space above
			if (starter == 1)
			{
				if (row == 0) //check for edge cases
				{
					counter += 1;
					starter = 2;
				}
				else if (c[row - 1][col] == nullptr) //check to see if the space is empty
				{
					c[row - 1][col] = new Doodlebug(); //create a new doodlebug in the space
					c[row - 1][col]->setMoveHistory(true); //set the news doodlebugs move history to true so that it doenst move this turn
					break;
				}
				else
				{
					//if the doodlebug can't breed to that space try the next direction
					counter += 1;
					starter = 2;
				}
			}
			
			//breed in the space below (for notes see breed above) 
			if (starter == 2)
			{
				if (row == rows-1)
				{
					counter += 1;
					starter = 3;
				}
				else if (c[row + 1][col] == nullptr)
				{

					c[row + 1][col] = new Doodlebug();
					c[row + 1][col]->setMoveHistory(true);
					break;
				}
				else
				{
					counter += 1;
					starter = 3;
				}
			}
			
			//breed in the space to the right (for notes see breed above) 
			if (starter == 3)
			{
				if (col == 0)
				{
					counter += 1;
					starter = 4;
				}
				else if (c[row][col - 1] == nullptr)
				{
					c[row][col - 1] = new Doodlebug();
					c[row][col - 1]->setMoveHistory(true);
					break;
				}
				else
				{
					counter += 1;
					starter = 4;
				}
			}
			
			//breed in the space to the left (for notes see breed above) 
			if (starter == 4)
			{
				if (col == columns-1)
				{
					counter += 1;
					starter = 1;
				}
				else if (c[row][col + 1] == nullptr)
				{
					c[row][col + 1] = new Doodlebug();
					c[row][col + 1]->setMoveHistory(true);
					break;

				}
				else
				{
					counter += 1;
					starter = 1;
				}
			}
		}
	}
}

void Doodlebug::starve(Critter*** c, int row, int col)
{
	delete c[row][col]; //delete the doodlebug
	c[row][col] = nullptr; //set the space the doodlebug was in to a null pointer 
}
