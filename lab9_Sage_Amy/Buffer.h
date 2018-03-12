/****************************************
** Program name: Buffer.h
** Author: Amy Sage
** Date: 3/7/2018
** Description:
****************************************
***************************/

#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include <random>
#include <iterator>
using std::endl;
using std::cout;
using std::cin;

class Buffer
{
  public:
    Buffer();
    int generate_number(int);
    void game_queue();
    ~Buffer();
};
#endif
