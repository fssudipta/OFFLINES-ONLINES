#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> lst; // create an empty list
    int i;
    for (i = 0; i < 10; i++)
        lst.push_back(i);

    cout << "Size = " << lst.size() << endl;
    cout << "Contents: ";
    list<int>::iterator p = lst.begin();
    while (p != lst.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    // change contents of list
    p = lst.begin();
    while (p != lst.end())
    {
        *p = *p + 100;
        p++;
    }

    cout << "Contents modified: ";
    p = lst.begin();
    while (p != lst.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    return 0;
}
