#include <bits/stdc++.h>
using namespace std;

long long DistinctSubsequence(string f, string s, int n , int m)
{
    vector<vector<int>> dp (f.size() + 1, vector<int> (s.size() + 1, -1));

    for(int x = 0 ; x < f.size() + 1 ; x++)
        dp[x][0] = 1;

    for(int x = 0 ; x < s.size() + 1 ; x++)
        dp[0][x] = 0;

    dp[0][0] = 1;

    for(int x = 1 ; x < f.size() + 1 ; x++)
        for(int y = 1 ; y < s.size() + 1 ; y++)
        {
            if(f[x-1] == s[y-1])
                dp[x][y] = dp[x-1][y-1] + dp[x-1][y];
            
            else
                dp[x][y] = dp[x-1][y];
        }

    return dp[f.size()][s.size()];

}

long long DistinctSubsequence2(string f, string s, int n, int m, vector<vector<int>> &dp) //memoization.
{
    if(m<0)
        return 1;

    if (n<0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    if(f[n] == s[m])
        return dp[n][m] = (DistinctSubsequence2(f,s,n-1,m,dp) + DistinctSubsequence2(f,s,n-1,m-1,dp));
    
    return dp[n][m] = DistinctSubsequence2(f,s,n-1,m,dp);

}

int main()
{
    string s1, s2;

    cin>>s1>>s2;

    cout<<"No. of Distinct Subsequence of "<<s2<<" in "<<s1<<" are : ";
    
    // vector<vector<int>> dp(s1.size(), vector<int> (s2.size(), -1));

    // cout<<DistinctSubsequence2(s1,s2,s1.size()-1, s2.size() - 1,dp)<<endl;

    cout<<DistinctSubsequence(s1,s2,s1.size(), s2.size())<<endl;
    
    return 0;
}