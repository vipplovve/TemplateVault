#include <bits/stdc++.h>
using namespace std;

int rotations(int d[], int s)
{
    int l = 0, r = s-1;

    int ans = 0;

    while(l<=r)
    {
        int m = l + (r-l)/2;

        if(d[m]>d[m+1])
        {
            ans = m;
            break;
        }

        else if(d[m]>d[s-1])
            l = m + 1;

        else
            r = m - 1;
    }

    return s - ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Code Here.

    int s;
    cin >> s;

    int data[s];

    for(int x = 0 ; x < s ; x++)
        cin>>data[x];

    cout<<"The Array Has Gone Through "<<rotations(data,s)<<" Left Circular Shifts."<<endl;

    return 0;
}
