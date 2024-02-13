# Author: Aum Patel
# Date: March 13, 2023

CC = g++
CFLAGS = -g --std=c++17 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = Sokoban.hpp Sokoban.cpp main.cpp CPPLINT.cfg

.PHONY: all Sokoban clean lint

all: Sokoban

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

Sokoban: Sokoban.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o Sokoban

lint:
	cpplint *.cpp *.hpp