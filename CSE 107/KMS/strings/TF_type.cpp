#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> directory;

    // put names and numbers into map
    directory.insert(pair<string, string>("Tom", "555-4533"));
    directory.insert(pair<string, string>("Chris", "555-9678"));
    directory.insert(pair<string, string>("John", "555-8195"));
    directory.insert(pair<string, string>("Rachel", "555-0809"));

    string s;
    cout << "Enter name: ";
    cin >> s;

    map<string, string>::iterator p;
    p = directory.find(s);
    if (p != directory.end())
        cout << "Phone number: " << p->second;
    else
        cout << "Name not in directory\n";

    return 0;
}
