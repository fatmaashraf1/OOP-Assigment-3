#include "board.h"

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void board::display_board(){
    for(int i = 0; i < 5 ;i++){
        cout << "\n|";
        for(int j = 0; j < 5 ; j++){
         cout  << setw(2) << arr[i][j]  << " |";
        }
        cout << "\n---------------------";
    }
       cout << endl;
}

bool board::update_board(int x, char c){
    if(!(x <1 || x > 3)){
        if(c == 'v'){
            for(int i = 0 ; i < 5; i++){
                if(arr[i][x] == 'v' && i != 4){
                    if(arr[i+1][x] == 0){
                        arr[i+1][x] = 'v';
                        arr[i][x] = 0;
                        return true;
                    }else if(arr[i+2][x] == 0){
                        arr[i+2][x] = 'v';
                        arr[i][x] = 0;
                        return true;
                    }
                    return false;
                }

            }
            return false;
        }else{
            for(int i = 0 ; i < 5; i++){
                if(arr[x][i] == '>' && i != 4){
                    if(arr[x][i+1] == 0){
                        arr[x][i+1] = '>';
                        arr[x][i] = 0;

                        return true;
                    }else if(arr[x][i+2] == 0){
                        arr[x][i+2] = '>';
                        arr[x][i] = 0;

                        return true;
                    }

                    return false;
                }

            }
            return false;

        }
    }
}

bool board::noMove(board b,char c){
    bool flag;
    board temp(b);

    for(int i = 1; i < 4;i++){
        if(temp.update_board(i,c)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    return flag;
}


bool board::is_winner(){
    if(arr[1][4] == '>' && arr[2][4] == '>' && arr[3][4] == '>'){
        return true;
    }else if(arr[4][1] == 'v' && arr[4][2] == 'v' && arr[4][3] == 'v'){
        return true;
    }else{
        return false;
    }

};
