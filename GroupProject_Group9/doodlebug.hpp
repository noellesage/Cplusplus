#ifndef DOODLEBUG_HPP_INCLUDED
#define DOODLEBUG_HPP_INCLUDED

#include "critter.hpp"

class Doodlebug : public Critter
{
    private:
		int lastFed; 
    public:
        Doodlebug();
        void move(Critter*** c, int, int, int, int);
        void breed(Critter*** c, int, int, int, int);
        void starve(Critter*** c, int, int);
		int getLastFed(); 

};

#endif // DOODLEBUG_HPP_INCLUDED
