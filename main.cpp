#include "board.hpp"
#include "game.hpp"

int main() {
    Game g;
    g.initGame();
    for(;;) {
        g.nextMove();
    }
}
