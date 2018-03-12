all: output
output: main.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Vampire.o LineupQueue.o Game.o LoserList.o
	g++ -std=c++11 main.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Vampire.o LineupQueue.o Game.o LoserList.o -o output
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Barbarian.o: Barbarian.cpp Barbarian.h
	g++ -std=c++11 -c Barbarian.cpp
BlueMen.o: BlueMen.cpp BlueMen.h
	g++ -std=c++11 -c BlueMen.cpp
Character.o: Character.cpp Character.h
	g++ -std=c++11 -c Character.cpp
HarryPotter.o: HarryPotter.cpp HarryPotter.h
	g++ -std=c++11 -c HarryPotter.cpp
Medusa.o: Medusa.cpp Medusa.h
	g++ -std=c++11 -c Medusa.cpp
Vampire.o: Vampire.cpp Vampire.h
	g++ -std=c++11 -c Vampire.cpp
LineupQueue.o: LineupQueue.cpp LineupQueue.h
	g++ -std=c++11 -c LineupQueue.cpp
Game.o: Game.cpp Game.h
	g++ -std=c++11 -c Game.cpp
LoserList.o: LoserList.cpp LoserList.h
	g++ -std=c++11 -c LoserList.cpp
clean:
	rm *.o output
