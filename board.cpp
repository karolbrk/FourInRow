#include "board.hpp"
#include <string>
#include <iostream>
#include <algorithm>

Board::Board():
    board{std::vector<std::vector<char>>(6, std::vector<char>(7, ' '))} {
}

void Board::show() const {
    for(const auto& row: board) {
        for(const auto& field: row) {
            std::cout << '[' << field << ']';
        }
        std::cout << std::endl;
    }
}

bool Board::insert(unsigned col, char token) {
    if (col > 7) {
        return false;
    }
    if (board[0][col] != ' ') {
        return false;
    } else {
        size_t row{6};
        while (row != 0) {
            if (board[row - 1][col] == ' ') {
                board[row - 1][col] = token;
                return true;
            }
            else {
                --row;
            }
        }
        return false;
    }
}

void Board::clean() {
    for(auto& row: board) {
        std::fill(row.begin(), row.end(), ' ');
    }
}
