#ifndef BOARD_H
#define BOARD_H


#include "player.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class board
{

    public:
        char arr[5][5] = {{0,'v', 'v','v',0} , {'>',0,0,0,0} , {'>',0,0,0,0} , {'>',0,0,0,0}, {0}};
        void display_board();
        bool update_board(int x, char c);
        bool is_winner();
        bool noMove(board b , char c);


};


#endif // BOARD_H
