#include "player.h"

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Player::Player(char symbol) {
    this->symbol = symbol;
}


Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move (int& x) {
    cout <<  "\n "<< name<< " , Please enter your move (from 1 to 3): ";
    cin >> x ;
}

string Player::to_string(){
    return "Player: " + name ;
}


char Player::get_symbol() {
    return symbol;
}
