#include "ant.hpp"
#include "critter.hpp"

#include <time.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

Ant::Ant()
{
	id = 'O';
}

Ant::~Ant()
{

}

void Ant::move(Critter*** c, int row, int col,int rows, int columns)
{
    int counter = 0; //counter tracks how many directions have been tried. if it reaches 4 the ant cannot move any direction. 
    int starter = rand() % 4 + 1;  //represents a random direction in the loop below

    while(moveHistory == false) //move history will be true if the ant has already moved this turn
    {
        //move up
		if(starter == 1) 
        {
			if (counter == 4) //check to see if all 4 directions have been tired already 
				moveHistory = true;

			else if(row == 0) //check for edge cases
            {
                counter += 1;
                starter = 2;
            }
            else if(c[row-1][col] == nullptr) //check if the space above is empty
            {
                c[row-1][col] = c[row][col]; //move the ant to the space
                c[row][col] = nullptr; //clear the space the ant was in previously
                moveHistory = true; // indicate the ant has moved this turn
            }
            else
            {
				//if the ant can't move to that space try the next direction
                counter += 1;
                starter = 2;
            }
        }
        //move down (for notes see move up)
		if(starter == 2)
        {
			if (counter == 4)
				moveHistory = true;

			else if(row == rows-1)
            {
                counter +=1;
                starter = 3;
            }
            else if(c[row+1][col] == nullptr)
            {
                c[row+1][col] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter +=1;
                starter = 3;
            }
        }
		//move left (for notes see move up)
        if(starter == 3)
        {
			if (counter == 4)
				moveHistory = true; 		
			
			else if(col == 0)
            {
                counter +=1;
                starter = 4;
            }
            else if(c[row][col-1] == nullptr)
            {
                c[row][col-1] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter +=1;
                starter = 4;
            }
        }
		//move right (for notes see move up) 
        if(starter == 4)
        {
			if (counter == 4)
				moveHistory = true;

			else if(col == columns-1)
            {
                counter +=1;
                starter = 1;
            }
            else if(c[row][col+1] == nullptr)
            {
                c[row][col+1] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter +=1;
                starter = 1;
            }
        }
    }
}


void Ant::breed(Critter*** c, int row, int col,int rows, int columns)
{
    int counter = 0; //counter tracks how many directions have been tried. if it reaches 4 the ant cannot move any direction. 
    int starter = rand() % 4 + 1; //represents a random direction in the loop below
   
	//check if the ants age is both greater than 3, and a multiple of 3
	if(c[row][col]->getAge() >= 3 && c[row][col]->getAge() % 3 == 0)
    {
        while(counter < 4) //while all 4 directions have not been tried
        {
            //breed in the space above
			if(starter == 1)
            {
                if(row == 0) //check for edge cases
                {
                    counter += 1;
                    starter = 2;
                }
                else if(c[row-1][col] == nullptr) //check to see if the space is empty
                {
                    c[row-1][col] = new Ant(); //create a new ant in the space
                    c[row-1][col]->setMoveHistory(true); //set the news ants move history to true so that it doenst move this turn
                    break;
                }
                else
                {
					//if the ant can't breed to that space try the next direction
					counter += 1;
                    starter = 2;
                }
            }
            
			//breed in the space below (for notes see breed above) 
			if(starter == 2)
            {
                if(row == rows-1)
                {
                    counter +=1;
                    starter = 3;
                }
                else if(c[row+1][col] == nullptr)
                {

                    c[row+1][col] = new Ant();
                    c[row+1][col]->setMoveHistory(true);
                    break;
                }
                else
                {
                    counter +=1;
                    starter = 3;
                }
            }
         
			//breed in the space to the right (for notes see breed above) 
			if(starter == 3)
            {
                if(col == 0)
                {
                    counter +=1;
                    starter = 4;
                }
                else if(c[row][col-1] == nullptr)
                {
                    c[row][col-1] = new Ant();
                    c[row][col-1]->setMoveHistory(true);
                    break;
                }
                else
                {
                    counter +=1;
                    starter = 4;
                }
            }
			
			//breed in the space to the left (for notes see breed above) 
            if(starter == 4)
            {
                if(col == columns-1)
                {
                    counter +=1;
                    starter = 1;
                }
                else if(c[row][col+1] == nullptr)
                {
                    c[row][col+1] = new Ant();
                    c[row][col+1]->setMoveHistory(true);
                    break;

                }
                else
                {
                    counter +=1;
                    starter = 1;
                }
            }
        }
    }

}

