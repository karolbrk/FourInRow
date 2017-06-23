#pragma once 

#include <vector>

class Board {
    public:
        Board();
        void show() const;
        bool insert(unsigned column_index, char token);
        void clean();
    private:
        std::vector<std::vector<char>> board;
};
