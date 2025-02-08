#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << hex << 100 << endl;

    cout << setfill('?') << setw(10) << 2343.0 << endl;

    cout << setiosflags(ios::showpos);
    cout << setiosflags(ios::showbase);
    cout << 123 << " " << hex << 123 << endl;

    bool b;
    b = true;
    cout << b << " " << boolalpha << b << endl;

    cout << "Enter a Boolean value: ";
    cin >> boolalpha >> b;
    cout << "Here is what you entered: " << b << endl;

    return 0;
}
