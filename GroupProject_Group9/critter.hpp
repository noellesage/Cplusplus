#ifndef CRITTER_HPP_INCLUDED
#define CRITTER_HPP_INCLUDED


class Critter
{
    protected:
        int age;
        char id;
        bool moveHistory;

    public:
        Critter();
        virtual ~Critter();
        virtual void move(Critter***, int, int, int, int);
        virtual void breed(Critter***, int, int, int, int);
		virtual void starve(Critter***, int, int); 
		virtual int getLastFed(); 
        void setMoveHistory(bool);
        char getID();
        void setAge();
        int getAge();

};

#endif // CRITTER_HPP_INCLUDED
