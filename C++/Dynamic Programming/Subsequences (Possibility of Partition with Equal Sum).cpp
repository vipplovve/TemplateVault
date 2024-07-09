#include <bits/stdc++.h>
using namespace std;

bool Ksum(int s, int t, int d[]) 
{
    vector<vector<bool>> dp(s,vector<bool>(t+1));

    for(int x = 0 ; x < s ; x++)
        dp[x][0] = true;

    dp[0][d[0]] = true;

    for(int x = 1 ; x < s ; x++)
        for(int y = 1 ; y <= t ; y++)
        {
            bool left = dp[x-1][y];

            bool took = (y>=d[x])?dp[x-1][y-d[x]]:false;

            dp[x][y] = left | took;
        }

    return dp[s-1][t];
}

int main()
{
    int len;
    cin>>len;

    int data[len];

    int sum = 0;

    bool flag;

    for(int x = 0 ; x < len ; x++)
    {
        cin>>data[x];
        sum += data[x];
    }

    (sum&1)?flag = false:flag = true;

    cout<<"It is ";

    (Ksum(len,sum/2,data) && flag)?cout<<"Possible ":cout<<"Impossible ";

    cout<<"To Partition this Sequence into Two Subsets of Equal Sum."<<endl;

    return 0;
}