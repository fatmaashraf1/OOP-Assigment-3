#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
#include "board.h"


class computerPlayer : public Player{
protected:
    string name = "computer";
    int best_move = 1;
public:
    computerPlayer(board x_o);
    int evaluate_moves(const board& temp_board);
    int minimax(board temp_board, int num,bool is_player);
    int get_best_move(){
        return best_move;
    };




};

#endif // COMPUTERPLAYER_H
