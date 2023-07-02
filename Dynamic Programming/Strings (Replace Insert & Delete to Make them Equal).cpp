#include <bits/stdc++.h>
using namespace std;

long long EditDistance(string f, string s, int n, int m) //tabulation.
{
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

    for(int x = 0 ; x < n + 1 ; x++)
        dp[x][0] = x + 1;

    for(int y = 0 ; y < m + 1 ; y++)
        dp[0][y] = y + 1;

    dp[0][0] = 0;

    for(int x = 1 ; x < n + 1 ; x++)
        for(int y = 1 ; y < m + 1 ; y++)
        {
            if(f[x-1] == s[y-1])
                dp[x][y] = dp[x-1][y-1];
            else
            {
                int i = 1 + dp[x][y-1];
                int d = 1 + dp[x-1][y];
                int r = 1 + dp[x-1][y-1];

                dp[x][y] = min(i,min(d,r));
            }            
        }

    return dp[n][m];
}

long long EditDistance2(string f, string s, int n, int m, vector<vector<int>> &dp) //memoization.
{
    if(n < 0)
        return m + 1;
    
    if(m < 0)
        return n + 1;

    if(f[n] == s[m])
        return EditDistance2(f,s,n-1,m-1,dp);

    if(dp[n][m] != - 1)
        return dp[n][m];
    
    else
    {
        long long insert = 1 + EditDistance2(f,s,n,m-1,dp);

        long long deletee = 1 + EditDistance2(f,s,n-1,m,dp);

        long long replace = 1 + EditDistance2(f,s,n-1,m-1,dp);

        return dp[n][m] = min(insert,min(deletee,replace));
    }
}

int main()
{
    string s1, s2;

    cin>>s1>>s2;

    cout<<"Minimum Operations Needed to Make "<<s1<<" Equal to "<<s2<<" are : ";

    // vector<vector<int>> dp(s1.size(), vector<int> (s2.size(),-1));

    // cout<<EditDistance2(s1,s2,s1.size()-1, s2.size()-1,dp)<<endl;

    cout<<EditDistance(s1,s2,s1.size(),s2.size())<<endl;

    cout<<"(Given That The Permissible Operations are : Insertion, Deletion & Replacement)."<<endl;

    return 0;
}