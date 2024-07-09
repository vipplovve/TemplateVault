#include <bits/stdc++.h>
using namespace std;

long long LBS(int d[], int s) //it's tabulation but wierder.
{
    vector<long long> dp1(s,1), dp2(s,1);

    for(int x = 0 ; x < s ; x++)
    {
        for(int p = 0 ; p < x ; p++)
            if(d[p] < d[x] && 1 + dp1[p] > dp1[x])
                dp1[x] = 1 + dp1[p];
    }

    reverse(d,d+s);

    for(int x = 0 ; x < s ; x++)
    {
        for(int p = 0 ; p < x ; p++)
            if(d[p] < d[x] && 1 + dp2[p] > dp2[x])
                dp2[x] = 1 + dp2[p];
    }

    long long ans = -1e3;

    for(int x = 0 ; x < s ; x++)
        ans = max(dp1[x] + dp2[x] - 1 , ans);

    return ans;
}

int main()
{
    int size;

    cin>>size;

    int data[size];

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];

    cout<<"Length of Longest Bitonic Subsequence is : "<<LBS(data,size)<<endl;

    cout<<endl;

    return 0;
}