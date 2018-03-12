/********************************************************************** Program name: ant_main.cpp 
** Author: Amy Sage
** Date: 1/18/2018
** Description: uses ant class and user input to define Langston Ant board 
********************************************************************/
#include <iostream>
#include <string>
#include "Ant.hpp"
using std::cout;
using std::cin;
using std::endl;

//shows menu to start/quit game
void showMenu()	
{
     cout << "Menu" << endl;
     cout << "1) Start" << endl;
     cout << "2) Quit" << endl;
}
	
int main()
{
	//show menu
	showMenu();
	int choice = 0;
	cin >> choice;
	//user menu choice evaluated
	switch(choice)
	{
		case 1:
			break;
		case 2:
			cout << "Goodbye" << endl;
			return 0;
	}
	
	//program begins, asker for user input
	int rows, columns, steps, row_location, col_location; 
	//ask user for rows
	cout << "Please enter the number of rows: "; 	
	cin >> rows;
	while(cin.fail() || rows <= 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter another number. " << endl;
		cin >> rows;
	}
	//ask user for columns
	cout << "Please enter the number of columns: ";
	cin >> columns;
	while(cin.fail() || columns <= 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter another number."<< endl;
		cin >> columns; 
	}
	//ask user for number of steps
	cout << "Please enter the number of steps during simulation: ";
	cin >> steps;
	while(cin.fail() || steps <= 0)
        {
		cin.clear();
		cin.ignore();
                cout << "The number must be positive. Please enter another number."<< endl;
                cin >> steps;
        }

	//ask for user input on start location
	cout << "Please enter the starting row location: ";
	cin >> row_location;
	while(cin.fail() || row_location <= 0)
        {
		cin.clear();
		cin.ignore();
                cout << "The number must be positive. Please enter another number."<< endl;
                cin >> row_location;
        }

	cout << "Please enter the starting column location: ";
	cin >> col_location;
	while(cin.fail() || col_location <= 0)
        {
		cin.clear();
		cin.ignore();
                cout << "The number must be positive. Please enter another number."<< endl;
                cin >> col_location;
        }

	//create ant object
	Ant myAnt(row_location, col_location);
	//make board
	char **board = new char*[rows];
	for(int i=0; i<rows; i++)
	{
		board[i] = new char[columns];
	}
	
	//draw board
	for(int i=0; i<rows; i++)
	{
		for(int k=0; k<columns; k++)
		{
			board[i][k] = ' ';
		}
	}
	//ant starting location
	board[row_location][col_location] = '*';
	//show board
	 for(int i=0; i<rows; i++)
        {
                for(int k=0; k<columns; k++)
                {
                        cout << board[i][k];
                }
        }
	
	//loop through number of steps given
	for(int i=0; i < steps; i++)
	{	
	//if space lands on is white
	if(myAnt.get_color() == ' ')
	{
	
		//change previous space to black
		board[myAnt.get_prev_row()][myAnt.get_prev_col()] = '#';
		 //if current direction is up
                if(myAnt.get_direction() == up)
                {
                        myAnt.set_direction(right);
                        col_location = myAnt.get_curr_col();
                        col_location++;
                        if(col_location >= columns )
                        {
                                col_location = 0;
                        }
                        myAnt.set_curr_col(col_location);
                        if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ')
                        {
                                myAnt.set_color(' ');
                        }
                        else
                        {
                                myAnt.set_color('#');
                        }
                        board[myAnt.get_curr_row()][myAnt.get_curr_col()] = '*';
                }	
		//if current direction is right 
		else if(myAnt.get_direction() == right)
		{
			myAnt.set_direction(down);
			row_location = myAnt.get_curr_row();
			row_location++;
			if(row_location >= rows)
			{
				row_location = 0;
			}
			myAnt.set_curr_row(row_location);
			if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ')
			{
				myAnt.set_color(' ');
			}
			else
			{
				myAnt.set_color('#');
			}
			board[myAnt.get_curr_row()][myAnt.get_curr_col()] = '*';
		}
		//if current direction is down
		else if(myAnt.get_direction() == down)
		{
			myAnt.set_direction(left);
			col_location = myAnt.get_curr_col();
			col_location -= 1;
			if(col_location < 0)
			{
				col_location = columns -1;
			}
			myAnt.set_curr_col(col_location);
			if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ')
			{
				myAnt.set_color(' ');
			}
			else
			{
				myAnt.set_color('#');
			}
			board[myAnt.get_curr_row()][myAnt.get_curr_col()] = '*';
		}
		//if current direction is left
		else if(myAnt.get_direction() == left)
		{
			myAnt.set_direction(up);
			row_location = myAnt.get_curr_row();
			row_location -= 1;
			if(row_location < 0)
			{
				row_location = rows - 1;
			}
			myAnt.set_curr_row(row_location);
			if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ' )
			{
				myAnt.set_color(' ');
			}
			else
			{
				myAnt.set_color('#');
			}
			board[row_location][col_location] = '*';
		}
				
		}
	//if space lands on is black
	else if(myAnt.get_color() == '#')
	{
		//change previous space to white
		board[row_location][col_location] = ' ';
		//if current direction is up
                if(myAnt.get_direction() == up)
                {
                        myAnt.set_direction(left);
                        col_location = myAnt.get_curr_col();
                        if(col_location < 0)
                        {
                                col_location = columns -1;
                        }
                        myAnt.set_curr_col(col_location);
                        if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ')
                        {
                                myAnt.set_color(' ');
                        }
                        else
                        {
                                myAnt.set_color('#');
                        }
                        board[myAnt.get_curr_row()][myAnt.get_curr_col()] = '*';

                }
		    //if current direction is right
                else if(myAnt.get_direction() == right)
                {
                        myAnt.set_direction(up);
                        row_location = myAnt.get_curr_row();
                        row_location = rows - 1;
                        myAnt.set_curr_row(row_location);
                        if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ')
                        {
                                myAnt.set_color(' ');
                        }
                        else
                        {
                                myAnt.set_color('#');
                        }
                        board[row_location][col_location] = '*';

                }
		//if current direction is down
                else if(myAnt.get_direction() == down)
                {
                        myAnt.set_direction(right);
                        col_location = myAnt.get_curr_col();
                        col_location++;
                        if(col_location >= columns)
                        {
                                col_location = 0;
                        }
                        myAnt.set_curr_col(col_location);
                        if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ' )
                        {
                                myAnt.set_color(' ');
                        }
                        else
                        {
                                myAnt.set_color('#');
                        }
                        board[myAnt.get_curr_row()][myAnt.get_curr_col()] = '*';
                }

		//if current direction is left
		else if(myAnt.get_direction() == left)
		{
			myAnt.set_direction(down);
			row_location = myAnt.get_curr_row();
			row_location++;
			if(row_location >= rows)
			{	
				row_location = 0;
			}
			myAnt.set_curr_row(row_location);
			if(board[myAnt.get_curr_row()][myAnt.get_curr_col()] == ' ') 
			{
				myAnt.set_color(' ');
			}
			else
			{
				myAnt.set_color('#');
			}
		
			board[myAnt.get_curr_row()][myAnt.get_curr_col()] == '*';
		}	
	}
	//print board
	for(int i=0; i < rows; i++)
	{
		for(int k=0; k<columns; k++)
		{
			cout << board[i][k];
		}
		cout << endl;
	}
	myAnt.set_prev_row(row_location);
	myAnt.set_prev_col(col_location);
	}
	//deallocate
	for(int i=0; i<rows;i++)
	{
		delete [] board[i];
	}
		delete [] board;	
			
return 0;
}	
