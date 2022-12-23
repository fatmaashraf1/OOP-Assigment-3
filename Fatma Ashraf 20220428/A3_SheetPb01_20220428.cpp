#include<bits/stdc++.h>
using namespace std;


/// Q1 Individual
void valid(int index,string word,string current_word,string sentence, map<string,bool>&dic){
    if(index == sentence.size()){
        cout << current_word << endl;
        return;
    }
    word+=tolower(sentence[index]);
    current_word+=sentence[index];
    if(dic.count(word)){
        valid(index+1,"",current_word+" ",sentence,dic);
    }
    valid(index+1,word,current_word,sentence,dic);
}

int main() {
    map<string, bool> dictionary;
    ifstream file("dictionary.txt");

    while (!file.eof()) {
        string s;
        getline(file, s);
        dictionary[s] = true;
    }
    dictionary[""] = true;

    string word;
    cin >> word;
    valid(0,"","",word,dictionary);

}