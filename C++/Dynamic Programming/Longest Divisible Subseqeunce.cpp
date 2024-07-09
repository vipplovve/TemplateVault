#include <bits/stdc++.h>
using namespace std;

long long LDS(int d[], int s, vector<long long> &v) //it's tabulation but wierder.
{
    sort(d,d+s);

    vector<long long> dp(s,1),record(s);

    long long ans = -1e3;

    long long last = 0;
    for(int x = 1 ; x < s ; x++)
    {
        record[x] = x;
        for(int p = 0 ; p < x ; p++)
            if(d[x]%d[p]==0 && 1 + dp[p] > dp[x])
            {
                dp[x] = 1 + dp[p];
                record[x] = p;
            }
        
        if(dp[x] > ans)
        {
            ans = dp[x];
            last = x;
        }
    }

    v.push_back(d[last]);

    while(record[last] != last)
    {
        last = record[last];
        v.push_back(d[last]);
    }

    reverse(v.begin(), v.end());

    return ans;
}

int main()
{
    int size;

    cin>>size;

    int data[size];

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];

    // cout<<LIS(data,size,0,-1)<<endl;
    vector<long long> sol;

    cout<<"Length of Longest Divisible Subsequence is : "<<LDS(data,size,sol)<<endl;

    cout<<"\nThe LDS is : - \n\n";

    for(auto i : sol)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}