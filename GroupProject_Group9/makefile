CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = ant.o doodlebug.o main.o critter.o board.o intVal.o Menu.o

SRCS = ant.cpp doodlebug.cpp main.cpp critter.cpp board.cpp intVal.cpp Menu.cpp


main: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o GroupProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o GroupProject
