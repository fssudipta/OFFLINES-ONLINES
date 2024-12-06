#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxTripletSumHelper(vector<int>& arr, int left, int right) {
        // Base Case: If the size of the segment is less than 3, return INT_MIN
        if (right - left + 1 < 3) {
            return INT_MIN;
        }
        // Base Case: If exactly 3 elements, return their sum
        if (right - left + 1 == 3) {
            return arr[left] + arr[left + 1] + arr[left + 2];
        }

        // Find mid
        int mid = left + (right - left) / 2;

        // Divide and conquer
        int leftMax = maxTripletSumHelper(arr, left, mid);
        int rightMax = maxTripletSumHelper(arr, mid + 1, right);

        // Crossing triplet (last two of left + first of right)
        int crossMax = INT_MIN;
        if (mid - 1 >= left && mid + 1 <= right) {
            crossMax = arr[mid - 1] + arr[mid] + arr[mid + 1];
        }

        // Return the maximum of left, right, and crossing sums
        return max({leftMax, rightMax, crossMax});
    }

    int maxTripletSum(vector<int>& arr) {
        return maxTripletSumHelper(arr, 0, arr.size() - 1);
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
    cout << sol.maxTripletSum(arr) << endl;

    return 0;
}
