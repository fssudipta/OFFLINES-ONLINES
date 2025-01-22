#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void square(int &n);
void print(int &n);

int main()
{
    vector<int> v;
    v.push_back(11);
    v.push_back(3);
    v.push_back(4);
    v.push_back(22);

    // Invoke the given function (print, square)
    // for each element in the range
    for_each(v.begin(), v.end() - 1, print);
    cout << endl;
    for_each(v.begin() + 1, v.begin() + 3, square);
    for_each(v.begin(), v.end(), print);
    cout << endl;

    return 0;
}

void square(int &n) { n *= n; }
void print(int &n) { cout << n << " "; }
