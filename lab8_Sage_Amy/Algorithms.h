/****************************************
** Program name: Algorithms.h
** Author: Amy Sage
** Date: 3/4/2018
** Description: Defines 2 searching and 1 sorting algorithm
****************************************
***************************/
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Algorithms
{
  private:
    int SIZE; //array size
    int count; //loop counter
  public:
    Algorithms();
    void linear_search(string, int);
    string insertion_sort(string);
    void binary_search(string, int);
    ~Algorithms();
};
#endif
