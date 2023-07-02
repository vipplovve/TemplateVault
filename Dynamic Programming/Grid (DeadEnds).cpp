#include <bits/stdc++.h>
using namespace std;

long long MazeWithDeadEnds(int r, int c, vector<pair<int,int>> deadends) //tabulation.
{
    long long dp[r][c];

    dp[0][0]=1;

    for(auto i : deadends)
        dp[i.first][i.second] = 0;

    for(int x =  0 ; x < r ; x++)
        for(int y = 0 ; y < c ; y++)
        {
            if(!x && !y)
                continue;
            
            if(!dp[x][y])
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

long long MazeWithDeadEnds2(int r, int c, vector<vector<long long>> &dp, vector<pair<int,int>> deadends) //memoization.
{
    if(!r && !c)
        return 1;

    if(r<0 || c<0)
        return 0;

    for(auto i : deadends)
        if(r==i.first && c==i.second)
            return 0;
    
    if(dp[r][c]!=-1)
        return dp[r][c];
    
    long long up = MazeWithDeadEnds2(r-1,c,dp,deadends);
    long long left = MazeWithDeadEnds2(r,c-1,dp,deadends);

    dp[r][c] = up + left;

    return dp[r][c];
}

int main()
{
    int r,c,d;

    cin>>r>>c>>d;

    vector<pair<int,int>> deadends(d);

    for(int x = 0 ; x < d ; x++)
        cin>>deadends[x].first>>deadends[x].second;

    vector<vector<long long>> dp(r,vector<long long> (c,-1));

    // cout<<"No of Ways to Solve The Maze are : "<<MazeWithDeadEnds2(r-1,c-1,dp,deadends)<<endl;
    
    // cout<<"(Assuming that Right and Down are the only Permissible movements.)"<<endl;

    cout<<"No of Ways to Solve The Maze are : "<<MazeWithDeadEnds(r,c,deadends)<<endl;
    
    cout<<"(Assuming that Right and Down are the only Permissible movements.)"<<endl;
    
    cout<<"\nDeadEnd Blocks Being :-\n\n";

    for(auto i : deadends)
        cout<<"Block at : "<<i.first<<' '<<i.second<<endl;

    return 0;
}