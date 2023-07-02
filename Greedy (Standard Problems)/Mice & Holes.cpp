#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MiceHole(vector<int> m, vector<int> h, int s)
{
    if(m.size() != h.size())
        return -1;

    int ans = 0;

    sort(m.begin(), m.end());
    sort(h.begin(), h.end());

    for(int x = 0 ; x < s ; x++)
        ans = max(ans, abs(m[x] - h[x]));

    return ans;
}

int main()
{
    int size;
    cin>>size;

    vector<int> a(size), b(size);

    for(int x = 0 ; x < size ; x++)
        cin>>a[x];
    
    for(int x = 0 ; x < size ; x++)
        cin>>b[x];

    int ans = MiceHole(a,b,size);

    cout<<"Time Taken is : "<<ans<<" Minutes."<<endl;
    
}