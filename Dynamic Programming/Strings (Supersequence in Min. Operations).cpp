#include <bits/stdc++.h>
using namespace std;

int LCS(string f, string s, int n, int m, string &ans)//tabulation.
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

    int a = n, b = m;

    while(a>0 && b>0)
    {
        if(f[a-1] == s[b-1])
        {
            ans += f[a-1];
            a--;
            b--;
        }

        else
        {
            if(dp[a-1][b] > dp[a][b-1])
            {
                ans += f[a-1];
                a--;
            }

            else
            {
                ans += s[b-1];
                b--;
            }
        }
    }

    while(a>0)
    {
        ans += f[a-1];
        a--;
    }

    while(b>0)
    {
        ans += s[b-1];
        b--;
    }
    return dp[n][m];
}

int main()
{
    string a,b;

    cin>>a>>b;

    string sol = "";

    int ans = a.size() + (b.size() - LCS(a,b,a.size(),b.size(),sol));

    cout<<"Minimum No. Of Operations needed are : "<<ans<<endl;

    reverse(sol.begin(), sol.end());

    cout<<"The Supersequence is : "<<sol<<endl;

    return 0;
}