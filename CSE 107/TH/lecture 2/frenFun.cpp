#include <iostream>
using namespace std;

class MyClass {
    int a; // private member
public:
    MyClass(int a1) : a(a1) {}
    friend void ff1(MyClass obj);
};

// friend keyword not used 
void ff1(MyClass obj) {
    cout << obj.a << endl;
    MyClass obj2(100);
    cout << obj2.a << endl;
}

int main() {
    MyClass o1(10);
    ff1(o1);
    return 0;
}
