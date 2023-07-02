#include <bits/stdc++.h>
using namespace std;

int LCS(string f, string s, int n, int m)//tabulation.
{
    vector<vector<int>> dp(n+1,vector<int> (m+1));

    for(int x = 0 ; x <= n ; x++)
        dp[x][0] = 0;

    for(int y = 0 ; y <= m ; y++)
        dp[0][y] = 0;

    for(int x = 1 ; x <= n ; x++)
        for(int y = 1 ; y <= m ; y++)
        {
            if(f[x-1] == s[y-1])
                dp[x][y] = 1 + dp[x-1][y-1];

            else
                dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
        }

    return dp[n][m];
}

int main()
{
    string a,b;

    cin>>a>>b;

    int ans = a.size() + b.size() - 2*LCS(a,b,a.size(),b.size());

    cout<<"Minimum No. Of Operations needed are : "<<ans<<endl;

    return 0;
}