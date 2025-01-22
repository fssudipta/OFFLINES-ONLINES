#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    vector<char> v(10); // create a vector of length 10
    int i = 0;

    // assign elements in vector a value
    for (auto p = v.begin(); p != v.end(); ++p) {
        *p = i + 'a';
        i++;
    }

    // display contents of vector
    cout << "Original contents:\n";
    for (auto p = v.begin(); p != v.end(); ++p) {
        cout << *p << " ";
    }
    cout << "\n\n";

    return 0;
}
