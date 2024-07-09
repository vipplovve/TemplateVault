#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string f, string s, int n, int m)//tabulation.
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

int LongestCommonSubsequence2(string f, string s, int n, int m, vector<vector<int>> &dp) //memoization.
{
    if(n < 0 || m < 0)
        return 0;

    if(dp[n][m]!=-1)
        return dp[n][m];

    if(f[n] == s[m])
        return dp[n][m] = (1 + LongestCommonSubsequence2(f,s,n-1,m-1,dp));

    else
        return dp[n][m] = max(LongestCommonSubsequence2(f,s,n-1,m,dp),LongestCommonSubsequence2(f,s,n,m-1,dp));
}

int main()
{
    string first, second;

    cin>>first>>second;

    int s1 = first.size();
    int s2 = second.size();

    // vector<vector<int>> dp(s1,vector<int>(s2,-1));

    // int ans = LongestCommonSubsequence2(first,second,s1-1,s2-1,dp);

    // cout<<"The Length Of the Longest Common Substring is : "<<ans<<endl;

    int ans = LongestCommonSubsequence(first,second,s1,s2);

    cout<<"The Length Of the Longest Common Substring is : "<<ans<<' '<<endl;

    return 0;
}