#include <bits/stdc++.h>
using namespace std;

bool Ksum(int s, int t, int d[]) //tabulation.
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

bool Ksum2(int s, int t, int d[], vector<vector<int>> &dp) //memoization.
{
    if(s==0)
        return d[s] == t;
    
    if(t==0)
        return true;
    
    if(dp[s][t] != -1)
        return dp[s][t];
    
    bool left = Ksum2(s-1,t,d,dp);

    bool took = (t>=d[s])?Ksum2(s-1,t-d[s],d,dp):false;

    return dp[s][t] = left | took;
}

int main()
{
    int size,sum;
    cin>>size>>sum;

    int data[size];

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];
    
    // vector<vector<int>> dp (size,vector<int> (sum+1,-1));

    // cout<<"To achieve a Sum of "<<sum<<" is : ";

    // bool ans = Ksum2(size-1,sum,data,dp);

    // ans?cout<<"Possible."<<endl:cout<<"Impossible."<<endl;

    cout<<"To achieve a Sum of "<<sum<<" is : ";

    Ksum(size,sum,data)?cout<<"Possible."<<endl:cout<<"Impossible."<<endl;

    return 0;
}