all: output

output: main_queue.o Queue.o 
	g++ -std=c++11 main_queue.o Queue.o -o output
main_queue.o: main_queue.cpp
	g++ -std=c++11 -c main_queue.cpp
Queue.o: Queue.cpp Queue.h
	g++ -std=c++11 -c Queue.cpp
clean:
	rm *.o output
 