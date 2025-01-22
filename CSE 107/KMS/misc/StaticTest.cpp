#include <iostream>
using namespace std;

class StaticTest
{
    static int i;
    // declaring it, not defining it

public:
    void seti(int n) { i = n; }
    int geti() { return i; }
    static int getVal() { return i; }
};

int StaticTest::i; // defining it, without this, the linked won't find the static memeber variable, gives a linker error
// this line ensures that there is a single instance of the static member variable i
// that is shared among all instances of the StaticTest class.

int main()
{
    StaticTest s1, s2;
    s1.seti(30);
    cout << s2.geti() << endl;
    cout << s1.getVal() << endl;
    cout << StaticTest::getVal() << endl;
    return 0;
}
