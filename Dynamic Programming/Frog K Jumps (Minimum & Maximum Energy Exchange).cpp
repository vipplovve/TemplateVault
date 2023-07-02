#include <bits/stdc++.h>
using namespace std;

int KjumpFrog(int data[], int size, int k) //tabulation.
{
    int dp[size];

        dp[0]=0;

        for(int x = 1 ; x < size ; x++)
        {
            int jump1 = 1e9;
            for(int y = 1 ; y < k + 1 ; y++)
            {
                if(x-y>=0)
                {
                    int localjump = dp[x-y] + abs(data[x-y] - data[x]);
                    jump1 = min(jump1,localjump);
                }
            }

            dp[x] = jump1;
        }  

        return dp[size - 1];
}

int KjumpFrog2(int data[], int x, int k, vector<int> &dp) //meomization.
{
    if(x==0)
        return 0;

    if(dp[x]!=-1)
        return dp[x];

    else
    {
        int jumper = 1e9;

        for(int y = 1 ; y < k + 1 ; y++)
        {
            if(x-y>=0)
                {
                    int localjump;
                    localjump = KjumpFrog2(data,x-y,k,dp) + abs(data[x-y] - data[x]);
                    jumper = min(jumper,localjump);
                } 
        }

        dp[x] = jumper;

        return dp[x];
    }
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {    
        int size,k;
        cin>>size>>k;

        int data[size];

        for(int x = 0 ; x < size ; x++)
            cin>>data[x];

        long long maxE = 0;

        for(int y = 0 ; y < size -1 ; y++)
            maxE += abs(data[y+1] - data[y]);

        // vector<int> dp(size,-1);

        // cout<<"Minimum Possible Energy Exchange is : "<<KjumpFrog2(data,size - 1,k,dp)<<endl;

        cout<<"Minimum Possible Energy Exchange is : "<<KjumpFrog(data,size,k)<<" Units."<<endl;
        cout<<"Maximum Possible Energy Exchange is : "<<maxE<<" Units."<<endl;
    }

    return 0;
}