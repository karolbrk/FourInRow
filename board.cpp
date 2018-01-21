#include "board.hpp"
#include <string>
#include <iostream>
#include <algorithm>

Board::Board():
    board{std::vector<std::vector<char>>(6, std::vector<char>(7, ' '))} {
}

void Board::show() const {
    std::cout << " 1  2  3  4  5  6  7\n";
    for(const auto& row: board) {
        for(const auto& field: row) {
            std::cout << '[' << field << ']';
        }
        std::cout << std::endl;
    }
}

bool Board::insert(unsigned col, const char token) {
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

char Board::whichWin() const {
    char winToken{' '};

    if (isFourInRow(winToken)) {
        return winToken;
    }

    if (isFourInColumn(winToken)) {
        return winToken;
    }

    if (isFourCrosswise(winToken)) {
        return winToken;
    }

    return ' ';
}

bool Board::isFourInRow(char& token) const {
    if (checkIsFourInRow(board, 'o')) {
        token = 'o';
        return true;
    }

    if (checkIsFourInRow(board, 'x')) {
        token = 'x';
        return true;
    }

    return false;
}

bool Board::isFourInColumn(char& token) const {
    std::vector<std::vector<char>> trans(7, std::vector<char>(6, ' '));
    for (std::vector<char>::size_type i = 0; i < board.size(); ++i) {
        for (std::vector<char>::size_type j = 0; j < board[i].size(); ++j) {
            trans[j][i] = board[i][j];
        }
    }

    if (checkIsFourInRow(trans, 'o')) {
        token = 'o';
        return true;
    }

    if (checkIsFourInRow(trans, 'x')) {
        token = 'x';
        return true;
    }

    return false;

}

bool Board::isFourCrosswise(char& token) const {
    for (size_t row = 5; row > 2; --row) {
        for (size_t col = 0; col < 4; ++col) {
            if (board[row][col] != ' ' &&
                    board[row][col] == board[row - 1][col + 1] &&
                    board[row - 1][col + 1] == board[row - 2][col + 2] &&
                    board[row - 2][col + 2] == board[row - 3][col + 3]) {
                token = board[row][col];
                return true;
            }
        }
    }

    for (size_t row = 0; row < 3; ++row) {
        for (size_t col = 0; col < 4; ++col) {
            if (board[row][col] != ' ' &&
                    board[row][col] == board[row + 1][col + 1] &&
                    board[row + 1][col + 1] == board[row + 2][col + 2] &&
                    board[row + 2][col + 2] == board[row + 3][col + 3]) {
                token = board[row][col];
                return true;
            }
        }
    }

    return false;
}

bool Board::checkIsFourInRow(const std::vector<std::vector<char>>& board, const char token) const {
    for (auto& row : board) {
        if (std::search_n(row.begin(), row.end(), 4, token) != row.end()) {
            return true;
        }
    }
    return false;

}
