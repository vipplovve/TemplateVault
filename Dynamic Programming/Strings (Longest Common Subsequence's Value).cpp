#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string f, string s, int n, int m, string &ans) 
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
                a--;

            else
                b--;
        }
    }

    return dp[n][m];
}

int main()
{
    string first, second;

    cin>>first>>second;

    int s1 = first.size();
    int s2 = second.size();

    string str;

    int ans = LongestCommonSubsequence(first,second,s1,s2,str);

    reverse(str.begin(), str.end());

    cout<<"The Longest Common Subsequence is : "<<str<<endl;

    return 0;
}