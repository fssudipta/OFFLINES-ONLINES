#include <iostream>
using namespace std;

class myClass
{
    int a;
    public:
    myClass(int n);
    void set_a(int n);
    int get_a();
};

inline void myClass::set_a(int n)
{
    a = n;
}

inline int myClass::get_a()
{
    return a;
}

myClass::myClass(int n)
{
    a = n;
}

int main()
{
    myClass obj(10);
    obj.set_a(20);
    cout << obj.get_a() << endl;
    return 0;
}