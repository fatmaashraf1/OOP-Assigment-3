#include<bits/stdc++.h>
#include "exceptions.h"
using namespace std;

// Q8 Bonus Template stack class
template <class T>
class Stack {
private:
    T* arr;
    int _size{};
    int _top{};

public:
    // Parameterized Constructor
    explicit Stack(int _size);

    // Copy Constructor
    Stack(const Stack& other);

    // Copy Assignment
    Stack& operator=(const Stack& other);

    //Destructor
    ~Stack();

    // push() method: to add element to stack which can be any type
    void push(T k);

    // pop() method: to remove top element from stack
    T pop();

    // top() method: to print top element in stack
    T top();

    // isFull() method: to check whether stack is full
    bool isFull();

    // empty() method: to check whether stack is empty
    bool empty();

    // index[] operator: to return arr[index]
    T& operator[](int index);

    int get_top(){
        return _top;
    }

    friend ostream& operator << (ostream& out, Stack<T>& vt){
        for (int i = 0; i <= vt.get_top() ; i++) {
            out << vt[i] << " ";
        }
        return out;
    }


};

// Parametrized constructor to set a fixed size to stack
template <class T>
Stack<T>::Stack(int size): arr(new T[size]), _top(-1), _size(size) {}

template<class T>
Stack<T>::Stack(const Stack& other) {
    this->_top =other._top;
    this->_size = other._size;
    this->arr = new T[this->_size];
    for (int i = 0; i <= this->_top; ++i) {
        this->arr[i] = other.arr[i];
    }
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack &other) {

    // Self-Assignment Check
    if (this == &other){
        return *this;
    }
    // Assign Variables
    this->_size= other._size;
    this->_top= other._top;

    // Delete old dynamic array (this)
    delete [] this->arr;

    // Create new one (this) with new assigned size (other.size)
    this->arr = new T[this->_size];

    // Copy the old one (other) to new one (this)
    for (int i = 0; i <= this->_top; ++i) {
        this->arr[i] = other.arr[i];
    }
    return *this;
}
template <class T>
Stack<T>::~Stack() {
    delete [] arr;
}

template <class T>
bool Stack<T>::isFull()
{
    if (_top == (_size - 1))
        return true;
    else
        return false;
}


// To add elements to stack
template <class T>
void Stack<T>::push(T k)
{
    // Exception occurred if stack is full (Overflow)
    if (isFull()) {
        throw StackOverflow();
    }
    // Incrementing the top by unit
    _top++;

    // Adding element to stack
    arr[_top] = k;
}

// Index operator overloading
template<class T>
T& Stack<T>::operator[](int index){
    if(index > _top || index < 0)
        throw outOfRange();
    else
        return arr[index];
}


template <class T>
bool Stack<T>::empty()
{
    if (_top == -1)
        return true;
    else
        return false;
}



template <class T>
T Stack<T>::pop()
{
    T popped_element = arr[_top];

    if (empty()){
        throw StackEmptyException();
    }
    else{
        _top--;
        return popped_element;
    }

}

template <class T>
T Stack<T>::top()
{
    T top_element = arr[_top];
    return top_element;
}

int main()
{

    Stack<int> stack1_integer(4);
    Stack<string> stack2_string(4);


    // Adding to integer stack
    stack1_integer.push(2);
    stack1_integer.push(54);
    stack1_integer.push(255);

    // Adding to string stack
    stack2_string.push("Welcome");
    stack2_string.push("to");
    stack2_string.push("OOP");

    cout << stack1_integer << endl;
    cout << stack2_string << endl;

    // Test Copy Assignment
    Stack<int> stack3(3);
    stack3 = stack1_integer;
    cout << "\n" << stack3 << endl;

    // Test Copy Constructor
    Stack<string> stack4= stack2_string;
    cout << stack4 << "\n" << endl;

    cout << stack1_integer.pop() << " is removed from integer stack" << endl;
    cout << stack2_string.pop() << " is removed from string stack " << endl;
    cout << "Top element is " << stack1_integer.top() << endl;
    cout << "Top element is " << stack2_string.top() << endl;


    //// Test exceptions
    try{
        stack3.push(55);
        stack3.push(66);
    }catch(StackOverflow& no_push){
        cout << "Exception occurred: " << no_push.what() << endl;
    }

    try{
        stack2_string.pop();
        stack2_string.pop();
        stack2_string.pop();
        stack2_string.pop();
    }catch(StackEmptyException& empty){
        cout << "Exception occurred: " << empty.what() << endl;
    }


    return 0;
}
