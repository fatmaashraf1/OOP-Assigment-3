#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Player
{
    protected:
        string name;
        char symbol;
    public:
        Player (char symbol);
        Player (int order, char symbol);
        virtual void get_move(int& x);
        string get_name(){
            return name;
        }
        string to_string();

        char get_symbol();


};



#endif // PLAYER_H
