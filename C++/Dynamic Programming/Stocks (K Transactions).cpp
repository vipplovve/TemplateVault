#include <bits/stdc++.h>
using namespace std;

long long StocksKTransactions(int d[], int s, int k) //tabulation.
{
    vector<vector<vector<int>>> dp (s+1, vector<vector<int>> (2,vector<int> (k+1,-1)));

    for(int x = 0 ; x < k+1; x++)
    {
        dp[s][0][x] = 0;
        dp[s][1][x] = 0;
    }

    for(int x = 0 ; x < s ; x++)
    {
        dp[x][0][0] = 0;
        dp[x][1][0] = 0;
    }

    for(int x = s - 1 ; x > -1 ; x--)
        for(int y = 0 ; y < 2 ; y++)
            for(int z = 1 ; z < k + 1 ; z++)
            {
                if(!y)
                    dp[x][y][z] = max(dp[x+1][y][z] , -d[x] + dp[x+1][!y][z]);
                else
                    dp[x][y][z] = max(d[x] + dp[x+1][!y][z-1] , dp[x+1][y][z]);
            }

    return dp[0][0][k];
}

long long StocksKTransactions2(int d[], int i, int s, int state,int k, vector<vector<vector<int>>> &dp) //memoization.
{
    if(i == s || k == 0)
        return 0;

    if(dp[i][state][k] != -1)
        return dp[i][state][k];

    if(state == 1)
        return dp[i][state][k] = max(StocksKTransactions2(d,i+1,s,state,k,dp), -d[i] + StocksKTransactions2(d,i+1,s,!state,k,dp));

    else
        return dp[i][state][k] = max(d[i] + StocksKTransactions2(d,i+1,s,!state,k-1,dp),StocksKTransactions2(d,i+1,s,state,k,dp));
}

int main()
{
    int days;

    cin>>days;

    int data[days];

    for(int x = 0 ; x < days ; x++)
        cin>>data[x];

    int k;
    cin>>k;

    cout<<"Max Profit That Can Be Generated is : ";

    // vector<vector<vector<int>>> dp(days, vector<vector<int>> (2,vector<int> (k+1,-1)));

    // cout<<StocksKTransactions(data,0,days,1,k,dp)<<endl;

    cout<<StocksKTransactions(data,days,k)<<endl;

    cout<<"(Considering we may do atmost "<<k<<" Transactions)."<<endl;

    return 0;
}