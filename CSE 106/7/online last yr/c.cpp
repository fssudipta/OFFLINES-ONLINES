#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findOddOccurringElement(vector<int>& arr, int left, int right) {
        if (left == right) {
            return arr[left]; // Base case: odd element found
        }

        int mid = left + (right - left) / 2;

        // Check the pairing
        if (mid > 0 && arr[mid] == arr[mid - 1]) {
            // Pair starts at mid - 1
            if ((mid - 1) % 2 == 0) {
                // Pair is valid; search right
                return findOddOccurringElement(arr, mid + 1, right);
            } else {
                // Pair is invalid; search left
                return findOddOccurringElement(arr, left, mid - 2);
            }
        } else if (mid < arr.size() - 1 && arr[mid] == arr[mid + 1]) {
            // Pair starts at mid
            if (mid % 2 == 0) {
                // Pair is valid; search right
                return findOddOccurringElement(arr, mid + 2, right);
            } else {
                // Pair is invalid; search left
                return findOddOccurringElement(arr, left, mid - 1);
            }
        } else {
            // Odd element found
            return arr[mid];
        }
    }

    int findOddElement(vector<int>& arr) {
        return findOddOccurringElement(arr, 0, arr.size() - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.findOddElement(arr) << endl;

    return 0;
}
