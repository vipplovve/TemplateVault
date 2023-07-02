#include <bits/stdc++.h>
using namespace std;

long long Sum(int s, int d[]) //tabulation.
{
    long long dp[s];

    dp[0] = d[0];

    for(int x = 1 ; x < s ; x++)
    {
        long long chosen = d[x] + (x>1?dp[x-2]:0);
        long long leftout = 0 + dp[x-1];

        dp[x] = max(chosen,leftout);
    }

    return dp[s-1];
}
 
long long Sum2(int s, int d[], int *dp) //memoization.
{
    if(s==0)
        return d[0];

    if(s<0)
        return 0;

    if(*(dp + s)!=-1)
        return *(dp + s);

    else
    {
        long long chosen = d[s] + Sum2(s-2,d,dp);
        long long leftout = 0 + Sum2(s - 1,d,dp);

        *(dp + s) = max(chosen,leftout);
    }

    return *(dp + s);
}

int main()
{
    int size;
    cin>>size;

    int data[size];

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];

    int dp[size];

    memset(dp,-1,sizeof(dp));
    
    //cout<<"Max Possible Non-Adjacent Subsequence Sum is : "<<Sum2(size-1,data,dp)<<endl;
    
    cout<<"Max Possible Non-Adjacent Subsequence Sum is : "<<Sum(size,data)<<endl;

    return 0;
}