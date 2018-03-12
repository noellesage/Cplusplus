all: output

output: main_die.o Die.o Loaded_die.o Game.o
	g++ -std=c++11 main_die.o Die.o Loaded_die.o Game.o -o output
main_die.o: main_die.cpp
	g++ -std=c++11 -c main_die.cpp
Die.o: Die.cpp Die.h
	g++ -std=c++11 -c Die.cpp
Loaded_die: Loaded_die.cpp Loaded_die.h
	g++ -std=c++11 -c Loaded_die.cpp
Game.o: Game.cpp Game.h
	g++ -std=c++11 -c Game.cpp
clean:
	rm *.o output
