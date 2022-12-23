#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
class VTSet{
    vector<T> S;

public:
    void v_add (T item);
    void v_delete (T item);
    bool is_exist(T item);
    int v_size();
    void Print();
    };

template <class T>
void VTSet<T> :: Print() {
    sort(S.begin(), S.end());

    for (auto it = S.begin(); it != S.end(); ++it)
        cout << ' ' << *it;
}

template <class T>
bool VTSet<T> :: is_exist(T item){
    for(int i = 0; i < S.size(); i++){
        if (*(S.begin()+i) == item) {
            return true;

        }
    }
    return false ;
}

template <class T>
void VTSet<T>  :: v_add (T item){
    if (is_exist(item)== false){
        S.push_back(item);
    }
   else{
       cout << "this item already exist"<<endl;
   }
   S.shrink_to_fit();
}

template <class T>
void  VTSet<T> ::v_delete (T item){
    typename vector<T>::iterator it ;
     it = S.begin()+item;
    if (item<=S.size()-1){
        S.erase(it);
    }else {
        cout << "this index is not found"<<endl;
    }
    S.shrink_to_fit();
}

template <class T>
int VTSet<T> :: v_size(){
    int y = S.size();
}

int main() {
    int o;
    VTSet<char>  obj1;
    //int n;
    char n;
    cout << "enter the number of operation you want it:\n"<<"1-Add\n"<<"2-Delete\n"<<"3-Number of elements\n"<<"4-Check the item\n"<<"5-Exit\n";
    while (true){
        cin>> o ;
        if (o==1){
            int x;
            cout << "enter the number of elements :\n";
            cin>> x;
            for (int i =0 ; i<x; i++){
                cout << "Enter the "<<i+1<<" item :";
                cin >>  n;
                obj1.v_add(n);
            }

            cout<< "Set = ";
            obj1.Print();
        }
        else if (o==2){
            cout << "Enter the number of index :"<<endl;
            cin >> n;
            obj1.v_delete(n);
            cout<< "Set = ";
            obj1.Print();
        }
        else if (o==3){
            cout<<obj1.v_size()<<endl;
        }
        else if (o==4 ){
            cout << "Enter the item :"<<endl;
            cin >> n;
            if (obj1.is_exist(n)){
                cout << "the item " << n << " is exist"<<endl;
            }
            else {
                cout << "the item " << n << " isn't exist"<<endl;
            }
        } else if(o == 5) {
            return 0;
        }

    }

    return 0;
}
