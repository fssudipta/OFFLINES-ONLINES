#include <iostream>
#include <vector>
#include <string>
#define MAX_LEN 120
using namespace std;

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> dp(p.length() + 1, 0);
    dp[0] = 1; // empty pattern==empty test case
    // checkin the cases where 0 occurences are there for *, standalone * arki
    for (int j = 1; j < p.length(); j++)
    {
        if (p[j] == '*' && dp[j - 1])
        {
            dp[j + 1] = 1;
        }
    }
    // general case
    for (int i = 1; i <= t.length(); i++)
    {
        int prev = dp[0];
        dp[0] = 0; //not an empty pattern thats why
        for (int j = 1; j <= p.length(); j++)
        {
            int temp = dp[j];
            //. matched any char || direct character match (basically . is like a wildcard)
            if (p[j - 1] == '.' || t[i - 1] == p[j - 1])
            {
                dp[j] = prev;
            }
            // * 0 or more occurences
            else if (p[j - 1] == '*')
            {
                // dp[j-2] to skip * and the preceding character, 0 occ.
                // 0 occ. *? character match? . match?
                dp[j] = dp[j - 2] || (dp[j] && (t[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            // at least one match
            // then go for the next matching elems by dp[j-1]
            else if (p[j - 1] == '+')
            {
                dp[j] = (t[i - 1] == p[j - 2] || p[j - 2] == '.') && (dp[j - 1] || dp[j]);
            }
            else
            {
                dp[j] = 0; // match nai
            }
            prev = temp; // update
        }
    }
    cout << (dp[p.length()] ? "True" : "False") << endl;
    return 0;
}


