#include "YFVector.h"


template<typename T>
YFVector<T>::YFVector() {
    arr = new T[1];
    _capacity = 1;
    _size= 0;
}
template<typename T>
YFVector<T>::YFVector(int n) {
    arr = new T[n];
    _capacity = n;
    _size= 0;
}

template<typename T>
YFVector<T>::~YFVector() {
    delete [] arr;
}

template<typename T>
T& YFVector<T>::operator[](int index) {
    try{
    if (index >= _size || index < 0)
        throw 0;
    return arr[index];
    }
    catch (int x){
        cout << "Index " << index <<" must be in interval [0," << _size << "]" << endl;
        return arr[0];
    }
}

template<typename T>
void YFVector<T>::push_back(T data) {
    if (_size == _capacity) {
        resize();
    }

    // Inserting data at end
    arr[_size] = data;
    _size++;
}



template<typename T>
T YFVector<T>::pop_back() {
    return arr[--_size];
}
template<typename T>
void YFVector<T>::clear(){
    int i = 0;
    while (i < _size){
        arr[i].~T();
        i++;
    }
    _size = 0;
}

template<typename T>
bool YFVector<T>::operator ==(const YFVector<T>& v) const {
    if( _size == v.size()){
        int i = 0;
        while (arr[i] == v.arr[i] && i < _size){
            i++;
        }
        if (i == _size)
            return true;
        return false;
    }
    return false;
}

template<typename T>
bool YFVector<T>::operator<(const YFVector<T>& v) const{
    if(arr[0] < v.arr[0])
        return true;
       return false;
}

template<typename T>
int YFVector<T>::resize() {
    T* temp = new T[2 * _capacity];

    // copying old array elements to new array
    for (int i = 0; i < _capacity; i++) {
        temp[i] = arr[i];
    }

    // deleting previous array
    delete[] arr;
    _capacity *= 2;
    arr = temp;

    return _capacity;
}


template<typename T>
int YFVector<T>::capacity() const{
    return _capacity;
}

template<typename T>
int YFVector<T>::size() const{
    return _size;
}
template<typename T>
bool YFVector<T>::empty(){
    if(_size == 0)
        return true;
    return false;
}
