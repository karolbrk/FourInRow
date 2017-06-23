CC=clang++ -Wall

.PHONY = clean

main.out: main.o board.o game.o player.o
	$(CC) -o main.out main.o board.o game.o player.o

board.o: board.cpp board.hpp
	$(CC) -std=c++11 -c board.cpp

game.o: game.cpp game.hpp
	$(CC) -std=c++11 -c game.cpp

player.o: player.cpp player.hpp
	$(CC) -std=c++11 -c player.cpp

main.o: main.cpp
	$(CC) -std=c++11 -c main.cpp

clean:
	@rm -rf main.out *.o >/dev/null 2>&1
