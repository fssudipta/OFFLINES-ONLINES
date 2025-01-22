#include <iostream>
using namespace std;

//const int SIZE = 10;

template <class AType, int size>
class atype {
    AType a[size]; // length of array is passed in size
public:
    atype() {
        register int i;
        for (i = 0; i < size; i++)
            a[i] = i;
    }
    AType& operator[](int i);
};

// Provide range checking for atype.
template <class AType, int size>
AType& atype<AType, size>::operator[](int i) {
    if (i < 0 || i >= size) {
        cout << "\nIndex value of " << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}

int main() {
    atype<int, 10> intob; // integer array of size 10
    atype<double, 15> doubleob; // double array of size 15
    int i;

    cout << "Integer array: ";
    for (i = 0; i < 10; i++)
        intob[i] = i;
    for (i = 0; i < 10; i++)
        cout << intob[i] << "  ";
    cout << '\n';

    cout << "Double array: ";
    for (i = 0; i < 15; i++)
        doubleob[i] = (double)i / 3;
    for (i = 0; i < 15; i++)
        cout << doubleob[i] << "  ";
    cout << '\n';

    intob[12] = 100; // generates runtime error

    return 0;
}
