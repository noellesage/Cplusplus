/***************************
** Author: Taylor Eldreth
** Date: Jan 20 2018
** Description: menu function. takes in multiple menu options and displays them for the user, then returns the users choice.
***************************/

#include <iostream>
#include "Menu.hpp"
#include <string>

using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 


int menu(string options[], int size) { 

	int choice; 

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " << options[i] << endl; //print out each option
	}
	cin >> choice; 
	while (1) {  // check to see if the user inputed a valid input
		if (!cin.fail())
			if (choice < 1){ 
				cout << "Sorry that number is too low, please make a "; 
				cout <<	"selection from the available options."; 
				cout << endl; 
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> choice; 
				}
			else if(choice > size){
				cout << "Sorry that number is too high, please make a"; 
				cout << "selection from the available options."; 
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
	cin.clear();
	cin.ignore(10000, '\n');
	return choice; //return an integers representing the users choice

}
