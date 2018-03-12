all: output
output: main_alg.o Algorithms.o
	g++ -std=c++11 main_alg.o Algorithms.o -o output
main_alg.o: main_alg.cpp
	g++ -std=c++11 -c  main_alg.cpp
Algorithms.o: Algorithms.cpp Algorithms.h
	g++ -std=c++11 -c Algorithms.cpp
clean:
	rm *.o output
