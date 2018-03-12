all: output

output: linked_list_main.o List.o Node.o
	g++ -std=c++11 linked_list_main.o List.o Node.o -o output
linked_list_main.o: linked_list_main.cpp
	g++ -std=c++11 -c linked_list_main.cpp
List.o: List.cpp List.h
	g++ -std=c++11 -c List.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm *.o output
