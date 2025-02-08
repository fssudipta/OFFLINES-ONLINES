#include <iostream>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
    list<double> vals;
    
    // Put values into the list
    for (int i = 1; i < 10; i++)  
        vals.push_back((double)i);

    cout << "Original contents of vals:\n";
    for (double val : vals)  
        cout << val << " ";

    cout << endl;

    // Use the negate function object
    list<double> result(vals.size()); // Create a separate list for output
    transform(vals.begin(), vals.end(), result.begin(), negate<double>());

    cout << "Negated contents of vals:\n";
    for (double val : result)  
        cout << val << " ";

    return 0;
}
