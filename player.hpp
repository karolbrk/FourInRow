#pragma once

#include <string>
#include "board.hpp"

class Player {
    public:
        Player();
        Player(const std::string& name, char token);
        bool move(Board& board, unsigned column_index) const;
        std::string getName() const;
        char getToken() const;
    private:
        char token;
        std::string name;
};
