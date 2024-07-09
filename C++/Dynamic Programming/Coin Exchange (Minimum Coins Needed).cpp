#include <bits/stdc++.h>
using namespace std;

int CoinsNeeded(int s, int c[], int t) //tabulation.
{
    vector<vector<int>> dp(s,vector<int>(t+1));

    for(int x = 0 ; x <= t ; x++)
    {
        if(x%c[0]==0)
            dp[0][x] = x/c[0];
        else
            dp[0][x] = 1e9;
    }

    for(int x = 1 ; x < s ; x++)
        for(int y = 0 ; y <= t ; y++)
        {
            int left = dp[x-1][y];

            int took = (c[x]<=y)?(1 + dp[x][y-c[x]]):1e9;

            dp[x][y] = min(left,took);
        }

    return dp[s-1][t];
}

int CoinsNeeded2(int s, int c[], int t, vector<vector<int>> &dp) //memoization.
{
    if(!s)
    {
        if(t%c[0]==0)
            return t/c[0];
        else
            return 1e9;
    }
    
    if(dp[s][t]!=-1)
        return dp[s][t];

    int left = CoinsNeeded2(s-1,c,t,dp);

    int took = (c[s]<=t)?(1 + CoinsNeeded2(s,c,t-c[s],dp)):1e9;

    return dp[s][t] = min(left,took);
}

int main()
{
    int size;
    cin>>size;

    int coins[size];

    for(int x = 0 ; x < size ; x++)
        cin>>coins[x];

    int sum;
    cin>>sum;
    
    cout<<"Minimum Coins Needed to Get a Sum of "<<sum<<" are : ";
    // vector<vector<int>> dp(size,vector<int>(sum+1,-1));

    // cout<<CoinsNeeded2(size-1,coins,sum,dp)<<endl;

    cout<<CoinsNeeded(size,coins,sum)<<endl;

    return 0;
}