all: output
output: combat_main.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Vampire.o
	g++ -std=c++11 combat_main.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Vampire.o -o output
combat_main.o: combat_main.cpp
	g++ -std=c++11 -c combat_main.cpp
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
clean:
	rm *.o output
 
