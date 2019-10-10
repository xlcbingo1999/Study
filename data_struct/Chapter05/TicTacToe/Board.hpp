#ifndef BOARD_H
#define BOARD_H

#include "Move.hpp"
#include <stack>
class Board
{
public:
    Board();
    bool done()const;
    void print()const;
    void instructions()const;
    bool better(int value , int old_value)const;
    void play(Move try_it);
    int worst_case() const;
    int evaluate() const;
    int legal_moves(stack &moves)const;
private:
    int squares[3][3];
    int moves_done;
    int the_winner()const;
};
#endif // BOARD_H
