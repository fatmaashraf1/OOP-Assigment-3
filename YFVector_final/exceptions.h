#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include <stdexcept>

using namespace std;

class outOfRange : public exception{
public:
    outOfRange() :errormsg{"Attempted to access OUT OF RANGE element"}{}
    string what(){return errormsg;}
private:
    string errormsg;
};

class noPop : public exception{
public:
    noPop():errormsg{"CAN'T pop, there are no elements in the Vector"}{}
    string what(){return errormsg;}
private:
    string errormsg;
};



#endif // EXCEPTIONS_H_INCLUDED
