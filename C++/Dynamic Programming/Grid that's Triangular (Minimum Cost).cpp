#include <bits/stdc++.h>
using namespace std;

long long triangulargrid(vector<vector<int>> grid, int size) //tabulation.
{
    vector<vector<int>> dp(size,vector<int>(size));

    for(int x = 0 ; x < size ; x++)
        dp[size-1][x] = grid[size-1][x];
    
    for(int x = size - 2 ; x > -1 ;x--)
        for(int y = x ; y > -1 ; y--)
        {
            int down = grid[x][y] + dp[x+1][y];
            int diagonal = grid[x][y] + dp[x+1][y+1];
            
            dp[x][y] = min(down,diagonal); 
        }
    return dp[0][0];
}

long long triangulargrid2(int r, int c, vector<vector<int>> grid, int size, vector<vector<int>> &dp) //memoization.
{
    if(r==size-1)
        return dp[size-1][c] = grid[size-1][c];

    if(dp[r][c]!=-1)
        return dp[r][c];
    
    int down = grid[r][c] + triangulargrid2(r+1,c,grid,size,dp);
    int diagonal = grid[r][c] + triangulargrid2(r+1,c+1,grid,size,dp);

    return dp[r][c] = min(down,diagonal);
}

int main()
{
    int size;
    cin>>size;

    vector<vector<int>> grid(size);

    int row = 0;

    for(int x = 1 ; x < size + 1 ; x++)
    {
        for(int y = 0 ; y < x ; y++)
        {
            int val;
            cin>>val;
            grid[row].push_back(val);
        } 
        row++;
    }

    // vector<vector<int>> dp(size,vector<int>(size,-1));

    // cout<<"Minimum Cost of Travel is : "<<triangulargrid2(0,0,grid,size,dp)<<endl;

    // cout<<"(Assuming that Down and Diagonally Down are the only Permissible movements.)"<<endl;
    
    cout<<"Minimum Cost of Travel is : "<<triangulargrid(grid,size)<<endl;

    cout<<"(Assuming that Down and Diagonally Down are the only Permissible movements.)"<<endl;

    return 0;
}