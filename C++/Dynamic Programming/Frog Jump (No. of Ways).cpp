#include <bits/stdc++.h>
using namespace std;

long long jump(int n) //tabulation.
{
    long long dp[n];

    dp[0]=dp[1]=1;

    for(int x = 2 ; x <= n ; x++)
        dp[x]=dp[x-1]+dp[x-2];
    
    return dp[n];
}

long long jump2(int n, vector<long long> &dp) //memoization.
{
    if(n<=1)
        return 1;

    if(dp[n])
        return dp[n];
    
    else
        dp[n] = jump2(n-1,dp) + jump2(n-2,dp);
    
    return dp[n];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
{    
    //cout<<"Enter the Stair you wish to reach: ";
    long long stair;
    cin>>stair;

    // vector<long long> dp(86); 

    // cout<<"No. of possible ways are : "<<jump2(stair,dp)<<endl;

    cout<<"No. of possible ways are : "<<jump(stair)<<endl;
}
    return 0;
}