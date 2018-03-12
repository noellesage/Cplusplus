/*********************************************************************
** Program name: matrixMain.cpp 
** Author: Amy Sage 
** Date: 1/13/2018
** Description: main execution file for finding determinant of matrix
*********************************************************************/
#include "determinant.h"
#include "readMatrix.h"
#include <iostream>

int main()
{
	int SIZE = 0;
	std::cout << "Please enter the size of the matrix. Either 2x2 or 3x3. For a 2x2 enter 2 and for a 3x3 enter 3." << std::endl;
	std::cin >> SIZE;

	//dynamic array
	int **array = new int*[SIZE];
	for(int i=0; i < SIZE; i++)
	{
		array[i] = new int[SIZE];
	}	

	std::cout << "Please enter 4 integers for a 2x2 and 9 integers for a 3x3." << std::endl;

	//read integers into array and display
	readMatrix(array, SIZE);
	for(int i=0; i < SIZE;i++)
	{
	for(int k=0; k < SIZE; k++)
		{
			std::cout << array[i][k] << " ";
		}
		std::cout << std::endl;
	} 
 
	//calculate determinant and display
	int deter = determinant(array, SIZE);
	std::cout << "The determinant is " << deter << std::endl;
	
	//deallocate memory
	for(int i=0; i < SIZE; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	
	return 0;
} 
	
