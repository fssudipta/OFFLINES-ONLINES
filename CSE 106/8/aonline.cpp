#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int w, n;
    cin>>w>>n;
    vector<int> weight(n);
    vector<int> price(n);
    for(int i=0; i<n; i++)
    {
        cin>>weight[i]>>price[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(i-j>1 ||j-i>1) 
            {
                if(weight[i-1]<=w)
                dp[i][j]=max(dp[i-1][j], price[i-1]+dp[i-1][w-weight[i-1]]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}