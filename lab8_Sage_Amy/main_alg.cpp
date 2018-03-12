/****************************************
** Program name: main_alg.cpp
** Author: Amy Sage
** Date: 3/4/2018
** Description: Implements Algorithms class
* creates 4 algorithms objects for 4 
* different txt files
****************************************
***************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Algorithms.h"
using std::ifstream;
using std::string; 

int main()
{
  Algorithms my_alg; //create Algorithm object
  Algorithms my_alg2; //create Algorithm object
  Algorithms my_alg3; //create Algorithm object
  Algorithms my_alg4; //create Algorithm object
  
  string name = "early.txt";
  string name2 = "middle.txt";
  string name3 = "end.txt";
  string name4 = "original.txt";
  
  //linear search
  cout << "****Linear search algorithm****" << endl;
  cout << "Please enter a target value: ";
  int v;
  cin >> v;
  while(cin.fail())
  {
    cout << "Sorry, invalid entry. Please enter an integer: ";
    cin.clear();
    cin.ignore();
    cin >> v;
  }
  cout << endl;
  my_alg.linear_search(name, v);
  my_alg2.linear_search(name2, v);
  my_alg3.linear_search(name3, v);
  my_alg4.linear_search(name4, v);
  cout << endl;
  
  //insertion sort
  cout << "****Insertion sort****" << endl;
  cout << "For early.txt sorted array: " << endl;
  string newFileName = my_alg.insertion_sort(name);
  cout << endl;
  cout << "For middle.txt sorted array: " << endl;
  string newFileName2 = my_alg2.insertion_sort(name2);
  cout << endl;
  cout << "For end.txt sorted array: " << endl;
  string newFileName3 = my_alg3.insertion_sort(name3);
  cout << endl;
  cout << "For original.txt sorted array: " << endl;
  string newFileName4 = my_alg4.insertion_sort(name4);
  cout << endl;
  cout << endl;
  
  //binary search
  cout << "****Binary search algorithm****" << endl;
  cout << "Please enter a target value: ";
  int v2;
  cin >> v2;
  while(cin.fail())
  {
    cout << "Sorry, invalid entry. Please enter an integer: ";
    cin.clear();
    cin.ignore();
    cin >> v2;
  }
  cout << endl;
  my_alg.binary_search(newFileName, v2);
  my_alg2.binary_search(newFileName2, v2);
  my_alg3.binary_search(newFileName3, v2);
  my_alg4.binary_search(newFileName4, v2);
  cout << endl;

  return 0;
}
