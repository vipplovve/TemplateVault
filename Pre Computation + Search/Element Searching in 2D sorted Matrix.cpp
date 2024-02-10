#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> d, int row, int col, int val)
{
    int l = 0, r = row*col - 1;

    if(d[0][0] == val || d[row-1][col-1] == val)
            return true;

    while(l<=r)
    {
        int mid = l + (r-l)/2;


        int x = (mid-1)/col;

        int y = mid - col*x - 1;

        // cout<<mid<<" : ";
        // cout<<x<<" : "<<y<<" : "<<d[x][y]<<endl;

        if(d[x][y] == val)
            return true;

        else if(d[x][y] > val)
            r = mid - 1;

        else
            l = mid + 1;
    }

    return false;
}

int main()
{
    int r,c;

    cin>>r>>c;

    vector<vector<int>> data (r, vector<int> (c));

    for(int x = 0 ; x < r ; x++)
        for(int y = 0 ; y < c ; y++)
            cin>>data[x][y];
    
    int e;
    
    cin>>e;
    
    // cout<<r<<c<<e<<endl;
    
    cout<<(solve(data,r,c,e)?"Yes, the Element exists.":"No, the Element is absent.")<<endl;
    
    return 0;
}