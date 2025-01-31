#include <iostream>
#include <cstring>
using namespace std;

class strtype
{
    char *p;
    int len;

public:
    strtype(char *s)
    {
        len = strlen(s) + 1;
        p = new char[len];
        strcpy(p, s);
    }
    ~strtype()
    {
        delete[] p;
    }
    strtype &operator=(const strtype &ob);
    char *getP() { return p; } // Function to access p
};

// Assignment operator
strtype &strtype::operator=(const strtype &ob)
{
    if (len < ob.len)
    {
        delete[] p;
        p = new char[ob.len];
    }
    len = ob.len;
    strcpy(p, ob.p);
    return *this;
}

int main()
{
    strtype s1("BUET"), s2("CSE");
    s1 = s2;                             // no problem
    cout << "s1: " << s1.getP() << endl; // Accessing p using getP()
    cout << "s2: " << s2.getP() << endl; // Accessing p using getP()
    return 0;
}
