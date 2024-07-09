#include <bits/stdc++.h>
using namespace std;

long double root(long double num, long double p)
{
    long double l = 0, r = 1e20;

    while(l<=r)
    {
        long double mid = l + (r-l)/2;

        if(pow(mid,p)<num)
            l = mid + 0.00000000000001;

        else
            r = mid - 0.00000000000001;
    }

    return r + 0.00000000000001;
}

int main()
{
    long double x,y;

    cin >> x >> y;

    cout<<"The "<<y<<"th Root of "<<x<<" is : ";

    cout<<setprecision(14)<<root(x,y)<<endl;
    
    return 0;
}
