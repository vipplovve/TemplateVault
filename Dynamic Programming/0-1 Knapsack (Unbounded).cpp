#include <bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(int s, int w[], int v[], int c) //tabulation.
{
    vector<vector<int>> dp(s,vector<int>(c+1));

    for(int y = 0 ; y <= c ; y++)
        dp[0][y] = int((y/w[0]))*v[0];

    for(int x = 1 ; x < s ; x++)
        for(int y = 0 ; y <= c ; y++)
        {
            int left = dp[x-1][y];

            int stolen = (w[x]<=y)?(v[x] + dp[x][y-w[x]]):-1e9;

            dp[x][y] = max(left,stolen);
        }

    return dp[s-1][c];
}

int UnboundedKnapsack2(int s, int w[], int v[],int c, vector<vector<int>> &dp) //memoization.
{
    if(s==0)
        return (c/w[0])*v[0];

    if(dp[s][c]!=-1)
        return dp[s][c];

    int left = UnboundedKnapsack2(s-1,w,v,c,dp);

    int stolen = (w[s]<=c)?(v[s] + UnboundedKnapsack2(s,w,v,c-w[s],dp)):0;

    dp[s][c] = max(left,stolen);

    return dp[s][c];
}

int main()
{
    int size;
    cin>>size;

    int value[size], weight[size];

    for(int x = 0 ; x < size ; x++)
        cin>>weight[x];
    
    for(int x = 0 ; x < size ; x++)
        cin>>value[x];

    int cap;
    cin>>cap;
    
    cout<<"Maximum Value That Can Be filled in the Knapsack of Capacity "<<cap<<" is : ";

    // vector<vector<int>> dp(size,vector<int>(cap+1,-1));

    // cout<<UnboundedKnapsack2(size-1,weight,value,cap,dp)<<endl;

    cout<<UnboundedKnapsack(size,weight,value,cap)<<endl;

    return 0;
}