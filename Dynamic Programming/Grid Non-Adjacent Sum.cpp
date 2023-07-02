#include <bits/stdc++.h>
using namespace std;

long long Sum2(long n, long k, long left, vector<vector<long long>> data, vector<vector<long long>> &dp) //memoization.
{
    if(n==0)
    {
        long long m = -1e11;

        for(long long x = 0 ; x < k ; x++)
            if(x!=left)
                m = max(m,data[0][x]);
        
        dp[n][left] = m;
        return m;
    }

    if(dp[n][left] != -1)
        return dp[n][left];

    long long M = -1e11;

    for(long long y = 0 ; y < k ; y++)
        if(y!=left)
        {
            long long p = data[n][y] + Sum2(n-1,k,y,data,dp);
            M = max(M,p);
        } 

    return dp[n][left] = M;
}

long long Sum(long n, long k, vector<vector<long long>> data) //tabulation.
{
    vector<vector<long long>> dp(n,vector<long long>(k+1,-1));

    for(long long left = 0 ; left < k + 1 ; left++)
        {
            long long m = -1e11;

            for(long long x = 0 ; x < k ; x++)
                if(x!=left)
                    m = max(m,data[0][x]);
        
            dp[0][left] = m;
        }

    for(long long x = 1 ; x < n ; x++)
    {
        for(long long left = 0 ; left < k + 1 ;left++)
        {
            long long M = -1e11;
            for(long long y = 0 ; y < k ; y++)
                if(y!=left)
                {
                    long long p = data[x][y] + dp[x-1][y];
                    M = max(M,p);  
                } 

            dp[x][left] = max(dp[x][left],M);

            }
    }

    return dp[n-1][k];
}

int main()
{
    long long r,c;
    cin>>r>>c;

    vector<vector<long long>> data(r,vector<long long>(c));

    vector<vector<long long>> dp(r,vector<long long>(c+1,-1));

    for(long long x = 0 ; x < r ; x++)
        for(long long y = 0 ; y < c ; y++)
            cin>>data[x][y];

    //     for(int x = 0 ; x < r ; x++)
    //     {
    //         for(int y = 0 ; y < c ; y++)
    //             cout<<data[x][y]<<' ';
    //         
    //          cout<<endl;
    //     }

    // long long ans = 0;

    // ans = Sum2(r-1,c,c,data,dp);

    // cout<<ans<<endl;

    long long ans = Sum(r,c,data);

    cout<<"Maximum Possible Non-Adjacent 2D Grid Sum is : "<<ans<<endl;

    return 0;
}