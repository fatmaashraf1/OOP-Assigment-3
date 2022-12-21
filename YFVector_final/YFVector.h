#ifndef YFVECTOR_H_INCLUDED
#define YFVECTOR_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;


template <class T>
class YFVector {
    T* arr;
    size_t _capacity{};
    size_t _size{};
    void copyInternalData(const YFVector&);                   // to copy internal data (can't be used by the client)

public:
    // Constructors and big 4
    YFVector();                                               // default constructor
    explicit YFVector(int);                                   // Parametrized constructor (capacity)
    YFVector(T*, int);                                        // Initialize parametrized constructor (array,size)
    YFVector(const YFVector&);                                // Copy constructor
    ~YFVector();                                              // destructor
    YFVector &operator= (const YFVector&);                    // Copy assignment
    YFVector &operator= (YFVector&&) noexcept ;               // Move assignment

    //Access Operations
    T& operator[](int);                                       // [] with    outOfBound Check

    // Iterator class
    class iterator;                                           // declaring iterator class

    // Modifying operations
    void push_back(T);                                        // push_back
    T pop_back();                                             // pop_back
    void erase(iterator);
    void erase(iterator, iterator);
    void clear();                                             // clear
    void insert(iterator, T const&);

    // Iterators
    iterator begin();                                         // iterator begin
    iterator end();                                           // iterator end

    // Comparison operations
    bool operator== (const YFVector<T>&) const;               // == operator
    bool operator<(const YFVector<T>&) const;                 // < operator

    // Capacity Operations

    int size() const;                                         // get_size
    int capacity() const;                                     // get_capacity
    int resize();                                             // resize
    bool empty() const;                                       // empty

    // Friends
    friend ostream& operator << (ostream& out, YFVector<T>& vt){
        for (int i = 0; i < vt.size(); i++) {
            out << vt[i] << " ";
        }
        return out;
    }



};



#endif // YFVECTOR_H_INCLUDED
