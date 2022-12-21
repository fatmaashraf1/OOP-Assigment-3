#ifndef YFVECTOR_H_INCLUDED
#define YFVECTOR_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;


template <class T>
class YFVector {
    T* arr;
    size_t _capacity{};
    size_t _size{};

public:
   YFVector();                                               // default constructor
   explicit YFVector(int);                                   // overloaded 1
   YFVector(T*, int);                                        // overloaded 2
   YFVector(const YFVector&);                                // Copy constructor
   ~YFVector();                                              // destructor
   YFVector &operator= (const YFVector&);                    // Copy assignment
   YFVector &operator= (YFVector&&) noexcept ;                // Move assignment
   T& operator[](int);                                       // [] with    outOfBound Check
   void push_back(T);                                        // push_back
   T pop_back();                                             // pop_back
   int size() const;                                         // get_size
   int capacity() const;                                     // get_capacity
   void clear();                                             // clear
   class iterator;                                           // declaring iterator class
   iterator begin();                                         // iterator begin
   iterator end();                                           // iterator end
   bool operator== (const YFVector<T>&) const;               // == operator
   bool operator<(const YFVector<T>&) const;                 // < operator
   bool empty() const;                                       // empty
   void erase(iterator);
   void erase(iterator, iterator);
   void insert(iterator, T const&);
   void copyInternalData(const YFVector&);
   int resize();


   friend ostream& operator << (ostream& out, YFVector<T>& vt){
        for (int i = 0; i < vt.size(); i++) {
            out << vt[i] << " ";
        }
        return out;
    }
};



#endif // YFVECTOR_H_INCLUDED
