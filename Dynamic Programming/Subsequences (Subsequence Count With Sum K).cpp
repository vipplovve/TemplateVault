#include <bits/stdc++.h>
using namespace std;

long long Ksum(int s, int t, int d[]) //tabulation.
{
    vector<vector<long long>> dp(s,vector<long long>(t+1));

    for(int x = 0 ; x < s ; x++)
        dp[x][0] = 1;

    dp[0][d[0]] = 1;

    for(int x = 1 ; x < s ; x++)
        for(int y = 1 ; y <= t ; y++)
        {
            int left = dp[x-1][y];

            int took = (y>=d[x])?dp[x-1][y-d[x]]:false;

            dp[x][y] = left + took;
        }

    return dp[s-1][t];
}

int main()
{
    int size,sum;
    cin>>size>>sum;

    int data[size];

    int zeroes = 0;

    for(int x = 0 ; x < size ; x++)
    {
        cin>>data[x];
        if(!data[x])
            zeroes++;
    }
    
    // cout<<zeroes;

    cout<<"No of Subsequences With Sum Equal to "<<sum<<" are : ";

    long long extras = pow(2,zeroes);

    cout<<Ksum(size,sum,data)*extras<<endl;
    
    return 0;
}