#include <iostream>
using namespace std;

template <class AType = int, int size = 10>
class atype
{
    AType a[size]; // size of array is passed in size
public:
    atype()
    {
        register int i;
        for (i = 0; i < size; i++)
            a[i] = i;
    }
    AType &operator[](int i);
};

template <class AType, int size>
AType &atype<AType, size>::operator[](int i)
{
    if (i < 0 || i >= size)
    {
        cout << "\nIndex value of " << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}

int main()
{
    atype<int, 5> intarray;  // integer array, size 100
    atype<double> doublearray; // double array, default size
    atype<> defarray;          // default to int array of size 10
    int i;

    cout << "int array: ";
    for (i = 0; i < 5; i++)
        intarray[i] = i;
    for (i = 0; i < 5; i++)
        cout << intarray[i] << "  ";
    cout << '\n';

    cout << "double array: ";
    for (i = 0; i < 5; i++)
        doublearray[i] = (double)i / 3;
    for (i = 0; i < 5; i++)
        cout << doublearray[i] << "  ";
    cout << '\n';

    cout << "defarray array: ";
    for (i = 0; i < 5; i++)
        defarray[i] = i;
    for (i = 0; i < 5; i++)
        cout << defarray[i] << "  ";
    cout << '\n';

    return 0;
}
