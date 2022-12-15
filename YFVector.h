#include <bits/stdc++.h>


using namespace std;

template <class T>
class YFVector {
private:
    T* arr;
    int _capacity;
    int _size;

public:
   YFVector();
   YFVector(int);
   ~YFVector();
   void push_back(T);
   T pop_back();
   T& operator[](int);
   int size() const;
   int capacity() const;
   void clear();
   bool empty();
   int resize();
   bool operator==(const YFVector<T>&) const;
   bool operator<(const YFVector<T>&) const;


   friend ostream& operator << (ostream& out, YFVector<T>& vt){
        for (int i = 0; i < vt.size(); i++) {
            out << vt[i] << " ";
        }
        return out;
    }
};

