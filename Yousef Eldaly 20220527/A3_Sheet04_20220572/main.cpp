#include<bits/stdc++.h>
#include<iostream>
#include <vector>

using namespace std;

vector <string> v1 { "GREEN","YELLOW"  ,"RED"};
vector<string> taken;
void bactracking (int counter)
{
    if (counter==0)
    {
        for ( int i = 0 ; i < taken.size()   ; i++)
        {
           cout <<i+1<< "- " <<  taken[i] <<"   ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        taken.push_back(v1[i]);
        bactracking(counter-1);
        taken.pop_back();
    }
}
int main ()
{

    long long a ;
    cin >> a;
    bactracking(a);
    return 0;

}
