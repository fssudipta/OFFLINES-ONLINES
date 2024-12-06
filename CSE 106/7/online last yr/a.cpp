#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakHelper(vector<int>& arr, int low, int high) {
        int mid = low + (high - low) / 2;

        // Base Case: Single element is always a peak
        if (low == high) return arr[low];

        // Check if mid is a peak
        bool leftCheck = (mid == 0 || arr[mid - 1] <= arr[mid]);
        bool rightCheck = (mid == arr.size() - 1 || arr[mid + 1] <= arr[mid]);

        if (leftCheck && rightCheck) return arr[mid];

        // Move to the side with the greater neighbor
        if (mid > 0 && arr[mid - 1] > arr[mid]) {
            return findPeakHelper(arr, low, mid - 1);
        } else {
            return findPeakHelper(arr, mid + 1, high);
        }
    }

    int findPeakElement(vector<int>& arr) {
        return findPeakHelper(arr, 0, arr.size() - 1);
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
    cout << sol.findPeakElement(arr) << endl;

    return 0;
}
