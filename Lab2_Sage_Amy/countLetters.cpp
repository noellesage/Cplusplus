/********************************************************************* 
** Program name: countLetters.cpp
** Author: Amy Sage
** Date: 1/20/18 
** Description: cpp file for counting letters
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "countLetters.h"
using namespace std;
void count_letters(ifstream &inFile, int* array)
{
	string text, letters = "";
	char ch;
	int l = 0;
	//takes input until newline encountered
	while(getline(inFile, text)) 
	{
		if(text.empty())
		{
			break;
		}
		else
		{
			//add lines
			letters += text + ' ';
		}
	} 
		//delete spaces
		letters.erase(letters.length()-1);
		//increment ASCII and array position
		for(int i=0; i<letters.length(); i++) 
		{
			//change letter to lowercase
			ch = tolower(letters[i]);	
			//if letter matches ASCII, increase count 
			if((int)ch >= 97 && (int)ch <= 122) 
			{
				array[(int)ch -97] += 1;	
			}
		}
}
