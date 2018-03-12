/********************************************************************* 
** Program name: outputLetters.cpp 
** Author: Amy Sage
** Date: 1/20/18 
** Description: cpp file for outputting letters to new file
*********************************************************************/
#include <iostream>
#include <fstream>
#include "outputLetters.h"
using namespace std;
void output_letters(ofstream &outFile, int* array)
{
	//loop through int array while printing corresponding letter
	for(int i=0; i< 26; i++) 
	{	
		outFile << (char)(i + 97) << ": " << array[i] << endl;
	}	
}
