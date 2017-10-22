#include "chess.hpp"
#include <iostream>
#include <memory>

using namespace chess;

void game::move(piece_p piece, pos to) {
    board[to.x][to.y].p = piece;
}

void game::print() {
    for (int j = 0; j < size; j++) {
        std::cout << j+1 << ' ';
        for (int i = 0; i < size; i++) {
            if (board[i][j].is_occupied())
                std::cout << board[i][j].p->repr();
            else
                std::cout << '.';
        }
        std::cout << '\n';
    }
}

bool pawn::could_move(pos from, pos to) {
    return false;
}

char pawn::repr() {
    return 'p';
}

void game::set_start_position() {
    for (int i = 0; i < size; i++) {
        piece_p p(new pawn(color::white));
        board[i][1].p = p;
        pieces.push_back(p);

        piece_p pb(new pawn(color::black));
        board[i][6].p = pb;
        pieces.push_back(pb);
    }
}

int main () {
    game game;
    game.set_start_position();
    game.print();
}
