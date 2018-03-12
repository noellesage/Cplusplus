/********************************************************************* 
** Program name: countMain.cpp 
** Author: Amy Sage 
** Date: 1/20/18
** Description: takes input file, counts letters, outputs to outfile 
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "countLetters.h"
#include "outputLetters.h"
using namespace std;

int main()
{
	string inFilename; //input file
	ifstream inFile;
	string outFilename;
	ofstream outFile;
	int array[26] = {0}; //pointer array of alphabet occurences 
	int l = 1;	
	//ask for input file
	cout << "Please enter the name of the file you'd like to open: ";
	cin >> inFilename; 
	//open file
	inFile.open(inFilename, ios::in);
	
	//if it doesn't open try again
	while(inFile.good())
	{
		//count letters in file
		count_letters(inFile, array);
		//ask for outputfile name
		cout << "Please enter the output file name." << l << ": ";
		cin >> outFilename;
		//paragraph
		l += 1;
		//open output file
		outFile.open(outFilename, ios::out);
		//output letter occurences to file
		output_letters(outFile, array);
		//close output file
		outFile.close();
	}
	 //close input file
	 inFile.close();	
return 0;
}
	
