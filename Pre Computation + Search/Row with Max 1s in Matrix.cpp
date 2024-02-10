#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> d, int row, int col)
{
    int l,r,ones = -1, ans = -1;

    for(int x = 0 ; x < row ; x++)
    {
        l = 0, r = col - 1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(!d[x][mid])
                l = mid + 1;
            
            else
                r = mid - 1;
        }

        //cout<<x<<" : "<<col-l<<endl;

        if(col-l > ones)
        {
            ans = x + 1;
            ones = col - l;
        }
    }    

    return ans;
}

int main()
{
    int r,c;

    cin>>r>>c;

    vector<vector<int>> data (r, vector<int> (c));

    for(int x = 0 ; x < r ; x++)
        for(int y = 0 ; y < c ; y++)
            cin>>data[x][y];
    
    cout<<"Row with Max. No. of 1s is : Row #";

    cout<<solve(data,r,c)<<endl;

    return 0;
}