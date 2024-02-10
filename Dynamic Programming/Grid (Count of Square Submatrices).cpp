#include <bits/stdc++.h>
using namespace std;

int SquareSubmatrices(vector<vector<int>> m, int a, int b) 
{
    vector<vector<int>> dp(a, vector<int> (b,0));

    int ans = 0;

    for(int x = 0 ; x < a ; x++)
    {
        dp[x][0] = m[x][0];
        ans += m[x][0];
    }

    for(int x = 0 ; x < b ; x++)
    {
        dp[0][x] = m[0][x];
        ans += m[0][x];
    }

    ans -= dp[0][0];
    
    for(int x = 1 ; x < a ; x++)
        for(int y = 1 ; y < b ; y++)
        {
            dp[x][y] = (m[x][y]?1 + min(dp[x-1][y], min(dp[x-1][y-1],dp[x][y-1])):0);

            ans += dp[x][y];
        }
    
    // for(int x = 0 ; x < a ; x++)
    // {
    //     for(int y = 0 ; y < b ; y++)
    //         cout<<dp[x][y]<<' ';

    //     cout<<endl;
    // }

    return ans;
}

int main()
{
    int n,m;

    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int> (m));

    for(int x = 0 ; x < n ; x++)
        for(int y = 0 ; y < m ; y++)
            cin>>matrix[x][y];
        
    cout<<"No. of Square Submatrices is : ";

    cout<<SquareSubmatrices(matrix,n,m)<<endl;

    return 0;
}