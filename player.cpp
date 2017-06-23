#include "player.hpp"

Player::Player(const std::string& name, char token): token{token}, name{name} {}

Player::Player(): Player("", ' ') {}

bool Player::move(Board& board, unsigned column_index) const {
    return board.insert(column_index, token);
}

std::string Player::getName() const {
    return name;
}

char Player::getToken() const {
    return token;
}
