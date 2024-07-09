#include <bits/stdc++.h>
using namespace std;

bool len(string &a, string &b) //comparator.
{
    return a.size() < b.size();   
}

bool check(string &a, string &b) //check condition.
{
    if(a.size() != b.size() + 1)
        return false;

    int s1 = 0, s2 = 0;

    while(s1 < a.size())
    {
        if(s2 < b.size() && a[s1] == b[s2])
        {
            s1++;
            s2++;
        }

        else
            s1++;
    }

    if(s1 == a.size() && s2 == b.size())
        return true;

    else
        return false;
}

long long LSC(string d[], int s, vector<string> &v) //it's tabulation but wierder.
{
    vector<long long> dp(s,1),record(s);

    sort(d,d+s,len);

    long long ans = -1e3;

    long long last = 0;
    for(int x = 0 ; x < s ; x++)
    {
        record[x] = x;
        for(int p = 0 ; p < x ; p++)
            if(check(d[x],d[p]) && 1 + dp[p] > dp[x])
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

    string data[size];

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];

    vector<string> sol;

    cout<<"Length of Longest String Chain is : "<<LSC(data,size,sol)<<endl;

    cout<<"\nThe LSC is : - \n\n";

    for(auto i : sol)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}