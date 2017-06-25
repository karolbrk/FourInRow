CC=clang++
CFLAGS=-std=c++11 -Wall

.PHONY = clean

main.out: main.o board.o game.o player.o
	@echo Linking main.out	
	@$(CC) -o main.out main.o board.o game.o player.o

board.o: board.cpp board.hpp
	$(CC) $(CFLAGS) -c board.cpp

game.o: game.cpp game.hpp
	$(CC) $(CFLAGS) -c game.cpp

player.o: player.cpp player.hpp
	$(CC) $(CFLAGS) -c player.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	@rm -rf main.out *.o >/dev/null 2>&1
