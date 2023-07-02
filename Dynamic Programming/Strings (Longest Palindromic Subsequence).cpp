#include <bits/stdc++.h>
using namespace std;

int LongestPalindromicSubsequence(string f, string s, int n, string &ans) 
{
    vector<vector<int>> dp(n+1,vector<int> (n+1));

    for(int x = 0 ; x <= n ; x++)
        dp[x][0] = 0;

    for(int y = 0 ; y <= n ; y++)
        dp[0][y] = 0;

    for(int x = 1 ; x <= n ; x++)
        for(int y = 1 ; y <= n ; y++)
        {
            if(f[x-1] == s[y-1])
                dp[x][y] = 1 + dp[x-1][y-1];

            else
                dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
        }

    int a = n, b = n;

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

    return dp[n][n];
}

int main()
{
    string str;

    cin>>str;

    string straight = str;

    reverse(str.begin(), str.end());

    string palindrome = "";

    int len = LongestPalindromicSubsequence(straight,str,str.size(),palindrome);

    reverse(palindrome.begin(), palindrome.end());

    cout<<"The Longest Plaindromic Subsequence's Length is : "<<len<<endl<<endl;
    cout<<"It's Value is : "<<palindrome<<endl;

    return 0;
}