#include "computerPlayer.h"



int computerPlayer :: evaluate_moves(const board& temp) {
   if(temp.arr[1][4] == '>' && temp.arr[2][4] == '>' && temp.arr[3][4] == '>'){
        return -10;
    }else if(temp.arr[4][1] == 'v' && temp.arr[4][2] == 'v' && temp.arr[4][3] == 'v'){
        return 10;
    }
    return 0;
}


computerPlayer::computerPlayer(board b) : Player('v'){
    vector<int> evaluation = {0, 0 ,0};

    for (int i = 1; i < 4; ++i) {
        board temp(b);
        if (temp.update_board(i , 'v')){

            //temp.display_board();
            evaluation[i-1] = minimax(temp, 0, true);


        }else{

            evaluation[i-1] = -50;
            continue;
        }
//        for(int i =0;i < evaluation.size(); i++){
//            cout << evaluation[i] << endl;
//        }

//    }
//    for(int i = 0; i < evaluation.size();i++){
//        cout << evaluation[i] << endl;
//    }
    int best = evaluation[0] ;

    for (int i = 0; i < 3; ++i) {
        if (best < evaluation[i]){
            best = evaluation[i];
            this->best_move = i+1;

        }
    }
}
}

int computerPlayer::minimax(board temp, int num, bool is_player) {
    int score = evaluate_moves(temp);
   // cout << "here" << endl;
    if (score == 10){
        return score - num;
    }else if (score == -10){
        return score + num;
    }

    if (is_player){
        int minimum = 50;
        for (int i = 1; i < 4; ++i) {

                if (temp.update_board(i , '>')){
                    minimum = min(minimum, minimax(temp, num+1, !is_player));



                }

        }
        return minimum;
    }else{
        int maximum = -50;
        for (int i = 1; i < 4; ++i) {

                if (temp.update_board(i , 'v')){
                    maximum = max(maximum, minimax(temp, num+1, !is_player));



                }
            }

        return maximum;
    }
}

