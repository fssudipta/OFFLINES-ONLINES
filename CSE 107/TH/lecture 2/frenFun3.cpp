#include <iostream>
using namespace std;

class YourClass; // a forward declaration

class MyClass
{
    int a; // private member
public:
    MyClass(int a1) : a(a1) {}
    int compare(YourClass obj);
};

class YourClass
{
    int a; // private member
public:
    YourClass(int a1) : a(a1) {}
    friend int MyClass::compare(YourClass obj);
};

int MyClass::compare(YourClass obj)
{
    return (a - obj.a);
}

int main()
{
    MyClass o1(10);
    YourClass o2(5);
    int n = o1.compare(o2); // n = 5
    cout << "Comparison result: " << n << endl;
    return 0;
}
