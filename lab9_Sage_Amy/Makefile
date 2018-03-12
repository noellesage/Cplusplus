all: output
output: main.o Buffer.o menu_validate.o Stack.o
	g++ -std=c++11 main.o Buffer.o menu_validate.o Stack.o -o output
Buffer.o: Buffer.cpp Buffer.h
	g++ -std=c++11 -c Buffer.cpp
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Stack.o: Stack.cpp Stack.h
	g++ -std=c++11 -c Stack.cpp
menu_validate.o: menu_validate.cpp menu_validate.h
	g++ -std=c++11 -c menu_validate.cpp
clean:
	rm *.o output
