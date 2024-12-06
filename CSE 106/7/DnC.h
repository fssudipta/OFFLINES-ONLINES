#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int CSS(const vector<int> &arr, int l, int m, int r, int &cStart, int &cEnd)
{
    // maintaining the ref to cstart and cend
    int sum = 0;
    int lSum = INT_MIN;
    int tStart = m;
    // mid to left->sum, max sum
    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > lSum)
        {
            // store the max left sum
            lSum = sum;
            tStart = i;
        }
    }
    sum = 0;
    int rSum = INT_MIN;
    int tEnd = m;
    // mid to right->sum, max sum
    for (int i = m; i <= r; i++)
    {
        sum += arr[i];
        if (sum > rSum)
        {
            // store the max right sum
            rSum = sum;
            tEnd = i;
        }
    }
    // max sum found? set cStart cEnd
    cStart = tStart;
    cEnd = tEnd;
    // max cross subarray from the pivot
    return max(lSum + rSum - arr[m], max(lSum, rSum));
}

int Streak(const vector<int> &arr, int l, int r, int &start, int &end)
{
    if (l > r) // base case...invalid range
        return INT_MIN;
    if (l == r)
    {
        // single elem case
        start = end = l;
        return arr[l];
    }
    int m = (l + r) / 2; // mid point update
    // will divide this array into 2 halves, then i'll keep calling them recursively to find maxsum in the subarray
    int lStart, lEnd, rStart, rEnd, cStart, cEnd;
    int lSum = Streak(arr, l, m - 1, lStart, lEnd);
    int rSum = Streak(arr, m + 1, r, rStart, rEnd);
    int cSum = CSS(arr, l, m, r, cStart, cEnd);
    if (lSum == max(lSum, max(cSum, rSum)))
    {
        start = lStart;
        end = lEnd;
        return lSum;
    }
    else if (rSum == max(rSum, max(cSum, lSum)))
    {
        start = rStart;
        end = rEnd;
        return rSum;
    }
    else
    {
        start = cStart;
        end = cEnd;
        return cSum;
    }
}

void printSubArray(const vector<int> &arr)
{
    int start, end;
    int max = Streak(arr, 0, arr.size() - 1, start, end);
    cout << "[";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i];
        if (i < end)
            cout << ", ";
    }
    cout << "] with a sum of " << max << endl;
}
