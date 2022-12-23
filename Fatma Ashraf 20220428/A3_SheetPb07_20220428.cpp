#include<bits/stdc++.h>
using namespace std;


// Q7 Bonus Assign3 " STL-Map "
int main(){
    vector<string> docx;
    map<string ,int> table;
    fstream file;
    string filename,word;
    cin >> filename;
    filename+= ".txt";

    file.open(filename.c_str());
    while (file >> word)
    {
        int i = 0;
        while(i < word.size()){
            if (ispunct(word[i]))
                word.erase(i);
            i++;
        }
        docx.push_back(word);
    }

    for (int i = 0 ; i < docx.size(); i++){
        string x = docx[i];
        if(table.count(x)) {
            x="";
            continue;
        } table.insert(pair<string,int >(x,0));
        for (auto & j : docx) {
            if (x == j)
                table[x] += 1;
        }
        x="";
    }

    map<string ,int>:: iterator itr;
    cout << "\tWord\tRepeated times\n";
    for (itr = table.begin(); itr != table.end(); ++itr) {
        cout << "\t"  << itr->first << "\t\t" << itr->second << endl;
    }

}
