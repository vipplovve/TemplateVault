#include <bits/stdc++.h>
using namespace std;

bool search(int d[], int s, int e, int val)
{
    while(s<=e)
    {
        int mid = s + (e-s)/2;

        if(d[mid] == val)
            return true;

        else if(d[mid] < val)
            s = mid + 1;

        else
            e = mid - 1;
    }

    return false;
}

int turningpoint(int d[], int s)
{
    int l = 0, r = s-1;

    int ans = 0;

    while(l<=r)
    {
        int m = l + (r-l)/2;

        if(d[m] > d[m+1])
        {
            ans = m;
            break;
        }

        else if(d[m]>d[s-1])
            l = m + 1;

        else
            r = m - 1;
    }

    return ans;
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

    int num;

    cin >> num;

    int p = turningpoint(data,s);

    cout<<((search(data,0,p,num) | search(data,p+1,s-1,num))?"Yes, the Element Exists.":"No, the Element is Absent.")<<endl;

    return 0;
}
