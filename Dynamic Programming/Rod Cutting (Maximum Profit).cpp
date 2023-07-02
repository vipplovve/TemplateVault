#include <bits/stdc++.h>
using namespace std;

int RodCutting(int s, int w[], int v[], int c) //tabulation.
{
    vector<vector<int>> dp(s,vector<int>(c+1));

    for(int y = 0 ; y <= c ; y++)
        dp[0][y] = y*v[0];

    for(int x = 1 ; x < s ; x++)
        for(int y = 0 ; y <= c ; y++)
        {
            int left = dp[x-1][y];

            int stolen = (w[x]<=y)?(v[x] + dp[x][y-w[x]]):0;

            dp[x][y] = max(left,stolen);
        }

    return dp[s-1][c];
}

int RodCutting2(int s, int w[], int v[],int c, vector<vector<int>> &dp) //memoization.
{
    if(s==0)
        return c*v[0];

    if(dp[s][c]!=-1)
        return dp[s][c];

    int left = RodCutting2(s-1,w,v,c,dp);

    int stolen = (w[s]<=c)?(v[s] + RodCutting2(s,w,v,c-w[s],dp)):0;

    dp[s][c] = max(left,stolen);

    return dp[s][c];
}

int main()
{
    int size;
    cin>>size;

    int value[size], weight[size];

    for(int x = 0 ; x < size ; x++)
        weight[x]=x+1;
    
    for(int x = 0 ; x < size ; x++)
        cin>>value[x];
    
    cout<<"Maximum Profit From Selling Pieces of Rod of Length "<<size<<" is : ";

    // vector<vector<int>> dp(size,vector<int>(size+1,-1));

    // cout<<RodCutting2(size-1,weight,value,size,dp)<<endl;

    cout<<RodCutting(size,weight,value,size)<<endl;

    return 0;
}