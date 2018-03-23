vimCXX = g++
CXXFLAGS = -std=c++0x -g
OBJS = alienbox.o aliensecrets.o alienspace.o alienthanks.o blackhole.o boundary.o forcefield.o fuelcan.o game.o hole.o item.o outerspace.o planet.o player.o rock.o rocketship.o rocketshipkey.o ship.o space.o spacesuit.o star.o starspace.o main.o
SRCS = alienbox.cpp aliensecrets.cpp alienspace.cpp alienthanks.cpp blackhole.cpp boundary.cpp forcefield.cpp fuelcan.cpp game.cpp hole.cpp item.cpp outerspace.cpp planet.cpp player.cpp rock.cpp rocketship.cpp rocketshipkey.cpp ship.cpp space.cpp spacesuit.cpp star.cpp starspace.cpp main.cpp
HEADERS = alienbox.h aliensecrets.h alienspace.h alienthanks.h blackhole.h boundary.h forcefield.h fuelcan.h game.h hole.h item.h outerspace.cpp planet.h player.h rock.h rocketship.h rocketshipkey.h ship.h space.h spacesuit.h star.h starspace.h
final: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o cosmos
clean:
	rm -f cosmos *.o
