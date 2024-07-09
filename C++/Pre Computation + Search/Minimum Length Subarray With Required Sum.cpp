#include <bits/stdc++.h>
using namespace std;

bool S(int d[], int s, int t, int p)
{
    int sum = 0;

    for(int x = 0 ; x < p ; x++)
        sum += d[x];

    if(sum>=t)
        return true;
    //cout<<sum<<" : ";

    for(int y = p ; y < s ; y++)
    {
        sum += d[y];

        sum -= d[y-p];

        //cout<<sum<<" : ";

        if(sum >= t)
            return true;
    }
    return false;
}

int solve(int d[], int s, int t)
{
    int l = 1, r = s;

    int ans = -1;

    while(l<=r)
    {
        int mid = l + (r-l)/2;

        if(S(d,s,t,mid))
        {
            r = mid - 1;
            ans = mid;
        }

        else
            l = mid + 1;
    }

    return (ans <= s)?ans:-1;
}

int main()
{
    int size;

    cin>>size;

    int data[size];

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];

    int sum;

    cin>>sum;

    int ans = 0;

    // bool p = S(data,size,sum,2);

    ans = solve(data,size,sum);

    cout<<"Minimum Size Subarray with Sum >= "<<sum<<" has a size of "<<ans<<endl;

    return 0;
}