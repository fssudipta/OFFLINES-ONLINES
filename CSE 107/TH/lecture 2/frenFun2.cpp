#include <iostream>
using namespace std;

class YourClass; // a forward declaration

class MyClass
{
    int a; // private member
public:
    MyClass(int a1) : a(a1) {}
    friend int compare(MyClass obj1, YourClass obj2);
};

class YourClass
{
    int a; // private member
public:
    YourClass(int a1) : a(a1) {}
    friend int compare(MyClass obj1, YourClass obj2);
};

int compare(MyClass obj1, YourClass obj2)
{
    return (obj1.a - obj2.a);
}

int main()
{
    MyClass o1(10);
    YourClass o2(5);
    int n = compare(o1, o2); // n = 5
    cout << "Comparison result: " << n << endl;
    return 0;
}
