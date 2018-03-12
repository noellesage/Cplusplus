all: output

output: countMain.o countLetters.o outputLetters.o
	g++ -std=c++11 -o output countMain.o countLetters.o outputLetters.o
countMain.o: countMain.cpp
	g++ -std=c++11 -c countMain.cpp
countLetters.o: countLetters.cpp
	g++ -std=c++11 -c countLetters.cpp
outputLetters.o: outputLetters.cpp 
	g++ -std=c++11 -c outputLetters.cpp
clean:
	rm *.o output
