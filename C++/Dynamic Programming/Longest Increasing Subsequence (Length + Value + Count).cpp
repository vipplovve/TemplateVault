#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> LISwierd(int d[], int s, vector<long long> &v) //it's tabulation but wierder.
{
    vector<long long> dp(s,1),record(s),counts(s,1);

    long long ans = -1e3;

    long long last = 0;

    long long count = 0;

    for(int x = 0 ; x < s ; x++)
    {
        record[x] = x;
        for(int p = 0 ; p < x ; p++)
        {
               if(d[p] < d[x] && 1 + dp[p] > dp[x])
            {
                dp[x] = 1 + dp[p];
                record[x] = p;
                counts[x] = counts[p];
            }

            else if(d[p] < d[x] && 1 + dp[p] == dp[x])
                counts[x] += counts[p];
        }
        
        if(dp[x] > ans)
        {
            ans = dp[x];
            last = x;
        }
    }

    for(int x = 0 ; x < s ; x++)
        if(dp[x] == ans)
            count += counts[x];

    v.push_back(d[last]);

    while(record[last] != last)
    {
        last = record[last];
        v.push_back(d[last]);
    }

    reverse(v.begin(), v.end());

    
            
    return pair<long long, long long>(ans,count);
}

long long LIS(int d[], int s, int i, int p)
{
    if(i == s)
        return 0;

    if(p == -1 || d[i] > d[p])
        return max(LIS(d,s,i+1,p),1 + LIS(d,s,i+1,i));
    else
        return LIS(d,s,i+1,p);        
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

    auto answer = LISwierd(data,size,sol);

    cout<<"Length of Longest Increasing Subsequence is : "<<answer.first<<endl;

    cout<<"\nThe Count of LIS : "<<answer.second<<endl;

    cout<<"\nOne of LIS is : - \n\n";

    for(auto i : sol)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}