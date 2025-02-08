#include <iostream>
#include <string>
using namespace std;

int main() {
    int i;
    string s1 = "Quick of Mind, Strong of Body, Pure of Heart"; // Original string
    string s2; // Empty string to store the result

    // Find the first occurrence of the substring "Quick"
    i = s1.find("Quick");
    if (i != string::npos)  // Check if the substring is found
        cout << "Match found at " << i << endl; // Print position of the match

    // Find the last occurrence of the substring "of"
    i = s1.rfind("of");
    if (i != string::npos) {
        cout << "Match found at " << i << endl; // Print position of the match
        cout << "Remaining string is:\n";

        // Extract substring starting from position `i` to the end of the string
        s2.assign(s1, i, s1.size());
        cout << s2; // Print the extracted substring
    }

    return 0;
}
