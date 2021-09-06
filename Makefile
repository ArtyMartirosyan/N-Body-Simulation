CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic  
OBJ = celestialBody.o universe.o main.o 
DEPS = celestialBody.cpp celestialBody.h universe.cpp universe.h main.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXE = NBody

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)