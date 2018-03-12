/********************************************************************* ** Program name: readMatrix.cpp
** Author: Amy Sage 
** Date: 1/13/2018
** Description: implements readMatrix function
*********************************************************************/
#include "readMatrix.h"

//Function which takes input from user into matrix
void readMatrix(int **array, int SIZE) 
{
	for(int rows=0; rows < SIZE; rows++)
	{	for(int cols=0; cols < SIZE; cols++)
		{
			std::cin >> array[rows][cols];
		}
	}
}
