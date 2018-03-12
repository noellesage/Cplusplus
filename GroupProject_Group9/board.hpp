#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "critter.hpp"

class Board
{
    private:
        Critter*** grid;
        int critterCount;
		int rows; 
		int columns; 

    public:
        Board();
		Board(int, int); 
        ~Board();
        Board getBoard();
        Critter*** getGrid();
		int getRows(); 
		int getColumns(); 
        void printBoard();
        void checkAntMove();
		void checkDoodleMove();
        void advanceAge();
        void checkAntBreed();
		void checkDoodleStarve(); 
		void checkDoodleBreed();

};

#endif // BOARD_HPP_INCLUDED
