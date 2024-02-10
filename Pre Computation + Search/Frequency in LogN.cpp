#include <bits/stdc++.h>
using namespace std;

int frequency(vector<int> d, int num)
{
    int ans = 0;

    int l = 0, r = d.size() - 1;

    int a,b;

    while(l<=r)
    {
        int m = l + (r-l)/2;

        if(d[m] >= num)
            r = m - 1;

        else
            l = m + 1;
    }

    a = l;

    l = 0, r = d.size() - 1;

    while(l<=r)
    {
        int m = l + (r-l)/2;

        if(d[m] <= num)
            l = m + 1;

        else
            r = m - 1;
    }

    b = l;

    return abs(a-b);
}

int main()
{
    int size;

    cin >> size;

    vector<int> data(size);

    for(int x = 0 ; x < size ; x++)
        cin>>data[x];

    int num;

    cin >> num;

    cout<<"Total Occurences of "<<num<<" are : ";
    
    cout<<frequency(data,num)<<endl;
    
    return 0;
}
