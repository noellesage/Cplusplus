/***************************
** Author: Taylor Eldreth
** Date: Jan 20 2018
** Description: integer Validation function. takes in a min and max, and requests the user to enter an integer until a valid input is given. 
***************************/

#include <iostream>
#include "intVal.hpp"
 
using std::cin; 
using std::cout; 
using std::endl; 


int intVal(char MaxVal, int max, char MinVal, int min) { 
	
	int choice; 
	cin >> choice; 
	while (1) {  // check to see if the user inputed a valid input
		if (!cin.fail())
			if (MinVal =='y' && choice < min){  //if the MinVal option was set to y(yes) check to see if the value is smaller than the min
				cout << "Sorry that number is too low, please enter "; 
				cout <<	"and integer in the allowed range."; 
				cout << endl; 
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> choice; 
				}
			else if (MaxVal == 'y' && choice > max){  //if the MaxVal option was set to y(yes) check to see if the value is larger than max
				cout << "Sorry that number is too high, please enter "; 
				cout <<	"and integer in the allowed range."; 
				cout << endl; 
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> choice; 
				}
			else 
				break; 
		else {
			cout << "Sorry that is no a valid input, please enter an integer" << endl; //if the input was not valid request the user to reinput a value
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> choice; 
		}
	}
	cin.clear();  //clear out the cin stream to remove possible errors from values that cin.fail() does not catch. ex: 123abc
	cin.ignore(10000, '\n');
	return choice; //return an integers representing the users choice

}
