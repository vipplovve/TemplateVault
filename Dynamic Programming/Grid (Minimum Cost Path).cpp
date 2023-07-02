#include <bits/stdc++.h>
using namespace std;

long long MazeCost(int r, int c, vector<vector<long long>> grid) //tabulation.
{
    long long dp[r][c];

    dp[0][0]=grid[0][0];

    for(int x =  0 ; x < r ; x++)
        for(int y = 0 ; y < c ; y++)
        {
            if(!x && !y)
                continue;
            
            else
            {
                long long up = (x>0?(grid[x][y] + dp[x-1][y]):LONG_LONG_MAX);
                long long left = (y>0?(grid[x][y] + dp[x][y-1]):LONG_LONG_MAX);
                dp[x][y] = min(up,left);
            }
        }

    return dp[r-1][c-1];
}

long long MazeCost2(int r, int c, vector<vector<long long>> &dp, vector<vector<long long>> grid) //memoization.
{
    if(!r && !c)
        return grid[0][0];

    if(r<0 || c<0)
        return LONG_LONG_MAX;
    
    if(dp[r][c]!=-1)
        return dp[r][c];
    
    long long up = grid[r][c] + MazeCost2(r-1,c,dp,grid);
    long long left = grid[r][c] + MazeCost2(r,c-1,dp,grid);

    dp[r][c] = min(up,left);

    return dp[r][c];
}

int main()
{
    int r,c;

    cin>>r>>c;

    vector<vector<long long>> grid(r,vector<long long>(c));

    for(int x = 0; x < r ; x++)
        for(int y = 0; y < c; y++)
            cin>>grid[x][y];

    // vector<vector<long long>> dp(r,vector<long long> (c,-1));

    // cout<<"Minimum Cost to Reach the End is : "<<MazeCost2(r-1,c-1,dp,grid)<<endl;
    
    // cout<<"(Assuming that Right and Down are the only Permissible movements.)"<<endl;

    cout<<"Minimum Cost to Reach the End is : "<<MazeCost(r,c,grid)<<endl;
    
    cout<<"(Assuming that Right and Down are the only Permissible movements.)"<<endl;

    return 0;
}