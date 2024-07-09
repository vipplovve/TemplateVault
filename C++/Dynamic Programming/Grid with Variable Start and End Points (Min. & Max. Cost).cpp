#include <bits/stdc++.h>

using namespace std;

long long VariableGrid(int rows, int cols, vector<vector<long long>> grid, int mode) //tabulation.
{
    vector<vector<long long>> dp(rows,vector<long long>(cols));

    for(int y = 0 ; y < cols ; y++)
        dp[0][y] = grid[0][y];

    for(int x = 1 ; x < rows ; x++)
        for(int y = 0 ; y < cols ; y++)
        {
            long long up = grid[x][y] + dp[x-1][y];
           
            long long left = (mode == 1)?-1e8:1e8;
            long long right = (mode == 1)?-1e8:1e8;
            
            if(y-1>=0)
                left = grid[x][y] + dp[x-1][y-1];
            if(y+1<cols)
                right = grid[x][y] + dp[x-1][y+1];

            dp[x][y] = (mode == 1)?max(up,max(left,right)):min(up,min(left,right));
        }

    long long ans = (mode == 1)?-1e8:1e8;

    for(int x = 0 ; x < cols ; x++)
        ans = (mode == 1)?max(ans,dp[rows-1][x]):min(ans,dp[rows-1][x]);

    return ans;
}

long long VariableGrid2Max(int r, int col, int columns, vector<vector<long long>> grid, vector<vector<long long>> &dp) //memoization.
{
    if(col < 0 || col >= columns)
        return -1e7; 

    if(r==0)
        return grid[0][col];

    if(dp[r][col]!=-1)
        return dp[r][col];

    long long up = grid[r][col] + VariableGrid2Max(r-1,col,columns,grid,dp);
    long long left = grid[r][col] + VariableGrid2Max(r-1,col-1,columns,grid,dp);
    long long right = grid[r][col] + VariableGrid2Max(r-1,col+1,columns,grid,dp);
    
    return dp[r][col] = max(up,max(left,right));
}

long long VariableGrid2Min(int r, int col, int columns, vector<vector<long long>> grid, vector<vector<long long>> &dp) //memoization.
{
    if(col < 0 || col >= columns)
        return 1e7; 

    if(r==0)
        return grid[0][col];

    if(dp[r][col]!=-1)
        return dp[r][col];

    long long up = grid[r][col] + VariableGrid2Min(r-1,col,columns,grid,dp);
    long long left = grid[r][col] + VariableGrid2Min(r-1,col-1,columns,grid,dp);
    long long right = grid[r][col] + VariableGrid2Min(r-1,col+1,columns,grid,dp);
    
    return dp[r][col] = min(up,min(left,right));
}


int main()
{
    int rows,cols;
    cin>>rows>>cols;

    vector<vector<long long>> grid(rows,vector<long long>(cols));


    for(int x = 0 ; x < rows ; x++)
        for(int y = 0 ; y < cols ; y++)
            cin>>grid[x][y];
        
    // long long ans1 = -1e7, ans2 = 1e7;

    // vector<vector<long long>> dp1(rows,vector<long long>(cols,-1));

    // vector<vector<long long>> dp2(rows,vector<long long>(cols,-1));

    // for(int x = 0 ; x < cols ; x++)
    // {
    //     ans1 = max(ans1, VariableGrid2Max(rows-1,x,cols,grid,dp1));
        
    //     ans2 = min(ans2, VariableGrid2Min(rows-1,x,cols,grid,dp2));
    // }
    
    // cout<<"The Maximum Cost is : "<<ans1<<endl;
    
    // cout<<"The Minimum Cost is : "<<ans2<<endl;
    
    // cout<<"(Assuming Downward, Diagonally Left & Diagonally Right Movements to be permissible.}"<<endl;

    cout<<"The Maximum Cost is : "<<VariableGrid(rows,cols,grid,1)<<endl;
    
    cout<<"The Minimum Cost is : "<<VariableGrid(rows,cols,grid,2)<<endl;
    
    cout<<"(Assuming Downward, Diagonally Left & Diagonally Right Movements to be permissible.}"<<endl;

    return 0;
}