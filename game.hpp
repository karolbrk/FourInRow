#pragma once 

#include <vector>
#include <string>
#include "player.hpp"
#include "board.hpp"

class Game {
    public:
        Game();
        void initGame();
        void nextMove();
        Player * whoWin() const;
    private:
        char readToken(const std::string& message) const;
        unsigned readColumnIndex(const std::string& message) const;
        void swapPlayer();
        std::vector<Player> players;
        Board board;
        Player * currentPlayer;
        Player * nextPlayer;
};
