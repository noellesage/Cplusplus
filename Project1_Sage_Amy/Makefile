
output: ant_main_best.o Ant.o
	g++ ant_main_best.o Ant.o -o output
ant_main_best.o: ant_main_best.cpp
	g++ -c ant_main_best.cpp
Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

clean:
	rm *.o output

