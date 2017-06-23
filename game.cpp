#include "game.hpp"
#include <iostream>
#include <limits>

Game::Game():
    players(2), board{Board()}, currentPlayer{nullptr}, nextPlayer{nullptr} {}

void Game::initGame() {
    std::string name1;
    std::string name2;
    char token1;
    char token2;

    std::cout << "Podaj imie pierwszego gracza: ";
    std::cin >> name1;
    token1 = readToken("Podaj token (znak) pierwszego gracza: ");

    for(;;) {
        std::cout << "Podaj imie drugiego gracza: ";
        std::cin >> name2;

        if(name1 == name2) {
            std::cout << "Drugi gracz powinien miec inne imie niz pierwszy!\n";
            std::cout << "Sprobuj jeszcze raz!\n";
            continue;
        }
        for(;;) {
            token2 = readToken("Podaj token (znak) drugiego gracza: ");
            if(token1 == token2) {
                std::cout << "Drugi gracz powinien miec inny znak zetonu!\n";
                std::cout << "Sprobuj jeszcze raz!\n";
                continue;
            }
            break;
        }
        break;
    }
    players[0] = Player(name1, token1);
    players[1] = Player(name2, token2);
    currentPlayer = &(players[0]);
    nextPlayer = &(players[1]);
}

char Game::readToken(const std::string& message) const {
    char token;
    for(;;) {
        std::cout << message;
        std::cin >> token;
        if(std::cin) {
            break;
        }
        std::cout << "Podaj znak!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return token;
}

unsigned Game::readColumnIndex(const std::string& message) const {
    unsigned index;
    for(;;) {
        std::cout << message;
        std::cin >> index;
        if(std::cin && index < 8) {
            break;
        }
        std::cout << "Podaj prawidlowy index!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return index - 1;
}

void Game::swapPlayer() {
    std::swap(currentPlayer, nextPlayer);
}

void Game::nextMove() {
   std::cout << currentPlayer->getName() << ", wykonuje ruch\n";
   for (;;) {
      auto column_index = readColumnIndex("Podaj index od 1 do 7: ");
      if (board.insert(column_index, currentPlayer->getToken())) {
         break;
      }
      else {
         std::cout << "Nieprawidlowy ruch! Sprobuj jeszcze raz.\n";
      }
   }
    board.show();
    swapPlayer();
}

Player * Game::whoWin() const {
    return nullptr;
}
