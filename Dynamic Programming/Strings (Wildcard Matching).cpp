#include <bits/stdc++.h>
using namespace std;

bool WildcardMatching(string f, string s, int n, int m) //tabulation.
{
    vector<vector<bool>> dp(f.size() + 1, vector<bool> (s.size() + 1, 0));

    for(int x = 0 ; x < m + 1 ; x++)
        dp[0][x] = false;

    for(int y = 0 ; y < n + 1 ; y++)
    {
        bool flag = true;
        
        for(int p = 1 ; p <= y ; p++)
        {
            if(f[p-1]!='*')
            {
                flag = false;
                break;
            }
        }
        
        dp[y][0] = flag;
    }

    dp[0][0] = true;

    for(int x = 1 ; x < n + 1 ; x++)
        for(int y = 1 ; y < m + 1 ; y++)
        {
            if(f[x-1] == s[y-1] || f[x-1] == '?')
                dp[x][y] = dp[x-1][y-1];

            else if(f[x-1] == '*')
                dp[x][y] = dp[x-1][y] || dp[x][y-1];

            else
                dp[x][y] = false;
        }

    return dp[n][m];
}

bool WildcardMatching2(string f, string s, int n, int m,vector<vector<int>> &dp) //memoization.
{
    if(n < 0 && m < 0 )
        return true;
    
    if(n < 0 && m >= 0)
        return false;

    if(n >=0 && m < 0)
    {
        for(int x = 0 ; x < n + 1 ; x++)
            if(f[x] != '*')
                return false;
        
        return true;
    }

    if(dp[n][m] != -1)
        return dp[n][m];

    if(f[n] == s[m] || f[n] == '?')
        return dp[n][m] = WildcardMatching2(f,s,n-1,m-1,dp);
    
    if(f[n] == '*')
        return dp[n][m] = WildcardMatching2(f,s,n-1,m,dp) || WildcardMatching2(f,s,n,m-1,dp);
    
    return false;
}

int main()
{
    string s,f ;

    cin>>f>>s;

    cout<<f<<" And "<<s;

    // vector<vector<int>> dp(f.size(), vector<int> (s.size(),-1));

    // if(WildcardMatching2(f,s,f.size()-1,s.size()-1,dp))
    //     cout<<" Do Match."<<endl;
    // else
    //     cout<<" Don't Match."<<endl;
    
    if(WildcardMatching(f,s,f.size(),s.size()))
        cout<<" Do Match."<<endl;
    else
        cout<<" Don't Match."<<endl;

    return 0;
}