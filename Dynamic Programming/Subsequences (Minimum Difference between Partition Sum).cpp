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
    int size;
    cin>>size;

    int data[size];
    int sum = 0;

    for(int x = 0 ; x < size ; x++)
    {
        cin>>data[x];
        sum += data[x];
    }

    int ans = (sum&1)?1:0; 
    
    if(ans)
        sum = (sum-1)/2;
    else
        sum = sum/2;

    while(sum>0)
    {
        if(Ksum(size,sum,data))
            break;
        else
        {
            ans+=2;
            sum--;
        }
    }

    cout<<"Minimum Possible Absolute Difference After Partitioning into Two Subsets : "<<ans<<endl;
    
    return 0;
}