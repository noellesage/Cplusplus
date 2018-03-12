#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

#include <iostream>

using namespace std;

Board::Board()
{
    //default contructor makes a 20x20 grid
	grid = new Critter**[20];
    for(int i = 0; i < 20; i++)
    {
        grid[i] = new Critter*[20];
    }

    //set all elements to null pointers. 
	for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            grid[i][j] = nullptr;
        }
    }
	
	rows = 20; 
	columns = 20;  
}

Board::Board(int r, int c)
{
	//contructor that creates a user defined size of grid
	rows = r; 
	columns = c; 
	//create a grid of pointers with the rows and columns entered in the parameters
	grid = new Critter**[r];
	for (int i = 0; i < r; i++)
	{
		grid[i] = new Critter*[c];
	}

	//set all elements to null pointers
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			grid[i][j] = nullptr; 
		}
	}

}


Board::~Board()
{
    //destructor for the board
	for(int i = 0; i < rows; i++)
    {
        delete [] grid[i];
    }

    delete [] grid;
}

int Board::getColumns() {
	return columns; 
}

int Board::getRows() {
	return rows; 
}

void Board::printBoard()
{
    //print out a character for each element in the grid
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
			//for empty spaces print out a space
			if(grid[i][j] == nullptr)
            {
                cout << '.';
            }
			//if the element is a pointer to an ant, print O
            else if(grid[i][j]->getID() == 'O')
            {
                cout << 'O';
            }
			//if the element is a pointer to a doodlebug print and X. 
			else if (grid[i][j]->getID() == 'X')
			{
				cout << 'X';
			}
        }
		cout << endl;
    }
    cout << endl;

}

Critter*** Board::getGrid()
{
    return grid;
}

void Board::checkAntMove()
{
    //for all the elements in the grid, check their id
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            //for empty spaces do nothing
			if(grid[i][j] == nullptr) 
            {

            }
			//for ant pointers, call their move function
            else if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->move(getGrid(), i, j, rows, columns);
            }
        }
    }
}

void Board::checkDoodleMove()
{
	//for all the elements in the grid, check their id
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//for empty spaces do nothing
			if (grid[i][j] == nullptr)
			{

			}
			//for doodlebug pointers, call their move function
			else if (grid[i][j]->getID() == 'X')
			{
				grid[i][j]->move(getGrid(), i, j, rows, columns);
			}
		}
	}
}

void Board::advanceAge()
{
	//for all the elements in the grid, call the age function if there is a critter there
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            //for empty spaces do nothing
			if(grid[i][j] == nullptr)
            {

            }
            //call the age function for any critters
			else
            {
                grid[i][j]->setAge();
                grid[i][j]->setMoveHistory(false);
            }
        }
    }
}

void Board::checkAntBreed()
{
    //for all of the elements in the grid, check their id. 
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            //for empty spaces do nothing
			if(grid[i][j] == nullptr)
            {

            }
			//for ants call their breed function
            else if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->breed(getGrid(), i, j, rows, columns);
            }
        }
    }
}

void Board::checkDoodleStarve()
{
	//for all elements in the grid, check their id
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//for empty spaces do nothing
			if (grid[i][j] == nullptr)
			{

			}
			//for doodlebugs call their starve function
			else if (grid[i][j]->getLastFed() == 3)
			{
				grid[i][j]->starve(getGrid(), i, j);
			}
		}
	}
}

void Board::checkDoodleBreed()
{
	//for all of the elements in the grid, check their id. 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//for empty spaces do nothing
			if (grid[i][j] == nullptr)
			{

			}
			//for doodlebugs call their breed function
			else if (grid[i][j]->getID() == 'X')
			{
				grid[i][j]->breed(getGrid(), i, j, rows, columns);
			}
		}
	}
}
