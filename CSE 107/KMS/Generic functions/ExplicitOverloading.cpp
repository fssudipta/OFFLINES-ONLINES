#include <iostream>
using namespace std;

template <class X>
void swapargs(X &a, X &b) {
    X temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Inside template swapargs.\n\n";
}

void swapargs(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Inside swapargs int specialization.\n\n";
}

int main() {
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'z';

    cout << "Original i, j: " << i << ' ' << j << endl;
    cout << "Original x, y: " << x << ' ' << y << endl;
    cout << "Original a, b: " << a << ' ' << b << endl<<endl;

    swapargs(i, j); // calls explicitly overloaded swapargs()
    swapargs(x, y); // calls generic swapargs()
    swapargs(a, b); // calls generic swapargs()

    cout << "Swapped i, j: " << i << ' ' << j << '\n';
    cout << "Swapped x, y: " << x << ' ' << y << '\n';
    cout << "Swapped a, b: " << a << ' ' << b << endl<<endl;

    return 0;
}
