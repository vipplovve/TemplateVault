#include <bits/stdc++.h>
using namespace std;

long long Sum3D(int row,int col,vector<vector<long long>> grid) //tabulation.
{
    vector<vector<vector<long long>>> dp(row,vector<vector<long long>> (col,vector<long long>(col,0)));

    for(int y1 = 0 ; y1 < col ; y1++)
        for(int y2 = 0 ; y2 < col ; y2++)
        {
            if(y1==y2)
                dp[row-1][y1][y2] = grid[row-1][y1];
            else
                dp[row-1][y1][y2] = grid[row-1][y1] + grid[row-1][y2];
        }

    for(int x = row - 2 ; x >= 0 ; x--)
        for(int y1 = 0 ; y1 < col ; y1++)
            for(int y2 = 0 ; y2 < col ; y2++)
            {
               long long maxsum = -1e8;

                for(int a1 = -1 ; a1 <= 1 ; a1++)
                    for(int a2 = -1 ; a2 <= 1 ; a2++)
                    {
                        long long val = 0;

                        if(y1==y2)
                            val = grid[x][y1];
                        
                        else
                            val = grid[x][y1] + grid[x][y2];
                        
                        if(y1+a1 >=0 && y1+a1 <col && y2+a2>=0 && y2+a2 < col)
                            val += dp[x+1][y1 + a1][y2 + a2];

                        else
                            val = -1e8;

                        maxsum = max(maxsum,val);

                    }

                dp[x][y1][y2] = maxsum;
            }

    return dp[0][0][col-1];
}

long long Sum3D2(int r, int c1, int c2, int row, int col, vector<vector<long long>> grid, vector<vector<vector<long long>>> &dp) //memoization.
{
    if(c1 < 0 || c2 < 0 || c1 >= col || c2 >= col)
        return -1e9;
    
    if(r == row-1)
    {
        if(c1==c2)
            return grid[r][c1];
        else
            return grid[r][c1] + grid[r][c2];
    }

    if(dp[r][c1][c2] != -1)
        return dp[r][c1][c2];

    long long maxsum = -1e8;

    for(int y1 = -1 ; y1 <= 1 ; y1++)
        for(int y2 = -1 ; y2 <= 1 ; y2++)
        {
            long long val = 0;

            if(c1==c2)
                val += grid[r][c1];
            
            else
                val += grid[r][c1] + grid[r][c2];
            
            val += Sum3D2(r+1,c1 + y1, c2 + y2, row,col,grid,dp);

            maxsum = max(maxsum,val);

        }

    return dp[r][c1][c2] = maxsum;
}

int main()
{
    int r,c;

    cin>>r>>c;

    vector<vector<long long>> grid(r,vector<long long> (c));


    for(int x = 0 ; x < r ; x++)
        for(int y = 0 ; y < c ; y++)
            cin>>grid[x][y];
    
    // for(int x = 0 ; x < r ; x++)
    //     for(int y = 0 ; y < c ; y++)
    //         cout<<grid[x][y];

    // vector<vector<vector<long long>>> dp(r,vector<vector<long long>> (c,vector<long long>(c,-1)));
    
    // long long ans = 0;

    // ans = Sum3D2(0,0,c-1,r,c,grid,dp);

    // cout<<"The Maximum Total Sum Achievable is : "<<ans<<endl;

    // cout<<"(Considering Down, Diagonally Right and Diagonally Left to be Permissible Movements."<<endl;

    cout<<"The Maximum Total Sum Achievable is : "<<Sum3D(r,c,grid)<<endl;

    cout<<"(Considering Down, Diagonally Right and Diagonally Left to be Permissible Movements."<<endl;

    return 0;
}