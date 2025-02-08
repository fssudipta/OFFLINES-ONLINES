#include <iostream>
using namespace std;

int main(){
    // Set showpoint and showpos
    cout.setf(ios::showpoint);  // Force decimal point to show
    cout.setf(ios::showpos);    // Force positive numbers to show +
    cout << 100.0 << "\n";      // Expected output: +100.000 (shows + and decimal point)

    // Set uppercase and scientific
    cout.setf(ios::uppercase | ios::scientific); 
    cout << 100.12 << "\n";     // Expected output: 1.001200E+02 (scientific and uppercase E)

    // Unset uppercase flag
    cout.unsetf(ios::uppercase); 
    cout << 100.12 << "\n";     // Expected output: 1.001200e+02 (scientific with lowercase e)

    // Unset flags and adjust precision and width
    cout.unsetf(ios::showpos | ios::uppercase | ios::scientific);
    cout.precision(5);          // Set precision to 4 significant digits
    cout.width(10);             // Set field width to 10
    cout << 10.12345 << "\n";   // Expected output:     10.1235 (4 significant digits)

    // Set fill character and display again
    cout.fill('*');             // Set fill character to '*'
    cout.width(10);             // Set field width to 10 again
    cout << 10.12345 << "\n";   // Expected output: *****10.1235 (padded with '*' to the left)

    // Field width applies to strings too
    cout.width(10); 
    cout << "Hi!" << "\n";      // Expected output: *******Hi! (padded with '*' to the left)

    // Left justify and display
    cout.width(10);
    cout.setf(ios::left);       // Left-justify
    cout << 10.12345;           // Expected output: 10.1235*** (left-justified, padding with *)

    return 0;
}
