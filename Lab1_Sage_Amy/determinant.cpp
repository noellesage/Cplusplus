/********************************************************************* ** Program name: determinant.cpp 
** Author: Amy Sage 
** Date: 1/13/2018
** Description: implements determinant function 
*********************************************************************/
#include "determinant.h"
//calculates the determinant for either a 2x2 or 3x3 matrix

int determinant(int **array, int SIZE)
{
    int result = 0;
	
    //if matrix is 2x2
    if(SIZE == 2)
    {
     	result = (array[0][0]*array[1][1]) - (array[0][1]*array[1][0]);
	return result;
    }
    //if matrix is 3x3
    else if(SIZE == 3)
    {
	int l, m, n = 0;
	l = array[0][0]*(array[1][1]*array[2][2]-array[1][2]*array[2][1]);
	m = array[0][1]*(array[1][0]*array[2][2]-array[1][2]*array[2][0]);
	n = array[0][2]*(array[1][0]*array[2][1]-array[1][1]*array[2][0]);
	
	result = l-m+n;
	return result; 
    }	
}
