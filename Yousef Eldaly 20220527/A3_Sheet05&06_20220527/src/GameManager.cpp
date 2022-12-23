#include "GameManager.h"
#include "computerPlayer.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int menu(){
    int choice;
    cout<<"1- multi players\n"
          "2- player vs computer\n"
          "3- exit\n";
    cin>>choice;
    return choice;
}

void GameManger::run(){
    board Board;
    int x, choice;
    choice = menu();

    if(choice == 1){
        Player players[2] = {Player (1, '>'), Player (2, 'v')};
        Board.display_board();
        while(true){
            for (int i:{0,1}) {
                players[i].get_move(x);
                while (!Board.update_board (x, players[i].get_symbol())){
                    if(Board.noMove(Board ,players[i].get_symbol())){
                        cout << "there is no move for " << players[i].get_name() << endl;
                        break;
                    }
                    players[i].get_move(x);
                }
                Board.display_board();
                if (Board.is_winner()){
                    cout  << players[i].to_string() << " wins\n";
                    return;
                }

            }
        }
    }else if(choice == 2){
        Player player1(1 ,'>');
        Board.display_board();
        while (true) {
            player1.get_move(x);
            while (!Board.update_board (x, player1.get_symbol())){
                if(Board.noMove(Board ,player1.get_symbol())){
                    cout << "there is no move for " << player1.get_name() << endl;
                    break;
                }
                player1.get_move(x);
            }
            if (Board.is_winner()){
                cout  << "player wins\n";
                return;
            }

            computerPlayer comp(Board);
            Board.update_board(comp.get_best_move(), comp.get_symbol());
            Board.display_board();
            if (Board.is_winner()){
                cout  << "Computer wins\n";
                return;
            }

        }
    }else{
        exit(0);
    }
}
