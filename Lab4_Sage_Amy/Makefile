all: output

output: main_university.o University.o Building.o Person.o Student.o Instructor.o
	g++ -std=c++11 main_university.o University.o Building.o Person.o Student.o Instructor.o -o output
main_university.o: main_university.cpp
	g++ -std=c++11 -c main_university.cpp
University.o: University.cpp University.h
	g++ -std=c++11 -c University.cpp
Building.o: Building.cpp Building.h
	g++ -std=c++11 -c Building.cpp
Person.o: Person.cpp Person.h
	g++ -std=c++11 -c Person.cpp
Student.o: Student.cpp Student.h
	g++ -std=c++11 -c Student.cpp
Instructor.o: Instructor.cpp Instructor.h
	g++ -std=c++11 -c Instructor.cpp
clean:
	rm *.o output 
