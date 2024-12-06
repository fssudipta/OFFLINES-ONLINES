#include <iostream>
#include <vector>
#include "DnC.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printSubArray(arr);
    return 0;
}
