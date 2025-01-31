#include <iostream>
#include <cstring>
using namespace std;

class MyArray
{
    int a[3];

public:
    MyArray()
    {
        for (int i = 0; i < 3; i++)
            a[i] = i;
    }
    int &operator[](int i)
    {
        return a[i];
    }
    int operator[](const char *s);
};

int MyArray::operator[](const char *s)
{
    if (strcmp(s, "zero") == 0)
        return a[0];
    else if (strcmp(s, "one") == 0)
        return a[1];
    else if (strcmp(s, "two") == 0)
        return a[2];
    return -1;
}

int main()
{
    MyArray ob;
    cout << ob[1] << endl;     // 1
    cout << ob["two"] << endl; // 2
    ob[0] = 5;                 // Now this works
    cout << ob[0] << endl;     // 5
    return 0;
}
