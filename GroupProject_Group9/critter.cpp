#include "critter.hpp"

#include <iostream>

using namespace std;

Critter::Critter()
{
    age = 0;
    id = ' ';
    moveHistory = false;
}

Critter::~Critter()
{

}

void Critter::move(Critter*** c, int row, int col, int rows, int columns)
{

}

void Critter::breed(Critter*** c, int row, int col, int rows, int columns)
{

}

void Critter::starve(Critter*** c, int row, int col)
{

}

int Critter::getLastFed() {

}

char Critter::getID()
{
    return id;
}

void Critter::setMoveHistory(bool t)
{
    moveHistory = t;
}

void Critter::setAge()
{
    age += 1;
}

int Critter::getAge()
{
    return age;
}
