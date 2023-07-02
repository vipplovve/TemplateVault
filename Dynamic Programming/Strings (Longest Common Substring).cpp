#include <bits/stdc++.h>
using namespace std;

int LCS(string f, string s, int n, int m) //tabulation.
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
                dp[x][y] = 0;
        }

    int ans = 0;

    // for(int x = 1 ; x <= n ; x++)
    //     {for(int y = 1 ; y <= m ; y++)
    //                 cout<<dp[x][y]<<' ';
    //             cout<<endl;
    //             }
    //         cout<<endl<<endl;
    
    for(int x = 1 ; x <= n ; x++)
        for(int y = 1 ; y <= m ; y++)
            ans = max(ans,dp[x][y]);

    return ans;
}

int LCS2(string s, string t, int a, int b, int cur, int &ans) //recursive.
{
    if(a<0 || b<0)
        return ans;
    
    if(s[a] == t[b])
    {
        cur++;
        ans = max(ans,cur);
        LCS2(s,t,a-1,b-1,cur,ans);
    }

    else
    {
        cur = 0;
        ans = max(LCS2(s,t,a-1,b,cur,ans),LCS2(s,t,a,b-1,cur,ans));
    }
    return ans;
}


int main()
{
    string s,b;

    cin>>s>>b;

    // int ans = 0,cur = 0;

    // LCS2(s,b,s.size()-1,b.size()-1,cur,ans);

    // cout<<"Length of Longest Common Substring is : "<<ans<<endl;

    int ans = LCS(s,b,s.size(),b.size());

    cout<<"Length of Longest Common Substring is : "<<ans<<endl;

    return 0;
}