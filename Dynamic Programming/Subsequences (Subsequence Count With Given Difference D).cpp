#include <bits/stdc++.h>
using namespace std;

long long Ksum(int s, int t, int d[]) //tabulation.
{
    vector<vector<long long>> dp(s,vector<long long>(t+1));

    if(d[0] == 0)
        dp[0][0]=2;

    else
        dp[0][0]=1;

    if(d[0] != 0 && d[0] <= t)
        dp[0][d[0]] = 1;

    for(int x = 1 ; x < s ; x++)
        for(int y = 0 ; y <= t ; y++)
        {
            int left = dp[x-1][y];

            int took = (y>=d[x])?dp[x-1][y-d[x]]:false;

            dp[x][y] = left + took;
        }

    return dp[s-1][t];
}

int main()
{
    int size,sum = 0;
    cin>>size;

    int data[size];

    int zeroes = 0;

    for(int x = 0 ; x < size ; x++)
    {
        cin>>data[x];
        sum += data[x];

        if(!data[x])
            zeroes++;
    }

    int d;
    cin>>d;

    if((sum - d)%2 || (sum - d)<0)
        cout<<"It is Not Possible to Partition This Sequence into Two having the Given Difference."<<endl;
    
    // cout<<zeroes;

    else
    {
        cout<<"No of Subsequence Pairs Having Difference between their Sums as "<<(sum-d)/2<<" are : ";

        long long extras = pow(2,zeroes);

        cout<<Ksum(size,(sum-d)/2,data)<<endl;
    }

    return 0;
}