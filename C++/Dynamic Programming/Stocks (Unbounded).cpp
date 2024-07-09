#include <bits/stdc++.h>
using namespace std;

long long StocksCCooldown(int d[], int s,int c) //tabulation.
{
    vector<vector<int>> dp (s+1, vector<int> (2,0));

    dp[s][0] = 0;
    dp[s][1] = 1;

    for(int x = s - 1 ; x > -1 ; x--)
        for(int y = 0 ; y < 2 ; y++)
        {
            if(!y)
                dp[x][y] = max(dp[x+1][0],dp[x+1][1] - d[x]);
            else
                dp[x][y] = max(d[x] + dp[x+c+1][0], dp[x+1][1]);
        }

    return dp[0][0];
}

long long StocksCCooldown2(int d[], int i, int s, int state,int m, vector<vector<int>> &dp) //memoization.
{
    if(i == s)
        return 0;

    if(dp[i][state] != -1)
        return dp[i][state];

    if(state == 0)
        return dp[i][state] = max(StocksCCooldown2(d,i+1,s,0,m,dp), -d[i] + StocksCCooldown2(d,i+1,s,1,m,dp));

    else
        return dp[i][state] = max(d[i] + StocksCCooldown2(d,i+m+1,s,0,m,dp),StocksCCooldown2(d,i+1,s,1,m,dp));
}

int main()
{
    int days;

    cin>>days;

    int data[days];

    for(int x = 0 ; x < days ; x++)
        cin>>data[x];

    int m;
    cin>>m;

    cout<<"Max Profit That Can Be Generated is : ";

    // vector<vector<int>> dp(days, vector<int>(2,-1));

    // cout<<StocksCCooldown2(data,0,days,0,m,dp)<<endl;

    cout<<StocksCCooldown(data,days,m)<<endl;

    cout<<"(Considering we may do any number of transactions)."<<endl;

    return 0;
}