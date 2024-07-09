#include <bits/stdc++.h>
using namespace std;

long long Coins(int s, int t, int d[]) //tabulation.
{
    vector<vector<long long>> dp(s,vector<long long>(t+1));

    for(int x = 0 ; x <= t ; x++)
    {
        if(x%d[0]==0)
            dp[0][x] = 1;
        else
            dp[0][x] = 0;
    }

    for(int x = 1 ; x < s ; x++)
        for(int y = 0 ; y <= t ; y++)
        {
            int left = dp[x-1][y];

            int took = (y>=d[x])?dp[x][y-d[x]]:0;

            dp[x][y] = left + took;
        }

    return dp[s-1][t];
}

long long Coins2(int s, int t, int d[], vector<vector<int>> &dp) //memoization.
{
    if(!s)
        return (t%d[0]==0);

    if(dp[s][t]!=-1)
        return dp[s][t];

    int left = Coins2(s-1,t,d,dp);

    int took = (t>=d[s])?Coins2(s,t-d[s],d,dp):0;

    return dp[s][t] = left + took;
}

int main()
{
    int size,sum;
    cin>>size>>sum;

    int data[size];

    int zeroes = 0;

    for(int x = 0 ; x < size ; x++)
    {
        cin>>data[x];
        if(!data[x])
            zeroes++;
    }
    
    // cout<<zeroes;

    cout<<"No of Subsequences With Sum Equal to "<<sum<<" are : ";

    // vector<vector<int>> dp(size,vector<int>(sum+1,-1));

    // cout<<Coins2(size-1,sum,data,dp)<<endl;

    cout<<Coins(size,sum,data)<<endl;
    
    return 0;
}