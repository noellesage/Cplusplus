all: output

output: main_recursive.o recursive.o
	g++ -std=c++11 main_recursive.o recursive.o -o output
main_recursive.o: main_recursive.cpp
	g++ -std=c++11 -c main_recursive.cpp
recursive.o: recursive.cpp recursive.h
	g++ -std=c++11 -c recursive.cpp
clean:
	rm *.o output
