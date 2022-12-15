#include "YFVector.cpp"
#include <bits/stdc++.h>


using namespace std;
int main()
{
    YFVector<char> v1;
    YFVector<int> v2;
    YFVector<int> v3(4);

    v1.push_back('c');
    v1.push_back('a');
    v1.push_back('t');
    v1.push_back('s');

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);

    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);

    cout << "-------------------------------------------"<< endl;
    cout << "Compare between v2 == v3 : "<< ((v2 == v3) ? "True" : "False") << endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V2[2]Operator Before: " << v2[2] <<endl;
    v2[2] = 4;
    cout << "V2[2]Operator After: " << v2[2] <<endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V1 size: " << v1.size() << endl;
    cout << "V1 capacity: " << v1.capacity() << endl;
    cout << "V2 size: " << v2.size() << endl;
    cout << "V2 capacity: " << v2.capacity() << endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V1 elements: "<< v1 << endl;
    cout << "-------------------------------------------"<< endl;
    cout << "V2 elements: "<< v2 << endl;


    int x = v2.pop_back();
    char c = v1.pop_back();

    cout << "-------------------------------------------"<< endl;
    cout << "After deleting last element" << endl;
    cout << "Last elements are deleted:" << endl;

    cout << x << " " << c << endl;

    cout << "V1 size: " << v1.size() << endl;
    cout << "V2 capacity: " << v2.capacity() << endl;
    cout << "V2 size: " << v2.size() << endl;
    cout << "V1 capacity: " << v1.capacity() << endl;

    cout << "-------------------------------------------"<< endl;
    // V2 elements after pop_back
    cout << "V2 elements: ";
    cout << v2 << endl;
    cout << "-------------------------------------------"<< endl;
    // Access element out of bounds test
    v2[6] = 4;
    cout << "-------------------------------------------"<< endl;

    // Clear test
    v1.clear();
    cout << "V1 is " << ((v1.empty()) ? "empty": "NOT empty") << endl;

    YFVector<int> v4(3);
    YFVector<int> v5(3);

    v4.push_back(8);
    v4.push_back(4);
    v4.push_back(2);

    v5.push_back(6);
    v5.push_back(4);
    v5.push_back(2);
    cout << "-------------------------------------------"<< endl;
    cout << (v4 < v5);


    return 0;
}
