#include <iostream>
using namespace std;

inline void increment(int n)
{
    n = n + 1;
}

inline void set(int x, int y)
{
    x = y;
}

int main()
{
    int n = 10;
    increment(n);
    cout << n<<endl;
    int a=3, b=5;
    set(a, b);
    cout<<a<<" "<<b<<endl;
    return 0;
}