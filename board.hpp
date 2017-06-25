#pragma once 

#include <vector>

class Board {
    public:
        Board();
        void show() const;
        bool insert(unsigned column_index, char token);
        void clean();
        char whichWin() const;
    private:
        bool isFourInRow(char&) const;
        bool isFourInColumn(char&) const;
        bool isFourCrosswise(char&) const;
        bool checkIsFourInRow(const std::vector<std::vector<char>>&, const char) const;
        std::vector<std::vector<char>> board;
};
