#include <bits/stdc++.h>
using namespace std;

long long Maze(int r, int c) //tabulation.
{
    long long dp[r][c];

    dp[0][0]=1;

    for(int x =  0 ; x < r ; x++)
        for(int y = 0 ; y < c ; y++)
        {
            if(!x && !y)
                continue;
            
            else
            {
                long long up = (x>0?dp[x-1][y]:0);
                long long left = (y>0?dp[x][y-1]:0);
                dp[x][y] = up + left;
            }
        }

    return dp[r-1][c-1];
}

long long Maze2(int r, int c, vector<vector<long long>> &dp) //memoization.
{
    if(!r && !c)
        return 1;

    if(r<0 || c<0)
        return 0;
    
    if(dp[r][c]!=-1)
        return dp[r][c];
    
    long long up = Maze2(r-1,c,dp);
    long long left = Maze2(r,c-1,dp);

    dp[r][c] = up + left;

    return dp[r][c];
}

int main()
{
    int r,c;

    cin>>r>>c;

    //vector<vector<long long>> dp(r,vector<long long> (c,-1));

    // cout<<"No of Ways to Solve The Maze are : "<<Maze2(r-1,c-1,dp)<<endl;
    
    // cout<<"(Assuming that Right and Down are the only Permissible movements.)"<<endl;

    cout<<"No of Ways to Solve The Maze are : "<<Maze(r,c)<<endl;
    
    cout<<"(Assuming that Right and Down are the only Permissible movements.)"<<endl;

    return 0;
}