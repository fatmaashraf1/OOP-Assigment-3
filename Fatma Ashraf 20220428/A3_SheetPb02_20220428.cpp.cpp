#include<bits/stdc++.h>
using namespace std;

///// Variant One
#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define N_COINS 23
#define HUMAN 1
#define COMPUTER 0


int findGoodMove(int nCoins, int humanCoins, int botCoins, bool bot) {
    int times = min(nCoins, MAX_MOVE);
    if (times == 0) {
        return humanCoins % 2;
    }
    for (int n = 1; n <= times; n++)
        if (bot) {
            if (findGoodMove(nCoins - n, humanCoins, botCoins+n, !bot))
                return n;
        } else if (!bot){
            if (!findGoodMove(nCoins - n, humanCoins+n, botCoins, !bot))
                return 0;
        }
    return !bot;
}

int main() {
    int nCoins = N_COINS, n;
    int whoseTurn = HUMAN;
    int humanCoins = 0, botCoins = 0;
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins > 0) {
        cout << "\nWe have " << nCoins << ".\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                n = nCoins + 10;
                while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                }
                humanCoins += n;
                break;
            case COMPUTER:
                n = findGoodMove(nCoins, humanCoins, botCoins, true);
                if (!n)
                    n = 1;
                botCoins += n;
                cout << "Computer takes " << n << " coins.\n" ;
        }
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (humanCoins%2 ? "Computer \n" : "Human\n");
}
/*

//// Variant Two
#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define N_COINS 3
#define HUMAN 1
#define COMPUTER 0
#define pii pair<int, int>

using namespace std;

bool isBadPosition(int piles[]);

pii noGood = {0, 0};

pii findGoodMove(int piles[]) {
    for (int i = 0; i < 3; ++i) {
        int pile = i + 1;
        for (int n = 1; n <= min(piles[i], MAX_MOVE); n++) {
            piles[i] -= n;
            if (isBadPosition(piles)) {
                piles[i] += n;
                return {pile, n};
            }
            piles[i] += n;
        }
    }
    return {0, 0};
}

bool isBadPosition(int piles[]) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += piles[i];
    }
    if (sum == 1)
        return true;
    return findGoodMove(piles) == noGood;
}

int main() {
    int n, pile;
    int whoseTurn = HUMAN;
    int piles[3];
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        piles[i] = N_COINS + i;
        sum += piles[i];
    }
    cout << "Welcome to Nim. We start with three piles." << endl;
    for (int i = 1; i <= 3; ++i) {
        cout << "Pile number #" << i << " contains: " << piles[i-1] << " coins.\n";
    }
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";
    while (sum > 1) {
        cout << "\nWe have " << sum << ".\n";
        for (int i = 1; i <= 3; ++i) {
            cout << "Pile number #" << i << " contains: " << piles[i-1] << " coins.\n";
        }
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                pile = 4;
                while (pile < 1 || pile > 3 || !piles[pile - 1]) {
                    cout << "Pls choose a valid pile: ";
                    cin >> pile;
                }
                n = MAX_MOVE + 1;
                while (n < 1 || n > MAX_MOVE || n > piles[pile - 1]) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                }
                break;
            case COMPUTER:
                pii t = findGoodMove(piles);
                pile = t.first;
                n = t.second;
                if (n == 0) {
                    n = 1;
                    for (int i = 0; i < 3; ++i) {
                        if (piles[i] > 0)pile = i + 1;
                    }
                }
                cout << "Computer takes " << n << " coins from pile " << pile << ".\n";
        }
        sum -= n;
        piles[pile - 1] -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human\n");
}

*/